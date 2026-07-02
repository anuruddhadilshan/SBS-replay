#include "gmn_tree.C"
#include "TChain.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>
#include "TString.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TCut.h"
#include "TTreeFormula.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TDecompSVD.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TClonesArray.h"
#include "TSpectrum.h"
#include <cmath>
#include <vector>
#include <set>
#include "TCanvas.h"
#include "TPad.h"
#include "TSystem.h"
#include "TGraph.h"
#include "TMinuit.h"
#include "TClonesArray.h"
#include "TGraphErrors.h"
#include "TFitResult.h"
#include "TF1.h"

const double Mp=0.938272;
const double Mn = 0.939565;

// long NEVENTSFIT;
// vector<int> NHITS_EVENT;
// vector<vector<int> > HITBAR; //BAR ID OF HITS
// vector<vector<double> > HIT_TLEFT; // "RAW" TLEFT
// vector<vector<double> > HIT_TRIGHT; // "RAW" TRIGHT
// vector<vector<double> > HIT_TOTLEFT; // TOT LEFT
// vector<vector<double> > 
// void CHI2_FCN( int &npar, double *gin, double &f, double *par, int flag ){

// }

// TFitResultPtr FitGaus_FWHM( TH1D *Htest, double thresh=0.4 ){
//   int binmax = Htest->GetMaximumBin();
//   int binlow = binmax-1, binhigh = binmax+1;
//   double max = Htest->GetBinContent(binmax);

//   while( binlow > 1 && Htest->GetBinContent(binlow) >= thresh * max ){ binlow--; }
//   while( binhigh < Htest->GetNbinsX() && Htest->GetBinContent(binhigh) >= thresh * max ){ binhigh++; }

//   double xlow = Htest->GetBinLowEdge(binlow);
//   double xhigh = Htest->GetBinLowEdge(binhigh+1);
  
//   return Htest->Fit("gaus","SQ","",xlow,xhigh);
// }

TFitResultPtr FitGaus_FWHM( TH1D *Htest, double thresh=0.4 ){
  //Let's do a 3-neighbor bin content sum to more accurately find the true peak bin from possible noisy neighbors.
  int binmax = 1;
  double highest_sum = 0.;

  for ( int i = 2; i < Htest->GetNbinsX(); i++ ){
    double sum = Htest->GetBinContent(i-1) +
                 Htest->GetBinContent(i)   +
                 Htest->GetBinContent(i+1);

    if ( sum > highest_sum ) {
      highest_sum = sum;
      binmax = i;
    }
  }

  //int binmax = Htest->GetMaximumBin();
  int binlow = binmax-1, binhigh = binmax+1;
  double max = Htest->GetBinContent(binmax);

  while( binlow > 1 && Htest->GetBinContent(binlow) >= thresh * max ){ binlow--; }
  while( binhigh < Htest->GetNbinsX() && Htest->GetBinContent(binhigh) >= thresh * max ){ binhigh++; }

  double xlow = Htest->GetBinLowEdge(binlow);
  double xhigh = Htest->GetBinLowEdge(binhigh+1);
  
  return Htest->Fit("gaus","SQ","",xlow,xhigh);
}


void TOFcal_consolidated(const char *inputfilename, const char *outputfilename="TOFcal_temp.root"){

  const int MAXNBLK_HCAL = 50;
  const int MAXNBLK_BBSH = 25;
  const int MAXNBLK_BBPS = 10;

  const int MAXNHIT_GRINCH = 100; //This might need to be adjusted higher for GEN analysis
  
  ifstream configfile(inputfilename);

  if( !configfile ) return;

  TFile *fout = new TFile(outputfilename,"RECREATE");
  
  TChain *C = new TChain("T");
  
  TString currentline;
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endlist") ){
    if( !currentline.BeginsWith("#") ){
      C->Add(currentline.Data());
    }
  }

  TCut globalcut = "";
  
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endcut") ){
    if( !currentline.BeginsWith("#") ){
      globalcut += currentline.Data();
    }
  }

  
  
  //Default reference PMTs for aligning all other PMTs:
  //NOTE: in the current procedure these definitions are meaningless; since we align all the corrected mean times to zero!
  int hodorefID = 44; // reference BAR (not PMT); we'll set the LEFT PMT to the reference by convention
  int hcalrefID = 150; //row 16 column 6

  int BBSHrefID = 95;
  int BBPSrefID = 22;

  int GRINCHrefID = 275;
  
  double zhodo = 1.854454; //meters
  double Lbar_hodo = 0.6; //meters
  double etof0 = (1.96+3.0)/0.299792458; // "central" TOF value:

  double thetaHCAL = 29.4;
  double dHCAL = 11.0;
  double dSBS = 2.25;

  double W2min=0.5, W2max=1.1;
  double W2min_LD2 = 0.1, W2max_LD2 = 1.2;
  bool use_elastic_cut_HCAL = true;
  
  double sbsmaxfield = 1.26;
  double sbsfield_default = 0.0; //default to zero-field assumption for proton TOF calculations
  // When combining different field settings for calculating proton
  // TOF, we need to associate field values with run ranges

  //Need some hit quality checks:
  double totmin = 6.0, totmax = 35.0;
  double totdiff_max = 10.0;
  double tdiff_max = 10.0; //max time difference with respect to cluster maximum
  double ydiff_max = 0.25; // 0.15 m/ (0.18 m/ns) 
  double xdiff_max = 0.06; // vertical position difference of 0.06 m max wrt track projection 

  double GRINCH_TDC_calib = 1.0; //ns/TDC count
  double GRINCH_tdiff_max = 15.0; //ns
  
  int mineventsperbar = 100;
  
  int nfieldsettings;
  vector<int> rmin,rmax;
  vector<double> sbsfield;
  vector<double> ptof_central;
  
  const double Dgap = 48.0*2.54/100.0;
  
  double Ebeam = 5.9826;

  double RF_freq = 249.5e6;
  double bunch_spacing_ns = 1.0e9/RF_freq;
  
  cout << "bunch spacing = " << bunch_spacing_ns << " ns" << endl;

  TString fname_RFoffsets="";

  TString fname_meantime_offsets="";

  TString fname_vscint_old=""; 

  TString fname_walkcorr_old="";

  TString fname_etof_old="";

  TString fname_HCAL_ADCtime_offsets="";
  TString fname_BBSH_ADCtime_offsets="";
  TString fname_BBPS_ADCtime_offsets="";
  TString fname_GRINCH_offsets="";
  
  bool fixhodoparams = false;
  
  bool useRFcorr = false;
  bool fixoffsets = false;

  bool do_etof_calc = false;
  
  double vscint_default = 0.16; //m/ns
  double wL_default = 0.3;
  double wR_default = 0.21;

  double BBtrig_t0 = 371.5;

  double dx0 = 0.0;
  double dy0 = 0.0;
  double dxsigma = 0.05;
  double dysigma = 0.05;
  double dxdy_nsigma_cut = 3.5;

  double dx04vect = 0.0;
  double dy04vect = 0.0;
  double dxsigma4vect = 0.1;
  double dysigma4vect = 0.1;

  double dtcut_SH = 10.0;
  double dtcut_PS = 10.0;
  double dtcut_HCAL = 10.0; 

  int minhits_GRINCH_internal = 100;
  int minhits_GRINCH_hododiff = 300;
  
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endconfig") ){
    if( !currentline.BeginsWith("#") ){
      TObjArray *currentline_tokens = currentline.Tokenize(" ");
      if( currentline_tokens->GetEntries() >= 2 ){
	TString skey = ( (TObjString*) (*currentline_tokens)[0] )->GetString();

	TString sval = ( (TObjString*) (*currentline_tokens)[1] )->GetString();

	if( skey.EqualTo("BBtrig_t0") ){
	  BBtrig_t0 = sval.Atof();
	}
	
	if( skey.EqualTo("totmin") ){
	  totmin = sval.Atof();
	}

	if( skey.EqualTo("totmax") ){
	  totmax = sval.Atof();
	}

	if( skey.EqualTo("tdiff_max") ){
	  tdiff_max = sval.Atof();
	}

	if( skey.EqualTo("ydiff_max") ){
	  ydiff_max = sval.Atof();
	}

	if( skey.EqualTo("xdiff_max") ){
	  xdiff_max = sval.Atof();
	}

	if( skey.EqualTo("totdiff_max") ){
	  totdiff_max = sval.Atof();
	}
	
	if( skey.EqualTo("mineventsperbar") ){
	  mineventsperbar = sval.Atoi();
	}
	
	if( skey.EqualTo("hodorefID") ){
	  hodorefID = sval.Atoi();
	}

	if( skey.EqualTo("hcalrefID") ){
	  hcalrefID = sval.Atoi();
	}

	if( skey.EqualTo("zhodo") ){
	  zhodo = sval.Atof();
	}

	if( skey.EqualTo("Lbar_hodo") ){
	  Lbar_hodo = sval.Atof();
	}

	if( skey.EqualTo("etof0") ){
	  etof0 = sval.Atof();
	}

	if( skey.EqualTo("bunch_spacing_ns") ){
	  bunch_spacing_ns = sval.Atof();
	}

	if( skey.EqualTo( "RFoffsets" ) ){
	  fname_RFoffsets = sval;
	}

	if( skey.EqualTo( "userfcorr" ) ){
	  int val = sval.Atoi();
	  useRFcorr = val > 0;
	}

	if( skey.EqualTo("ebeam") ){
	  Ebeam = sval.Atof();
	}

	if( skey.EqualTo("sbsmaxfield") ){
	  sbsmaxfield = sval.Atof();
	}
	if( skey.EqualTo("sbsdist") || skey.EqualTo("dSBS")){
	  dSBS = sval.Atof();
	}
	if( skey.EqualTo("hcaldist") || skey.EqualTo("dHCAL") ){
	  dHCAL = sval.Atof();
	}
	if( skey.EqualTo("thetaHCAL") ){
	  thetaHCAL = sval.Atof();
	}
	if( skey.EqualTo("W2min") ){
	  W2min = sval.Atof();
	}
	if( skey.EqualTo("W2max") ){
	  W2max = sval.Atof();
	}

	if( skey.EqualTo("W2min_LD2") ){
	  W2min_LD2 = sval.Atof();
	}

	if( skey.EqualTo("W2max_LD2") ){
	  W2max_LD2 = sval.Atof();
	}
	
	if( skey.EqualTo("meantime_offsets_old") ){
	  fname_meantime_offsets = sval;
	}

	if( skey.EqualTo("vscint_old") ){
	  fname_vscint_old = sval;
	}

	if( skey.EqualTo("walkcorr_old") ){ //walk correction slopes
	  fname_walkcorr_old = sval;
	}

	if( skey.EqualTo("etofparams_old") ){
	  fname_etof_old = sval;
	}
	
	if( skey.EqualTo("useelasticcut_HCAL") ){
	  use_elastic_cut_HCAL = (sval.Atoi() > 0);
	}

	if( skey.EqualTo("HCAL_ADCtime_offsets") ){
	  fname_HCAL_ADCtime_offsets = sval;
	}
	if( skey.EqualTo("BBSH_ADCtime_offsets") ){
	  fname_BBSH_ADCtime_offsets = sval;
	}
	if( skey.EqualTo("BBPS_ADCtime_offsets") ){
	  fname_BBPS_ADCtime_offsets = sval;
	}

	if( skey.EqualTo("fixhodoparams") ){
	  fixhodoparams = ( sval.Atoi() != 0 );
	}

	if( skey.EqualTo("dx0") ){
	  dx0 = sval.Atof();
	}
	if( skey.EqualTo("dy0") ){
	  dy0 = sval.Atof();
	}

	if( skey.EqualTo("dxsigma") ){
	  dxsigma = sval.Atof();
	}

	if( skey.EqualTo("dysigma") ){
	  dysigma = sval.Atof();
	}

	if( skey.EqualTo("dxdy_nsigma_cut") ){
	  dxdy_nsigma_cut = sval.Atof();
	}

	if( skey.EqualTo("dxsigma4vect") ){
	  dxsigma4vect = sval.Atof();
	}

	if( skey.EqualTo("dysigma4vect") ){
	  dysigma4vect = sval.Atof();
	}

	if( skey.EqualTo("dx04vect") ){
	  dx04vect = sval.Atof();
	}

	if( skey.EqualTo("dy04vect") ){
	  dy04vect = sval.Atof();
	}

	if( skey.EqualTo( "dtcut_SH" ) ){
	  dtcut_SH = sval.Atof();
	}

	if( skey.EqualTo( "dtcut_PS" ) ){
	  dtcut_PS = sval.Atof();
	}

	if( skey.EqualTo( "dtcut_HCAL" ) ){
	  dtcut_HCAL = sval.Atof();
	}

	if( skey.EqualTo( "GRINCH_TDC_calib" ) ){
	  GRINCH_TDC_calib = sval.Atof();
	}

	if( skey.EqualTo( "GRINCH_TDC_offsets" ) ){
	  fname_GRINCH_offsets = sval;
	}
	
	if( skey.EqualTo( "GRINCH_tdiff_max" ) ){
	  GRINCH_tdiff_max = sval.Atof();
	}

	if( skey.EqualTo( "minhits_GRINCH_internal") ){
	  minhits_GRINCH_internal = sval.Atoi();
	}
	if( skey.EqualTo( "minhits_GRINCH_hododiff") ){
	  minhits_GRINCH_hododiff = sval.Atoi();
	} 
      }
    }
  }

  nfieldsettings = 0;
  
  //Parsing field configuration info to calculate proton TOF corrections:
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endfieldconfig") ){
    if( !currentline.BeginsWith("#") ){
      TObjArray *tokens = currentline.Tokenize(" ");
      //Here we expect three values per line, rmin, rmax, field (as fraction of maximum):
      if( tokens->GetEntries() >= 3 ){
	TString srmin = ( (TObjString*) (*tokens)[0] )->GetString();
	TString srmax = ( (TObjString*) (*tokens)[1] )->GetString();
	TString sfieldval = ( (TObjString*) (*tokens)[2] )->GetString();

	nfieldsettings++;
	rmin.push_back( srmin.Atoi() );
	rmax.push_back( srmax.Atoi() );
	sbsfield.push_back( sfieldval.Atof());
      }
    }
  }

  int ntargsettings=0;
  
  vector<int> rmin_tgt, rmax_tgt, targnum; //0 = LH2, 1 = LD2, default = LH2
  
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endtargetconfig") ){
    if( !currentline.BeginsWith("#") ){
      TObjArray *tokens = currentline.Tokenize(" ");
      //Here we expect three values per line, rmin, rmax, field (as fraction of maximum):
      if( tokens->GetEntries() >= 3 ){
	TString srmin = ( (TObjString*) (*tokens)[0] )->GetString();
	TString srmax = ( (TObjString*) (*tokens)[1] )->GetString();
	TString stargnum = ( (TObjString*) (*tokens)[2] )->GetString();

	ntargsettings++;
	rmin_tgt.push_back( srmin.Atoi() );
	rmax_tgt.push_back( srmax.Atoi() );
	int targtemp = stargnum.Atoi();
	if( targtemp >=0 && targtemp <2 ){
	  targnum.push_back( stargnum.Atoi() );
	} else {
	  targnum.push_back( 0 );
	}
      }
    }
  }
  
  std::cout << "Number of field settings = " << nfieldsettings << endl;

  vector<double> cetof;
  vector<vector<double> > etof_expon;

  if( fname_etof_old != "" ){
    ifstream fetofparams(fname_etof_old.Data());

    if( fetofparams ){
      int nterms = 0;

      fetofparams >> nterms;

      if( nterms > 0 ){
	double ctemp;
	vector<double> expontemp(5,0);
	while( fetofparams >> ctemp >> expontemp[0] >> expontemp[1] >> expontemp[2] >> expontemp[3] >> expontemp[4] ){
	  cetof.push_back( ctemp );
	  etof_expon.push_back( expontemp );
	}
	if( cetof.size() == nterms && etof_expon.size() == nterms ){
	  do_etof_calc = true;
	  cout << "loaded " << nterms << " ETOF coefficients from \"" << fname_etof_old << "\", doing our own ETOF calculation..." << endl;
	}
      }
    }
  }
  
  // Mean time offsets for start time:
  vector<double> RFoffsets(90,0.0);
  vector<double> dRFoffsets(90,1.0);

  ifstream offsetsfile(fname_RFoffsets);
  if( offsetsfile ){
    int noffsets=0;
    while( offsetsfile >> RFoffsets[noffsets] ){
      cout << "bar, RF offset = " << noffsets << ", " << RFoffsets[noffsets] << endl;
      noffsets++;
    }
    cout << "Number of RF offsets loaded = " << noffsets << endl;
    
    if( noffsets != 90 ){
      cout << "Error: RF offsets file does not contain 90 entries, abort" << endl;
      useRFcorr = false;
      exit(-1);
    }
  }

  vector<double> MeanTimeOffsets(90,0.0);

  ifstream offsetsfile2(fname_meantime_offsets.Data());
  
  if( offsetsfile2 ){
    int noffsets = 0;
    while( offsetsfile2 >> MeanTimeOffsets[noffsets] ){
      cout << "bar, meantime offset = " << noffsets << ", " << MeanTimeOffsets[noffsets] << endl;
      noffsets++;
    }
    fixoffsets = true;
    cout << "Number of mean-time offsets loaded = " << noffsets << endl;
    if( noffsets != 90 ){
      cout << "Error: meantime offsets file does not contain 90 entries, abort" << endl;
      fixoffsets = false;
      exit(-1);
    }
  }
	   
  vector<double> VSCINT_OLD(90,vscint_default);
  vector<double> wL_OLD(90,wL_default);
  vector<double> wR_OLD(90,wR_default);

  ifstream vscint_file(fname_vscint_old.Data());
  if( vscint_file ){
    int npar=0;
    while( vscint_file >> VSCINT_OLD[npar] ){
      cout << "bar, vscint = " << npar << ", " << VSCINT_OLD[npar] << endl;
      npar++;
    }

    if( npar != 90 ){
      cout << "Error: vscint file does not contain 90 entries, abort" << endl;
      exit(-1);
    }
  }

  ifstream walkcorr_file(fname_walkcorr_old);

  if( walkcorr_file ){
    int npar=0;
    double par = 0.0;
    while( walkcorr_file >> par ){
      if( par < 0 ) par *= -1.0;
      if( npar<90 ) wL_OLD[npar] = par;
      if( npar >= 90 ) wR_OLD[npar-90] = par;
      npar++;
    }

    if( npar != 180 ){
      cout << "Error: walk correction file given does not contain 180 entries, abort" << endl;
      exit(-1);
    }
  }

  int nchan_HCAL = 288;
  int nchan_BBSH = 189;
  int nchan_BBPS = 52;

  int nchan_GRINCH = 512;

  vector<double> oldGRINCHoffsets( nchan_GRINCH, 0.0 );
  ifstream oldGRINCHoffsetsfile(fname_GRINCH_offsets.Data());
  if( oldGRINCHoffsetsfile ){
    int npar=0; double par=0.0;
    while( oldGRINCHoffsetsfile >> par ){
      if( npar<nchan_GRINCH ){
	//Since time = (TDC - offset)*calib, we want to multiply offset by calib
	// time offset = offset*calib
	// NOTE: we will have to DIVIDE by calib at the end when writing the NEW offsets
	oldGRINCHoffsets[npar] = par * GRINCH_TDC_calib;
      }
      npar++;
    }
    if( npar != nchan_GRINCH ){
      cout << "Error: old GRINCH offsets file contains incorrect number (" << npar << ", expected 512) of entries; abort" << endl;
      exit(-1);
    }
  }
  
  // For the moment, we only add the old offsets to the new ones after the analysis is over
  // for ADC times:
  vector<double> oldHCALoffsets( nchan_HCAL, 0.0 );
  ifstream oldHCALoffsetsfile(fname_HCAL_ADCtime_offsets.Data());

  if( oldHCALoffsetsfile ){
    int npar=0;
    double par=0.0;
    while( oldHCALoffsetsfile >> par ){
      if( npar<nchan_HCAL ){
	oldHCALoffsets[npar] = par;
      }
      npar++;
    }

    if( npar != nchan_HCAL ){
      cout << "Error: old HCAL offsets file contains incorrect number of entries; abort" << endl;
      exit(-1);
    }
  }

  vector<double> oldBBSHoffsets( nchan_BBSH, 0.0 );
  ifstream oldBBSHoffsetsfile(fname_BBSH_ADCtime_offsets.Data());

  if( oldBBSHoffsetsfile ){
    int npar=0;
    double par=0.0;
    while( oldBBSHoffsetsfile >> par ){
      if( npar<nchan_BBSH ){
	oldBBSHoffsets[npar] = par;
      }
      npar++;
    }

    if( npar != nchan_BBSH ){
      cout << "Error: old BBSH offsets file contains incorrect number of entries; abort" << endl;
      exit(-1);
    }
  }

  vector<double> oldBBPSoffsets( nchan_BBPS, 0.0 );
  ifstream oldBBPSoffsetsfile(fname_BBPS_ADCtime_offsets.Data());

  if( oldBBPSoffsetsfile ){
    int npar=0;
    double par=0.0;
    while( oldBBPSoffsetsfile >> par ){
      if( npar<nchan_BBPS ){
	oldBBPSoffsets[npar] = par;
      }
      npar++;
    }

    if( npar != nchan_BBPS ){
      cout << "Error: old BBPS offsets file contains incorrect number of entries; abort" << endl;
      exit(-1);
    }
  }

  
  
  thetaHCAL *= TMath::Pi()/180.0;
  
  TVector3 zaxis_HCAL(-sin(thetaHCAL),0,cos(thetaHCAL));
  TVector3 xaxis_HCAL(0,-1,0);
  TVector3 yaxis_HCAL = (zaxis_HCAL.Cross(xaxis_HCAL)).Unit();

  TVector3 HCALorigin = dHCAL*zaxis_HCAL;

  double pp_ptheta_central = 2.0*Mp*Ebeam*(Mp+Ebeam)*cos(thetaHCAL)/(pow(Mp,2)+2.0*Mp*Ebeam + pow(Ebeam*sin(thetaHCAL),2));
  double Tp_ptheta_central = sqrt(pow(pp_ptheta_central,2)+pow(Mp,2))-Mp;

  double beta_ptheta_central = pp_ptheta_central/(Tp_ptheta_central+Mp);

  double pn_ptheta_central = 2.0*Mn*Ebeam*(Mn+Ebeam)*cos(thetaHCAL)/(pow(Mn,2)+2.0*Mn*Ebeam + pow(Ebeam*sin(thetaHCAL),2));
  double beta_ntheta_central = pn_ptheta_central/sqrt(pow(pn_ptheta_central,2)+pow(Mn,2));
  
  double ptof_central_default = dHCAL/(beta_ptheta_central*0.299792458);
  double ntof_central_default = dHCAL/(beta_ntheta_central*0.299792458);
  
  if( nfieldsettings > 0 ){
    for( int iset=0; iset<nfieldsettings; iset++ ){
      if( sbsfield[iset] > 0. ){
	double BdL = sbsfield[iset]*sbsmaxfield*Dgap;
	double Radius = pp_ptheta_central / 0.299792458 / (sbsfield[iset]*sbsmaxfield);
	double x_in = 0.0;
	double z_in = dSBS;
	double x_center = x_in - Radius;
	double z_center = z_in;
	double z_out = dSBS + Dgap;
	double A = 1.0;
	double B = -2.0*x_center;
	double C = pow(x_center,2) + pow(z_out - z_center,2) - pow(Radius,2);
	double x_out = (-B + sqrt(pow(B,2)-4.0*A*C))/(2.0*A);
	double theta_in = 0.0;
	double theta_out = asin( (z_center-z_out)/Radius );
	//need to calculate path length:
	double pathlength = dSBS + Radius * (theta_in - theta_out) + (dHCAL-z_out )/cos(theta_out);
	ptof_central.push_back( pathlength/(beta_ptheta_central*0.299792458)); //ns 
      } else {
	ptof_central.push_back( ptof_central_default );
      }
    }
  }
  
  
  //int nparams_hodo = 3*180; //offset, walk correction, propagation speed for left and right PMTs for 90 bars minus offset fixed at zero for reference PMT
  //actually, vscint should be determined per paddle;
  int nparams_hodo = 180+2*90; //We actually only really want one zero offset (paddle-specific) that applies to the mean time, so we need 90 zero offsets, 90 vscint values, and 180 walk correction slopes.
  int nparams_HCAL = 288*2; //offset and two walk correction parameters for 288 modules.

  int nparams_hodo_t0fixed= 3*90; // wL, wR, vscint
  
  //Ordering of params:
  // t0, walkileft, walkiright, 1/vscint
  
  TMatrixD Mhodo(nparams_hodo,nparams_hodo);
  TMatrixD Mhcal(nparams_HCAL,nparams_HCAL);
  TVectorD bhodo(nparams_hodo);
  TVectorD bhcal(nparams_HCAL);
  
  for( int ipar=0; ipar<nparams_hodo; ipar++ ){
    for( int jpar=0; jpar<nparams_hodo; jpar++ ){
      Mhodo(ipar,jpar) = 0.0;
    }
    bhodo(ipar) = 0.0;
  }

  // for( int ipar=0; ipar<nparams_hodo_t0fixed; ipar++ ){
  //   for( int jpar=0; jpar<nparams_hodo_t0fixed; jpar++ ){
  //     Mhodo_t0fixed(ipar,jpar) = 0.0;
  //   }
  //   bhodo_t0fixed(ipar) = 0.0;
  // }

  for( int ipar=0; ipar<nparams_HCAL; ipar++ ){
    for( int jpar=0; jpar<nparams_HCAL; jpar++ ){
      Mhcal(ipar,jpar) = 0.0;
    }
    bhcal(ipar) = 0.0;
  }
  
  //HCAL and hodo TDCs both use BigBite trigger as reference time, so both have reference time subtracted:

  TTreeFormula *GlobalCut = new TTreeFormula("GlobalCut",globalcut,C);

  gmn_tree *T = new gmn_tree(C);

  C->SetBranchStatus("*",0);
  C->SetBranchStatus("g.*",1);
  C->SetBranchStatus("bb.hodotdc.*",1);
  C->SetBranchStatus("sbs.hcal.tdctimeblk",1);
  C->SetBranchStatus("sbs.hcal.eblk",1);
  C->SetBranchStatus("sbs.hcal.idblk",1);
  C->SetBranchStatus("sbs.hcal.x",1);
  C->SetBranchStatus("sbs.hcal.y",1);
  C->SetBranchStatus("sbs.hcal.e",1);
  C->SetBranchStatus("sbs.hcal.nblk",1);
  C->SetBranchStatus("sbs.hcal.clus_blk.*",1);
  C->SetBranchStatus("sbs.hcal.nclus",1);
  C->SetBranchStatus("sbs.hcal.atimeblk",1);
  C->SetBranchStatus("sbs.hcal.nblk_goodtdc",1);
  C->SetBranchStatus("bb.tr.*",1);
  C->SetBranchStatus("bb.grinch_tdc.*",1);
  C->SetBranchStatus("bb.gem.track.*",1);
  C->SetBranchStatus("e.kine.*",1);
  C->SetBranchStatus("bb.tdctrig.*",1);
  C->SetBranchStatus("sbs.tdctrig.*",1);
  C->SetBranchStatus("bb.sh.e",1);
  C->SetBranchStatus("bb.ps.e",1);
  C->SetBranchStatus("bb.sh.nblk",1);
  C->SetBranchStatus("bb.ps.nblk",1);
  C->SetBranchStatus("bb.etot_over_p",1);
  C->SetBranchStatus("bb.gem.trigtime",1);
  C->SetBranchStatus("bb.sh.clus_blk.*",1);
  C->SetBranchStatus("bb.ps.clus_blk.*",1);
  
  int treenum=-1,oldtreenum=-1;

  long nevent=0;

  vector<double> nevent_vs_bar(90,0.0);

  TH2D *htmeancorr_vs_ID_old = new TH2D("htmeancorr_vs_ID_old", "OLD; bar ID; corrected t_{mean} (ns)", 90, -0.5, 89.5, 300,-30,30);

  //Matrices for internal alignment offsets:
  TMatrixD Minternal(90,90);
  TVectorD binternal(90);
  for( int i=0; i<90; i++ ){
    for( int j=0; j<90; j++ ){
      Minternal(i,j) = 0.0;
    }
    binternal(i) = 0.0;
  }
  
  // Loop 1: get meantime offsets to align hodoscope internally:
  //if( !fixhodoparams ){ //We skip loops 1 and 2 and simply use "tfinal" if "fixhodoparams" is set:
  cout << "Loop 1: Internal alignment of meantime offsets" << endl;
  while( T->GetEntry(nevent) ){
    if( nevent % 10000 == 0 ){
      cout << "Loop 1: nevent = " << nevent << ", run number = " << T->g_runnum << endl;
    }
    
    treenum = C->GetTreeNumber();
    if( nevent == 0 || treenum != oldtreenum ){
      oldtreenum = treenum;
      GlobalCut->UpdateFormulaLeaves();
    }

    bool passed_global_cut = GlobalCut->EvalInstance(0) != 0;

    if( passed_global_cut ){ //do the things:
      //grab needed track parameters:
      double tref = T->bb_hodotdc_trigtime - T->bb_hodotdc_trigphasecorr - BBtrig_t0;
      
      double vz = T->bb_tr_vz[0];
      double pathl = T->bb_tr_pathl[0];
      double etof = pathl/0.299792458-etof0; //electron TOF from vertex to hodo.

      if( do_etof_calc ){
	double xfp = T->bb_tr_r_x[0];
	double yfp = T->bb_tr_r_y[0];
	double xpfp = T->bb_tr_r_th[0];
	double ypfp = T->bb_tr_r_ph[0];

	etof = etof0;
	for( int ipar=0; ipar<cetof.size(); ipar++ ){
	  double term =
	    pow(xfp,etof_expon[ipar][0])*
	    pow(yfp,etof_expon[ipar][1])*
	    pow(xpfp,etof_expon[ipar][2])*
	    pow(ypfp,etof_expon[ipar][3]);

	  etof += cetof[ipar]*term; //neglecting xtar dependence
							 
	}

	etof -= etof0;
	
      }
      
      double yhodo = T->bb_tr_y[0]+zhodo*T->bb_tr_ph[0];
      double xhodo = T->bb_tr_x[0]+zhodo*T->bb_tr_th[0];
      
      double dLEFT = std::min(Lbar_hodo,std::max(0.0,Lbar_hodo/2.0 - yhodo));
      double dRIGHT = std::min(Lbar_hodo,std::max(0.0,Lbar_hodo/2.0 + yhodo));
      
      double tmean0 = 0.0;
      
      for( int ibar=0; ibar<T->bb_hodotdc_clus_size[0]; ibar++ ){
	//double tHODO = T->bb_hodotdc_clus_bar_tdc_meantime[ibar];
	double tleft = T->bb_hodotdc_clus_bar_tdc_tleft[ibar];
	double tright = T->bb_hodotdc_clus_bar_tdc_tright[ibar];
	double totleft = T->bb_hodotdc_clus_bar_tdc_totleft[ibar];
	double totright = T->bb_hodotdc_clus_bar_tdc_totright[ibar];

	//double tmean = T->bb_hodotdc_clus_bar_tdc_meantime[ibar];
	//double ypos = T->bb_hodotdc_clus_bar_tdc_timehitpos[ibar];
	double xpos = T->bb_hodotdc_clus_bar_tdc_vpos[ibar];
	double IDHODO = T->bb_hodotdc_clus_bar_tdc_id[ibar];

	double tleft_corr_i = tleft - etof - MeanTimeOffsets[IDHODO] + wL_OLD[IDHODO]*totleft - dLEFT/VSCINT_OLD[IDHODO] + tref; 
	double tright_corr_i = tright - etof - MeanTimeOffsets[IDHODO] + wR_OLD[IDHODO]*totright - dRIGHT/VSCINT_OLD[IDHODO] + tref;
	
	double tmeancorr_i = 0.5*(tleft_corr_i + tright_corr_i);
	double tdiffcorr_i = tleft_corr_i - tright_corr_i;
	
	double ypos = -0.5*VSCINT_OLD[IDHODO]*tdiffcorr_i;
    
	if( ibar == 0 ){
	  tmean0 = tmeancorr_i;
	}
	
	bool goodhit_i = totleft >= totmin && totleft <= totmax &&
	  totright >= totmin && totright <= totmax &&
	  fabs( totleft - totright ) <= totdiff_max &&
	  fabs( ypos - yhodo ) <= ydiff_max &&
	  fabs( xpos - xhodo ) <= xdiff_max &&
	  fabs( tmeancorr_i - tmean0 ) <= tdiff_max;
	
	if( goodhit_i ){
	  //apply OLD walk corrections and propagation corrections here for hit quality cuts:

	  for( int jbar=ibar+1; jbar<T->bb_hodotdc_clus_size[0]; jbar++ ){
	    double tleft_j = T->bb_hodotdc_clus_bar_tdc_tleft[jbar];
	    double tright_j = T->bb_hodotdc_clus_bar_tdc_tright[jbar];
	    double totleft_j = T->bb_hodotdc_clus_bar_tdc_totleft[jbar];
	    double totright_j = T->bb_hodotdc_clus_bar_tdc_totright[jbar];
	    
	    //double tmean = T->bb_hodotdc_clus_bar_tdc_meantime[jbar];
	    //double ypos = T->bb_hodotdc_clus_bar_tdc_timehitpos[jbar];
	    double xpos_j = T->bb_hodotdc_clus_bar_tdc_vpos[jbar];
	    double IDHODO_j = T->bb_hodotdc_clus_bar_tdc_id[jbar];

	    double tleft_corr_j = tleft_j - etof - MeanTimeOffsets[IDHODO_j] + wL_OLD[IDHODO_j]*totleft_j - dLEFT/VSCINT_OLD[IDHODO_j] + tref; 
	    double tright_corr_j = tright_j - etof - MeanTimeOffsets[IDHODO_j] + wR_OLD[IDHODO_j]*totright_j - dRIGHT/VSCINT_OLD[IDHODO_j] + tref;
	    
	    double tmeancorr_j = 0.5*(tleft_corr_j + tright_corr_j);
	    double tdiffcorr_j = tleft_corr_j - tright_corr_j;
	    
	    double ypos_j = -0.5*VSCINT_OLD[IDHODO_j]*tdiffcorr_j;
	    
	    bool goodhit_j = totleft_j >= totmin && totleft_j <= totmax &&
	      totright_j >= totmin && totright_j <= totmax &&
	      fabs( totleft_j - totright_j ) <= totdiff_max &&
	      fabs( ypos_j - yhodo ) <= ydiff_max &&
	      fabs( xpos_j - xhodo ) <= xdiff_max &&
	      fabs( tmeancorr_j - tmean0 ) <= tdiff_max;

	    if( goodhit_j ){ // Increment some matrix elements:
	      int ipar_t0_i = IDHODO;
	      int ipar_vinv_i = IDHODO+90;
	      //int ipar_t0R = ID+90;
	      int ipar_wL_i = IDHODO+180;
	      int ipar_wR_i = IDHODO+270;

	      int ipar_t0_j = IDHODO_j;
	      int ipar_vinv_j = IDHODO_j+90;
	      //int ipar_t0R = ID+90;
	      int ipar_wL_j = IDHODO_j+180;
	      int ipar_wR_j = IDHODO_j+270;

	      // tL corrected = tL - tof - t0 + w * TOTL - dL/v = 0
	      // tR corrected = tR - tof - t0 + w * TOTR - dR/v = 0
	      double t_i = tmeancorr_i;
	      double t_j = tmeancorr_j; 

	      nevent_vs_bar[IDHODO] += 1.;
	      nevent_vs_bar[IDHODO_j] += 1.;

	      binternal(IDHODO) += (t_i - t_j);
	      binternal(IDHODO_j) += (t_j - t_i);

	      Minternal(IDHODO,IDHODO) += 1.0;
	      Minternal(IDHODO,IDHODO_j) += -1.0;
	      Minternal(IDHODO_j,IDHODO) += -1.0;
	      Minternal(IDHODO_j,IDHODO_j) += 1.0;
	      
	      
	    }
	  }
	}	      
      }
    }
    nevent++;
  }

  // Get fit results for internal alignments:

  for( int i=0; i<90; i++ ){
    if( nevent_vs_bar[i] <= 100. ){
      cout << "Warning: bar " << i << " fewer than 100 events... zeroing out offsets"
	   << endl;
      binternal(i) = 0.0;
      Minternal(i,i) = 1.0;
      for( int j=0; j<90; j++ ){
	if( j != i ){
	  Minternal(i,j) = Minternal(j,i) = 0.0;
	}
      }
    }
  }

  TDecompSVD Ainternal(Minternal);
  Ainternal.Solve(binternal);

  binternal.Print();
  
  // Correct all offsets so that offset for "reference" channel is not changed:
  double corr = -(MeanTimeOffsets[hodorefID] + binternal(hodorefID));
  for( int i=0; i<90; i++ ){
    binternal(i) += corr;
    MeanTimeOffsets[i] += binternal(i);
    cout << "(i, MeanTimeOffsets[i]) = (" << i << ", "
	 << MeanTimeOffsets[i] << endl;
  }

  nevent = 0;
  cout << "Loop 2: Determine RF offsets after internal alignment" << endl;

  treenum = -1;
  oldtreenum = -1;

  TH2D *hdTij_aligned_vs_IDi = new TH2D("hdTij_aligned_vs_IDi","After internal alignment; hodoscope bar ID; #Deltat_{j-i} (ns)",90,-0.5,89.5,200,-20,20);
  TH2D *hdT_hodo_ID = new TH2D("hdT_hodo_ID", "; hodoscope bar ID ; t_{mean}^{raw}-t_{RF} (ns)", 90,-0.5,89.5, 250, -5.5*bunch_spacing_ns, 5.5*bunch_spacing_ns);

  while( T->GetEntry(nevent) ){

    if( nevent % 10000 == 0 ){
      cout << "Loop 2: nevent = " << nevent << ", run number = " << T->g_runnum << endl;
    }
    
    treenum = C->GetTreeNumber();
    if( nevent == 0 || treenum != oldtreenum ){
      oldtreenum = treenum;
      GlobalCut->UpdateFormulaLeaves();
    }

    bool passed_global_cut = GlobalCut->EvalInstance(0) != 0;

    if( passed_global_cut ){ //do the things:

      double tref = T->bb_hodotdc_trigtime - T->bb_hodotdc_trigphasecorr - BBtrig_t0;
      
      double RFtime = T->bb_hodotdc_rftime + tref;
      
      //RFtime = fmod( RFtime, 160.321 );
      double trigtime = T->bb_tdctrig_trigtime - T->bb_hodotdc_trigphasecorr - BBtrig_t0;

      bool goodRF = fabs( RFtime ) <= 1.e5;
      bool goodTRIG = fabs( trigtime ) <= 1.e5;

      if( goodRF && goodTRIG ){
	//grab needed track parameters:
	double vz = T->bb_tr_vz[0];
	double pathl = T->bb_tr_pathl[0];
	double etof = pathl/0.299792458-etof0; //electron TOF from vertex to hodo.

	if( do_etof_calc ){
	  double xfp = T->bb_tr_r_x[0];
	  double yfp = T->bb_tr_r_y[0];
	  double xpfp = T->bb_tr_r_th[0];
	  double ypfp = T->bb_tr_r_ph[0];
	  
	  etof = etof0;
	  for( int ipar=0; ipar<cetof.size(); ipar++ ){
	    double term =
	      pow(xfp,etof_expon[ipar][0])*
	      pow(yfp,etof_expon[ipar][1])*
	      pow(xpfp,etof_expon[ipar][2])*
	      pow(ypfp,etof_expon[ipar][3]);
	    
	    etof += cetof[ipar]*term; //neglecting xtar dependence
	    
	  }

	  etof -= etof0;
	  
	}
	
	double yhodo = T->bb_tr_y[0]+zhodo*T->bb_tr_ph[0];
	double xhodo = T->bb_tr_x[0]+zhodo*T->bb_tr_th[0];
	
	double dLEFT = std::min(Lbar_hodo,std::max(0.0,Lbar_hodo/2.0 - yhodo));
	double dRIGHT = std::min(Lbar_hodo,std::max(0.0,Lbar_hodo/2.0 + yhodo));

	double tmean0 = 0.0;
	
	for( int ibar=0; ibar<T->bb_hodotdc_clus_size[0]; ibar++ ){
	  //double tHODO = T->bb_hodotdc_clus_bar_tdc_meantime[ibar];
	  double tleft = T->bb_hodotdc_clus_bar_tdc_tleft[ibar];
	  double tright = T->bb_hodotdc_clus_bar_tdc_tright[ibar];
	  double totleft = T->bb_hodotdc_clus_bar_tdc_totleft[ibar];
	  double totright = T->bb_hodotdc_clus_bar_tdc_totright[ibar];
	  
	  double IDHODO = T->bb_hodotdc_clus_bar_tdc_id[ibar];
	  
	  double tleft_corr = tleft - etof + wL_OLD[IDHODO]*totleft - MeanTimeOffsets[IDHODO] - dLEFT/VSCINT_OLD[IDHODO]+tref;
	  double tright_corr = tright - etof + wR_OLD[IDHODO]*totright - MeanTimeOffsets[IDHODO] - dRIGHT/VSCINT_OLD[IDHODO]+tref;
	  
	  double tHODO = 0.5*(tleft_corr + tright_corr);

	  double tdiff = tleft_corr - tright_corr;
	  double ypos = -0.5*VSCINT_OLD[IDHODO]*tdiff; 
	  double xpos = T->bb_hodotdc_clus_bar_tdc_vpos[ibar];
	  
	  if( ibar == 0 ){
	    tmean0 = tHODO;
	  }
	  
	  bool goodhit = totleft >= totmin && totleft <= totmax &&
	    totright >= totmin && totright <= totmax &&
	    fabs( totleft - totright ) <= totdiff_max &&
	    fabs( ypos - yhodo ) <= ydiff_max &&
	    fabs( xpos - xhodo ) <= xdiff_max &&
	    fabs( tHODO - tmean0 ) <= tdiff_max;

	  if( goodhit ){
	    double RFcorr = RFtime + vz/0.299792458 - bunch_spacing_ns * (floor( (RFtime + vz/0.299792458)/bunch_spacing_ns));
	    double dtRF = tHODO - RFcorr;
	    //dtRF -= bunch_spacing_ns * ( floor( dtRF/bunch_spacing_ns ) + 0.5 );
	   
	    hdT_hodo_ID->Fill( IDHODO, dtRF );
	    //hdT_hodo_ID->Fill( IDHODO, dtRF - bunch_spacing_ns );
	    //hdT_hodo_ID->Fill( IDHODO, dtRF + bunch_spacing_ns );
	    //let's also fill diagnostic histo for bar to bar time differences:
	    for( int jbar=ibar+1; jbar<T->bb_hodotdc_clus_size[0]; jbar++ ){
	      double tleft_j = T->bb_hodotdc_clus_bar_tdc_tleft[jbar];
	      double tright_j = T->bb_hodotdc_clus_bar_tdc_tright[jbar];
	      double totleft_j = T->bb_hodotdc_clus_bar_tdc_totleft[jbar];
	      double totright_j = T->bb_hodotdc_clus_bar_tdc_totright[jbar];
	      
	      double IDHODO_j = T->bb_hodotdc_clus_bar_tdc_id[jbar];

	      double tleft_corr_j = tleft_j - etof + wL_OLD[IDHODO_j]*totleft_j - MeanTimeOffsets[IDHODO_j] - dLEFT/VSCINT_OLD[IDHODO_j]+tref;
	      double tright_corr_j = tright_j - etof + wR_OLD[IDHODO_j]*totright_j - MeanTimeOffsets[IDHODO_j] - dRIGHT/VSCINT_OLD[IDHODO_j]+tref;
	      double tHODO_j = 0.5*(tleft_corr_j + tright_corr_j);
	      double tdiff_j = tleft_corr_j - tright_corr_j;
	      double ypos_j = -0.5*VSCINT_OLD[IDHODO_j]*tdiff_j;
	      double xpos_j = T->bb_hodotdc_clus_bar_tdc_vpos[jbar];

	      bool goodhit_j = totleft_j >= totmin && totleft_j <= totmax &&
		totright_j >= totmin && totright_j <= totmax &&
		fabs(totleft_j - totright_j) <= totdiff_max &&
		fabs(ypos_j - yhodo) <= ydiff_max &&
		fabs(xpos_j - xhodo) <= xdiff_max &&
		fabs(tHODO_j - tmean0 ) <= tdiff_max;

	      if( goodhit_j ){
		hdTij_aligned_vs_IDi->Fill( IDHODO, tHODO_j - tHODO );
	      }
	      
	    }
	  }
	}	
      }
    }
    nevent++;
  }
    
  TCanvas *c1 = new TCanvas("c1","c1",1200,900);
  TCanvas *c2 = new TCanvas("c2","c2",1200,900);

  //if( !fixhodoparams ){
  c1->cd();
  hdT_hodo_ID->Draw("colz");

  TString histname;
  TClonesArray *dthodo_by_bar = new TClonesArray( "TH1D", 90 );
  
  for( int i=0; i<90; i++ ){
    TH1D *htemp = hdT_hodo_ID->ProjectionY( histname.Format( "hdThodo_bar%d", i ), i+1, i+1 );
    new( (*dthodo_by_bar)[i] ) TH1D(*htemp);
  }

  c2->cd();
  
  TH1D *href = ( (TH1D*) dthodo_by_bar->At(hodorefID) );

  href->Draw();

  TSpectrum refspec;
  int npeaksref = refspec.Search( href );

  double *peakpos = refspec.GetPositionX();

  double *peakheight = refspec.GetPositionY();
  
  int ipeak_best = -1;
  double mindiff = 1000.0;
  double maxheight = 0.0;
  double xpeak_best = 0.0;
  for( int ipeak=0; ipeak<npeaksref; ipeak++ ){
    double pos = peakpos[ipeak];
    //  if( ipeak_best < 0 || fabs( pos )<mindiff ){
    if( ipeak_best < 0 || peakheight[ipeak] > maxheight ){
      ipeak_best = ipeak;
      maxheight = peakheight[ipeak];
      xpeak_best = pos;
    }
  }

  

  href->Fit( "gaus", "SQ","", xpeak_best-1.0, xpeak_best+1.0);

  gPad->Modified();
  c2->Update();
  gSystem->ProcessEvents();

  TF1 *fitfunc = ( (TF1*) (href->GetListOfFunctions()->FindObject("gaus")) );

  RFoffsets[hodorefID] = fitfunc->GetParameter("Mean");
  dRFoffsets[hodorefID] = fitfunc->GetParError(fitfunc->GetParNumber("Mean"));

  double xtest = RFoffsets[hodorefID];

  for( int bar=hodorefID+1; bar<90; bar++ ){
    TH1D *htemp = ( (TH1D*) dthodo_by_bar->At(bar) );
    htemp->Draw();
    
    if( htemp->GetEntries() >= 100.0 ){
      
      gPad->Modified();
      c2->Update();
      gSystem->ProcessEvents();
      
      //double xtest = toffset_by_bar[bar-1];
      
      TSpectrum spectemp;
      int npeakstemp = spectemp.Search( htemp );
      double *xpeakstemp = spectemp.GetPositionX();
      ipeak_best = -1;
      mindiff = 1000.0;
      
      for( int ipeak=0; ipeak<npeakstemp; ipeak++ ){
	//int bin = 1 + int(peakpos[ipeak]+0.5);
	//double pos = htemp->GetBinCenter(bin);
	double pos = xpeakstemp[ipeak];
	if( ipeak_best < 0 || fabs( pos - xtest ) < mindiff ){
	  ipeak_best = ipeak;
	  mindiff = fabs( pos - xtest );
	  xpeak_best = pos;
	}
      }
      
      htemp->Fit("gaus","SQ","",xpeak_best-1.0,xpeak_best+1.0);
      gPad->Modified();
      c2->Update();
      gSystem->ProcessEvents();
      
      fitfunc = ( (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus")) );

      RFoffsets[bar] = fitfunc->GetParameter("Mean");
      dRFoffsets[bar] = fitfunc->GetParError(fitfunc->GetParNumber("Mean"));
      
      xtest = RFoffsets[bar];
    } else {
      RFoffsets[bar] = xtest;
    }
  }

  xtest = RFoffsets[hodorefID];
  
  for( int bar=hodorefID-1; bar>=0; bar-- ){
    TH1D *htemp = ( (TH1D*) dthodo_by_bar->At(bar) );
    htemp->Draw();
    
    if( htemp->GetEntries() >= 100.0 ){
      
      gPad->Modified();
      c2->Update();
      gSystem->ProcessEvents();
      
      //double xtest = toffset_by_bar[bar-1];
      
      TSpectrum spectemp;
      int npeakstemp = spectemp.Search( htemp );
      double *xpeakstemp = spectemp.GetPositionX();
      ipeak_best = -1;
      mindiff = 1000.0;
      
      for( int ipeak=0; ipeak<npeakstemp; ipeak++ ){
	//int bin = 1 + int(peakpos[ipeak]+0.5);
	//double pos = htemp->GetBinCenter(bin);
	double pos = xpeakstemp[ipeak];
	if( ipeak_best < 0 || fabs( pos - xtest ) < mindiff ){
	  ipeak_best = ipeak;
	  mindiff = fabs( pos - xtest );
	  xpeak_best = pos;
	}
      }
      
      htemp->Fit("gaus","SQ","",xpeak_best-1.0,xpeak_best+1.0);
      gPad->Modified();
      c2->Update();
      gSystem->ProcessEvents();
      
      fitfunc = ( (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus")) );

      RFoffsets[bar] = fitfunc->GetParameter("Mean");
      dRFoffsets[bar] = fitfunc->GetParError(fitfunc->GetParNumber("Mean"));
      
      xtest = RFoffsets[bar];
    } else {
      RFoffsets[bar] = xtest;
      //      RFoffsets[bar] = RFoffsets[hodorefID];
    }
  }

  //Now the RF offsets should be all up to date. But let's make the graph and write the database file:
  vector<double> gID(90), dgID(90,0.0);
  for( int i=0; i<90; i++ ){
    gID[i] = i;
  }

  TGraphErrors *gRFoffsets = new TGraphErrors( 90, &(gID[0]), &(RFoffsets[0]), &(dgID[0]), &(dRFoffsets[0]) );
  gRFoffsets->SetMarkerStyle(20);
  gRFoffsets->SetMarkerColor(1);
  gRFoffsets->SetLineColor(1);
  c1->cd();
  gRFoffsets->Draw("PSAME");

  gPad->Modified();
  c1->Update();
  gSystem->ProcessEvents();
  
  TString pdffilename = outputfilename;
  pdffilename.ReplaceAll(".root",".pdf");

  TString tempname = pdffilename;
  tempname += "(";

  fout->cd();

  gRFoffsets->Write("gRFoffsets");
  
  c1->Print(tempname.Data());
  
  treenum = -1;
  oldtreenum = -1;

  nevent = 0;
  cout << "Loop 3: Fit hodoscope walk correction slope, propagation delay, and t0 offset, and set up internal alignment of BBCAL and HCAL FADC times and GRINCH TDC time" << endl;

  int nchan_BBCAL = 189+52;
  
  
  //In loop three we'll set up and do internal alignments of SH, PS, and HCAL FADC time:
  vector<double> nhit_chan_BBCAL(nchan_BBCAL,0.0);
  vector<double> nhit_chan_HCAL(nchan_HCAL,0.0);
  TVectorD bint_BBCAL( nchan_BBCAL );
  TVectorD bint_HCAL( nchan_HCAL );
  TMatrixD Mint_BBCAL( nchan_BBCAL, nchan_BBCAL );
  TMatrixD Mint_HCAL( nchan_HCAL, nchan_HCAL );

  vector<double> nhit_chan_GRINCH(nchan_GRINCH, 0.0 );
  TVectorD bint_GRINCH( nchan_GRINCH );
  TMatrixD Mint_GRINCH( nchan_GRINCH, nchan_GRINCH );

  for( int i=0; i<nchan_GRINCH; i++ ){
    for( int j=0; j<nchan_GRINCH; j++ ){
      Mint_GRINCH(i,j) = 0.0;
    }
    bint_GRINCH(i) = 0.0;
  }
  
  for( int i=0; i<nchan_BBCAL; i++ ){
    for( int j=0; j<nchan_BBCAL; j++ ){
      Mint_BBCAL(i,j) = 0.0;
    }
    bint_BBCAL(i) = 0.0;
  }

  for( int i=0; i<nchan_HCAL; i++ ){
    for( int j=0; j<nchan_HCAL; j++ ){
      Mint_HCAL(i,j) = 0.0;
    }
    bint_HCAL(i) = 0.0;
  }
    
  
  while( T->GetEntry(nevent) ){

    if( nevent % 10000 == 0 ){
      cout << "Loop 3: nevent = " << nevent << ", run number = " << T->g_runnum << endl;
    }
    
    treenum = C->GetTreeNumber();
    if( nevent == 0 || treenum != oldtreenum ){
      oldtreenum = treenum;
      GlobalCut->UpdateFormulaLeaves();
    }

    bool passed_global_cut = GlobalCut->EvalInstance(0) != 0;

    if( passed_global_cut ){ //do the things:

      double tref = T->bb_hodotdc_trigtime - T->bb_hodotdc_trigphasecorr - BBtrig_t0;
      
      //Grab reference time and RF time for calibration:
      bool goodRF = false, goodTRIG = false;

      //We'll use bb.tdctrig branches for now; later we'll use the new convenience variables:
      double RFtime = T->bb_hodotdc_rftime + tref;
      double TrigTime = T->bb_hodotdc_trigtime - T->bb_hodotdc_trigphasecorr - BBtrig_t0;

      if( fabs( RFtime ) < 1.e5 ) goodRF = true;
      if( fabs( TrigTime ) < 1.e5 ) goodTRIG = true;
      // for( int ihit=0; ihit<T->; ihit++ ){
      // if( fabs( T->bb_tdctrig_rftime <= 1.e5 ) ){ // RF Time:
      // 	goodRF = true;
      // 	RFtime = T->bb_tdctrig_rftime;
      // }
	
      // 	//if( T->bb_tdctrig_tdcelemID[ihit] == 5 ){ //Trigger/reference time:
      // if( fabs( T->bb_tdctrig_trigtime <= 1.e5 ) ){
      // 	goodTRIG = true;
      // 	TrigTime = T->bb_tdctrig_trigtime;
      // }
      
      //grab needed track parameters:
      double vz = T->bb_tr_vz[0];
      double pathl = T->bb_tr_pathl[0];
      double etof = pathl/0.299792458 - etof0; //electron TOF from vertex to hodo.
      
      if( do_etof_calc ){
	double xfp = T->bb_tr_r_x[0];
	double yfp = T->bb_tr_r_y[0];
	double xpfp = T->bb_tr_r_th[0];
	double ypfp = T->bb_tr_r_ph[0];
	
	etof = etof0;
	for( int ipar=0; ipar<cetof.size(); ipar++ ){
	  double term =
	    pow(xfp,etof_expon[ipar][0])*
	    pow(yfp,etof_expon[ipar][1])*
	    pow(xpfp,etof_expon[ipar][2])*
	    pow(ypfp,etof_expon[ipar][3]);
	  
	  etof += cetof[ipar]*term; //neglecting xtar dependence
	  
	}

	etof -= etof0;
	
      }
      
      //These are "raw" leading-edge times and TOT values for the max bar in the

      if( T->bb_hodotdc_clus_trackindex[0]==0 && goodRF && goodTRIG){

	//double Tstart = fmod( RFtime - TrigTime, bunch_spacing_ns );


	//Tstart = 0.0;
	//double Tstart = RFtime - TrigTime - bunch_spacing_ns * floor( (RFtime-TrigTime)/bunch_spacing_ns );
	
	// cout << "(Rftime,TrigTime,Tstart,bunch_spacing_ns) = (" << RFtime << ", "
	//      << TrigTime << ", " << Tstart << ", " << bunch_spacing_ns << ") ns" << endl;
	
	double yhodo = T->bb_tr_y[0]+zhodo*T->bb_tr_ph[0];
	double xhodo = T->bb_tr_x[0]+zhodo*T->bb_tr_th[0];

	double dLEFT = std::min(Lbar_hodo,std::max(0.0,Lbar_hodo/2.0 - yhodo));
	double dRIGHT = std::min(Lbar_hodo,std::max(0.0,Lbar_hodo/2.0 + yhodo));

	double RFcorr = RFtime + vz/0.299792458 - bunch_spacing_ns * (floor( (RFtime + vz/0.299792458)/bunch_spacing_ns));
	//	RFcorr -= bunch_spacing_ns * (floor(RFcorr/bunch_spacing_ns)+0.5);

	double tmean0 = 0.0;
	
	for( int ibar=0; ibar<int(T->bb_hodotdc_clus_size[0]); ibar++ ){
	    
	  // Now that we have a prescription for aligning all the RF-corrected
	  // hodo mean times into a common "bucket", the thing we want to minimize
	  // is to find the meantime offsets that align the following quantity at zero:
	  
	  
	  //tleft and tright are raw leading-edge times (ref time and TDC offset subtracted)
	  double tleft = T->bb_hodotdc_clus_bar_tdc_tleft[ibar];
	  double tright = T->bb_hodotdc_clus_bar_tdc_tright[ibar];
	  double totleft = T->bb_hodotdc_clus_bar_tdc_totleft[ibar];
	  double totright = T->bb_hodotdc_clus_bar_tdc_totright[ibar];
	  
	  //Some additional variables for hit quality checks:
	  //double tmean = T->bb_hodotdc_clus_bar_tdc_meantime[ibar];
	  
	  double ypos = T->bb_hodotdc_clus_bar_tdc_timehitpos[ibar];
	  double xpos = T->bb_hodotdc_clus_bar_tdc_vpos[ibar];
	  
	  
	  int ID = int(T->bb_hodotdc_clus_bar_tdc_id[ibar]);

	  //	  RFcorr += RFoffsets[ID];
	  
	  double tleft_corr = tleft - etof + wL_OLD[ID]*totleft - MeanTimeOffsets[ID] - dLEFT/VSCINT_OLD[ID] + tref -RFoffsets[ID];
	  double tright_corr = tright - etof + wR_OLD[ID]*totright - MeanTimeOffsets[ID] - dRIGHT/VSCINT_OLD[ID] + tref -RFoffsets[ID];
	  

	  double tdiff_corr = tleft_corr - tright_corr;
	  ypos = -0.5*VSCINT_OLD[ID]*tdiff_corr;
	  double tmean = 0.5*(tleft_corr + tright_corr);
	  
	  if( ibar == 0 ) {
	    tmean0 = tmean;
	  }
	  
	  //RFcorr = RFtime + vz/0.299792458 + RFoffsets[ID];
	  //RFcorr += RFoffsets[ID];
	  
	  bool goodhit = totleft >= totmin && totleft <= totmax &&
	    totright >= totmin && totright <= totmax &&
	    fabs( totleft - totright ) <= totdiff_max &&
	    fabs( ypos - yhodo ) <= ydiff_max &&
	    fabs( xpos - xhodo ) <= xdiff_max &&
	    fabs( tmean - tmean0 ) <= tdiff_max;

	  if( goodhit ){
	    nevent_vs_bar[ID] += 1.;
	  
	    // how to define our chi2 statistic? We want to correct all hodo PMT times to tvertex = 0:
	    // How will the algebra change if we want to align the hodoscope mean times to the RF signal instead of the BigBite trigger signal?
	    // Basically we want to add back in the reference time to get the "raw" times of the PMTs, and then subtract the RF time modulo bunch spacing (or some
	    // integer multiple thereof:
	    // Corrected raw PMT time is Tcorr = tPMT + ref time - RF time
	    // 
	    // tPMT = etof + t0 - walk * TOT + d/vscint
	    // chi2 = sum_{i=1}^N \sum_{j=1}^Nhit (tPMT-etof-t0+walk*TOT - d/vscint)^2
	    // dchi2/dt0_k = 2*\sum_i,j (tPMT-etof-t0+walk*TOT-d/vscint)*-1
	    // dchi2/dwalk_k = 2*sum_i,j (tPMT-etof-t0+walk*TOT-d/vscint)*TOT
	    // dchi2/d(1/v)_k = 2*sum_i,j (tPMT-etof-t0+walk*TOT-d/vscint)*-d
	
	  
	
	    // cout << "Best hodo hit (tL,tR, totL, totR, yhodo, dL, dR, pathl, etof)=("
	    // 	   << tleft << ", " << tright << ", " << totleft << ", " << totright << ", " << yhodo << ", "
	    // 	   << dLEFT << ", " << dRIGHT << ", " << pathl << ", " << etof << ")" << endl;
	
	    // we want to minimize
	    // chi2 = sum_{i=1}^Nevent (tleft_corr^2 + tright_corr^2)
	    // dchi2/dt0_j = sum_i (2*tleft_corr_i*dtleft_corr_i/dt0_j + 2*tright_corr_i*dtright_corr_i/dt0_j) = 0
	    //we COULD just use TMinuit but that's lazy.
	    //let parameters 0-89 be the t0L, 90-179 be t0R, 180-269 be wL, 270-359 be wR, and 360-449 be 1/vscint:
	    int ipar_t0 = ID;
	    int ipar_vinv = ID+90;
	    //int ipar_t0R = ID+90;
	    int ipar_wL = ID+180;
	    int ipar_wR = ID+270;

	    // double coeff_t0L = 
	
	    //sum_i (tL - etof - t0 + w*TOTL - dL/v) = Tstart  
	    // tL-etof = t0L -w*TOTL + dL/v

	    // tL = TRFcorr + etof + RFoffset + t0 - w*TOT - D/v

	    //Correct for TOF:
	    
	    //	    double tleft_corr = tleft - (etof-etof0) + wL_OLD[ID]*totleft - dLEFT/VSCINT_OLD[ID] - MeanTimeOffsets[ID] - RFcorr;
	    //Correct everything to a common beam bucket:
	    //This is the thing we want to align to zero!
	    //tleft_corr -= bunch_spacing_ns * (floor( tleft_corr/bunch_spacing_ns ) + 0.5);
	    //double tright_corr = tright - (etof-etof0) + wR_OLD[ID]*totright - dRIGHT/VSCINT_OLD[ID] - MeanTimeOffsets[ID] - RFcorr;

	    //tmean_corr = 0.5*(tleft_corr+tright_corr);

	    //tleft_corr -= RFcorr;
	    //tright_corr -= RFcorr; 

	    
	    
	    double tmean_corr = 0.5*(tleft_corr+tright_corr) - RFcorr; // includes RF offset;

	    //tmean_corr -= bunch_spacing_ns * floor( tmean_corr/bunch_spacing_ns + 0.5 );
	    
	    htmeancorr_vs_ID_old->Fill( ID, tmean_corr );

	    tleft_corr -= RFcorr;
	    tright_corr -= RFcorr;
	    
	    //At this point, if all is handled correctly, RFcorr should center hodo mean time at 0 +/- n * bunchspace;
	    // so the correction we want to apply here is what?
  
	    // tmean_corr, floor( tmean_corr/bunchspace + 0.5 ), desired correction, actual correction =
	    // -8 ns, -2, +8, +8 CORRECT
	    
	    double RF_bucket = floor( tmean_corr/bunch_spacing_ns + 0.5 );
	      // This RF bucket subtraction will only work if all other offsets/corrections/etc are reasonably well-known to begin with!
	    tmean_corr -= bunch_spacing_ns * RF_bucket;
	    tleft_corr -= bunch_spacing_ns * RF_bucket;
	    tright_corr -= bunch_spacing_ns * RF_bucket;
	    
	    // tmean_corr -= bunch_spacing_ns * (RF_bucket + 0.5);
	    // tleft_corr -= bunch_spacing_ns * (RF_bucket + 0.5);
	    // tright_corr -= bunch_spacing_ns * (RF_bucket + 0.5);

	    // std::cout << "Corrected (tL,tR,tmean)=(" << tleft_corr << ", " << tright_corr << ", "
	    // 	      << tmean_corr << ")" << std::endl;
	    
	    // if( fixoffsets ){
	    //   tleft_corr -= MeanTimeOffsets[ID];
	    //   tright_corr -= MeanTimeOffsets[ID];
	    // }
	    //tright_corr -= bunch_spacing_ns * (floor(tright_corr/bunch_spacing_ns) + 0.5);
	    //Correcting L and R PMT times separately to a common "beam bucket" does not work; one needs to correct the mean time:
	    // if( useRFcorr ){
	    //   tleft_corr -= RFcorr + RFoffsets[ID];
	    //   tright_corr -= RFcorr + RFoffsets[ID];
	    // }
	    
	    //  if( useRFcorr ){
	    //Commenting this until we can get a fit to converge with RF corrections included and resolve the "bucket ambiguity"

	    //Now that we've aligned all corrected times to a common RF bucket, let's REMOVE the walk and propagation delay corrections
	    // (but not the t0 offset). But we retain the TOF correction and the (old) mean time and RF offset:
	    double tleft_raw = tleft_corr - wL_OLD[ID]*totleft + dLEFT/VSCINT_OLD[ID];
	    double tright_raw = tright_corr - wR_OLD[ID]*totright + dRIGHT/VSCINT_OLD[ID];
	  
	    //there is a more elegant way to do this:
	    //Left PMT:
	    Mhodo(ipar_t0,ipar_t0) += 1.0;
	    Mhodo(ipar_t0,ipar_wL) += -totleft;
	    Mhodo(ipar_t0,ipar_vinv) += dLEFT;
	
	    Mhodo(ipar_wL, ipar_t0) += -totleft;
	    Mhodo(ipar_wL, ipar_wL) += pow(totleft,2);
	    Mhodo(ipar_wL, ipar_vinv) += -totleft*dLEFT;
	
	    Mhodo(ipar_vinv, ipar_t0) += dLEFT;
	    Mhodo(ipar_vinv, ipar_wL) += -totleft*dLEFT;
	    Mhodo(ipar_vinv, ipar_vinv) += pow(dLEFT,2);
	
	    bhodo(ipar_t0) += (tleft_raw)*1.0;
	    bhodo(ipar_wL) += (tleft_raw)*(-totleft);
	    bhodo(ipar_vinv) += (tleft_raw)*dLEFT;
	
	
	    //Right PMT:
	    Mhodo(ipar_t0,ipar_t0) += 1.0;
	    Mhodo(ipar_t0,ipar_wR) += -totright;
	    Mhodo(ipar_t0,ipar_vinv) += dRIGHT;
	
	    Mhodo(ipar_wR, ipar_t0) += -totright;
	    Mhodo(ipar_wR, ipar_wR) += pow(totright,2);
	    Mhodo(ipar_wR, ipar_vinv) += -totright*dRIGHT;
	    
	    Mhodo(ipar_vinv, ipar_t0) += dRIGHT;
	    Mhodo(ipar_vinv, ipar_wR) += -totright*dRIGHT;
	    Mhodo(ipar_vinv, ipar_vinv) += pow(dRIGHT,2);
	    
	    bhodo(ipar_t0) += (tright_raw)*1.0;
	    bhodo(ipar_wR) += (tright_raw)*(-totright);
	    bhodo(ipar_vinv) += (tright_raw)*dRIGHT;
	  }
	}
      }

      //Some of the time cuts here should probably NOT be hard-coded;
      //It assumes the initial alignment is already reasonable.
      
      //Make temporary arrays to hold relevant sh and ps info:
      vector<double> bbcal_idtemp, bbcal_etemp, bbcal_atimetemp;

      int nblkSH = std::min(MAXNBLK_BBSH,int(T->bb_sh_nblk));
      int nblkPS = std::min(MAXNBLK_BBPS,int(T->bb_ps_nblk));
      int nblkHCAL = std::min(MAXNBLK_HCAL,int(T->sbs_hcal_nblk));

      int nhitGRINCH = std::min(MAXNHIT_GRINCH, int(T->bb_grinch_tdc_ngoodhits) );
      
      // cout << "event " << nevent << ", (nblkSH, nblkPS, nblkHCAL)=("
      // 	   << nblkSH << ", " << nblkPS << ", " << nblkHCAL << ")" << endl;

      if( T->bb_grinch_tdc_clus_size > 2 && T->bb_grinch_tdc_clus_trackindex==0 ){ //increment
	// GRINCH internal alignment matrices:
      
	for( int ihit=0; ihit<nhitGRINCH; ihit++ ){
	  
	  
	  //We don't need the trigger phase correction for the INTERNAL alignment of GRINCH:
	  double thit_i = T->bb_grinch_tdc_hit_time[ihit];

	  int pmt_i = int(T->bb_grinch_tdc_hit_pmtnum[ihit]);
	  
	  bool goodhit_i =  T->bb_grinch_tdc_hit_trackindex[ihit] == 0 && T->bb_grinch_tdc_hit_clustindex[ihit] == T->bb_grinch_tdc_bestcluster && fabs( thit_i - T->bb_grinch_tdc_clus_t_mean ) <= GRINCH_tdiff_max;
	  
	  for( int jhit=ihit+1; jhit<nhitGRINCH; jhit++ ){
	    double thit_j = T->bb_grinch_tdc_hit_time[jhit];
	    bool goodhit_j = T->bb_grinch_tdc_hit_trackindex[jhit] == 0 && T->bb_grinch_tdc_hit_clustindex[jhit] == T->bb_grinch_tdc_bestcluster && fabs( thit_j - T->bb_grinch_tdc_clus_t_mean ) <= GRINCH_tdiff_max;

	    int pmt_j = int(T->bb_grinch_tdc_hit_pmtnum[jhit]);
	    
	    if( goodhit_i && goodhit_j ){
	      nhit_chan_GRINCH[pmt_i] += 1.0;
	      nhit_chan_GRINCH[pmt_j] += 1.0;
	      Mint_GRINCH( pmt_i, pmt_i ) += 1.0;
	      Mint_GRINCH( pmt_i, pmt_j ) += -1.0;
	      Mint_GRINCH( pmt_j, pmt_i ) += -1.0;
	      Mint_GRINCH( pmt_j, pmt_j ) += 1.0;
	      bint_GRINCH( pmt_i ) += thit_i - thit_j;
	      bint_GRINCH( pmt_j ) += thit_j - thit_i;
	    }
	    
	  }
	}
      }
	
      for( int ihit=0; ihit<nblkSH; ihit++ ){
	double ehit = T->bb_sh_clus_blk_e[ihit];
	double atimehit = T->bb_sh_clus_blk_atime[ihit];
	//Only use hits above threshold in both GeV and fraction of seed energy:
	if( ehit >= 0.1 && ehit/T->bb_sh_eblk >= 0.05 &&
	    fabs( atimehit - T->bb_sh_atimeblk ) <= dtcut_SH ){
	  bbcal_idtemp.push_back( int( T->bb_sh_clus_blk_id[ihit] ) );
	  bbcal_etemp.push_back( T->bb_sh_clus_blk_e[ihit] );
	  bbcal_atimetemp.push_back( T->bb_sh_clus_blk_atime[ihit] );
	}
      }
      for( int ihit=0; ihit<nblkPS; ihit++ ){
	double ehit = T->bb_ps_clus_blk_e[ihit];
	double atimehit = T->bb_ps_clus_blk_atime[ihit];
	if( ehit >= 0.05 && ehit/T->bb_ps_eblk >= 0.1 &&
	    fabs( atimehit - T->bb_ps_atimeblk ) <= dtcut_PS ){
	  bbcal_idtemp.push_back( int(T->bb_ps_clus_blk_id[ihit]) + 189 );
	  bbcal_etemp.push_back( T->bb_ps_clus_blk_e[ihit] );
	  bbcal_atimetemp.push_back( T->bb_ps_clus_blk_atime[ihit] );
	}
      }

      //Now increment internal alignment matrices for BBCAL:
      
      for( int ihit=0; ihit<bbcal_idtemp.size(); ihit++ ){
	for( int jhit=ihit+1; jhit<bbcal_idtemp.size(); jhit++ ){
	  nhit_chan_BBCAL[bbcal_idtemp[ihit]] += 1.0;
	  nhit_chan_BBCAL[bbcal_idtemp[jhit]] += 1.0;

	  Mint_BBCAL(bbcal_idtemp[ihit],bbcal_idtemp[ihit]) += 1.0;
	  Mint_BBCAL(bbcal_idtemp[ihit],bbcal_idtemp[jhit]) += -1.0;
	  Mint_BBCAL(bbcal_idtemp[jhit],bbcal_idtemp[ihit]) += -1.0;
	  Mint_BBCAL(bbcal_idtemp[jhit],bbcal_idtemp[jhit]) += 1.0;
	  bint_BBCAL(bbcal_idtemp[ihit]) += bbcal_atimetemp[ihit]-bbcal_atimetemp[jhit];
	  bint_BBCAL(bbcal_idtemp[jhit]) += bbcal_atimetemp[jhit]-bbcal_atimetemp[ihit];
	}
      }

      for( int ihit=0; ihit<nblkHCAL; ihit++ ){
	int id_i = int( T->sbs_hcal_clus_blk_id[ihit] )-1;
	double e_i = T->sbs_hcal_clus_blk_e[ihit];
	double t_i = T->sbs_hcal_clus_blk_atime[ihit];
	for( int jhit=ihit+1; jhit<nblkHCAL; jhit++ ){
	  int id_j = int( T->sbs_hcal_clus_blk_id[jhit] )-1;
	  double e_j = T->sbs_hcal_clus_blk_e[jhit];
	  double t_j = T->sbs_hcal_clus_blk_atime[jhit];

	  if( e_i >= 0.025 && e_i > 0.1 * T->sbs_hcal_eblk && T->sbs_hcal_e >= 0.05 &&
	      fabs( t_i - T->sbs_hcal_atimeblk ) <= dtcut_HCAL &&
	      e_j >= 0.025 && e_j > 0.1 * T->sbs_hcal_eblk && T->sbs_hcal_e >= 0.05 &&
	      fabs( t_j - T->sbs_hcal_atimeblk ) <= dtcut_HCAL ){
	    nhit_chan_HCAL[id_i] += 1.0;
	    nhit_chan_HCAL[id_j] += 1.0;
	    
	    Mint_HCAL(id_i, id_i) += 1.0;
	    Mint_HCAL(id_i, id_j) += -1.0;
	    Mint_HCAL(id_j, id_i) += -1.0;
	    Mint_HCAL(id_j, id_j) += 1.0;
	    bint_HCAL(id_i) += t_i - t_j;
	    bint_HCAL(id_j) += t_j - t_i;
	  }
	  
	}
      }
    }
    nevent++;
  }

  //Before we fit, we want to fix all parameters for paddles with less than, say, 50 events (we'll replace the offset with zero and
  // the vscint and walk correction slopes with the average of all the other paddles):
  for( int i=0; i<90; i++ ){
    if( nevent_vs_bar[i] < double(mineventsperbar) ){
      int ipar_t0 = i;
      int ipar_vinv = i+90;
      int ipar_wL = i+180;
      int ipar_wR = i+270;

      Mhodo(ipar_t0, ipar_t0) = 1.;
      Mhodo(ipar_vinv, ipar_vinv) = 1.;
      Mhodo(ipar_wL, ipar_wL) = 1.;
      Mhodo(ipar_wR, ipar_wR) = 1.;
      for( int j=0; j<nparams_hodo; j++ ){
	if( j != ipar_t0 ) {
	  Mhodo(ipar_t0,j) = Mhodo(j,ipar_t0) = 0.0;
	}
	if( j != ipar_vinv ){
	  Mhodo(ipar_vinv, j) = Mhodo(j,ipar_vinv) = 0.0;
	}
	if( j != ipar_wL ){
	  Mhodo( ipar_wL, j ) = Mhodo(j,ipar_wL) = 0.0;
	}
	if( j != ipar_wR ){
	  Mhodo( ipar_wR, j ) = Mhodo(j,ipar_wL) = 0.0;
	}
      }
      bhodo( ipar_t0 ) = 0.0;
      bhodo( ipar_vinv ) = 0.0;
      bhodo( ipar_wL ) = 0.0;
      bhodo( ipar_wR ) = 0.0;
      
    }
  }
  
  TDecompSVD Ahodo(Mhodo);
  Ahodo.Solve(bhodo);

  bhodo.Print();

  double HODObarID[90];
  double HODOt0[90], HODOwL[90], HODOwR[90], vscint[90];

  for( int i=0; i<90; i++ ){
    HODObarID[i] = i;
    HODOt0[i] = bhodo[i];
    //HODOt0R[i] = bhodo[i+90];
    HODOwL[i] = bhodo[i+180];
    HODOwR[i] = bhodo[i+270];
    vscint[i] = 1.0/bhodo[i+90];
  }

  for( int chan=0; chan<nchan_BBCAL; chan++ ){
    if( nhit_chan_BBCAL[chan] < 100. ){
      bint_BBCAL(chan) = 0.0;
      Mint_BBCAL(chan,chan) = 1.0;
      for( int j=0; j<nchan_BBCAL; j++ ){
	if( j != chan ){
	  Mint_BBCAL(chan,j) = 0.0;
	  Mint_BBCAL(j,chan) = 0.0;
	}
      }
    }
  }
  
  TDecompSVD ABBCAL(Mint_BBCAL);
  ABBCAL.Solve(bint_BBCAL);

  corr = -bint_BBCAL(BBSHrefID);
  for( int i=0; i<nchan_BBCAL; i++ ){
    bint_BBCAL(i) += corr;
  }
  
  for( int chan=0; chan<nchan_HCAL; chan++ ){
    if( nhit_chan_HCAL[chan] < 100. ){
      bint_HCAL(chan) = 0.0;
      Mint_HCAL(chan,chan) = 1.0;
      for( int j=0; j<nchan_HCAL; j++ ){
	if( j != chan ){
	  Mint_HCAL(chan,j) = 0.0;
	  Mint_HCAL(j,chan) = 0.0;
	}
      }
    }
  }
  
  TDecompSVD AHCAL(Mint_HCAL);
  AHCAL.Solve(bint_HCAL);

  corr = -bint_HCAL(hcalrefID);
  for( int i=0; i<nchan_HCAL; i++ ){
    bint_HCAL(i) += corr;
  }
  
  vector<double> BBCAL_t0ADC(nchan_BBCAL,0.0);
  for( int i=0; i<nchan_BBCAL; i++ ){
    BBCAL_t0ADC[i] = bint_BBCAL(i);
  }
  vector<double> HCAL_t0ADC(nchan_HCAL,0.0);
  for( int i=0; i<nchan_HCAL; i++ ){
    HCAL_t0ADC[i] = bint_HCAL(i);
  }

  for( int i=0; i<nchan_GRINCH; i++ ){
    if( nhit_chan_GRINCH[i] < minhits_GRINCH_internal ){
      bint_GRINCH(i) = 0.0;
      Mint_GRINCH(i,i) = 1.0;
      for( int j=0; j<nchan_GRINCH; j++ ){
	if( j != i ){
	  Mint_GRINCH(j,i) = 0.0;
	  Mint_GRINCH(i,j) = 0.0;
	}
      }
    }
  }

  TDecompSVD AGRINCH(Mint_GRINCH);
  AGRINCH.Solve( bint_GRINCH );

  corr = -bint_GRINCH( GRINCHrefID );
  for( int i=0; i<nchan_GRINCH; i++ ){
    bint_GRINCH(i) += corr;
  }
  
  vector<double> GRINCH_t0(nchan_GRINCH,0.0);
  for(int i=0; i<nchan_GRINCH; i++ ){
    GRINCH_t0[i] = bint_GRINCH(i);
  }
  
  nevent = 0;

  treenum=-1,oldtreenum=-1;

  cout << "Loop 4, testing new hodoscope calibrations and setting up BBCAL/HCAL FADC --> hodo alignments" << endl;

  fout->cd();
  
  TH2D *htmean_vs_ID_old = new TH2D("htmean_vs_ID_old","OLD ;bar ID; bar t_{mean} (ns)", 90,-0.5,89.5, 300,-30,30);
  TH2D *htmean_vs_ID_new = new TH2D("htmean_vs_ID_new","NEW (with RF corrections);bar ID; bar t_{mean} (ns)", 90,-0.5,89.5, 300,-30,30);
  TH2D *htmean_vs_ID_new_noRFcorr = new TH2D("htmean_vs_ID_new_noRFcorr","NEW (no RF corrections);bar ID; bar t_{mean} (ns)",90,-0.5,89.5,300,-30,30);
  
  TH2D *htdiff_yhodo_old = new TH2D("htdiff_yhodo_old", "OLD; y_{hodo} (m); bar t_{L}-t_{R} (ns)", 150,-0.3,0.3,300,-15,15);
  TH2D *htdiff_yhodo_new = new TH2D("htdiff_yhodo_new", "NEW; y_{hodo} (m); bar t_{L}-t_{R} (ns)", 150,-0.3,0.3,300,-15,15);

  TH2D *htleft_corr_vs_ID_old = new TH2D("htleft_corr_vs_ID_old", "OLD; bar ID; t_{left}^{corr} (ns)",90,-0.5,89.5,300,-30,30);
  TH2D *htright_corr_vs_ID_old = new TH2D("htright_corr_vs_ID_old", "OLD; bar ID; t_{right}^{corr} (ns)",90,-0.5,89.5,300,-30,30);

  //Let's make some additional diagnostic plots on walk corrections (with all other corrections applied:
  TH2D *hwalkcorr_allpmts = new TH2D("hwalkcorr_allpmts", "All corrections except timewalk; Time-over-threshold (ns); T_{PMT}",200,0,60,300,-30,30);

  TClonesArray *hwalkcorr_by_PMT = new TClonesArray("TH2D",180);
  TClonesArray *htdiff_vs_y_by_bar = new TClonesArray("TH2D",90);
  
  for( int i=0; i<90; i++ ){
    TString histname;
    TString title;
    new( (*hwalkcorr_by_PMT)[i] ) TH2D(histname.Format("hwalkcorr_bar%d_left",i), title.Format("Bar %d Left: all corrections except timewalk; time-over-threshold (ns); corrected time (ns)",i), 200,0,60,300,-30,30);
    new( (*hwalkcorr_by_PMT)[i+90] ) TH2D(histname.Format("hwalkcorr_bar%d_right",i), title.Format("Bar %d Right: all corrections except timewalk; time-over-threshold (ns); corrected time (ns)",i), 200,0,60,300,-30,30);
    new( (*htdiff_vs_y_by_bar)[i] ) TH2D(histname.Format("htdiff_vs_y_bar%d",i), title.Format("Bar %d: all corrections except propagation delay; y_{hodo} (m); T_{L}-T_{R} (ns)",i), 150,-0.3,0.3,300,-15,15);
  }
  
  //We really want a large quantity of zero-field LH2 data for this purpose:
  TH2D *htdiffHCAL_vs_HCALID_new = new TH2D("htdiffHCAL_vs_HCALID_new", "NEW hodo, old HCAL; HCAL ID; t_{HCAL}-t_{HODO,corr} (ns)",289,-0.5,288.5,250,-25,25); 

  TH2D *htdiffHCAL_vs_eblk_all = new TH2D("htdiffHCAL_vs_eblk_all", "NEW hodo, old HCAL; energy deposit (GeV); #Deltat(ns)",250,0.0,1.0,250,-25,25);

  TH1D *hW2_xycut = new TH1D("hW2_xycut", "LH2 proton spot cut; W^{2} (GeV^{2});",250,-1,4);
  TH1D *hW2_xycut_p = new TH1D("hW2_xycut_p", "LD2 proton spot cut; W^{2} (GeV^{2});",250,-1,4);
  TH1D *hW2_xycut_n = new TH1D("hW2_xycut_n", "LD2 neutron spot cut; W^{2} (GeV^{2});",250,-1,4);
  
  TH2D *hdxdy = new TH2D("hdxdy",";#Deltay (m); #Deltax (m)",250,-1.25,1.25,250,-1.25,1.25);
  
  TH2D *hdxdy_p = new TH2D("hdxdy_p", "Proton hypothesis (4-vector); #Deltay (m); #Deltax (m)", 250,-2.5,2.5,500,-5,4);
  TH2D *hdxdy_n = new TH2D("hdxdy_n", "Neutron hypothesis (4-vector); #Deltay (m); #Deltax (m)", 250,-2.5,2.5,500,-3,2);

  TH2D *hdxdy_nodeflect_LH2 = new TH2D("hdxdy_nodeflect_LH2", "LH2 (no deflection correction); #Deltay (m); #Deltax (m)", 250,-2.5,2.5,250,-3,2);
  
  vector<double> nevent_blk_HCAL(288,0.0);
  vector<double> nevent_blk_BBSH(189,0.0);
  vector<double> nevent_blk_BBPS(52,0.0);

  //Let's make several sets of histograms which we will then fit to get e.g., offsets and (if applicable) walk corrections for HCAL and BBCAL FADC times 

  //We'll apply ALL corrections to hodoscope (including RF offset and TOF); then do a simple fit to align SH, PS, and HCAL FADC times to the hodoscope:
  TH2D *hdt_HCAL_hodo_vs_IDHCAL = new TH2D("hdt_HCAL_hodo_vs_IDHCAL","; HCAL block ID ; t_{HCAL}^{(FADC)}-t_{HODO} (ns)", 288,0.5,288.5,500,-50,50);
  TH2D *hdt_BBSH_hodo_vs_IDBBSH = new TH2D("hdt_BBSH_hodo_vs_IDBBSH","; BBSH block ID ; t_{BBSH}^{(FADC)}-t_{HODO} (ns)", 189,-0.5,188.5,500,-50,50);
  TH2D *hdt_BBPS_hodo_vs_IDBBPS = new TH2D("hdt_BBPS_hodo_vs_IDBBPS","; BBPS block ID ; T_{BBPS}^{(FADC)}-t_{HODO} (ns)", 52,-0.5,51.5,500,-50,50); 

  //Add GRINCH:
  TH2D *hdt_GRINCH_hodo_vs_IDGRINCH = new TH2D("hdt_GRINCH_hodo_vs_IDGRINCH", "; GRINCH PMT; t_{GRINCH}-t_{HODO} (ns)", 512, -0.5, 511.5, 200, -50, 50 );
  
  int bar3counter=0;
  
  while( T->GetEntry(nevent) ){

    if( nevent % 10000 == 0 ){
      cout << "Loop 4: nevent = " << nevent << ", run number = " << T->g_runnum << endl;
    }
    
    treenum = C->GetTreeNumber();
    if( nevent == 0 || treenum != oldtreenum ){
      oldtreenum = treenum;
      GlobalCut->UpdateFormulaLeaves();
    }

    bool passed_global_cut = GlobalCut->EvalInstance(0) != 0;

    if( passed_global_cut ){ //do the things:

      //Grab reference time and RF time for calibration:
      bool goodRF = false, goodTRIG = false;

      double tref = T->bb_hodotdc_trigtime - T->bb_hodotdc_trigphasecorr - BBtrig_t0;

      //We'll use bb.tdctrig branches for now; later we'll use the new convenience variables:
      double RFtime = T->bb_hodotdc_rftime + tref;
      double TrigTime = T->bb_hodotdc_trigtime - T->bb_hodotdc_trigphasecorr - BBtrig_t0;

      if( fabs( RFtime ) < 1.e5 ) goodRF = true;
      if( fabs( TrigTime ) < 1.e5 ) goodTRIG = true;

      double vz = T->bb_tr_vz[0];
      double pathl = T->bb_tr_pathl[0];
      double etof = pathl/0.299792458 - etof0;
      
      if( do_etof_calc ){
	double xfp = T->bb_tr_r_x[0];
	double yfp = T->bb_tr_r_y[0];
	double xpfp = T->bb_tr_r_th[0];
	double ypfp = T->bb_tr_r_ph[0];
	
	etof = etof0;
	for( int ipar=0; ipar<cetof.size(); ipar++ ){
	  double term =
	    pow(xfp,etof_expon[ipar][0])*
	    pow(yfp,etof_expon[ipar][1])*
	    pow(xpfp,etof_expon[ipar][2])*
	    pow(ypfp,etof_expon[ipar][3]);
	  
	  etof += cetof[ipar]*term; //neglecting xtar dependence
	  
	}

	etof -= etof0;
      }
      
      double yhodo = T->bb_tr_y[0]+zhodo*T->bb_tr_ph[0];
	  
      // how to define our chi2 statistic? We want to correct all hodo PMT times to tvertex = 0:
      // tPMT = etof + t0 - walk * TOT + d/vscint
      // chi2 = sum_{i=1}^N \sum_{j=1}^Nhit (tPMT-etof-t0+walk*TOT - d/vscint)^2
      // dchi2/dt0_k = 2*\sum_i,j (tPMT-etof-t0+walk*TOT-d/vscint)*-1
      // dchi2/dwalk_k = 2*sum_i,j (tPMT-etof-t0+walk*TOT-d/vscint)*TOT
      // dchi2/d(1/v)_k = 2*sum_i,j (tPMT-etof-t0+walk*TOT-d/vscint)*-d
      
      double dLEFT = std::min(Lbar_hodo,std::max(0.0,Lbar_hodo/2.0 - yhodo));
      double dRIGHT = std::min(Lbar_hodo,std::max(0.0,Lbar_hodo/2.0 + yhodo));

      double RFcorr = RFtime + vz/0.299792458 - bunch_spacing_ns * (floor( (RFtime + vz/0.299792458)/bunch_spacing_ns));

      double tmean0 = 0.0;
      
      if( T->bb_hodotdc_clus_trackindex[0]==0 && goodRF && goodTRIG ){

	//	double RFcorr = RFtime + vz/0.299792458;
	//RFcorr -= bunch_spacing_ns * (floor(RFcorr/bunch_spacing_ns)+0.5);
	
	//	double Tstart = fmod( RFtime - TrigTime, bunch_spacing_ns );

	double Tstart = 0.0;
	
	double HodoTmean = 0.0;
	double HodoTOTsum = 0.0;

	double Tmean_corr = -1000.0;
	
	for( int ibar=0; ibar<int(T->bb_hodotdc_clus_size[0]); ibar++ ){
	  double tleft = T->bb_hodotdc_clus_bar_tdc_tleft[ibar];
	  double tright = T->bb_hodotdc_clus_bar_tdc_tright[ibar];
	  double totleft = T->bb_hodotdc_clus_bar_tdc_totleft[ibar];
	  double totright = T->bb_hodotdc_clus_bar_tdc_totright[ibar];
	  
	  int ID = int(T->bb_hodotdc_clus_bar_tdc_id[ibar]);

	  // if( ID == 3 ){
	  //   bar3counter++;
	  //   std::cout << "(size, ibar, ID, int(ID), nhits)=(" << int(T->bb_hodotdc_clus_size[0]) << ", " << ibar << ", " << T->bb_hodotdc_clus_bar_tdc_id[ibar]
	  // 	      << ", " << ID << ", " << bar3counter << ")" << std::endl;
	  // }

	  //Apply all corrections EXCEPT RF:
	  // double tleft_CORR = tleft - (etof-etof0) - HODOt0[ID] + HODOwL[ID]*totleft - dLEFT/vscint[ID] - RFcorr - RFoffsets[ID] - MeanTimeOffsets[ID] + tref;
	  // double tright_CORR = tright - (etof-etof0) - HODOt0[ID] + HODOwR[ID]*totright - dRIGHT/vscint[ID] - RFcorr - RFoffsets[ID] - MeanTimeOffsets[ID] + tref;

	  //WITHOUT RF corrections:
	  double tleft_CORR = tleft - etof - HODOt0[ID] + HODOwL[ID]*totleft - dLEFT/vscint[ID] - MeanTimeOffsets[ID] + tref - RFoffsets[ID];
	  double tright_CORR = tright - etof - HODOt0[ID] + HODOwR[ID]*totright - dRIGHT/vscint[ID] - MeanTimeOffsets[ID] + tref - RFoffsets[ID];
	  
	  // if( fixoffsets ){
	  //   tleft_CORR -= MeanTimeOffsets[ID];
	  //   tright_CORR -= MeanTimeOffsets[ID];
	  // }

	  //	  RFcorr += RFoffsets[ID];

	  //Increment TOT-weighted cluster mean time (do NOT subtract RF correction here!)
	  double totmean = 0.5*(totleft + totright);

	  HodoTmean += totmean * 0.5 * (tleft_CORR + tright_CORR);
	  HodoTOTsum += totmean;
	  
	  double tmean_CORR = 0.5*(tleft_CORR+tright_CORR) - RFcorr;

	  tleft_CORR -= RFcorr;
	  tright_CORR -= RFcorr;

	  double RF_bucket = floor( tmean_CORR/bunch_spacing_ns + 0.5 );

	  tmean_CORR -= bunch_spacing_ns * RF_bucket;
	  tleft_CORR -= bunch_spacing_ns * RF_bucket;
	  tright_CORR -= bunch_spacing_ns * RF_bucket;
	  
	  //	  double tdiff_CORR = tleft_corr - tright_corr; 
	  
	  // double RF_bucket = floor( tmean_CORR/bunch_spacing_ns );

	  // tmean_CORR -= bunch_spacing_ns * (RF_bucket + 0.5);
	  // tleft_CORR -= bunch_spacing_ns * (RF_bucket + 0.5);
	  // tright_CORR -= bunch_spacing_ns * (RF_bucket + 0.5);
	  
	  // htmeancorr_vs_ID_old->Fill( ID, tmean_CORR + HODOt0[ID] );
	  
	  // double tmean_CORR_nowalk = 0.5*(tleft_CORR - HODOwL[ID]*totleft +
	  // 				  tright_CORR - HODOwR[ID]*totright);
	  
	  //tmean_CORR -= bunch_spacing_ns * (floor(tmean_CORR/bunch_spacing_ns)+0.5);
	  //	  tleft_CORR -= bunch_spacing_ns * (floor( tleft_CORR/bunch_spacing_ns )+0.5);
	  //tright_CORR -= bunch_spacing_ns * (floor( tright_CORR/bunch_spacing_ns )+0.5);
		  
	  //  tleft_CORR -= bunch_spacing_ns * ( floor(tmean_CORR/bunch_spacing_ns)+0.5 );
	  //tright_CORR -= bunch_spacing_ns * ( floor(tmean_CORR/bunch_spacing_ns)+0.5 );
	  
	  
	  double tmean_old = T->bb_hodotdc_clus_bar_tdc_meantime[ibar];
	  double tdiff_old = T->bb_hodotdc_clus_bar_tdc_timediff[ibar];
	  htleft_corr_vs_ID_old->Fill( ID, tleft_CORR );
	  htright_corr_vs_ID_old->Fill( ID, tright_CORR );
	  
	  hwalkcorr_allpmts->Fill( totleft, tleft_CORR - HODOwL[ID] * totleft );
	  hwalkcorr_allpmts->Fill( totright, tright_CORR - HODOwR[ID] * totright );

	  ( (TH2D*) (*hwalkcorr_by_PMT)[ID] )->Fill( totleft, tleft_CORR - HODOwL[ID]*totleft );
	  ( (TH2D*) (*hwalkcorr_by_PMT)[ID+90] )->Fill( totright, tright_CORR - HODOwR[ID]*totright );
	  
	  //calculate a corrected time difference without the propagation correction:
	  //This only includes walk correction and offset
	  //double tdiff_CORR = (tleft - HODOt0[ID]+ HODOwL[ID]*totleft)-
	  //  (tright-HODOt0[ID]+HODOwR[ID]*totright);

	  double tdiff_CORR = (tleft_CORR + dLEFT/vscint[ID]) -
	    (tright_CORR + dRIGHT/vscint[ID]);

	  ( (TH2D*) (*htdiff_vs_y_by_bar)[ID] )->Fill( yhodo, tdiff_CORR);
	  
	  
	  //double tmean_CORR = fmod(0.5*(tleft_CORR + tright_CORR),bunch_spacing_ns);
	  //tmean_CORR -= bunch_spacing_ns*(floor(tmean_CORR/bunch_spacing_ns)+0.5);
	  
	  if( ibar== 0 ) Tmean_corr = tmean_CORR;
	  
	  htmean_vs_ID_old->Fill( ID, tmean_old );
	  htmean_vs_ID_new->Fill( ID, tmean_CORR );
	  htmean_vs_ID_new_noRFcorr->Fill( ID, tmean_CORR + RFcorr + RFoffsets[ID] );
	  htdiff_yhodo_old->Fill( yhodo, tdiff_old );
	  htdiff_yhodo_new->Fill( yhodo, tdiff_CORR );
	}

	HodoTmean /= HodoTOTsum;

	//If "fix hodo params is set, use the OLD hodo params for
	//ADC time alignments, as represented by the "tfinal" variable
	if( fixhodoparams ) HodoTmean = T->bb_hodotdc_clus_tfinal[0]; 

	int nblkSH = std::min(MAXNBLK_BBSH,int(T->bb_sh_nblk));
	int nblkPS = std::min(MAXNBLK_BBPS,int(T->bb_ps_nblk));
	int nblkHCAL = std::min(MAXNBLK_HCAL,int(T->sbs_hcal_nblk));
	
	// Let's loop on BBCAL hits first;
	// No additional corrections are required here because the trigger phase correction has already been
	// applied to hodoscope (and shower/preshower are immediately adjacent to hodoscope):
	for( int ihit=0; ihit<nblkSH; ihit++ ){
	  double atime = T->bb_sh_clus_blk_atime[ihit];
	  double eblk = T->bb_sh_clus_blk_e[ihit];
	  double idblk = T->bb_sh_clus_blk_id[ihit];
	  //Somewhat arbitrary threshold of 100 MeV:
	  if( eblk >= 0.1 && (ihit == 0 || fabs( atime - T->bb_sh_atimeblk ) <= 6.0 ) && eblk >= 0.1 * T->bb_sh_eblk ){
	    hdt_BBSH_hodo_vs_IDBBSH->Fill( idblk, atime - BBCAL_t0ADC[idblk] - HodoTmean );
	  }
	}

	for( int ihit=0; ihit<nblkPS; ihit++ ){
	  double atime = T->bb_ps_clus_blk_atime[ihit];
	  double eblk = T->bb_ps_clus_blk_e[ihit];
	  double idblk = T->bb_ps_clus_blk_id[ihit];

	  if( eblk >= 0.1 && (ihit == 0 || fabs( atime - T->bb_ps_atimeblk ) <= 6.0 ) && eblk >= 0.1 * T->bb_ps_eblk ){ //Use 50 MeV threshold for PS:
	    hdt_BBPS_hodo_vs_IDBBPS->Fill( idblk, atime - BBCAL_t0ADC[idblk+189] - HodoTmean );
	  }
	}

	int nhitGRINCH = std::min(MAXNHIT_GRINCH, int( T->bb_grinch_tdc_ngoodhits ) );
	//Add GRINCH: 
	for( int ihit=0; ihit<nhitGRINCH; ihit++ ){ //For this comparison we DO require trigger phase correction:
	  //We'll manually correct GRINCH times for trigger phase until we have some
	  //large replays with the new "corrected time" variables:

	  long timestamp = long(T->g_evtime);
	  
	  double trigphasecorr = 4.00802 * ((timestamp%2+1)%2-1);

	  // cout << "timestamp, trigphase, trigphasecorr = " << timestamp
	  //      << ", " << (timestamp%2+1)%2-1 << ", " << trigphasecorr << endl;
	  
	  double time = T->bb_grinch_tdc_hit_time[ihit];
	  int pmt = int( T->bb_grinch_tdc_hit_pmtnum[ihit] );
	  
	  bool goodhit = T->bb_grinch_tdc_hit_trackindex[ihit] == 0 && T->bb_grinch_tdc_hit_clustindex[ihit] == T->bb_grinch_tdc_bestcluster && fabs( time - T->bb_grinch_tdc_clus_t_mean ) <= GRINCH_tdiff_max;

	  //time -= GRINCH_t0[pmt]; //correct GRINCH time for internal alignment offset

	  if( goodhit ){
	    hdt_GRINCH_hodo_vs_IDGRINCH->Fill( pmt, time - GRINCH_t0[pmt] - trigphasecorr - HodoTmean );
	  }
	}
	  
	//For HCAL ADC times, we'll fill histogram with a cut on deltax, deltay
	
	// HCAL TDC times have already been reference time subtracted;
	// But for comparison to the "RF-corrected" hodoscope mean time we want to remove the influence of the reference time subtraction from HCAL as well. 
	
	double RFtime_HCAL = T->sbs_tdctrig_rftime;
	double TrigTime_HCAL = T->sbs_tdctrig_trigtime;

	bool goodRF_HCAL = abs(RFtime_HCAL)<1.e5;
	bool goodTrig_HCAL = abs(TrigTime_HCAL)<1.e5;

	
	//if( goodRF_HCAL ){
	//HCAL RF time has already been reference subtracted
	double RFcorr_HCAL = RFtime_HCAL + vz/0.299792458;
	
	if( !goodRF_HCAL ){ //Replace HCAL RF time with BB RF time:
	  // Up to some integer multiple of RF spacing (160.321 ns), we have:
	  // RFtime HCAL - RFtime BB = Trigger Time HCAL - Trigger Time BB
	  // HOWEVER since RF time HCAL has already been reference subtracted, we
	  // don't need to add it back in
	  RFcorr_HCAL = RFtime - TrigTime;
	}
	RFcorr_HCAL -= bunch_spacing_ns*(floor(RFcorr_HCAL/bunch_spacing_ns+0.5));
	
	double tHCAL = T->sbs_hcal_tdctimeblk - RFcorr_HCAL;
	double eblkHCAL = T->sbs_hcal_eblk;
	int idblkHCAL = int(T->sbs_hcal_idblk);
	double xHCAL = T->sbs_hcal_x;
	double yHCAL = T->sbs_hcal_y;
	
	
	TVector3 ep(T->bb_tr_px[0], T->bb_tr_py[0], T->bb_tr_pz[0]);
	TLorentzVector k(0,0,Ebeam,Ebeam);
	TLorentzVector P(0,0,0,Mp);
	
	TLorentzVector kprime(ep,ep.Mag());
	TLorentzVector q = k-kprime;
	TLorentzVector Pprime = P + q;
	
	double Q2 = q.M2();
	
	double etheta = ep.Theta();
	double ephi = ep.Phi();

	//We are ASSUMING that we're dealing with PROTONs here:
	double ptof_central_temp = ptof_central_default;
	double sbsfield_temp = sbsfield_default * sbsmaxfield;
	if( nfieldsettings>0 ){
	  for( int iset=0; iset<nfieldsettings; iset++ ){
	    if( T->g_runnum >= rmin[iset] && T->g_runnum <= rmax[iset] ){
	      sbsfield_temp = sbsmaxfield * sbsfield[iset];
	      ptof_central_temp = ptof_central[iset];
	    }
	  }
	}
	
	double Eprime_etheta = Ebeam/(1.0+Ebeam/Mp*(1.0-cos(etheta)));
	double Tp_etheta = Ebeam-Eprime_etheta;
	double pp_etheta = sqrt(pow(Tp_etheta,2)+2.0*Mp*Tp_etheta);
	double ptheta_etheta = acos( (Ebeam-Eprime_etheta*cos(etheta))/(pp_etheta));
	double pphi_ephi = ephi + TMath::Pi();
	
	
	double ptheta_4vect = q.Vect().Theta();
	double pphi_4vect = q.Vect().Phi();
	double pp_e4vect = q.Vect().Mag();
	
	TVector3 pnhat_expect( sin(ptheta_etheta)*cos(pphi_ephi),
			       sin(ptheta_etheta)*sin(pphi_ephi),
			       cos(ptheta_etheta) );

	TVector3 pnhat_expect_4vect( sin(ptheta_4vect)*cos(pphi_4vect),
				     sin(ptheta_4vect)*sin(pphi_4vect),
				     cos(ptheta_4vect) );
	
	TVector3 vertex(0,0,vz);
	
	double sintersect = (HCALorigin-vertex).Dot(zaxis_HCAL)/(pnhat_expect.Dot(zaxis_HCAL));
	double sint_4vect = (HCALorigin-vertex).Dot(zaxis_HCAL)/(pnhat_expect_4vect.Dot(zaxis_HCAL));
	
	TVector3 HCAL_intersect = vertex + sintersect * pnhat_expect;
	TVector3 HCALint_4vect = vertex + sint_4vect * pnhat_expect_4vect;
	
	double xHCAL_expect = (HCAL_intersect - HCALorigin).Dot( xaxis_HCAL );
	double yHCAL_expect = (HCAL_intersect - HCALorigin).Dot( yaxis_HCAL );

	double xHCAL_expect_4vect = (HCALint_4vect - HCALorigin).Dot( xaxis_HCAL );
	double yHCAL_expect_4vect = (HCALint_4vect - HCALorigin).Dot( yaxis_HCAL );
	
	double Lpath_HCAL_expect = (HCAL_intersect - vertex).Mag();
	double Lpath_HCAL_expect_4vect = (HCALint_4vect - vertex).Mag();
	
	double beta_proton = pp_etheta/sqrt(pow(pp_etheta,2)+pow(Mp,2));

	double betap_4vect = pp_e4vect/sqrt(pow(pp_e4vect,2)+pow(Mp,2));
	double betan_4vect = pp_e4vect/sqrt(pow(pp_e4vect,2)+pow(Mn,2));

	//expected PROTON TOF
	double TOF_HCAL_expect = Lpath_HCAL_expect/(beta_proton*0.299792458);
	double TOF_HCAL_expect_p4vect = Lpath_HCAL_expect_4vect/(betap_4vect*0.299792458);
	double TOF_HCAL_expect_n4vect = Lpath_HCAL_expect_4vect/(betan_4vect*0.299792458);
	
	double protondeflection = 0.0;
	double protondeflection_4vect = 0.0;
	
	if( sbsfield_temp != 0. ){ //Calculated expected proton TOF with correction for magnetic deflection:
	  double BdL = sbsfield_temp * Dgap;
	  double Radius = pp_etheta/0.299792458/sbsfield_temp;
	  double thtar_expect = atan( pnhat_expect.Dot( xaxis_HCAL ) / pnhat_expect.Dot( zaxis_HCAL ) );

	  double x_in = (dSBS - vertex.Dot(zaxis_HCAL))*tan(thtar_expect);
	  double z_in = dSBS;
	  double x_center = x_in - Radius * cos(thtar_expect);
	  double z_center = z_in + Radius * sin(thtar_expect);
	  double z_out = dSBS+Dgap;
	  double A = 1.0;
	  double B = -2.0*x_center;
	  double C = pow(x_center,2)+pow( z_out-z_center,2) - pow(Radius,2);

	  double x_out = (-B + sqrt(pow(B,2)-4.0*A*C))/(2.0*A);
	  double theta_out = asin( (z_center-z_out)/Radius );
	  double phtar_expect = atan( pnhat_expect.Dot( yaxis_HCAL )/pnhat_expect.Dot( zaxis_HCAL ) );
	  //note that this neglects
	  double pathL = (dSBS-vertex.Dot(zaxis_HCAL))*sqrt(1.0+pow(tan(thtar_expect),2)+pow(tan(phtar_expect),2)) + Radius * (thtar_expect - theta_out) + (dHCAL-z_out)*sqrt(1.0+pow(tan(theta_out),2)+pow(tan(phtar_expect),2));
	  TOF_HCAL_expect = pathL/(beta_proton*0.299792458);

	  double xproj_HCAL = x_out + tan(theta_out) * (dHCAL-z_out);
	  protondeflection = xHCAL_expect - xproj_HCAL;


	  //Now do 4-vector calculation:
	  thtar_expect = atan( pnhat_expect_4vect.Dot(xaxis_HCAL)/pnhat_expect_4vect.Dot(zaxis_HCAL) );
	  x_in = (dSBS - vertex.Dot(zaxis_HCAL))*tan(thtar_expect);
	  Radius = pp_e4vect / 0.299792458 / sbsfield_temp;
	  x_center = x_in - Radius * cos(thtar_expect);
	  z_center = z_in + Radius * sin(thtar_expect);
	  B = -2.0*x_center;
	  C = pow(x_center,2)+pow( z_out - z_center, 2 ) - pow(Radius,2);
	  x_out = (-B + sqrt(pow(B,2)-4.*A*C))/(2.0*A);
	  theta_out = asin( (z_center-z_out)/Radius );
	  phtar_expect = atan( pnhat_expect_4vect.Dot( yaxis_HCAL ) / pnhat_expect_4vect.Dot( zaxis_HCAL ) );
	  pathL = (dSBS-vertex.Dot(zaxis_HCAL))*sqrt(1.0+pow(tan(thtar_expect),2)+pow(tan(phtar_expect),2)) + Radius * (thtar_expect - theta_out) + (dHCAL-z_out)*sqrt(1.0+pow(tan(theta_out),2)+pow(tan(phtar_expect),2));
	  TOF_HCAL_expect_p4vect = pathL/(betap_4vect*0.299792458);
	  
	  xproj_HCAL = x_out + tan(theta_out) * (dHCAL - z_out);
	  protondeflection_4vect = xHCAL_expect_4vect - xproj_HCAL;
	}

	
	
	//	cout << "proton deflection = " << protondeflection << endl;
	
	double W2 = T->e_kine_W2;
	
	// thetabend = 0.3/p * BdL ;
	
	//double BdL = Dgap * sbsmaxfield * sbsfield;
	//double thetabend = 0.3/pp_etheta * BdL;
	
	//	double protondeflection = tan(thetabend)*(dHCAL-(dSBS+Dgap/2.0)); 
	
	//int idblkHCAL = T->sbs_hcal_idblk;

	double deltax_nodeflect = xHCAL - xHCAL_expect;
	double deltax = xHCAL-(xHCAL_expect-protondeflection);
	double deltay = yHCAL-(yHCAL_expect);

	double deltax_p4vect = xHCAL-(xHCAL_expect_4vect-protondeflection_4vect);
	double deltax_n4vect = xHCAL-(xHCAL_expect_4vect);
	double deltay_4vect = yHCAL - yHCAL_expect_4vect;
	
	
	

	bool elcut_p_LH2 = W2>W2min && W2<W2max && sqrt(pow((deltax-dx0)/dxsigma,2)+pow((deltay-dy0)/dysigma,2))<= dxdy_nsigma_cut;
	
	bool elcut_p_LD2 = W2>W2min_LD2 && W2<W2max_LD2 && sqrt(pow((deltax_p4vect-dx04vect)/dxsigma4vect,2)+pow((deltay_4vect-dy04vect)/dysigma4vect,2))<= dxdy_nsigma_cut;
	bool elcut_n_LD2 = W2>W2min_LD2 && W2<W2max_LD2 && sqrt(pow((deltax_n4vect-dx04vect)/dxsigma4vect,2)+pow((deltay_4vect-dy04vect)/dysigma4vect,2))<= dxdy_nsigma_cut;

	// if( elcut_n_LD2 ){
	//   cout << "Proton deflection (m), (angles-only, 4-vector)=(" << protondeflection << ", " << protondeflection_4vect << ")" << endl;
	//   cout << "expected proton momentum (GeV), (angles-only, 4-vector)=(" << pp_etheta << ", " << pp_e4vect << ")" << endl;
	//   cout << "Expected nucleon three-vector, angles-only = "; pnhat_expect.Print();
	//   cout << endl << "Expected nucleon three-vector, 4-vector method = "; pnhat_expect_4vect.Print();
	// }
	
	//default proton LH2:
	bool elcut = elcut_p_LH2 || !use_elastic_cut_HCAL;

	int targtemp = 0;
	
	if( ntargsettings > 0 ){
	  for( int i=0; i<ntargsettings; i++ ){
	    if( T->g_runnum >= rmin_tgt[i] && T->g_runnum <= rmax_tgt[i] ){
	      if( targnum[i] == 1 ){ //LD2; switch to 4-vector:
		elcut = elcut_p_LD2 || elcut_n_LD2 || !use_elastic_cut_HCAL;
		targtemp = 1;
	      }
	    }
	  }
	}

	if( targtemp == 0 && sqrt(pow((deltax-dx0)/dxsigma,2)+pow((deltay-dy0)/dysigma,2))<= dxdy_nsigma_cut ){
	  hW2_xycut->Fill( W2 );
	}

	if( targtemp == 1 && sqrt(pow((deltax_p4vect-dx04vect)/dxsigma4vect,2)+pow((deltay_4vect-dy04vect)/dysigma4vect,2))<= dxdy_nsigma_cut ){
	  hW2_xycut_p->Fill( W2 );
	}

	if( targtemp == 1 && sqrt(pow((deltax_n4vect-dx04vect)/dxsigma4vect,2)+pow((deltay_4vect-dy04vect)/dysigma4vect,2))<= dxdy_nsigma_cut ){
	  hW2_xycut_n->Fill( W2 );
	}
	
	if( eblkHCAL > 0.02 && W2>W2min && W2<W2max ){
	  if( targtemp == 0 ){
	    hdxdy->Fill( deltay,deltax );
	    hdxdy_nodeflect_LH2->Fill( deltay, deltax_nodeflect );
	  } else {
	    hdxdy_p->Fill( deltay_4vect, deltax_p4vect );
	    hdxdy_n->Fill( deltay_4vect, deltax_n4vect );
	  }
	}
	
	//if( W2min < W2 && W2 < W2max && sqrt(pow(deltax,2)+pow(deltay,2))<=0.24 && eblkHCAL>0.02 ){
	// if( (W2>W2min && W2<W2max && sqrt(pow((deltax-dx0)/dxsigma,2)+pow((deltay-dy0)/dysigma,2))<= dxdy_nsigma_cut) ||
	//     !use_elastic_cut_HCAL ){
	if( elcut ){
	  // cout << "Elastic event found: (pTOF expect, pTOF central, diff)=("
	  //      << TOF_HCAL_expect << ", " << ptof_central_temp << ", "
	  //      << TOF_HCAL_expect - ptof_central_temp << ")" << endl;

	  double TOFcorr = 0.0;
	  if( use_elastic_cut_HCAL ){
	    if( elcut_p_LH2 ){ //LH2 protons:
	      TOFcorr = TOF_HCAL_expect - ptof_central_temp;
	    } else if( targtemp == 1 ){ //LD2:
	      if( elcut_p_LD2 ){ //LD2 protons:
		TOFcorr = TOF_HCAL_expect_p4vect - ptof_central_temp;
	      } else { //LD2 neutrons:
		TOFcorr = TOF_HCAL_expect_n4vect - ntof_central_default;
	      }
	    }
	  }
	     
	  
	  for( int iblk=0; iblk<nblkHCAL; iblk++ ){

	    double eblk = T->sbs_hcal_clus_blk_e[iblk];
	    double idblk = T->sbs_hcal_clus_blk_id[iblk];
	    double atimeblk = T->sbs_hcal_clus_blk_atime[iblk];
	    double t0 = HCAL_t0ADC[idblk-1];
	    
	    if( eblk >= 0.02 && (iblk == 0 || fabs( atimeblk - T->sbs_hcal_atimeblk) <= 6.0 ) && eblk >= 0.1 * T->sbs_hcal_eblk ){
	      //hdt_HCAL_hodo_vs_IDHCAL->Fill( idblk, atimeblk - t0 - (TOF_HCAL_expect - ptof_central_temp) - HodoTmean );
	      hdt_HCAL_hodo_vs_IDHCAL->Fill( idblk, atimeblk - t0 - TOFcorr - HodoTmean );
	    }
	    
	    if( T->sbs_hcal_clus_blk_tdctime[iblk] != -1000. && T->sbs_hcal_clus_blk_e[iblk] >= 0.025 ){
	      //double eblk = T->sbs_hcal_clus_blk_e[iblk];
	      double tblk = T->sbs_hcal_clus_blk_tdctime[iblk] - RFcorr_HCAL;
	      //double idblk = T->sbs_hcal_clus_blk_id[iblk];

	      double tblk_walkcorr = tblk - 1.25/sqrt(eblk) + 0.0285/eblk;
	      
	      htdiffHCAL_vs_eblk_all->Fill( eblk, tblk-HodoTmean-(TOF_HCAL_expect - ptof_central_temp));
	  
	      htdiffHCAL_vs_HCALID_new->Fill( idblk, tblk_walkcorr-HodoTmean-(TOF_HCAL_expect - ptof_central_temp));
	      int ipar_hcalt0 = idblk-1;
	      int ipar_hcalw0 = idblk+288-1;
	      //	      int ipar_hcalw1 = idblk+2*288-1;

	      double tblk_corr = tblk-HodoTmean-(TOF_HCAL_expect-ptof_central_temp);
	      
	      // tHCAL = tstart + t0 + w0/sqrt(E)
	      Mhcal(ipar_hcalt0,ipar_hcalt0) += 1.0;
	      Mhcal(ipar_hcalt0,ipar_hcalw0) += 1.0/sqrt(eblk);
	      //Mhcal(ipar_hcalt0,ipar_hcalw1) += -1.0/eblk;

	      Mhcal(ipar_hcalw0,ipar_hcalt0) += 1.0/sqrt(eblk);
	      Mhcal(ipar_hcalw0,ipar_hcalw0) += 1.0/eblk;
	      //Mhcal(ipar_hcalw0,ipar_hcalw1) += pow(eblk,-1.5);

	      // Mhcal(ipar_hcalw1,ipar_hcalt0) += -1.0/eblk;
	      // Mhcal(ipar_hcalw1,ipar_hcalw0) += pow(eblk,-1.5);
	      // Mhcal(ipar_hcalw1,ipar_hcalw1) += pow(eblk,-2);

	      bhcal(ipar_hcalt0) += (tblk_corr)*1.0;
	      bhcal(ipar_hcalw0) += (tblk_corr)/sqrt(eblk);
	      //    bhcal(ipar_hcalw1) += -(tblk_corr)/eblk;

	      nevent_blk_HCAL[idblk-1]+=1.0;
	      
	    }

	    
	    
	  }
	  //}
	}
      }
    }
    nevent++;
  }

  double ngoodbars=0;
  double vscint_avg_good = 0.0;
  double wL_avg_good = 0.0;
  double wR_avg_good = 0.0;
  
  for( int i=0; i<90; i++ ){
    if( nevent_vs_bar[i] >= double(mineventsperbar) ){
      ngoodbars += nevent_vs_bar[i];
      vscint_avg_good += vscint[i]*nevent_vs_bar[i];
      wL_avg_good += HODOwL[i]*nevent_vs_bar[i];
      wR_avg_good += HODOwR[i]*nevent_vs_bar[i];
    }
  }

  vscint_avg_good /= ngoodbars;
  wL_avg_good /= ngoodbars;
  wR_avg_good /= ngoodbars;
  
  for( int i=0; i<90; i++ ){
    if( nevent_vs_bar[i] < mineventsperbar ){
      HODOt0[i] = 0.0;
      vscint[i] = vscint_avg_good;
      HODOwL[i] = wL_avg_good;
      HODOwR[i] = wR_avg_good;
    }
  }
  
  //bhodo.Print();
  TString THdbfilename = outputfilename;
  THdbfilename.ReplaceAll(".root",".dat");  

  ofstream wLfile(Form("hodowL_%s",THdbfilename.Data()));
  ofstream wRfile(Form("hodowR_%s",THdbfilename.Data()));
  ofstream vscintfile(Form("hodovscint_%s",THdbfilename.Data()));
  ofstream t0file(Form("hodot0_%s",THdbfilename.Data()));
  ofstream RFfile(Form("hodoRF_%s",THdbfilename.Data()));
  
  TString dbfilename(outputfilename);
  dbfilename.ReplaceAll(".root",".dat");
  ofstream dbfile(dbfilename.Data());

  dbfile << "bb.hodotdc.timewalk0map = " << endl;
  for( int i=0; i<90; i++ ){
    if( i>0 && i%9 == 0 ) {
      dbfile << endl;
      wLfile << endl;
    }
    TString entry;
    dbfile << entry.Format("%15.6g", -HODOwL[i]) << " ";
    wLfile << entry.Format("%15.6g", HODOwL[i]) << " ";
  }

  dbfile << endl;

  //dbfile << "bb.hodotdc.timewalk1map = " << endl;
  for( int i=0; i<90; i++ ){
    if( i>0 && i%9 == 0 ) {
      dbfile << endl;
      wRfile << endl;
    }
    TString entry;
    dbfile << entry.Format("%15.6g", -HODOwR[i]) << " ";
    wRfile << entry.Format("%15.6g", HODOwR[i]) << " ";
  }

  dbfile << endl << endl;
  dbfile << "bb.hodotdc.timewalk1map = " << endl;

  for( int i=0; i<180; i++ ){
    if( i>0 && i%9 == 0 ) dbfile << endl;
    TString entry;
    dbfile << entry.Format("%15.6g", 0.0) << " ";
  }
  dbfile << endl << endl;

  dbfile << "bb.hodotdc.vscint = " << endl;
  for( int i=0; i<90; i++ ){
    if( i>0 && i%9 == 0 ){
      dbfile << endl;
      vscintfile << endl;
    }
    TString entry;
    dbfile << entry.Format("%15.6g", vscint[i] ) << " ";
    vscintfile << entry.Format("%15.6g", vscint[i] ) << " ";
  }
  dbfile << endl << endl;

  // In the calibration procedure, we have aligned the following quantity at zero:
  // t corrected = 0 = t - (etof-etof0) - t0 + w*TOT - d/v - (RFtime+vz/c + RFoffset) - MeanTimeOffset 
  dbfile << "bb.hodotdc.meantime_offset = " << endl;
  for( int i=0; i<90; i++ ){
    if( i>0 && i%9 == 0 ){
      dbfile << endl;
      t0file << endl;
    }
    TString entry;
    dbfile << entry.Format("%15.6g", HODOt0[i]+MeanTimeOffsets[i]) << " ";
    t0file << entry.Format("%15.6g", HODOt0[i]+MeanTimeOffsets[i]) << " ";
  }
  dbfile << endl << endl;
  dbfile << "bb.hodotdc.rf_offset = " << endl;
  for( int i=0; i<90; i++ ){
    if( i>0 && i%9 == 0 ){
      dbfile << endl;
      RFfile << endl;
    }
    TString entry;
    dbfile << entry.Format("%15.6g", RFoffsets[i]) << " ";
    RFfile << entry.Format("%15.6g", RFoffsets[i]) << " ";
  }
  dbfile << endl << endl;

  dbfile << "bb.hodotdc.tdiffoffset = " << endl;
  for( int i=0; i<90; i++ ){
    if( i>0 && i%9 == 0 ){
      dbfile << endl;
    }
    TString entry;
    dbfile << entry.Format("%15.6g", 0.0) << " ";
  }
  dbfile << endl;
  
  // Print out some diagnostic plots:
  //TCanvas *c1 = new TCanvas("c1","c1",1200,900);
  c1->Clear();

  

  htmean_vs_ID_new->Draw("colz");
  gPad->Modified();
  c1->Update();
  gSystem->ProcessEvents();
  tempname = pdffilename;
  //tempname+= "(";
  c1->Print(tempname.Data());

  
  
  //  double lmargin=0.2, bmargin=0.12, rmargin=0.03, tmargin=0.04;

  c1->Clear();
  c1->Divide(3,3,.001,.001);

  for( int i=0; i<90; i++ ){
    c1->cd(i%9+1);
    TString histname,histtitle;
    TH1D *htemp = htmean_vs_ID_new->ProjectionY(histname.Format("htmean_corr_bar%d",i),i+1,i+1);
    htemp->SetTitle(histtitle.Format("Bar %d, all corrections; t_{mean} (ns);",i));
    htemp->Draw();
    gPad->Modified();
    c1->Update();
    gSystem->ProcessEvents();
    tempname = pdffilename;
    if( i%9 == 8 ) c1->Print(tempname.Data());
  }
  
  for( int i=0; i<90; i++ ){
    c1->cd(i%9+1);
    ( (TH2D*) (*htdiff_vs_y_by_bar)[i] )->Draw("colz");
    gPad->Modified();
    c1->Update();
    gSystem->ProcessEvents();

    if( i%9 == 8 ){ //Print this page:
      tempname=pdffilename;

      c1->Print(tempname.Data());
    }
  }

  //Walk for left pmts:
  for( int i=0; i<90; i++ ){
    c1->cd(i%9+1);
    ( (TH2D*) (*hwalkcorr_by_PMT)[i] )->Draw("colz");
    gPad->Modified();
    c1->Update();
    gSystem->ProcessEvents();

    if( i%9 == 8 ){ //Print this page:
      tempname=pdffilename;
      //if( i == 8 ) tempname += "(";

      c1->Print(tempname.Data());
    }
  }
  //walk for right pmts:
  for( int i=0; i<90; i++ ){
    c1->cd(i%9+1);
    ( (TH2D*) (*hwalkcorr_by_PMT)[i+90] )->Draw("colz");
    gPad->Modified();
    c1->Update();
    gSystem->ProcessEvents();

    if( i%9 == 8 ){ //Print this page:
      tempname=pdffilename;
      //if( i == 8 ) tempname += "(";
      //if( i == 89 ) tempname += ")";
      c1->Print(tempname.Data());
    }
  }


  for( int i=0; i<288; i++ ){
    if( nevent_blk_HCAL[i] < 100. ){
      int ipar_t0 = i;
      int ipar_w0 = i+288;
      //      int ipar_w1 = i+288;
      Mhcal(ipar_t0,ipar_t0)=1.;
      Mhcal(ipar_w0,ipar_w0)=1.;
      //Mhcal(ipar_w1,ipar_w1)=1.;
      bhcal(ipar_t0) = 0.;
      bhcal(ipar_w0) = 0.;
      //bhcal(ipar_w1) = 0.;
      for( int j=0; j<nparams_HCAL; j++){ //zero out all off-diagonal elements:
	if( j != ipar_t0 ){
	  Mhcal(ipar_t0,j) = Mhcal(j,ipar_t0) = 0.0;
	}
	if( j != ipar_w0 ){
	  Mhcal(ipar_w0,j) = Mhcal(j,ipar_w0) = 0.0;
	}
	// if( j != ipar_w1 ){
	//   Mhcal(ipar_w1,j) = Mhcal(j,ipar_w1) = 0.0;
	// }
      }
    }
  }

  TDecompSVD Ahcal(Mhcal);
  Ahcal.Solve(bhcal);
  bhcal.Print();

  double t0avg_hcal = 0.0;
  double walkcorr_avg_hcal = 0.0;
  double nblocks_hcal = 0.0;

  double t0hcal[288];
  double w0hcal[288];
  double blkIDhcal[288];
  for( int i=0; i<288; i++ ){
    if( nevent_blk_HCAL[i] >= 100. ){
      walkcorr_avg_hcal += nevent_blk_HCAL[i]*bhcal[i+288];
      nblocks_hcal += nevent_blk_HCAL[i];
      t0avg_hcal += nevent_blk_HCAL[i]*bhcal[i];
      t0hcal[i] = bhcal[i];
      w0hcal[i] = bhcal[i+288];
      
    }
    blkIDhcal[i]=i+1;
  }

  walkcorr_avg_hcal /= nblocks_hcal;
  t0avg_hcal /= nblocks_hcal;
  
  for( int i=0; i<288; i++ ){
    if( nevent_blk_HCAL[i] < 100. ){
      t0hcal[i] = t0avg_hcal;
      w0hcal[i] = walkcorr_avg_hcal;
    }
  }
  
  nevent=0;

  TGraph *gHODOt0 = new TGraph(90,HODObarID,HODOt0);
  TGraph *gHODOwL = new TGraph(90,HODObarID,HODOwL);
  TGraph *gHODOwR = new TGraph(90,HODObarID,HODOwR);
  TGraph *gHODOvscint = new TGraph(90,HODObarID,vscint);

  // TGraph *gHCALt0 = new TGraph(288,blkIDhcal,t0hcal);
  // TGraph *gHCALw0 = new TGraph(288,blkIDhcal,w0hcal);
  
  gHODOt0->SetMarkerStyle(20);
  gHODOwL->SetMarkerStyle(20);
  gHODOwR->SetMarkerStyle(21);
  gHODOvscint->SetMarkerStyle(20);
  // gHCALt0->SetMarkerStyle(20);
  // gHCALw0->SetMarkerStyle(20);
  
  c1->Clear();
  c1->Divide(2,2,.001,.001);
  c1->cd(1);
  gHODOt0->Draw("AP");
  gHODOt0->SetTitle("Hodoscope fit results;bar ID;mean time offset (ns)");
  c1->cd(2);
  gHODOvscint->Draw("AP");
  gHODOvscint->SetTitle("Hodoscope fit results;bar ID;bar propagation speed (m/ns)");
  c1->cd(3);
  gHODOwL->Draw("AP");
  gHODOwL->SetTitle("Hodoscope fit results; bar ID; Left PMT walk correction slope");

  c1->cd(4);
  gHODOwR->Draw("AP");
  gHODOwR->SetTitle("Hodoscope fit results; bar ID; right PMT walk correction slope");

  // c1->Update();
  // gPad->Modified();
  // gSystem->ProcessEvents();
  // c1->Print(pdffilename);

  // c1->Clear();
  // c1->Divide(2,1,0.001,0.001);
  // c1->cd(1);
  // gHCALt0->Draw("AP");
  // gHCALt0->SetTitle("HCAL fit results; Block ID; time offset (ns)");
  // c1->cd(2);
  // gHCALw0->Draw("AP");
  // gHCALw0->SetTitle("HCAL fit results; Block ID; walk correction (1/sqrt(e)) slope");

  c1->Update();
  gPad->Modified();
  gSystem->ProcessEvents();
  //pdffilename += ")";
  c1->Print(pdffilename);

  gHODOt0->Write("gHODOt0");
  gHODOwL->Write("gHODOwL");
  gHODOwR->Write("gHODOwR");
  gHODOvscint->Write("gHODOvscint");
  // gHCALt0->Write("gHCALt0");
  // gHCALw0->Write("gHCALw0");

  //Do shower, preshower, and HCAL ADC time offset fits:

  c1->Clear();
  c1->Divide(3,3,.001,.001);

  set<int> listbadSH;
  set<int> listbadPS;
  vector<double> IDSH(189);
  vector<double> dIDSH(189,0);
  vector<double> ToffSH(189,0);
  vector<double> dToffSH(189,1);

  gStyle->SetOptFit();
  
  for(int i=0; i<189; i++ ){
    //ToffSH[i] = -BBCAL_t0ADC[i];
    
    TH1D *htemp = hdt_BBSH_hodo_vs_IDBBSH->ProjectionY( Form("hdtSHhodo_blk%d",i), i+1, i+1 );

    c1->cd(i%9+1);

    htemp->Draw();
    
    IDSH[i] = i;
    //    dIDSH[i] = 0.0;
    
    if( htemp->GetEntries() >= 300 ){
      TFitResultPtr fr = FitGaus_FWHM( htemp );

      htemp->Draw();

      if( fr->IsValid() ){
      
	TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));

	double mean = ftemp->GetParameter("Mean");
	//      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	double dmean = ftemp->GetParameter("Sigma");
	
	ToffSH[i] = mean;
	dToffSH[i] = dmean;
      } else { //try a simpler fit method; Gaussian with mean +/- 10 ns
	fr = htemp->Fit("gaus","SQ", "", htemp->GetMean()-10.0, htemp->GetMean() + 10.0 );

	if( fr->IsValid() ){
	  TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	  
	  double mean = ftemp->GetParameter("Mean");
	  //      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	  double dmean = ftemp->GetParameter("Sigma");
	  
	  ToffSH[i] = mean;
	  dToffSH[i] = dmean;
	} else {
	  ToffSH[i] = htemp->GetMean();
	  dToffSH[i] = htemp->GetRMS();
	}
      }
    } else if( htemp->GetEntries() >= 100 ){
      TFitResultPtr fr = htemp->Fit("gaus","SQ","",htemp->GetMean()-10.0, htemp->GetMean()+10.0);

      if( fr->IsValid() ){
	TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	
	double mean = ftemp->GetParameter("Mean");
	//      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	double dmean = ftemp->GetParameter("Sigma");

	ToffSH[i] = mean;
	dToffSH[i] = dmean;
      } else {
	ToffSH[i] = htemp->GetMean();
	dToffSH[i] = htemp->GetRMS();
      }
    } else {
      listbadSH.insert( i );
    }

    if( (i+1)%9 == 0 ){
      c1->Update();
      gPad->Modified();
      gSystem->ProcessEvents();
      //pdffilename += ")";
      c1->Print(pdffilename);
    }
  }

  for( auto ibad : listbadSH ){
    // Find the closest successfully-calibrated channel to the current one; channels run from right to left within
    // each row and from bottom to top overall:
    int rowbad = ibad/7;
    int colbad = ibad%7;
    
    // look for nearest neighbors up/down/left/right:
    double T0avg_neighbors = 0.0;
    double nnear = 0.0;

    int testrow, testcol, testid;

    //while( nnear == 0.0 ){ //first test nearest neighbors up, down, left, right
    testrow = rowbad;
    testcol = colbad-1;
    if( testcol >= 0 ){
      testid = testcol + 7*testrow;
      if( listbadSH.find(testid) == listbadSH.end() ){
	T0avg_neighbors += ToffSH[testid];
	nnear += 1.0;
      }
    }
    
    testcol = colbad+1;
    if( testcol < 7 ){
      testid = testcol + 7*testrow;
      if( listbadSH.find(testid) == listbadSH.end() ){
	T0avg_neighbors += ToffSH[testid];
	nnear += 1.0;
      }
    }
	  
    testrow = rowbad-1;
    testcol = colbad;
    if( testrow >= 0 ){
      testid = testcol + 7*testrow;
      if( listbadSH.find(testid) == listbadSH.end() ){
	T0avg_neighbors += ToffSH[testid];
	nnear += 1.0;
      }
    }

    testrow = rowbad + 1;
    testcol = colbad;
    if( testrow < 27 ){
      testid = testcol + testrow*7;
      if( listbadSH.find(testid) == listbadSH.end() ){
	T0avg_neighbors += ToffSH[testid];
	nnear+=1.0;
      }
    }

    // Note here that ToffSH[id] = tSH - t0SHinternal - thodo;
    // therefore if we set ToffSH for the uncalibrated channels to the average of its nearest neighbors,
    // this should also be a reasonable proxy for tSH-t0SHinternal (for that channel) - thodo
    // When we write out the DB file, we will need to ADD t0SHinternal to this offset to get the TOTAL offset
    // that needs to be applied (relative to the database one)
    
    if( nnear > 0.0 ){ //if any immediate neighbors were calibrated, take the simple average of nearest neighbors.
      ToffSH[ibad] = T0avg_neighbors/nnear;
    } else { //take a brute-force approach, loop on all calibrated channels and then take the offset from the nearest one to the channel in question:
      double inear = -1;
      double mindiff = 1000.0;
      for( int j=0; j<189; j++ ){
	if( listbadSH.find(j) == listbadSH.end() ){
	  testcol = j%7;
	  testrow = j/7;
	  double diff = pow( testcol-colbad, 2 ) + pow( testrow - rowbad, 2 );
	  if( inear < 0 || diff < mindiff ){
	    mindiff = diff;
	    inear = j;
	  }
	  
	}
      }

      if( inear >= 0 ){
	ToffSH[ibad] = ToffSH[inear];
      } 
    }
  }

  TString BBSHdbfilename = outputfilename;

  BBSHdbfilename.ReplaceAll(".root",".dat");
  BBSHdbfilename.Prepend("BBSHt0_");

  TString BBPSdbfilename = outputfilename;

  BBPSdbfilename.ReplaceAll(".root",".dat");
  BBPSdbfilename.Prepend("BBPSt0_");

  TString HCALdbfilename = outputfilename;
    
  HCALdbfilename.ReplaceAll(".root",".dat");
  HCALdbfilename.Prepend("HCALt0_");
  
  ofstream dbSH(BBSHdbfilename.Data());
  ofstream dbPS(BBPSdbfilename.Data());
  ofstream dbHCAL(HCALdbfilename.Data());
  // In SBSGenericDetector, the time offset for FADC waveforms is
  // ADDED to the result. Our t0 needs to be subtracted.
  // ToffSH above is equivalent to the mean value of
  // ToffSH = OLD ADC time - t0internal - thodo - tofcorr
  // OLD ADC time = RAW ADC time + OLD OFFSET
  // RAW ADC time + OLD OFFSET - t0internal - thodo - tofcorr = ToffSH
  // RAW ADC time + OLD OFFSET - t0internal - ToffSH - thodo - tofcorr = 0
  // RAW ADC time + NEW OFFSET - thodo - tofcorr = 0
  // NEW OFFSET = OLD OFFSET - t0internal - ToffSH
  
  dbSH << "bb.sh.adc.timeoffset = " << endl;
  for( int i=0; i<189; i++ ){
    if( i%7 == 0 && i > 0 ) dbSH << endl;
    dbSH << Form("%12.7g ", -(BBCAL_t0ADC[i]+ToffSH[i])+oldBBSHoffsets[i]);
  }
  
  TGraphErrors *gT0SH = new TGraphErrors( 189, &(IDSH[0]), &(ToffSH[0]), &(dIDSH[0]), &(dToffSH[0]) );
  gT0SH->SetMarkerStyle(20);
  gT0SH->SetMarkerColor(1);
  gT0SH->SetLineColor(1);
  
  c1->Clear();
  hdt_BBSH_hodo_vs_IDBBSH->Draw("colz");
  gT0SH->Draw("PZSAME");
  c1->Update();
  gPad->Modified();
  gSystem->ProcessEvents();

  gT0SH->Write("gT0_BBshower");
  //pdffilename += ")";
  c1->Print(pdffilename);


  c1->Clear();
  c1->Divide(3,3,.001,.001);
  
  //Now do PS:

  vector<double> IDPS(52);
  vector<double> dIDPS(52,0);
  vector<double> ToffPS(52,0);
  vector<double> dToffPS(52,1);

  
  
  for(int i=0; i<52; i++ ){

    //ToffPS[i] = -BBCAL_t0ADC[i+189];
    
    TH1D *htemp = hdt_BBPS_hodo_vs_IDBBPS->ProjectionY( Form("hdtPShodo_blk%d",i), i+1, i+1 );

    c1->cd(i%9+1);

    htemp->Draw();
    gStyle->SetOptFit();
    
    IDPS[i] = i;
    //    dIDPS[i] = 0.0;
    
    if( htemp->GetEntries() >= 300 ){
      TFitResultPtr fr = FitGaus_FWHM( htemp );

      htemp->Draw();

      if( fr->IsValid() ){
	
	TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	
	double mean = ftemp->GetParameter("Mean");
	//double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	double dmean = ftemp->GetParameter("Sigma");
	
	//These lines won't compile under older ROOT versions:
	// double mean = ( (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus") ) )->GetParameter("Mean");
	// double dmean = ( (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus") ) )->GetParError("Mean");
	
	ToffPS[i] = mean;
	dToffPS[i] = dmean;
      } else { //try a simpler fit method:
	fr = htemp->Fit("gaus","SQ", "", htemp->GetMean()-10.0, htemp->GetMean() + 10.0 );
	
	if( fr->IsValid() ){
	  TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	  
	  double mean = ftemp->GetParameter("Mean");
	  //      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	  double dmean = ftemp->GetParameter("Sigma");
	  
	  ToffPS[i] = mean;
	  dToffPS[i] = dmean;
	} else {
	  ToffPS[i] = htemp->GetMean();
	  dToffPS[i] = htemp->GetRMS();
	}
      }
    } else if( htemp->GetEntries() >= 100 ){
      TFitResultPtr fr = htemp->Fit("gaus","SQ","",htemp->GetMean()-10.0, htemp->GetMean()+10.0);
      if( fr->IsValid() ){
	TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	
	double mean = ftemp->GetParameter("Mean");
	//      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	double dmean = ftemp->GetParameter("Sigma");

	ToffPS[i] = mean;
	dToffPS[i] = dmean;
      } else {
	ToffPS[i] = htemp->GetMean();
	dToffPS[i] = htemp->GetRMS();
      }
    } else {
      listbadPS.insert( i );
    }

    if( (i+1)%9 == 0 ){
      c1->Update();
      gPad->Modified();
      gSystem->ProcessEvents();
      //pdffilename += ")";
      c1->Print(pdffilename);
    }
  }


  for( auto ibad : listbadPS ){
    // Find the closest successfully-calibrated channel to the current one; channels run from right to left within
    // each row and from bottom to top overall:
    int rowbad = ibad/2;
    int colbad = ibad%2;
    
    // look for nearest neighbors up/down/left/right:
    double T0avg_neighbors = 0.0;
    double nnear = 0.0;

    int testrow, testcol, testid;

    //while( nnear == 0.0 ){ //first test nearest neighbors up, down, left, right
    testrow = rowbad;
    testcol = colbad-1;
    if( testcol >= 0 ){
      testid = testcol + 2*testrow;
      if( listbadPS.find(testid) == listbadPS.end() ){
	T0avg_neighbors += ToffPS[testid];
	nnear += 1.0;
      }
    }
    
    testcol = colbad+1;
    if( testcol < 2 ){
      testid = testcol + 2*testrow;
      if( listbadPS.find(testid) == listbadPS.end() ){
	T0avg_neighbors += ToffPS[testid];
	nnear += 1.0;
      }
    }
	  
    testrow = rowbad-1;
    testcol = colbad;
    if( testrow >= 0 ){
      testid = testcol + 2*testrow;
      if( listbadPS.find(testid) == listbadPS.end() ){
	T0avg_neighbors += ToffPS[testid];
	nnear += 1.0;
      }
    }

    testrow = rowbad + 1;
    testcol = colbad;
    if( testrow < 26 ){
      testid = testcol + testrow*2;
      if( listbadPS.find(testid) == listbadPS.end() ){
	T0avg_neighbors += ToffPS[testid];
	nnear+=1.0;
      }
    }

    // Note here that ToffSH[id] = tSH - t0SHinternal - thodo;
    // therefore if we set ToffSH for the uncalibrated channels to the average of its nearest neighbors,
    // this should also be a reasonable proxy for tSH-t0SHinternal (for that channel) - thodo
    // When we write out the DB file, we will need to ADD t0SHinternal to this offset to get the TOTAL offset
    // that needs to be applied (relative to the database one)
    
    if( nnear > 0.0 ){ //if any immediate neighbors were calibrated, take the simple average of nearest neighbors.
      ToffPS[ibad] = T0avg_neighbors/nnear;
    } else { //take a brute-force approach, loop on all calibrated channels and then take the offset from the nearest one to the channel in question:
      double inear = -1;
      double mindiff = 1000.0;
      for( int j=0; j<52; j++ ){
	if( listbadPS.find(j) == listbadPS.end() ){
	  testcol = j%2;
	  testrow = j/2;
	  double diff = pow( testcol-colbad, 2 ) + pow( testrow - rowbad, 2 );
	  if( inear < 0 || diff < mindiff ){
	    mindiff = diff;
	    inear = j;
	  }
	  
	}
      }

      if( inear >= 0 ){
	ToffPS[ibad] = ToffPS[inear];
      }
    }
  }

  dbPS << "bb.ps.adc.timeoffset = " << endl;
  for( int i=0; i<52; i++ ){
    if( i%2 == 0 && i > 0 ) dbPS << endl;
    dbPS << Form("%12.7g ", -(BBCAL_t0ADC[i+189]+ToffPS[i]) + oldBBPSoffsets[i] );
  }
  
  
  TGraphErrors *gT0PS = new TGraphErrors( 52, &(IDPS[0]), &(ToffPS[0]), &(dIDPS[0]), &(dToffPS[0]) );
  gT0PS->SetMarkerStyle(20);
  gT0PS->SetMarkerColor(1);
  gT0PS->SetLineColor(1);
  
  c1->Clear();
  hdt_BBPS_hodo_vs_IDBBPS->Draw("colz");
  gT0PS->Draw("PZSAME");
  c1->Update();
  gPad->Modified();
  gSystem->ProcessEvents();
  //pdffilename += ")";
  c1->Print(pdffilename);

  gT0PS->Write("gT0_BBpreshower");
  
  c1->Clear();

  
  c1->Divide(3,3,.001,.001);

  //Now do HCAL:

  vector<double> IDHCAL(288);
  vector<double> dIDHCAL(288,0);
  vector<double> ToffHCAL(288,0);
  vector<double> dToffHCAL(288,1);

  set<int> listbadHCAL;
  
  //The "dt" histogram has been filled with HCAL atime - t0 from internal alignment, - TOF corr -
  // Thodo. The resulting mean from the fit is the remaining offset:
  // T(hcal) - tinternal - TOF corr - Thodo = toff
  // So then the offset to be subtracted from 
  
  for(int i=1; i<=288; i++ ){
    //ToffHCAL[i-1] = -HCAL_t0ADC[i-1];
    
    TH1D *htemp = hdt_HCAL_hodo_vs_IDHCAL->ProjectionY( Form("hdtHCALhodo_blk%d",i), i, i );

    c1->cd((i-1)%9+1);

    htemp->Draw();
    
    IDHCAL[i-1] = i;
    //    dIDHCAL[i] = 0.0;
    
    if( htemp->GetEntries() >= 300 ){
      TFitResultPtr fr = FitGaus_FWHM( htemp );

      htemp->Draw();

      if( fr->IsValid() ){
      
	TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	
	double mean = ftemp->GetParameter("Mean");
	//      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	//double dmean = ftemp->GetParError(ftemp->GetParameter("Sigma"));
	double dmean = ftemp->GetParameter("Sigma");
	//These lines won't compile under older ROOT versions:
	// double mean = ( (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus") ) )->GetParameter("Mean");
	// double dmean = ( (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus") ) )->GetParError("Mean");

	ToffHCAL[i-1] = mean;
	dToffHCAL[i-1] = dmean;
      } else { //try a simpler fit method:
	fr = htemp->Fit("gaus","SQ", "", htemp->GetMean()-10.0, htemp->GetMean() + 10.0 );
	if( fr->IsValid() ){
	  TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	  
	  double mean = ftemp->GetParameter("Mean");
	  //      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	  //double dmean = ftemp->GetParError(ftemp->GetParameter("Sigma"));
	  double dmean = ftemp->GetParameter("Sigma");

	  ToffHCAL[i-1] = mean;
	  dToffHCAL[i-1] = dmean;
	} else {
	  ToffHCAL[i-1] = htemp->GetMean();
	  dToffHCAL[i-1] = htemp->GetRMS();
	}	  
      }
    } else if( htemp->GetEntries() >= 100 ){
      TFitResultPtr fr = htemp->Fit("gaus","SQ","",htemp->GetMean()-10.0, htemp->GetMean()+10.0);
      
      if( fr->IsValid() ){
	TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	
	double mean = ftemp->GetParameter("Mean");
	//      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
	double dmean = ftemp->GetParameter("Sigma");

	ToffHCAL[i-1] = mean;
	dToffHCAL[i-1] = dmean;
      } else {
	ToffHCAL[i-1] = htemp->GetMean();
	dToffHCAL[i-1] = htemp->GetRMS();
      }	
    } else {
      listbadHCAL.insert( i );      
    }

    if( (i)%9 == 0 ){
      c1->Update();
      gPad->Modified();
      gSystem->ProcessEvents();
      //pdffilename += ")";
      c1->Print(pdffilename);
    }
  }

  
  for( auto ibad : listbadHCAL ){
    // Find the closest successfully-calibrated channel to the current one; channels run from right to left within
    // each row and from bottom to top overall:
    int rowbad = (ibad-1)/12;
    int colbad = (ibad-1)%12;
    
    // look for nearest neighbors up/down/left/right:
    double T0avg_neighbors = 0.0;
    double nnear = 0.0;

    int testrow, testcol, testid;

    //while( nnear == 0.0 ){ //first test nearest neighbors up, down, left, right
    testrow = rowbad;
    testcol = colbad-1;
    if( testcol >= 0 ){
      testid = testcol + 12*testrow + 1;
      if( listbadHCAL.find(testid) == listbadHCAL.end() ){
	T0avg_neighbors += ToffHCAL[testid-1];
	nnear += 1.0;
      }
    }
    
    testcol = colbad+1;
    if( testcol < 12 ){
      testid = testcol + 12*testrow + 1;
      if( listbadHCAL.find(testid) == listbadHCAL.end() ){
	T0avg_neighbors += ToffHCAL[testid-1];
	nnear += 1.0;
      }
    }
	  
    testrow = rowbad-1;
    testcol = colbad;
    if( testrow >= 0 ){
      testid = testcol + 12*testrow + 1;
      if( listbadHCAL.find(testid) == listbadHCAL.end() ){
	T0avg_neighbors += ToffHCAL[testid-1];
	nnear += 1.0;
      }
    }

    testrow = rowbad + 1;
    testcol = colbad;
    if( testrow < 24 ){
      testid = testcol + testrow*12 + 1;
      if( listbadHCAL.find(testid) == listbadHCAL.end() ){
	T0avg_neighbors += ToffHCAL[testid-1];
	nnear+=1.0;
      }
    }

    // Note here that ToffSH[id] = tSH - t0SHinternal - thodo;
    // therefore if we set ToffSH for the uncalibrated channels to the average of its nearest neighbors,
    // this should also be a reasonable proxy for tSH-t0SHinternal (for that channel) - thodo
    // When we write out the DB file, we will need to ADD t0SHinternal to this offset to get the TOTAL offset
    // that needs to be applied (relative to the database one)
    
    if( nnear > 0.0 ){ //if any immediate neighbors were calibrated, take the simple average of nearest neighbors.
      ToffHCAL[ibad-1] = T0avg_neighbors/nnear;
    } else { //take a brute-force approach, loop on all calibrated channels and then take the offset from the nearest one to the channel in question:
      double inear = -1;
      double mindiff = 1000.0;
      for( int j=1; j<=288; j++ ){
	if( listbadHCAL.find(j) == listbadHCAL.end() ){
	  testcol = (j-1)%12;
	  testrow = (j-1)/12;
	  double diff = pow( testcol-colbad, 2 ) + pow( testrow - rowbad, 2 );
	  if( inear < 0 || diff < mindiff ){
	    mindiff = diff;
	    inear = j-1;
	  }
	  
	}
      }

      if( inear >= 0 ){
	ToffHCAL[ibad-1] = ToffHCAL[inear];
      }
    }
  }

  dbHCAL << "sbs.hcal.adc.timeoffset = " << endl;
  for( int i=0; i<288; i++ ){
    if( i%12 == 0 && i > 0 ) dbHCAL << endl;
    dbHCAL << Form("%12.7g ", -(HCAL_t0ADC[i]+ToffHCAL[i]) + oldHCALoffsets[i] );
  }
  
  TGraphErrors *gT0HCAL = new TGraphErrors( 288, &(IDHCAL[0]), &(ToffHCAL[0]), &(dIDHCAL[0]), &(dToffHCAL[0]) );
  gT0HCAL->SetMarkerStyle(20);
  gT0HCAL->SetMarkerColor(1);
  gT0HCAL->SetLineColor(1);
  
  c1->Clear();
  hdt_HCAL_hodo_vs_IDHCAL->Draw("colz");
  gT0HCAL->Draw("PZSAME");
  c1->Update();
  gPad->Modified();
  gSystem->ProcessEvents();
  //pdffilename += ")";
  c1->Print(pdffilename);

  gT0HCAL->Write("gT0_HCAL");

  //After HCAL, let's do the GRINCH:

  c1->Clear();
  c1->Divide(4,4,.001,.001);

  vector<double> IDGRINCH(512);
  vector<double> dIDGRINCH(512,0.0);
  vector<double> ToffGRINCH(512,0.0);
  vector<double> dToffGRINCH(512,2.0);

  set<int> listbadGRINCH; 
  
  for( int i=0; i<512; i++ ){
    c1->cd( i%16+1 );
    TString histname, histtitle;
    TH1D *htemp = hdt_GRINCH_hodo_vs_IDGRINCH->ProjectionY( Form("hdtGRINCHhodo_pmt%d", i), i+1, i+1 );

    htemp->Draw();

    IDGRINCH[i] = i;

    ToffGRINCH[i] = GRINCH_t0[i]; //default to GRINCH_t0 (internal alignment offset)
    
    if( htemp->GetEntries() >= minhits_GRINCH_hododiff ){
      TFitResultPtr fr = FitGaus_FWHM( htemp );

      htemp->Draw();
      if( fr->IsValid() ){
	TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));

	double mean = ftemp->GetParameter("Mean");
	double sigma = ftemp->GetParameter("Sigma");

	double dmean = ftemp->GetParError( ftemp->GetParNumber("Mean") );
	double dsigma = ftemp->GetParError( ftemp->GetParNumber("Sigma") );
	//for a "good" fit, the sigma should be right around 2 ns: 

	if( sigma >= 0.5 && sigma <= 8.0 && dmean < 0.3 && dsigma/sigma < 0.3 ){
	
	  ToffGRINCH[i] = mean;
	  dToffGRINCH[i] = sigma;
	} else {
	  listbadGRINCH.insert(i);
	}
      } else {
	listbadGRINCH.insert(i);
      }
	// else {
      // 	fr = htemp->Fit("gaus","SQ", "", htemp->GetMean()-10.0, htemp->GetMean() + 10.0 );
	
      // 	if( fr->IsValid() ){
      // 	  TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	  
      // 	  double mean = ftemp->GetParameter("Mean");
      // 	  //      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
      // 	  double dmean = ftemp->GetParameter("Sigma");

      // 	  ToffGRINCH[i] = mean;
      // 	  dToffGRINCH[i] = dmean;
      // 	} else {
      // 	  ToffGRINCH[i] = htemp->GetMean();
      // 	  dToffGRINCH[i] = htemp->GetRMS();
      // 	}
      // }
      // } // else if( htemp->GetEntries() >= 100 ){
      // TFitResultPtr fr = htemp->Fit("gaus","SQ","",htemp->GetMean()-10.0, htemp->GetMean()+10.0);

      // if( fr->IsValid() ){
      // 	TF1 *ftemp = (TF1*) (htemp->GetListOfFunctions()->FindObject("gaus"));
	
      // 	double mean = ftemp->GetParameter("Mean");
      // 	//      double dmean = ftemp->GetParError(ftemp->GetParNumber("Mean"));
      // 	double dmean = ftemp->GetParameter("Sigma");

      // 	ToffGRINCH[i] = mean;
      // 	dToffGRINCH[i] = dmean;
      // } else {
      // 	ToffGRINCH[i] = htemp->GetMean();
      // 	dToffGRINCH[i] = htemp->GetRMS();
      // }
    } else {
      listbadGRINCH.insert( i );
    }
    if( (i+1)%16 == 0 ){
      c1->Update();
      gPad->Modified();
      gSystem->ProcessEvents();
      c1->Print( pdffilename );
    }
  }

  for( auto ibad : listbadGRINCH ){
    //Let's just do the most basic test; don't check position, just check PMT number. Find the closest PMT number up or down and take the average:
    bool gotup=false, gotdown=false;
    int testup = ibad+1;
    int testdown = ibad-1;
    double t0up = 0.0, t0down = 0.0;
    while( !gotup && testup < 512 ){
      if( listbadGRINCH.find( testup ) == listbadGRINCH.end() ){
	gotup = true;
	t0up = ToffGRINCH[testup];
      }	
      testup++;
    }

    while( !gotdown && testdown >= 0 ){
      if( listbadGRINCH.find( testdown ) == listbadGRINCH.end() ){
	gotdown = true;
	t0down = ToffGRINCH[testdown];
      }
      testdown--;
    }

    double tsum = 0.0;
    double n = 0.0;
    if( gotup ){
      n += 1.0;
      tsum += t0up;
    }
    if( gotdown ){
      n += 1.0;
      tsum += t0down;
    }

    if( n > 0 ) ToffGRINCH[ibad] = tsum/n;
  }
    
  // For the GRINCH, the new TDC offset is to be SUBTRACTED from the "raw" TDC time:
  // Thus, the value to be subtracted will equal old offset + new offset

  TGraphErrors *gT0GRINCH = new TGraphErrors( 512, &(IDGRINCH[0]), &(ToffGRINCH[0]), &(dIDGRINCH[0]), &(dToffGRINCH[0]) );
  
  c1->Clear();
  hdt_GRINCH_hodo_vs_IDGRINCH->Draw("colz");
  gT0GRINCH->SetMarkerStyle(20);
  gT0GRINCH->SetMarkerColor(1);
  gT0GRINCH->SetLineColor(1);

  gT0GRINCH->Draw("PZSAME");

  gT0GRINCH->Write("gT0_GRINCH");
  
  TString GRINCHdbfilename = outputfilename;
  GRINCHdbfilename.ReplaceAll(".root",".dat");
  GRINCHdbfilename.Prepend("db_GRINCH_");
  
  ofstream dbGRINCH(GRINCHdbfilename.Data());

  dbGRINCH << "bb.grinch_tdc.tdc.offset = " << endl;
  for( int i=0; i<512; i++ ){
    if( i%16 == 0 && i > 0 ) dbGRINCH << endl;
    dbGRINCH << Form( "%12.7g ", (GRINCH_t0[i]+ToffGRINCH[i] + oldGRINCHoffsets[i])/GRINCH_TDC_calib);
  }

  pdffilename += ")";
  c1->Print(pdffilename);
  
  // c1->Update();
  // gPad->Modified();
  // gSystem->ProcessEvents();
  // pdffilename += ")";
  // c1->Print(pdffilename);
  
  fout->Write();
  
}
