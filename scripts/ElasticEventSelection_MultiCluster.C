//#include "GEM_cosmic_tracks.C"
#include "TChain.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TDecompSVD.h"
#include "TVector3.h"
#include "TRotation.h"
#include "TEventList.h"
#include "TCut.h"
#include <iostream>
#include <fstream>
#include "TMinuit.h"
#include "TMath.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TString.h"
#include "TEventList.h"
#include "TLorentzVector.h"
#include "TProfile.h"
#include "TStyle.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TEllipse.h"
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include "TTreeFormula.h"

double PI = TMath::Pi();

double Mp = 0.938272;
double Mn = 0.939565;

void ElasticEventSelection_MultiCluster( const char *configfilename, const char *outputfilename="ElasticTemp.root" ){

  gStyle->SetOptFit();
  
  ifstream configfile(configfilename);

  //so as usual the main things to define are:
  // 1. List of files
  // 2. Global cuts
  // 3. Nominal beam energy (perhaps corrected for average energy loss along half target thickness
  // 4. File name for old momentum coefficients (optional?)
  // 5. BigBite central angle
  // 6. SBS central angle
  // 7. HCAL distance

  TChain *C = new TChain("T");
  
  TString currentline;

  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endlist") ){
    if( !currentline.BeginsWith("#") ){
      C->Add(currentline);
    }
  }

  TCut globalcut="";
  
  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endcut") ){
    if( !currentline.BeginsWith("#") ){
      globalcut += currentline;
    }
  }

  TTreeFormula *GlobalCut = new TTreeFormula("GlobalCut",globalcut,C);
  
  //int fitorder = 2;
  
  double ebeam=1.916;
  double bbtheta = 51.0*TMath::DegToRad();
  double sbstheta = 34.5*TMath::DegToRad();
  double hcaldist = 13.5; //meters
  double hcalvoff = 0.35; //meters
  double Ltgt = 15.0; //cm
  double rho_tgt = 0.0723; //g/cc
  double rho_Al = 2.7; //g/cc

  double sbsdist = 2.25;
  double sbsfield = 1.0; //fraction of max field:
  //double sbsmaxfield = 0.53/0.3; //About 1.77 Tesla.
  double sbsmaxfield = 1.26; //Tesla
  double Dgap = 48.0*2.54/100.0; //about 1.22 m
  
  double celldiameter = 1.6*2.54; //cm, right now this is a guess

  //Eventually we will grab HALLA:p from the EPICs tree for the beam energy:

  
  sbsmaxfield = 3.1 * atan( 0.85/(11.0 - 2.25 - Dgap/2.0 ))/0.3/Dgap/0.7;
  
  // 0.85 m deflection / 3.1 nucleon momentum @70% of max field
  // p * thetabend = 0.3 * BdL
  // deflection = tan(thetabend) * (11 - (2.25 + 0.6) )
    //BdL = p*thetabend/0.3 --> Bmax = p*thetabend/0.3/dL/0.7

    
  double Ztgt = 1.0;
  double Atgt = 1.0;
  double Mmol_tgt = 1.008; //g/mol
  
  //For energy-loss correction to beam energy:
  
  double dEdx_tgt=0.00574; //According to NIST ESTAR, the collisional stopping power of hydrogen is about 5.74 MeV*cm2/g at 2 GeV energy:
  double dEdx_Al = 0.0021; //According to NIST ESTAR, the collisional stopping power of Aluminum is about 2.1 MeV*cm2/g between 1-4 GeV:

  double uwallthick_LH2 = 0.0145; //cm
  double dwallthick_LH2 = 0.015; //cm
  double cellthick_LH2 = 0.02; //cm, this is a guess;

  int useAlshield = 0; //Use 1/8" aluminum shield on scattering chamber exit?

  double Alshieldthick = 2.54/8.0; //= 1/8 inch * 2.54 cm/inch
  
  
  //Mean energy loss of the beam prior to the scattering:
  double MeanEloss = Ltgt/2.0 * rho_tgt * dEdx_tgt + uwallthick_LH2 * rho_Al * dEdx_Al; //approximately 3 MeV:

  double MeanEloss_outgoing = celldiameter/2.0/sin(bbtheta) * rho_tgt * dEdx_tgt; //Approximately 1 MeV
  
  int usehcalcut = 0; //default to false:

  double dx0=0.0, dy0=0.0; //zero offsets for deltax and deltay cuts:
  double dt0=0.0, dtcut = 100.0;
  double Emin_HCAL = 0.065*0.25*3.0/(2.0*Mp); //default to HCAL energy threshold for 3 GeV^2, approximately 26 MeV
  
  double dxsigma = 0.06, dysigma = 0.1; //sigmas for deltax and deltay cuts:

  double GEMpitch = 10.0*TMath::DegToRad();

  double dpelmin_fit = -0.03;
  double dpelmax_fit = 0.03;
  double Wmin_fit = 0.86;
  double Wmax_fit = 1.02; 

  //To calculate a proper dx, dy for HCAL, we need
  double hcalheight = 0.365; //m (we are guessing that this is the height of the center of HCAL above beam height:

  //The following are the positions of the "first" row and column from HCAL database (top right block as viewed from upstream)
  double xoff_hcal = 0.92835;
  double yoff_hcal = 0.47305;
  
  double blockspace_hcal = 0.15254; //don't need to make this configurable

  int nrows_hcal=24;
  int ncols_hcal=12;

  //By default we fix the zero-order coefficient for pth and the first-order pth coefficient for xfp:
  
  int fix_pth0_flag = 1;
  int fix_pthx_flag = 1;

  double pth0 = 0.275;
  double pthx = 0.102;
  
  int order = 2; 
  //int order_ptheta = 1; //default to first-order expansion for momentum, and 2nd-order for vertices, angles. 
  
  double A_pth0 = 0.275;
  double B_pth0 = 0.61;
  double C_pth0 = -0.074;

  double BBdist = 1.85;
  
  TString fname_oldcoeffs = "oldcoeffs.dat"; //mainly for merging angle/vertex reconstruction coefficients with momentum coefficients:

  double thtgtmin_fit = -0.15;
  double thtgtmax_fit = 0.15;

  //double Wmin_treefill = 0;
  //double Wmax_treefill = 

  int hcal_coordflag = 0; //0 = "new" HCAL coordinate system that matches transport.
                          //1 = "old" HCAL coordinate system that doesn't match transport

  int hcal_selectionflag = 0; //0 = choose highest-energy passing ADC coincidence time cut
                              //1 = choose smallest thetapq (proton or neutron)
                              //2 = choose highest-energy regardless of ADC time.

  int HCALatimeflag = 0; //default = use sbs.hcal.clus.atimeblk (current). 1 = OLD = use sbs.hcal.clus.atime
  
  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endconfig") ){
    if( !currentline.BeginsWith("#") ){
      TObjArray *tokens = currentline.Tokenize(" ");

      int ntokens = tokens->GetEntries();

      if( ntokens >= 2 ){
	TString skey = ( (TObjString*) (*tokens)[0] )->GetString();

	// if( skey == "oldcoeffs" ){ //this should be the name of a text file
	//   fname_oldcoeffs = ( (TObjString*) (*tokens)[1] )->GetString();
	// }
	  
	// if ( skey == "order" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   order = stemp.Atoi();
	// }

	// if( skey == "order_pth" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   order_ptheta = stemp.Atoi();
	// }

	if( skey == "HCALatimeflag" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  HCALatimeflag = stemp.Atoi();
	}
	
	if( skey == "dEdx" ){ //assumed to be given in GeV/(g/cm^2)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  dEdx_tgt = stemp.Atof();
	}

	if( skey == "dEdx_Al" ){ //assumed to be given in GeV/(g/cm^2)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  dEdx_Al = stemp.Atof();
	}

	if( skey == "useAlShield" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  useAlshield = stemp.Atoi();
	}
	
	if( skey == "ebeam" ){ //primary beam energy (GeV):
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  ebeam = stemp.Atof();
	}

	if( skey == "bbtheta" ){ //BigBite central angle (deg) (assumed to be on beam left)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  bbtheta = stemp.Atof() * TMath::DegToRad();
	}

	if( skey == "bbdist" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  BBdist = stemp.Atof();
	}

	// if( skey == "A_pth0" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   A_pth0 = stemp.Atof();
	// }

	// if( skey == "B_pth0" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   B_pth0 = stemp.Atof();
	// }

	// if( skey == "C_pth0" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   C_pth0 = stemp.Atof();
	// }
	
	if( skey == "sbstheta" ){ //SBS/HCAL central angle (deg) (assumed to be on beam right)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  sbstheta = stemp.Atof() * TMath::DegToRad();
	}

	if( skey == "hcaldist" ){ //HCAL distance from target (m)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  hcaldist = stemp.Atof();
	}

	if( skey == "Ltgt" ){ //target length (cm):
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  Ltgt = stemp.Atof();
	}

	if( skey == "rho_tgt" ){ //target density (g/cm^3)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  rho_tgt = stemp.Atof();
	}

	if( skey == "celldiameter" ){ //cell diameter (cm)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  celldiameter = stemp.Atof();
	}
	
	
	if( skey == "usehcalcut" ){ //calculate dxHCAL, dyHCAL and cut on them (2.5 sigma)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  usehcalcut = stemp.Atoi();
	}

	if( skey == "dx0" ){ //calculate dxHCAL, dyHCAL and cut on them (2.5 sigma)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  dx0 = stemp.Atof();
	}

	if( skey == "dy0" ){ //calculate dxHCAL, dyHCAL and cut on them (2.5 sigma)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  dy0 = stemp.Atof();
	}

	if( skey == "dxsigma" ){ //calculate dxHCAL, dyHCAL and cut on them (2.5 sigma)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  dxsigma = stemp.Atof();
	}

	if( skey == "dysigma" ){ //calculate dxHCAL, dyHCAL and cut on them (2.5 sigma)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  dysigma = stemp.Atof();
	}

	if( skey == "GEMpitch" ){ //calculate dxHCAL, dyHCAL and cut on them (2.5 sigma)
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  GEMpitch = stemp.Atof()*TMath::DegToRad();
	}

	// if( skey == "dpel_min" ){ //p/pel - 1 minimum to include in fit
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   dpelmin_fit = stemp.Atof();
	// }

	// if( skey == "dpel_max" ){ //p/pel - 1 maximum to include in fit
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   dpelmax_fit = stemp.Atof();
	// }

	// if( skey == "Wmin" ){ //Wmin to include in fit
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   Wmin_fit = stemp.Atof();
	// }

	// if( skey == "Wmax" ){ //Wmax to include in fit
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   Wmax_fit = stemp.Atof();
	// }

	// if( skey == "fix_pth0" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   fix_pth0_flag = stemp.Atoi();
	// }

	// if( skey == "fix_pthx" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   fix_pthx_flag = stemp.Atoi();
	// }

	// if( skey == "pth0" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   pth0 = stemp.Atof();
	// }

	// if( skey == "pthx" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   pthx = stemp.Atof();
	// }

	// if( skey == "hcalvoff" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   hcalheight = stemp.Atof();
	//   hcalvoff = stemp.Atof();
	// }

	// if( skey == "hcalxoff" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   xoff_hcal = stemp.Atof();
	// }

	// if( skey == "hcalyoff" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   yoff_hcal = stemp.Atof();
	// }

	// if( skey == "hcalcoordsys" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   hcal_coordflag = stemp.Atoi();
	// }
	
	// if( skey == "fit_thtgt_min" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   thtgtmin_fit = stemp.Atof();
	// }

	// if( skey == "fit_thtgt_max" ){
	//   TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	//   thtgtmax_fit = stemp.Atof();
	// }

	if( skey == "sbsdist" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  sbsdist = stemp.Atof();
	}

	if( skey == "sbsfield" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  sbsfield = stemp.Atof();
	}

	if( skey == "sbsmaxfield" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  sbsmaxfield = stemp.Atof();
	}

	if( skey == "dt0" ){ 
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  dt0 = stemp.Atof();
	}

	if( skey == "dtcut" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  dtcut = stemp.Atof();
	}

	if( skey == "Emin_HCAL" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  Emin_HCAL = stemp.Atof();
	}

	if( skey == "HCALselectionflag" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  hcal_selectionflag = stemp.Atoi();
	}
	  
      }
      
      tokens->Delete();
    }
  }
  
  hcal_coordflag = 0;
  xoff_hcal = 0.0;
  yoff_hcal = 0.0;
  hcalheight = 0.0;
  hcalvoff = 0.0;
  
  //Note that both of these calculations neglect the Aluminum end windows and cell walls:
  
  MeanEloss = Ltgt/2.0 * rho_tgt * dEdx_tgt + uwallthick_LH2 * rho_Al * dEdx_Al; //hopefully the user has provided these quantities with correct units
  
  MeanEloss_outgoing = celldiameter/2.0/sin(bbtheta) * rho_tgt * dEdx_tgt +
    cellthick_LH2/sin(bbtheta) * rho_Al * dEdx_Al;
  if( useAlshield != 0 ) MeanEloss_outgoing += Alshieldthick * rho_Al * dEdx_Al;

  cout << "mean eloss in aluminum shield = " << Alshieldthick * rho_Al * dEdx_Al << endl;
  
  cout << "use Aluminum shield = " << useAlshield << endl;
						     
						     
  
  cout << "Mean E loss (beam electron) = " << MeanEloss << endl;
  cout << "BigBite theta = " << bbtheta * TMath::RadToDeg() << endl;
  cout << "Mean E loss (outgoing electron) = " << MeanEloss_outgoing << endl;
  cout << "Ebeam corrected (GeV) = " << ebeam - MeanEloss << endl;
 
  
					   
  
  // In order to get 

  //TEventList *elist = new TEventList("elist","Event list for BigBite momentum calibration");

  //C->Draw(">>elist",globalcut);

  int MAXNTRACKS=1000;

  int MAXHCALCLUSTERS=100;
  //Declare variables to hold branch addresses:
  int MAXNBLKBBCAL = 50;
  
  double ntrack;
  double px[MAXNTRACKS], py[MAXNTRACKS], pz[MAXNTRACKS], p[MAXNTRACKS];
  double vx[MAXNTRACKS], vy[MAXNTRACKS], vz[MAXNTRACKS];

  double pathL[MAXNTRACKS];
  
  //Use "rotated" versions of the focal plane variables:
  double xfp[MAXNTRACKS], yfp[MAXNTRACKS], thfp[MAXNTRACKS], phfp[MAXNTRACKS];
  double xfp0[MAXNTRACKS], yfp0[MAXNTRACKS], thfp0[MAXNTRACKS], phfp0[MAXNTRACKS];
  //Also need target variables:
  double xtgt[MAXNTRACKS], ytgt[MAXNTRACKS], thtgt[MAXNTRACKS], phtgt[MAXNTRACKS];

  double bbtrchi2[MAXNTRACKS], bbtrchi2hits[MAXNTRACKS], bbtrnhits[MAXNTRACKS], 
    bbtrngoodhits[MAXNTRACKS], bbtrt0[MAXNTRACKS];

  int MAXNCP = 2;
  double xfcp[MAXNCP],yfcp[MAXNCP],zfcp[MAXNCP];
  double xbcp[MAXNCP],ybcp[MAXNCP],zbcp[MAXNCP];

  int nclustHCAL;
  double xHCAL[MAXHCALCLUSTERS], yHCAL[MAXHCALCLUSTERS], EHCAL[MAXHCALCLUSTERS];
  double ADCTIMEHCAL[MAXHCALCLUSTERS], TDCTIMEHCAL[MAXHCALCLUSTERS], EMAXHCAL[MAXHCALCLUSTERS], NBLKHCAL[MAXHCALCLUSTERS];
  double EPS, ESH, xSH, ySH, xPS, TPS, TSH;

  int maxhodoclusters=100;
  
  double hodotmean[maxhodoclusters];
  double hodotdiff[maxhodoclusters];
  double hodotfinal[maxhodoclusters];

  int nhodoclust; //number of TRACK-MATCHED hodo clusters:

  int MAXGRINCHCLUSTERS=100;
  
  double nclustGRINCH;
  double GRINCH_trackindex, GRINCH_clustersize, GRINCH_tmean, GRINCH_xmean, GRINCH_ymean, GRINCH_adc, GRINCH_totmean;

  //Ignore hodo variables for meow:
  // int maxHODOclusters=100;

  // double nHODOclusters;
  
  // double xHODO[maxHODOclusters],yHODO[maxHODOclusters];
  // double tmeanHODO[maxHODOclusters], tdiffHODO[maxHODOclusters];
  
  C->SetBranchStatus("*",0);

  //Hope this works: in pass 2 we will replace with g.runnum
  //C->SetBranchStatus("fEvtHdr.fRun",1);
  //UInt_t runnumber;
  //C->SetBranchAddress("fEvtHdr.fRun",&runnumber);
  
  C->SetBranchStatus("g.runnum",1);
  double runnumber;
  C->SetBranchAddress("g.runnum", &runnumber);

  C->SetBranchStatus("MC.mc_nucl",1);
  C->SetBranchStatus("MC.mc_fnucl",1);
  
  C->SetBranchStatus("bb.grinch_tdc.nclus",1);
  C->SetBranchStatus("bb.grinch_tdc.clus.*",1);
  
  C->SetBranchAddress("bb.grinch_tdc.nclus",&nclustGRINCH);
  C->SetBranchAddress("bb.grinch_tdc.clus.size", &GRINCH_clustersize);
  C->SetBranchAddress("bb.grinch_tdc.clus.t_mean", &GRINCH_tmean);
  C->SetBranchAddress("bb.grinch_tdc.clus.trackindex", &GRINCH_trackindex);
  C->SetBranchAddress("bb.grinch_tdc.clus.x_mean", &GRINCH_xmean);
  C->SetBranchAddress("bb.grinch_tdc.clus.y_mean", &GRINCH_ymean);
  C->SetBranchAddress("bb.grinch_tdc.clus.adc", &GRINCH_adc);
  C->SetBranchAddress("bb.grinch_tdc.clus.tot_mean", &GRINCH_totmean);

  //Minimal set of HCAL variables:
  C->SetBranchStatus("sbs.hcal.x",1);
  C->SetBranchStatus("sbs.hcal.y",1);
  C->SetBranchStatus("sbs.hcal.e",1);
  C->SetBranchStatus("sbs.hcal.atimeblk",1);
  C->SetBranchStatus("sbs.hcal.tdctimeblk",1);
  C->SetBranchStatus("sbs.hcal.index",1);

  // block information for best cluster:
  C->SetBranchStatus("sbs.hcal.nblk",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.again",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.atime",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.e",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.id",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.row",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.col",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.x",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.y",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.col",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.tdctime",1);

  double indexHCAL;
  double nblkHCAL;
  double againHCAL[MAXHCALCLUSTERS];
  double atimeHCAL[MAXHCALCLUSTERS];
  double eblkHCAL[MAXHCALCLUSTERS];
  double idblkHCAL[MAXHCALCLUSTERS];
  double rowblkHCAL[MAXHCALCLUSTERS];
  double colblkHCAL[MAXHCALCLUSTERS];
  double xblkHCAL[MAXHCALCLUSTERS];
  double yblkHCAL[MAXHCALCLUSTERS];
  double tdctimeblkHCAL[MAXHCALCLUSTERS];

  C->SetBranchAddress("sbs.hcal.index",&indexHCAL);
  C->SetBranchAddress("sbs.hcal.nblk",&nblkHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.again",againHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.atime",atimeHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.e",eblkHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.id",idblkHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.row",rowblkHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.col",colblkHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.x",xblkHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.y",yblkHCAL);
  C->SetBranchAddress("sbs.hcal.clus_blk.tdctime",tdctimeblkHCAL);

  //Block information for BBCAL:

  C->SetBranchStatus("bb.ps.index",1);
  C->SetBranchStatus("bb.sh.index",1);
  C->SetBranchStatus("bb.ps.nblk",1);
  C->SetBranchStatus("bb.sh.nblk",1);
  C->SetBranchStatus("bb.sh.clus_blk.*",1);
  C->SetBranchStatus("bb.ps.clus_blk.*",1);
  
  double indexBBSH;
  double nblkBBSH;
  double againBBSH[MAXNBLKBBCAL];
  double atimeBBSH[MAXNBLKBBCAL];
  double eblkBBSH[MAXNBLKBBCAL];
  double idblkBBSH[MAXNBLKBBCAL];
  double rowblkBBSH[MAXNBLKBBCAL];
  double colblkBBSH[MAXNBLKBBCAL];
  double xblkBBSH[MAXNBLKBBCAL];
  double yblkBBSH[MAXNBLKBBCAL];
  //double tdctimeblkBBSH[MAXNBLKBBCAL];

  C->SetBranchAddress("bb.sh.index",&indexBBSH);
  C->SetBranchAddress("bb.sh.nblk",&nblkBBSH);
  C->SetBranchAddress("bb.sh.clus_blk.again",againBBSH);
  C->SetBranchAddress("bb.sh.clus_blk.atime",atimeBBSH);
  C->SetBranchAddress("bb.sh.clus_blk.e",eblkBBSH);
  C->SetBranchAddress("bb.sh.clus_blk.id",idblkBBSH);
  C->SetBranchAddress("bb.sh.clus_blk.row",rowblkBBSH);
  C->SetBranchAddress("bb.sh.clus_blk.col",colblkBBSH);
  C->SetBranchAddress("bb.sh.clus_blk.x",xblkBBSH);
  C->SetBranchAddress("bb.sh.clus_blk.y",yblkBBSH);
  
  
  double indexBBPS;
  double nblkBBPS;
  double againBBPS[MAXNBLKBBCAL];
  double atimeBBPS[MAXNBLKBBCAL];
  double eblkBBPS[MAXNBLKBBCAL];
  double idblkBBPS[MAXNBLKBBCAL];
  double rowblkBBPS[MAXNBLKBBCAL];
  double colblkBBPS[MAXNBLKBBCAL];
  double xblkBBPS[MAXNBLKBBCAL];
  double yblkBBPS[MAXNBLKBBCAL];
  //  double tdctimeblkBBPS[MAXNBLKBBCAL];

  C->SetBranchAddress("bb.ps.index",&indexBBPS);
  C->SetBranchAddress("bb.ps.nblk",&nblkBBPS);
  C->SetBranchAddress("bb.ps.clus_blk.again",againBBPS);
  C->SetBranchAddress("bb.ps.clus_blk.atime",atimeBBPS);
  C->SetBranchAddress("bb.ps.clus_blk.e",eblkBBPS);
  C->SetBranchAddress("bb.ps.clus_blk.id",idblkBBPS);
  C->SetBranchAddress("bb.ps.clus_blk.row",rowblkBBPS);
  C->SetBranchAddress("bb.ps.clus_blk.col",colblkBBPS);
  C->SetBranchAddress("bb.ps.clus_blk.x",xblkBBPS);
  C->SetBranchAddress("bb.ps.clus_blk.y",yblkBBPS);
  
  //minimal set of hodoscope branches:
  C->SetBranchStatus("Ndata.bb.hodotdc.clus.tmean",1);
  C->SetBranchStatus("bb.hodotdc.clus.tmean",1);
  C->SetBranchStatus("bb.hodotdc.clus.tdiff",1);
  C->SetBranchStatus("bb.hodotdc.clus.tfinal",1);
  
  //Variables for all HCAL clusters:
  C->SetBranchStatus("Ndata.sbs.hcal.clus.e",1);
  C->SetBranchStatus("sbs.hcal.nclus",1);
  C->SetBranchStatus("sbs.hcal.clus.adctime",1);
  C->SetBranchStatus("sbs.hcal.clus.atimeblk",1);
  C->SetBranchStatus("sbs.hcal.clus.e",1);
  C->SetBranchStatus("sbs.hcal.clus.eblk",1);
  C->SetBranchStatus("sbs.hcal.clus.nblk",1);
  C->SetBranchStatus("sbs.hcal.clus.tdctime",1);
  C->SetBranchStatus("sbs.hcal.clus.x",1);
  C->SetBranchStatus("sbs.hcal.clus.y",1);
  
  C->SetBranchStatus("e.kine.W2",1);
  C->SetBranchStatus("e.kine.Q2",1);
  C->SetBranchStatus("bb.etot_over_p",1);

  //BigBite track variables:
  C->SetBranchStatus("bb.tr.*",1);
  C->SetBranchStatus("bb.tr.n",1);
  C->SetBranchStatus("bb.tr.px",1);
  C->SetBranchStatus("bb.tr.py",1);
  C->SetBranchStatus("bb.tr.pz",1);
  C->SetBranchStatus("bb.tr.p",1);
  C->SetBranchStatus("bb.tr.vx",1);
  C->SetBranchStatus("bb.tr.vy",1);
  C->SetBranchStatus("bb.tr.vz",1);
  
  C->SetBranchStatus("bb.tr.r_x",1);
  C->SetBranchStatus("bb.tr.r_y",1);
  C->SetBranchStatus("bb.tr.r_th",1);
  C->SetBranchStatus("bb.tr.r_ph",1);

  C->SetBranchStatus("bb.tr.x",1);
  C->SetBranchStatus("bb.tr.y",1);
  C->SetBranchStatus("bb.tr.th",1);
  C->SetBranchStatus("bb.tr.ph",1);
  
  C->SetBranchStatus("bb.tr.tg_x",1);
  C->SetBranchStatus("bb.tr.tg_y",1);
  C->SetBranchStatus("bb.tr.tg_th",1);
  C->SetBranchStatus("bb.tr.tg_ph",1);

  C->SetBranchStatus("bb.x_fcp",1);
  C->SetBranchStatus("bb.y_fcp",1);
  C->SetBranchStatus("bb.z_fcp",1);
  C->SetBranchStatus("bb.x_bcp",1);
  C->SetBranchStatus("bb.y_bcp",1);
  C->SetBranchStatus("bb.z_bcp",1);
  

  C->SetBranchStatus("bb.gem.track.t0",1);
  C->SetBranchStatus("bb.gem.track.nhits",1);
  C->SetBranchStatus("bb.gem.track.ngoodhits",1);
  C->SetBranchStatus("bb.gem.track.chi2ndf",1);
  C->SetBranchStatus("bb.gem.track.chi2ndf_hitquality",1);

  //We should probably add some hodoscope variables too, but not essential at this stage:
  
  //Shower and preshower variables:
  C->SetBranchStatus("bb.ps.e",1);
  C->SetBranchStatus("bb.ps.x",1);
  C->SetBranchStatus("bb.ps.y",1);
  C->SetBranchStatus("bb.sh.e",1);
  C->SetBranchStatus("bb.sh.x",1);
  C->SetBranchStatus("bb.sh.y",1);
  C->SetBranchStatus("bb.sh.atimeblk",1);
  C->SetBranchStatus("bb.ps.atimeblk",1);

  C->SetBranchAddress("bb.tr.n",&ntrack);
  C->SetBranchAddress("bb.tr.p",p);
  C->SetBranchAddress("bb.tr.px",px);
  C->SetBranchAddress("bb.tr.py",py);
  C->SetBranchAddress("bb.tr.pz",pz);
  C->SetBranchAddress("bb.tr.vx",vx);
  C->SetBranchAddress("bb.tr.vy",vy);
  C->SetBranchAddress("bb.tr.vz",vz);
  C->SetBranchAddress("bb.tr.pathl",pathL);

  //Focal-plane track variables (use "rotated" versions):
  C->SetBranchAddress("bb.tr.r_x",xfp);
  C->SetBranchAddress("bb.tr.r_y",yfp);
  C->SetBranchAddress("bb.tr.r_th",thfp);
  C->SetBranchAddress("bb.tr.r_ph",phfp);

  C->SetBranchAddress("bb.tr.x",xfp0);
  C->SetBranchAddress("bb.tr.y",yfp0);
  C->SetBranchAddress("bb.tr.th",thfp0);
  C->SetBranchAddress("bb.tr.ph",phfp0);

  //Target track variables (other than momentum):
  C->SetBranchAddress("bb.tr.tg_x",xtgt);
  C->SetBranchAddress("bb.tr.tg_y",ytgt);
  C->SetBranchAddress("bb.tr.tg_th",thtgt);
  C->SetBranchAddress("bb.tr.tg_ph",phtgt);

  C->SetBranchAddress("bb.x_fcp",xfcp);
  C->SetBranchAddress("bb.y_fcp",yfcp);
  C->SetBranchAddress("bb.z_fcp",zfcp);

  C->SetBranchAddress("bb.x_bcp",xbcp);
  C->SetBranchAddress("bb.y_bcp",ybcp);
  C->SetBranchAddress("bb.z_bcp",zbcp);

  C->SetBranchAddress("bb.gem.track.t0",bbtrt0);
  C->SetBranchAddress("bb.gem.track.nhits",bbtrnhits);
  C->SetBranchAddress("bb.gem.track.ngoodhits",bbtrngoodhits);
  C->SetBranchAddress("bb.gem.track.chi2ndf",bbtrchi2);
  C->SetBranchAddress("bb.gem.track.chi2ndf_hitquality",bbtrchi2hits);
  

  C->SetBranchAddress("Ndata.sbs.hcal.clus.e",&nclustHCAL);
  C->SetBranchAddress("sbs.hcal.clus.x",xHCAL);
  C->SetBranchAddress("sbs.hcal.clus.y",yHCAL);
  C->SetBranchAddress("sbs.hcal.clus.e",EHCAL);
  //  C->SetBranchAddress("sbs.hcal.clus.adctime",ADCTIMEHCAL);
  if( HCALatimeflag == 0 ){
    C->SetBranchAddress("sbs.hcal.clus.atimeblk",ADCTIMEHCAL);
  } else {
    C->SetBranchAddress("sbs.hcal.clus.atime",ADCTIMEHCAL);
  }
  C->SetBranchAddress("sbs.hcal.clus.tdctime",TDCTIMEHCAL);
  C->SetBranchAddress("sbs.hcal.clus.eblk",EMAXHCAL);
  C->SetBranchAddress("sbs.hcal.clus.nblk",NBLKHCAL);

  C->SetBranchAddress("bb.ps.e",&EPS);
  C->SetBranchAddress("bb.sh.e",&ESH);
  C->SetBranchAddress("bb.ps.x",&xPS);
  C->SetBranchAddress("bb.sh.x",&xSH);
  C->SetBranchAddress("bb.sh.y",&ySH);
  C->SetBranchAddress("bb.sh.atimeblk", &TSH );
  C->SetBranchAddress("bb.ps.atimeblk", &TPS );

  C->SetBranchAddress("bb.hodotdc.clus.tmean",hodotmean);
  C->SetBranchAddress("bb.hodotdc.clus.tdiff",hodotdiff);
  C->SetBranchAddress("bb.hodotdc.clus.tfinal",hodotfinal);
  C->SetBranchAddress("Ndata.bb.hodotdc.clus.tmean",&nhodoclust);
  

  double pcentral = ebeam/(1.+ebeam/Mp*(1.-cos(bbtheta)));

  TFile *fout = new TFile(outputfilename,"RECREATE");

  //After we get this working, we'll also want correlation plots of dpel and W vs. focal plane and target variables, new and old:
  TH1D *hdpel_old = new TH1D("hdpel_old","Old MEs;p/p_{elastic}(#theta)-1;",250,-0.25,0.25);
  TH1D *hW_old = new TH1D("hW_old","Old MEs;W (GeV);",250,0,2);
  TH1D *hp_old = new TH1D("hp_old","Old MEs;p (GeV);",250,0.5*pcentral,1.5*pcentral);
  TH1D *hpthetabend_old = new TH1D("hpthetabend_old","Old MEs; p#theta_{bend};",250,0.2,0.35);

  TH2D *hxpfp_vs_xfp_old = new TH2D("hxpfp_vs_xfp_old",";xfp (m); xpfp",250,-0.75,0.75,250,-0.4,0.4);
  
  TH2D *hdpel_xfp_old = new TH2D("hdpel_xfp_old", "Old MEs; xfp (m); p/p_{elastic}(#theta)-1",250,-0.75,0.75,250,-0.125,0.125);
  TH2D *hdpel_yfp_old = new TH2D("hdpel_yfp_old", "Old MEs; yfp (m); p/p_{elastic}(#theta)-1",250,-0.25,0.25,250,-0.125,0.125);
  TH2D *hdpel_xpfp_old = new TH2D("hdpel_xpfp_old", "Old MEs; xpfp; p/p_{elastic}(#theta)-1",250,-0.4,0.4,250,-0.125,0.125);
  TH2D *hdpel_ypfp_old = new TH2D("hdpel_ypfp_old", "Old MEs; ypfp; p/p_{elastic}(#theta)-1",250,-0.15,0.15,250,-0.125,0.125);

  TH2D *hpthetabend_xfp_old = new TH2D("hpthetabend_xfp_old", "Old MEs; xfp (m); p#theta_{bend}",250,-0.75,0.75,250,0.2,0.35);
  TH2D *hpthetabend_yfp_old = new TH2D("hpthetabend_yfp_old", "Old MEs; yfp (m); p#theta_{bend}",250,-0.25,0.25,250,0.2,0.35);
  TH2D *hpthetabend_xpfp_old = new TH2D("hpthetabend_xpfp_old", "Old MEs; xpfp; p#theta_{bend}",250,-0.4,0.4,250,0.2,0.35);
  TH2D *hpthetabend_ypfp_old = new TH2D("hpthetabend_ypfp_old", "Old MEs; ypfp; p#theta_{bend}",250,-0.15,0.15,250,0.2,0.35);

  TH2D *hpthetabend_xptar_old = new TH2D("hpthetabend_xptar_old", "Old MEs; xptar; p#theta_{bend}",250,-0.4,0.4,250,0.0,0.5);
  TH2D *hpthetabend_yptar_old = new TH2D("hpthetabend_yptar_old", "Old MEs; yptar; p#theta_{bend}",250,-0.15,0.15,250,0.2,0.35);
  TH2D *hpthetabend_ytar_old = new TH2D("hpthetabend_ytar_old", "Old MEs; ytar; p#theta_{bend}",250,-0.15,0.15,250,0.2,0.35);

  TH2D *hdpel_xptar_old = new TH2D("hdpel_xptar_old", "Old MEs; xptar; p/p_{elastic}(#theta)-1",250,-0.4,0.4,250,-0.125,0.125);
  TH2D *hdpel_yptar_old = new TH2D("hdpel_yptar_old", "Old MEs; yptar; p/p_{elastic}(#theta)-1",250,-0.15,0.15,250,-0.125,0.125);
  TH2D *hdpel_ytar_old = new TH2D("hdpel_ytar_old", "Old MEs; ytar; p/p_{elastic}(#theta)-1",250,-0.15,0.15,250,-0.125,0.125);

  TH1D *hdx_HCAL_old = new TH1D("hdx_HCAL_old","Old MEs; xHCAL - xBB (m);", 250, -2.5,2.5);
  TH1D *hdy_HCAL_old = new TH1D("hdy_HCAL_old","Old MEs; yHCAL - yBB (m);", 250, -1.25,1.25);
  
  TH2D *hdxdy_HCAL_old = new TH2D("hdxdy_HCAL_old","Old MEs; yHCAL - yBB (m); xHCAL - xBB (m)", 250, -1.25,1.25, 250,-2.5,2.5);
  TH2D *hdxdy_HCAL_new = new TH2D("hdxdy_HCAL_new","Old MEs; yHCAL - yBB (m); yHCAL - yBB (m)", 250, -1.25,1.25, 250,-2.5,2.5);
  
  TH1D *hW_new = new TH1D("hW_new","New MEs;W (GeV);",250,0,2);
  TH1D *hdpel_new = new TH1D("hdpel_new","New MEs;p/p_{elastic}(#theta)-1;",250,-0.25,0.25);

  TH1D *hW_new_nocut = new TH1D("hW_new_nocut","New MEs;W (GeV);",250,0,2);
  TH1D *hdpel_new_nocut = new TH1D("hdpel_new_nocut","New MEs;p/p_{elastic}(#theta)-1;",250,-0.25,0.25);

  TH2D *hW2_thpq_p = new TH2D("hW2_thpq_p",";#theta_{pq}^{(p)} (deg);W^{2} (GeV^{2})",250,0,12,250,0,2.5);
  TH2D *hW2_thpq_n = new TH2D("hW2_thpq_n",";#theta_{pq}^{(n)} (deg);W^{2} (GeV^{2})",250,0,12,250,0,2.5);

  TH1D *hdt_HCAL = new TH1D("hdt_HCAL", ";t_{HCAL}-t_{HODO} (ns);",250,-125,125);
  TH1D *hE_HCAL = new TH1D("hE_HCAL", ";E_{HCAL} (GeV);",500,0,1.0);
  
  TTree *Tout = new TTree("Tout","Tree containing variables for momentum calibration");

  double T_ebeam, T_etheta, T_ephi, T_precon, T_pelastic, T_thetabend, T_dpel, T_W2;
  double T_pincident;
  double T_xfp, T_yfp, T_thfp, T_phfp;
  double T_xfp0, T_yfp0, T_thfp0, T_phfp0;
  double T_thtgt, T_phtgt, T_ytgt, T_xtgt;
  double T_xfcp, T_yfcp, T_zfcp, T_xbcp, T_ybcp, T_zbcp;
  double T_bbtrchi2, T_bbtrchi2hits, T_bbtrnhits, T_bbtrngoodhits, T_bbtrt0;
  double T_vx, T_vy, T_vz;
  double T_BBdist, T_BBtheta;
  double T_HCALdist, T_HCALtheta;
  int T_nclHCAL;
  double T_xHCAL, T_yHCAL, T_EHCAL, T_THCAL_adc, T_THCAL_tdc, T_deltax, T_deltay;
  double T_xHCAL_expect, T_yHCAL_expect;
  double T_xHCAL_expect_4vect, T_yHCAL_expect_4vect;
  double T_pp_expect, T_ptheta_expect, T_pphi_expect;
  double T_EPS, T_ESH, T_Etot, T_TPS, T_TSH;
  double T_xSH, T_ySH, T_xPS;
  double T_Q2;
  double T_Q2_4vect, T_W2_4vect;
  double T_thetaq, T_phiq, T_px, T_py, T_pz, T_qx, T_qy, T_qz, T_qmag;
  double T_theta_recon_n, T_phi_recon_n, T_theta_recon_p, T_phi_recon_p; //Reconstructed nucleon angles under proton and neutron hypothesis
  double T_thetapq_n, T_phipq_n, T_thetapq_p, T_phipq_p;
  double T_thetapq_n_4vect, T_thetapq_p_4vect, T_thetapq_p_exact, T_thetapq_p_exact_4vect;
  double T_dx_4vect, T_dy_4vect; //Here we want to use the 4-vector momentum transfer to calculate dx/dy
  double T_dt;
  double T_dta;
  double T_Thodo;
  
  double T_protondeflect, T_protondeflect_4vect, T_protondeflect_exact, T_protondeflect_exact_4vect;

  // These are "expected" TOF values for neutron and proton elastic/QE hypotheses; to be calculated from
  // BigBite vertex and q-vector information (angles-only and 4-vector methods)
  double T_nTOF, T_nTOF_4vect, T_pTOF, T_pTOF_4vect, T_pTOF_exact, T_pTOF_exact_4vect;

  double T_pathLnHCAL; //straight-line path from vertex to ***measured*** HCAL cluster
  // We can also calculate the straight-line path length to the actual measured HCAL cluster. What should we call this? 
  // Without tracking in SBS, we can't directly calculate charged-particle path length. 
  
  int T_grinch_tridx;
  int T_grinch_clustersize;
  double T_grinch_tmean;
  double T_grinch_xmean;
  double T_grinch_ymean;
  double T_grinch_adc;
  double T_epsilon,T_epsilon_inel;
  
  int bestHCALcluster;
  int HCALcut;
  int BBcut;

  int T_runnum;
  
  Tout->Branch( "runnum", &T_runnum, "runnum/I");
  
  Tout->Branch( "HCALcut", &HCALcut, "HCALcut/I");
  Tout->Branch( "BBcut", &BBcut, "BBcut/I");
  Tout->Branch( "Ebeam", &T_ebeam, "Ebeam/D" );
  Tout->Branch( "Q2", &T_Q2, "Q2/D");
  Tout->Branch( "epsilon", &T_epsilon, "epsilon/D");
  Tout->Branch( "epsilon_inel", &T_epsilon_inel, "epsilon_inel/D");
  Tout->Branch( "etheta", &T_etheta, "etheta/D");
  Tout->Branch( "ephi", &T_ephi, "ephi/D");
  Tout->Branch( "ep_recon", &T_precon, "ep_recon/D");
  Tout->Branch( "ep_elastic", &T_pelastic, "ep_elastic/D");
  Tout->Branch( "ep_incident", &T_pincident, "ep_incident/D");
  Tout->Branch( "thetabend", &T_thetabend, "thetabend/D");
  Tout->Branch( "dpel", &T_dpel, "dpel/D");
  Tout->Branch( "W2", &T_W2, "W2/D");
  Tout->Branch( "xfp", &T_xfp, "xfp/D");
  Tout->Branch( "yfp", &T_yfp, "yfp/D");
  Tout->Branch( "thfp", &T_thfp, "thfp/D");
  Tout->Branch( "phfp", &T_phfp, "phfp/D");
  Tout->Branch( "xfp0", &T_xfp0, "xfp0/D");
  Tout->Branch( "yfp0", &T_yfp0, "yfp0/D");
  Tout->Branch( "thfp0", &T_thfp0, "thfp0/D");
  Tout->Branch( "phfp0", &T_phfp0, "phfp0/D");
  Tout->Branch( "thtgt", &T_thtgt, "thtgt/D");
  Tout->Branch( "phtgt", &T_phtgt, "phtgt/D");
  Tout->Branch( "ytgt", &T_ytgt, "ytgt/D");
  Tout->Branch( "xtgt", &T_xtgt, "xtgt/D");
  Tout->Branch( "xfcp", &T_xfcp, "xfcp/D");
  Tout->Branch( "yfcp", &T_yfcp, "yfcp/D");
  Tout->Branch( "zfcp", &T_zfcp, "zfcp/D");
  Tout->Branch( "xbcp", &T_xbcp, "xbcp/D");
  Tout->Branch( "ybcp", &T_ybcp, "ybcp/D");
  Tout->Branch( "zbcp", &T_zbcp, "zbcp/D");
  
  Tout->Branch( "bbtrchi2", &T_bbtrchi2, "bbtrchi2/D");
  Tout->Branch( "bbtrchi2hits", &T_bbtrchi2hits, "bbtrchi2hits/D");
  Tout->Branch( "bbtrnhits", &T_bbtrnhits, "bbtrnhits/D");
  Tout->Branch( "bbtrngoodhits", &T_bbtrngoodhits, "bbtrngoodhits/D");
  Tout->Branch( "bbtrt0", &T_bbtrt0, "bbtrt0/D");
  Tout->Branch( "vx", &T_vx, "vx/D");
  Tout->Branch( "vy", &T_vy, "vy/D");
  Tout->Branch( "vz", &T_vz, "vz/D");
  Tout->Branch( "BBdist", &T_BBdist, "BBdist/D");
  Tout->Branch( "BBtheta", &T_BBtheta, "BBtheta/D");
  Tout->Branch( "HCALdist", &T_HCALdist, "HCALdist/D");
  Tout->Branch( "HCALtheta", &T_HCALtheta, "HCALtheta/D");
  Tout->Branch( "nclHCAL", &T_nclHCAL, "nclHCAL/I" );
  Tout->Branch( "xHCAL", &T_xHCAL, "xHCAL/D");
  Tout->Branch( "yHCAL", &T_yHCAL, "yHCAL/D");
  Tout->Branch( "xHCAL_expect", &T_xHCAL_expect, "xHCAL_expect/D");
  Tout->Branch( "yHCAL_expect", &T_yHCAL_expect, "yHCAL_expect/D");
  Tout->Branch( "xHCAL_expect_4vect", &T_xHCAL_expect_4vect, "xHCAL_expect_4vect/D");
  Tout->Branch( "yHCAL_expect_4vect", &T_yHCAL_expect_4vect, "yHCAL_expect_4vect/D");
  Tout->Branch( "EHCAL", &T_EHCAL, "EHCAL/D");
  Tout->Branch( "THCAL_adc", &T_THCAL_adc, "THCAL_adc/D");
  Tout->Branch( "THCAL_tdc", &T_THCAL_tdc, "THCAL_tdc/D");
  Tout->Branch( "deltax", &T_deltax, "deltax/D");
  Tout->Branch( "deltay", &T_deltay, "deltay/D");
  Tout->Branch( "pp_expect", &T_pp_expect, "pp_expect/D");
  Tout->Branch( "ptheta_expect", &T_ptheta_expect, "ptheta_expect/D");
  Tout->Branch( "pphi_expect", &T_pphi_expect, "pphi_expect/D");
  Tout->Branch( "EPS", &T_EPS, "EPS/D");
  Tout->Branch( "ESH", &T_ESH, "ESH/D");
  Tout->Branch( "Etot", &T_Etot, "Etot/D");
  Tout->Branch( "xSH", &T_xSH, "xSH/D");
  Tout->Branch( "ySH", &T_ySH, "ySH/D");
  Tout->Branch( "xPS", &T_xPS, "xPS/D");
  Tout->Branch( "TSH", &T_TSH, "TSH/D");
  Tout->Branch( "TPS", &T_TPS, "TPS/D");
  Tout->Branch( "Q2_4vect", &T_Q2_4vect, "Q2_4vect/D");
  Tout->Branch( "W2_4vect", &T_W2_4vect, "W2_4vect/D");
  Tout->Branch( "epx", &T_px, "epx/D");
  Tout->Branch( "epy", &T_py, "epy/D");
  Tout->Branch( "epz", &T_pz, "epz/D");
  Tout->Branch( "qx", &T_qx, "qx/D" );
  Tout->Branch( "qy", &T_qy, "qy/D" );
  Tout->Branch( "qz", &T_qz, "qz/D" );
  Tout->Branch( "qmag", &T_qmag, "qmag/D" );
  Tout->Branch( "thetaq", &T_thetaq, "thetaq/D");
  Tout->Branch( "phiq", &T_phiq, "phiq/D" );
  Tout->Branch( "thetarecon_n", &T_theta_recon_n, "thetarecon_n/D" );
  Tout->Branch( "phirecon_n", &T_phi_recon_n, "phirecon_n/D" );
  Tout->Branch( "thetarecon_p", &T_theta_recon_p, "thetarecon_p/D" );
  Tout->Branch( "phirecon_p", &T_phi_recon_p, "phirecon_p/D" );
  Tout->Branch( "thetapq_n", &T_thetapq_n, "thetapq_n/D" );
  Tout->Branch( "thetapq_p", &T_thetapq_p, "thetapq_p/D" );
  Tout->Branch( "thetapq_n_4vect", &T_thetapq_n_4vect, "thetapq_n_4vect/D" );
  Tout->Branch( "thetapq_p_4vect", &T_thetapq_p_4vect, "thetapq_p_4vect/D" );
  Tout->Branch( "thetapq_p_exact", &T_thetapq_p_exact, "thetapq_p_exact/D" );
  Tout->Branch( "thetapq_p_exact_4vect", &T_thetapq_p_exact_4vect, "thetapq_p_exact_4vect/D" );
  
  Tout->Branch( "deltat", &T_dt, "deltat/D");
  Tout->Branch( "deltat_adc", &T_dta, "deltat_ADC/D");
  //Tout->Branch( "phipq_n", &T_phipq_n, "phipq_n/D" );
  //Tout->Branch( "phipq_p", &T_phipq_p, "phipp_n/D" );
  Tout->Branch( "deltax_4vect", &T_dx_4vect, "deltax_4vect/D" );
  Tout->Branch( "deltay_4vect", &T_dy_4vect, "deltay_4vect/D" );
  Tout->Branch( "protondeflection", &T_protondeflect, "protondeflection/D");
  Tout->Branch( "protondeflection_exact", &T_protondeflect_exact, "protondeflection_exact/D");
  Tout->Branch( "protondeflection_4vect", &T_protondeflect, "protondeflection_4vect/D");
  Tout->Branch( "protondeflection_exact_4vect", &T_protondeflect_exact, "protondeflection_exact_4vect/D");

  Tout->Branch( "nTOF", &T_nTOF, "nTOF/D");
  Tout->Branch( "nTOF_4vect", &T_nTOF_4vect, "nTOF_4vect/D");
  Tout->Branch( "pTOF", &T_pTOF, "pTOF/D");
  Tout->Branch( "pTOF_4vect", &T_pTOF_4vect, "pTOF_4vect/D");
  Tout->Branch( "pTOF_exact", &T_pTOF_exact, "pTOF_exact/D");
  Tout->Branch( "pTOF_4vect_exact", &T_pTOF_exact_4vect, "pTOF_4vect_exact/D");

  Tout->Branch( "pathLnHCAL", &T_pathLnHCAL, "pathLnHCAL/D");
  
  Tout->Branch( "ibest_HCAL", &bestHCALcluster, "ibest_HCAL/I" );

  Tout->Branch( "THODO", &T_Thodo, "THODO/D" );

  int T_HCALindex;
  Tout->Branch("indexHCAL", &T_HCALindex, "indexHCAL/I");
  
  int T_HCALnblk;
  //Write out all the blocks in the best HCAL cluster:
  Tout->Branch( "nblkHCAL", &T_HCALnblk, "nblkHCAL/I" );
  Tout->Branch( "againblkHCAL", againHCAL, "againblkHCAL[nblkHCAL]/D" );
  Tout->Branch( "atimeblkHCAL", atimeHCAL, "atimeblkHCAL[nblkHCAL]/D" );
  Tout->Branch( "eblkHCAL", eblkHCAL, "eblkHCAL[nblkHCAL]/D" );
  Tout->Branch( "idblkHCAL", idblkHCAL, "idblkHCAL[nblkHCAL]/D" );
  //these branches give us enough information to calibrate, but we should
  //probably write out a bit more:
  Tout->Branch( "rowblkHCAL", rowblkHCAL, "rowblkHCAL[nblkHCAL]/D" );
  Tout->Branch( "colblkHCAL", colblkHCAL, "colblkHCAL[nblkHCAL]/D" );
  Tout->Branch( "xblkHCAL", xblkHCAL, "xblkHCAL[nblkHCAL]/D" );
  Tout->Branch( "yblkHCAL", yblkHCAL, "yblkHCAL[nblkHCAL]/D" );

  int T_BBPSnblk;
  Tout->Branch("nblkBBPS", &T_BBPSnblk, "nblkBBPS/I" );
  Tout->Branch("againblkBBPS", againBBPS, "againblkBBPS[nblkBBPS]/D" );
  Tout->Branch("atimeblkBBPS", atimeBBPS, "atimeblkBBPS[nblkBBPS]/D" );
  Tout->Branch("eblkBBPS", eblkBBPS, "eblkBBPS[nblkBBPS]/D" );
  Tout->Branch("idblkBBPS", idblkBBPS, "idblkBBPS[nblkBBPS]/D" );
  Tout->Branch("rowblkBBPS", rowblkBBPS, "rowblkBBPS[nblkBBPS]/D" );
  Tout->Branch("colblkBBPS", colblkBBPS, "colblkBBPS[nblkBBPS]/D" );
  Tout->Branch("xblkBBPS", xblkBBPS, "xblkBBPS[nblkBBPS]/D" );
  Tout->Branch("yblkBBPS", yblkBBPS, "yblkBBPS[nblkBBPS]/D" );

  int T_BBSHnblk;
  Tout->Branch("nblkBBSH", &T_BBSHnblk, "nblkBBSH/I" );
  Tout->Branch("againblkBBSH", againBBSH, "againblkBBSH[nblkBBSH]/D" );
  Tout->Branch("atimeblkBBSH", atimeBBSH, "atimeblkBBSH[nblkBBSH]/D" );
  Tout->Branch("eblkBBSH", eblkBBSH, "eblkBBSH[nblkBBSH]/D" );
  Tout->Branch("idblkBBSH", idblkBBSH, "idblkBBSH[nblkBBSH]/D" );
  Tout->Branch("rowblkBBSH", rowblkBBSH, "rowblkBBSH[nblkBBSH]/D" );
  Tout->Branch("colblkBBSH", colblkBBSH, "colblkBBSH[nblkBBSH]/D" );
  Tout->Branch("xblkBBSH", xblkBBSH, "xblkBBSH[nblkBBSH]/D" );
  Tout->Branch("yblkBBSH", yblkBBSH, "yblkBBSH[nblkBBSH]/D" );

  
  Tout->Branch( "grinch_clsize", &T_grinch_clustersize, "grinch_clsize/I");
  Tout->Branch( "grinch_tridx", &T_grinch_tridx, "grinch_tridx/I");
  Tout->Branch( "grinch_tmean", &T_grinch_tmean, "grinch_tmean/D");
  Tout->Branch( "grinch_xmean", &T_grinch_xmean, "grinch_xmean/D"); 
  Tout->Branch( "grinch_ymean", &T_grinch_ymean, "grinch_ymean/D");
  Tout->Branch( "grinch_adc", &T_grinch_adc, "grinch_adc/D");

  

  
  Long64_t NTOT = C->GetEntriesFast();

  //First pass: accumulate sums required for the fit: 

  int treenum=0, currenttreenum=0;
  
  //while( C->GetEntry(nevent++) ){
  
  //for( Long64_t ievent=0; ievent<NTOT; ievent++ ){

  long ievent = 0;
  while( C->GetEntry(ievent) ){
  
    if( ievent % 100000 == 0 ) {
      cout << ievent << ", run number = " << runnumber << ", file = \""
	   << C->GetFile()->GetName() << "\"" << endl;
    }
    //Long64_t chainEntry = ievent;

    //    C->GetEntry(ievent);

    currenttreenum = C->GetTreeNumber();

    if( currenttreenum != treenum || ievent == 0 ){

      //Very temporary hack: extract run number from filename:

      TString fname = C->GetFile()->GetName();

      TString skey = "e1209019_fullreplay_";

      int start = fname.Index( skey ) + skey.Length();

      TString srunnum( fname( start, 5 ) );

      // cout << "new file name = \"" << fname << "\", run number extracted from file name = \"" << srunnum << "\"" 
      // 	   << ", runnumber from g.runnum = " << int(runnumber) << endl;
      //T_runnum = srunnum.Atoi();
      //T_runnum = runnumber;

      treenum = currenttreenum;
      GlobalCut->UpdateFormulaLeaves();
    }

    T_runnum = runnumber;

    ievent++;
    
    bool passed_global_cut = GlobalCut->EvalInstance(0) != 0;
    
    HCALcut=0;
    BBcut = 0;

    T_HCALnblk = int(nblkHCAL);

    T_BBPSnblk = int(nblkBBPS);
    T_BBSHnblk = int(nblkBBSH);
    
    //T_runnum = int(runnumber);
    
    if( int(ntrack) >= 1 && passed_global_cut ){
      //The first thing we want to do is to calculate the "true" electron momentum incident on BigBite:
      double Ebeam_corrected = ebeam - MeanEloss;

      T_HCALindex = int( indexHCAL ); //best cluster selected by "online" replay
      
      T_xfcp = xfcp[0];
      T_yfcp = yfcp[0];
      T_zfcp = zfcp[0];

      T_xbcp = xbcp[0];
      T_ybcp = ybcp[0];
      T_zbcp = zbcp[0];

      T_xfp0 = xfp0[0];
      T_yfp0 = yfp0[0];
      T_thfp0 = thfp0[0];
      T_phfp0 = phfp0[0];
      
      T_Thodo = hodotfinal[0];
      
      T_ebeam = Ebeam_corrected;
      
      double etheta = acos(pz[0]/p[0]);

      T_etheta = etheta;
      
      // Calculate the expected momentum of an elastically scattered electron at the reconstructed scattering angle and then correct it for the mean energy loss of the
      // electron on its way out of the target:
      double pelastic = Ebeam_corrected/(1.+Ebeam_corrected/Mp*(1.0-cos(etheta))); 
      
      double precon = p[0] + MeanEloss_outgoing; //reconstructed momentum, corrected for mean energy loss exiting the target (later we'll also want to include Al shielding on scattering chamber)

      T_precon = precon;
      T_pelastic = pelastic; 
      T_pincident = pelastic - MeanEloss_outgoing;
      
      double nu_recon = Ebeam_corrected - precon;
      
      double Q2recon = 2.0*Ebeam_corrected*precon*(1.0-cos(etheta));
      double W2recon = pow(Mp,2) + 2.0*Mp*nu_recon - Q2recon;

      T_Q2 = Q2recon;
      T_W2 = W2recon;

      //1 + nu^2 / Q^2 = 1 + Q^4/(4M^2 Q^2) = 1 + tau
      
      T_epsilon_inel = pow(1.0+2.0*(1.0+pow(nu_recon,2)/Q2recon)*pow(tan(etheta/2.0),2),-1);

      T_epsilon = pow(1.0+2.0*(1.0+Q2recon/(4.0*pow(Mp,2)))*pow(tan(etheta/2.0),2),-1);
      
      T_xfp = xfp[0];
      T_yfp = yfp[0];
      T_thfp = thfp[0];
      T_phfp = phfp[0];

      T_thtgt = thtgt[0];
      T_phtgt = phtgt[0];
      T_ytgt = ytgt[0];
      //T_xtgt = xtgt[0];

      //for now:
      T_vx = 0.0;
      T_vy = 0.0;

      //xtgt = -vy - vz * costheta * thtgt
      T_xtgt = -vz[0]*cos(bbtheta)*thtgt[0];

      T_vz = vz[0];

      T_BBdist = BBdist;
      T_BBtheta = bbtheta;
      T_HCALdist = hcaldist;
      T_HCALtheta = sbstheta;

      
      double Wrecon = sqrt( std::max(0.0,W2recon) );
      
      double dpel = precon/pelastic-1.0;

      T_dpel = dpel;
      
      bool passed_HCAL_cut = true;

      TVector3 vertex( 0, 0, vz[0] );
      TLorentzVector Pbeam(0,0,Ebeam_corrected,Ebeam_corrected);
      TLorentzVector Kprime(precon*px[0]/p[0],precon*py[0]/p[0],precon*pz[0]/p[0],precon);
      TLorentzVector Ptarg(0,0,0,Mp);
      
      TLorentzVector q = Pbeam - Kprime;

      T_Q2_4vect = -q.M2();
      T_W2_4vect = (Ptarg + q).M2();

      TVector3 qvect = q.Vect();
      T_thetaq = qvect.Theta();
      T_phiq = qvect.Phi();
      T_px = Kprime.Px();
      T_py = Kprime.Py();
      T_pz = Kprime.Pz();

      T_qx = q.Px();
      T_qy = q.Py();
      T_qz = q.Pz();

      T_qmag = qvect.Mag();
      
      double ephi = atan2( py[0], px[0] );
      //double etheta = acos( pz[0]/p[0] );

      T_ephi = ephi;
      
      //      double nu = Ebeam_corrected - p[0];

      // Usually when we are running this code, the angle reconstruction is already well calibrated, but the momentum reconstruction is
      // unreliable; use pel(theta) as electron momentum for kinematic correlation:
      double nu = Ebeam_corrected - pelastic; 
      
      double pp_expect = sqrt(pow(nu,2)+2.*Mp*nu); //sqrt(nu^2 + Q^2) = sqrt(nu^2 + 2Mnu)
      double pphi_expect = ephi + PI;
      //double ptheta_expect = acos( (Ebeam_corrected-pz[0])/pp_expect ); //will this give better resolution than methods based on electron angle only? Not entirely clear

      T_pp_expect = pp_expect;
      T_pphi_expect = pphi_expect;
      
      double ptheta_expect = acos( (Ebeam_corrected-pelastic*cos(etheta))/pp_expect ); //will this give better resolution than methods based on electron angle only? Not entirely clear

      T_ptheta_expect = ptheta_expect;

      T_EPS = EPS;
      T_ESH = ESH;
      T_Etot = EPS + ESH;
      T_xSH = xSH;
      T_ySH = ySH;
      T_xPS = xPS;
      T_TPS = TPS;
      T_TSH = TSH;
      
      TVector3 pNhat( sin(ptheta_expect)*cos(pphi_expect), sin(ptheta_expect)*sin(pphi_expect), cos(ptheta_expect) );

      TVector3 HCAL_zaxis(-sin(sbstheta),0,cos(sbstheta));
      TVector3 HCAL_xaxis(0,-1,0);
      TVector3 HCAL_yaxis = HCAL_zaxis.Cross(HCAL_xaxis).Unit();
      
      TVector3 HCAL_origin = hcaldist * HCAL_zaxis;
      
      double sintersect = (HCAL_origin - vertex ).Dot( HCAL_zaxis ) / (pNhat.Dot(HCAL_zaxis));
      //Straight-line projection to the surface of HCAL:
      TVector3 HCAL_intersect = vertex + sintersect * pNhat;

      double yexpect_HCAL = (HCAL_intersect - HCAL_origin).Dot( HCAL_yaxis );
      double xexpect_HCAL = (HCAL_intersect - HCAL_origin).Dot( HCAL_xaxis );

      TVector3 qunit = qvect.Unit();

      double s4vect = (HCAL_origin - vertex).Dot( HCAL_zaxis )/ (qunit.Dot( HCAL_zaxis ) );
      TVector3 HCAL_intersect4 = vertex + s4vect * qunit;

      T_xHCAL_expect_4vect = (HCAL_intersect4 - HCAL_origin).Dot( HCAL_xaxis );
      T_yHCAL_expect_4vect = (HCAL_intersect4 - HCAL_origin).Dot( HCAL_yaxis );

      int nhcalclust=nclustHCAL;

      T_nclHCAL = nhcalclust;
      
      int ibest_HCAL = -1;

      double minthpq = 1000.;

      double maxE = 0.0;
      
      //choose the best cluster from HCAL:
      
      //Calculate expected proton deflection using crude model:
      double BdL = sbsfield * sbsmaxfield * Dgap;

      //thetabend = 0.3 * BdL/p: 
      double proton_deflection_4vect = tan( 0.3 * BdL / qvect.Mag() ) * (hcaldist - (sbsdist + Dgap/2.0) );

      double proton_deflection = tan( 0.3 * BdL / pp_expect ) * (hcaldist - (sbsdist + Dgap/2.0) );
      
      double xHCAL_expect_proton, xHCAL_expect_proton_4vect;

      //      T_pathLnHCAL = (HCAL_origin - vertex).Mag();

      double betan = pp_expect / sqrt(pow(pp_expect,2)+pow(Mn,2));
      double betap = pp_expect / sqrt(pow(pp_expect,2)+pow(Mp,2));
      double betan4 = qvect.Mag()/sqrt(pow(qvect.Mag(),2)+pow(Mn,2));
      double betap4 = qvect.Mag()/sqrt(pow(qvect.Mag(),2)+pow(Mp,2));
      
      T_nTOF = (HCAL_intersect - vertex).Mag()/0.299792458/betan;
      T_nTOF_4vect = (HCAL_intersect4 - vertex).Mag()/0.299792458/betan4;

      TVector3 gapmidpoint = (sbsdist + Dgap/2.0)*HCAL_zaxis;

      double sgapmid = (gapmidpoint-vertex).Dot(HCAL_zaxis)/(pNhat.Dot(HCAL_zaxis));
      double sgapmid4 = (gapmidpoint-vertex).Dot(HCAL_zaxis)/(qunit.Dot(HCAL_zaxis));

      TVector3 GapMidInt = vertex + sgapmid * pNhat;
      TVector3 GapMidInt4 = vertex + sgapmid4 * qunit;

      //double BendAngle = 0.299792458 * BdL / pp_expect;
      //double BendAngle4 = 0.299792458 * BdL / T_qmag; 


      TVector3 HCALint_proton = HCAL_intersect - proton_deflection * HCAL_xaxis;
      TVector3 HCALint_proton4 = HCAL_intersect4 - proton_deflection_4vect * HCAL_xaxis;
      
      double pathLp = (GapMidInt - vertex).Mag() + (HCALint_proton - GapMidInt).Mag();
      double pathLp4vect = (GapMidInt4 - vertex).Mag() + (HCALint_proton4 - GapMidInt4).Mag();

      T_pTOF = pathLp/0.299792458/betap;
      T_pTOF_4vect = pathLp4vect/0.299792458/betap4;

      
      //default to no deflection assumption.
      //double pathLp = T_pathLnHCAL, pathLp4vect = T_pathLnHCAL;
      
      bool goodpcalc = true, goodpcalc_4vect = true;
      if( BdL > 0 ){ //do more "precise" calculation:
	double R_cyclotron = pp_expect / 0.3 / (sbsfield * sbsmaxfield);
	
	double thtarSBS_expect = atan( pNhat.Dot( HCAL_xaxis )/ pNhat.Dot(HCAL_zaxis) );
	//x and z where the proton track enters the SBS effective field boundary:
	double x_in = ( sbsdist - vertex.Dot(HCAL_zaxis) ) * tan(thtarSBS_expect);
	double z_in = sbsdist;
	//Center coordinates of the circle:
	double x_center = x_in - R_cyclotron * cos(thtarSBS_expect);
	double z_center = z_in + R_cyclotron * sin(thtarSBS_expect);
	double z_out = sbsdist + Dgap;
	//equation is (x_out - x_center)^2 + (z_out - z_center)^2 = R^2
	// A * x^2 + B * x + C = 0, where:
	// A = 1
	// B = -2 x_center
	// C = x_center^2 + (z_out - z_center)^2 - R^2 
	double Atemp = 1.0;
	double Btemp = -2.0*x_center;
	double Ctemp = pow(x_center,2) + pow( z_out - z_center, 2 ) - pow(R_cyclotron,2);
	double x_out_plus = (-Btemp + sqrt(pow(Btemp,2)-4.0*Atemp*Ctemp))/(2.0*Atemp);
	//double x_out_minus = (-Btemp - sqrt(pow(Btemp,2)-4.0*Atemp*Ctemp))/(2.0*Atemp); 
	//In virtually all PHYSICAL cases, we are interested in the + solution:
	double theta_out = asin( (z_center - z_out)/R_cyclotron );

	double phtarSBS_expect = atan( pNhat.Dot( HCAL_yaxis )/pNhat.Dot(HCAL_zaxis));
	
	//now we project to HCAL and get:
	xHCAL_expect_proton = x_out_plus + tan(theta_out) * (hcaldist - z_out);

	pathLp = (sbsdist - vertex.Dot( HCAL_zaxis ))*sqrt(1.0 + pow(tan(thtarSBS_expect),2) + pow( tan(phtarSBS_expect),2)) + R_cyclotron * (thtarSBS_expect - theta_out) + (hcaldist - z_out)*sqrt(1.0+pow(tan(theta_out),2) + pow(tan(phtarSBS_expect),2));

	T_pTOF_exact = pathLp/0.299792458/betap; //ns
	
	goodpcalc = pow( R_cyclotron, 2 ) > pow( z_out - z_center, 2 );
	// this leads to a negative discriminant
	
	double R_cyclotron_4vect = qvect.Mag() / 0.3 / (sbsfield * sbsmaxfield);

	thtarSBS_expect = atan( qunit.Dot(HCAL_xaxis)/qunit.Dot(HCAL_zaxis) );
	phtarSBS_expect = atan( qunit.Dot(HCAL_yaxis)/qunit.Dot(HCAL_zaxis) );
	x_in = ( sbsdist - vertex.Dot(HCAL_zaxis) ) * tan(thtarSBS_expect);
	x_center = x_in - R_cyclotron_4vect * cos(thtarSBS_expect);
	z_center = z_in + R_cyclotron_4vect * sin(thtarSBS_expect);
	
	Btemp = -2.0*x_center;
	Ctemp = pow(x_center,2) + pow( z_out - z_center, 2 ) - pow(R_cyclotron_4vect,2);
	x_out_plus = (-Btemp + sqrt(pow(Btemp,2)-4.0*Atemp*Ctemp))/(2.0*Atemp);
	theta_out = asin( (z_center-z_out)/R_cyclotron_4vect );

	xHCAL_expect_proton_4vect = x_out_plus + tan(theta_out) * (hcaldist - z_out);

	pathLp4vect = (sbsdist - vertex.Dot( HCAL_zaxis))*sqrt(1.0 + pow(tan(thtarSBS_expect),2)+pow(tan(phtarSBS_expect),2)) +
	  R_cyclotron_4vect * (thtarSBS_expect - theta_out) + (hcaldist - z_out)*sqrt(1.0+pow(tan(theta_out),2)+pow(tan(phtarSBS_expect),2));

	T_pTOF_exact_4vect = pathLp4vect / 0.299792458 / betap4;
	
	goodpcalc_4vect = pow( R_cyclotron_4vect, 2 ) > pow( z_out - z_center, 2 );
      }

      //Fall back to "regular" calculation:
      if( !goodpcalc ){
	xHCAL_expect_proton = xexpect_HCAL - proton_deflection;
	T_pTOF_exact = T_pTOF;
      }
      if( !goodpcalc_4vect ){
	xHCAL_expect_proton_4vect = xexpect_HCAL - proton_deflection_4vect;
	T_pTOF_exact_4vect = T_pTOF_4vect;
      }
      
      
      T_protondeflect = proton_deflection;
      T_protondeflect_4vect = proton_deflection_4vect;

      T_protondeflect_exact = goodpcalc ? xexpect_HCAL - xHCAL_expect_proton : -1000.0;
      T_protondeflect_exact_4vect = goodpcalc_4vect ? T_xHCAL_expect_4vect - xHCAL_expect_proton_4vect : -1000.0;
      
      T_dt = -1000.0;

      T_THCAL_adc = -1000.0;
      T_THCAL_tdc = -1000.0;
      
      for( int iclust=0; iclust<nhcalclust; iclust++ ){
	
	TVector3 HCALpos = HCAL_origin + (xHCAL[iclust] - dx0) * HCAL_xaxis + (yHCAL[iclust]-dy0) * HCAL_yaxis;
	
	//cout << "Expected proton deflection = " << proton_deflection << " meters" << endl;
	
	TVector3 NeutronDirection = (HCALpos - vertex).Unit();
	TVector3 ProtonDirection = (HCALpos + proton_deflection * HCAL_xaxis - vertex).Unit();
	TVector3 ProtonDirection_4vect = (HCALpos + proton_deflection_4vect * HCAL_xaxis - vertex).Unit();
	TVector3 ProtonDirection_exact = (HCALpos + T_protondeflect_exact * HCAL_xaxis - vertex).Unit();
	TVector3 ProtonDirection_exact_4vect = (HCALpos + T_protondeflect_exact_4vect * HCAL_xaxis - vertex).Unit();
	
	double thpq_p_temp = acos( ProtonDirection.Dot( pNhat.Unit() ) );
	double thpq_n_temp = acos( NeutronDirection.Dot( pNhat.Unit() ) );
	double thpq_p_temp_4vect = acos( ProtonDirection_4vect.Dot( qvect.Unit() ) );
	double thpq_n_temp_4vect = acos( NeutronDirection.Dot( qvect.Unit() ) );

	double thpq_p_temp_exact = acos( ProtonDirection_exact.Dot( pNhat.Unit() ) );
	double thpq_p_temp_exact_4vect = acos( ProtonDirection_exact_4vect.Dot( qvect.Unit() ) );


	double deltat_temp = ADCTIMEHCAL[iclust] - TSH;
       

	//T_dt = ADCTIMEHCAL[iclust] - 

	//The following chooses the highest-energy cluster passing the coincidence time cut:
	bool isbest = false;

	if( fabs( deltat_temp - dt0 ) <= dtcut || hcal_selectionflag >= 2 ){ //ignore time cut if selection flag > 1
	  
	  isbest = ibest_HCAL < 0 || EHCAL[iclust] > maxE;
	  if( hcal_selectionflag == 1 ) isbest = ibest_HCAL < 0 || std::min( thpq_p_temp, thpq_n_temp ) < minthpq;

	  if(  std::min(thpq_p_temp, thpq_n_temp) < minthpq ){
	    minthpq = std::min(thpq_p_temp, thpq_n_temp);
	  }

	  if( EHCAL[iclust] > maxE ){
	    maxE = EHCAL[iclust];
	  }
	  
	  if( isbest ){
	  //if( ibest_HCAL < 0 || std::min( thpq_p_temp, thpq_n_temp ) < minthpq ){
	    ibest_HCAL = iclust;
	    

	    T_pathLnHCAL = (HCALpos-vertex).Mag();
	    
	    T_theta_recon_n = acos( NeutronDirection.Z() );
	    T_phi_recon_n = TMath::ATan2( NeutronDirection.Y(), NeutronDirection.X() );
	    
	    T_theta_recon_p = acos( ProtonDirection.Z() );
	    T_phi_recon_p = TMath::ATan2( ProtonDirection.Y(), ProtonDirection.X() );
	    
	    //T_thetapq_n = acos( NeutronDirection.Dot( qvect.Unit() ) );
	    //T_thetapq_p = acos( ProtonDirection.Dot( qvect.Unit() ) );

	    T_thetapq_n = thpq_n_temp;
	    T_thetapq_p = thpq_p_temp;
	    T_thetapq_n_4vect = thpq_n_temp_4vect;
	    T_thetapq_p_4vect = thpq_p_temp_4vect;
	    T_thetapq_p_exact = thpq_p_temp_exact;
	    T_thetapq_p_exact_4vect = thpq_p_temp_exact_4vect;
	    
	    T_dx_4vect = xHCAL[ibest_HCAL] - (HCAL_intersect4 - HCAL_origin).Dot( HCAL_xaxis ) - dx0;
	    T_dy_4vect = yHCAL[ibest_HCAL] - (HCAL_intersect4 - HCAL_origin).Dot( HCAL_yaxis ) - dy0;

	    T_dt = TDCTIMEHCAL[iclust] - hodotmean[0];

	    T_THCAL_adc = ADCTIMEHCAL[ibest_HCAL];
	    T_THCAL_tdc = TDCTIMEHCAL[ibest_HCAL];
	    //T_dta = ADCTIMEHCAL[iclust] - hodotmean[0];
	    T_dta = deltat_temp;

	  }
	}
      }

      if( ibest_HCAL < 0 && nhcalclust > 0 ) {
	ibest_HCAL = 0;

	TVector3 HCALpos = HCAL_origin + (xHCAL[ibest_HCAL] - dx0) * HCAL_xaxis + (yHCAL[ibest_HCAL]-dy0) * HCAL_yaxis;
	
	//cout << "Expected proton deflection = " << proton_deflection << " meters" << endl;
	
	TVector3 NeutronDirection = (HCALpos - vertex).Unit();
	TVector3 ProtonDirection = (HCALpos + proton_deflection * HCAL_xaxis - vertex).Unit();
	TVector3 ProtonDirection_4vect = (HCALpos + proton_deflection_4vect * HCAL_xaxis - vertex).Unit();
	TVector3 ProtonDirection_exact = (HCALpos + T_protondeflect_exact * HCAL_xaxis - vertex).Unit();
	TVector3 ProtonDirection_exact_4vect = (HCALpos + T_protondeflect_exact_4vect * HCAL_xaxis - vertex).Unit();
	
	double thpq_p_temp = acos( ProtonDirection.Dot( pNhat.Unit() ) );
	double thpq_n_temp = acos( NeutronDirection.Dot( pNhat.Unit() ) );
	double thpq_p_temp_4vect = acos( ProtonDirection_4vect.Dot( qvect.Unit() ) );
	double thpq_n_temp_4vect = acos( NeutronDirection.Dot( qvect.Unit() ) );

	double thpq_p_temp_exact = acos( ProtonDirection_exact.Dot( pNhat.Unit() ) );
	double thpq_p_temp_exact_4vect = acos( ProtonDirection_exact_4vect.Dot( qvect.Unit() ) );
      
	double deltat_temp = ADCTIMEHCAL[ibest_HCAL] - TSH;

	T_pathLnHCAL = (HCALpos - vertex).Mag();
	
	
	T_theta_recon_n = acos( NeutronDirection.Z() );
	T_phi_recon_n = TMath::ATan2( NeutronDirection.Y(), NeutronDirection.X() );
	    
	T_theta_recon_p = acos( ProtonDirection.Z() );
	T_phi_recon_p = TMath::ATan2( ProtonDirection.Y(), ProtonDirection.X() );

	T_thetapq_n = thpq_n_temp;
	T_thetapq_p = thpq_p_temp;
	T_thetapq_n_4vect = thpq_n_temp_4vect;
	T_thetapq_p_4vect = thpq_p_temp_4vect;
	T_thetapq_p_exact = thpq_p_temp_exact;
	T_thetapq_p_exact_4vect = thpq_p_temp_exact_4vect;
	    
	T_dx_4vect = xHCAL[ibest_HCAL] - (HCAL_intersect4 - HCAL_origin).Dot( HCAL_xaxis ) - dx0;
	T_dy_4vect = yHCAL[ibest_HCAL] - (HCAL_intersect4 - HCAL_origin).Dot( HCAL_yaxis ) - dy0;

	T_dt = TDCTIMEHCAL[ibest_HCAL] - hodotmean[0];

	//T_dta = ADCTIMEHCAL[iclust] - hodotmean[0];
	T_dta = deltat_temp;
      }
      
      bestHCALcluster = ibest_HCAL;
      
      //Now we need to calculate the "true" trajectory bend angle for the electron from the reconstructed angles:
      TVector3 enhat_tgt( thtgt[0], phtgt[0], 1.0 );
      enhat_tgt = enhat_tgt.Unit();
	
      TVector3 enhat_fp( thfp[0], phfp[0], 1.0 );
      enhat_fp = enhat_fp.Unit();
	
      TVector3 GEMzaxis(-sin(GEMpitch),0,cos(GEMpitch));
      TVector3 GEMyaxis(0,1,0);
      TVector3 GEMxaxis = (GEMyaxis.Cross(GEMzaxis)).Unit();
      
      TVector3 enhat_fp_rot = enhat_fp.X() * GEMxaxis + enhat_fp.Y() * GEMyaxis + enhat_fp.Z() * GEMzaxis;
      
      double thetabend = acos( enhat_fp_rot.Dot( enhat_tgt ) );
      
      T_thetabend = thetabend;

      T_xHCAL_expect = xexpect_HCAL;
      T_yHCAL_expect = yexpect_HCAL;
      
      HCALcut = 0;

      passed_HCAL_cut = true;
      if( usehcalcut != 0 ) passed_HCAL_cut = false;
      
      if( ibest_HCAL >= 0 ){
	if( Wrecon >= Wmin_fit && Wrecon <= Wmax_fit ){
	  hdx_HCAL_old->Fill( xHCAL[ibest_HCAL] - xexpect_HCAL );
	  hdy_HCAL_old->Fill( yHCAL[ibest_HCAL] - yexpect_HCAL );
	  hdxdy_HCAL_old->Fill( yHCAL[ibest_HCAL] - yexpect_HCAL,
				xHCAL[ibest_HCAL] - xexpect_HCAL );

	  hdt_HCAL->Fill( TDCTIMEHCAL[ibest_HCAL] - hodotmean[0] );
	  hE_HCAL->Fill( EHCAL[ibest_HCAL] );
	}

	T_dt = TDCTIMEHCAL[ibest_HCAL] - hodotmean[0];
	  
	T_xHCAL = xHCAL[ibest_HCAL];
	T_yHCAL = yHCAL[ibest_HCAL];
	T_EHCAL = EHCAL[ibest_HCAL];
	T_deltax = xHCAL[ibest_HCAL] - xexpect_HCAL - dx0;
	T_deltay = yHCAL[ibest_HCAL] - yexpect_HCAL - dy0;

	T_THCAL_adc = ADCTIMEHCAL[ibest_HCAL];
	T_THCAL_tdc = TDCTIMEHCAL[ibest_HCAL];

	T_dta = ADCTIMEHCAL[ibest_HCAL] - TSH;
	
	if( usehcalcut != 0 ){
	  passed_HCAL_cut = pow( (xHCAL[ibest_HCAL]-xexpect_HCAL - dx0)/dxsigma, 2 ) +
	    pow( (yHCAL[ibest_HCAL]-yexpect_HCAL - dy0)/dysigma, 2 ) <= pow(2.5,2); 
	}

	HCALcut = pow( (xHCAL[ibest_HCAL]-xexpect_HCAL - dx0)/dxsigma, 2 ) +
	  pow( (yHCAL[ibest_HCAL]-yexpect_HCAL - dy0)/dysigma, 2 ) <= pow(2.5,2);

	hW2_thpq_p->Fill( T_thetapq_p*180.0/PI, W2recon );
	hW2_thpq_n->Fill( T_thetapq_n*180.0/PI, W2recon );
      } else {
	T_xHCAL = -1000.;
	T_yHCAL = -1000.;
	T_EHCAL = 0.;
	T_deltax = -1000.;
	T_deltay = -1000.;
	T_dx_4vect = -1000.;
	T_dy_4vect = -1000.;
	T_nclHCAL = 0;
	T_THCAL_adc = -1000.;
	T_THCAL_tdc = -1000.;
	T_dt = -1000;
	T_dta = -1000.;
	T_pathLnHCAL = 1000.;
      }
      BBcut = Wrecon >= Wmin_fit && Wrecon <= Wmax_fit && dpel >= dpelmin_fit && dpel <= dpelmax_fit;
      
      if( passed_HCAL_cut ){
	  
	hdpel_old->Fill( dpel );
	hW_old->Fill( sqrt(W2recon) );
	
	hdpel_xfp_old->Fill( xfp[0], dpel );
	hdpel_yfp_old->Fill( yfp[0], dpel );
	hdpel_xpfp_old->Fill( thfp[0], dpel );
	hdpel_ypfp_old->Fill( phfp[0], dpel );
	
	
	hdpel_xptar_old->Fill( thtgt[0], dpel );
	hdpel_yptar_old->Fill( phtgt[0], dpel );
	hdpel_ytar_old->Fill( ytgt[0], dpel );
	
	
	double pincident = pelastic - MeanEloss_outgoing;
	
	
	
	// cout << "Reconstructed bend angle = " << thetabend * TMath::RadToDeg() << endl;
	// cout << "p*thetabend = " << pincident * thetabend << endl;
	
	//Increment sums only if dpel and W are within limits:
	  
	hpthetabend_xptar_old->Fill( thtgt[0], pincident*thetabend );
	
	if( dpel >= dpelmin_fit && dpel <= dpelmax_fit &&
	    Wrecon >= Wmin_fit && Wrecon <= Wmax_fit ){
	  //cout << "dpel, W = " << dpel << ", " << Wrecon << endl;
	  
	  hp_old->Fill( precon );
	  hpthetabend_old->Fill( pincident * thetabend );
	  
	  hpthetabend_xfp_old->Fill( xfp[0], pincident*thetabend );
	  hpthetabend_yfp_old->Fill( yfp[0], pincident*thetabend );
	  hpthetabend_xpfp_old->Fill( thfp[0], pincident*thetabend );
	  hpthetabend_ypfp_old->Fill( phfp[0], pincident*thetabend );
	  
	  
	  hpthetabend_yptar_old->Fill( phtgt[0], pincident*thetabend );
	  hpthetabend_ytar_old->Fill( ytgt[0], pincident*thetabend );
	  
	  hxpfp_vs_xfp_old->Fill( xfp[0], thfp[0] );
	  
	}
      }
    
      T_grinch_tridx = int( GRINCH_trackindex );
      T_grinch_clustersize = int( GRINCH_clustersize );
      T_grinch_tmean = GRINCH_tmean;
      T_grinch_xmean = GRINCH_xmean;
      T_grinch_ymean = GRINCH_ymean;
      T_grinch_adc = GRINCH_adc;

      T_bbtrchi2 = bbtrchi2[0];
      T_bbtrchi2hits = bbtrchi2hits[0];
      T_bbtrnhits = bbtrnhits[0];
      T_bbtrngoodhits = bbtrngoodhits[0];
      T_bbtrt0 = bbtrt0[0];
  
      //if( ibest_HCAL >= 0 ) Tout->Fill();
      Tout->Fill();
    }
  }
  cout << "Event loop finished..." << endl;
 
  fout->Write();

  cout << "output file written..." << endl;
}
