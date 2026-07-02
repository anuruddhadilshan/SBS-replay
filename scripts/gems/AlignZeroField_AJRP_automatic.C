#include "TVector3.h"
#include "TMinuit.h"
#include "TMath.h"
#include "TObjArray.h"
#include "TObjString.h"
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
#include "TTreeFormula.h"
#include "TRotation.h"
#include <iostream>
#include <fstream>

const int nxsieve = 13;
const int nysieve = 7;

const double PI = TMath::Pi();

//Example code to align the GEM stack relative to the spectrometer coordinate system and determine distance from target to sieve plate using
//known dimensions and hole spacings of sieve and known dimensions and internal alignments of GEMs:
//We are going to be lazy and use MINUIT even though this problem could easily be linearized:

const double sigma_targpos = 0.002; //assume 2 mm resolution on track projection to target
const double sigma_pos = 0.002; //we really need to account for sieve hole size in the resolution here
const double sigma_slope = sigma_pos/1.6; //0.1 mm/1.6 m ~= 6e-5 gives rough order of magnitude for slope uncertainty, of course multiple scattering might invalidate that.

int NTRACKS;

//These arrays will be filled by Holly's code to select tracks going through the individual sieve holes:
vector<double> XTRACK,YTRACK,XPTRACK,YPTRACK; //Measured track parameters in GEM internal coordinate system
vector<double> XSIEVE,YSIEVE; //known x and y center positions of the holes the tracks went through.
//We assume the single foil position defines the global origin and acts as a point source of straight-line rays coming through the sieve holes into the GEMS

void CHI2_FCN( int &npar, double *gin, double &f, double *par, int flag ){
  double chi2 = 0.0;

  //Parameters are:
  
  // zsieve: distance from target to sieve along spectrometer central ray
  // (x0,y0,z0): coordinates of the GEM origin relative to the target center in spectrometer coordinates
  // (theta,phi): polar and azimuthal angles of the Z axis of the GEM stack relative to the spectrometer central ray:
  TVector3 GEMPOS(par[0], par[1], par[2] );
  
  double ZSIEVE = par[3];
  double ax = par[4];
  double ay = par[5]; 
  double az = par[6];

  TRotation Rtot;
  //In the BigBite case, we start with the y-axis rotation, as that
  //is the biggest one (roughly 10 degrees):
  //Rtot.RotateX(ax);
  Rtot.RotateY(ay);
  Rtot.RotateZ(az);
  Rtot.RotateX(ax);

  //For the usual convention of a CW rotation as viewed from upstream (right-hand rule) being defined positive, the GEM z axis is rotated
  // by ~-10 degrees wrt TRANSPORT.
  // With this convention, the COLUMNS of the rotation matrix
  // (or the ROWS of the inverse rotation)
  // become the unit vectors;
  TVector3 GEM_zaxis( Rtot.XZ(), Rtot.YZ(), Rtot.ZZ() );
  TVector3 GEM_yaxis( Rtot.XY(), Rtot.YY(), Rtot.ZY() );
  TVector3 GEM_xaxis( Rtot.XX(), Rtot.YX(), Rtot.ZX() );

  //Inverse matrix not needed for this purpose (I think)
  // TRotation Rinv = Rtot.Inverse();
  
  //Define unit vectors along the GEM internal axes with respect to the global system:
  //Obsolete; switch to new definition of coordinate transformation
  //TVector3 GEM_zaxis( sin(thetaGEM)*cos(phiGEM), sin(thetaGEM)*sin(phiGEM), cos(thetaGEM) );
  
  TVector3 Global_yaxis(0,1,0);
  //Not clear if we will need these:
  TVector3 Global_xaxis(1,0,0);
  TVector3 Global_zaxis(0,0,1); 
  
  //  TVector3 GEM_xaxis = (Global_yaxis.Cross( GEM_zaxis )).Unit();
  //  TVector3 GEM_yaxis = (GEM_zaxis.Cross( GEM_xaxis )).Unit();

  
  
  chi2 = 0.0;

  for( int i=0; i<NTRACKS; i++ ){
    //Track position at sieve plate: XSIEVE and YSIEVE have to be determined by Holly's code:
    TVector3 TrackSievePos( XSIEVE[i], YSIEVE[i], ZSIEVE );

    //Track direction 
    TVector3 TrackDirGlobal = TrackSievePos.Unit();
    TVector3 TrackPosLocal( XTRACK[i], YTRACK[i], 0.0 );

    //    TVector3 TrackPosGlobal = Rtot * TrackPosLocal + GEMPOS;
    TVector3 TrackPosGlobal = GEMPOS + GEM_xaxis * TrackPosLocal.X() + GEM_yaxis * TrackPosLocal.Y() + GEM_zaxis * TrackPosLocal.Z();
    //Now compute track intersection with plane of first GEM:
    //Since all tracks start at origin, 
    //Equation is: ( s * TrackDir - GEMPOS ) dot GEM_zaxis = 0
    // OR: s = (GEMPOS dot GEM_zaxis)/(TrackDir dot GEM_zaxis)
    
    //the calculation below ASSUMES that the track originates from the origin:
    double sintersect = GEMPOS.Dot( GEM_zaxis )/(TrackDirGlobal.Dot( GEM_zaxis ) );

    TVector3 TrackIntersect_FirstGEMplane = sintersect * TrackDirGlobal;

    double xfp_expect = (TrackIntersect_FirstGEMplane - GEMPOS).Dot( GEM_xaxis );
    double yfp_expect = (TrackIntersect_FirstGEMplane - GEMPOS).Dot( GEM_yaxis );
    double xpfp_expect = TrackDirGlobal.Dot( GEM_xaxis )/TrackDirGlobal.Dot( GEM_zaxis );
    double ypfp_expect = TrackDirGlobal.Dot( GEM_yaxis )/TrackDirGlobal.Dot( GEM_zaxis );

    //Let's also add target x and target y to the chi2 calculation:
    //Project back to the origin:
    // equation is ( r + nhat * s ) dot zglobal = 0;
    sintersect = -TrackPosGlobal.Dot( Global_zaxis ) / TrackDirGlobal.Dot( Global_zaxis );
    TVector3 TrackIntersect_Origin = TrackPosGlobal + sintersect * TrackDirGlobal;
    double xtar = TrackIntersect_Origin.X();
    double ytar = TrackIntersect_Origin.Y();
    
    chi2 += ( pow( xfp_expect - XTRACK[i], 2 ) + pow( yfp_expect - YTRACK[i], 2 ) ) / (sigma_pos*sigma_pos) +
      ( pow( xpfp_expect - XPTRACK[i], 2 ) + pow( ypfp_expect - YPTRACK[i], 2 ) ) / (sigma_slope*sigma_slope) +
      ( pow( xtar/sigma_targpos, 2 ) + pow( ytar/sigma_targpos, 2 ) );
    
  }
  
  f = chi2;
}

void AlignZeroField( const char *configfilename ){

  TChain *C = new TChain("T");
  
  ifstream configfile(configfilename);

  TString prefix = "bb.gem";

  //These are in spectrometer transport coordinates for an assumed magnet distance of 1.85 m
  double GEMX0=-0.1637, GEMY0=0.0, GEMZ0=2.958;
  double ZSIEVE=1.85-13.37*2.54/100.0; // = 1.51 m
  double XOFFSIEVE = 0.0;
  double YOFFSIEVE = 0.0; 
  double GEMtheta = 10.0*PI/180.0; //this will become the pitch angle
  double GEMphi = 180.0*PI/180.0; 
  double GEMax = 0.0;
  double GEMay = -10.0*PI/180.0;
  double GEMaz = 0.0;

  int fixzsieve = 1;
  
  TCut globalcut = "";
  
  if( configfile ){
    TString currentline;
    
    while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endlist") ){
      if( !currentline.BeginsWith("#") ){
	C->Add(currentline.Data());
      }
    }

    while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endconfig")){
      if( !currentline.BeginsWith("#") ){
	TObjArray *tokens = currentline.Tokenize(" ");
	
	int ntokens = tokens->GetEntries();

	if( ntokens >= 2 ){
	  TString skey = ( (TObjString*) (*tokens)[0] )->GetString();

	  if( skey == "fixzsieve" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    fixzsieve = stemp.Atoi();
	  }
	  
	  if( skey == "prefix" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    prefix = stemp;
	  }

	  if( skey == "GEMX0" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    GEMX0 = stemp.Atof();
	  }
	  if( skey == "GEMY0" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    GEMY0 = stemp.Atof();
	  }

	  if( skey == "GEMZ0" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    GEMZ0 = stemp.Atof();
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

	  if( skey == "GEMtheta" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    GEMtheta = stemp.Atof()*PI/180.0;
	  }

	  if( skey == "GEMphi" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    GEMphi = stemp.Atof()*PI/180.0;
	  }

	  if( skey == "GEMax" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    GEMax = stemp.Atof()*PI/180.0;
	  }

	  if( skey == "GEMay" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    GEMay = stemp.Atof()*PI/180.0;
	  }

	  if( skey == "GEMaz" ){
	    TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	    GEMaz = stemp.Atof()*PI/180.0;
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

  TTreeFormula *GlobalCut = new TTreeFormula( "GlobalCut",globalcut,C );
  
  //  TEventList *elist = new TEventList("elist");
  
  // C->Draw(">>elist",globalcut);
  
  //  cout << "Number of events passing global cut = " << elist->GetN() << endl;

  //TODO: need to declare variables and set tree branch addresses

  UInt_t MAXNTRACKS = 10000;
  
  double ntracks, besttrack;

  //We'll use the GEM track variables directly rather than the BigBite ones to avoid confusion initially.
  //The GEM track variables are guaranteed to be given in the internal GEM coordinates:
  vector<double> tracknhits(MAXNTRACKS);
  vector<double> trackChi2NDF(MAXNTRACKS);
  vector<double> trackX(MAXNTRACKS);
  vector<double> trackY(MAXNTRACKS);
  vector<double> trackXp(MAXNTRACKS);
  vector<double> trackYp(MAXNTRACKS); 

  C->SetBranchStatus("*",0);

  TString branchname;

  C->SetBranchStatus( "bb.tr.*", 1 ); 

  C->SetBranchStatus( "bb.grinch_tdc.clus.*", 1 ); 
  
  C->SetBranchStatus( branchname.Format("%s.track.ntrack",prefix.Data() ), 1 );
  C->SetBranchStatus( branchname.Format("%s.track.chi2ndf",prefix.Data() ), 1 );
  C->SetBranchStatus( branchname.Format("%s.track.x",prefix.Data() ), 1 );
  C->SetBranchStatus( branchname.Format("%s.track.y",prefix.Data() ), 1 );
  C->SetBranchStatus( branchname.Format("%s.track.xp",prefix.Data() ), 1 );
  C->SetBranchStatus( branchname.Format("%s.track.yp",prefix.Data() ), 1 );
  C->SetBranchStatus( branchname.Format("%s.track.nhits",prefix.Data() ), 1 );
  C->SetBranchStatus( branchname.Format("%s.track.besttrack",prefix.Data() ), 1 );
  C->SetBranchStatus( "bb.ps.e", 1 );
  C->SetBranchStatus( "bb.sh.e", 1 );
  //main event loop here:
  C->SetBranchAddress( branchname.Format("%s.track.ntrack",prefix.Data() ), &ntracks );
  C->SetBranchAddress( branchname.Format("%s.track.chi2ndf",prefix.Data() ), &(trackChi2NDF[0]) );
  C->SetBranchAddress( branchname.Format("%s.track.x",prefix.Data() ), &(trackX[0]) );
  C->SetBranchAddress( branchname.Format("%s.track.y",prefix.Data() ), &(trackY[0]) );
  C->SetBranchAddress( branchname.Format("%s.track.xp",prefix.Data() ), &(trackXp[0]) );
  C->SetBranchAddress( branchname.Format("%s.track.yp",prefix.Data() ), &(trackYp[0]) );
  C->SetBranchAddress( branchname.Format("%s.track.nhits",prefix.Data() ), &(tracknhits[0]) );
  C->SetBranchAddress( branchname.Format("%s.track.besttrack",prefix.Data() ), &besttrack );
  
  TObjArray HList(0);
  TFile *fout = new TFile("ZeroFieldAlign_results_new.root","RECREATE");

  TH2D *hxyfp = new TH2D("hxyfp"," ; y_{fp} (m) ; x_{fp} (m)",100,-0.3,0.3,250,-1.1,1.1); HList.Add(hxyfp);
  TH2D *hxysieve = new TH2D("hxysieve", " ; y_{sieve} (m) ; x_{sieve} (m)", 200,-0.2,0.2,200,-0.4,0.4); HList.Add(hxysieve);
  TH2F *hYpFpYFp = new TH2F("hYpFpYFp"," ; Ypfp ; Yfp",100,-.3,.3,100,-0.3,0.3); HList.Add(hYpFpYFp);
  TH2F *hXpFpXFp = new TH2F("hXpFpXFp"," ; Xpfp ; Xfp",100,-.7,.7,100,-0.7,0.7); HList.Add(hXpFpXFp);
  TH2D *hxyfp_sel = new TH2D("hxyfp_sel","with sieve cuts; y_{fp} (m) ; x_{fp} (m)",100,-0.3,0.3,250,-1.1,1.1); HList.Add(hxyfp);
  TH2D *hxysieve_sel = new TH2D("hxysieve_sel", "with sieve cuts; y_{sieve} (m) ; x_{sieve} (m)", 200,-0.4,0.4,200,-0.4,0.4); HList.Add(hxysieve);
  TH2F *hYpFpYFp_sel = new TH2F("hYpFpYFp_sel","with sieve cuts; Ypfp ; Yfp",100,-.3,.3,100,-0.3,0.3); HList.Add(hYpFpYFp);
  TH2F *hXpFpXFp_sel = new TH2F("hXpFpXFp_sel","with sieve cuts; Xpfp ; Xfp",100,-.7,.7,100,-0.7,0.7); HList.Add(hXpFpXFp);

  TH1D *hytar_old = new TH1D("hytar_old",";y_{tar} (m);", 250,-0.025,0.025);
  TH1D *hxtar_old = new TH1D("hxtar_old",";x_{tar} (m);", 250,-0.025,0.025);

  TH1D *hytar_new = new TH1D("hytar_new",";y_{tar} (m);", 250,-0.025,0.025);
  TH1D *hxtar_new = new TH1D("hxtar_new",";x_{tar} (m);", 250,-0.025,0.025);

  
  long nevent=0;

  TVector3 Global_yaxis(0,1,0);
  //Not clear if we will need these:
  TVector3 Global_xaxis(1,0,0);
  TVector3 Global_zaxis(0,0,1);

  TRotation Rtot;
  Rtot.RotateY( GEMay );
  Rtot.RotateZ( GEMaz );
  Rtot.RotateX( GEMax );

  TRotation Rinv = Rtot.Inverse();
  
  TVector3 GEMzaxis( Rtot.XZ(), Rtot.YZ(), Rtot.ZZ() );
  TVector3 GEMyaxis( Rtot.XY(), Rtot.YY(), Rtot.ZY() );
  TVector3 GEMxaxis( Rtot.XX(), Rtot.YX(), Rtot.ZX() );
  //  TVector3 GEMzaxis( sin(GEMtheta)*cos(GEMphi), sin(GEMtheta)*sin(GEMphi), cos(GEMtheta) );
  //TVector3 GEMxaxis = (Global_yaxis.Cross(GEMzaxis)).Unit();
  //TVector3 GEMyaxis = (GEMzaxis.Cross(GEMxaxis)).Unit();
  TVector3 GEMorigin( GEMX0, GEMY0, GEMZ0 );
  TVector3 SieveOrigin(0,0,ZSIEVE);

  

  TString outCutFile;
  outCutFile=Form("sieve_cut.root");
  cout << "outCutFile =  " << outCutFile << endl;
  TFile fcut(outCutFile,"RECREATE");
  TString hname_cut;

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
    xs_cent[ix] += XOFFSIEVE;
  }

  vector <Double_t> ys_cent;
  for (Int_t nys=0;nys<nysieve;nys++) {
    Double_t pos=nys*0.0381-0.0381*3;//old sieve
    ys_cent.push_back(pos + YOFFSIEVE);
  }

  int treenum=-1, currenttreenum=-1;
  
  while( C->GetEntry( nevent++ ) ){

    treenum = C->GetTreeNumber();
    if( treenum != currenttreenum || nevent <= 1 ){
      GlobalCut->UpdateFormulaLeaves();
      currenttreenum = treenum;
    }

    bool passedcut = GlobalCut->EvalInstance(0) != 0;
    
    if( nevent % 1000 == 0 ) cout << "nevent = " << nevent << endl;

    if( passedcut ){
    
      //do stuff: grab track info from tree, apply cuts, fill the track arrays defined near the top of this macro (see XTRACK, YTRACK, XPTRACK, YPTRACK, XSIEVE, YSIEVE above)
      int itr = int(besttrack);
      if( besttrack >= 0 && ntracks <= MAXNTRACKS ){
	hxyfp->Fill( trackY[itr], trackX[itr] );
	hYpFpYFp->Fill(trackYp[itr],trackY[itr]);
	hXpFpXFp->Fill(trackXp[itr],trackX[itr]);
	
	TVector3 TrackPos_local( trackX[itr], trackY[itr], 0.0 );
	TVector3 TrackDir_local( trackXp[itr], trackYp[itr], 1.0 );
	TrackDir_local = TrackDir_local.Unit();
	
	TVector3 TrackDir_global = TrackDir_local.X() * GEMxaxis +
	  TrackDir_local.Y() * GEMyaxis +
	  TrackDir_local.Z() * GEMzaxis;
	//TVector3 TrackDir_global_test = Rinv * TrackDir_local;

	// cout << "Testing two different calculations of track direction in global coordinates: " << endl;
	// cout << "Local track direction: ";
	// TrackDir_local.Print();
	// cout << "Standard calculation: ";
	// TrackDir_global.Print();
	// cout << "Using inverse rotation: ";
	// TrackDir_global_test.Print();
	
	TVector3 TrackPos_global = GEMorigin + TrackPos_local.X() * GEMxaxis + TrackPos_local.Y() * GEMyaxis + TrackPos_local.Z() * GEMzaxis; 

	// cout << "Testing two different calculations of track position in global coordinates: " << endl;
	// cout << "Local Track position: ";
	// TrackPos_local.Print();
	// cout << "Standard calculation: ";
	// TrackPos_global.Print();
	// cout << "Using Rtot: ";
	// TVector3 TrackPos_global_rtot = GEMorigin + Rtot * TrackPos_local;
	// TrackPos_global_rtot.Print();
	// cout << "Using Rinv: ";
	// TVector3 TrackPos_global_rinv = GEMorigin + Rinv * TrackPos_local;
	// TrackPos_global_rinv.Print();
	
	//TVector3 TrackPos_global = GEMorigin + Rtot * TrackPos_local;
	
	//Now compute intersection of track ray in global coordinates with sieve slit:
	// (trackpos + s * trackdir - sieveorigin) dot globalzaxis = 0
	// --> s * trackdir dot globalzaxis = (sieveorigin - trackpos) dot globalzaxis
	double sintersect = (SieveOrigin - TrackPos_global).Dot( Global_zaxis ) /
	  ( TrackDir_global.Dot( Global_zaxis ) );
	TVector3 TrackSievePos = TrackPos_global + sintersect * TrackDir_global;
	
	hxysieve->Fill( TrackSievePos.Y(), TrackSievePos.X() );
	//cout<<"ysieve: "<<TrackSievePos.Y()<<" xsieve: "<<TrackSievePos.X()<<endl;
	double sintersect_target = -TrackPos_global.Dot( Global_zaxis ) / (TrackDir_global.Dot( Global_zaxis ) );
	
	TVector3 TrackTargPos = TrackPos_global + sintersect_target * TrackDir_global;
	
	hytar_old->Fill( TrackTargPos.Y() );
	hxtar_old->Fill( TrackTargPos.X() );
	
      }
    }
  }//end while event

  //Set the sieve hole selection
  gROOT->Reset();
  TCanvas *histView_Cut; 
  histView_Cut= new TCanvas("histView_Cut","cut",1400,1000);
  histView_Cut->Divide(1,1);
  histView_Cut->cd(1);
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetLogz(); 
  
  TCutG*t;
  histView_Cut->Clear();
  hxysieve->Draw("colz");
  hxysieve->SetMinimum(1.);	

  histView_Cut->Update();
  gSystem->ProcessEvents();
  histView_Cut->Update();
  //hxysieve->GetYaxis()->SetRangeUser(-1,1);
  //hxysieve->GetXaxis()->SetRangeUser(-1,1);
  //draw the ideal positions
  TLine* ys_line[nysieve];
  TText* ys_text[nysieve];
  TLine* xs_line[nxsieve];
  TText* xs_text[nxsieve];
  
  for (Int_t nys=0;nys<nysieve;nys++) {
    Double_t pos=ys_cent[nys];//for old nysieve=7	
    ys_line[nys]= new TLine(pos,-0.4,pos,0.4);
    ys_text[nys]= new TText(pos,-0.4,Form("%d",nys));
    ys_text[nys]->SetTextColor(2);
    ys_line[nys]->SetLineColor(2);
    ys_line[nys]->SetLineWidth(1);
    ys_line[nys]->Draw("same");
    ys_text[nys]->Draw("same");
  }
  for (Int_t nxs=0;nxs<nxsieve;nxs++) {
    Double_t pos=xs_cent[nxs];//for old nysieve=7	
    xs_line[nxs]= new TLine(-0.2,pos,0.2,pos);
    xs_text[nxs]= new TText(-0.2,pos,Form("%d",nxs));
    xs_text[nxs]->SetTextColor(2);
    xs_line[nxs]->SetLineColor(2);
    xs_line[nxs]->SetLineWidth(1);
    xs_line[nxs]->Draw("same");
    xs_text[nxs]->Draw("same");
  }
  
  histView_Cut->Update();
  gPad->Modified();
  gSystem->ProcessEvents();
    
  vector<vector<bool> > goodfit_hole(nxsieve);
  vector<vector<double> > xmean_hole(nxsieve);
  vector<vector<double> > ymean_hole(nxsieve);
  vector<vector<double> > xsigma_hole(nxsieve);
  vector<vector<double> > ysigma_hole(nxsieve);

  double yspace = 0.038;
  double xspace = 0.049; 

  TCanvas *cfit = new TCanvas("cfit","cfit",1600,700);

  cfit->Divide(3,1,.001,.001);
  

  for( int ix=0; ix<nxsieve; ix++ ){
    goodfit_hole[ix].resize( nysieve );
    xmean_hole[ix].resize( nysieve );
    ymean_hole[ix].resize( nysieve );
    xsigma_hole[ix].resize( nysieve );
    ysigma_hole[ix].resize( nysieve );
    for( int iy=0; iy<nysieve; iy++ ){
      int binglobal, binx,biny,binz;

      //define bin range as xcent +/ 0.04, 
      // ycent +/- 0.03

      double ylo = ys_cent[iy] - 0.5*yspace;
      double yhi = ys_cent[iy] + 0.5*yspace;
      double xlo = xs_cent[ix] - 0.5*xspace;
      double xhi = xs_cent[ix] + 0.5*xspace;

      TString histname;

      int binyhi,binylo,binxhi,binxlo;
      hxysieve->GetBinXYZ( hxysieve->FindBin( ylo, xlo ), binylo, binxlo, binz );
      hxysieve->GetBinXYZ( hxysieve->FindBin( yhi, xhi ), binyhi, binxhi, binz );

      TH1D *hxtemp = hxysieve->ProjectionY( histname.Format("hxsieve_x%d_y%d", ix, iy ), binylo, binyhi );
      TH1D *hytemp = hxysieve->ProjectionX( histname.Format("hysieve_x%d_y%d", ix, iy ), binxlo, binxhi );

      bool skiphole = false;
      bool goodfit = false;
      
      double xmin_fit = xs_cent[ix]-0.5*xspace;
      double xmax_fit = xs_cent[ix]+0.5*xspace;
      double ymin_fit = ys_cent[iy]-0.5*yspace; 
      double ymax_fit = ys_cent[iy]+0.5*yspace; 

      goodfit_hole[ix][iy] = false;

      while( !goodfit ){
	
	TLine L;
	L.SetLineColor(2);
	
	cfit->cd(1)->SetGrid();
	hxtemp->Draw();
	//hxtemp->Fit("gaus","","",xlo,xhi);
	hxtemp->GetXaxis()->SetRangeUser(xs_cent[ix]-2.0*xspace,xs_cent[ix]+2.0*xspace);
	 
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
	hxysieve->Draw("colz");
	  
	L.DrawLine( ys_cent[iy],-0.4,ys_cent[iy], 0.4);
	L.DrawLine( -0.2, xs_cent[ix], 0.2, xs_cent[ix] );
	  
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
	  
	  
	  xmean_hole[ix][iy] = xfit;
	  ymean_hole[ix][iy] = yfit;
	  xsigma_hole[ix][iy] = xsigma;
	  ysigma_hole[ix][iy] = ysigma;
 
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
	    
	    //hxtemp->Fit( "gaus","","",xmin_fit, xmax_fit );
	    //hytemp->Fit( "gaus","","",ymin_fit, ymax_fit );
	    
	    //cfit->Update();
	    //gPad->Modified();
	    //gSystem->ProcessEvents();
	    
	    //	  reply.ReadLine(cin,kFALSE);
	    
	  } else if( reply.BeginsWith("s") ){
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
      }

      //fout->cd();
      //hxtemp->Write();
      //hytemp->Write();
      
      hxtemp->Delete();
      hytemp->Delete();

      goodfit_hole[ix][iy] = !skiphole;
      //xmean_hole[

    }
  }

   
  //load up the sieve hole cuts
  nevent = 0;
  //  vector<vector<TCutG*>> sieve_cut;
  //vector<vector<bool> > cutexists;
 

  while( C->GetEntry( nevent++ ) ){
    //In this second loop, make explicit the association between sieve holes and tracks:

    treenum = C->GetTreeNumber();
    if( treenum != currenttreenum || nevent <= 1 ){
      GlobalCut->UpdateFormulaLeaves();
      currenttreenum = treenum;
    }

    bool passedcut = GlobalCut->EvalInstance(0) != 0;
    
    int itr = int(besttrack);
    if( passedcut && besttrack >= 0 && ntracks <= MAXNTRACKS ){
      
      TVector3 TrackPos_local( trackX[itr], trackY[itr], 0.0 );
      TVector3 TrackDir_local( trackXp[itr], trackYp[itr], 1.0 );
      TrackDir_local = TrackDir_local.Unit();
      
      TVector3 TrackDir_global = TrackDir_local.X() * GEMxaxis +
      	TrackDir_local.Y() * GEMyaxis +
      	TrackDir_local.Z() * GEMzaxis;
      //TVector3 TrackDir_global = Rinv * TrackDir_local;
      
      TVector3 TrackPos_global = GEMorigin + TrackPos_local.X() * GEMxaxis + TrackPos_local.Y() * GEMyaxis + TrackPos_local.Z() * GEMzaxis; 
      //TVector3 TrackPos_global = GEMorigin + Rtot * TrackPos_local;
      
      //Now compute intersection of track ray in global coordinates with sieve slit:
      // (trackpos + s * trackdir - sieveorigin) dot globalzaxis = 0
      // --> s * trackdir dot globalzaxis = (sieveorigin - trackpos) dot globalzaxis
      double sintersect = (SieveOrigin - TrackPos_global).Dot( Global_zaxis ) /
	( TrackDir_global.Dot( Global_zaxis ) );
      TVector3 TrackSievePos = TrackPos_global + sintersect * TrackDir_global;

      int iy_found=-1;
      int ix_found=-1;
      
      for (Int_t iy=0; iy<nysieve; iy++){
	for (Int_t ix=0;ix<nxsieve;ix++){ 

	  // if( cutexists[iy][ix] ){
	  //   if (sieve_cut[iy][ix]->IsInside(TrackSievePos.Y(),TrackSievePos.X())){

	  if( goodfit_hole[ix][iy] && pow( (xmean_hole[ix][iy] - TrackSievePos.X())/xsigma_hole[ix][iy], 2 ) + pow( (ymean_hole[ix][iy] - TrackSievePos.Y())/ysigma_hole[ix][iy], 2 ) <= pow(1.5,2) ){ 
	    cout << "track passed cut, event = " << nevent << endl;
	    
	    iy_found = iy; ix_found=ix;
	    hxysieve_sel->Fill( TrackSievePos.Y(), TrackSievePos.X() );
	    
	  }
	}
      }
      //we have an event going through a hole
      if (iy_found != -1 && ix_found != -1){
	cout << "found a track going through a hole, (iy, ix)=(" << iy_found << ", " << ix_found
	     << ")" << endl;
	
	hxyfp_sel->Fill( trackY[itr], trackX[itr] );
	hYpFpYFp_sel->Fill(trackYp[itr],trackY[itr]);
	hXpFpXFp_sel->Fill(trackXp[itr],trackX[itr]);
	XTRACK.push_back(trackX[itr]);
	YTRACK.push_back(trackY[itr]);
	XPTRACK.push_back(trackXp[itr]);
	YPTRACK.push_back(trackYp[itr]);
	XSIEVE.push_back(xs_cent[ix_found]);
	YSIEVE.push_back(ys_cent[iy_found]);
	NTRACKS++;
      }
    }
  }


  //do the thing
  TMinuit *FitZeroField = new TMinuit( 7 );
  
  FitZeroField->SetFCN( CHI2_FCN );
  
  int ierflg = 0;
  
  FitZeroField->mnparm( 0, "GEMX0", GEMX0, 0.01,0,0,ierflg ); //guesstimate 1 cm as initial position accuracy
  FitZeroField->mnparm( 1, "GEMY0", GEMY0, 0.03,0,0,ierflg ); //start with 3-cm uncertainty for y position
  FitZeroField->mnparm( 2, "GEMZ0", GEMZ0, 0.01,0,0,ierflg );
  FitZeroField->mnparm( 3, "ZSIEVE", ZSIEVE, 0.01,0,0,ierflg );
  FitZeroField->mnparm( 4, "GEMax", GEMax, 0.3*PI/180.0, 0, 0, ierflg ); //guesstimate 0.3 degrees as initial angular accuracy
  FitZeroField->mnparm( 5, "GEMay", GEMay, 0.3*PI/180.0, 0, 0, ierflg );
  FitZeroField->mnparm( 6, "GEMaz", GEMaz, 0.3*PI/180.0, 0, 0, ierflg );

  if( fixzsieve != 0 ) FitZeroField->FixParameter(3);
  
  double arglist[10];
  arglist[0]=1;
  FitZeroField->mnexcm("SET ERR",arglist,1,ierflg);
  
  arglist[0] = 5000;
  arglist[1] = 1.;
  
  //Uncomment this line when we are actually set up to do a fit:   
  FitZeroField->mnexcm("MIGRAD",arglist,2,ierflg);
  
  //TODO: grab parameters, write them out to file. Profit.
  double fitpar[7];
  double fitparerr[7];

  ofstream outfile("ZeroFieldAlign_results_new.txt");

  TString outline;
  
  for (int ii=0;ii<7;ii++){
  //fitpar[ii]=FitZeroField->GetParameter(ii);fitparerr[ii]=FitZeroField->GetParameter(ii);?????
    FitZeroField->GetParameter(ii,fitpar[ii],fitparerr[ii]);
  }

  GEMX0 = fitpar[0];
  GEMY0 = fitpar[1];
  GEMZ0 = fitpar[2];
  GEMax = fitpar[4];
  GEMay = fitpar[5];
  GEMaz = fitpar[6];

  TRotation Rnew;
  Rnew.RotateY(GEMay);
  Rnew.RotateZ(GEMaz);
  Rnew.RotateX(GEMax);

  GEMxaxis.SetXYZ( Rnew.XX(), Rnew.YX(), Rnew.ZX() );
  GEMyaxis.SetXYZ( Rnew.XY(), Rnew.YY(), Rnew.ZY() );
  GEMzaxis.SetXYZ( Rnew.XZ(), Rnew.YZ(), Rnew.ZZ() );

  GEMorigin.SetXYZ( GEMX0, GEMY0, GEMZ0 );

  SieveOrigin.SetXYZ( 0, 0, fitpar[3] );
  
  cout << endl << "GEM z axis in global coordinates:" << endl;
  GEMzaxis.Print();

  cout << endl << "GEM x axis in global coordinates:" << endl;
  GEMxaxis.Print();

  cout << endl << "GEM y axis in global coordinates:" << endl;
  GEMyaxis.Print();

  cout << endl << "GEM origin in global coordinates:" << endl;
  GEMorigin.Print();

  cout << endl << "Sieve slit origin in global coordinates: " << endl;
  SieveOrigin.Print();
  
  outline.Form("GEMX0 = %18.9g +/- %18.9g",fitpar[0], fitparerr[0]);
  outfile << outline << endl;
  cout << outline << endl;

  outline.Form("GEMY0 = %18.9g +/- %18.9g",fitpar[1], fitparerr[1]);
  outfile << outline << endl;
  cout << outline << endl;

  outline.Form("GEMZ0 = %18.9g +/- %18.9g",fitpar[2], fitparerr[2]);
  outfile << outline << endl;
  cout << outline << endl;

  outline.Form("ZSIEVE = %18.9g +/- %18.9g",fitpar[3], fitparerr[3]);
  outfile << outline << endl;
  cout << outline << endl;

  outline.Form("GEMax = %18.9g +/- %18.9g",fitpar[4]*TMath::RadToDeg(), fitparerr[4]*TMath::RadToDeg());
  outfile << outline << endl;
  cout << outline << endl;

  outline.Form("GEMay = %18.9g +/- %18.9g",fitpar[5]*TMath::RadToDeg(), fitparerr[5]*TMath::RadToDeg());
  outfile << outline << endl;
  cout << outline << endl;

  outline.Form("GEMaz = %18.9g +/- %18.9g",fitpar[6]*TMath::RadToDeg(), fitparerr[6]*TMath::RadToDeg());
  outfile << outline << endl;
  cout << outline << endl;
  
  outline.Form("Implied magnet distance = %18.9g +/- %18.9g",fitpar[3]+0.3882-0.75*0.0254, fitparerr[3]);
  outfile << outline << endl;
  cout << outline << endl;

  TString dbfilename = configfilename;
  dbfilename.ReplaceAll(".txt",".dat");
  dbfilename.Prepend("db_");

  ofstream dbfile(dbfilename.Data());

  dbfile << Form( "bb.gemorigin_xyz = %14.9g %14.9g %14.9g", fitpar[0], fitpar[1], fitpar[2] ) << endl;
  dbfile << Form( "bb.gemangles_xyz = %14.9g %14.9g %14.9g",
		  fitpar[4]*TMath::RadToDeg(),
		  fitpar[5]*TMath::RadToDeg(),
		  fitpar[6]*TMath::RadToDeg() ) << endl;

  
  
  fout->Write();
 
}//end program
