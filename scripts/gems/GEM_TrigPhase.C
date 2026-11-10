#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TTreeFormula.h"
#include "TCut.h"
#include "TString.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TClonesArray.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TF1.h"
#include "TLine.h"
//#include "gen_tree.C"
//#include "gmn_tree.C"
//#include "genrp_tree.C"
//#include "gep_tree_data.C"

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
  
  return Htest->Fit("gaus","SQ0","",xlow,xhigh);
}

double CorrCoeff( int nsamples, const vector<double> &U, const vector<double> &V, const vector<double> &weights ){

  double sumweights = 0.0;
  double sumU = 0.0, sumV = 0.0, sumU2 = 0.0, sumV2 = 0.0;
  double sumUV = 0.0;
  if( U.size() != nsamples || V.size() != nsamples || weights.size() != nsamples ) {
    cout << "warning: size mismatch in corr. coeff. calculation" << endl;
    return -10000.;
  }
  
  for( int i=0; i<nsamples; i++ ){
    sumweights += weights[i];
    sumU += U[i] * weights[i];
    sumV += V[i] * weights[i];
    sumU2 += pow(U[i],2) * weights[i];
    sumV2 += pow(V[i],2) * weights[i];
    sumUV += U[i] * V[i] * weights[i];
  }

  double meanU = sumU/sumweights;
  double meanV = sumV/sumweights;
  double varU = sumU2/sumweights - pow(meanU,2);
  double varV = sumV2/sumweights - pow(meanV,2);
  double sigU = sqrt(varU);
  double sigV = sqrt(varV);

  return ( sumUV - sumweights * meanU*meanV )/(sumweights * sigU * sigV);

}

void GEM_TrigPhase( const char *configfilename, const char *outfilename = "GEM_TrigPhase_Test.root" ){

  TFile *fout = new TFile(outfilename, "RECREATE");
  
  ifstream configfile(configfilename);

  if( !configfile ) return;
  
  TChain *C = new TChain("T");

  TString currentline;

  //read list of ROOT files: 
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endlist") ){
    if( !currentline.BeginsWith("#") ){
      C->Add(currentline.Data());
    }
  }

  TCut globalcut="";
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endcut") ){
    if( !currentline.BeginsWith("#") ){
      globalcut += currentline.Data();
    }
  }

  TTreeFormula *GlobalCut = new TTreeFormula( "GlobalCut", globalcut, C );
  
  //Default to BigBite GEM configuration (v3 used starting Jan. 2022 with four U/V + 1 X/Y layers)

  TString expname="gmn_v3"; //BigBite GEMs only, version 3 is default!

  double ccor_cut_unweighted_default = 0.8;
  double ccor_cut_weighted_default = 0.8;

  double ccor_cut_unweighted = ccor_cut_unweighted_default;
  double ccor_cut_weighted = ccor_cut_weighted_default;

  //Default to taking 99% of the correlation coefficient distribution in determining the threshold.
  double frac_unweighted = 0.995;
  double frac_weighted = 0.995;

  //Default limits for setting threshold on correlation coefficient: 
  double thresh_ccor_min = -1.0;
  double thresh_ccor_max = 0.95;

  double thresh_ccor_min_uw = -1.0;
  double thresh_ccor_max_uw = 0.9;

  //Default to BigBite GEMs:
  TString trackername = "bb.gem";

  //int minevents = 5000; //default to prevent analysis of absent/low-statistics modules

  //List of modules to skip:
  std::set<int> skipmodules;
  
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endconfig") ){
    if( !currentline.BeginsWith("#") ){
      TObjArray *tokens = currentline.Tokenize(" ");

      int ntokens = tokens->GetEntries();
      if( ntokens >= 2 ){
	TString skey = ( (TObjString*) (*tokens)[0] )->GetString();
	TString sval = ( (TObjString*) (*tokens)[1] )->GetString();
	if( skey == "expname" ){
	  expname = sval;
	}

	if( skey == "trackername" ){
	  trackername = sval;
	}
	//	if( skey == "nmodules" ){
	//  nmodules = sval.Atoi();
	//}
	if( skey == "frac_uw" ){
	  frac_unweighted = sval.Atof();
	}

	if( skey == "frac_w" ){
	  frac_weighted = sval.Atof();
	}

	if( skey == "thresh_ccor_min" ){
	  thresh_ccor_min = sval.Atof();
	}

	if( skey == "thresh_ccor_max" ){
	  thresh_ccor_max = sval.Atof();
	}

	if( skey == "thresh_ccor_min_uw" ){
	  thresh_ccor_min_uw = sval.Atof();
	}

	if( skey == "thresh_ccor_max_uw" ){
	  thresh_ccor_max_uw = sval.Atof();
	}

	//	if( skey == "minevents" ){
	//minevents = sval.Atoi();
	//}

	if( skey == "skipmodules" ){
	  for( int i=1; i<ntokens; i++ ){
	    TString sval_i = ( (TObjString*) (*tokens)[i] )->GetString();
	    skipmodules.insert(sval_i.Atoi());
	  }
	}
      }
    }
  }

  C->SetBranchStatus("*",0);
  C->SetBranchStatus("g.*",1);

  double g_runnum, g_evtime; //evtime gives us trigger phase. run number may come in handy later
  C->SetBranchAddress("g.runnum",&g_runnum);
  C->SetBranchAddress("g.evtime",&g_evtime);
  
  //We mainly need GEM and spectrometer-level track and hit branches (and some ancillary calorimeter branches):

  //only do one tracker at a time here (slightly inefficient)
  //int ntracker=1;
  int nmodules = 8; //default to 8 modules per tracker
  

  //Default is "gmn_v3" (BigBite with 8 modules):

  //Check for valid combination of tracker name and experiment name: 
  
  if( expname.EqualTo("gmn_v1") ){ //only allowed tracker names for GMN are bb.gem
    nmodules = 12; //GMN version 1 with 12 modules: 2 UV + 6 INFN + 4 X/Y
    trackername = "bb.gem";
  }
  if( expname.EqualTo("gmn_v2") ){
    nmodules = 10; //GMN version two with ten modules: 3 UV + 3 INFN + 4 X/Y
    trackername = "bb.gem";
  }
  if( expname.EqualTo("gmn_v3") ){
    nmodules = 8;
    trackername = "bb.gem";
  }

  if( expname.EqualTo("gen") ){
    if( trackername.EqualTo("bb.gem") ){
      nmodules = 8;
    } else if( trackername.EqualTo("sbs.gem") ){
      nmodules = 30; //SBS GEM with 30 modules (although modules 0-5 are never functional)
    } else {
      cout << "Incorrect combination of experiment and tracker, for gen experiment allowed tracker names are bb.gem, sbs.gem" << endl
	   << "FIX config file!" << endl;
      exit(-1);
    }
  }

  if( expname.EqualTo("genrp") ){
    if( trackername.EqualTo("bb.gem") ){
      nmodules = 8;
    } else if( trackername.EqualTo("sbs.gem") ){
      nmodules = 34;
    } else if( trackername.EqualTo("sbs.gemCeF") ){
      nmodules = 10;
    } else if( trackername.EqualTo("sbs.gemCeR") ){
      nmodules = 16;
    } else {
      cout << "Incorrect combination of experiment and tracker, for genrp experiment allowed tracker names are bb.gem, sbs.gem (for Straight-through runs, sbs.gemCeF, and sbs.gemCeR" << endl
	   << "FIX config file!" << endl;
      exit(-1);
    }
    
  }
   

  if( expname.EqualTo("gep") ){
    if( trackername.EqualTo("sbs.gemFT") ){
      nmodules = 14; //2 X/W + 4 U/V + 8 X/Y
    } else if( trackername.EqualTo("sbs.gemFPP") ){
      nmodules = 32; //8 layers of 4 X/Y each
    } else {
      cout << "Incorrect combination of experiment and tracker, for gep experiment allowed tracker names are sbs.gemFT and sbs.gemFPP" << endl
	   << "FIX config file!" << endl;
      exit(-1);
    }
    
  }
    
  
  //We'll start with just the GMN options, deal with the other configs later: 
  // switch(expname.Data()){
  // case gmn_v1: //BigBite GEMs with 12 modules (SBS-4, SBS-7)
  //   nmodules = 12;
  //   trackername = "bb.gem";
  //   break;
  // case gmn_v2: //BigBite GEMs with 10 modules (SBS-11)
  //   nmodules = 10;
  //   trackername = "bb.gem";
  //   break;
  // case gmn_v3: //BigBite GEMs with 8 modules (SBS-14/8/9)
  // default: 
  //   cout << "warning: experiment not recognized, allowed options are:" << endl
  // 	 << "gmn_v1: BigBite GEMs during GMN, 12-module configuration (SBS-4,7 kinematics)" << endl
  // 	 << "gmn_v2: BigBite GEMs during GMN, 10-module configuration (SBS-11 kinematics)" << endl
  // 	 << "gmn_v3: BigBite GEMs during GMN, 8-module configuration (SBS-14,8,9 kinematics and default)" << endl
  // 	 << "gen-BB: BigBite GEMs during GEN-II, 8-module (same as default)" << endl
  // 	 << "gen-SBS: SBS GEMs during GEN-II, 30-modules (six INFN plus 24 X/Y)" << endl
  // 	 << "genrp-BB: BigBite GEMs during GEN-RP, 8-module (same as default)" << endl
  // 	 << "genrp-SBSFT: SBS front inline tracker during GEN-RP, 10 modules (two X/W plus 8 X/Y)" << endl
  // 	 << "genrp-SBSFPP: SBS back inline tracker during GEN-RP, 16 modules (four X/Y layers)" << endl
  // 	 << "genrp-SBSST: SBS Straight-through during GEN-RP (26 modules, 8 layers treated as single tracker)" << endl
  // 	 << "gepFT: GEP front tracker (14 modules (two X/W plus 4 U/V plus two X/Y layers))" << endl
  // 	 << "gepFPP: GEP back tracker (32 modules (8 X/Y layers))" << endl
  // 	 << "falling back to gmn_v3" << endl;
    
  //   nmodules = 8;
  //   trackername = "bb.gem";
  //   break;
  // }
  

  if( expname != "gep" ){
    //Activate needed BigBite branches other than GEM track and hit branches that might be used by global cut; 
    C->SetBranchStatus("bb.tr.*",1);
    C->SetBranchStatus("bb.ps.e",1);
    C->SetBranchStatus("bb.sh.e",1);
    C->SetBranchStatus("bb.etot_over_p",1);
    C->SetBranchStatus("bb.ps.atimeblk",1);
    C->SetBranchStatus("bb.sh.atimeblk",1);
    C->SetBranchStatus("bb.grinch_tdc.clus.*",1);
    C->SetBranchStatus("bb.hodotdc.clus.*",1);
    C->SetBranchStatus("bb.x_fcp",1);
    C->SetBranchStatus("bb.y_fcp",1);
    C->SetBranchStatus("bb.z_fcp",1);
    C->SetBranchStatus("bb.x_bcp",1);
    C->SetBranchStatus("bb.y_bcp",1);
    C->SetBranchStatus("bb.z_bcp",1);
  }

  if( expname == "gep" ){ //activate relevant ECAL and "heep" branches:
    C->SetBranchStatus("heep.*",1);
    C->SetBranchStatus("earm.ecal.x",1);
    C->SetBranchStatus("earm.ecal.y",1);
    C->SetBranchStatus("earm.ecal.nblk",1);
    C->SetBranchStatus("earm.ecal.nclus",1);
    C->SetBranchStatus("earm.ecal.atimeblk");
    C->SetBranchStatus("earm.ecal.e",1);
    //We may add others later...
  }
    
  if( !expname.BeginsWith("gmn") ){
    C->SetBranchStatus("sbs.tr.*",1);
  }
  

  //HCAL/SBS branches we always want to include:
  C->SetBranchStatus("sbs.hcal.e",1);
  C->SetBranchStatus("sbs.hcal.atimeblk",1);
  C->SetBranchStatus("sbs.hcal.nblk",1);
  C->SetBranchStatus("sbs.hcal.nclus",1);
  C->SetBranchStatus("sbs.hcal.x",1);
  C->SetBranchStatus("sbs.hcal.y",1);
  C->SetBranchStatus("sbs.HCALdir_*",1);
  C->SetBranchStatus("sbs.HCALth_n",1);
  C->SetBranchStatus("sbs.HCALph_n",1);  

  if( trackername.BeginsWith("sbs") ){ //Activate SBS constraint branches:
    C->SetBranchStatus("sbs.x_fcp",1);
    C->SetBranchStatus("sbs.y_fcp",1);
    C->SetBranchStatus("sbs.z_fcp",1);
    C->SetBranchStatus("sbs.x_bcp",1);
    C->SetBranchStatus("sbs.y_bcp",1);
    C->SetBranchStatus("sbs.z_bcp",1);
    if( expname == "gep" ){ //also activate the FT and FPP constraint branches:
      C->SetBranchStatus("sbs.x_fcp_FT",1);
      C->SetBranchStatus("sbs.y_fcp_FT",1);
      C->SetBranchStatus("sbs.z_fcp_FT",1);
      C->SetBranchStatus("sbs.x_bcp_FT",1);
      C->SetBranchStatus("sbs.y_bcp_FT",1);
      C->SetBranchStatus("sbs.z_bcp_FT",1);

      C->SetBranchStatus("sbs.x_fcp_FPP",1);
      C->SetBranchStatus("sbs.y_fcp_FPP",1);
      C->SetBranchStatus("sbs.z_fcp_FPP",1);
      C->SetBranchStatus("sbs.x_bcp_FPP",1);
      C->SetBranchStatus("sbs.y_bcp_FPP",1);
      C->SetBranchStatus("sbs.z_bcp_FPP",1);
    }
  }

  const int MAXNTRACKS = 10;
  const int MAXNHITS = 8*MAXNTRACKS;


  //Which branches are necessary for this analysis?
  // Let's make histograms first:

  int nhistos = 6*nmodules; //one for each trigger phase value

  //Question: should we do this for the max. strip only, or for the cluster sum? Why not both?
  //BECAUSE the cluster-summed time samples do not actually exist in the standard tracker "hit" outputs!
  TClonesArray *histos_ADCfrac_trigphase_maxUstrip = new TClonesArray( "TH2D", nhistos );
  TClonesArray *histos_ADCfrac_trigphase_maxVstrip = new TClonesArray( "TH2D", nhistos );
  //ADC frac vs trigger phase for different time samples:
  TClonesArray *histos_ADCfrac_timesamp_maxUstrip = new TClonesArray( "TH2D", nhistos );
  TClonesArray *histos_ADCfrac_timesamp_maxVstrip = new TClonesArray( "TH2D", nhistos );
  // TClonesArray *histos_ADCfrac_tphase_clsumU = new TClonesArray( "TH2D", nhistos );
  // TClonesArray *histos_ADCfrac_tphase_clsumV = new TClonesArray( "TH2D", nhistos );
  
  for( int ihist=0; ihist<nhistos; ihist++ ){
    TString prefix = trackername;
    prefix.ReplaceAll(".","_");

    int imod = ihist/6;
    int iphase = ihist%6;
    
    TString histname = Form( "hADCfrac_vs_timesample_maxUstrip_%s_mod%d_phase%d", prefix.Data(), imod, iphase);

    new( (*histos_ADCfrac_timesamp_maxUstrip)[ihist] ) TH2D(histname.Data(), Form("%s module %d phase %d (max U strip); time sample; ADC fraction", trackername.Data(), imod, iphase), 6, -0.5, 5.5, 400,-1.0,1.0);

    histname.Form( "hADCfrac_vs_timesample_maxVstrip_%s_mod%d_phase%d", prefix.Data(), imod, iphase );
    new( (*histos_ADCfrac_timesamp_maxVstrip)[ihist] ) TH2D(histname.Data(), Form("%s module %d phase %d (max V strip); time sample; ADC fraction", trackername.Data(), imod, iphase), 6, -0.5, 5.5, 400,-1.0,1.0);

    histname.Form( "hADCfrac_vs_trigphase_maxUstrip_%s_mod%d_samp%d", prefix.Data(), imod, iphase );
    new( (*histos_ADCfrac_trigphase_maxUstrip)[ihist] ) TH2D(histname.Data(), Form("%s module %d time sample %d (max U strip); trigger phase ; ADC fraction",trackername.Data(), imod, iphase), 6, -0.5, 5.5, 400, -1.0, 1.0);

    histname.Form( "hADCfrac_vs_trigphase_maxVstrip_%s_mod%d_samp%d", prefix.Data(), imod, iphase );
    new( (*histos_ADCfrac_trigphase_maxVstrip)[ihist] ) TH2D(histname.Data(), Form("%s module %d time sample %d (max V strip); trigger phase ; ADC fraction",trackername.Data(), imod, iphase), 6, -0.5, 5.5, 400, -1.0, 1.0);
    
    //Also make histos of fraction vs trigger phase in time sample i:
    
    
    // histname.Form( "hADCfrac_vs_timesample_clsumU_%s_mod%d_phase%d", prefix, imod, iphase );
    // new( (*histos_ADCfrac_tphase_clsumU)[ihist] ) TH2D(histname.Data(), Form("%s module %d phase %d (U cluster sum); time sample; ADC fraction", trackername.Data(), imod, iphase), 6, -0.5, 5.5, 400,-1.0,1.0);

    // histname.Form( "hADCfrac_vs_timesample_clsumV_%s_mod%d_phase%d", prefix, imod, iphase );
    // new( (*histos_ADCfrac_tphase_clsumV)[ihist] ) TH2D(histname.Data(), Form("%s module %d phase %d (V cluster sum); time sample; ADC fraction", trackername.Data(), imod, iphase), 6, -0.5, 5.5, 400,-1.0,1.0);
    
  }
  
  //Now activate GEM track and hit branches and set branch addresses:

  //To keep it simple, we only allow this to run for one "tracker" at a time: 
  C->SetBranchStatus(Form("%s.track.*",trackername.Data()),1);
  C->SetBranchStatus(Form("%s.hit.*",trackername.Data()),1);

  if( expname.EqualTo("gep") ){
    //in GEP case, activate FT (FPP) track and hit branches for FPP (FT):
    if( trackername.EqualTo("sbs.gemFPP") ){
      //also activate FT branches:
      C->SetBranchStatus("sbs.gemFT.track.*",1);
      C->SetBranchStatus("sbs.gemFT.hit.*",1);
    }
    if( trackername.EqualTo("sbs.gemFT") ){
      C->SetBranchStatus("sbs.gemFPP.track.*",1);
      C->SetBranchStatus("sbs.gemFPP.hit.*",1);
    }
  }
      
    
  
  //Now: branches we actually need to set addresses for:
  double hit_ADCmaxstripU[MAXNHITS];
  double hit_ADCmaxstripV[MAXNHITS];
  double hit_ADCasym[MAXNHITS];
  //double hit_ccor_clust[MAXNHITS];
  double hit_ccor_strip[MAXNHITS];
  double hit_module[MAXNHITS];
  double hit_trackindex[MAXNHITS];
  double hit_ngoodhits; 

  double hit_nstripu[MAXNHITS];
  double hit_nstripv[MAXNHITS];
  
  double hit_ADCU[MAXNHITS];
  double hit_ADCV[MAXNHITS];
  
  double hit_ADCfrac0_Umax[MAXNHITS];
  double hit_ADCfrac1_Umax[MAXNHITS];
  double hit_ADCfrac2_Umax[MAXNHITS];
  double hit_ADCfrac3_Umax[MAXNHITS];
  double hit_ADCfrac4_Umax[MAXNHITS];
  double hit_ADCfrac5_Umax[MAXNHITS];

  //double hit_ADCfrac_Umax[6*MAXNHITS]; //test
  
  double hit_ADCfrac0_Vmax[MAXNHITS];
  double hit_ADCfrac1_Vmax[MAXNHITS];
  double hit_ADCfrac2_Vmax[MAXNHITS];
  double hit_ADCfrac3_Vmax[MAXNHITS];
  double hit_ADCfrac4_Vmax[MAXNHITS];
  double hit_ADCfrac5_Vmax[MAXNHITS];

  double track_ntrack, track_nhits[MAXNTRACKS], track_chi2ndf[MAXNTRACKS];

  // The way this is currently written, we should be good to go on activating all the branches we need and setting all the branch addresses we need
  
  //double hit_ADCfrac_Vmax[6*MAXNHITS]; //test
  C->SetBranchAddress(Form("%s.track.ntrack",trackername.Data()), &track_ntrack );
  C->SetBranchAddress(Form("%s.track.nhits",trackername.Data()), track_nhits);
  C->SetBranchAddress(Form("%s.track.chi2ndf",trackername.Data()), track_chi2ndf);

  
  C->SetBranchAddress(Form("%s.hit.ngoodhits",trackername.Data()), &hit_ngoodhits);
  C->SetBranchAddress(Form("%s.hit.trackindex",trackername.Data()), hit_trackindex);
  C->SetBranchAddress(Form("%s.hit.ADCmaxstripU", trackername.Data()), hit_ADCmaxstripU );
  C->SetBranchAddress(Form("%s.hit.ADCmaxstripV", trackername.Data()), hit_ADCmaxstripV );
  C->SetBranchAddress(Form("%s.hit.ADCasym", trackername.Data()), hit_ADCasym );
  C->SetBranchAddress(Form("%s.hit.ccor_strip", trackername.Data()), hit_ccor_strip );
  C->SetBranchAddress(Form("%s.hit.module", trackername.Data()), hit_module );
  C->SetBranchAddress(Form("%s.hit.nstripu", trackername.Data()), hit_nstripu );
  C->SetBranchAddress(Form("%s.hit.nstripv", trackername.Data()), hit_nstripv );
  C->SetBranchAddress(Form("%s.hit.ADCU", trackername.Data()), hit_ADCU );
  C->SetBranchAddress(Form("%s.hit.ADCV", trackername.Data()), hit_ADCV );

  C->SetBranchAddress(Form("%s.hit.ADCfrac0_Umax", trackername.Data()), hit_ADCfrac0_Umax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac1_Umax", trackername.Data()), hit_ADCfrac1_Umax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac2_Umax", trackername.Data()), hit_ADCfrac2_Umax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac3_Umax", trackername.Data()), hit_ADCfrac3_Umax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac4_Umax", trackername.Data()), hit_ADCfrac4_Umax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac5_Umax", trackername.Data()), hit_ADCfrac5_Umax);

  C->SetBranchAddress(Form("%s.hit.ADCfrac0_Vmax", trackername.Data()), hit_ADCfrac0_Vmax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac1_Vmax", trackername.Data()), hit_ADCfrac1_Vmax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac2_Vmax", trackername.Data()), hit_ADCfrac2_Vmax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac3_Vmax", trackername.Data()), hit_ADCfrac3_Vmax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac4_Vmax", trackername.Data()), hit_ADCfrac4_Vmax);
  C->SetBranchAddress(Form("%s.hit.ADCfrac5_Vmax", trackername.Data()), hit_ADCfrac5_Vmax);


  long nevent=0;
  int treenum=-1, oldtreenum=-1;

  int runnum = -1, oldrunnum = -1;
  
  while( C->GetEntry(nevent++) ){
    if( nevent % 1000 == 0 ) cout << "Event " << nevent << endl;

    treenum = C->GetTreeNumber();
    if( treenum != oldtreenum ){
      GlobalCut->UpdateFormulaLeaves();
      oldtreenum = treenum;
      cout << "New file, (treenum,fname)=(" << treenum << ", " << C->GetFile()->GetName() << endl;
    }

    runnum = int(g_runnum);

    if( runnum != oldrunnum ){
      cout << "Starting run number " << runnum << endl;
      oldrunnum = runnum;
    }
    
    bool passed_cut = GlobalCut->EvalInstance(0) != 0;
    if( passed_cut ){ //loop on GEM hits and fill histograms:
      int ntracks = int(track_ntrack);
      if( ntracks > 0 ){ //loop on the hits:

	long evtime = long(g_evtime);
	int trigphase = evtime%6;

	//cout << "g_evtime, evtime, Trigger phase = (" << g_evtime << ", " << evtime << ", " << trigphase << ")" << endl;
	
	int nhits = int(hit_ngoodhits);
	for( int ihit=0; ihit<nhits; ihit++ ){
	  int tridx = int(hit_trackindex[ihit]);
	  if( tridx == 0 && hit_ccor_strip[ihit] >= 0.5 && hit_nstripu[ihit] > 1 && hit_nstripv[ihit] > 1
	      && track_nhits[0]>3 && track_chi2ndf[0]<15.0 ){
	    int module = int(hit_module[ihit]);
	    int nstripu = int(hit_nstripu[ihit]);
	    int nstripv = int(hit_nstripv[ihit]);

	    int histidx = 6*module + trigphase;

	    //Is it a good idea to weight by amplitude when filling these histos? Maybe! Let's try it out! 
	    double weightU = hit_ADCmaxstripU[ihit];
	    double weightV = hit_ADCmaxstripV[ihit];

	    weightU = 1.0;
	    weightV = 1.0;
	    
	    if( histidx >= 0 && histidx < nhistos ){
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxUstrip)[histidx] )->Fill( 0., hit_ADCfrac0_Umax[ihit], weightU );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxUstrip)[histidx] )->Fill( 1., hit_ADCfrac1_Umax[ihit], weightU );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxUstrip)[histidx] )->Fill( 2., hit_ADCfrac2_Umax[ihit], weightU );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxUstrip)[histidx] )->Fill( 3., hit_ADCfrac3_Umax[ihit], weightU );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxUstrip)[histidx] )->Fill( 4., hit_ADCfrac4_Umax[ihit], weightU );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxUstrip)[histidx] )->Fill( 5., hit_ADCfrac5_Umax[ihit], weightU );

	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxVstrip)[histidx] )->Fill( 0., hit_ADCfrac0_Vmax[ihit], weightV );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxVstrip)[histidx] )->Fill( 1., hit_ADCfrac1_Vmax[ihit], weightV );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxVstrip)[histidx] )->Fill( 2., hit_ADCfrac2_Vmax[ihit], weightV );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxVstrip)[histidx] )->Fill( 3., hit_ADCfrac3_Vmax[ihit], weightV );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxVstrip)[histidx] )->Fill( 4., hit_ADCfrac4_Vmax[ihit], weightV );
	      ( (TH2D*) (*histos_ADCfrac_timesamp_maxVstrip)[histidx] )->Fill( 5., hit_ADCfrac5_Vmax[ihit], weightV );

	    }

	    //Now for fixed time sample, fill ADC frac vs trig phase:
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxUstrip)[6*module] )->Fill( trigphase, hit_ADCfrac0_Umax[ihit], weightU );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxUstrip)[6*module+1] )->Fill( trigphase, hit_ADCfrac1_Umax[ihit], weightU );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxUstrip)[6*module+2] )->Fill( trigphase, hit_ADCfrac2_Umax[ihit], weightU );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxUstrip)[6*module+3] )->Fill( trigphase, hit_ADCfrac3_Umax[ihit], weightU );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxUstrip)[6*module+4] )->Fill( trigphase, hit_ADCfrac4_Umax[ihit], weightU );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxUstrip)[6*module+5] )->Fill( trigphase, hit_ADCfrac5_Umax[ihit], weightU );

	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxVstrip)[6*module] )->Fill( trigphase, hit_ADCfrac0_Vmax[ihit], weightV );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxVstrip)[6*module+1] )->Fill( trigphase, hit_ADCfrac1_Vmax[ihit], weightV );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxVstrip)[6*module+2] )->Fill( trigphase, hit_ADCfrac2_Vmax[ihit], weightV );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxVstrip)[6*module+3] )->Fill( trigphase, hit_ADCfrac3_Vmax[ihit], weightV );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxVstrip)[6*module+4] )->Fill( trigphase, hit_ADCfrac4_Vmax[ihit], weightV );
	    ( (TH2D*) (*histos_ADCfrac_trigphase_maxVstrip)[6*module+5] )->Fill( trigphase, hit_ADCfrac5_Vmax[ihit], weightV );
	    
	  }
	}

      }

    }
  }

  // Now, what are the next steps? We'll need to loop on all the histograms, and accumulate either the mean and standard deviation directly from the histogram, or from a fit to the peak, for each trigger phase value for each module.
  // Then, we'll do a second loop over the data and calculate the correlation coefficient (and perhaps chi^2 or likelihood score) of each hit wrt its "expected" shape.

  //Total number of parameters needed = nmodules * 36 (6 time samples * 6 trigger phases) * 2 (U and V strips) * 2 (mean and sigma)

  vector<double> fracmeanU(nmodules*36,0.0), fracmeanV(nmodules*36,0.0), fracsigmaU(nmodules*36,0.0), fracsigmaV(nmodules*36,0.0); //inner index = trigger phase, 

  //Plots: 

  TCanvas *c1 = new TCanvas("c1","c1",1800,1200);
  c1->Divide(6,4,.001,.001);

  TString pdffilename = outfilename;
  pdffilename.ReplaceAll(".root",".pdf");

  //Now, which ones should we fit? It doesn't really matter, but I'm going to go with fitting the "fraction vs time sample" graphs for each trigger phase value:
  
  for( int imod=0; imod<nmodules; imod++ ){

    if( skipmodules.find(imod) != skipmodules.end() ) continue;
    
    TGraphErrors *gtempU, *gtempV; 
    
    for( int iphase=0; iphase<6; iphase++ ){
      c1->cd(1+iphase);
      ( (TH2D*) (*histos_ADCfrac_timesamp_maxUstrip)[6*imod+iphase] )->Draw("colz");

      TH2D &hprojU = *( (TH2D*) (*histos_ADCfrac_timesamp_maxUstrip)[6*imod+iphase] );

      double xtemp[6],ytemp[6], extemp[6], eytemp[6];
      
      for( int isamp=0; isamp<6; isamp++ ){
	xtemp[isamp] = isamp;
	extemp[isamp] = 0.0;
	
	TH1D *htemp = hprojU.ProjectionY(Form("%s_samp%d",hprojU.GetName(), isamp), isamp+1,isamp+1);
	
	auto fitresult = FitGaus_FWHM( htemp, 0.4 );

	double mean = ( (TF1*) htemp->GetListOfFunctions()->FindObject("gaus") )->GetParameter("Mean");
	double sigma = ( (TF1*) htemp->GetListOfFunctions()->FindObject("gaus") )->GetParameter("Sigma");

	ytemp[isamp] = mean;
	eytemp[isamp] = sigma;

	fracmeanU[36*imod+6*iphase+isamp] = mean;
	fracsigmaU[36*imod+6*iphase+isamp] = sigma;
      }

      gtempU = new TGraphErrors(6,xtemp,ytemp,extemp,eytemp);
      gtempU->SetMarkerColor(6);
      gtempU->SetMarkerStyle(20);
      gtempU->SetLineColor(6);
      gtempU->Draw("PZSAME");
      
      c1->cd(7+iphase);
      ( (TH2D*) (*histos_ADCfrac_timesamp_maxVstrip)[6*imod+iphase] )->Draw("colz");

      TH2D &hprojV = *( (TH2D*) (*histos_ADCfrac_timesamp_maxVstrip)[6*imod+iphase] );

      for( int isamp=0; isamp<6; isamp++ ){
	TH1D *htemp = hprojV.ProjectionY(Form("%s_samp%d",hprojV.GetName(), isamp), isamp+1,isamp+1);
	auto fitresult = FitGaus_FWHM( htemp, 0.4 );

	double mean = ( (TF1*) htemp->GetListOfFunctions()->FindObject("gaus") )->GetParameter("Mean");
	double sigma = ( (TF1*) htemp->GetListOfFunctions()->FindObject("gaus") )->GetParameter("Sigma");

	ytemp[isamp] = mean;
	eytemp[isamp] = sigma;

	fracmeanV[36*imod+6*iphase+isamp] = mean;
	fracsigmaV[36*imod+6*iphase+isamp] = sigma;
      }

      gtempV = new TGraphErrors(6,xtemp,ytemp,extemp,eytemp);
      gtempV->SetMarkerColor(6);
      gtempV->SetMarkerStyle(20);
      gtempV->SetLineColor(6);
      gtempV->Draw("PZSAME");
      
    }
    for( int isamp=0; isamp<6; isamp++ ){
      double xtemp[6],ytemp[6], extemp[6], eytemp[6];
      
      c1->cd(13+isamp);
      ( (TH2D*) (*histos_ADCfrac_trigphase_maxUstrip)[6*imod+isamp] )->Draw("colz");

      for( int iphase=0; iphase<6; iphase++ ){
	xtemp[iphase] = iphase;
	extemp[iphase] = 0.0;
	ytemp[iphase] = fracmeanU[36*imod+6*iphase+isamp];
	eytemp[iphase] = fracsigmaU[36*imod+6*iphase+isamp];
      }

      gtempU = new TGraphErrors(6,xtemp,ytemp,extemp,eytemp);
      gtempU->SetMarkerColor(6);
      gtempU->SetMarkerStyle(20);
      gtempU->SetLineColor(6);
      gtempU->Draw("PZSAME");
      
      c1->cd(19+isamp);
      ( (TH2D*) (*histos_ADCfrac_trigphase_maxVstrip)[6*imod+isamp] )->Draw("colz");

      for( int iphase=0; iphase<6; iphase++ ){
	ytemp[iphase] = fracmeanV[36*imod+6*iphase+isamp];
	eytemp[iphase] = fracsigmaV[36*imod+6*iphase+isamp];
      }

      gtempV = new TGraphErrors(6,xtemp,ytemp,extemp,eytemp);
      gtempV->SetMarkerColor(6);
      gtempV->SetMarkerStyle(20);
      gtempV->SetLineColor(6);
      gtempV->Draw("PZSAME");
      
    }

    gPad->Modified();
    c1->Update();
    gSystem->ProcessEvents();
    
    TString printname = pdffilename;
    if( imod == 0 ) printname += "(";
    //if( imod+1==nmodules ) printname += ")"; // to be commented later when we add more pages

    c1->Print(printname);
  }

  //Set up histograms for loop 2 (calculate weighted correlation coefficient between pulse shape and "expected" pulse shape:

  TClonesArray *histos_ccor_vs_trigphase_maxstripU = new TClonesArray( "TH2D", nmodules );
  TClonesArray *histos_ccor_vs_trigphase_maxstripV = new TClonesArray( "TH2D", nmodules );

  TClonesArray *histos_ccor_unweighted_vs_trigphase_maxstripU = new TClonesArray( "TH2D", nmodules );
  TClonesArray *histos_ccor_unweighted_vs_trigphase_maxstripV = new TClonesArray( "TH2D", nmodules );

  for( int ihist=0; ihist<nmodules; ihist++ ){


    int imod = ihist;
    //   int iphase = ihist%6;
    
    TString prefix = trackername;
    prefix.ReplaceAll(".","_");
    TString histname;
    histname.Form("hccor_vs_trigphase_maxUstrip_%s_mod%d", prefix.Data(), imod);

    new( (*histos_ccor_vs_trigphase_maxstripU)[ihist] ) TH2D( histname.Data(), Form( "%s module %d (max U strip); trigger phase ; Corr. Coeff. (weighted)", prefix.Data(), imod), 6,-0.5,5.5, 400, -1.0, 1.0 );

    histname.Form("hccor_vs_trigphase_maxVstrip_%s_mod%d", prefix.Data(), imod );

    new( (*histos_ccor_vs_trigphase_maxstripV)[ihist] ) TH2D( histname.Data(), Form( "%s module %d (max V strip); trigger phase ; Corr. Coeff. (weighted)", prefix.Data(), imod), 6,-0.5,5.5, 400, -1.0, 1.0 );

    histname.Form("hccor_unweighted_vs_trigphase_maxUstrip_%s_mod%d", prefix.Data(), imod);

    new( (*histos_ccor_unweighted_vs_trigphase_maxstripU)[ihist] ) TH2D( histname.Data(), Form( "%s module %d (max U strip); trigger phase ; Corr. Coeff. (un-weighted)", prefix.Data(), imod ), 6,-0.5,5.5, 400, -1.0, 1.0 );

    histname.Form("hccor_unweighted_vs_trigphase_maxVstrip_%s_mod%d", prefix.Data(), imod );

    new( (*histos_ccor_unweighted_vs_trigphase_maxstripV)[ihist] ) TH2D( histname.Data(), Form( "%s module %d (max V strip); trigger phase ; Corr. Coeff. (un-weighted)", prefix.Data(), imod ), 6,-0.5,5.5, 400, -1.0, 1.0 );
    
  }
  
  
  //Start loop 2: calculate weighted correlation coefficient of each hit (technically the max U and V strips)
  nevent = 0;

  treenum=-1;
  oldtreenum=-1;

  cout << "Starting Loop 2: calculate weighted correlation coefficient of each hit with expected pulse shape: " << endl;

  //A relevant question: should we also weight by amplitude when we fill the corr. coeff histograms? Maybe...
  
  
  while( C->GetEntry(nevent++) ){
    if( nevent % 1000 == 0 ) cout << "Event " << nevent << endl;

    treenum = C->GetTreeNumber();
    if( treenum != oldtreenum ){
      GlobalCut->UpdateFormulaLeaves();
      oldtreenum = treenum;
    }

    bool passed_cut = GlobalCut->EvalInstance(0) != 0;
    if( passed_cut ){
      int ntracks = int(track_ntrack);
      if( ntracks > 0 ){ //loop on the hits on the best track:
	long evtime = long(g_evtime);
	int trigphase = evtime % 6;

	int nhits = int(hit_ngoodhits);
	for( int ihit=0; ihit<nhits; ihit++ ){
	  int tridx = int(hit_trackindex[ihit]);
	  if( tridx == 0 && hit_ccor_strip[ihit] >= 0.5 && hit_nstripu[ihit] > 1 && hit_nstripv[ihit] > 1
	      && track_nhits[0] > 3 && track_chi2ndf[0] < 10.0 ){

	    double hitweightU = hit_ADCmaxstripU[ihit];
	    double hitweightV = hit_ADCmaxstripV[ihit];
	    
	    int module = int(hit_module[ihit]);
	    int histidx = module;

	    vector<double> sampU(6), sampV(6);
	    vector<double> sampU_expect(6), sampV_expect(6);
	    vector<double> weightU(6), weightV(6);
	    vector<double> weight1(6,1.0);
	    
	    sampU[0] = hit_ADCfrac0_Umax[ihit];
	    sampU[1] = hit_ADCfrac1_Umax[ihit];
	    sampU[2] = hit_ADCfrac2_Umax[ihit];
	    sampU[3] = hit_ADCfrac3_Umax[ihit];
	    sampU[4] = hit_ADCfrac4_Umax[ihit];
	    sampU[5] = hit_ADCfrac5_Umax[ihit];

	    sampV[0] = hit_ADCfrac0_Vmax[ihit];
	    sampV[1] = hit_ADCfrac1_Vmax[ihit];
	    sampV[2] = hit_ADCfrac2_Vmax[ihit];
	    sampV[3] = hit_ADCfrac3_Vmax[ihit];
	    sampV[4] = hit_ADCfrac4_Vmax[ihit];
	    sampV[5] = hit_ADCfrac5_Vmax[ihit];

	    double sumW_U = 0.0, sumW_V = 0.0;
	    double sumU = 0.0, sumV = 0.0, sum2_U = 0.0, sum2_V = 0.0;
	    double sumU_expect = 0.0, sumV_expect = 0.0, sum2_U_expect = 0.0, sum2_V_expect = 0.0;
	    double sumUUexp = 0.0, sumVVexp = 0.0;

	    
	    
	    for( int isamp=0; isamp<6; isamp++ ){
	      sampU_expect[isamp] = fracmeanU[36*module+6*trigphase+isamp];
	      sampV_expect[isamp] = fracmeanV[36*module+6*trigphase+isamp];
	      
	      weightU[isamp] = pow( fracsigmaU[36*module+6*trigphase+isamp], -2 );
	      weightV[isamp] = pow( fracsigmaV[36*module+6*trigphase+isamp], -2 );

	      sumW_U += weightU[isamp];
	      sumW_V += weightV[isamp];
	      
	      sumU += weightU[isamp]*sampU[isamp];
	      sumV += weightV[isamp]*sampV[isamp];

	      sum2_U += weightU[isamp]*pow(sampU[isamp],2);
	      sum2_V += weightV[isamp]*pow(sampV[isamp],2);
	      
	      sumU_expect += weightU[isamp]*sampU_expect[isamp];
	      sumV_expect += weightV[isamp]*sampV_expect[isamp];

	      sum2_U_expect += weightU[isamp]*pow(sampU_expect[isamp],2);
	      sum2_V_expect += weightV[isamp]*pow(sampV_expect[isamp],2);

	      //now for the all-important covariance terms:
	      sumUUexp += weightU[isamp]*sampU_expect[isamp]*sampU[isamp];
	      sumVVexp += weightV[isamp]*sampV_expect[isamp]*sampV[isamp];
	    }

	    // double meanU = sumU/sumW_U, meanU_expect = sumU_expect/sumW_U;
	    // double meanV = sumV/sumW_V, meanV_expect = sumV_expect/sumW_V;
	    // double varU = sum2_U/sumW_U - pow(meanU,2), varU_expect = sum2_U_expect/sumW_U - pow(meanU_expect,2);
	    // double varV = sum2_V/sumW_V - pow(meanV,2), varV_expect = sum2_V_expect/sumW_V - pow(meanV_expect,2);
	    // double sigU = sqrt(varU), sigU_expect = sqrt(varU_expect);
	    // double sigV = sqrt(varV), sigV_expect = sqrt(varV_expect);
	    
	    // double ccor_U = (sumUUexp - sumW_U*meanU*meanU_expect)/(sumW_U*sigU*sigU_expect);
	    // double ccor_V = (sumVVexp - sumW_V*meanV*meanV_expect)/(sumW_V*sigV*sigV_expect);

	    double ccor_U = CorrCoeff( 6, sampU, sampU_expect, weightU );
	    double ccor_V = CorrCoeff( 6, sampV, sampV_expect, weightV );

	    double ccor_U_unweighted = CorrCoeff( 6, sampU, sampU_expect, weight1 );
	    double ccor_V_unweighted = CorrCoeff( 6, sampV, sampV_expect, weight1 );
	    

	    //chances are it's a bad idea to weight events by amplitude when filling these histograms; we want to define the threshold based on the distribution for ALL good hits! 

	    //Comment these lines if you want to make the corr. coeff distributions unweighted by amplitude:
	    
	    hitweightU = 1.0;
	    hitweightV = 1.0;
	    
	    if( histidx >= 0 && histidx < nhistos ){
	      ( (TH2D*) (*histos_ccor_vs_trigphase_maxstripU)[histidx] )->Fill( trigphase, ccor_U, hitweightU );
	      ( (TH2D*) (*histos_ccor_vs_trigphase_maxstripV)[histidx] )->Fill( trigphase, ccor_V, hitweightV );

	      ( (TH2D*) (*histos_ccor_unweighted_vs_trigphase_maxstripU)[histidx] )->Fill( trigphase, ccor_U_unweighted, hitweightU );
	      ( (TH2D*) (*histos_ccor_unweighted_vs_trigphase_maxstripV)[histidx] )->Fill( trigphase, ccor_V_unweighted, hitweightV );
	      
     
	    }
	  }
	}
      }
    }
  }

  //Let's do one page per module here:

  //Numbers we need are two "thresholds" per trigger phase value; for unweighted and weighted
  // correlation coefficient. Size of array is nmodule * 2 * 6
  vector<double> threshU_uw(nmodules*6);
  vector<double> threshU_w(nmodules*6);

  vector<double> threshV_uw(nmodules*6);
  vector<double> threshV_w(nmodules*6);

  TLine L;
  L.SetLineColor(2);
  L.SetLineWidth(2);
  
  for( int imod=0; imod<nmodules; imod++ ){

    if( skipmodules.find(imod) != skipmodules.end() ) continue;
    
    TString prefix = trackername;
    prefix.ReplaceAll(".","_");
    
    for( int iphase=0; iphase<6; iphase++ ){

      TString histname;
      
      TH1D *htempU_uw = ( (TH2D*) (*histos_ccor_unweighted_vs_trigphase_maxstripU)[imod] )->ProjectionY( histname.Format("hccor_uw_maxUstrip_%s_mod%d_phase%d",prefix.Data(), imod, iphase), iphase+1, iphase+1 );
      TH1D *htempV_uw = ( (TH2D*) (*histos_ccor_unweighted_vs_trigphase_maxstripV)[imod] )->ProjectionY( histname.Format("hccor_uw_maxVstrip_%s_mod%d_phase%d",prefix.Data(), imod, iphase), iphase+1, iphase+1 );

      TH1D *htempU = ( (TH2D*) (*histos_ccor_vs_trigphase_maxstripU)[imod] )->ProjectionY( histname.Format("hccor_maxUstrip_%s_mod%d_phase%d",prefix.Data(), imod, iphase), iphase+1, iphase+1 );
      TH1D *htempV = ( (TH2D*) (*histos_ccor_vs_trigphase_maxstripV)[imod] )->ProjectionY( histname.Format("hccor_maxVstrip_%s_mod%d_phase%d",prefix.Data(), imod, iphase), iphase+1, iphase+1 );

      
      
      double tot,nbins;

      int binlow;

      //U strips, unweighted:
      nbins = htempU_uw->GetNbinsX();
      tot = htempU_uw->Integral(1,nbins);
      binlow = 1;
      
      while( htempU_uw->Integral(binlow, nbins)/tot > frac_unweighted ){ binlow++; }

      threshU_uw[ iphase+6*imod ] = std::max(thresh_ccor_min_uw, std::min(thresh_ccor_max_uw, htempU_uw->GetBinLowEdge(binlow) ) );

      //V strips, unweighted:
      nbins = htempV_uw->GetNbinsX();
      tot = htempV_uw->Integral(1,nbins);
      binlow = 1;
      
      while( htempV_uw->Integral(binlow, nbins)/tot > frac_unweighted ){ binlow++; }

      threshV_uw[ iphase+6*imod ] = std::max(thresh_ccor_min_uw, std::min(thresh_ccor_max_uw, htempV_uw->GetBinLowEdge(binlow) ) ); //htempV_uw->GetBinLowEdge(binlow);

      
      //U strips, weighted:
      nbins = htempU->GetNbinsX();
      tot = htempU->Integral(1,nbins);
      binlow = 1;
      
      while( htempU->Integral(binlow, nbins)/tot > frac_unweighted ){ binlow++; }

      threshU_w[ iphase+6*imod ] = std::max(thresh_ccor_min, std::min(thresh_ccor_max, htempU->GetBinLowEdge(binlow) ) ); //htempU->GetBinLowEdge(binlow);

      //V strips, weighted: 
      nbins = htempV->GetNbinsX();
      tot = htempV->Integral(1,nbins);
      binlow = 1;
      
      while( htempV->Integral(binlow, nbins)/tot > frac_unweighted ){ binlow++; }

      threshV_w[ iphase+6*imod ] = std::max(thresh_ccor_min, std::min(thresh_ccor_max, htempV->GetBinLowEdge(binlow) ) ); //htempV->GetBinLowEdge(binlow);

      //Plot distributions and thresholds:

      double ymax;
      
      c1->cd(1+iphase)->SetLogy();

      htempU_uw->Draw();

      ymax = htempU_uw->GetBinContent(htempU_uw->GetMaximumBin());

      L.DrawLine( threshU_uw[ iphase+6*imod ], 0, threshU_uw[iphase+6*imod], ymax );

      c1->cd(7+iphase)->SetLogy();
      htempV_uw->Draw();

      ymax = htempV_uw->GetBinContent(htempV_uw->GetMaximumBin());
      L.DrawLine( threshV_uw[ iphase+6*imod ], 0, threshV_uw[iphase+6*imod], ymax );

      c1->cd(13+iphase)->SetLogy();

      htempU->Draw();

      ymax = htempU->GetBinContent(htempU->GetMaximumBin());

      L.DrawLine( threshU_w[ iphase+6*imod ], 0, threshU_w[iphase+6*imod], ymax );

      c1->cd(19+iphase)->SetLogy();
      htempV->Draw();

      ymax = htempV->GetBinContent(htempV->GetMaximumBin());
      L.DrawLine( threshV_w[ iphase+6*imod ], 0, threshV_w[iphase+6*imod], ymax );

      htempU_uw->SetTitle( Form( "%s module %d phase %d max U strip (thresh = %6.4g); Corr. coeff (unweighted);", trackername.Data(), imod, iphase, threshU_uw[iphase+6*imod] ) );
      htempV_uw->SetTitle( Form( "%s module %d phase %d max V strip (thresh = %6.4g); Corr. coeff (unweighted);", trackername.Data(), imod, iphase, threshV_uw[iphase+6*imod] ) );
      htempU->SetTitle( Form( "%s module %d phase %d max U strip (thresh = %6.4g); Corr. coeff (weighted);", trackername.Data(), imod, iphase, threshU_w[iphase+6*imod] ) );
      htempV->SetTitle( Form( "%s module %d phase %d max V strip (thresh = %6.4g); Corr. coeff (weighted);", trackername.Data(), imod, iphase, threshV_w[iphase+6*imod] ) );
      
    }

    gPad->Modified();
    c1->Update();
    gSystem->ProcessEvents();

    TString printname = pdffilename;

    if( imod+1 == nmodules ) printname += ")";

    c1->Print(printname);
    
  }
  
  
  //What are the next step(s)?

  //TO-DO: how to organize database 
  
  // Write out the list of parameters in Podd database-ready format. What should we name the parameters?
  // What parameters are needed? We need, for each module and strip direction, the mean and standard deviation of the ADC fraction by time sample and trigger phase value.
  // therefore, 6 TS *6 trigger phase values *nmodules*2 strip directions * 2 parameters ( mean and std. dev ) = 144 parameters per module

  // something like, appname.detname.TSfrac<U,V>_trigphase_<mean,sigma> = ... (with this naming convention, there will be four different key values defining 36 parameters each; we'll do six rows of six, where each row represents one time sample and each column represents one trigger phase offset:

  TString dbfilename = outfilename;
  dbfilename.ReplaceAll(".root",".dat");

  ofstream dbfile(dbfilename.Data());

  dbfile << "#############################################################################################" << endl
	 << "#                                                                                           #" << endl
	 << "#   Parameters to calculate and apply threshold to (weighted and/or unweighted) GEM strip   #" << endl
	 << "#   correlation with expected shape in the time domain, as a function of trigger phase      #" << endl
	 << "#                                                                                           #" << endl
	 << "#############################################################################################" << endl << endl;
  
  for( int imod=0; imod<nmodules; imod++ ){

    if( skipmodules.find(imod) != skipmodules.end() ) continue;
    
    dbfile << endl << Form("# Parameters for module %d (%s.m%d):", imod, trackername.Data(), imod ) << endl << endl;
    dbfile << Form("%s.m%d.TSfrac_vs_trigphase_Umean = ",trackername.Data(), imod) << endl;
    // First do means:
    for( int isamp=0; isamp<6; isamp++ ){
      for( int iphase=0; iphase<6; iphase++ ){
	dbfile << Form(" %8.5g ", fracmeanU[36*imod+6*iphase+isamp] );
      }
      dbfile << Form("     # time sample %d", isamp ) << endl;
    }
    
    dbfile << endl;

    //Do all the parameters for each module in one continuous section of the DB file:
    dbfile << Form("%s.m%d.TSfrac_vs_trigphase_Vmean = ",trackername.Data(), imod) << endl;
    for( int isamp=0; isamp<6; isamp++ ){
      for( int iphase=0; iphase<6; iphase++ ){
	dbfile << Form(" %8.5g ", fracmeanV[36*imod+6*iphase+isamp] );
      }
      dbfile << Form("     # time sample %d", isamp ) << endl;
    }

    dbfile << endl;

    dbfile << Form("%s.m%d.TSfrac_vs_trigphase_Usigma = ",trackername.Data(), imod) << endl;
    
    //then do sigmas:
    for( int isamp=0; isamp<6; isamp++ ){
      for( int iphase=0; iphase<6; iphase++ ){
	dbfile << Form(" %8.5g ", fracsigmaU[36*imod+6*iphase+isamp] );
      }
      dbfile << Form("     # time sample %d", isamp ) << endl;
    }
    
    dbfile << endl;
    
    //Do all the parameters for each module in one continuous section of the DB file:
    dbfile << Form("%s.m%d.TSfrac_vs_trigphase_Vsigma = ",trackername.Data(), imod) << endl;
    for( int isamp=0; isamp<6; isamp++ ){
      for( int iphase=0; iphase<6; iphase++ ){
	dbfile << Form(" %8.5g ", fracsigmaV[36*imod+6*iphase+isamp] );
      }
      dbfile << Form("     # time sample %d", isamp ) << endl;
    }

    dbfile << endl;

    //Finally, let's do the thresholds. For these we have separate U and V strip thresholds per module and trigger phase value:
    dbfile << Form("%s.m%d.threshU_wTScorr_vs_trigphase = ",trackername.Data(), imod) << endl;
    for( int iphase=0; iphase<6; iphase++ ){
      dbfile << Form(" %8.5g ", threshU_w[iphase+6*imod] );
    }
    dbfile << endl;

    //Finally, let's do the thresholds. For these we have separate U and V strip thresholds per module and trigger phase value:
    dbfile << Form("%s.m%d.threshV_wTScorr_vs_trigphase = ",trackername.Data(), imod) << endl;
    for( int iphase=0; iphase<6; iphase++ ){
      dbfile << Form(" %8.5g ", threshV_w[iphase+6*imod] );
    }
    dbfile << endl;

    //Finally, let's do the thresholds. For these we have separate U and V strip thresholds per module and trigger phase value:
    dbfile << Form("%s.m%d.threshU_uTScorr_vs_trigphase = ",trackername.Data(), imod) << endl;
    for( int iphase=0; iphase<6; iphase++ ){
      dbfile << Form(" %8.5g ", threshU_uw[iphase+6*imod] );
    }
    dbfile << endl;

    //Finally, let's do the thresholds. For these we have separate U and V strip thresholds per module and trigger phase value:
    dbfile << Form("%s.m%d.threshV_uTScorr_vs_trigphase = ",trackername.Data(), imod) << endl;
    for( int iphase=0; iphase<6; iphase++ ){
      dbfile << Form(" %8.5g ", threshV_uw[iphase+6*imod] );
    }
    dbfile << endl;
    
  }
	
  
  
  fout->cd();
  histos_ADCfrac_timesamp_maxUstrip->Write();
  histos_ADCfrac_timesamp_maxVstrip->Write();
  histos_ADCfrac_trigphase_maxUstrip->Write();
  histos_ADCfrac_trigphase_maxVstrip->Write();

  histos_ccor_vs_trigphase_maxstripU->Write();
  histos_ccor_vs_trigphase_maxstripV->Write();

  histos_ccor_unweighted_vs_trigphase_maxstripU->Write();
  histos_ccor_unweighted_vs_trigphase_maxstripV->Write();
  
  
  
  
  //  fout->cd();
  

  
  
}
