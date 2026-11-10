#include "TVector3.h"
#include "TMinuit.h"
#include "TMath.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TClonesArray.h"
#include "TRandom3.h"
#include "TChain.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCut.h"
#include "TCutG.h"
#include "TEventList.h"
#include "TMinuit.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TLine.h"
#include "TText.h"
#include "TSystem.h"
#include "TF1.h"
#include "TEllipse.h"
#include "TFitResult.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TDecompSVD.h"
#include "BB_optics_tree.C"
#include "TTreeFormula.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

const int nxsieve = 13;
const int nysieve = 7;

const double PI = TMath::Pi();

//Example code to align the GEM stack relative to the spectrometer coordinate system and determine distance from target to sieve plate using
//known dimensions and hole spacings of sieve and known dimensions and internal alignments of GEMs:
//We are going to be lazy and use MINUIT even though this problem could easily be linearized:

const double sigma_pos = 0.0001; //0.1 mm (wild guess)
const double sigma_slope = sigma_pos/1.6; //0.1 mm/1.6 m ~= 6e-5 gives rough order of magnitude for slope uncertainty, of course multiple scattering might invalidate that.

void FitGaus_FWHM( TH1D *htest, double xmin, double xmax, double thresh=0.5 ){

  htest->GetXaxis()->SetRangeUser(xmin,xmax); 
  
  int binmax = htest->GetMaximumBin();
  int binlow = binmax, binhigh = binmax;

  double max = htest->GetBinContent(binmax);

  while( htest->GetBinContent(binlow) >= thresh*max && binlow > 1 ){binlow--;}
  while( htest->GetBinContent(binhigh) >= thresh*max && binhigh < htest->GetNbinsX() ){ binhigh++; }

  double xlow = htest->GetBinLowEdge(binlow);
  double xhigh = htest->GetBinLowEdge(binhigh+1);

  htest->Fit("gaus","qS","",xlow, xhigh);
}

void Optics_BigBite_automatic( const char *configfilename, const char *outfilename = "Optics_BigBite_temp.root" ){

  TChain *C = new TChain("T");
  
  ifstream configfile(configfilename);

  TString prefix = "bb.gem";

  //We need a list of files and associated targets (4-foil, 5-foil, dummy, etc):

  double BBtheta = 26.5; //Spectrometer central angle
  double BBdist = 1.55; //m, default; sieve is ~0.37 m upstream of magnet. 
  double XOFFSIEVE = 0.0;
  double YOFFSIEVE = 0.0;
  double ZSIEVE = 1.18;
  double XBEAM = 0.0; //+X to beam right
  double YBEAM = 0.0; //+Y vertically up

  double rasterx_min_raw = 4.079e4;
  double rasterx_max_raw = 4.748e4;
  double rastery_min_raw = 4.0889e4;
  double rastery_max_raw = 4.5943e4;
  double rastersize_x_mm = 2.0;
  double rastersize_y_mm = 2.0;

  int raster_flag = 0;
  
  int order=2; //Fit order
  int xtar_flag = 0; //include xtarget-dependent MEs?

  double nsigma_cut_zvertex = 2.0;
  double nsigma_cut_xysieve = 2.0;
  
  //Include raster corrections? Ignore for now.
  
  int ntargets = 0;

  std::vector<int> nfoils;  // number of foils per target;
  std::vector<std::vector<double> > zfoil; //Z position of foils by target:
  std::vector<std::vector<double> > zmean; //Z position of foils by target:
  std::vector<std::vector<double> > zsigma; //Z position of foils by target:
  std::vector<std::vector<bool> > skipfoil; //flag to disable target/foil from the analysis. 
  std::vector<double> zmin_targ;
  std::vector<double> zmax_targ; 
  //We need to associate each target with a list of ROOT files if we are going to combine them: 
  std::vector<std::vector<TString> > list_of_files_by_target; //ROOT files for each target
  //std::vector<std::vector<TCut> > foilcuts; //Cut associated with each target/foil (essentially vertex z) 
  
  TCut globalcut = "";
  
  if( configfile ){
    TString currentline;

    //First read the list of targets:
    while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endconfig")){
      if( !currentline.BeginsWith("#") ){
	TObjArray *tokens = currentline.Tokenize(" ");
	
	int ntokens = tokens->GetEntries();

	if( ntokens >= 2 ){
	  TString skey = ( (TObjString*) (*tokens)[0] )->GetString();
	  TString sval = ( (TObjString*) (*tokens)[1] )->GetString();
	  //format for target definition is "target nfoils z1 z2 ..."
	  if( skey == "target" ){
	    int nfoiltemp = sval.Atoi();
	    
	    if( ntokens >= nfoiltemp + 3 ){
	      int itarg = ntargets;

	      cout << "new target definition, (itarg, nfoil)=(" << itarg << ", " << nfoiltemp << ")" << endl;
	      
	      zmin_targ.push_back( 10000.0 );
	      zmax_targ.push_back( -10000.0 );
	      nfoils.push_back( nfoiltemp );
	      
	      std::vector<double> ztemp(nfoiltemp,0);
	      std::vector<double> zmeantemp(nfoiltemp,0.0);
	      std::vector<double> zsigmatemp(nfoiltemp,0.005);
	      std::vector<bool> skipfoiltemp(nfoiltemp,false);
	      for( int ifoil=0; ifoil<nfoiltemp; ifoil++ ){
		TString sz = ( (TObjString*) (*tokens)[ifoil+2] )->GetString();
		ztemp[ifoil] = sz.Atof();
		
		zmin_targ[itarg] = (ztemp[ifoil] < zmin_targ[itarg]) ? ztemp[ifoil] : zmin_targ[itarg];
		zmax_targ[itarg] = (ztemp[ifoil] > zmax_targ[itarg]) ? ztemp[ifoil] : zmax_targ[itarg];
		zmeantemp[ifoil] = ztemp[ifoil]; //initialize mean z to the nominal z, will be replaced by fit later
		cout << "(ifoil, zfoil, zmin, zmax, zmean)=(" << ifoil << ", "
		     << ztemp[ifoil] << ", " 
		     << zmin_targ[itarg] << ", "
		     << zmax_targ[itarg] << ", "
		     << zmeantemp[ifoil] << ")" << endl;
		
	      }

	      zfoil.push_back( ztemp );
	      zmean.push_back( zmeantemp );
	      zsigma.push_back( zsigmatemp );
	      skipfoil.push_back( skipfoiltemp );

	      vector<TString> listfilestemp;
	      for( int itoken = nfoiltemp+2; itoken<ntokens; itoken++ ){
		TString rootfilename = ( (TObjString*) (*tokens)[itoken] )->GetString();
		//Check existence of file:
		//std::cout << "Checking for root file " << rootfilename << std::endl;
		//There really isn't a need for this check, and this is an incorrect usage of this function anyway.
		//if( gSystem->AccessPathName(rootfilename.Data()) ){
		//  std::cout << "File " << rootfilename << " exists, adding..." << std::endl;
		listfilestemp.push_back( rootfilename );
		//}
	      }
		
	      list_of_files_by_target.push_back( listfilestemp );

	      ntargets++;
	    }
	  }
	  
	  
	  if( skey == "prefix" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    prefix = stemp;
	  }

	  if( skey == "X0SIEVE" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    XOFFSIEVE = stemp.Atof();
	  }

	  if( skey == "Y0SIEVE" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    YOFFSIEVE = stemp.Atof();
	  }

	  if( skey == "ZSIEVE" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    ZSIEVE = stemp.Atof();
	  }

	  if( skey == "XBEAM" ){
	    XBEAM = sval.Atof();
	  }

	  if( skey == "YBEAM" ){
	    YBEAM = sval.Atof();
	  }

	  if( skey == "order" ){
	    order = sval.Atoi();
	  }

	  if( skey == "xtar_flag" ){
	    xtar_flag = sval.Atoi();
	  }

	  if( skey == "BBtheta" ){
	    BBtheta = sval.Atof()*TMath::DegToRad();
	  }

	  if( skey == "raster_flag" ){
	    raster_flag = sval.Atoi();
	  }

	  if( skey == "rasterx_min_raw" ){
	    rasterx_min_raw = sval.Atof();
	  }

	  if( skey == "rasterx_max_raw" ){
	    rasterx_max_raw = sval.Atof();
	  }

	  if( skey == "rastery_min_raw" ){
	    rastery_min_raw = sval.Atof();
	  }

	  if( skey == "rastery_max_raw" ){
	    rastery_max_raw = sval.Atof();
	  }

	  if( skey == "rastersize_x_mm" ){
	    rastersize_x_mm = sval.Atof();
	  }

	  if( skey == "rastersize_y_mm" ){
	    rastersize_y_mm = sval.Atof();
	  }
	  
	}
      }
    }

    while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endcut") ){
      if( !currentline.BeginsWith("#") ){
	globalcut += currentline;
      }
    }
  } else {
    return;
  }

  //First we need to loop over the data and set vertex and hole cuts:
  // Initialize histograms:

  if( ntargets <= 0 ) return;

  //Count the total number of foils;
  int maxnfoils = 0;
  for( int itarg=0; itarg<ntargets; itarg++ ){
    if( nfoils[itarg] > maxnfoils ){
      maxnfoils = nfoils[itarg];
    }
  }
  
  TClonesArray *zvertex_histos = new TClonesArray( "TH1D", ntargets );
  TClonesArray *xysieve_histos = new TClonesArray( "TH2D", ntargets*maxnfoils );

  for( int itarg=0; itarg<ntargets; itarg++ ){
    TString hnametemp;
    new( (*zvertex_histos)[itarg] ) TH1D(hnametemp.Format("hzvertex_targ%d",itarg), ";vertex z (m);", 250, zmin_targ[itarg]-0.05, zmax_targ[itarg] + 0.05 );
    for( int ifoil=0; ifoil<nfoils[itarg]; ifoil++ ){ //Create xysieve histos:
      new( (*xysieve_histos)[ifoil+maxnfoils*itarg] ) TH2D(hnametemp.Format("hxysieve_targ%d_foil%d", itarg, ifoil),";y_{sieve} (m); x_{sieve} (m)", 400, -0.2,0.2, 400, -0.4,0.4);
    }
  }

  //How many loops over the data do we need?
  // 1. Fill zvertex histograms; fit peak positions and widths, define cuts
  // 2. Fill xy sieve histograms; fit peak positions and widths x and y, define ellipse cuts
  // 3. Set up and do the fits for ytarget, xptarget, yptarget

  //Since we only really need the BigBite branches for this purpose; these are largely the same across all experiments;
  //Might as well use the GMN tree structure here; 
  
  for( int itarg=0; itarg<ntargets; itarg++ ){
    TChain *Ctemp = new TChain("T");

    Ctemp->SetBranchStatus("*",0);
    Ctemp->SetBranchStatus("bb.tr.*",1);
    Ctemp->SetBranchStatus("bb.gem.track.*",1);
    Ctemp->SetBranchStatus("e.kine.*",1);
    Ctemp->SetBranchStatus("bb.grinch_tdc.clus.*",1);
    Ctemp->SetBranchStatus("bb.etot_over_p",1);
    Ctemp->SetBranchStatus("bb.ps.e",1);
    Ctemp->SetBranchStatus("bb.sh.e",1);
    
    for( int ifile=0; ifile<list_of_files_by_target[itarg].size(); ifile++ ){
      Ctemp->Add( list_of_files_by_target[itarg][ifile] );
    }
      
    TH1D *htemp = ( (TH1D*) zvertex_histos->At(itarg) );
    
    TString hnametemp = htemp->GetName();

    Ctemp->Project( hnametemp.Data(), "bb.tr.vz[0]", globalcut );

    TCanvas *ctemp = new TCanvas("ctemp","ctemp",1000,750);
    
    //typical foil spacing is ~5 cm in BB optics targets, so take +/- 0.025 of the nominal foil position as the range
    for( int ifoil=0; ifoil<nfoils[itarg]; ifoil++ ){

      double zmintemp=zfoil[itarg][ifoil]-0.025,zmaxtemp=zfoil[itarg][ifoil] +0.025;
      
      bool okay = false;
      while( !okay ){
	
	FitGaus_FWHM( htemp, zmintemp, zmaxtemp, 0.4 );

	TF1 *gausfunc = ( (TF1*) htemp->GetListOfFunctions()->FindObject("gaus") );
	
	zmean[itarg][ifoil] = gausfunc->GetParameter("Mean");
	zsigma[itarg][ifoil] = gausfunc->GetParameter("Sigma");
	
	htemp->GetXaxis()->SetRangeUser( zmin_targ[itarg] - 0.05, zmax_targ[itarg] + 0.05 );
	htemp->Draw();
	
	ctemp->Update();
	gPad->Modified();
	gSystem->ProcessEvents();
	
	std::cout << "fit okay (y/n/s = yes/no/skip)?" << std::endl;

	TString reply;
	reply.ReadLine(cin,kTRUE);
	reply.ToLower();
	if( reply.BeginsWith("n") ){
	  cout << "zmin for fit = ";
	  cin >> zmintemp;
	  cout << "zmax for fit = ";
	  cin >> zmaxtemp; 
	} else if( reply.BeginsWith("s") ){ //skip:
	  skipfoil[itarg][ifoil] = true;
	  okay = true;
	} else {
	  okay = true;
	}
      }
    }
    Ctemp->Delete();
  }

  //Next up, fill sieve slit reconstruction histograms:
  
  for( int itarg=0; itarg<ntargets; itarg++ ){
    TChain *Ctemp = new TChain("T");
    for( int ifile=0; ifile<list_of_files_by_target[itarg].size(); ifile++ ){
      Ctemp->Add( list_of_files_by_target[itarg][ifile] );
    }

    
    TTreeFormula *GlobalCut = new TTreeFormula( "GlobalCut", globalcut, Ctemp );

    int treenum=-1, currenttreenum=-1;

    BB_optics_tree *Ttemp = new BB_optics_tree(Ctemp);

    Ctemp->SetBranchStatus("*",0);
    Ctemp->SetBranchStatus("bb.tr.*",1);
    Ctemp->SetBranchStatus("bb.gem.track.*",1);
    Ctemp->SetBranchStatus("e.kine.*",1);
    Ctemp->SetBranchStatus("bb.grinch_tdc.clus.*",1);
    Ctemp->SetBranchStatus("bb.etot_over_p",1);
    Ctemp->SetBranchStatus("bb.ps.e",1);
    Ctemp->SetBranchStatus("bb.sh.e",1);
    Ctemp->SetBranchStatus("Lrb.Raster.rawcur.x",1);
    Ctemp->SetBranchStatus("Lrb.Raster.rawcur.y",1);
    
    long nevent=0;

    while( Ctemp->GetEntry( nevent++ ) ){
      treenum = Ctemp->GetTreeNumber();

      if( nevent%10000 == 0 ) cout << "Event " << nevent << endl;
      
      if ( treenum != currenttreenum ){
	cout << "new file " << Ctemp->GetFile()->GetName() << ", event number "
	     << nevent << endl;
	
	currenttreenum = treenum;
	GlobalCut->UpdateFormulaLeaves();
      }

      if( GlobalCut->EvalInstance(0) != 0 ){
	//grab z vertex from tree:
	double zvertex = Ttemp->bb_tr_vz[0];

	//double zspec = zvertex*cos(BBtheta)
	
	for( int ifoil=0; ifoil<nfoils[itarg]; ifoil++ ){
	  if( !skipfoil[itarg][ifoil] && fabs( zvertex - zmean[itarg][ifoil] ) <= nsigma_cut_zvertex * zsigma[itarg][ifoil] ){
	    TH2D *hxytemp = ( (TH2D*) (*xysieve_histos)[ifoil+maxnfoils*itarg] );

	    // The effect of a horizontal beam offset (assuming +XBEAM is to beam RIGHT) is the following:
	    //
	    double xbeamtemp = XBEAM;
	    double ybeamtemp = YBEAM;
	    if( raster_flag != 0 ){
	      double rastx_temp = (Ttemp->Lrb_Raster_rawcur_x - 0.5*(rasterx_min_raw+rasterx_max_raw))*(rastersize_x_mm/1000.0)/(rasterx_max_raw-rasterx_min_raw);
	      double rasty_temp = (Ttemp->Lrb_Raster_rawcur_y - 0.5*(rastery_min_raw+rastery_max_raw))*(rastersize_y_mm/1000.0)/(rastery_max_raw-rastery_min_raw);
	      xbeamtemp += rastx_temp;
	      ybeamtemp += rasty_temp;
	    }
	    
	    double zspec = zfoil[itarg][ifoil]*cos(BBtheta) - xbeamtemp*sin(BBtheta);
	    double yspec = -zfoil[itarg][ifoil]*sin(BBtheta) - xbeamtemp*cos(BBtheta);
	    double xspec = -ybeamtemp;
	     
	    double xsieve = xspec+Ttemp->bb_tr_tg_th[0]*(ZSIEVE-zspec);
	    double ysieve = yspec+Ttemp->bb_tr_tg_ph[0]*(ZSIEVE-zspec);

	    hxytemp->Fill( ysieve, xsieve );
	  }
	}
	
      }
    }

    Ctemp->Delete();
  }

  TFile *fout = new TFile(outfilename, "RECREATE");

  // AJRP 9/24/2026: the ZSIEVE value we use is projected to the midpoint of the sieve, therefore we should use the X coordinates of the midpoint
  // to be consistent:

  Double_t inch = 2.54/100.0;

  Double_t sieve_height = 27.50*inch;
  
  Double_t sieve_thick = 1.5*inch; //1.5 inches converted to meters

  // xoff/(thick/2) = tan(theta) --> xoff = thick/2 * tan(theta)
  
  Double_t xs_cent_midpoint[13] =
    { -sieve_height/2.0+1.942*inch/cos(18.0*PI/180.0) - sieve_thick/2.0*tan(18.0*PI/180.0),
      -sieve_height/2.0+(1.942+1.938)*inch/cos(18.0*PI/180.0) - sieve_thick/2.0*tan(18.0*PI/180.0),
      -sieve_height/2.0+5.879*inch/cos(9.0*PI/180.0) - sieve_thick/2.0*tan(9.0*PI/180.0),
      -sieve_height/2.0+(5.879+1.938)*inch/cos(9.0*PI/180.0) - sieve_thick/2.0*tan(9.0*PI/180.0),
      -sieve_height/2.0+(5.879+2.0*1.938)*inch/cos(9.0*PI/180.0) - sieve_thick/2.0*tan(9.0*PI/180.0),
      -1.938*inch,
      0.0,
      1.938*inch,
      sieve_height/2.0-(5.879+2.0*1.938)*inch/cos(9.0*PI/180.0) + sieve_thick/2.0*tan(9.0*PI/180.0),
      sieve_height/2.0-(5.879+1.938)*inch/cos(9.0*PI/180.0) + sieve_thick/2.0*tan(9.0*PI/180.0),
      sieve_height/2.0-5.879*inch/cos(9.0*PI/180.0) + sieve_thick/2.0*tan(9.0*PI/180.0),
      sieve_height/2.0-(1.942+1.938)*inch/cos(18.0*PI/180.0) + sieve_thick/2.0*tan(18.0*PI/180.0),
      sieve_height/2.0-1.942*inch/cos(18.0*PI/180.0) + sieve_thick/2.0*tan(18.0*PI/180.0)
    };
 
  //Here are the desired sieve positions:
  vector <Double_t> xs_cent{-(0.3+0.0492)+0.0493/cos(18.*PI/180.),
      -(0.3+0.0492)+(0.0493+0.0492)/cos(18.*PI/180.),
      -(0.3+0.0492)+0.1493/cos(9.*PI/180.),
      -(0.3+0.0492)+(0.1493+0.0492)/cos(9.*PI/180.),
      -(0.3+0.0492)+(0.1493+0.0492*2.)/cos(9.*PI/180.),
      -0.0492,
      0.0,
      0.0492,
      0.3+0.0492-(0.1493+0.0492*2.)/cos(9.*PI/180.),
      0.3+0.0492-(0.1493+0.0492)/cos(9.*PI/180.),
      0.3+0.0492-0.1493/cos(9.*PI/180.),
      0.3+0.0492-(0.0493+0.0492)/cos(18.*PI/180),
      0.3+0.0492-0.0493/cos(18.*PI/180.)};
   
  //Add in any XSIEVE offset defined by the user:
  for( int ix=0; ix<nxsieve; ix++ ){
    xs_cent[ix] = xs_cent_midpoint[ix]; //comment this line to use the "OLD" sieve positions
    xs_cent[ix] += XOFFSIEVE;
  }

  double yspace = 1.5*inch;
  
  vector <Double_t> ys_cent;
  for (Int_t nys=0;nys<nysieve;nys++) {
    Double_t pos=yspace * (nys-3);//old sieve
    ys_cent.push_back(pos + YOFFSIEVE);
  }

  vector<bool> goodfithole(ntargets*maxnfoils*nxsieve*nysieve,false);
  vector<double> xmean_hole(ntargets*maxnfoils*nxsieve*nysieve,0.0);
  vector<double> ymean_hole(ntargets*maxnfoils*nxsieve*nysieve,0.0);
  vector<double> xsigma_hole(ntargets*maxnfoils*nxsieve*nysieve,0.0);
  vector<double> ysigma_hole(ntargets*maxnfoils*nxsieve*nysieve,0.0);

  yspace = 0.0381;
  double xspace = 0.0492; 

  TCanvas *cfit = new TCanvas("cfit","cfit",1600,700);

  cfit->Divide(3,1,.001,.001);

  for( int itarg=0; itarg<ntargets; itarg++ ){
    for( int ifoil=0; ifoil<nfoils[itarg]; ifoil++ ){
      TH2D *hxysieve_temp = ( (TH2D*) (*xysieve_histos)[ifoil+maxnfoils*itarg] );

      cfit->cd(3);
      hxysieve_temp->Draw("colz");
      
      for( int ix=0; ix<nxsieve; ix++ ){
	for( int iy=0; iy<nysieve; iy++ ){

	  int holeindex = iy + nysieve*ix + nxsieve*nysieve*ifoil + nxsieve*nysieve*maxnfoils*itarg;
	  
	  double ylow = ys_cent[iy] - 0.4*yspace;
	  double yhigh = ys_cent[iy] + 0.4*yspace;
	  double xlow = xs_cent[ix] - 0.4*xspace;
	  double xhigh = xs_cent[ix] + 0.4*xspace;

	  int binz;
	  int binylo, binyhi, binxlo, binxhi;
	  hxysieve_temp->GetBinXYZ( hxysieve_temp->FindBin(ylow,xlow), binylo, binxlo, binz );
	  hxysieve_temp->GetBinXYZ( hxysieve_temp->FindBin(yhigh,xhigh), binyhi, binxhi, binz );

	  TString histname;
	  TH1D *hxtemp = hxysieve_temp->ProjectionY( histname.Format( "hxsieve_targ%d_foil%d_x%d_y%d", itarg, ifoil, ix, iy ), binylo, binyhi );
	  TH1D *hytemp = hxysieve_temp->ProjectionX( histname.Format( "hysieve_targ%d_foil%d_x%d_y%d", itarg, ifoil, ix, iy ), binxlo, binxhi );

	  double xmin_fit = xs_cent[ix]-0.5*xspace;
	  double xmax_fit = xs_cent[ix]+0.5*xspace;
	  double ymin_fit = ys_cent[iy]-0.5*yspace; 
	  double ymax_fit = ys_cent[iy]+0.5*yspace;

	  bool goodfit = false;
	  bool skiphole = false;

	  while( !goodfit ){
	    TLine L;
	    L.SetLineColor(2);

	    cfit->cd(1)->SetGrid();
	    hxtemp->Draw();

	    hxtemp->GetXaxis()->SetRangeUser(xmin_fit-1.5*xspace,xmax_fit+1.5*xspace);

	    bool goodx = false, goody = false;
	    
	    if( hxtemp->Integral(hxtemp->FindBin(xmin_fit),hxtemp->FindBin(xmax_fit)) >= 50 ){
	      goodx = true;
	      L.DrawLine( xs_cent[ix], 0, xs_cent[ix], hxtemp->GetMaximum());
	      
	      TFitResultPtr xfit = hxtemp->Fit("gaus","S","",xmin_fit, xmax_fit);
	      goodx = xfit->IsValid();
	    }

	    cfit->cd(2)->SetGrid();
	    hytemp->Draw();
	    hytemp->GetXaxis()->SetRangeUser(ys_cent[iy]-2.0*yspace,ys_cent[iy]+2.0*yspace);
	    
	    if( hytemp->Integral(hytemp->FindBin(ymin_fit),hytemp->FindBin(ymax_fit)) >= 50 ){
	      goody = true;
	      L.DrawLine( ys_cent[iy], 0, ys_cent[iy], hytemp->GetMaximum());
	      
	      TFitResultPtr yfit = hytemp->Fit("gaus","S","",ymin_fit, ymax_fit);
	      goody = yfit->IsValid();
	    }
	    cfit->cd(3)->SetGrid();
	    hxysieve_temp->Draw("colz");

	    L.DrawLine( ys_cent[iy],-0.3,ys_cent[iy], 0.3);
	    L.DrawLine( -0.15, xs_cent[ix], 0.15, xs_cent[ix] );

	    if( goodx && goody ){
	      double xfit = ( (TF1*) hxtemp->GetListOfFunctions()->FindObject("gaus") )->GetParameter("Mean");
	      double yfit = ( (TF1*) hytemp->GetListOfFunctions()->FindObject("gaus") )->GetParameter("Mean");
	  
	      double xsigma = ( (TF1*) hxtemp->GetListOfFunctions()->FindObject("gaus") )->GetParameter("Sigma");
	      double ysigma = ( (TF1*) hytemp->GetListOfFunctions()->FindObject("gaus") )->GetParameter("Sigma");
	  
	      TEllipse holecut(yfit,xfit,2.0*ysigma,2.0*xsigma);
	      holecut.SetLineColor(kMagenta);
	      holecut.SetLineWidth(2);
	  
	      holecut.SetFillStyle(0);
	      holecut.Draw("SAME");
	  
	      cfit->Update();
	      gPad->Modified();
	      gSystem->ProcessEvents();

	      
	  
	      xmean_hole[holeindex] = xfit;
	      ymean_hole[holeindex] = yfit;
	      xsigma_hole[holeindex] = xsigma;
	      ysigma_hole[holeindex] = ysigma;
 
	      cout << "Fit okay? (y/n/s = skip)";
	  
	      TString reply;
	      reply.ReadLine(cin,kTRUE);
	  
	      reply.ToLower();
	  
	      if( reply.BeginsWith("n") ){
		cout << "xmin for fit = "; 
	    
		cin >> xmin_fit;
		cout << "xmax for fit = ";
		cin >> xmax_fit;
		cout << "ymin for fit = ";
		cin >> ymin_fit;
		cout << "ymax for fit = ";
		cin >> ymax_fit; 
	    
	      } else if ( reply.BeginsWith("s") ){
		goodfit = true;
		skiphole = true;
	      } else {
		goodfit = true;
		skiphole = false;
	      }
	    } else {
	      goodfit = true;
	      skiphole = true;
	    }
	  } //end while ! goodfit

	  hxtemp->Delete();
	  hytemp->Delete();

	  goodfithole[iy + nysieve * ix + nxsieve*nysieve * ifoil + nxsieve*nysieve*maxnfoils*itarg ] = !skiphole;
	  
	} //end loop over ysieve 
      } //end loop over xsieve
    } //end loop over target foils 
  } //end loop over targets

  //Next step: set up the matrices for the fit and loop over everything again:

  int nterms=0;

  vector<int> xtar_expon;
  vector<int> xfp_expon;
  vector<int> xpfp_expon;
  vector<int> yfp_expon;
  vector<int> ypfp_expon;
  
  for( int i=0; i<=order; i++ ){
    for( int j=0; j<=order-i; j++ ){
      for( int k=0; k<=order-i-j; k++ ){
	for( int l=0; l<=order-i-j-k; l++ ){
	  for( int m=0; m<=order-i-j-k-l; m++ ){
	    nterms++;
	    xtar_expon.push_back( i );
	    xfp_expon.push_back( m );
	    yfp_expon.push_back( l );
	    xpfp_expon.push_back( k );
	    ypfp_expon.push_back( j );
	  }
	}
      }
    }
  }
  
  TMatrixD M(nterms,nterms);
  //TMatrixD Mforward(nterms,nterms);
  TVectorD b_ytar(nterms);
  TVectorD b_xptar(nterms);
  TVectorD b_yptar(nterms);
  
  //  TVectorD b_xfp(nterms), b_yfp(nterms), b_xpfp(nterms), b_ypfp(nterms);

  for(int i=0; i<nterms; i++){
    for(int j=0; j<nterms; j++){
      M(i,j) = 0.0;
      //Mforward(i,j) = 0.0;
      //M_etof(i,j) = 0.0;
    }
    b_xptar(i) = 0.0;
    b_yptar(i) = 0.0;
    b_ytar(i) = 0.0;
    //b_pinv(i) = 0.0;
    
    // b_xfp(i) = 0.0;
    // b_yfp(i) = 0.0;
    // b_xpfp(i) = 0.0;
    // b_ypfp(i) = 0.0;

    // b_etof(i) = 0.0;
  }

  //Next up we've got to loop over all the data from all the targets to set up the fit with foil/hole cuts.
  //Then we'll need to do one MORE loop over the data to generate quality-check plots:

  //This loop will ONLY be for setting up and doing the fit:
  for( int itarg=0; itarg<ntargets; itarg++ ){
     
    TChain *Ctemp = new TChain("T");
    for( int ifile=0; ifile<list_of_files_by_target[itarg].size(); ifile++ ){
      Ctemp->Add( list_of_files_by_target[itarg][ifile] );
    }

    
    TTreeFormula *GlobalCut = new TTreeFormula( "GlobalCut", globalcut, Ctemp );

    int treenum=-1, currenttreenum=-1;

    BB_optics_tree *Ttemp = new BB_optics_tree(Ctemp);

    Ctemp->SetBranchStatus("*",0);
    Ctemp->SetBranchStatus("bb.tr.*",1);
    Ctemp->SetBranchStatus("bb.gem.track.*",1);
    Ctemp->SetBranchStatus("e.kine.*",1);
    Ctemp->SetBranchStatus("bb.grinch_tdc.clus.*",1);
    Ctemp->SetBranchStatus("bb.etot_over_p",1);
    Ctemp->SetBranchStatus("bb.ps.e",1);
    Ctemp->SetBranchStatus("bb.sh.e",1);
    Ctemp->SetBranchStatus("Lrb.Raster.rawcur.x",1);
    Ctemp->SetBranchStatus("Lrb.Raster.rawcur.y",1);
    
    long nevent=0;

    while( Ctemp->GetEntry( nevent++ ) ){
      treenum = Ctemp->GetTreeNumber();

      if( nevent%10000 == 0 ) cout << "Event " << nevent << endl;
      
      if ( treenum != currenttreenum ){
	cout << "new file " << Ctemp->GetFile()->GetName() << ", event number "
	     << nevent << endl;
	
	currenttreenum = treenum;
	GlobalCut->UpdateFormulaLeaves();
      }

      if( GlobalCut->EvalInstance(0) != 0 ){
	//first, check foil cuts;
	double zvertex = Ttemp->bb_tr_vz[0];
	for( int ifoil=0; ifoil<nfoils[itarg]; ifoil++ ){
	  if( fabs( zvertex - zmean[itarg][ifoil] ) <= nsigma_cut_zvertex * zsigma[itarg][ifoil] ){
	    //now loop over sieve hole cuts:
	    for( int ix=0; ix<nxsieve; ix++ ){
	      for( int iy=0; iy<nysieve; iy++ ){
		int holeindex= iy + nysieve*ix + nxsieve*nysieve*ifoil + nxsieve*nysieve*maxnfoils*itarg;
		if( goodfithole[holeindex] ){ //Calculate whether the current track passes through this hole and if so, increment matrices:

		  //calculate xsieve, ysieve the same way we did in filling the histograms:
		  double xbeamtemp = XBEAM;
		  double ybeamtemp = YBEAM;
		  if( raster_flag != 0 ){
		    double rastx_temp = (Ttemp->Lrb_Raster_rawcur_x - 0.5*(rasterx_min_raw+rasterx_max_raw))*(rastersize_x_mm/1000.0)/(rasterx_max_raw-rasterx_min_raw);
		    double rasty_temp = (Ttemp->Lrb_Raster_rawcur_y - 0.5*(rastery_min_raw+rastery_max_raw))*(rastersize_y_mm/1000.0)/(rastery_max_raw-rastery_min_raw);
		    xbeamtemp += rastx_temp;
		    ybeamtemp += rasty_temp;
		  }
		  
		  //Calculate xsieve and ysieve same way as before:
		  double zspec = zfoil[itarg][ifoil] * cos(BBtheta) - xbeamtemp*sin(BBtheta);
		  double yspec = -zfoil[itarg][ifoil] * sin(BBtheta) - xbeamtemp*cos(BBtheta);
		  double xspec = -ybeamtemp;
		  
		  double xsieve = xspec+Ttemp->bb_tr_tg_th[0]*(ZSIEVE-zspec);
		  double ysieve = yspec+Ttemp->bb_tr_tg_ph[0]*(ZSIEVE-zspec);

		  if( sqrt( pow( (xsieve-xmean_hole[holeindex])/xsigma_hole[holeindex], 2 ) +
			    pow( (ysieve-ymean_hole[holeindex])/ysigma_hole[holeindex], 2 ) ) <= nsigma_cut_xysieve ){
		    //Good event; calculate "true" kinematics and increment fit matrices:
		    // beam intersection with foil is at (0,0,zfoil)
		    double vzBBtrue = zspec;
		    double vyBBtrue = yspec;
		    double vxBBtrue = xspec; //to be refined later with raster/BPM/mispointing info
		    double xptartrue = (xs_cent[ix]-vxBBtrue)/(ZSIEVE-vzBBtrue);
		    double yptartrue = (ys_cent[iy]-vyBBtrue)/(ZSIEVE-vzBBtrue);
		    double ytartrue = vyBBtrue - yptartrue * vzBBtrue;
		    double xtartrue = vxBBtrue - xptartrue * vzBBtrue;

		    double xfp = Ttemp->bb_tr_r_x[0];
		    double yfp = Ttemp->bb_tr_r_y[0];
		    double thfp = Ttemp->bb_tr_r_th[0];
		    double phfp = Ttemp->bb_tr_r_ph[0];

		    vector<double> term(nterms);
		     
		    for( int ipar=0; ipar<nterms; ipar++ ){
		      term[ipar] = pow(xfp,xfp_expon[ipar]) * pow( yfp, yfp_expon[ipar] ) * pow( thfp, xpfp_expon[ipar] ) * pow( phfp, ypfp_expon[ipar] ) * pow( xtartrue, xtar_expon[ipar] );
		      b_xptar(ipar) += term[ipar] * xptartrue;
		      b_yptar(ipar) += term[ipar] * yptartrue;
		      b_ytar(ipar) += term[ipar] * ytartrue;
		    }

		    for( int ipar=0; ipar<nterms; ipar++ ){
		      for( int jpar=0; jpar<nterms; jpar++ ){
			M(ipar,jpar) += term[ipar]*term[jpar];
		      }
		    }
		    //-----------------------------------
		  } //end check for hole cuts:
		} //end check if hole had a good fit for this foil
	      } //end loop over y sieve holes
	    } //end loop over x sieve holes
	  } //end if block for z vertex cut
	} //end loop over foils
      } //end check on global cut 
    } //end main event loop

    Ctemp->Delete();
  } //loop over targets

  if( xtar_flag == 0 ){
    for( int ipar=0; ipar<nterms; ipar++ ){
      if( xtar_expon[ipar] != 0 ){
	b_xptar(ipar) = 0.0;
	b_yptar(ipar) = 0.0;
	b_ytar(ipar) = 0.0;
	for( int jpar=0; jpar<nterms; jpar++ ){
	  if( jpar != ipar ){
	    M(ipar,jpar) = 0.0;
	    M(jpar,ipar) = 0.0;
	  }
	}
	M(ipar,ipar) = 1.0;
      }
    }
  }
    
  
  TDecompSVD A_xptar(M);
  TDecompSVD A_yptar(M);
  TDecompSVD A_ytar(M);

  A_xptar.Solve(b_xptar);
  A_yptar.Solve(b_yptar);
  A_ytar.Solve(b_ytar);
  
  TString dbfilename = outfilename;

  dbfilename.ReplaceAll(".root",".dat");

  ofstream dbfile(dbfilename);
  
  dbfile << "bb.optics_order = " << order << endl;
  dbfile << "bb.optics_parameters = " << endl;
  TString Cline;
  for( int i=0; i<nterms; i++ ){
    Cline.Form( "%15.9g %15.9g %15.9g %15.9g        %d %d %d %d %d", b_xptar(i), b_yptar(i), b_ytar(i),
		0.0, xfp_expon[i], yfp_expon[i], xpfp_expon[i], ypfp_expon[i], xtar_expon[i] );
    dbfile << Cline << endl;
  }

  //Final loop: diagnostics; also put together output tree:
  //TT
  
  fout->cd();

  TTree *Tout = new TTree("Tout","BigBite Optics Results");
  double T_xtartrue;
  double T_ytartrue;
  double T_xptartrue;
  double T_yptartrue;
  double T_vztrue;
  double T_vz_recon, T_vz_recon_old;
  double T_precon;
  double T_xfp, T_yfp, T_thfp, T_phfp;
  double T_xtar_recon, T_ytar_recon, T_xptar_recon, T_yptar_recon;
  double T_xtar_recon_old, T_ytar_recon_old, T_xptar_recon_old, T_yptar_recon_old;

  double T_rasterx_raw, T_rastery_raw, T_rasterx_m, T_rastery_m;
  //Note: add beam position variables later:
  int T_itarg, T_ifoil, T_ixhole, T_iyhole;

  double T_xsieve_old, T_ysieve_old;
  double T_xsieve, T_ysieve;
  
  Tout->Branch( "itarg", &T_itarg, "itarg/I" );
  Tout->Branch( "ifoil", &T_ifoil, "ifoil/I" );
  Tout->Branch( "ixhole", &T_ixhole, "ixhole/I" );
  Tout->Branch( "iyhole", &T_iyhole, "iyhole/I" );
  
  Tout->Branch( "xfp", &T_xfp, "xfp/D");
  Tout->Branch( "yfp", &T_yfp, "yfp/D");
  Tout->Branch( "thfp", &T_thfp, "thfp/D");
  Tout->Branch( "phfp", &T_phfp, "phfp/D");
  
  Tout->Branch( "xtartrue", &T_xtartrue, "xtartrue/D" );
  Tout->Branch( "ytartrue", &T_ytartrue, "ytartrue/D" );
  Tout->Branch( "xptartrue", &T_xptartrue, "xptartrue/D" );
  Tout->Branch( "yptartrue", &T_yptartrue, "yptartrue/D" );
  Tout->Branch( "vztrue", &T_vztrue, "vztrue/D" );

  Tout->Branch( "precon", &T_precon, "precon/D" );
  
  Tout->Branch( "xtar_recon", &T_xtar_recon, "xtar_recon/D" );
  Tout->Branch( "ytar_recon", &T_ytar_recon, "ytar_recon/D" );
  Tout->Branch( "xptar_recon", &T_xptar_recon, "xptar_recon/D" );
  Tout->Branch( "yptar_recon", &T_yptar_recon, "yptar_recon/D" );
  Tout->Branch( "vz_recon", &T_vz_recon, "vz_recon/D" );
  
  Tout->Branch( "xtar_recon_old", &T_xtar_recon_old, "xtar_recon_old/D" );
  Tout->Branch( "ytar_recon_old", &T_ytar_recon_old, "ytar_recon_old/D" );
  Tout->Branch( "xptar_recon_old", &T_xptar_recon_old, "xptar_recon_old/D" );
  Tout->Branch( "yptar_recon_old", &T_yptar_recon_old, "yptar_recon_old/D" );
  Tout->Branch( "vz_recon_old", &T_vz_recon_old, "vz_recon_old/D" );
  Tout->Branch( "xsieve", &T_xsieve, "xsieve/D" );
  Tout->Branch( "ysieve", &T_ysieve, "ysieve/D" );
  Tout->Branch( "xsieve_old", &T_xsieve_old, "xsieve_old/D" );
  Tout->Branch( "ysieve_old", &T_ysieve_old, "ysieve_old/D" );

  Tout->Branch( "rasterx_raw", &T_rasterx_raw, "rasterx_raw/D");
  Tout->Branch( "rastery_raw", &T_rastery_raw, "rastery_raw/D");

  Tout->Branch( "rasterx_m", &T_rasterx_m, "rasterx_m/D");
  Tout->Branch( "rastery_m", &T_rastery_m, "rastery_m/D");

  for( int itarg=0; itarg<ntargets; itarg++ ){
     
    TChain *Ctemp = new TChain("T");
    for( int ifile=0; ifile<list_of_files_by_target[itarg].size(); ifile++ ){
      Ctemp->Add( list_of_files_by_target[itarg][ifile] );
    }

    
    TTreeFormula *GlobalCut = new TTreeFormula( "GlobalCut", globalcut, Ctemp );

    int treenum=-1, currenttreenum=-1;

    BB_optics_tree *Ttemp = new BB_optics_tree(Ctemp);

    Ctemp->SetBranchStatus("*",0);
    Ctemp->SetBranchStatus("bb.tr.*",1);
    Ctemp->SetBranchStatus("bb.gem.track.*",1);
    Ctemp->SetBranchStatus("e.kine.*",1);
    Ctemp->SetBranchStatus("bb.grinch_tdc.clus.*",1);
    Ctemp->SetBranchStatus("bb.etot_over_p",1);
    Ctemp->SetBranchStatus("bb.ps.e",1);
    Ctemp->SetBranchStatus("bb.sh.e",1);
    Ctemp->SetBranchStatus("Lrb.Raster.rawcur.x",1);
    Ctemp->SetBranchStatus("Lrb.Raster.rawcur.y",1);
    
    long nevent=0;

    while( Ctemp->GetEntry( nevent++ ) ){
      treenum = Ctemp->GetTreeNumber();

      if( nevent%10000 == 0 ) cout << "Event " << nevent << endl;
      
      if ( treenum != currenttreenum ){
	cout << "new file " << Ctemp->GetFile()->GetName() << ", event number "
	     << nevent << endl;
	
	currenttreenum = treenum;
	GlobalCut->UpdateFormulaLeaves();
      }

      if( GlobalCut->EvalInstance(0) != 0 ){ //Check cuts but also do reconstruction for all tracks passing global cuts:
	//first, check foil cuts;
	double zvertex = Ttemp->bb_tr_vz[0];

	T_vz_recon_old = zvertex;
	
	T_xfp = Ttemp->bb_tr_r_x[0];
	T_yfp = Ttemp->bb_tr_r_y[0];
	T_thfp = Ttemp->bb_tr_r_th[0];
	T_phfp = Ttemp->bb_tr_r_ph[0];

	T_xtar_recon_old = Ttemp->bb_tr_tg_x[0];
	T_ytar_recon_old = Ttemp->bb_tr_tg_y[0];
	T_xptar_recon_old = Ttemp->bb_tr_tg_th[0];
	T_yptar_recon_old = Ttemp->bb_tr_tg_ph[0];
	T_precon = Ttemp->bb_tr_p[0];

	//Calculate "old" xsieve and ysieve, same way as before, except this time use reconstructed vertex z instead of "true"
	double xbeamtemp = XBEAM;
	double ybeamtemp = YBEAM;
	if( raster_flag != 0 ){
	  double rastx_temp = (Ttemp->Lrb_Raster_rawcur_x - 0.5*(rasterx_min_raw+rasterx_max_raw))*(rastersize_x_mm/1000.0)/(rasterx_max_raw-rasterx_min_raw);
	  double rasty_temp = (Ttemp->Lrb_Raster_rawcur_y - 0.5*(rastery_min_raw+rastery_max_raw))*(rastersize_y_mm/1000.0)/(rastery_max_raw-rastery_min_raw);
	  xbeamtemp += rastx_temp;
	  ybeamtemp += rasty_temp;
	}

	double zspec = zvertex*cos(BBtheta);

	// Here we should NOT subtract "zspec" from ZSIEVE, since target x and y are already evaluated at zspec = 0!
	T_xsieve_old = Ttemp->bb_tr_tg_x[0]+Ttemp->bb_tr_tg_th[0]*(ZSIEVE);
	T_ysieve_old = Ttemp->bb_tr_tg_y[0]+Ttemp->bb_tr_tg_ph[0]*(ZSIEVE);

	T_rasterx_raw = Ttemp->Lrb_Raster_rawcur_x;
	T_rastery_raw = Ttemp->Lrb_Raster_rawcur_y;
	//To be updated with calibration.
	//T_rasterx_m = 0.0;
	//T_rastery_m = 0.0;

	T_rasterx_m = (T_rasterx_raw - 0.5*(rasterx_min_raw+rasterx_max_raw))*(rastersize_x_mm/1000.0)/(rasterx_max_raw-rasterx_min_raw);
	T_rastery_m = (T_rastery_raw - 0.5*(rastery_min_raw+rastery_max_raw))*(rastersize_y_mm/1000.0)/(rastery_max_raw-rastery_min_raw);
	
	//now calculate reconstructed tracks:
	
	int niter = 3;
	if( xtar_flag == 0 ) niter=1;
	
	double xtartemp = -ybeamtemp;
	
	for( int iter=0; iter<niter; iter++ ){
	  double sum_xptar = 0.0, sum_yptar = 0.0, sum_ytar = 0.0;
	  
	  for( int i=0; i<nterms; i++ ){
	    double term = pow( T_xfp, xfp_expon[i] ) * pow( T_yfp, yfp_expon[i] ) *
	      pow( T_thfp, xpfp_expon[i] ) * pow( T_phfp, ypfp_expon[i] ) *
	      pow( xtartemp, xtar_expon[i] );

	    sum_xptar += term * b_xptar(i);
	    sum_yptar += term * b_yptar(i);
	    sum_ytar += term * b_ytar(i);
	  }

	  //BB on beam left: ytar = -vz*sin(theta) - vz * cos(theta) * phtar
	  // ytar = -vz*(sin(theta)+phtar*cos(theta))
	  // vz = -ytar/(sin(theta)+phtar*cos(theta))

	  //Now for zbeam reconstruction, we need to take into account the effect of xbeam; ASSUMING BB on beam left and
	  // +Xbeam to beam right, then the effect of a horizontal beam offset on vertex Z is 
	  
	  double vztemp = -(sum_ytar + xbeamtemp*(cos(BBtheta)-sum_yptar*sin(BBtheta)))/(sin(BBtheta)+sum_yptar*cos(BBtheta));
	  xtartemp = -ybeamtemp -sum_xptar*vztemp*cos(BBtheta);

	  T_xtar_recon = xtartemp;
	  T_xptar_recon = sum_xptar;
	  T_yptar_recon = sum_yptar;
	  T_ytar_recon = sum_ytar;
	  T_vz_recon = vztemp;
	}

	
	//zspec = T_vz_recon * cos(BBtheta);
	
	//In calculating xsieve, ysieve from new reconstructed quantities, we should NOT subtract off zspec,
	//since xtar and ytar are already reconstructed at zspec = 0!
	T_xsieve = T_xtar_recon + T_xptar_recon * (ZSIEVE);
	T_ysieve = T_ytar_recon + T_yptar_recon * (ZSIEVE);
	
	// Check whether track passed vertex and/or hole cuts to calculate "true"
	// vertex and angles:
	T_ifoil=-1;
	T_itarg=itarg;
	T_ixhole = -1;
	T_iyhole = -1;

	T_xtartrue = -1000.;
	T_ytartrue = -1000.;
	T_xptartrue = -1000.;
	T_yptartrue = -1000.;
	T_vztrue = -1000.;

	//"True" quantities are only calculated for tracks passing vertex and hole cuts:
	int ifoil_mindiff=-1;
	double mindiff_zfoil = 10.0;
	for( int ifoil=0; ifoil<nfoils[itarg]; ifoil++ ){
	  double zdiff = zvertex - zmean[itarg][ifoil];  //z vertex cuts are based on OLD reconstruction.
	  if( !skipfoil[itarg][ifoil] && fabs( zdiff ) <= nsigma_cut_zvertex * zsigma[itarg][ifoil] ){
	    if( ifoil_mindiff<0 || fabs( zdiff ) < mindiff_zfoil ){
	      ifoil_mindiff = ifoil;
	      mindiff_zfoil = fabs( zdiff );
	    }
	  }
	}

	if( ifoil_mindiff >= 0 ){
	  T_ifoil = ifoil_mindiff;
	  //loop on sieve holes:
	  for( int ix=0; ix<nxsieve; ix++ ){
	    for( int iy=0; iy<nysieve; iy++ ){

	      //Here we need to actually calculate xsieve and ysieve the same way they were used to fill the histograms, using the "true" vertex positions, in order to have consistency of cuts
	      double vzspec =  zfoil[itarg][ifoil_mindiff] * cos(BBtheta) - xbeamtemp*sin(BBtheta);
	      double vyspec = -zfoil[itarg][ifoil_mindiff] * sin(BBtheta) - xbeamtemp*cos(BBtheta);
	      double vxspec = -ybeamtemp;

	      double xsieve = vxspec + T_xptar_recon_old * (ZSIEVE-vzspec);
	      double ysieve = vyspec + T_yptar_recon_old * (ZSIEVE-vzspec);
	      
	      int holeindex = iy + nysieve*ix + nxsieve*nysieve*ifoil_mindiff + nxsieve*nysieve*maxnfoils*itarg;
	      if( goodfithole[holeindex] && sqrt( pow( (xsieve-xmean_hole[holeindex])/xsigma_hole[holeindex], 2 ) +
			pow( (ysieve-ymean_hole[holeindex])/ysigma_hole[holeindex], 2 ) ) <= nsigma_cut_xysieve ){
		T_ixhole = ix;
		T_iyhole = iy;
		
		T_vztrue = zfoil[itarg][ifoil_mindiff];
		
		T_xptartrue = (xs_cent[ix]-vxspec)/(ZSIEVE-vzspec);
		T_yptartrue = (ys_cent[iy]-vyspec)/(ZSIEVE-vzspec);
		T_ytartrue = vyspec - T_yptartrue * vzspec;
		T_xtartrue = vxspec - T_xptartrue * vzspec; 
	      }
	    }
	  }
	}
	Tout->Fill();
      }
    }
  }
	 
  
  zvertex_histos->Compress();
  xysieve_histos->Compress();
  zvertex_histos->Write();
  xysieve_histos->Write();
 
  Tout->Write();

  fout->Close();
  
 
}//end program
