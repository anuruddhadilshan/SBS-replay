/*
  This script generates diagnostic plots for quality assurance of BBCAL calibration.
  -----
  P. Datta <pdbforce@jlab.org> Created 04-21-2022
  -----
*/
#include <iostream>
#include <sstream>
#include <fstream>

#include "TCut.h"
#include "TH2F.h"
#include "TMath.h"
#include "TChain.h"
#include "TString.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TStopwatch.h"
#include "TTreeFormula.h"

const double Mp = 0.938272081; // +/- 6E-9 GeV

const Int_t kNbarsTH = 90;    // # Hodo bars
const Int_t kNcolsSH = 7;     // SH columns
const Int_t kNrowsSH = 27;    // SH rows
const Int_t kNblksSH = 189;   // Total # SH blocks/PMTs
const Int_t kNcolsPS = 2;     // PS columns
const Int_t kNrowsPS = 26;    // PS rows
const Int_t kNblksPS = 52;    // Total # PS blocks/PMTs
const Int_t kNcolsHCAL = 12;  // HCAL columns
const Int_t kNrowsHCAL = 24;  // HCAL rows
const Int_t kNblksHCAL = 288; // Total # HCAL blocks/PMTs

const Double_t zposSH = 1.901952; // m
const Double_t zposPS = 1.695704; // m

const double zhodo = 1.854454;                   // meters
const double Lbar_hodo = 0.6;                    // meters

double RF_freq = 249.5e6;
double bunch_spacing_ns = 1.0e9 / RF_freq;

struct RunRanges
{
      int rmin;
      int rmax;
      float sbsmagfrac;
};

string GetDate();
double GetNDC(double x);
TF1 *FitTimePeak(TH1F *h);
void CustmProfHisto(TProfile *);
void Custm2DRnumHisto(TH2F *, std::vector<std::string> const &lrnum);
std::vector<double> ReadOffsets(char const *infile, int nchan);
float GetSBSFieldPerRun(int run, const std::vector<RunRanges> &sbsfields);

void qualityA_plots_BBCAL(TString outFileBase = "qulaityA_plots_BBCAL.root",
                          const char *configFile = "Beam_analysis_macros/setup_qualityA_plots_BBCAL.cfg")
{
      gErrorIgnoreLevel = kError; // Ignores all ROOT warnings

      // creating a TChain
      TChain *C = new TChain("T");

      // Defining variables
      Int_t SBSconfig = 4;
      bool cut_on_W = 0, cut_on_PovPel = 0, apply_spot_cut = 0;
      Double_t sbsmaxfield, sbsdipolegap = (48.0 * 2.54) / 100.;
      Double_t E_beam = 0., sbstheta = 0., hcaldist = 0., hcalheight = 0., hcalhoffset = 0., hcalzoffset = 0.;
      Double_t p_rec = 0., px_rec = 0., py_rec = 0., pz_rec = 0.;
      Double_t pspot_dxM = 0., pspot_dxS = 0., pspot_ndxS = 0.;
      Double_t pspot_dyM = 0., pspot_dyS = 0., pspot_ndyS = 0.;
      Double_t nspot_dxM = 0., nspot_dxS = 0., nspot_ndxS = 0.;
      Double_t nspot_dyM = 0., nspot_dyS = 0., nspot_ndyS = 0.;
      Double_t h_EovP_bin = 200, h_EovP_min = 0., h_EovP_max = 5.;
      Double_t h2_p_coarse_bin = 25, h2_p_coarse_min = 0., h2_p_coarse_max = 5.;
      Double_t h2_SHeng_vs_blk_low = 0., h2_SHeng_vs_blk_up = 4.;
      Double_t h2_PSeng_vs_blk_low = 0., h2_PSeng_vs_blk_up = 4.;
      Double_t bbcal_atppos = 0., hcal_atppos = 0., BBtrig_t0 = 0., etof0 = 0.;
      int apply_th_timeoffset = 0, apply_hcal_atimeoffset = 0, apply_sh_atimeoffset = 0, apply_ps_atimeoffset = 0;
      float const_hcal_atimeoffset = 0., const_sh_atimeoffset = 0., const_ps_atimeoffset = 0.;
      TString fname_HCAL_atime_offsets_old = "", fname_BBSH_atime_offsets_old = "", fname_BBPS_atime_offsets_old = "";
      TString fname_HCAL_atime_offsets_new = "", fname_BBSH_atime_offsets_new = "", fname_BBPS_atime_offsets_new = "";
      TString fname_THRF_offsets = "", fname_THt0_offsets = "", fname_THwL_offsets = "", fname_THwR_offsets = "", fname_THvscint_offsets = "";

      // Define a stopwatch to measure macro processing time
      TStopwatch *sw = new TStopwatch();
      sw->Start();

      // reading config file
      ifstream configfile(configFile);
      TString currentline;
      cout << endl
           << "Chaining all the ROOT files.." << endl;
      while (currentline.ReadLine(configfile) && !currentline.BeginsWith("endRunlist"))
      {
            if (!currentline.BeginsWith("#"))
            {
                  C->Add(currentline);
            }
      }
      // char runlistfile[1000];
      // TString currentline, readline;
      // while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endRunlist") ){
      //   if( !currentline.BeginsWith("#") ){
      //     sprintf(runlistfile,"%s",currentline.Data());
      //     ifstream run_list(runlistfile);
      //     while( readline.ReadLine( run_list ) && !readline.BeginsWith("endlist") ){
      // 	if( !readline.BeginsWith("#") ){
      // 	  std::cout << readline << "\n";
      // 	  C->Add(readline);
      // 	}
      //     }
      //   }
      // }
      TCut globalcut = "";
      while (currentline.ReadLine(configfile) && !currentline.BeginsWith("endcut"))
      {
            if (!currentline.BeginsWith("#"))
            {
                  globalcut += currentline;
            }
      }
      TTreeFormula *GlobalCut = new TTreeFormula("GlobalCut", globalcut, C);
      while (currentline.ReadLine(configfile) && !currentline.BeginsWith("endconfig"))
      {
            if (currentline.BeginsWith("#"))
                  continue;
            TObjArray *tokens = currentline.Tokenize(" ");
            Int_t ntokens = tokens->GetEntries();
            if (ntokens > 1)
            {
                  TString skey = ((TObjString *)(*tokens)[0])->GetString();
                  if (skey == "E_beam")
                  {
                        E_beam = ((TObjString *)(*tokens)[1])->GetString().Atof();
                  }
                  if (skey == "SBS_theta")
                  {
                        sbstheta = ((TObjString *)(*tokens)[1])->GetString().Atof();
                        sbstheta *= TMath::DegToRad();
                  }
                  if (skey == "HCAL_dist")
                  {
                        hcaldist = ((TObjString *)(*tokens)[1])->GetString().Atof();
                  }
                  if (skey == "HCAL_hoffset")
                  {
                        hcalhoffset = ((TObjString *)(*tokens)[1])->GetString().Atof();
                  }
                  if (skey == "HCAL_zoffset")
                  {
                        hcalzoffset = ((TObjString *)(*tokens)[1])->GetString().Atof();
                  }
                  if (skey == "sbsmaxfield")
                  {
                        sbsmaxfield = ((TObjString *)(*tokens)[1])->GetString().Atof();
                  }
                  if (skey == "apply_spot_cut")
                  {
                        apply_spot_cut = ((TObjString *)(*tokens)[1])->GetString().Atoi();
                  }
                  if (skey == "pspot_cut")
                  {
                        pspot_dxM = ((TObjString *)(*tokens)[1])->GetString().Atof();
                        pspot_dxS = ((TObjString *)(*tokens)[2])->GetString().Atof();
                        pspot_ndxS = ((TObjString *)(*tokens)[3])->GetString().Atof();
                        pspot_dyM = ((TObjString *)(*tokens)[4])->GetString().Atof();
                        pspot_dyS = ((TObjString *)(*tokens)[5])->GetString().Atof();
                        pspot_ndyS = ((TObjString *)(*tokens)[6])->GetString().Atof();
                  }
                  if (skey == "nspot_cut")
                  {
                        nspot_dxM = ((TObjString *)(*tokens)[1])->GetString().Atof();
                        nspot_dxS = ((TObjString *)(*tokens)[2])->GetString().Atof();
                        nspot_ndxS = ((TObjString *)(*tokens)[3])->GetString().Atof();
                        nspot_dyM = ((TObjString *)(*tokens)[4])->GetString().Atof();
                        nspot_dyS = ((TObjString *)(*tokens)[5])->GetString().Atof();
                        nspot_ndyS = ((TObjString *)(*tokens)[6])->GetString().Atof();
                  }
                  if (skey.EqualTo("etof0"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        etof0 = sval.Atof();
                  }   		  
                  if (skey.EqualTo("BBtrig_t0"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        BBtrig_t0 = sval.Atof();
                  }                  
                  if (skey == "apply_th_timeoffset")
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        apply_th_timeoffset = sval.Atoi();
                  }  
                  if (skey.EqualTo("THRF_offsets"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_THRF_offsets = sval;
                  }                      
                  if (skey.EqualTo("THt0_offsets"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_THt0_offsets = sval;
                  }                  
                  if (skey.EqualTo("THwL_offsets"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_THwL_offsets = sval;
                  }                  
                  if (skey.EqualTo("THwR_offsets"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_THwR_offsets = sval;
                  }                  
                  if (skey.EqualTo("THvscint_offsets"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_THvscint_offsets = sval;
                  }                  
                  if (skey == "apply_hcal_atimeoffset")
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        apply_hcal_atimeoffset = sval.Atoi();
                        TString sval1 = ((TObjString *)(*tokens)[2])->GetString();
                        const_hcal_atimeoffset = sval1.Atof();
                  }
                  if (skey.EqualTo("HCAL_atime_offsets_old"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_HCAL_atime_offsets_old = sval;
                  }
                  if (skey.EqualTo("HCAL_atime_offsets_new"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_HCAL_atime_offsets_new = sval;
                  }
                  if (skey == "apply_sh_atimeoffset")
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        apply_sh_atimeoffset = sval.Atoi();
                        TString sval1 = ((TObjString *)(*tokens)[2])->GetString();
                        const_sh_atimeoffset = sval1.Atof();
                  }
                  if (skey.EqualTo("BBSH_atime_offsets_old"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_BBSH_atime_offsets_old = sval;
                  }
                  if (skey.EqualTo("BBSH_atime_offsets_new"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_BBSH_atime_offsets_new = sval;
                  }
                  if (skey == "apply_ps_atimeoffset")
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        apply_ps_atimeoffset = sval.Atoi();
                        TString sval1 = ((TObjString *)(*tokens)[2])->GetString();
                        const_ps_atimeoffset = sval1.Atof();
                  }
                  if (skey.EqualTo("BBPS_atime_offsets_old"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_BBPS_atime_offsets_old = sval;
                  }
                  if (skey.EqualTo("BBPS_atime_offsets_new"))
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        fname_BBPS_atime_offsets_new = sval;
                  }
                  if (skey == "h_EovP")
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        h_EovP_bin = sval.Atoi();
                        TString sval1 = ((TObjString *)(*tokens)[2])->GetString();
                        h_EovP_min = sval1.Atof();
                        TString sval2 = ((TObjString *)(*tokens)[3])->GetString();
                        h_EovP_max = sval2.Atof();
                  }
                  if (skey == "h2_p_coarse")
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        h2_p_coarse_bin = sval.Atoi();
                        TString sval1 = ((TObjString *)(*tokens)[2])->GetString();
                        h2_p_coarse_min = sval1.Atof();
                        TString sval2 = ((TObjString *)(*tokens)[3])->GetString();
                        h2_p_coarse_max = sval2.Atof();
                  }
                  if (skey == "h2_SHeng_vs_blk")
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        h2_SHeng_vs_blk_low = sval.Atof();
                        TString sval1 = ((TObjString *)(*tokens)[2])->GetString();
                        h2_SHeng_vs_blk_up = sval1.Atof();
                  }
                  if (skey == "h2_PSeng_vs_blk")
                  {
                        TString sval = ((TObjString *)(*tokens)[1])->GetString();
                        h2_PSeng_vs_blk_low = sval.Atof();
                        TString sval1 = ((TObjString *)(*tokens)[2])->GetString();
                        h2_PSeng_vs_blk_up = sval1.Atof();
                  }
                  if (skey == "bbcal_atppos")
                        bbcal_atppos = ((TObjString *)(*tokens)[1])->GetString().Atof();
                  if (skey == "hcal_atppos")
                        hcal_atppos = ((TObjString *)(*tokens)[1])->GetString().Atof();
                  if (skey == "*****")
                  {
                        break;
                  }
            }
            delete tokens;
      }

      // Parsing field configuration info to calculate proton TOF corrections:
      vector<RunRanges> sbsfields;
      int nfieldsettings = 0;
      while (currentline.ReadLine(configfile) && !currentline.BeginsWith("endfieldconfig"))
      {
            if (!currentline.BeginsWith("#"))
            {
                  TObjArray *tokens = currentline.Tokenize(" ");
                  // Here we expect three values per line, rmin, rmax, field (as fraction of maximum):
                  if (tokens->GetEntries() >= 3)
                  {
                        TString srmin = ((TObjString *)(*tokens)[0])->GetString();
                        TString srmax = ((TObjString *)(*tokens)[1])->GetString();
                        TString sfieldval = ((TObjString *)(*tokens)[2])->GetString();

                        nfieldsettings++;
                        sbsfields.push_back({srmin.Atoi(), srmax.Atoi(), (float)sfieldval.Atof()});
                  }
            }
      }
      std::cout << "Number of field settings = " << nfieldsettings << endl;

      // Reading in time offsets
      std::vector<double> thRFoffsets = ReadOffsets(fname_THRF_offsets.Data(), kNbarsTH);
      std::vector<double> tht0offsets = ReadOffsets(fname_THt0_offsets.Data(), kNbarsTH);
      std::vector<double> thwLoffsets = ReadOffsets(fname_THwL_offsets.Data(), kNbarsTH);
      std::vector<double> thwRoffsets = ReadOffsets(fname_THwR_offsets.Data(), kNbarsTH);
      std::vector<double> thvscintoffsets = ReadOffsets(fname_THvscint_offsets.Data(), kNbarsTH);
      std::vector<double> oldhcaloffsets = ReadOffsets(fname_HCAL_atime_offsets_old.Data(), kNblksHCAL);
      std::vector<double> oldshoffsets = ReadOffsets(fname_BBSH_atime_offsets_old.Data(), kNblksSH);
      std::vector<double> oldpsoffsets = ReadOffsets(fname_BBPS_atime_offsets_old.Data(), kNblksPS);
      std::vector<double> newhcaloffsets = ReadOffsets(fname_HCAL_atime_offsets_new.Data(), kNblksHCAL);
      std::vector<double> newshoffsets = ReadOffsets(fname_BBSH_atime_offsets_new.Data(), kNblksSH);
      std::vector<double> newpsoffsets = ReadOffsets(fname_BBPS_atime_offsets_new.Data(), kNblksPS);

      // Implementing global cuts
      if (C->GetEntries() == 0)
      {
            cerr << endl
                 << " --- No ROOT file found!! ---" << endl
                 << endl;
            throw;
      }
      else
      {
            cout << endl
                 << "Found " << C->GetEntries() << " events. Implementing global cuts.." << endl;
      }

      // Setting branch addresses for various tree variables for analysis
      int maxNtr = 200;
      C->SetBranchStatus("*", 0);
      // bb.ps branches
      C->SetBranchStatus("bb.ps.*", 1);
      Double_t psNclus;
      C->SetBranchAddress("bb.ps.nclus", &psNclus);
      Double_t psIdblk;
      C->SetBranchAddress("bb.ps.idblk", &psIdblk);
      Double_t psRowblk;
      C->SetBranchAddress("bb.ps.rowblk", &psRowblk);
      Double_t psColblk;
      C->SetBranchAddress("bb.ps.colblk", &psColblk);
      Double_t psNblk;
      C->SetBranchAddress("bb.ps.nblk", &psNblk);
      Double_t psAtime;
      C->SetBranchAddress("bb.ps.atimeblk", &psAtime);
      Double_t psE;
      C->SetBranchAddress("bb.ps.e", &psE);
      Double_t psX;
      C->SetBranchAddress("bb.ps.x", &psX);
      Double_t psY;
      C->SetBranchAddress("bb.ps.y", &psY);
      Double_t psClBlkId[maxNtr];
      C->SetBranchAddress("bb.ps.clus_blk.id", &psClBlkId);
      Double_t psClBlkE[maxNtr];
      C->SetBranchAddress("bb.ps.clus_blk.e", &psClBlkE);
      Double_t psClBlkX[maxNtr];
      C->SetBranchAddress("bb.ps.clus_blk.x", &psClBlkX);
      Double_t psClBlkY[maxNtr];
      C->SetBranchAddress("bb.ps.clus_blk.y", &psClBlkY);
      Double_t psClBlkAtime[maxNtr];
      C->SetBranchAddress("bb.ps.clus_blk.atime", &psClBlkAtime);
      Double_t psAgainblk;
      C->SetBranchAddress("bb.ps.againblk", &psAgainblk);
      // bb.sh branches
      C->SetBranchStatus("bb.sh.*", 1);
      Double_t shNclus;
      C->SetBranchAddress("bb.sh.nclus", &shNclus);
      Double_t shIdblk;
      C->SetBranchAddress("bb.sh.idblk", &shIdblk);
      Double_t shRowblk;
      C->SetBranchAddress("bb.sh.rowblk", &shRowblk);
      Double_t shColblk;
      C->SetBranchAddress("bb.sh.colblk", &shColblk);
      Double_t shNblk;
      C->SetBranchAddress("bb.sh.nblk", &shNblk);
      Double_t shAtime;
      C->SetBranchAddress("bb.sh.atimeblk", &shAtime);
      Double_t shE;
      C->SetBranchAddress("bb.sh.e", &shE);
      Double_t shX;
      C->SetBranchAddress("bb.sh.x", &shX);
      Double_t shY;
      C->SetBranchAddress("bb.sh.y", &shY);
      Double_t shClBlkId[maxNtr];
      C->SetBranchAddress("bb.sh.clus_blk.id", &shClBlkId);
      Double_t shClBlkE[maxNtr];
      C->SetBranchAddress("bb.sh.clus_blk.e", &shClBlkE);
      Double_t shClBlkX[maxNtr];
      C->SetBranchAddress("bb.sh.clus_blk.x", &shClBlkX);
      Double_t shClBlkY[maxNtr];
      C->SetBranchAddress("bb.sh.clus_blk.y", &shClBlkY);
      Double_t shClBlkAtime[maxNtr];
      C->SetBranchAddress("bb.sh.clus_blk.atime", &shClBlkAtime);
      Double_t shAgainblk;
      C->SetBranchAddress("bb.sh.againblk", &shAgainblk);
      // sbs.hcal branches
      Double_t hcalIdblk;
      C->SetBranchStatus("sbs.hcal.idblk", 1);
      C->SetBranchAddress("sbs.hcal.idblk", &hcalIdblk);
      Double_t hcalE;
      C->SetBranchStatus("sbs.hcal.e", 1);
      C->SetBranchAddress("sbs.hcal.e", &hcalE);
      Double_t hcalX;
      C->SetBranchStatus("sbs.hcal.x", 1);
      C->SetBranchAddress("sbs.hcal.x", &hcalX);
      Double_t hcalY;
      C->SetBranchStatus("sbs.hcal.y", 1);
      C->SetBranchAddress("sbs.hcal.y", &hcalY);
      Double_t hcalAtime;
      C->SetBranchStatus("sbs.hcal.atimeblk", 1);
      C->SetBranchAddress("sbs.hcal.atimeblk", &hcalAtime);
      // bb.tr branches
      C->SetBranchStatus("bb.tr.*", 1);
      Double_t trN;
      C->SetBranchAddress("bb.tr.n", &trN);
      Double_t trP[maxNtr];
      C->SetBranchAddress("bb.tr.p", &trP);
      Double_t trPx[maxNtr];
      C->SetBranchAddress("bb.tr.px", &trPx);
      Double_t trPy[maxNtr];
      C->SetBranchAddress("bb.tr.py", &trPy);
      Double_t trPz[maxNtr];
      C->SetBranchAddress("bb.tr.pz", &trPz);
      Double_t trX[maxNtr];
      C->SetBranchAddress("bb.tr.x", &trX);
      Double_t trY[maxNtr];
      C->SetBranchAddress("bb.tr.y", &trY);
      Double_t trTh[maxNtr];
      C->SetBranchAddress("bb.tr.th", &trTh);
      Double_t trPh[maxNtr];
      C->SetBranchAddress("bb.tr.ph", &trPh);
      Double_t trVz[maxNtr];
      C->SetBranchAddress("bb.tr.vz", &trVz);
      Double_t trVy[maxNtr];
      C->SetBranchAddress("bb.tr.vy", &trVy);
      Double_t trTgth[maxNtr];
      C->SetBranchAddress("bb.tr.tg_th", &trTgth);
      Double_t trTgph[maxNtr];
      C->SetBranchAddress("bb.tr.tg_ph", &trTgph);
      Double_t trRx[maxNtr];
      C->SetBranchAddress("bb.tr.r_x", &trRx);
      Double_t trRy[maxNtr];
      C->SetBranchAddress("bb.tr.r_y", &trRy);
      Double_t trRth[maxNtr];
      C->SetBranchAddress("bb.tr.r_th", &trRth);
      Double_t trRph[maxNtr];
      C->SetBranchAddress("bb.tr.r_ph", &trRph);
      Double_t trPathl[maxNtr];
      C->SetBranchAddress("bb.tr.pathl", &trPathl);
      // bb.hodotdc branches
      Double_t thRFTime;
      C->SetBranchStatus("bb.hodotdc.rftime", 1);
      C->SetBranchAddress("bb.hodotdc.rftime", &thRFTime);
      Double_t thTrigTime;
      C->SetBranchStatus("bb.hodotdc.trigtime", 1);
      C->SetBranchAddress("bb.hodotdc.trigtime", &thTrigTime);
      Double_t thTrigPhaseCorr;
      C->SetBranchStatus("bb.hodotdc.trigphasecorr", 1);
      C->SetBranchAddress("bb.hodotdc.trigphasecorr", &thTrigPhaseCorr);
      Double_t thClsize[maxNtr]; 
      C->SetBranchStatus("bb.hodotdc.clus.size", 1);
      C->SetBranchAddress("bb.hodotdc.clus.size", &thClsize);      
      Double_t thBTId[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.bar.tdc.id", 1);
      C->SetBranchAddress("bb.hodotdc.clus.bar.tdc.id", &thBTId);
      Double_t thBTmean[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.bar.tdc.meantime", 1);
      C->SetBranchAddress("bb.hodotdc.clus.bar.tdc.meantime", &thBTmean);
      Double_t thBTdiff[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.bar.tdc.timediff", 1);
      C->SetBranchAddress("bb.hodotdc.clus.bar.tdc.timediff", &thBTdiff);      
      Double_t thBTleft[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.bar.tdc.tleft", 1);
      C->SetBranchAddress("bb.hodotdc.clus.bar.tdc.tleft", &thBTleft);
      Double_t thBTright[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.bar.tdc.tright", 1);
      C->SetBranchAddress("bb.hodotdc.clus.bar.tdc.tright", &thBTright);
      Double_t thBTotleft[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.bar.tdc.totleft", 1);
      C->SetBranchAddress("bb.hodotdc.clus.bar.tdc.totleft", &thBTotleft);
      Double_t thBTotright[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.bar.tdc.totright", 1);
      C->SetBranchAddress("bb.hodotdc.clus.bar.tdc.totright", &thBTotright);
      Double_t thTfinal[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.tfinal", 1);
      C->SetBranchAddress("bb.hodotdc.clus.tfinal", &thTfinal);
      Double_t thTdiff[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.tdiff", 1);
      C->SetBranchAddress("bb.hodotdc.clus.tdiff", &thTdiff);
      Double_t thTmean[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.tmean", 1);
      C->SetBranchAddress("bb.hodotdc.clus.tmean", &thTmean);
      Double_t thTOTmean[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.totmean", 1);
      C->SetBranchAddress("bb.hodotdc.clus.totmean", &thTOTmean);
      Double_t thTrIndex[maxNtr];
      C->SetBranchStatus("bb.hodotdc.clus.trackindex", 1);
      C->SetBranchAddress("bb.hodotdc.clus.trackindex", &thTrIndex);
      // Event info
      C->SetMakeClass(1);
      C->SetBranchStatus("fEvtHdr.*", 1);
      UInt_t rnum;
      C->SetBranchAddress("fEvtHdr.fRun", &rnum);
      UInt_t trigbits;
      C->SetBranchAddress("fEvtHdr.fTrigBits", &trigbits);
      ULong64_t gevnum;
      C->SetBranchAddress("fEvtHdr.fEvtNum", &gevnum);
      // turning on additional branches for the global cut
      C->SetBranchStatus("e.kine.W2", 1);
      C->SetBranchStatus("sbs.hcal.e", 1);
      C->SetBranchStatus("bb.etot_over_p", 1);
      C->SetBranchStatus("bb.gem.track.nhits", 1);
      C->SetBranchStatus("bb.gem.track.ngoodhits", 1);
      C->SetBranchStatus("bb.gem.track.chi2ndf", 1);
      C->SetBranchStatus("bb.grinch_tdc.clus.trackindex", 1);
      C->SetBranchStatus("bb.grinch_tdc.clus.size", 1);

      // Defining temporary histograms (don't wanna write these to files)
      TH2F *h2_SHeng_vs_SHblk_raw = new TH2F("h2_SHeng_vs_SHblk_raw", "Raw E_clus(SH) per SH block", kNcolsSH, 0, kNcolsSH, kNrowsSH, 0, kNrowsSH);
      TH2F *h2_EovP_vs_SHblk_raw = new TH2F("h2_EovP_vs_SHblk_raw", "Raw E_clus/p_rec per SH block", kNcolsSH, 0, kNcolsSH, kNrowsSH, 0, kNrowsSH);
      TH2F *h2_EovP_vs_PSblk_raw = new TH2F("h2_EovP_vs_PSblk_raw", "Raw E_clus/p_rec per PS block", kNcolsPS, 0, kNcolsPS, kNrowsPS, 0, kNrowsPS);
      TH2F *h2_count = new TH2F("h2_count", "Count for E_clus/p_rec per per SH block", kNcolsSH, 0, kNcolsSH, kNrowsSH, 0, kNrowsSH);
      TH2F *h2_EovP_vs_SHblk_trPOS_raw = new TH2F("h2_EovP_vs_SHblk_trPOS_raw", "Raw E_clus/p_rec per SH block(TrPos)", kNcolsSH, -0.2992, 0.2992, kNrowsSH, -1.1542, 1.1542);
      TH2F *h2_count_trP = new TH2F("h2_count_trP", "Count for E_clus/p_rec per per SH block(TrPos)", kNcolsSH, -0.2992, 0.2992, kNrowsSH, -1.1542, 1.1542);
      TH2F *h2_count_trP_PS = new TH2F("h2_count_trP_PS", "Count for E_clus(PS) per per PS block(TrPOS)", kNcolsPS, -0.3705, 0.3705, kNrowsPS, -1.201, 1.151);

      TH2F *h2_count_PS = new TH2F("h2_count_PS", "Count for E_clus/p_rec per per PS block", kNcolsPS, 0, kNcolsPS, kNrowsPS, 0, kNrowsPS);
      TH2F *h2_PSeng_vs_PSblk_raw = new TH2F("h2_PSeng_vs_PSblk_raw", "Raw E_clus(PS) per PS block", kNcolsPS, 0, kNcolsPS, kNrowsPS, 0, kNrowsPS);
      TH2F *h2_PSeng_vs_PSblk_trPOS_raw = new TH2F("h2_PSeng_vs_PSblk_trPOS_raw", "Raw E_clus(PS) per PS block(TrPos)", kNcolsPS, -0.3705, 0.3705, kNrowsPS, -1.201, 1.151);

      // Creating output ROOT file to contain histograms
      TString outFile = outFileBase;
      TFile *fout = new TFile(outFile, "RECREATE");
      fout->cd();

      // Defining physics histograms
      TH1F *h_EovP = new TH1F("h_EovP", "E/p", h_EovP_bin, h_EovP_min, h_EovP_max);
      TH2F *h2_EovP_vs_P = new TH2F("h2_EovP_vs_P", "E/p vs p; p (GeV); E/p", h2_p_coarse_bin, h2_p_coarse_min, h2_p_coarse_max, h_EovP_bin, h_EovP_min, h_EovP_max);
      TProfile *h2_EovP_vs_P_prof = new TProfile("h2_EovP_vs_P_prof", "E/p vs P (Profile)", h2_p_coarse_bin, h2_p_coarse_min, h2_p_coarse_max, h_EovP_min, h_EovP_max, "S");

      TH2D *htmean_vs_ID = new TH2D("htmean_vs_ID", "TH Mean Time vs Bar ID;bar ID; bar t_{mean} (ns)", kNbarsTH, -0.5, 89.5, 300, -30, 30);
      TProfile *htmean_vs_ID_prof = new TProfile("htmean_vs_ID_prof", "TH tfinal vs bars (Profile)", kNbarsTH, -0.5, 89.5, -3., 3., "S");

      TH2F *h2_EovP_vs_SHblk = new TH2F("h2_EovP_vs_SHblk", "E/p per SH block", kNcolsSH, 0, kNcolsSH, kNrowsSH, 0, kNrowsSH);
      TH2F *h2_EovP_vs_PSblk = new TH2F("h2_EovP_vs_PSblk", "E/p per PS block", kNcolsPS, 0, kNcolsPS, kNrowsPS, 0, kNrowsPS);
      TH2F *h2_EovP_vs_SHblk_trPOS = new TH2F("h2_EovP_vs_SHblk_trPOS", "E/p per SH block u Track Pos.", kNcolsSH, -0.2992, 0.2992, kNrowsSH, -1.1542, 1.1542);
      TH2F *h2_SHeng_vs_SHblk = new TH2F("h2_SHeng_vs_SHblk", "SH energy per SH block", kNcolsSH, 0, kNcolsSH, kNrowsSH, 0, kNrowsSH);

      TH2F *h2_PSeng_vs_PSblk = new TH2F("h2_PSeng_vs_PSblk", "PS energy per PS block", kNcolsPS, 0, kNcolsPS, kNrowsPS, 0, kNrowsPS);
      TH2F *h2_PSeng_vs_PSblk_trPOS = new TH2F("h2_PSeng_vs_PSblk_trPOS", "PS energy per PS block u Track Pos.", kNcolsPS, -0.3705, 0.3705, kNrowsPS, -1.201, 1.151);

      // Defining timing histos
      TH1F *h_THSH_diff = new TH1F("h_THSH_diff", "TH - SH ADC Time (ns)", 200, -8, 8);
      TH1F *h_THPS_diff = new TH1F("h_THPS_diff", "TH - PS ADC Time (ns)", 200, -8, 8);
      TH1F *h_THHCAL_diff = new TH1F("h_THHCAL_diff", "Red => proton, Black => neutron;TH-HCAL ADC Time Coin (ns)", 200, -8, 8);
      TH1F *h_THHCAL_diff_p = new TH1F("h_THHCAL_diff_p", "Red => proton, Black => neutron;TH-HCAL ADC Time Coin (ns)", 200, -8, 8);
      TH1F *h_THHCAL_diff_n = new TH1F("h_THHCAL_diff_n", "Red => proton, Black => neutron;TH-HCAL ADC Time Coin (ns)", 200, -8, 8);
      TH1F *h_SHHCAL_diff = new TH1F("h_SHHCAL_diff", "Red => proton, Black => neutron;SH-HCAL ADC Time Coin (ns)", 200, -8, 8);
      TH1F *h_SHHCAL_diff_p = new TH1F("h_SHHCAL_diff_p", "Red => proton, Black => neutron;SH-HCAL ADC Time Coin (ns)", 200, -8, 8);
      TH1F *h_SHHCAL_diff_n = new TH1F("h_SHHCAL_diff_n", "Red => proton, Black => neutron;SH-HCAL ADC Time Coin (ns)", 200, -8, 8);

      // ADC time related histograms
      // TH2F *h2_ADCtime_diff_wrt_Hodo = new TH2F("h2_ADCtime_diff_wrt_Hodo","ADCTime diff. w.r.t. Hodo tmean (ns) vs. SH block",189,0,189,200,-50,50);
      // TProfile *h2_ADCtime_diff_wrt_Hodo_prof = new TProfile("h2_ADCtime_diff_wrt_Hodo_prof","ADCTime diff. w.r.t. Hodo tmean (ns) vs. SH block (Profile)",189,0,189,-50,50);
      Double_t h_atime_bin = 200, h_atime_min = bbcal_atppos - 25., h_atime_max = bbcal_atppos + 20.;
      Double_t h2_ThShCoin_bin = 200, h2_ThShCoin_min = -bbcal_atppos - 15., h2_ThShCoin_max = -bbcal_atppos + 15.;
      Double_t ShHcalCoin = bbcal_atppos - hcal_atppos;
      Double_t h2_ShHcalCoin_bin = 200, h2_ShHcalCoin_min = ShHcalCoin - 15., h2_ShHcalCoin_max = ShHcalCoin + 15.;

      Double_t Nruns = 1000; // Max # runs we anticipate to analyze
      TH2F *h2_EovP_vs_rnum = new TH2F("h2_EovP_vs_rnum", "E/p vs Run no", Nruns, 0.5, Nruns + 0.5, 200, 0.4, 1.6);
      TProfile *h2_EovP_vs_rnum_prof = new TProfile("h2_EovP_vs_rnum_prof", "E/p vs Run no. (Profile)", Nruns, 0.5, Nruns + 0.5, 0.4, 1.6, "S");

      // TH1F *h_atimeSH = new TH1F("h_atimeSH","SH ADC time | Before corr.",h_atime_bin,h_atime_min,h_atime_max);
      // TH1F *h_atimePS = new TH1F("h_atimePS","PS ADC time | Before corr.",h_atime_bin,h_atime_min,h_atime_max);

      TH2F *h2_atimeSH_vs_rnum = new TH2F("h2_atimeSH_vs_rnum", "SH ADC time vs Run no.;Run no.;SH ADCtime (ns)", Nruns, 0.5, Nruns + 0.5, h_atime_bin, h_atime_min, h_atime_max);
      TProfile *h2_atimeSH_vs_rnum_prof = new TProfile("h2_atimeSH_vs_rnum_prof", "SH ADC time vs Run no. (Profile)", Nruns, 0.5, Nruns + 0.5, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");
      TH2F *h2_atimePS_vs_rnum = new TH2F("h2_atimePS_vs_rnum", "PS ADC time vs Run no.;Run no.;PS ADCtime (ns)", Nruns, 0.5, Nruns + 0.5, h_atime_bin, h_atime_min, h_atime_max);
      TProfile *h2_atimePS_vs_rnum_prof = new TProfile("h2_atimePS_vs_rnum_prof", "PS ADC time vs Run no. (Profile)", Nruns, 0.5, Nruns + 0.5, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");
      TH2F *h2_atimeHCAL_vs_rnum = new TH2F("h2_atimeHCAL_vs_rnum", "HCAL ADC time vs Run no.;Run no.;HCAL ADCtime (ns)", Nruns, 0.5, Nruns + 0.5, h_atime_bin, h_atime_min, h_atime_max);
      TProfile *h2_atimeHCAL_vs_rnum_prof = new TProfile("h2_atimeHCAL_vs_rnum_prof", "HCAL ADC time vs Run no. (Profile)", Nruns, 0.5, Nruns + 0.5, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");

      TH2F *h2_ThShCoin_vs_blk = new TH2F("h2_ThShCoin_vs_blk", "TH-SH Coin vs SH blocks;SH block id;TH ClusTfinal - SH ADCtime (ns)", kNblksSH, 0, kNblksSH, h2_ThShCoin_bin, h2_ThShCoin_min, h2_ThShCoin_max);
      TProfile *h2_ThShCoin_vs_blk_prof = new TProfile("h2_ThShCoin_vs_blk_prof", "TH-SH Coin vs SH blocks (Profile)", 189, 0, 189, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");
      TH2F *h2_ThPsCoin_vs_blk = new TH2F("h2_ThPsCoin_vs_blk", "TH-PS Coin vs PS blocks;PS block id;TH ClusTfinal - PS ADCtime (ns)", kNblksPS, 0, kNblksPS, h2_ThShCoin_bin, h2_ThShCoin_min, h2_ThShCoin_max);
      TProfile *h2_ThPsCoin_vs_blk_prof = new TProfile("h2_ThPsCoin_vs_blk_prof", "TH-PS Coin vs PS blocks (Profile)", kNblksPS, 0, kNblksPS, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");
      TH2F *h2_ThHcalCoin_vs_blk = new TH2F("h2_ThHcalCoin_vs_blk", "TH-HCAL Coin vs HCAL blocks;HCAL block id;TH ClusTfinal - HCAL ADCtime (ns)", kNblksHCAL, 0, kNblksHCAL, h2_ThShCoin_bin, h2_ThShCoin_min, h2_ThShCoin_max);
      TProfile *h2_ThHcalCoin_vs_blk_prof = new TProfile("h2_ThHcalCoin_vs_blk_prof", "TH-HCAL Coin vs HCAL blocks (Profile)", kNblksHCAL, 0, kNblksHCAL, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");

      TH2F *h2_ThShCoin_vs_rnum = new TH2F("h2_ThShCoin_vs_rnum", "TH-SH Coin vs Run No.;Run no.;TH ClusTfinal - SH ADCtime (ns)", Nruns, 0.5, Nruns + 0.5, h2_ThShCoin_bin, h2_ThShCoin_min, h2_ThShCoin_max);
      TProfile *h2_ThShCoin_vs_rnum_prof = new TProfile("h2_ThShCoin_vs_rnum_prof", "TH-SH Coin vs Run No. (Profile)", Nruns, 0.5, Nruns + 0.5, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");
      TH2F *h2_ThPsCoin_vs_rnum = new TH2F("h2_ThPsCoin_vs_rnum", "TH-PS Coin vs Run No.;Run no.;TH ClusTfinal - PS ADCtime (ns)", Nruns, 0.5, Nruns + 0.5, h2_ThShCoin_bin, h2_ThShCoin_min, h2_ThShCoin_max);
      TProfile *h2_ThPsCoin_vs_rnum_prof = new TProfile("h2_ThPsCoin_vs_rnum_prof", "TH-PS Coin vs Run No. (Profile)", Nruns, 0.5, Nruns + 0.5, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");
      TH2F *h2_ThHcalCoin_vs_rnum = new TH2F("h2_ThHcalCoin_vs_rnum", "TH-HCAL Coin vs Run No.;Run no.;TH ClusTfinal - HCAL ADCtime (ns)", Nruns, 0.5, Nruns + 0.5, h2_ThShCoin_bin, h2_ThShCoin_min, h2_ThShCoin_max);
      TProfile *h2_ThHcalCoin_vs_rnum_prof = new TProfile("h2_ThHcalCoin_vs_rnum_prof", "TH-HCAL Coin vs Run No. (Profile)", Nruns, 0.5, Nruns + 0.5, -bbcal_atppos - 3., -bbcal_atppos + 3., "S");

      TH2F *h2_ShHcalCoin_vs_rnum = new TH2F("h2_ShHcalCoin_vs_rnum", "SH-HCAL Coin vs Run No.;Run no.;SH ADCtime - HCAL ADCtime (ns)", Nruns, 0.5, Nruns + 0.5, h2_ShHcalCoin_bin, h2_ShHcalCoin_min, h2_ShHcalCoin_max);
      TProfile *h2_ShHcalCoin_vs_rnum_prof = new TProfile("h2_ShHcalCoin_vs_rnum_prof", "SH-HCAL Coin vs Run No. (Profile)", Nruns, 0.5, Nruns + 0.5, ShHcalCoin - 5., ShHcalCoin + 5., "S");
      TH2F *h2_PsHcalCoin_vs_rnum = new TH2F("h2_PsHcalCoin_vs_rnum", "PS-HCAL Coin vs Run No.;Run no.;PS ADCtime - HCAL ADCtime (ns)", Nruns, 0.5, Nruns + 0.5, h2_ShHcalCoin_bin, h2_ShHcalCoin_min, h2_ShHcalCoin_max);
      TProfile *h2_PsHcalCoin_vs_rnum_prof = new TProfile("h2_PsHcalCoin_vs_rnum_prof", "PS-HCAL Coin vs Run No. (Profile)", Nruns, 0.5, Nruns + 0.5, ShHcalCoin - 5., ShHcalCoin + 5., "S");

      // histograms to check bias in tracking
      TH2F *h2_EovP_vs_trX = new TH2F("h2_EovP_vs_trX", "E/p vs Track x", 200, -0.8, 0.8, 200, 0, 2);
      TH2F *h2_EovP_vs_trY = new TH2F("h2_EovP_vs_trY", "E/p vs Track y", 200, -0.16, 0.16, 200, 0, 2);
      TH2F *h2_EovP_vs_trTh = new TH2F("h2_EovP_vs_trTh", "E/p vs Track theta", 200, -0.2, 0.2, 200, 0, 2);
      TH2F *h2_EovP_vs_trPh = new TH2F("h2_EovP_vs_trPh", "E/p vs Track phi", 200, -0.08, 0.08, 200, 0, 2);
      // TH2F *h2_PSeng_vs_trX = new TH2F("h2_PSeng_vs_trX","PS energy vs Track x",200,-0.8,0.8,200,0,4);
      // TH2F *h2_PSeng_vs_trY = new TH2F("h2_PSeng_vs_trY","PS energy vs Track y",200,-0.16,0.16,200,0,4);
      TH2D *h2_PSeng_vs_trXatPS = new TH2D("h2_PSeng_vs_trXatPS", "PS energy vs Track x (proj. at PS)", 200, -1., 1., 200, 0, 4);
      TH2D *h2_PSeng_vs_trYatPS = new TH2D("h2_PSeng_vs_trYatPS", "PS energy vs Track y (proj. at PS)", 200, -0.3, 0.3, 200, 0, 4);

      // Output tree
      TTree *Tout = new TTree("Tout", "output tree");
      Tout->SetMaxTreeSize(4000000000LL);
      bool pCut;
      Tout->Branch("pCut", &pCut, "pCut/O"); // Cut on momentum.
      bool nCut;
      Tout->Branch("nCut", &nCut, "nCut/O"); // Cut on momentum.      
      Double_t T_dx;
      Tout->Branch("dx", &T_dx, "dx/D"); // HCal actual x position - the expected x position according to BB GEM tracks
      Double_t T_dy;
      Tout->Branch("dy", &T_dy, "dy/D"); // HCal actual y position - the expected y position according to BB GEM tracks
      Double_t T_pdef;
      Tout->Branch("pdef", &T_pdef, "pdef/D"); // expected proton deflection
      // time branches
      Double_t T_atimeSH;
      Tout->Branch("atimeSH", &T_atimeSH, "atimeSH/D");
      Double_t T_atimePS;
      Tout->Branch("atimePS", &T_atimePS, "atimePS/D");
      Double_t T_atimeHCAL;
      Tout->Branch("atimeHCAL", &T_atimeHCAL, "atimeHCAL/D");
      Double_t T_THfinal;
      Tout->Branch("THfinal", &T_THfinal, "THfinal/D");

      // calculating HCAL co-ordinates
      TVector3 HCAL_zaxis(sin(-sbstheta), 0, cos(-sbstheta)); // use angle of SBS to calculate the center of HCal
      TVector3 HCAL_xaxis(0, -1, 0);
      TVector3 HCAL_yaxis = HCAL_zaxis.Cross(HCAL_xaxis).Unit();
      TVector3 HCAL_origin = (hcaldist + hcalzoffset) * HCAL_zaxis + hcalheight * HCAL_xaxis + hcalhoffset * HCAL_yaxis; // Define the center of HCal in 3D space

      // Looping over good events ================================================================= //
      Long64_t Nevents = C->GetEntries(), nevent = 0;
      cout << endl
           << "Processing " << Nevents << " events.." << endl;

      Int_t treenum = 0, currenttreenum = 0, itrrun = 0;
      UInt_t runnum = 0;
      std::vector<std::string> lrnum; // list of run numbers

      while (C->GetEntry(nevent++))
      {

            // progress indicator
            if (nevent % 100 == 0)
                  cout << nevent << "/" << Nevents << "\r";
            cout.flush();

            // apply global cuts efficiently (AJRP method)
            currenttreenum = C->GetTreeNumber();
            if (nevent == 1 || currenttreenum != treenum)
            {
                  treenum = currenttreenum;
                  GlobalCut->UpdateFormulaLeaves();

                  // track change of runnum
                  if (nevent == 1 || rnum != runnum)
                  {
                        runnum = rnum;
                        itrrun++;
                        lrnum.push_back(to_string(rnum));
                  }
            }
            bool passedgCut = GlobalCut->EvalInstance(0) != 0;
            if (passedgCut)
            {

                  // ------------
                  // Elastic calculations
                  // ------------
                  p_rec = trP[0];
                  px_rec = trPx[0];
                  py_rec = trPy[0];
                  pz_rec = trPz[0];

                  // elastic calculations (Using 4-vector method)
                  // Relevant 4-vectors
                  /* Reaction    : e + e' -> p + p'
                   Conservation: Pe + Peprime = Pp + Ppprime */
                  TVector3 vertex(0, 0, trVz[0]);
                  TLorentzVector Pe(0, 0, E_beam, E_beam); // incoming e- 4-vector
                  TLorentzVector Peprime(px_rec,           // scattered e- 4-vector
                                         py_rec,
                                         pz_rec,
                                         p_rec);
                  TLorentzVector Pp(0, 0, 0, Mp);  // target nucleon 4-vector
                  TLorentzVector Ppprime;          // Recoil nucleon 4-vector
                  TLorentzVector q = Pe - Peprime; // 4-momentum of virtual photon
                  // scattered e-
                  Double_t etheta = TMath::ACos(pz_rec / p_rec);
                  Double_t ephi = atan2(py_rec, px_rec);
                  Double_t pelas = E_beam / (1. + (E_beam / Mp) * (1.0 - cos(etheta)));
                  // struck nucleon
                  Double_t nu = q.E();
                  Ppprime = q + Pp;
                  TVector3 pNhat = Ppprime.Vect().Unit();
                  Double_t Q2 = -q.M2();
                  Double_t W2 = Ppprime.M2();
                  Double_t W = sqrt(max(0., W2));
                  Double_t PovPel = Peprime.E() / pelas;

                  // calculating expected hit positions on HCAL
                  Double_t sintersect = (HCAL_origin - vertex).Dot(HCAL_zaxis) / (pNhat.Dot(HCAL_zaxis));
                  TVector3 HCAL_intersect = vertex + sintersect * pNhat;
                  Double_t hcalX_exp = (HCAL_intersect - HCAL_origin).Dot(HCAL_xaxis);
                  Double_t hcalY_exp = (HCAL_intersect - HCAL_origin).Dot(HCAL_yaxis);
                  Double_t dx = hcalX - hcalX_exp;
                  Double_t dy = hcalY - hcalY_exp;

                  // Calculating proton deflection angle
                  float sbsmagfrac = GetSBSFieldPerRun(rnum, sbsfields);
                  double BdL = sbsmagfrac * sbsmaxfield * sbsdipolegap;
                  double proton_thetabend = 0.3 * BdL / Ppprime.Vect().Mag(); // p*theta = 0.3*BdL
                  double proton_deflection = tan(proton_thetabend) * (hcaldist + hcalzoffset - (2.25 + sbsdipolegap / 2.0));

                  // -----------
                  // Corrected TH time calculations
                  // -----------
                  bool goodRF = false, goodTRIG = false;

                  double tref = thTrigTime - thTrigPhaseCorr - BBtrig_t0;

                  // We'll use bb.tdctrig branches for now; later we'll use the new convenience variables:
                  double RFtime = thRFTime + tref;
                  double TrigTime = thTrigTime - thTrigPhaseCorr - BBtrig_t0;

                  if (fabs(RFtime) < 1.e5)
                        goodRF = true;
                  if (fabs(TrigTime) < 1.e5)
                        goodTRIG = true;

                  double vz = trVz[0];
                  double pathl = trPathl[0];
                  double etof = pathl / 0.299792458 - etof0;
	  
                  double yhodo = trY[0] + zhodo * trPh[0];

                  double dLEFT = std::min(Lbar_hodo, std::max(0.0, Lbar_hodo / 2.0 - yhodo));
                  double dRIGHT = std::min(Lbar_hodo, std::max(0.0, Lbar_hodo / 2.0 + yhodo));

                  double RFcorr = RFtime + vz / 0.299792458 - bunch_spacing_ns * (floor((RFtime + vz / 0.299792458) / bunch_spacing_ns));

                  double HodoTmean = 0.0;

                  if (thTrIndex[0] == 0 && goodRF && goodTRIG)
                  {

                        // Fill the tree branches before applying spot cuts
                        T_dx = dx;
                        T_dy = dy;
                        T_pdef = proton_deflection;
                        T_atimeSH = shAtime;
                        T_atimePS = psAtime;
                        T_atimeHCAL = hcalAtime;
                        T_THfinal = HodoTmean;

                        // Crude p and n spot cuts irrespective of target type
                        pCut = pow((dx + proton_deflection - pspot_dxM) / (pspot_dxS * pspot_ndxS), 2) + pow((dy - pspot_dyM) / (pspot_dyS * pspot_ndyS), 2) <= 1.;
                        nCut = pow((dx - nspot_dxM) / (nspot_dxS * nspot_ndxS), 2) + pow((dy - nspot_dyM) / (nspot_dyS * nspot_ndyS), 2) <= 1.;

                        bool spotCut = pCut || nCut;
			
                        if (apply_spot_cut)
                              if (!spotCut)
                                    continue;

                        // applying time offset corrections
                        if (apply_th_timeoffset == 1)
                        {
                              double Tstart = 0.0;
                              double HodoTOTsum = 0.0;
                              double Tmean_corr = -1000.0;

                              for (int ibar = 0; ibar < int(thClsize[0]); ibar++)
                              {
                                    double tleft = thBTleft[0];
                                    double tright = thBTright[0];
                                    double totleft = thBTotleft[0];
                                    double totright = thBTotright[0];

                                    int ID = int(thBTId[0]);

                                    // WITHOUT RF corrections:
                                    double tleft_CORR = tleft - etof - tht0offsets[ID] + thwLoffsets[ID] * totleft - dLEFT / thvscintoffsets[ID] + tref - thRFoffsets[ID];
                                    double tright_CORR = tright - etof - tht0offsets[ID] + thwRoffsets[ID] * totright - dRIGHT / thvscintoffsets[ID] + tref - thRFoffsets[ID];
                                    double totmean = 0.5 * (totleft + totright);

                                    HodoTmean += totmean * 0.5 * (tleft_CORR + tright_CORR);
                                    HodoTOTsum += totmean;

                                    double tmean_CORR = 0.5 * (tleft_CORR + tright_CORR) - RFcorr;

                                    tleft_CORR -= RFcorr;
                                    tright_CORR -= RFcorr;

                                    double RF_bucket = floor(tmean_CORR / bunch_spacing_ns + 0.5);

                                    tmean_CORR -= bunch_spacing_ns * RF_bucket;
                                    tleft_CORR -= bunch_spacing_ns * RF_bucket;
                                    tright_CORR -= bunch_spacing_ns * RF_bucket;

                                    double tmean_old = thBTmean[ibar];
                                    double tdiff_old = thBTdiff[ibar];
                                    double tdiff_CORR = (tleft_CORR + dLEFT / thvscintoffsets[ID]) -
                                                      (tright_CORR + dRIGHT / thvscintoffsets[ID]);

                                    if (ibar == 0)
                                          Tmean_corr = tmean_CORR;

                                    htmean_vs_ID->Fill(ID, tmean_CORR);
                                    htmean_vs_ID_prof->Fill(ID, tmean_CORR, 1.);
                              }

                              HodoTmean /= HodoTOTsum;
                        }
                        else
                        {
                              HodoTmean = thTfinal[0];
                        }
                        // -----------

                        // applying atime offset corrections
                        if (apply_sh_atimeoffset == 1)
                        {
                              shAtime = shAtime - oldshoffsets[shIdblk] + newshoffsets[shIdblk];
                        }
                        else if (apply_sh_atimeoffset == 2)
                        {
                              shAtime -= const_sh_atimeoffset;
                        }
                        if (apply_ps_atimeoffset == 1)
                        {
                              psAtime = psAtime - oldpsoffsets[psIdblk] + newpsoffsets[psIdblk];
                        }
                        else if (apply_ps_atimeoffset == 2)
                        {
                              psAtime -= const_ps_atimeoffset;
                        }
                        if (apply_hcal_atimeoffset == 1)
                        {
                              hcalAtime = hcalAtime - oldhcaloffsets[hcalIdblk - 1] + newhcaloffsets[hcalIdblk - 1];
                        }
                        else if (apply_hcal_atimeoffset == 2)
                        {
                              hcalAtime -= const_hcal_atimeoffset;
                        }


                        // ------------

                        Double_t clusEngBBCal = psE + shE;
                        // E/p
                        h_EovP->Fill((clusEngBBCal / trP[0]));

                        // E/p vs. p
                        h2_EovP_vs_P->Fill(trP[0], clusEngBBCal / trP[0]);
                        h2_EovP_vs_P_prof->Fill(trP[0], clusEngBBCal / trP[0], 1.);

                        // Shower block related histos
                        h2_SHeng_vs_SHblk_raw->Fill(shColblk, shRowblk, shE);
                        h2_EovP_vs_SHblk_raw->Fill(shColblk, shRowblk, (clusEngBBCal / trP[0]));
                        h2_EovP_vs_PSblk_raw->Fill(psColblk, psRowblk, (clusEngBBCal / trP[0]));
                        h2_count->Fill(shColblk, shRowblk, 1.);

                        Double_t xtrATsh = trX[0] + zposSH * trTh[0];
                        Double_t ytrATsh = trY[0] + zposSH * trPh[0];
                        h2_EovP_vs_SHblk_trPOS_raw->Fill(ytrATsh, xtrATsh, (clusEngBBCal / trP[0]));
                        h2_count_trP->Fill(ytrATsh, xtrATsh, 1.);

                        // PreShower block related histos
                        Double_t xtrATps = trX[0] + zposPS * trTh[0];
                        Double_t ytrATps = trY[0] + zposPS * trPh[0];
                        h2_PSeng_vs_PSblk_raw->Fill(psColblk, psRowblk, psE);
                        h2_count_PS->Fill(psColblk, psRowblk, 1.);
                        h2_PSeng_vs_PSblk_trPOS_raw->Fill(ytrATps, xtrATps, psE);
                        h2_count_trP_PS->Fill(ytrATps, xtrATps, 1.);

                        h2_EovP_vs_rnum->Fill(itrrun, clusEngBBCal / trP[0]);
                        h2_EovP_vs_rnum_prof->Fill(itrrun, clusEngBBCal / trP[0], 1.);

                        // ADCTime related histos
                        h2_atimeSH_vs_rnum->Fill(itrrun, shAtime);
                        h2_atimeSH_vs_rnum_prof->Fill(itrrun, shAtime, 1.);
                        h2_atimePS_vs_rnum->Fill(itrrun, psAtime);
                        h2_atimePS_vs_rnum_prof->Fill(itrrun, psAtime, 1.);
                        h2_atimeHCAL_vs_rnum->Fill(itrrun, hcalAtime);
                        h2_atimeHCAL_vs_rnum_prof->Fill(itrrun, hcalAtime, 1.);

                        Double_t sh_atimeOff = HodoTmean - shAtime;
                        Double_t ps_atimeOff = HodoTmean - psAtime;
                        Double_t hcal_atimeOff = HodoTmean - hcalAtime;

                        h_THSH_diff->Fill(sh_atimeOff);
                        h_THPS_diff->Fill(ps_atimeOff);
                        h_THHCAL_diff->Fill(hcal_atimeOff);
                        h_SHHCAL_diff->Fill(shAtime - hcalAtime);
                        if (pCut) 
                        { 
                              h_THHCAL_diff_p->Fill(hcal_atimeOff);
                              h_SHHCAL_diff_p->Fill(shAtime - hcalAtime);
                        } else if (nCut) 
                        { 
                              h_THHCAL_diff_n->Fill(hcal_atimeOff);
                              h_SHHCAL_diff_n->Fill(shAtime - hcalAtime);
                        }

                        h2_ThShCoin_vs_blk->Fill(shIdblk, sh_atimeOff);
                        h2_ThShCoin_vs_blk_prof->Fill(shIdblk, sh_atimeOff, 1.);

                        h2_ThPsCoin_vs_blk->Fill(psIdblk, ps_atimeOff);
                        h2_ThPsCoin_vs_blk_prof->Fill(psIdblk, ps_atimeOff, 1.);

                        h2_ThHcalCoin_vs_blk->Fill(hcalIdblk, hcal_atimeOff);
                        h2_ThHcalCoin_vs_blk_prof->Fill(hcalIdblk - 1, hcal_atimeOff, 1.);

                        h2_ThShCoin_vs_rnum->Fill(itrrun, sh_atimeOff);
                        h2_ThShCoin_vs_rnum_prof->Fill(itrrun, sh_atimeOff, 1.);

                        h2_ThPsCoin_vs_rnum->Fill(itrrun, ps_atimeOff);
                        h2_ThPsCoin_vs_rnum_prof->Fill(itrrun, ps_atimeOff, 1.);

                        h2_ThHcalCoin_vs_rnum->Fill(itrrun, hcal_atimeOff);
                        h2_ThHcalCoin_vs_rnum_prof->Fill(itrrun, hcal_atimeOff, 1.);

                        h2_ShHcalCoin_vs_rnum->Fill(itrrun, shAtime - hcalAtime);
                        h2_ShHcalCoin_vs_rnum_prof->Fill(itrrun, shAtime - hcalAtime, 1.);

                        h2_PsHcalCoin_vs_rnum->Fill(itrrun, psAtime - hcalAtime);
                        h2_PsHcalCoin_vs_rnum_prof->Fill(itrrun, psAtime - hcalAtime, 1.);

                        // Track related histos
                        h2_EovP_vs_trX->Fill(trX[0], (clusEngBBCal / trP[0]));
                        h2_EovP_vs_trY->Fill(trY[0], (clusEngBBCal / trP[0]));
                        h2_EovP_vs_trTh->Fill(trTh[0], (clusEngBBCal / trP[0]));
                        h2_EovP_vs_trPh->Fill(trPh[0], (clusEngBBCal / trP[0]));
                        // h2_PSeng_vs_trX->Fill( trX[0], psE );
                        // h2_PSeng_vs_trY->Fill( trY[0], psE );
                        h2_PSeng_vs_trXatPS->Fill(xtrATps, psE);
                        h2_PSeng_vs_trYatPS->Fill(ytrATps, psE);

                        Tout->Fill();
                  }
            }

      } // event loop
      cout << endl
           << endl;

      // customizing histo ranges
      h2_SHeng_vs_SHblk->Divide(h2_SHeng_vs_SHblk_raw, h2_count);
      h2_SHeng_vs_SHblk->GetZaxis()->SetRangeUser(h2_SHeng_vs_blk_low, h2_SHeng_vs_blk_up);
      //
      h2_EovP_vs_SHblk->Divide(h2_EovP_vs_SHblk_raw, h2_count);
      h2_EovP_vs_SHblk->GetZaxis()->SetRangeUser(0.8, 1.2);
      h2_EovP_vs_SHblk_trPOS->Divide(h2_EovP_vs_SHblk_trPOS_raw, h2_count_trP);
      h2_EovP_vs_SHblk_trPOS->GetZaxis()->SetRangeUser(0.8, 1.2);
      // PS
      h2_EovP_vs_PSblk->Divide(h2_EovP_vs_PSblk_raw, h2_count_PS);
      h2_EovP_vs_PSblk->GetZaxis()->SetRangeUser(0.8, 1.2);
      //
      h2_PSeng_vs_PSblk->Divide(h2_PSeng_vs_PSblk_raw, h2_count_PS);
      h2_PSeng_vs_PSblk->GetZaxis()->SetRangeUser(h2_PSeng_vs_blk_low, h2_PSeng_vs_blk_up);
      //
      h2_PSeng_vs_PSblk_trPOS->Divide(h2_PSeng_vs_PSblk_trPOS_raw, h2_count_trP_PS);
      h2_PSeng_vs_PSblk_trPOS->GetZaxis()->SetRangeUser(h2_PSeng_vs_blk_low, h2_PSeng_vs_blk_up);

      // customizing histos with run # on the x-axis
      Custm2DRnumHisto(h2_atimeSH_vs_rnum, lrnum);
      Custm2DRnumHisto(h2_atimePS_vs_rnum, lrnum);
      Custm2DRnumHisto(h2_atimeHCAL_vs_rnum, lrnum);
      Custm2DRnumHisto(h2_ThShCoin_vs_rnum, lrnum);
      Custm2DRnumHisto(h2_ThPsCoin_vs_rnum, lrnum);
      Custm2DRnumHisto(h2_ThHcalCoin_vs_rnum, lrnum);
      Custm2DRnumHisto(h2_ShHcalCoin_vs_rnum, lrnum);
      Custm2DRnumHisto(h2_PsHcalCoin_vs_rnum, lrnum);
      CustmProfHisto(htmean_vs_ID_prof);
      CustmProfHisto(h2_EovP_vs_P_prof);
      CustmProfHisto(h2_EovP_vs_rnum_prof);
      CustmProfHisto(h2_atimeSH_vs_rnum_prof);
      CustmProfHisto(h2_atimePS_vs_rnum_prof);
      CustmProfHisto(h2_atimeHCAL_vs_rnum_prof);
      CustmProfHisto(h2_ThShCoin_vs_blk_prof);
      CustmProfHisto(h2_ThShCoin_vs_rnum_prof);
      CustmProfHisto(h2_ThPsCoin_vs_blk_prof);
      CustmProfHisto(h2_ThPsCoin_vs_rnum_prof);
      CustmProfHisto(h2_ThHcalCoin_vs_blk_prof);
      CustmProfHisto(h2_ThHcalCoin_vs_rnum_prof);
      CustmProfHisto(h2_ShHcalCoin_vs_rnum_prof);
      CustmProfHisto(h2_PsHcalCoin_vs_rnum_prof);

      // creating a canvas to show all the interesting plots
      // printing out the canvas
      TString plotsFile = outFileBase.ReplaceAll(".root", ".pdf");

      TCanvas *c1 = new TCanvas("c1", "E/p", 1500, 1200);
      c1->Divide(3, 2);
      //
      c1->cd(1);
      gPad->SetGridx();
      gStyle->SetOptFit(1111);
      Int_t maxBin = h_EovP->GetMaximumBin();
      Double_t binW = h_EovP->GetBinWidth(maxBin), norm = h_EovP->GetMaximum();
      Double_t mean = h_EovP->GetMean(), stdev = h_EovP->GetStdDev();
      Double_t lower_lim = h_EovP_min + maxBin * binW - 1. * stdev;
      Double_t upper_lim = h_EovP_min + maxBin * binW + 1. * stdev;
      TF1 *fitg = new TF1("fitg", "gaus", h_EovP_min, h_EovP_max);
      fitg->SetRange(lower_lim, upper_lim);
      fitg->SetParameters(norm, mean, stdev);
      fitg->SetLineWidth(2);
      fitg->SetLineColor(2);
      h_EovP->Fit(fitg, "QR");
      h_EovP->SetLineWidth(2);
      h_EovP->SetLineColor(1);
      h_EovP->Draw();
      //
      c1->cd(2);
      gPad->SetGridy();
      gStyle->SetErrorX(0.0001);
      h2_EovP_vs_P->SetStats(0);
      h2_EovP_vs_P->Draw("colz");
      h2_EovP_vs_P_prof->Draw("same");
      //
      // c1->cd(3);
      // gPad->SetGridy();
      // gStyle->SetErrorX(0.0001);
      // // h2_PSeng_vs_PSblk->SetStats(0);
      // // h2_PSeng_vs_PSblk->Draw("colz");
      // h2_ADCtime_diff_wrt_Hodo->SetStats(0);
      // h2_ADCtime_diff_wrt_Hodo->Draw("colz");
      // h2_ADCtime_diff_wrt_Hodo_prof->SetMarkerStyle(7);
      // h2_ADCtime_diff_wrt_Hodo_prof->SetMarkerColor(2);
      // h2_ADCtime_diff_wrt_Hodo_prof->SetStats(0);
      // h2_ADCtime_diff_wrt_Hodo_prof->Draw("same")
      //
      c1->cd(3);
      h2_EovP_vs_SHblk->SetStats(0);
      h2_EovP_vs_SHblk->Draw("colz text");
      //
      c1->cd(4);
      // h2_EovP_vs_SHblk->SetStats(0);
      // h2_EovP_vs_SHblk->Draw("colz");
      h2_EovP_vs_PSblk->SetStats(0);
      h2_EovP_vs_PSblk->Draw("colz text");
      //
      c1->cd(5);
      h2_SHeng_vs_SHblk->SetStats(0);
      h2_SHeng_vs_SHblk->Draw("colz text");
      //
      c1->cd(6);
      h2_PSeng_vs_PSblk->SetStats(0);
      h2_PSeng_vs_PSblk->Draw("colz text");
      c1->SaveAs(Form("%s[", plotsFile.Data()), "pdf");
      c1->SaveAs(Form("%s", plotsFile.Data()), "pdf");
      c1->Write();
      // *****

      // creating another canvas to show all the interesting plots
      TCanvas *c2 = new TCanvas("c2", "E/p vs Track params", 1500, 1200);
      c2->Divide(3, 2);
      //
      c2->cd(1);
      gPad->SetGridy();
      h2_EovP_vs_trX->SetStats(0);
      h2_EovP_vs_trX->Draw("colz");
      //
      c2->cd(2);
      gPad->SetGridy();
      h2_EovP_vs_trY->SetStats(0);
      h2_EovP_vs_trY->Draw("colz");
      //
      c2->cd(3);
      gPad->SetGridy();
      h2_EovP_vs_trTh->SetStats(0);
      h2_EovP_vs_trTh->Draw("colz");
      //
      c2->cd(4);
      gPad->SetGridy();
      h2_EovP_vs_trPh->SetStats(0);
      h2_EovP_vs_trPh->Draw("colz");
      //
      c2->cd(5);
      gPad->SetGridy();
      // h2_PSeng_vs_trX->SetStats(0);
      // h2_PSeng_vs_trX->Draw("colz");
      h2_PSeng_vs_trXatPS->SetStats(0);
      h2_PSeng_vs_trXatPS->Draw("colz");
      //
      c2->cd(6);
      gPad->SetGridy();
      // h2_PSeng_vs_trY->SetStats(0);
      // h2_PSeng_vs_trY->Draw("colz");
      h2_PSeng_vs_trYatPS->SetStats(0);
      h2_PSeng_vs_trYatPS->Draw("colz");
      c2->SaveAs(Form("%s", plotsFile.Data()), "pdf");
      c2->Write();
      // *****

      /**** Canvas 3 (E/p vs. run number) ****/
      TCanvas *c3 = new TCanvas("c3", "E/p vs rnum", 1200, 1000);
      c3->Divide(1, 2);
      c3->cd(1); //
      gPad->SetGridy();
      gStyle->SetErrorX(0.0001);
      Custm2DRnumHisto(h2_EovP_vs_rnum, lrnum);
      h2_EovP_vs_rnum->Draw("colz");
      h2_EovP_vs_rnum_prof->Draw("same");
      c3->SaveAs(Form("%s", plotsFile.Data()), "pdf");
      c3->Write();

      /**** Canvas 6 (HCAL-SH coin vs. rnum) ****/
      TCanvas *chodo = new TCanvas("chodo", "TH tfinal vs blk", 1200, 800);
      chodo->Divide(1, 2);
      chodo->cd(1); //
      gPad->SetGridy();
      htmean_vs_ID->SetStats(0);
      htmean_vs_ID->Draw("colz");
      htmean_vs_ID_prof->Draw("same");
      chodo->SaveAs(Form("%s", plotsFile.Data()));
      chodo->Write();

      /**** Canvas 4 (SH off. vs. rnum) ****/
      TCanvas *c4 = new TCanvas("c4", "TH-BBCAL coin vs blk", 1200, 800);
      c4->Divide(1, 2);
      c4->cd(1); //
      gPad->SetGridy();
      h2_ThShCoin_vs_blk->SetStats(0);
      h2_ThShCoin_vs_blk->Draw("colz");
      h2_ThShCoin_vs_blk_prof->Draw("same");
      c4->cd(2); //
      gPad->SetGridy();
      h2_ThPsCoin_vs_blk->SetStats(0);
      h2_ThPsCoin_vs_blk->Draw("colz");
      h2_ThPsCoin_vs_blk_prof->Draw("same");
      c4->SaveAs(Form("%s", plotsFile.Data()));
      c4->Write();
      //**** -- ***//

      /**** Canvas 5 (PS off. vs. rnum) ****/
      TCanvas *c5 = new TCanvas("c5", "TH-BBCAL coin vs rnum", 1200, 800);
      c5->Divide(1, 2);
      c5->cd(1); //
      gPad->SetGridy();
      h2_ThShCoin_vs_rnum->SetStats(0);
      h2_ThShCoin_vs_rnum->Draw("colz");
      h2_ThShCoin_vs_rnum_prof->Draw("same");
      c5->cd(2); //
      gPad->SetGridy();
      h2_ThPsCoin_vs_rnum->SetStats(0);
      h2_ThPsCoin_vs_rnum->Draw("colz");
      h2_ThPsCoin_vs_rnum_prof->Draw("same");
      c5->SaveAs(Form("%s", plotsFile.Data()));
      c5->Write();
      //**** -- ***//

      /**** Canvas 6 (HCAL-SH coin vs. rnum) ****/
      TCanvas *c6 = new TCanvas("c6", "HCAL-BBCAL coin vs rnum", 1200, 800);
      c6->Divide(1, 2);
      c6->cd(1); //
      gPad->SetGridy();
      h2_ShHcalCoin_vs_rnum->SetStats(0);
      h2_ShHcalCoin_vs_rnum->Draw("colz");
      h2_ShHcalCoin_vs_rnum_prof->Draw("same");
      c6->cd(2); //
      gPad->SetGridy();
      h2_PsHcalCoin_vs_rnum->SetStats(0);
      h2_PsHcalCoin_vs_rnum->Draw("colz");
      h2_PsHcalCoin_vs_rnum_prof->Draw("same");
      c6->SaveAs(Form("%s", plotsFile.Data()));
      c6->Write();

      /**** Canvas 4 (SH off. vs. rnum) ****/
      TCanvas *c7 = new TCanvas("c7", "TH-BBCAL coin vs blk", 1200, 800);
      c7->Divide(1, 2);
      c7->cd(1); //
      gPad->SetGridy();
      h2_ThHcalCoin_vs_blk->SetStats(0);
      h2_ThHcalCoin_vs_blk->Draw("colz");
      h2_ThHcalCoin_vs_blk_prof->Draw("same");
      c7->cd(2); //
      gPad->SetGridy();
      h2_ThHcalCoin_vs_rnum->SetStats(0);
      h2_ThHcalCoin_vs_rnum->Draw("colz");
      h2_ThHcalCoin_vs_rnum_prof->Draw("same");
      c7->SaveAs(Form("%s", plotsFile.Data()));
      c7->Write();

      /**** Canvas 9 (SH atime vs. rnum) ****/
      TCanvas *c8 = new TCanvas("c8", "BBCAL atime vs rnum", 1200, 800);
      c8->Divide(1, 3);
      c8->cd(1); //
      gPad->SetGridy();
      h2_atimeSH_vs_rnum->SetStats(0);
      h2_atimeSH_vs_rnum->Draw("colz");
      h2_atimeSH_vs_rnum_prof->Draw("same");
      c8->cd(2); //
      gPad->SetGridy();
      h2_atimePS_vs_rnum->SetStats(0);
      h2_atimePS_vs_rnum->Draw("colz");
      h2_atimePS_vs_rnum_prof->Draw("same");
      c8->cd(3); //
      gPad->SetGridy();
      h2_atimeHCAL_vs_rnum->SetStats(0);
      h2_atimeHCAL_vs_rnum->Draw("colz");
      h2_atimeHCAL_vs_rnum_prof->Draw("same");
      c8->SaveAs(Form("%s", plotsFile.Data()));
      c8->Write();

      /**** Canvas 9 (SH atime vs. rnum) ****/
      TCanvas *c9 = new TCanvas("c9", "Timing plots", 1200, 800);
      gStyle->SetOptStat("e");
      gStyle->SetOptFit(1);
      c9->Divide(2, 2);
      c9->cd(1); //
      gPad->SetGridx();
      TF1 *f1 = FitTimePeak(h_THSH_diff);
      h_THSH_diff->Draw();
      // double fitparams1[3];
      // fcoin->GetParameters(&fitparams[0]);
      c9->cd(2); //
      gPad->SetGridx();
      TF1 *f2 = FitTimePeak(h_THPS_diff);
      h_THPS_diff->Draw();
      c9->cd(3); //
      gPad->SetGridx();
      TF1 *f3 = FitTimePeak(h_THHCAL_diff);
      h_THHCAL_diff->Draw();
      h_THHCAL_diff->SetLineColor(kBlue);
      h_THHCAL_diff_p->Draw("same");
      h_THHCAL_diff_p->SetLineColor(kRed);
      h_THHCAL_diff_n->Draw("same");
      h_THHCAL_diff_n->SetLineColor(kBlack);
      c9->cd(4); //
      gPad->SetGridx();
      TF1 *f4 = FitTimePeak(h_SHHCAL_diff);
      h_SHHCAL_diff->Draw();
      h_SHHCAL_diff->SetLineColor(kBlue);
      h_SHHCAL_diff_p->Draw("same");
      h_SHHCAL_diff_p->SetLineColor(kRed);
      h_SHHCAL_diff_n->Draw("same");
      h_SHHCAL_diff_n->SetLineColor(kBlack);
      c9->SaveAs(Form("%s", plotsFile.Data()));
      c9->SaveAs(Form("%s]", plotsFile.Data()));
      c9->Write();

      //**** -- ***//

      cout << "Finishing analysis..." << endl;
      cout << " --------- " << endl;
      cout << " Resulting histograms written to : " << outFile << endl;
      cout << " Generated plots saved to : " << plotsFile.Data() << endl;
      cout << " --------- " << endl;

      sw->Stop();
      std::cout << "CPU time = " << sw->CpuTime() << "s. Real time = " << sw->RealTime() << "s.\n\n";

      fout->Write();
      sw->Delete();
      C->Delete();
}

// **** ========== Useful functions ========== ****
// returns today's date
std::string GetDate()
{
      time_t now = time(0);
      tm ltm = *localtime(&now);
      std::string yyyy = to_string(1900 + ltm.tm_year);
      std::string mm = to_string(1 + ltm.tm_mon);
      std::string dd = to_string(ltm.tm_mday);
      std::string date = mm + '/' + dd + '/' + yyyy;
      return date;
}

// customizes profile histograms
void CustmProfHisto(TProfile *hprof)
{
      hprof->SetStats(0);
      hprof->SetMarkerStyle(20);
      hprof->SetMarkerColor(2);
}

// Customizes 2D histos with run # on the X-axis
void Custm2DRnumHisto(TH2F *h, std::vector<std::string> const &lrnum)
{
      h->SetStats(0);
      h->GetXaxis()->SetLabelSize(0.05);
      h->GetXaxis()->SetRange(1, lrnum.size());
      for (int i = 0; i < lrnum.size(); i++)
            h->GetXaxis()->SetBinLabel(i + 1, lrnum[i].c_str());
      if (lrnum.size() > 15)
            h->LabelsOption("v", "X");
}

// Returns NDC value for a given abscissa
double GetNDC(double x)
{
      gPad->Update();
      return (x - gPad->GetX1()) / (gPad->GetX2() - gPad->GetX1());
}

// Reads run ranges per SBS field settings
float GetSBSFieldPerRun(int run, const std::vector<RunRanges> &sbsfields)
{
      for (const auto &entry : sbsfields)
      {
            if (run >= entry.rmin && run <= entry.rmax)
                  return entry.sbsmagfrac;
      }
      throw std::runtime_error("No matching run range");
}

// Reads old offsets
std::vector<double> ReadOffsets(char const *infile, int nchan)
{

      std::vector<double> oldoffsets(nchan, 0.0);
      ifstream oldoffsetsfile(infile);

      if (oldoffsetsfile)
      {
            int npar = 0;
            double par = 0.0;
            while (oldoffsetsfile >> par)
            {
                  if (npar < nchan)
                  {
                        oldoffsets[npar] = par;
                  }
                  npar++;
            }

            if (npar != nchan)
            {
                  std::cerr << Form("Error: %s file contains incorrect number of entries; abort!", infile) << endl;
                  exit(-1);
            }
      }

      return oldoffsets;
}

//----------------------------------------------------------
TF1 *FitTimePeak(TH1F *h)
{
      // function to fit time histogram to find the corresponding mean and sigma.
      // it fits the time peak twice for better precision.

      // first fit
      double xmax = h->GetXaxis()->GetBinCenter(h->GetMaximumBin()); // x position of the bin with the highest content (i.e. the center of the good coin peak)
      double minfitR = xmax - 1.5;                                   // min fit range
      double maxfitR = xmax + 1.5;                                   // max fit range
      // defining fit function
      TF1 *fitg1 = new TF1("fit", "gaus", -8, 8);
      fitg1->SetRange(minfitR, maxfitR);
      h->Fit(fitg1, "NO+RQ");
      // get fit parameters from the first fit
      double param[3];
      fitg1->GetParameters(param);

      // second fit
      minfitR = param[1] - 2. * param[2];
      maxfitR = param[1] + 2. * param[2];
      TF1 *fitg2 = new TF1("fit", "gaus", minfitR, maxfitR);
      fitg1->SetRange(minfitR, maxfitR);
      fitg1->SetParameters(&param[0]);
      h->Fit(fitg2, "RQ");

      return fitg2;
}
