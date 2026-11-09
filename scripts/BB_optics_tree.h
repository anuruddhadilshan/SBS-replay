//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Sep 25 21:06:44 2026 by ROOT version 6.36.08
// from TChain T/
//////////////////////////////////////////////////////////

#ifndef BB_optics_tree_h
#define BB_optics_tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "THaEvent.h"
#include "THaEvent.h"

class BB_optics_tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        ax_new;
   Double_t        bx_new;
   Double_t        ay_new;
   Double_t        by_new;
   Double_t        targx;
   Double_t        targy;
   Double_t        scalhel_true_hel;
   Double_t        scalhel_hel_stable;
   Int_t           Ndata_bb_bbtrig_a_amp_p;
   Double_t        bb_bbtrig_a_amp_p[7];   //[Ndata.bb.bbtrig.a_amp_p]
   Int_t           Ndata_bb_bbtrig_a_time;
   Double_t        bb_bbtrig_a_time[7];   //[Ndata.bb.bbtrig.a_time]
   Int_t           Ndata_bb_bbtrig_adcelemID;
   Double_t        bb_bbtrig_adcelemID[7];   //[Ndata.bb.bbtrig.adcelemID]
   Int_t           Ndata_bb_bbtrig_tdc;
   Double_t        bb_bbtrig_tdc[5];   //[Ndata.bb.bbtrig.tdc]
   Int_t           Ndata_bb_bbtrig_tdcelemID;
   Double_t        bb_bbtrig_tdcelemID[5];   //[Ndata.bb.bbtrig.tdcelemID]
   Int_t           Ndata_bb_eps_over_etot;
   Double_t        bb_eps_over_etot[1];   //[Ndata.bb.eps_over_etot]
   Int_t           Ndata_bb_etot_over_p;
   Double_t        bb_etot_over_p[1];   //[Ndata.bb.etot_over_p]
   Int_t           Ndata_bb_gem_hit_ADCU;
   Double_t        bb_gem_hit_ADCU[5];   //[Ndata.bb.gem.hit.ADCU]
   Int_t           Ndata_bb_gem_hit_ADCU_deconv;
   Double_t        bb_gem_hit_ADCU_deconv[5];   //[Ndata.bb.gem.hit.ADCU_deconv]
   Int_t           Ndata_bb_gem_hit_ADCV;
   Double_t        bb_gem_hit_ADCV[5];   //[Ndata.bb.gem.hit.ADCV]
   Int_t           Ndata_bb_gem_hit_ADCV_deconv;
   Double_t        bb_gem_hit_ADCV_deconv[5];   //[Ndata.bb.gem.hit.ADCV_deconv]
   Int_t           Ndata_bb_gem_hit_ADCasym;
   Double_t        bb_gem_hit_ADCasym[5];   //[Ndata.bb.gem.hit.ADCasym]
   Int_t           Ndata_bb_gem_hit_ADCasym_deconv;
   Double_t        bb_gem_hit_ADCasym_deconv[5];   //[Ndata.bb.gem.hit.ADCasym_deconv]
   Int_t           Ndata_bb_gem_hit_ADCavg;
   Double_t        bb_gem_hit_ADCavg[5];   //[Ndata.bb.gem.hit.ADCavg]
   Int_t           Ndata_bb_gem_hit_ADCavg_deconv;
   Double_t        bb_gem_hit_ADCavg_deconv[5];   //[Ndata.bb.gem.hit.ADCavg_deconv]
   Int_t           Ndata_bb_gem_hit_ADCfrac0_Umax;
   Double_t        bb_gem_hit_ADCfrac0_Umax[5];   //[Ndata.bb.gem.hit.ADCfrac0_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac0_Vmax;
   Double_t        bb_gem_hit_ADCfrac0_Vmax[5];   //[Ndata.bb.gem.hit.ADCfrac0_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac1_Umax;
   Double_t        bb_gem_hit_ADCfrac1_Umax[5];   //[Ndata.bb.gem.hit.ADCfrac1_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac1_Vmax;
   Double_t        bb_gem_hit_ADCfrac1_Vmax[5];   //[Ndata.bb.gem.hit.ADCfrac1_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac2_Umax;
   Double_t        bb_gem_hit_ADCfrac2_Umax[5];   //[Ndata.bb.gem.hit.ADCfrac2_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac2_Vmax;
   Double_t        bb_gem_hit_ADCfrac2_Vmax[5];   //[Ndata.bb.gem.hit.ADCfrac2_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac3_Umax;
   Double_t        bb_gem_hit_ADCfrac3_Umax[5];   //[Ndata.bb.gem.hit.ADCfrac3_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac3_Vmax;
   Double_t        bb_gem_hit_ADCfrac3_Vmax[5];   //[Ndata.bb.gem.hit.ADCfrac3_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac4_Umax;
   Double_t        bb_gem_hit_ADCfrac4_Umax[5];   //[Ndata.bb.gem.hit.ADCfrac4_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac4_Vmax;
   Double_t        bb_gem_hit_ADCfrac4_Vmax[5];   //[Ndata.bb.gem.hit.ADCfrac4_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac5_Umax;
   Double_t        bb_gem_hit_ADCfrac5_Umax[5];   //[Ndata.bb.gem.hit.ADCfrac5_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac5_Vmax;
   Double_t        bb_gem_hit_ADCfrac5_Vmax[5];   //[Ndata.bb.gem.hit.ADCfrac5_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCmaxcomboUclust_deconv;
   Double_t        bb_gem_hit_ADCmaxcomboUclust_deconv[5];   //[Ndata.bb.gem.hit.ADCmaxcomboUclust_deconv]
   Int_t           Ndata_bb_gem_hit_ADCmaxcomboVclust_deconv;
   Double_t        bb_gem_hit_ADCmaxcomboVclust_deconv[5];   //[Ndata.bb.gem.hit.ADCmaxcomboVclust_deconv]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampU;
   Double_t        bb_gem_hit_ADCmaxsampU[5];   //[Ndata.bb.gem.hit.ADCmaxsampU]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampUclust;
   Double_t        bb_gem_hit_ADCmaxsampUclust[5];   //[Ndata.bb.gem.hit.ADCmaxsampUclust]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampUclust_deconv;
   Double_t        bb_gem_hit_ADCmaxsampUclust_deconv[5];   //[Ndata.bb.gem.hit.ADCmaxsampUclust_deconv]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampV;
   Double_t        bb_gem_hit_ADCmaxsampV[5];   //[Ndata.bb.gem.hit.ADCmaxsampV]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampVclust;
   Double_t        bb_gem_hit_ADCmaxsampVclust[5];   //[Ndata.bb.gem.hit.ADCmaxsampVclust]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampVclust_deconv;
   Double_t        bb_gem_hit_ADCmaxsampVclust_deconv[5];   //[Ndata.bb.gem.hit.ADCmaxsampVclust_deconv]
   Int_t           Ndata_bb_gem_hit_ADCmaxstripU;
   Double_t        bb_gem_hit_ADCmaxstripU[5];   //[Ndata.bb.gem.hit.ADCmaxstripU]
   Int_t           Ndata_bb_gem_hit_ADCmaxstripV;
   Double_t        bb_gem_hit_ADCmaxstripV[5];   //[Ndata.bb.gem.hit.ADCmaxstripV]
   Int_t           Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_U;
   Double_t        bb_gem_hit_BUILD_ALL_SAMPLES_U[5];   //[Ndata.bb.gem.hit.BUILD_ALL_SAMPLES_U]
   Int_t           Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_V;
   Double_t        bb_gem_hit_BUILD_ALL_SAMPLES_V[5];   //[Ndata.bb.gem.hit.BUILD_ALL_SAMPLES_V]
   Int_t           Ndata_bb_gem_hit_CM_GOOD_U;
   Double_t        bb_gem_hit_CM_GOOD_U[5];   //[Ndata.bb.gem.hit.CM_GOOD_U]
   Int_t           Ndata_bb_gem_hit_CM_GOOD_V;
   Double_t        bb_gem_hit_CM_GOOD_V[5];   //[Ndata.bb.gem.hit.CM_GOOD_V]
   Int_t           Ndata_bb_gem_hit_DeconvADC0_Umax;
   Double_t        bb_gem_hit_DeconvADC0_Umax[5];   //[Ndata.bb.gem.hit.DeconvADC0_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC0_Vmax;
   Double_t        bb_gem_hit_DeconvADC0_Vmax[5];   //[Ndata.bb.gem.hit.DeconvADC0_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC1_Umax;
   Double_t        bb_gem_hit_DeconvADC1_Umax[5];   //[Ndata.bb.gem.hit.DeconvADC1_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC1_Vmax;
   Double_t        bb_gem_hit_DeconvADC1_Vmax[5];   //[Ndata.bb.gem.hit.DeconvADC1_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC2_Umax;
   Double_t        bb_gem_hit_DeconvADC2_Umax[5];   //[Ndata.bb.gem.hit.DeconvADC2_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC2_Vmax;
   Double_t        bb_gem_hit_DeconvADC2_Vmax[5];   //[Ndata.bb.gem.hit.DeconvADC2_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC3_Umax;
   Double_t        bb_gem_hit_DeconvADC3_Umax[5];   //[Ndata.bb.gem.hit.DeconvADC3_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC3_Vmax;
   Double_t        bb_gem_hit_DeconvADC3_Vmax[5];   //[Ndata.bb.gem.hit.DeconvADC3_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC4_Umax;
   Double_t        bb_gem_hit_DeconvADC4_Umax[5];   //[Ndata.bb.gem.hit.DeconvADC4_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC4_Vmax;
   Double_t        bb_gem_hit_DeconvADC4_Vmax[5];   //[Ndata.bb.gem.hit.DeconvADC4_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC5_Umax;
   Double_t        bb_gem_hit_DeconvADC5_Umax[5];   //[Ndata.bb.gem.hit.DeconvADC5_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC5_Vmax;
   Double_t        bb_gem_hit_DeconvADC5_Vmax[5];   //[Ndata.bb.gem.hit.DeconvADC5_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxcomboU;
   Double_t        bb_gem_hit_DeconvADCmaxcomboU[5];   //[Ndata.bb.gem.hit.DeconvADCmaxcomboU]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxcomboV;
   Double_t        bb_gem_hit_DeconvADCmaxcomboV[5];   //[Ndata.bb.gem.hit.DeconvADCmaxcomboV]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxsampU;
   Double_t        bb_gem_hit_DeconvADCmaxsampU[5];   //[Ndata.bb.gem.hit.DeconvADCmaxsampU]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxsampV;
   Double_t        bb_gem_hit_DeconvADCmaxsampV[5];   //[Ndata.bb.gem.hit.DeconvADCmaxsampV]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxstripU;
   Double_t        bb_gem_hit_DeconvADCmaxstripU[5];   //[Ndata.bb.gem.hit.DeconvADCmaxstripU]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxstripV;
   Double_t        bb_gem_hit_DeconvADCmaxstripV[5];   //[Ndata.bb.gem.hit.DeconvADCmaxstripV]
   Int_t           Ndata_bb_gem_hit_ENABLE_CM_U;
   Double_t        bb_gem_hit_ENABLE_CM_U[5];   //[Ndata.bb.gem.hit.ENABLE_CM_U]
   Int_t           Ndata_bb_gem_hit_ENABLE_CM_V;
   Double_t        bb_gem_hit_ENABLE_CM_V[5];   //[Ndata.bb.gem.hit.ENABLE_CM_V]
   Int_t           Ndata_bb_gem_hit_TSchi2_Umax;
   Double_t        bb_gem_hit_TSchi2_Umax[5];   //[Ndata.bb.gem.hit.TSchi2_Umax]
   Int_t           Ndata_bb_gem_hit_TSchi2_Vmax;
   Double_t        bb_gem_hit_TSchi2_Vmax[5];   //[Ndata.bb.gem.hit.TSchi2_Vmax]
   Int_t           Ndata_bb_gem_hit_TSprob_Umax;
   Double_t        bb_gem_hit_TSprob_Umax[5];   //[Ndata.bb.gem.hit.TSprob_Umax]
   Int_t           Ndata_bb_gem_hit_TSprob_Vmax;
   Double_t        bb_gem_hit_TSprob_Vmax[5];   //[Ndata.bb.gem.hit.TSprob_Vmax]
   Int_t           Ndata_bb_gem_hit_Tavg;
   Double_t        bb_gem_hit_Tavg[5];   //[Ndata.bb.gem.hit.Tavg]
   Int_t           Ndata_bb_gem_hit_Tavg_corr;
   Double_t        bb_gem_hit_Tavg_corr[5];   //[Ndata.bb.gem.hit.Tavg_corr]
   Int_t           Ndata_bb_gem_hit_Tavg_deconv;
   Double_t        bb_gem_hit_Tavg_deconv[5];   //[Ndata.bb.gem.hit.Tavg_deconv]
   Int_t           Ndata_bb_gem_hit_Tavg_fit;
   Double_t        bb_gem_hit_Tavg_fit[5];   //[Ndata.bb.gem.hit.Tavg_fit]
   Int_t           Ndata_bb_gem_hit_Ugain;
   Double_t        bb_gem_hit_Ugain[5];   //[Ndata.bb.gem.hit.Ugain]
   Int_t           Ndata_bb_gem_hit_Utime;
   Double_t        bb_gem_hit_Utime[5];   //[Ndata.bb.gem.hit.Utime]
   Int_t           Ndata_bb_gem_hit_UtimeDeconv;
   Double_t        bb_gem_hit_UtimeDeconv[5];   //[Ndata.bb.gem.hit.UtimeDeconv]
   Int_t           Ndata_bb_gem_hit_UtimeFit;
   Double_t        bb_gem_hit_UtimeFit[5];   //[Ndata.bb.gem.hit.UtimeFit]
   Int_t           Ndata_bb_gem_hit_UtimeMaxStrip;
   Double_t        bb_gem_hit_UtimeMaxStrip[5];   //[Ndata.bb.gem.hit.UtimeMaxStrip]
   Int_t           Ndata_bb_gem_hit_UtimeMaxStripDeconv;
   Double_t        bb_gem_hit_UtimeMaxStripDeconv[5];   //[Ndata.bb.gem.hit.UtimeMaxStripDeconv]
   Int_t           Ndata_bb_gem_hit_UtimeMaxStripFit;
   Double_t        bb_gem_hit_UtimeMaxStripFit[5];   //[Ndata.bb.gem.hit.UtimeMaxStripFit]
   Int_t           Ndata_bb_gem_hit_Vgain;
   Double_t        bb_gem_hit_Vgain[5];   //[Ndata.bb.gem.hit.Vgain]
   Int_t           Ndata_bb_gem_hit_Vtime;
   Double_t        bb_gem_hit_Vtime[5];   //[Ndata.bb.gem.hit.Vtime]
   Int_t           Ndata_bb_gem_hit_VtimeDeconv;
   Double_t        bb_gem_hit_VtimeDeconv[5];   //[Ndata.bb.gem.hit.VtimeDeconv]
   Int_t           Ndata_bb_gem_hit_VtimeFit;
   Double_t        bb_gem_hit_VtimeFit[5];   //[Ndata.bb.gem.hit.VtimeFit]
   Int_t           Ndata_bb_gem_hit_VtimeMaxStrip;
   Double_t        bb_gem_hit_VtimeMaxStrip[5];   //[Ndata.bb.gem.hit.VtimeMaxStrip]
   Int_t           Ndata_bb_gem_hit_VtimeMaxStripDeconv;
   Double_t        bb_gem_hit_VtimeMaxStripDeconv[5];   //[Ndata.bb.gem.hit.VtimeMaxStripDeconv]
   Int_t           Ndata_bb_gem_hit_VtimeMaxStripFit;
   Double_t        bb_gem_hit_VtimeMaxStripFit[5];   //[Ndata.bb.gem.hit.VtimeMaxStripFit]
   Int_t           Ndata_bb_gem_hit_adc_id_U;
   Double_t        bb_gem_hit_adc_id_U[5];   //[Ndata.bb.gem.hit.adc_id_U]
   Int_t           Ndata_bb_gem_hit_adc_id_V;
   Double_t        bb_gem_hit_adc_id_V[5];   //[Ndata.bb.gem.hit.adc_id_V]
   Int_t           Ndata_bb_gem_hit_ccor_clust;
   Double_t        bb_gem_hit_ccor_clust[5];   //[Ndata.bb.gem.hit.ccor_clust]
   Int_t           Ndata_bb_gem_hit_ccor_clust_deconv;
   Double_t        bb_gem_hit_ccor_clust_deconv[5];   //[Ndata.bb.gem.hit.ccor_clust_deconv]
   Int_t           Ndata_bb_gem_hit_ccor_strip;
   Double_t        bb_gem_hit_ccor_strip[5];   //[Ndata.bb.gem.hit.ccor_strip]
   Int_t           Ndata_bb_gem_hit_ccor_strip_deconv;
   Double_t        bb_gem_hit_ccor_strip_deconv[5];   //[Ndata.bb.gem.hit.ccor_strip_deconv]
   Int_t           Ndata_bb_gem_hit_crate_U;
   Double_t        bb_gem_hit_crate_U[5];   //[Ndata.bb.gem.hit.crate_U]
   Int_t           Ndata_bb_gem_hit_crate_V;
   Double_t        bb_gem_hit_crate_V[5];   //[Ndata.bb.gem.hit.crate_V]
   Int_t           Ndata_bb_gem_hit_deltat;
   Double_t        bb_gem_hit_deltat[5];   //[Ndata.bb.gem.hit.deltat]
   Int_t           Ndata_bb_gem_hit_deltat_deconv;
   Double_t        bb_gem_hit_deltat_deconv[5];   //[Ndata.bb.gem.hit.deltat_deconv]
   Int_t           Ndata_bb_gem_hit_deltat_fit;
   Double_t        bb_gem_hit_deltat_fit[5];   //[Ndata.bb.gem.hit.deltat_fit]
   Int_t           Ndata_bb_gem_hit_eresidu;
   Double_t        bb_gem_hit_eresidu[5];   //[Ndata.bb.gem.hit.eresidu]
   Int_t           Ndata_bb_gem_hit_eresidv;
   Double_t        bb_gem_hit_eresidv[5];   //[Ndata.bb.gem.hit.eresidv]
   Int_t           Ndata_bb_gem_hit_icombomaxUclustDeconv;
   Double_t        bb_gem_hit_icombomaxUclustDeconv[5];   //[Ndata.bb.gem.hit.icombomaxUclustDeconv]
   Int_t           Ndata_bb_gem_hit_icombomaxUstripDeconv;
   Double_t        bb_gem_hit_icombomaxUstripDeconv[5];   //[Ndata.bb.gem.hit.icombomaxUstripDeconv]
   Int_t           Ndata_bb_gem_hit_icombomaxVclustDeconv;
   Double_t        bb_gem_hit_icombomaxVclustDeconv[5];   //[Ndata.bb.gem.hit.icombomaxVclustDeconv]
   Int_t           Ndata_bb_gem_hit_icombomaxVstripDeconv;
   Double_t        bb_gem_hit_icombomaxVstripDeconv[5];   //[Ndata.bb.gem.hit.icombomaxVstripDeconv]
   Int_t           Ndata_bb_gem_hit_isampmaxUclust;
   Double_t        bb_gem_hit_isampmaxUclust[5];   //[Ndata.bb.gem.hit.isampmaxUclust]
   Int_t           Ndata_bb_gem_hit_isampmaxUclustDeconv;
   Double_t        bb_gem_hit_isampmaxUclustDeconv[5];   //[Ndata.bb.gem.hit.isampmaxUclustDeconv]
   Int_t           Ndata_bb_gem_hit_isampmaxUstrip;
   Double_t        bb_gem_hit_isampmaxUstrip[5];   //[Ndata.bb.gem.hit.isampmaxUstrip]
   Int_t           Ndata_bb_gem_hit_isampmaxUstripDeconv;
   Double_t        bb_gem_hit_isampmaxUstripDeconv[5];   //[Ndata.bb.gem.hit.isampmaxUstripDeconv]
   Int_t           Ndata_bb_gem_hit_isampmaxVclust;
   Double_t        bb_gem_hit_isampmaxVclust[5];   //[Ndata.bb.gem.hit.isampmaxVclust]
   Int_t           Ndata_bb_gem_hit_isampmaxVclustDeconv;
   Double_t        bb_gem_hit_isampmaxVclustDeconv[5];   //[Ndata.bb.gem.hit.isampmaxVclustDeconv]
   Int_t           Ndata_bb_gem_hit_isampmaxVstrip;
   Double_t        bb_gem_hit_isampmaxVstrip[5];   //[Ndata.bb.gem.hit.isampmaxVstrip]
   Int_t           Ndata_bb_gem_hit_isampmaxVstripDeconv;
   Double_t        bb_gem_hit_isampmaxVstripDeconv[5];   //[Ndata.bb.gem.hit.isampmaxVstripDeconv]
   Int_t           Ndata_bb_gem_hit_layer;
   Double_t        bb_gem_hit_layer[5];   //[Ndata.bb.gem.hit.layer]
   Int_t           Ndata_bb_gem_hit_module;
   Double_t        bb_gem_hit_module[5];   //[Ndata.bb.gem.hit.module]
   Int_t           Ndata_bb_gem_hit_mpd_U;
   Double_t        bb_gem_hit_mpd_U[5];   //[Ndata.bb.gem.hit.mpd_U]
   Int_t           Ndata_bb_gem_hit_mpd_V;
   Double_t        bb_gem_hit_mpd_V[5];   //[Ndata.bb.gem.hit.mpd_V]
   Int_t           Ndata_bb_gem_hit_nstripu;
   Double_t        bb_gem_hit_nstripu[5];   //[Ndata.bb.gem.hit.nstripu]
   Int_t           Ndata_bb_gem_hit_nstripv;
   Double_t        bb_gem_hit_nstripv[5];   //[Ndata.bb.gem.hit.nstripv]
   Int_t           Ndata_bb_gem_hit_residu;
   Double_t        bb_gem_hit_residu[5];   //[Ndata.bb.gem.hit.residu]
   Int_t           Ndata_bb_gem_hit_residv;
   Double_t        bb_gem_hit_residv[5];   //[Ndata.bb.gem.hit.residv]
   Int_t           Ndata_bb_gem_hit_trackindex;
   Double_t        bb_gem_hit_trackindex[5];   //[Ndata.bb.gem.hit.trackindex]
   Int_t           Ndata_bb_gem_hit_u;
   Double_t        bb_gem_hit_u[5];   //[Ndata.bb.gem.hit.u]
   Int_t           Ndata_bb_gem_hit_uTScorr_MaxStripU;
   Double_t        bb_gem_hit_uTScorr_MaxStripU[5];   //[Ndata.bb.gem.hit.uTScorr_MaxStripU]
   Int_t           Ndata_bb_gem_hit_uTScorr_MaxStripV;
   Double_t        bb_gem_hit_uTScorr_MaxStripV[5];   //[Ndata.bb.gem.hit.uTScorr_MaxStripV]
   Int_t           Ndata_bb_gem_hit_uTScorr_Uclust;
   Double_t        bb_gem_hit_uTScorr_Uclust[5];   //[Ndata.bb.gem.hit.uTScorr_Uclust]
   Int_t           Ndata_bb_gem_hit_uTScorr_Vclust;
   Double_t        bb_gem_hit_uTScorr_Vclust[5];   //[Ndata.bb.gem.hit.uTScorr_Vclust]
   Int_t           Ndata_bb_gem_hit_umoment;
   Double_t        bb_gem_hit_umoment[5];   //[Ndata.bb.gem.hit.umoment]
   Int_t           Ndata_bb_gem_hit_usigma;
   Double_t        bb_gem_hit_usigma[5];   //[Ndata.bb.gem.hit.usigma]
   Int_t           Ndata_bb_gem_hit_ustriphi;
   Double_t        bb_gem_hit_ustriphi[5];   //[Ndata.bb.gem.hit.ustriphi]
   Int_t           Ndata_bb_gem_hit_ustriplo;
   Double_t        bb_gem_hit_ustriplo[5];   //[Ndata.bb.gem.hit.ustriplo]
   Int_t           Ndata_bb_gem_hit_ustripmax;
   Double_t        bb_gem_hit_ustripmax[5];   //[Ndata.bb.gem.hit.ustripmax]
   Int_t           Ndata_bb_gem_hit_v;
   Double_t        bb_gem_hit_v[5];   //[Ndata.bb.gem.hit.v]
   Int_t           Ndata_bb_gem_hit_vmoment;
   Double_t        bb_gem_hit_vmoment[5];   //[Ndata.bb.gem.hit.vmoment]
   Int_t           Ndata_bb_gem_hit_vsigma;
   Double_t        bb_gem_hit_vsigma[5];   //[Ndata.bb.gem.hit.vsigma]
   Int_t           Ndata_bb_gem_hit_vstriphi;
   Double_t        bb_gem_hit_vstriphi[5];   //[Ndata.bb.gem.hit.vstriphi]
   Int_t           Ndata_bb_gem_hit_vstriplo;
   Double_t        bb_gem_hit_vstriplo[5];   //[Ndata.bb.gem.hit.vstriplo]
   Int_t           Ndata_bb_gem_hit_vstripmax;
   Double_t        bb_gem_hit_vstripmax[5];   //[Ndata.bb.gem.hit.vstripmax]
   Int_t           Ndata_bb_gem_hit_wTScorr_MaxStripU;
   Double_t        bb_gem_hit_wTScorr_MaxStripU[5];   //[Ndata.bb.gem.hit.wTScorr_MaxStripU]
   Int_t           Ndata_bb_gem_hit_wTScorr_MaxStripV;
   Double_t        bb_gem_hit_wTScorr_MaxStripV[5];   //[Ndata.bb.gem.hit.wTScorr_MaxStripV]
   Int_t           Ndata_bb_gem_hit_wTScorr_Uclust;
   Double_t        bb_gem_hit_wTScorr_Uclust[5];   //[Ndata.bb.gem.hit.wTScorr_Uclust]
   Int_t           Ndata_bb_gem_hit_wTScorr_Vclust;
   Double_t        bb_gem_hit_wTScorr_Vclust[5];   //[Ndata.bb.gem.hit.wTScorr_Vclust]
   Int_t           Ndata_bb_gem_hit_xglobal;
   Double_t        bb_gem_hit_xglobal[5];   //[Ndata.bb.gem.hit.xglobal]
   Int_t           Ndata_bb_gem_hit_xlocal;
   Double_t        bb_gem_hit_xlocal[5];   //[Ndata.bb.gem.hit.xlocal]
   Int_t           Ndata_bb_gem_hit_yglobal;
   Double_t        bb_gem_hit_yglobal[5];   //[Ndata.bb.gem.hit.yglobal]
   Int_t           Ndata_bb_gem_hit_ylocal;
   Double_t        bb_gem_hit_ylocal[5];   //[Ndata.bb.gem.hit.ylocal]
   Int_t           Ndata_bb_gem_hit_zglobal;
   Double_t        bb_gem_hit_zglobal[5];   //[Ndata.bb.gem.hit.zglobal]
   Int_t           Ndata_bb_gem_n2Dhit_layer;
   Double_t        bb_gem_n2Dhit_layer[5];   //[Ndata.bb.gem.n2Dhit_layer]
   Int_t           Ndata_bb_gem_nclustu_layer;
   Double_t        bb_gem_nclustu_layer[5];   //[Ndata.bb.gem.nclustu_layer]
   Int_t           Ndata_bb_gem_nclustv_layer;
   Double_t        bb_gem_nclustv_layer[5];   //[Ndata.bb.gem.nclustv_layer]
   Int_t           Ndata_bb_gem_nstripsu_layer;
   Double_t        bb_gem_nstripsu_layer[5];   //[Ndata.bb.gem.nstripsu_layer]
   Int_t           Ndata_bb_gem_nstripsv_layer;
   Double_t        bb_gem_nstripsv_layer[5];   //[Ndata.bb.gem.nstripsv_layer]
   Int_t           Ndata_bb_gem_track_chi2ndf;
   Double_t        bb_gem_track_chi2ndf[1];   //[Ndata.bb.gem.track.chi2ndf]
   Int_t           Ndata_bb_gem_track_chi2ndf_hitquality;
   Double_t        bb_gem_track_chi2ndf_hitquality[1];   //[Ndata.bb.gem.track.chi2ndf_hitquality]
   Int_t           Ndata_bb_gem_track_ngoodhits;
   Double_t        bb_gem_track_ngoodhits[1];   //[Ndata.bb.gem.track.ngoodhits]
   Int_t           Ndata_bb_gem_track_nhits;
   Double_t        bb_gem_track_nhits[1];   //[Ndata.bb.gem.track.nhits]
   Int_t           Ndata_bb_gem_track_t0;
   Double_t        bb_gem_track_t0[1];   //[Ndata.bb.gem.track.t0]
   Int_t           Ndata_bb_gem_track_x;
   Double_t        bb_gem_track_x[1];   //[Ndata.bb.gem.track.x]
   Int_t           Ndata_bb_gem_track_xp;
   Double_t        bb_gem_track_xp[1];   //[Ndata.bb.gem.track.xp]
   Int_t           Ndata_bb_gem_track_y;
   Double_t        bb_gem_track_y[1];   //[Ndata.bb.gem.track.y]
   Int_t           Ndata_bb_gem_track_yp;
   Double_t        bb_gem_track_yp[1];   //[Ndata.bb.gem.track.yp]
   Int_t           Ndata_bb_grinch_tdc_allclus_adc;
   Double_t        bb_grinch_tdc_allclus_adc[13];   //[Ndata.bb.grinch_tdc.allclus.adc]
   Int_t           Ndata_bb_grinch_tdc_allclus_dx;
   Double_t        bb_grinch_tdc_allclus_dx[13];   //[Ndata.bb.grinch_tdc.allclus.dx]
   Int_t           Ndata_bb_grinch_tdc_allclus_dy;
   Double_t        bb_grinch_tdc_allclus_dy[13];   //[Ndata.bb.grinch_tdc.allclus.dy]
   Int_t           Ndata_bb_grinch_tdc_allclus_mirrorindex;
   Double_t        bb_grinch_tdc_allclus_mirrorindex[13];   //[Ndata.bb.grinch_tdc.allclus.mirrorindex]
   Int_t           Ndata_bb_grinch_tdc_allclus_size;
   Double_t        bb_grinch_tdc_allclus_size[13];   //[Ndata.bb.grinch_tdc.allclus.size]
   Int_t           Ndata_bb_grinch_tdc_allclus_t_mean;
   Double_t        bb_grinch_tdc_allclus_t_mean[13];   //[Ndata.bb.grinch_tdc.allclus.t_mean]
   Int_t           Ndata_bb_grinch_tdc_allclus_t_mean_corr;
   Double_t        bb_grinch_tdc_allclus_t_mean_corr[13];   //[Ndata.bb.grinch_tdc.allclus.t_mean_corr]
   Int_t           Ndata_bb_grinch_tdc_allclus_t_rms;
   Double_t        bb_grinch_tdc_allclus_t_rms[13];   //[Ndata.bb.grinch_tdc.allclus.t_rms]
   Int_t           Ndata_bb_grinch_tdc_allclus_t_rms_corr;
   Double_t        bb_grinch_tdc_allclus_t_rms_corr[13];   //[Ndata.bb.grinch_tdc.allclus.t_rms_corr]
   Int_t           Ndata_bb_grinch_tdc_allclus_tot_mean;
   Double_t        bb_grinch_tdc_allclus_tot_mean[13];   //[Ndata.bb.grinch_tdc.allclus.tot_mean]
   Int_t           Ndata_bb_grinch_tdc_allclus_trackindex;
   Double_t        bb_grinch_tdc_allclus_trackindex[13];   //[Ndata.bb.grinch_tdc.allclus.trackindex]
   Int_t           Ndata_bb_grinch_tdc_allclus_x_mean;
   Double_t        bb_grinch_tdc_allclus_x_mean[13];   //[Ndata.bb.grinch_tdc.allclus.x_mean]
   Int_t           Ndata_bb_grinch_tdc_allclus_y_mean;
   Double_t        bb_grinch_tdc_allclus_y_mean[13];   //[Ndata.bb.grinch_tdc.allclus.y_mean]
   Int_t           Ndata_bb_grinch_tdc_hit_amp;
   Double_t        bb_grinch_tdc_hit_amp[17];   //[Ndata.bb.grinch_tdc.hit.amp]
   Int_t           Ndata_bb_grinch_tdc_hit_clustindex;
   Double_t        bb_grinch_tdc_hit_clustindex[17];   //[Ndata.bb.grinch_tdc.hit.clustindex]
   Int_t           Ndata_bb_grinch_tdc_hit_col;
   Double_t        bb_grinch_tdc_hit_col[17];   //[Ndata.bb.grinch_tdc.hit.col]
   Int_t           Ndata_bb_grinch_tdc_hit_pmtnum;
   Double_t        bb_grinch_tdc_hit_pmtnum[17];   //[Ndata.bb.grinch_tdc.hit.pmtnum]
   Int_t           Ndata_bb_grinch_tdc_hit_row;
   Double_t        bb_grinch_tdc_hit_row[17];   //[Ndata.bb.grinch_tdc.hit.row]
   Int_t           Ndata_bb_grinch_tdc_hit_time;
   Double_t        bb_grinch_tdc_hit_time[17];   //[Ndata.bb.grinch_tdc.hit.time]
   Int_t           Ndata_bb_grinch_tdc_hit_time_corr;
   Double_t        bb_grinch_tdc_hit_time_corr[17];   //[Ndata.bb.grinch_tdc.hit.time_corr]
   Int_t           Ndata_bb_grinch_tdc_hit_trackindex;
   Double_t        bb_grinch_tdc_hit_trackindex[17];   //[Ndata.bb.grinch_tdc.hit.trackindex]
   Int_t           Ndata_bb_grinch_tdc_hit_xhit;
   Double_t        bb_grinch_tdc_hit_xhit[17];   //[Ndata.bb.grinch_tdc.hit.xhit]
   Int_t           Ndata_bb_grinch_tdc_hit_yhit;
   Double_t        bb_grinch_tdc_hit_yhit[17];   //[Ndata.bb.grinch_tdc.hit.yhit]
   Int_t           Ndata_bb_hodotdc_Ref_tdc;
   Double_t        bb_hodotdc_Ref_tdc[4];   //[Ndata.bb.hodotdc.Ref.tdc]
   Int_t           Ndata_bb_hodotdc_Ref_tdc_mult;
   Double_t        bb_hodotdc_Ref_tdc_mult[4];   //[Ndata.bb.hodotdc.Ref.tdc_mult]
   Int_t           Ndata_bb_hodotdc_Ref_tdc_te;
   Double_t        bb_hodotdc_Ref_tdc_te[4];   //[Ndata.bb.hodotdc.Ref.tdc_te]
   Int_t           Ndata_bb_hodotdc_Ref_tdc_tot;
   Double_t        bb_hodotdc_Ref_tdc_tot[4];   //[Ndata.bb.hodotdc.Ref.tdc_tot]
   Int_t           Ndata_bb_hodotdc_Ref_tdcelemID;
   Double_t        bb_hodotdc_Ref_tdcelemID[4];   //[Ndata.bb.hodotdc.Ref.tdcelemID]
   Int_t           Ndata_bb_hodotdc_allclus_etof;
   Double_t        bb_hodotdc_allclus_etof[6];   //[Ndata.bb.hodotdc.allclus.etof]
   Int_t           Ndata_bb_hodotdc_allclus_iclust;
   Double_t        bb_hodotdc_allclus_iclust[6];   //[Ndata.bb.hodotdc.allclus.iclust]
   Int_t           Ndata_bb_hodotdc_allclus_id;
   Double_t        bb_hodotdc_allclus_id[6];   //[Ndata.bb.hodotdc.allclus.id]
   Int_t           Ndata_bb_hodotdc_allclus_itrack;
   Double_t        bb_hodotdc_allclus_itrack[6];   //[Ndata.bb.hodotdc.allclus.itrack]
   Int_t           Ndata_bb_hodotdc_allclus_size;
   Double_t        bb_hodotdc_allclus_size[6];   //[Ndata.bb.hodotdc.allclus.size]
   Int_t           Ndata_bb_hodotdc_allclus_tdiff;
   Double_t        bb_hodotdc_allclus_tdiff[6];   //[Ndata.bb.hodotdc.allclus.tdiff]
   Int_t           Ndata_bb_hodotdc_allclus_tfinal;
   Double_t        bb_hodotdc_allclus_tfinal[6];   //[Ndata.bb.hodotdc.allclus.tfinal]
   Int_t           Ndata_bb_hodotdc_allclus_tleft;
   Double_t        bb_hodotdc_allclus_tleft[6];   //[Ndata.bb.hodotdc.allclus.tleft]
   Int_t           Ndata_bb_hodotdc_allclus_tmean;
   Double_t        bb_hodotdc_allclus_tmean[6];   //[Ndata.bb.hodotdc.allclus.tmean]
   Int_t           Ndata_bb_hodotdc_allclus_tmeanRFcorr;
   Double_t        bb_hodotdc_allclus_tmeanRFcorr[6];   //[Ndata.bb.hodotdc.allclus.tmeanRFcorr]
   Int_t           Ndata_bb_hodotdc_allclus_totleft;
   Double_t        bb_hodotdc_allclus_totleft[6];   //[Ndata.bb.hodotdc.allclus.totleft]
   Int_t           Ndata_bb_hodotdc_allclus_totmean;
   Double_t        bb_hodotdc_allclus_totmean[6];   //[Ndata.bb.hodotdc.allclus.totmean]
   Int_t           Ndata_bb_hodotdc_allclus_totright;
   Double_t        bb_hodotdc_allclus_totright[6];   //[Ndata.bb.hodotdc.allclus.totright]
   Int_t           Ndata_bb_hodotdc_allclus_tright;
   Double_t        bb_hodotdc_allclus_tright[6];   //[Ndata.bb.hodotdc.allclus.tright]
   Int_t           Ndata_bb_hodotdc_allclus_xmean;
   Double_t        bb_hodotdc_allclus_xmean[6];   //[Ndata.bb.hodotdc.allclus.xmean]
   Int_t           Ndata_bb_hodotdc_allclus_ymean;
   Double_t        bb_hodotdc_allclus_ymean[6];   //[Ndata.bb.hodotdc.allclus.ymean]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_etof;
   Double_t        bb_hodotdc_clus_bar_tdc_etof[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.etof]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_iclust;
   Double_t        bb_hodotdc_clus_bar_tdc_iclust[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.iclust]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_id;
   Double_t        bb_hodotdc_clus_bar_tdc_id[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.id]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_itrack;
   Double_t        bb_hodotdc_clus_bar_tdc_itrack[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.itrack]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_meantime;
   Double_t        bb_hodotdc_clus_bar_tdc_meantime[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.meantime]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_meantot;
   Double_t        bb_hodotdc_clus_bar_tdc_meantot[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.meantot]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_tfinal;
   Double_t        bb_hodotdc_clus_bar_tdc_tfinal[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.tfinal]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_timediff;
   Double_t        bb_hodotdc_clus_bar_tdc_timediff[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.timediff]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_timehitpos;
   Double_t        bb_hodotdc_clus_bar_tdc_timehitpos[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.timehitpos]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_tleft;
   Double_t        bb_hodotdc_clus_bar_tdc_tleft[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.tleft]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_tmeanRFcorr;
   Double_t        bb_hodotdc_clus_bar_tdc_tmeanRFcorr[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.tmeanRFcorr]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_totleft;
   Double_t        bb_hodotdc_clus_bar_tdc_totleft[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.totleft]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_totright;
   Double_t        bb_hodotdc_clus_bar_tdc_totright[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.totright]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_tright;
   Double_t        bb_hodotdc_clus_bar_tdc_tright[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.tright]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_vpos;
   Double_t        bb_hodotdc_clus_bar_tdc_vpos[5];   //[Ndata.bb.hodotdc.clus.bar.tdc.vpos]
   Int_t           Ndata_bb_hodotdc_clus_etof;
   Double_t        bb_hodotdc_clus_etof[1];   //[Ndata.bb.hodotdc.clus.etof]
   Int_t           Ndata_bb_hodotdc_clus_id;
   Double_t        bb_hodotdc_clus_id[1];   //[Ndata.bb.hodotdc.clus.id]
   Int_t           Ndata_bb_hodotdc_clus_size;
   Double_t        bb_hodotdc_clus_size[1];   //[Ndata.bb.hodotdc.clus.size]
   Int_t           Ndata_bb_hodotdc_clus_tdiff;
   Double_t        bb_hodotdc_clus_tdiff[1];   //[Ndata.bb.hodotdc.clus.tdiff]
   Int_t           Ndata_bb_hodotdc_clus_tfinal;
   Double_t        bb_hodotdc_clus_tfinal[1];   //[Ndata.bb.hodotdc.clus.tfinal]
   Int_t           Ndata_bb_hodotdc_clus_tleft;
   Double_t        bb_hodotdc_clus_tleft[1];   //[Ndata.bb.hodotdc.clus.tleft]
   Int_t           Ndata_bb_hodotdc_clus_tmean;
   Double_t        bb_hodotdc_clus_tmean[1];   //[Ndata.bb.hodotdc.clus.tmean]
   Int_t           Ndata_bb_hodotdc_clus_tmeanRFcorr;
   Double_t        bb_hodotdc_clus_tmeanRFcorr[1];   //[Ndata.bb.hodotdc.clus.tmeanRFcorr]
   Int_t           Ndata_bb_hodotdc_clus_totleft;
   Double_t        bb_hodotdc_clus_totleft[1];   //[Ndata.bb.hodotdc.clus.totleft]
   Int_t           Ndata_bb_hodotdc_clus_totmean;
   Double_t        bb_hodotdc_clus_totmean[1];   //[Ndata.bb.hodotdc.clus.totmean]
   Int_t           Ndata_bb_hodotdc_clus_totright;
   Double_t        bb_hodotdc_clus_totright[1];   //[Ndata.bb.hodotdc.clus.totright]
   Int_t           Ndata_bb_hodotdc_clus_trackindex;
   Double_t        bb_hodotdc_clus_trackindex[1];   //[Ndata.bb.hodotdc.clus.trackindex]
   Int_t           Ndata_bb_hodotdc_clus_tright;
   Double_t        bb_hodotdc_clus_tright[1];   //[Ndata.bb.hodotdc.clus.tright]
   Int_t           Ndata_bb_hodotdc_clus_xmean;
   Double_t        bb_hodotdc_clus_xmean[1];   //[Ndata.bb.hodotdc.clus.xmean]
   Int_t           Ndata_bb_hodotdc_clus_ymean;
   Double_t        bb_hodotdc_clus_ymean[1];   //[Ndata.bb.hodotdc.clus.ymean]
   Int_t           Ndata_bb_ps_clus_adctime;
   Double_t        bb_ps_clus_adctime[3];   //[Ndata.bb.ps.clus.adctime]
   Int_t           Ndata_bb_ps_clus_again;
   Double_t        bb_ps_clus_again[3];   //[Ndata.bb.ps.clus.again]
   Int_t           Ndata_bb_ps_clus_atimeblk;
   Double_t        bb_ps_clus_atimeblk[3];   //[Ndata.bb.ps.clus.atimeblk]
   Int_t           Ndata_bb_ps_clus_col;
   Double_t        bb_ps_clus_col[3];   //[Ndata.bb.ps.clus.col]
   Int_t           Ndata_bb_ps_clus_col_goodtdc;
   Double_t        bb_ps_clus_col_goodtdc[3];   //[Ndata.bb.ps.clus.col_goodtdc]
   Int_t           Ndata_bb_ps_clus_e;
   Double_t        bb_ps_clus_e[3];   //[Ndata.bb.ps.clus.e]
   Int_t           Ndata_bb_ps_clus_e_goodtdc;
   Double_t        bb_ps_clus_e_goodtdc[3];   //[Ndata.bb.ps.clus.e_goodtdc]
   Int_t           Ndata_bb_ps_clus_eblk;
   Double_t        bb_ps_clus_eblk[3];   //[Ndata.bb.ps.clus.eblk]
   Int_t           Ndata_bb_ps_clus_eblk_goodtdc;
   Double_t        bb_ps_clus_eblk_goodtdc[3];   //[Ndata.bb.ps.clus.eblk_goodtdc]
   Int_t           Ndata_bb_ps_clus_id;
   Double_t        bb_ps_clus_id[3];   //[Ndata.bb.ps.clus.id]
   Int_t           Ndata_bb_ps_clus_id_goodtdc;
   Double_t        bb_ps_clus_id_goodtdc[3];   //[Ndata.bb.ps.clus.id_goodtdc]
   Int_t           Ndata_bb_ps_clus_nblk;
   Double_t        bb_ps_clus_nblk[3];   //[Ndata.bb.ps.clus.nblk]
   Int_t           Ndata_bb_ps_clus_nblk_goodtdc;
   Double_t        bb_ps_clus_nblk_goodtdc[3];   //[Ndata.bb.ps.clus.nblk_goodtdc]
   Int_t           Ndata_bb_ps_clus_row;
   Double_t        bb_ps_clus_row[3];   //[Ndata.bb.ps.clus.row]
   Int_t           Ndata_bb_ps_clus_row_goodtdc;
   Double_t        bb_ps_clus_row_goodtdc[3];   //[Ndata.bb.ps.clus.row_goodtdc]
   Int_t           Ndata_bb_ps_clus_tdctime;
   Double_t        bb_ps_clus_tdctime[3];   //[Ndata.bb.ps.clus.tdctime]
   Int_t           Ndata_bb_ps_clus_tdctime_tw;
   Double_t        bb_ps_clus_tdctime_tw[3];   //[Ndata.bb.ps.clus.tdctime_tw]
   Int_t           Ndata_bb_ps_clus_tdctimeblk;
   Double_t        bb_ps_clus_tdctimeblk[3];   //[Ndata.bb.ps.clus.tdctimeblk]
   Int_t           Ndata_bb_ps_clus_tdctimeblk_tw;
   Double_t        bb_ps_clus_tdctimeblk_tw[3];   //[Ndata.bb.ps.clus.tdctimeblk_tw]
   Int_t           Ndata_bb_ps_clus_x;
   Double_t        bb_ps_clus_x[3];   //[Ndata.bb.ps.clus.x]
   Int_t           Ndata_bb_ps_clus_y;
   Double_t        bb_ps_clus_y[3];   //[Ndata.bb.ps.clus.y]
   Int_t           Ndata_bb_ps_clus_blk_again;
   Double_t        bb_ps_clus_blk_again[4];   //[Ndata.bb.ps.clus_blk.again]
   Int_t           Ndata_bb_ps_clus_blk_atime;
   Double_t        bb_ps_clus_blk_atime[4];   //[Ndata.bb.ps.clus_blk.atime]
   Int_t           Ndata_bb_ps_clus_blk_col;
   Double_t        bb_ps_clus_blk_col[4];   //[Ndata.bb.ps.clus_blk.col]
   Int_t           Ndata_bb_ps_clus_blk_e;
   Double_t        bb_ps_clus_blk_e[4];   //[Ndata.bb.ps.clus_blk.e]
   Int_t           Ndata_bb_ps_clus_blk_id;
   Double_t        bb_ps_clus_blk_id[4];   //[Ndata.bb.ps.clus_blk.id]
   Int_t           Ndata_bb_ps_clus_blk_row;
   Double_t        bb_ps_clus_blk_row[4];   //[Ndata.bb.ps.clus_blk.row]
   Int_t           Ndata_bb_ps_clus_blk_tdctime;
   Double_t        bb_ps_clus_blk_tdctime[4];   //[Ndata.bb.ps.clus_blk.tdctime]
   Int_t           Ndata_bb_ps_clus_blk_tdctime_tw;
   Double_t        bb_ps_clus_blk_tdctime_tw[4];   //[Ndata.bb.ps.clus_blk.tdctime_tw]
   Int_t           Ndata_bb_ps_clus_blk_x;
   Double_t        bb_ps_clus_blk_x[4];   //[Ndata.bb.ps.clus_blk.x]
   Int_t           Ndata_bb_ps_clus_blk_y;
   Double_t        bb_ps_clus_blk_y[4];   //[Ndata.bb.ps.clus_blk.y]
   Int_t           Ndata_bb_sh_clus_adctime;
   Double_t        bb_sh_clus_adctime[3];   //[Ndata.bb.sh.clus.adctime]
   Int_t           Ndata_bb_sh_clus_again;
   Double_t        bb_sh_clus_again[3];   //[Ndata.bb.sh.clus.again]
   Int_t           Ndata_bb_sh_clus_atimeblk;
   Double_t        bb_sh_clus_atimeblk[3];   //[Ndata.bb.sh.clus.atimeblk]
   Int_t           Ndata_bb_sh_clus_col;
   Double_t        bb_sh_clus_col[3];   //[Ndata.bb.sh.clus.col]
   Int_t           Ndata_bb_sh_clus_col_goodtdc;
   Double_t        bb_sh_clus_col_goodtdc[3];   //[Ndata.bb.sh.clus.col_goodtdc]
   Int_t           Ndata_bb_sh_clus_e;
   Double_t        bb_sh_clus_e[3];   //[Ndata.bb.sh.clus.e]
   Int_t           Ndata_bb_sh_clus_e_goodtdc;
   Double_t        bb_sh_clus_e_goodtdc[3];   //[Ndata.bb.sh.clus.e_goodtdc]
   Int_t           Ndata_bb_sh_clus_eblk;
   Double_t        bb_sh_clus_eblk[3];   //[Ndata.bb.sh.clus.eblk]
   Int_t           Ndata_bb_sh_clus_eblk_goodtdc;
   Double_t        bb_sh_clus_eblk_goodtdc[3];   //[Ndata.bb.sh.clus.eblk_goodtdc]
   Int_t           Ndata_bb_sh_clus_id;
   Double_t        bb_sh_clus_id[3];   //[Ndata.bb.sh.clus.id]
   Int_t           Ndata_bb_sh_clus_id_goodtdc;
   Double_t        bb_sh_clus_id_goodtdc[3];   //[Ndata.bb.sh.clus.id_goodtdc]
   Int_t           Ndata_bb_sh_clus_nblk;
   Double_t        bb_sh_clus_nblk[3];   //[Ndata.bb.sh.clus.nblk]
   Int_t           Ndata_bb_sh_clus_nblk_goodtdc;
   Double_t        bb_sh_clus_nblk_goodtdc[3];   //[Ndata.bb.sh.clus.nblk_goodtdc]
   Int_t           Ndata_bb_sh_clus_row;
   Double_t        bb_sh_clus_row[3];   //[Ndata.bb.sh.clus.row]
   Int_t           Ndata_bb_sh_clus_row_goodtdc;
   Double_t        bb_sh_clus_row_goodtdc[3];   //[Ndata.bb.sh.clus.row_goodtdc]
   Int_t           Ndata_bb_sh_clus_tdctime;
   Double_t        bb_sh_clus_tdctime[3];   //[Ndata.bb.sh.clus.tdctime]
   Int_t           Ndata_bb_sh_clus_tdctime_tw;
   Double_t        bb_sh_clus_tdctime_tw[3];   //[Ndata.bb.sh.clus.tdctime_tw]
   Int_t           Ndata_bb_sh_clus_tdctimeblk;
   Double_t        bb_sh_clus_tdctimeblk[3];   //[Ndata.bb.sh.clus.tdctimeblk]
   Int_t           Ndata_bb_sh_clus_tdctimeblk_tw;
   Double_t        bb_sh_clus_tdctimeblk_tw[3];   //[Ndata.bb.sh.clus.tdctimeblk_tw]
   Int_t           Ndata_bb_sh_clus_x;
   Double_t        bb_sh_clus_x[3];   //[Ndata.bb.sh.clus.x]
   Int_t           Ndata_bb_sh_clus_y;
   Double_t        bb_sh_clus_y[3];   //[Ndata.bb.sh.clus.y]
   Int_t           Ndata_bb_sh_clus_blk_again;
   Double_t        bb_sh_clus_blk_again[13];   //[Ndata.bb.sh.clus_blk.again]
   Int_t           Ndata_bb_sh_clus_blk_atime;
   Double_t        bb_sh_clus_blk_atime[13];   //[Ndata.bb.sh.clus_blk.atime]
   Int_t           Ndata_bb_sh_clus_blk_col;
   Double_t        bb_sh_clus_blk_col[13];   //[Ndata.bb.sh.clus_blk.col]
   Int_t           Ndata_bb_sh_clus_blk_e;
   Double_t        bb_sh_clus_blk_e[13];   //[Ndata.bb.sh.clus_blk.e]
   Int_t           Ndata_bb_sh_clus_blk_id;
   Double_t        bb_sh_clus_blk_id[13];   //[Ndata.bb.sh.clus_blk.id]
   Int_t           Ndata_bb_sh_clus_blk_row;
   Double_t        bb_sh_clus_blk_row[13];   //[Ndata.bb.sh.clus_blk.row]
   Int_t           Ndata_bb_sh_clus_blk_tdctime;
   Double_t        bb_sh_clus_blk_tdctime[13];   //[Ndata.bb.sh.clus_blk.tdctime]
   Int_t           Ndata_bb_sh_clus_blk_tdctime_tw;
   Double_t        bb_sh_clus_blk_tdctime_tw[13];   //[Ndata.bb.sh.clus_blk.tdctime_tw]
   Int_t           Ndata_bb_sh_clus_blk_x;
   Double_t        bb_sh_clus_blk_x[13];   //[Ndata.bb.sh.clus_blk.x]
   Int_t           Ndata_bb_sh_clus_blk_y;
   Double_t        bb_sh_clus_blk_y[13];   //[Ndata.bb.sh.clus_blk.y]
   Int_t           Ndata_bb_tdctrig_tdc;
   Double_t        bb_tdctrig_tdc[5];   //[Ndata.bb.tdctrig.tdc]
   Int_t           Ndata_bb_tdctrig_tdcelemID;
   Double_t        bb_tdctrig_tdcelemID[5];   //[Ndata.bb.tdctrig.tdcelemID]
   Int_t           Ndata_bb_tr_beta;
   Double_t        bb_tr_beta[1];   //[Ndata.bb.tr.beta]
   Int_t           Ndata_bb_tr_chi2;
   Double_t        bb_tr_chi2[1];   //[Ndata.bb.tr.chi2]
   Int_t           Ndata_bb_tr_d_ph;
   Double_t        bb_tr_d_ph[1];   //[Ndata.bb.tr.d_ph]
   Int_t           Ndata_bb_tr_d_th;
   Double_t        bb_tr_d_th[1];   //[Ndata.bb.tr.d_th]
   Int_t           Ndata_bb_tr_d_x;
   Double_t        bb_tr_d_x[1];   //[Ndata.bb.tr.d_x]
   Int_t           Ndata_bb_tr_d_y;
   Double_t        bb_tr_d_y[1];   //[Ndata.bb.tr.d_y]
   Int_t           Ndata_bb_tr_dbeta;
   Double_t        bb_tr_dbeta[1];   //[Ndata.bb.tr.dbeta]
   Int_t           Ndata_bb_tr_dtime;
   Double_t        bb_tr_dtime[1];   //[Ndata.bb.tr.dtime]
   Int_t           Ndata_bb_tr_flag;
   Double_t        bb_tr_flag[1];   //[Ndata.bb.tr.flag]
   Int_t           Ndata_bb_tr_ndof;
   Double_t        bb_tr_ndof[1];   //[Ndata.bb.tr.ndof]
   Int_t           Ndata_bb_tr_p;
   Double_t        bb_tr_p[1];   //[Ndata.bb.tr.p]
   Int_t           Ndata_bb_tr_pathl;
   Double_t        bb_tr_pathl[1];   //[Ndata.bb.tr.pathl]
   Int_t           Ndata_bb_tr_ph;
   Double_t        bb_tr_ph[1];   //[Ndata.bb.tr.ph]
   Int_t           Ndata_bb_tr_px;
   Double_t        bb_tr_px[1];   //[Ndata.bb.tr.px]
   Int_t           Ndata_bb_tr_py;
   Double_t        bb_tr_py[1];   //[Ndata.bb.tr.py]
   Int_t           Ndata_bb_tr_pz;
   Double_t        bb_tr_pz[1];   //[Ndata.bb.tr.pz]
   Int_t           Ndata_bb_tr_r_ph;
   Double_t        bb_tr_r_ph[1];   //[Ndata.bb.tr.r_ph]
   Int_t           Ndata_bb_tr_r_th;
   Double_t        bb_tr_r_th[1];   //[Ndata.bb.tr.r_th]
   Int_t           Ndata_bb_tr_r_x;
   Double_t        bb_tr_r_x[1];   //[Ndata.bb.tr.r_x]
   Int_t           Ndata_bb_tr_r_y;
   Double_t        bb_tr_r_y[1];   //[Ndata.bb.tr.r_y]
   Int_t           Ndata_bb_tr_tg_dp;
   Double_t        bb_tr_tg_dp[1];   //[Ndata.bb.tr.tg_dp]
   Int_t           Ndata_bb_tr_tg_ph;
   Double_t        bb_tr_tg_ph[1];   //[Ndata.bb.tr.tg_ph]
   Int_t           Ndata_bb_tr_tg_th;
   Double_t        bb_tr_tg_th[1];   //[Ndata.bb.tr.tg_th]
   Int_t           Ndata_bb_tr_tg_x;
   Double_t        bb_tr_tg_x[1];   //[Ndata.bb.tr.tg_x]
   Int_t           Ndata_bb_tr_tg_y;
   Double_t        bb_tr_tg_y[1];   //[Ndata.bb.tr.tg_y]
   Int_t           Ndata_bb_tr_th;
   Double_t        bb_tr_th[1];   //[Ndata.bb.tr.th]
   Int_t           Ndata_bb_tr_time;
   Double_t        bb_tr_time[1];   //[Ndata.bb.tr.time]
   Int_t           Ndata_bb_tr_vx;
   Double_t        bb_tr_vx[1];   //[Ndata.bb.tr.vx]
   Int_t           Ndata_bb_tr_vy;
   Double_t        bb_tr_vy[1];   //[Ndata.bb.tr.vy]
   Int_t           Ndata_bb_tr_vz;
   Double_t        bb_tr_vz[1];   //[Ndata.bb.tr.vz]
   Int_t           Ndata_bb_tr_x;
   Double_t        bb_tr_x[1];   //[Ndata.bb.tr.x]
   Int_t           Ndata_bb_tr_y;
   Double_t        bb_tr_y[1];   //[Ndata.bb.tr.y]
   Int_t           Ndata_bb_x_bcp;
   Double_t        bb_x_bcp[1];   //[Ndata.bb.x_bcp]
   Int_t           Ndata_bb_x_fcp;
   Double_t        bb_x_fcp[1];   //[Ndata.bb.x_fcp]
   Int_t           Ndata_bb_y_bcp;
   Double_t        bb_y_bcp[1];   //[Ndata.bb.y_bcp]
   Int_t           Ndata_bb_y_fcp;
   Double_t        bb_y_fcp[1];   //[Ndata.bb.y_fcp]
   Int_t           Ndata_bb_z_bcp;
   Double_t        bb_z_bcp[1];   //[Ndata.bb.z_bcp]
   Int_t           Ndata_bb_z_fcp;
   Double_t        bb_z_fcp[1];   //[Ndata.bb.z_fcp]
   Int_t           Ndata_sbs_gemCeF_hit_ADCU;
   Double_t        sbs_gemCeF_hit_ADCU[4];   //[Ndata.sbs.gemCeF.hit.ADCU]
   Int_t           Ndata_sbs_gemCeF_hit_ADCU_deconv;
   Double_t        sbs_gemCeF_hit_ADCU_deconv[4];   //[Ndata.sbs.gemCeF.hit.ADCU_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ADCV;
   Double_t        sbs_gemCeF_hit_ADCV[4];   //[Ndata.sbs.gemCeF.hit.ADCV]
   Int_t           Ndata_sbs_gemCeF_hit_ADCV_deconv;
   Double_t        sbs_gemCeF_hit_ADCV_deconv[4];   //[Ndata.sbs.gemCeF.hit.ADCV_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ADCasym;
   Double_t        sbs_gemCeF_hit_ADCasym[4];   //[Ndata.sbs.gemCeF.hit.ADCasym]
   Int_t           Ndata_sbs_gemCeF_hit_ADCasym_deconv;
   Double_t        sbs_gemCeF_hit_ADCasym_deconv[4];   //[Ndata.sbs.gemCeF.hit.ADCasym_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ADCavg;
   Double_t        sbs_gemCeF_hit_ADCavg[4];   //[Ndata.sbs.gemCeF.hit.ADCavg]
   Int_t           Ndata_sbs_gemCeF_hit_ADCavg_deconv;
   Double_t        sbs_gemCeF_hit_ADCavg_deconv[4];   //[Ndata.sbs.gemCeF.hit.ADCavg_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac0_Umax;
   Double_t        sbs_gemCeF_hit_ADCfrac0_Umax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac0_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac0_Vmax;
   Double_t        sbs_gemCeF_hit_ADCfrac0_Vmax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac0_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac1_Umax;
   Double_t        sbs_gemCeF_hit_ADCfrac1_Umax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac1_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac1_Vmax;
   Double_t        sbs_gemCeF_hit_ADCfrac1_Vmax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac1_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac2_Umax;
   Double_t        sbs_gemCeF_hit_ADCfrac2_Umax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac2_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac2_Vmax;
   Double_t        sbs_gemCeF_hit_ADCfrac2_Vmax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac2_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac3_Umax;
   Double_t        sbs_gemCeF_hit_ADCfrac3_Umax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac3_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac3_Vmax;
   Double_t        sbs_gemCeF_hit_ADCfrac3_Vmax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac3_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac4_Umax;
   Double_t        sbs_gemCeF_hit_ADCfrac4_Umax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac4_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac4_Vmax;
   Double_t        sbs_gemCeF_hit_ADCfrac4_Vmax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac4_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac5_Umax;
   Double_t        sbs_gemCeF_hit_ADCfrac5_Umax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac5_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCfrac5_Vmax;
   Double_t        sbs_gemCeF_hit_ADCfrac5_Vmax[4];   //[Ndata.sbs.gemCeF.hit.ADCfrac5_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxcomboUclust_deconv;
   Double_t        sbs_gemCeF_hit_ADCmaxcomboUclust_deconv[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxcomboUclust_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxcomboVclust_deconv;
   Double_t        sbs_gemCeF_hit_ADCmaxcomboVclust_deconv[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxcomboVclust_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxsampU;
   Double_t        sbs_gemCeF_hit_ADCmaxsampU[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxsampU]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxsampUclust;
   Double_t        sbs_gemCeF_hit_ADCmaxsampUclust[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxsampUclust]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxsampUclust_deconv;
   Double_t        sbs_gemCeF_hit_ADCmaxsampUclust_deconv[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxsampUclust_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxsampV;
   Double_t        sbs_gemCeF_hit_ADCmaxsampV[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxsampV]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxsampVclust;
   Double_t        sbs_gemCeF_hit_ADCmaxsampVclust[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxsampVclust]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxsampVclust_deconv;
   Double_t        sbs_gemCeF_hit_ADCmaxsampVclust_deconv[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxsampVclust_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxstripU;
   Double_t        sbs_gemCeF_hit_ADCmaxstripU[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxstripU]
   Int_t           Ndata_sbs_gemCeF_hit_ADCmaxstripV;
   Double_t        sbs_gemCeF_hit_ADCmaxstripV[4];   //[Ndata.sbs.gemCeF.hit.ADCmaxstripV]
   Int_t           Ndata_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_U;
   Double_t        sbs_gemCeF_hit_BUILD_ALL_SAMPLES_U[4];   //[Ndata.sbs.gemCeF.hit.BUILD_ALL_SAMPLES_U]
   Int_t           Ndata_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_V;
   Double_t        sbs_gemCeF_hit_BUILD_ALL_SAMPLES_V[4];   //[Ndata.sbs.gemCeF.hit.BUILD_ALL_SAMPLES_V]
   Int_t           Ndata_sbs_gemCeF_hit_CM_GOOD_U;
   Double_t        sbs_gemCeF_hit_CM_GOOD_U[4];   //[Ndata.sbs.gemCeF.hit.CM_GOOD_U]
   Int_t           Ndata_sbs_gemCeF_hit_CM_GOOD_V;
   Double_t        sbs_gemCeF_hit_CM_GOOD_V[4];   //[Ndata.sbs.gemCeF.hit.CM_GOOD_V]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC0_Umax;
   Double_t        sbs_gemCeF_hit_DeconvADC0_Umax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC0_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC0_Vmax;
   Double_t        sbs_gemCeF_hit_DeconvADC0_Vmax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC0_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC1_Umax;
   Double_t        sbs_gemCeF_hit_DeconvADC1_Umax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC1_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC1_Vmax;
   Double_t        sbs_gemCeF_hit_DeconvADC1_Vmax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC1_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC2_Umax;
   Double_t        sbs_gemCeF_hit_DeconvADC2_Umax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC2_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC2_Vmax;
   Double_t        sbs_gemCeF_hit_DeconvADC2_Vmax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC2_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC3_Umax;
   Double_t        sbs_gemCeF_hit_DeconvADC3_Umax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC3_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC3_Vmax;
   Double_t        sbs_gemCeF_hit_DeconvADC3_Vmax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC3_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC4_Umax;
   Double_t        sbs_gemCeF_hit_DeconvADC4_Umax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC4_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC4_Vmax;
   Double_t        sbs_gemCeF_hit_DeconvADC4_Vmax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC4_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC5_Umax;
   Double_t        sbs_gemCeF_hit_DeconvADC5_Umax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC5_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADC5_Vmax;
   Double_t        sbs_gemCeF_hit_DeconvADC5_Vmax[4];   //[Ndata.sbs.gemCeF.hit.DeconvADC5_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADCmaxcomboU;
   Double_t        sbs_gemCeF_hit_DeconvADCmaxcomboU[4];   //[Ndata.sbs.gemCeF.hit.DeconvADCmaxcomboU]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADCmaxcomboV;
   Double_t        sbs_gemCeF_hit_DeconvADCmaxcomboV[4];   //[Ndata.sbs.gemCeF.hit.DeconvADCmaxcomboV]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADCmaxsampU;
   Double_t        sbs_gemCeF_hit_DeconvADCmaxsampU[4];   //[Ndata.sbs.gemCeF.hit.DeconvADCmaxsampU]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADCmaxsampV;
   Double_t        sbs_gemCeF_hit_DeconvADCmaxsampV[4];   //[Ndata.sbs.gemCeF.hit.DeconvADCmaxsampV]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADCmaxstripU;
   Double_t        sbs_gemCeF_hit_DeconvADCmaxstripU[4];   //[Ndata.sbs.gemCeF.hit.DeconvADCmaxstripU]
   Int_t           Ndata_sbs_gemCeF_hit_DeconvADCmaxstripV;
   Double_t        sbs_gemCeF_hit_DeconvADCmaxstripV[4];   //[Ndata.sbs.gemCeF.hit.DeconvADCmaxstripV]
   Int_t           Ndata_sbs_gemCeF_hit_ENABLE_CM_U;
   Double_t        sbs_gemCeF_hit_ENABLE_CM_U[4];   //[Ndata.sbs.gemCeF.hit.ENABLE_CM_U]
   Int_t           Ndata_sbs_gemCeF_hit_ENABLE_CM_V;
   Double_t        sbs_gemCeF_hit_ENABLE_CM_V[4];   //[Ndata.sbs.gemCeF.hit.ENABLE_CM_V]
   Int_t           Ndata_sbs_gemCeF_hit_TSchi2_Umax;
   Double_t        sbs_gemCeF_hit_TSchi2_Umax[4];   //[Ndata.sbs.gemCeF.hit.TSchi2_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_TSchi2_Vmax;
   Double_t        sbs_gemCeF_hit_TSchi2_Vmax[4];   //[Ndata.sbs.gemCeF.hit.TSchi2_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_TSprob_Umax;
   Double_t        sbs_gemCeF_hit_TSprob_Umax[4];   //[Ndata.sbs.gemCeF.hit.TSprob_Umax]
   Int_t           Ndata_sbs_gemCeF_hit_TSprob_Vmax;
   Double_t        sbs_gemCeF_hit_TSprob_Vmax[4];   //[Ndata.sbs.gemCeF.hit.TSprob_Vmax]
   Int_t           Ndata_sbs_gemCeF_hit_Tavg;
   Double_t        sbs_gemCeF_hit_Tavg[4];   //[Ndata.sbs.gemCeF.hit.Tavg]
   Int_t           Ndata_sbs_gemCeF_hit_Tavg_corr;
   Double_t        sbs_gemCeF_hit_Tavg_corr[4];   //[Ndata.sbs.gemCeF.hit.Tavg_corr]
   Int_t           Ndata_sbs_gemCeF_hit_Tavg_deconv;
   Double_t        sbs_gemCeF_hit_Tavg_deconv[4];   //[Ndata.sbs.gemCeF.hit.Tavg_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_Tavg_fit;
   Double_t        sbs_gemCeF_hit_Tavg_fit[4];   //[Ndata.sbs.gemCeF.hit.Tavg_fit]
   Int_t           Ndata_sbs_gemCeF_hit_Ugain;
   Double_t        sbs_gemCeF_hit_Ugain[4];   //[Ndata.sbs.gemCeF.hit.Ugain]
   Int_t           Ndata_sbs_gemCeF_hit_Utime;
   Double_t        sbs_gemCeF_hit_Utime[4];   //[Ndata.sbs.gemCeF.hit.Utime]
   Int_t           Ndata_sbs_gemCeF_hit_UtimeDeconv;
   Double_t        sbs_gemCeF_hit_UtimeDeconv[4];   //[Ndata.sbs.gemCeF.hit.UtimeDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_UtimeFit;
   Double_t        sbs_gemCeF_hit_UtimeFit[4];   //[Ndata.sbs.gemCeF.hit.UtimeFit]
   Int_t           Ndata_sbs_gemCeF_hit_UtimeMaxStrip;
   Double_t        sbs_gemCeF_hit_UtimeMaxStrip[4];   //[Ndata.sbs.gemCeF.hit.UtimeMaxStrip]
   Int_t           Ndata_sbs_gemCeF_hit_UtimeMaxStripDeconv;
   Double_t        sbs_gemCeF_hit_UtimeMaxStripDeconv[4];   //[Ndata.sbs.gemCeF.hit.UtimeMaxStripDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_UtimeMaxStripFit;
   Double_t        sbs_gemCeF_hit_UtimeMaxStripFit[4];   //[Ndata.sbs.gemCeF.hit.UtimeMaxStripFit]
   Int_t           Ndata_sbs_gemCeF_hit_Vgain;
   Double_t        sbs_gemCeF_hit_Vgain[4];   //[Ndata.sbs.gemCeF.hit.Vgain]
   Int_t           Ndata_sbs_gemCeF_hit_Vtime;
   Double_t        sbs_gemCeF_hit_Vtime[4];   //[Ndata.sbs.gemCeF.hit.Vtime]
   Int_t           Ndata_sbs_gemCeF_hit_VtimeDeconv;
   Double_t        sbs_gemCeF_hit_VtimeDeconv[4];   //[Ndata.sbs.gemCeF.hit.VtimeDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_VtimeFit;
   Double_t        sbs_gemCeF_hit_VtimeFit[4];   //[Ndata.sbs.gemCeF.hit.VtimeFit]
   Int_t           Ndata_sbs_gemCeF_hit_VtimeMaxStrip;
   Double_t        sbs_gemCeF_hit_VtimeMaxStrip[4];   //[Ndata.sbs.gemCeF.hit.VtimeMaxStrip]
   Int_t           Ndata_sbs_gemCeF_hit_VtimeMaxStripDeconv;
   Double_t        sbs_gemCeF_hit_VtimeMaxStripDeconv[4];   //[Ndata.sbs.gemCeF.hit.VtimeMaxStripDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_VtimeMaxStripFit;
   Double_t        sbs_gemCeF_hit_VtimeMaxStripFit[4];   //[Ndata.sbs.gemCeF.hit.VtimeMaxStripFit]
   Int_t           Ndata_sbs_gemCeF_hit_adc_id_U;
   Double_t        sbs_gemCeF_hit_adc_id_U[4];   //[Ndata.sbs.gemCeF.hit.adc_id_U]
   Int_t           Ndata_sbs_gemCeF_hit_adc_id_V;
   Double_t        sbs_gemCeF_hit_adc_id_V[4];   //[Ndata.sbs.gemCeF.hit.adc_id_V]
   Int_t           Ndata_sbs_gemCeF_hit_ccor_clust;
   Double_t        sbs_gemCeF_hit_ccor_clust[4];   //[Ndata.sbs.gemCeF.hit.ccor_clust]
   Int_t           Ndata_sbs_gemCeF_hit_ccor_clust_deconv;
   Double_t        sbs_gemCeF_hit_ccor_clust_deconv[4];   //[Ndata.sbs.gemCeF.hit.ccor_clust_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_ccor_strip;
   Double_t        sbs_gemCeF_hit_ccor_strip[4];   //[Ndata.sbs.gemCeF.hit.ccor_strip]
   Int_t           Ndata_sbs_gemCeF_hit_ccor_strip_deconv;
   Double_t        sbs_gemCeF_hit_ccor_strip_deconv[4];   //[Ndata.sbs.gemCeF.hit.ccor_strip_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_crate_U;
   Double_t        sbs_gemCeF_hit_crate_U[4];   //[Ndata.sbs.gemCeF.hit.crate_U]
   Int_t           Ndata_sbs_gemCeF_hit_crate_V;
   Double_t        sbs_gemCeF_hit_crate_V[4];   //[Ndata.sbs.gemCeF.hit.crate_V]
   Int_t           Ndata_sbs_gemCeF_hit_deltat;
   Double_t        sbs_gemCeF_hit_deltat[4];   //[Ndata.sbs.gemCeF.hit.deltat]
   Int_t           Ndata_sbs_gemCeF_hit_deltat_deconv;
   Double_t        sbs_gemCeF_hit_deltat_deconv[4];   //[Ndata.sbs.gemCeF.hit.deltat_deconv]
   Int_t           Ndata_sbs_gemCeF_hit_deltat_fit;
   Double_t        sbs_gemCeF_hit_deltat_fit[4];   //[Ndata.sbs.gemCeF.hit.deltat_fit]
   Int_t           Ndata_sbs_gemCeF_hit_eresidu;
   Double_t        sbs_gemCeF_hit_eresidu[4];   //[Ndata.sbs.gemCeF.hit.eresidu]
   Int_t           Ndata_sbs_gemCeF_hit_eresidv;
   Double_t        sbs_gemCeF_hit_eresidv[4];   //[Ndata.sbs.gemCeF.hit.eresidv]
   Int_t           Ndata_sbs_gemCeF_hit_icombomaxUclustDeconv;
   Double_t        sbs_gemCeF_hit_icombomaxUclustDeconv[4];   //[Ndata.sbs.gemCeF.hit.icombomaxUclustDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_icombomaxUstripDeconv;
   Double_t        sbs_gemCeF_hit_icombomaxUstripDeconv[4];   //[Ndata.sbs.gemCeF.hit.icombomaxUstripDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_icombomaxVclustDeconv;
   Double_t        sbs_gemCeF_hit_icombomaxVclustDeconv[4];   //[Ndata.sbs.gemCeF.hit.icombomaxVclustDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_icombomaxVstripDeconv;
   Double_t        sbs_gemCeF_hit_icombomaxVstripDeconv[4];   //[Ndata.sbs.gemCeF.hit.icombomaxVstripDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_isampmaxUclust;
   Double_t        sbs_gemCeF_hit_isampmaxUclust[4];   //[Ndata.sbs.gemCeF.hit.isampmaxUclust]
   Int_t           Ndata_sbs_gemCeF_hit_isampmaxUclustDeconv;
   Double_t        sbs_gemCeF_hit_isampmaxUclustDeconv[4];   //[Ndata.sbs.gemCeF.hit.isampmaxUclustDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_isampmaxUstrip;
   Double_t        sbs_gemCeF_hit_isampmaxUstrip[4];   //[Ndata.sbs.gemCeF.hit.isampmaxUstrip]
   Int_t           Ndata_sbs_gemCeF_hit_isampmaxUstripDeconv;
   Double_t        sbs_gemCeF_hit_isampmaxUstripDeconv[4];   //[Ndata.sbs.gemCeF.hit.isampmaxUstripDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_isampmaxVclust;
   Double_t        sbs_gemCeF_hit_isampmaxVclust[4];   //[Ndata.sbs.gemCeF.hit.isampmaxVclust]
   Int_t           Ndata_sbs_gemCeF_hit_isampmaxVclustDeconv;
   Double_t        sbs_gemCeF_hit_isampmaxVclustDeconv[4];   //[Ndata.sbs.gemCeF.hit.isampmaxVclustDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_isampmaxVstrip;
   Double_t        sbs_gemCeF_hit_isampmaxVstrip[4];   //[Ndata.sbs.gemCeF.hit.isampmaxVstrip]
   Int_t           Ndata_sbs_gemCeF_hit_isampmaxVstripDeconv;
   Double_t        sbs_gemCeF_hit_isampmaxVstripDeconv[4];   //[Ndata.sbs.gemCeF.hit.isampmaxVstripDeconv]
   Int_t           Ndata_sbs_gemCeF_hit_layer;
   Double_t        sbs_gemCeF_hit_layer[4];   //[Ndata.sbs.gemCeF.hit.layer]
   Int_t           Ndata_sbs_gemCeF_hit_module;
   Double_t        sbs_gemCeF_hit_module[4];   //[Ndata.sbs.gemCeF.hit.module]
   Int_t           Ndata_sbs_gemCeF_hit_mpd_U;
   Double_t        sbs_gemCeF_hit_mpd_U[4];   //[Ndata.sbs.gemCeF.hit.mpd_U]
   Int_t           Ndata_sbs_gemCeF_hit_mpd_V;
   Double_t        sbs_gemCeF_hit_mpd_V[4];   //[Ndata.sbs.gemCeF.hit.mpd_V]
   Int_t           Ndata_sbs_gemCeF_hit_nstripu;
   Double_t        sbs_gemCeF_hit_nstripu[4];   //[Ndata.sbs.gemCeF.hit.nstripu]
   Int_t           Ndata_sbs_gemCeF_hit_nstripv;
   Double_t        sbs_gemCeF_hit_nstripv[4];   //[Ndata.sbs.gemCeF.hit.nstripv]
   Int_t           Ndata_sbs_gemCeF_hit_residu;
   Double_t        sbs_gemCeF_hit_residu[4];   //[Ndata.sbs.gemCeF.hit.residu]
   Int_t           Ndata_sbs_gemCeF_hit_residv;
   Double_t        sbs_gemCeF_hit_residv[4];   //[Ndata.sbs.gemCeF.hit.residv]
   Int_t           Ndata_sbs_gemCeF_hit_trackindex;
   Double_t        sbs_gemCeF_hit_trackindex[4];   //[Ndata.sbs.gemCeF.hit.trackindex]
   Int_t           Ndata_sbs_gemCeF_hit_u;
   Double_t        sbs_gemCeF_hit_u[4];   //[Ndata.sbs.gemCeF.hit.u]
   Int_t           Ndata_sbs_gemCeF_hit_uTScorr_MaxStripU;
   Double_t        sbs_gemCeF_hit_uTScorr_MaxStripU[4];   //[Ndata.sbs.gemCeF.hit.uTScorr_MaxStripU]
   Int_t           Ndata_sbs_gemCeF_hit_uTScorr_MaxStripV;
   Double_t        sbs_gemCeF_hit_uTScorr_MaxStripV[4];   //[Ndata.sbs.gemCeF.hit.uTScorr_MaxStripV]
   Int_t           Ndata_sbs_gemCeF_hit_uTScorr_Uclust;
   Double_t        sbs_gemCeF_hit_uTScorr_Uclust[4];   //[Ndata.sbs.gemCeF.hit.uTScorr_Uclust]
   Int_t           Ndata_sbs_gemCeF_hit_uTScorr_Vclust;
   Double_t        sbs_gemCeF_hit_uTScorr_Vclust[4];   //[Ndata.sbs.gemCeF.hit.uTScorr_Vclust]
   Int_t           Ndata_sbs_gemCeF_hit_umoment;
   Double_t        sbs_gemCeF_hit_umoment[4];   //[Ndata.sbs.gemCeF.hit.umoment]
   Int_t           Ndata_sbs_gemCeF_hit_usigma;
   Double_t        sbs_gemCeF_hit_usigma[4];   //[Ndata.sbs.gemCeF.hit.usigma]
   Int_t           Ndata_sbs_gemCeF_hit_ustriphi;
   Double_t        sbs_gemCeF_hit_ustriphi[4];   //[Ndata.sbs.gemCeF.hit.ustriphi]
   Int_t           Ndata_sbs_gemCeF_hit_ustriplo;
   Double_t        sbs_gemCeF_hit_ustriplo[4];   //[Ndata.sbs.gemCeF.hit.ustriplo]
   Int_t           Ndata_sbs_gemCeF_hit_ustripmax;
   Double_t        sbs_gemCeF_hit_ustripmax[4];   //[Ndata.sbs.gemCeF.hit.ustripmax]
   Int_t           Ndata_sbs_gemCeF_hit_v;
   Double_t        sbs_gemCeF_hit_v[4];   //[Ndata.sbs.gemCeF.hit.v]
   Int_t           Ndata_sbs_gemCeF_hit_vmoment;
   Double_t        sbs_gemCeF_hit_vmoment[4];   //[Ndata.sbs.gemCeF.hit.vmoment]
   Int_t           Ndata_sbs_gemCeF_hit_vsigma;
   Double_t        sbs_gemCeF_hit_vsigma[4];   //[Ndata.sbs.gemCeF.hit.vsigma]
   Int_t           Ndata_sbs_gemCeF_hit_vstriphi;
   Double_t        sbs_gemCeF_hit_vstriphi[4];   //[Ndata.sbs.gemCeF.hit.vstriphi]
   Int_t           Ndata_sbs_gemCeF_hit_vstriplo;
   Double_t        sbs_gemCeF_hit_vstriplo[4];   //[Ndata.sbs.gemCeF.hit.vstriplo]
   Int_t           Ndata_sbs_gemCeF_hit_vstripmax;
   Double_t        sbs_gemCeF_hit_vstripmax[4];   //[Ndata.sbs.gemCeF.hit.vstripmax]
   Int_t           Ndata_sbs_gemCeF_hit_wTScorr_MaxStripU;
   Double_t        sbs_gemCeF_hit_wTScorr_MaxStripU[4];   //[Ndata.sbs.gemCeF.hit.wTScorr_MaxStripU]
   Int_t           Ndata_sbs_gemCeF_hit_wTScorr_MaxStripV;
   Double_t        sbs_gemCeF_hit_wTScorr_MaxStripV[4];   //[Ndata.sbs.gemCeF.hit.wTScorr_MaxStripV]
   Int_t           Ndata_sbs_gemCeF_hit_wTScorr_Uclust;
   Double_t        sbs_gemCeF_hit_wTScorr_Uclust[4];   //[Ndata.sbs.gemCeF.hit.wTScorr_Uclust]
   Int_t           Ndata_sbs_gemCeF_hit_wTScorr_Vclust;
   Double_t        sbs_gemCeF_hit_wTScorr_Vclust[4];   //[Ndata.sbs.gemCeF.hit.wTScorr_Vclust]
   Int_t           Ndata_sbs_gemCeF_hit_xglobal;
   Double_t        sbs_gemCeF_hit_xglobal[4];   //[Ndata.sbs.gemCeF.hit.xglobal]
   Int_t           Ndata_sbs_gemCeF_hit_xlocal;
   Double_t        sbs_gemCeF_hit_xlocal[4];   //[Ndata.sbs.gemCeF.hit.xlocal]
   Int_t           Ndata_sbs_gemCeF_hit_yglobal;
   Double_t        sbs_gemCeF_hit_yglobal[4];   //[Ndata.sbs.gemCeF.hit.yglobal]
   Int_t           Ndata_sbs_gemCeF_hit_ylocal;
   Double_t        sbs_gemCeF_hit_ylocal[4];   //[Ndata.sbs.gemCeF.hit.ylocal]
   Int_t           Ndata_sbs_gemCeF_hit_zglobal;
   Double_t        sbs_gemCeF_hit_zglobal[4];   //[Ndata.sbs.gemCeF.hit.zglobal]
   Int_t           Ndata_sbs_gemCeF_n2Dhit_layer;
   Double_t        sbs_gemCeF_n2Dhit_layer[4];   //[Ndata.sbs.gemCeF.n2Dhit_layer]
   Int_t           Ndata_sbs_gemCeF_nclustu_layer;
   Double_t        sbs_gemCeF_nclustu_layer[4];   //[Ndata.sbs.gemCeF.nclustu_layer]
   Int_t           Ndata_sbs_gemCeF_nclustv_layer;
   Double_t        sbs_gemCeF_nclustv_layer[4];   //[Ndata.sbs.gemCeF.nclustv_layer]
   Int_t           Ndata_sbs_gemCeF_nstripsu_layer;
   Double_t        sbs_gemCeF_nstripsu_layer[4];   //[Ndata.sbs.gemCeF.nstripsu_layer]
   Int_t           Ndata_sbs_gemCeF_nstripsv_layer;
   Double_t        sbs_gemCeF_nstripsv_layer[4];   //[Ndata.sbs.gemCeF.nstripsv_layer]
   Int_t           Ndata_sbs_gemCeF_track_chi2ndf;
   Double_t        sbs_gemCeF_track_chi2ndf[1];   //[Ndata.sbs.gemCeF.track.chi2ndf]
   Int_t           Ndata_sbs_gemCeF_track_chi2ndf_hitquality;
   Double_t        sbs_gemCeF_track_chi2ndf_hitquality[1];   //[Ndata.sbs.gemCeF.track.chi2ndf_hitquality]
   Int_t           Ndata_sbs_gemCeF_track_ngoodhits;
   Double_t        sbs_gemCeF_track_ngoodhits[1];   //[Ndata.sbs.gemCeF.track.ngoodhits]
   Int_t           Ndata_sbs_gemCeF_track_nhits;
   Double_t        sbs_gemCeF_track_nhits[1];   //[Ndata.sbs.gemCeF.track.nhits]
   Int_t           Ndata_sbs_gemCeF_track_t0;
   Double_t        sbs_gemCeF_track_t0[1];   //[Ndata.sbs.gemCeF.track.t0]
   Int_t           Ndata_sbs_gemCeF_track_x;
   Double_t        sbs_gemCeF_track_x[1];   //[Ndata.sbs.gemCeF.track.x]
   Int_t           Ndata_sbs_gemCeF_track_xp;
   Double_t        sbs_gemCeF_track_xp[1];   //[Ndata.sbs.gemCeF.track.xp]
   Int_t           Ndata_sbs_gemCeF_track_y;
   Double_t        sbs_gemCeF_track_y[1];   //[Ndata.sbs.gemCeF.track.y]
   Int_t           Ndata_sbs_gemCeF_track_yp;
   Double_t        sbs_gemCeF_track_yp[1];   //[Ndata.sbs.gemCeF.track.yp]
   Int_t           Ndata_sbs_gemCeR_hit_ADCU;
   Double_t        sbs_gemCeR_hit_ADCU[47];   //[Ndata.sbs.gemCeR.hit.ADCU]
   Int_t           Ndata_sbs_gemCeR_hit_ADCU_deconv;
   Double_t        sbs_gemCeR_hit_ADCU_deconv[47];   //[Ndata.sbs.gemCeR.hit.ADCU_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ADCV;
   Double_t        sbs_gemCeR_hit_ADCV[47];   //[Ndata.sbs.gemCeR.hit.ADCV]
   Int_t           Ndata_sbs_gemCeR_hit_ADCV_deconv;
   Double_t        sbs_gemCeR_hit_ADCV_deconv[47];   //[Ndata.sbs.gemCeR.hit.ADCV_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ADCasym;
   Double_t        sbs_gemCeR_hit_ADCasym[47];   //[Ndata.sbs.gemCeR.hit.ADCasym]
   Int_t           Ndata_sbs_gemCeR_hit_ADCasym_deconv;
   Double_t        sbs_gemCeR_hit_ADCasym_deconv[47];   //[Ndata.sbs.gemCeR.hit.ADCasym_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ADCavg;
   Double_t        sbs_gemCeR_hit_ADCavg[47];   //[Ndata.sbs.gemCeR.hit.ADCavg]
   Int_t           Ndata_sbs_gemCeR_hit_ADCavg_deconv;
   Double_t        sbs_gemCeR_hit_ADCavg_deconv[47];   //[Ndata.sbs.gemCeR.hit.ADCavg_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac0_Umax;
   Double_t        sbs_gemCeR_hit_ADCfrac0_Umax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac0_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac0_Vmax;
   Double_t        sbs_gemCeR_hit_ADCfrac0_Vmax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac0_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac1_Umax;
   Double_t        sbs_gemCeR_hit_ADCfrac1_Umax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac1_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac1_Vmax;
   Double_t        sbs_gemCeR_hit_ADCfrac1_Vmax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac1_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac2_Umax;
   Double_t        sbs_gemCeR_hit_ADCfrac2_Umax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac2_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac2_Vmax;
   Double_t        sbs_gemCeR_hit_ADCfrac2_Vmax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac2_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac3_Umax;
   Double_t        sbs_gemCeR_hit_ADCfrac3_Umax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac3_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac3_Vmax;
   Double_t        sbs_gemCeR_hit_ADCfrac3_Vmax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac3_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac4_Umax;
   Double_t        sbs_gemCeR_hit_ADCfrac4_Umax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac4_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac4_Vmax;
   Double_t        sbs_gemCeR_hit_ADCfrac4_Vmax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac4_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac5_Umax;
   Double_t        sbs_gemCeR_hit_ADCfrac5_Umax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac5_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCfrac5_Vmax;
   Double_t        sbs_gemCeR_hit_ADCfrac5_Vmax[47];   //[Ndata.sbs.gemCeR.hit.ADCfrac5_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxcomboUclust_deconv;
   Double_t        sbs_gemCeR_hit_ADCmaxcomboUclust_deconv[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxcomboUclust_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxcomboVclust_deconv;
   Double_t        sbs_gemCeR_hit_ADCmaxcomboVclust_deconv[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxcomboVclust_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxsampU;
   Double_t        sbs_gemCeR_hit_ADCmaxsampU[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxsampU]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxsampUclust;
   Double_t        sbs_gemCeR_hit_ADCmaxsampUclust[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxsampUclust]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxsampUclust_deconv;
   Double_t        sbs_gemCeR_hit_ADCmaxsampUclust_deconv[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxsampUclust_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxsampV;
   Double_t        sbs_gemCeR_hit_ADCmaxsampV[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxsampV]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxsampVclust;
   Double_t        sbs_gemCeR_hit_ADCmaxsampVclust[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxsampVclust]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxsampVclust_deconv;
   Double_t        sbs_gemCeR_hit_ADCmaxsampVclust_deconv[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxsampVclust_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxstripU;
   Double_t        sbs_gemCeR_hit_ADCmaxstripU[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxstripU]
   Int_t           Ndata_sbs_gemCeR_hit_ADCmaxstripV;
   Double_t        sbs_gemCeR_hit_ADCmaxstripV[47];   //[Ndata.sbs.gemCeR.hit.ADCmaxstripV]
   Int_t           Ndata_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_U;
   Double_t        sbs_gemCeR_hit_BUILD_ALL_SAMPLES_U[47];   //[Ndata.sbs.gemCeR.hit.BUILD_ALL_SAMPLES_U]
   Int_t           Ndata_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_V;
   Double_t        sbs_gemCeR_hit_BUILD_ALL_SAMPLES_V[47];   //[Ndata.sbs.gemCeR.hit.BUILD_ALL_SAMPLES_V]
   Int_t           Ndata_sbs_gemCeR_hit_CM_GOOD_U;
   Double_t        sbs_gemCeR_hit_CM_GOOD_U[47];   //[Ndata.sbs.gemCeR.hit.CM_GOOD_U]
   Int_t           Ndata_sbs_gemCeR_hit_CM_GOOD_V;
   Double_t        sbs_gemCeR_hit_CM_GOOD_V[47];   //[Ndata.sbs.gemCeR.hit.CM_GOOD_V]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC0_Umax;
   Double_t        sbs_gemCeR_hit_DeconvADC0_Umax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC0_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC0_Vmax;
   Double_t        sbs_gemCeR_hit_DeconvADC0_Vmax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC0_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC1_Umax;
   Double_t        sbs_gemCeR_hit_DeconvADC1_Umax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC1_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC1_Vmax;
   Double_t        sbs_gemCeR_hit_DeconvADC1_Vmax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC1_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC2_Umax;
   Double_t        sbs_gemCeR_hit_DeconvADC2_Umax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC2_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC2_Vmax;
   Double_t        sbs_gemCeR_hit_DeconvADC2_Vmax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC2_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC3_Umax;
   Double_t        sbs_gemCeR_hit_DeconvADC3_Umax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC3_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC3_Vmax;
   Double_t        sbs_gemCeR_hit_DeconvADC3_Vmax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC3_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC4_Umax;
   Double_t        sbs_gemCeR_hit_DeconvADC4_Umax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC4_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC4_Vmax;
   Double_t        sbs_gemCeR_hit_DeconvADC4_Vmax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC4_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC5_Umax;
   Double_t        sbs_gemCeR_hit_DeconvADC5_Umax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC5_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADC5_Vmax;
   Double_t        sbs_gemCeR_hit_DeconvADC5_Vmax[47];   //[Ndata.sbs.gemCeR.hit.DeconvADC5_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADCmaxcomboU;
   Double_t        sbs_gemCeR_hit_DeconvADCmaxcomboU[47];   //[Ndata.sbs.gemCeR.hit.DeconvADCmaxcomboU]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADCmaxcomboV;
   Double_t        sbs_gemCeR_hit_DeconvADCmaxcomboV[47];   //[Ndata.sbs.gemCeR.hit.DeconvADCmaxcomboV]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADCmaxsampU;
   Double_t        sbs_gemCeR_hit_DeconvADCmaxsampU[47];   //[Ndata.sbs.gemCeR.hit.DeconvADCmaxsampU]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADCmaxsampV;
   Double_t        sbs_gemCeR_hit_DeconvADCmaxsampV[47];   //[Ndata.sbs.gemCeR.hit.DeconvADCmaxsampV]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADCmaxstripU;
   Double_t        sbs_gemCeR_hit_DeconvADCmaxstripU[47];   //[Ndata.sbs.gemCeR.hit.DeconvADCmaxstripU]
   Int_t           Ndata_sbs_gemCeR_hit_DeconvADCmaxstripV;
   Double_t        sbs_gemCeR_hit_DeconvADCmaxstripV[47];   //[Ndata.sbs.gemCeR.hit.DeconvADCmaxstripV]
   Int_t           Ndata_sbs_gemCeR_hit_ENABLE_CM_U;
   Double_t        sbs_gemCeR_hit_ENABLE_CM_U[47];   //[Ndata.sbs.gemCeR.hit.ENABLE_CM_U]
   Int_t           Ndata_sbs_gemCeR_hit_ENABLE_CM_V;
   Double_t        sbs_gemCeR_hit_ENABLE_CM_V[47];   //[Ndata.sbs.gemCeR.hit.ENABLE_CM_V]
   Int_t           Ndata_sbs_gemCeR_hit_TSchi2_Umax;
   Double_t        sbs_gemCeR_hit_TSchi2_Umax[47];   //[Ndata.sbs.gemCeR.hit.TSchi2_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_TSchi2_Vmax;
   Double_t        sbs_gemCeR_hit_TSchi2_Vmax[47];   //[Ndata.sbs.gemCeR.hit.TSchi2_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_TSprob_Umax;
   Double_t        sbs_gemCeR_hit_TSprob_Umax[47];   //[Ndata.sbs.gemCeR.hit.TSprob_Umax]
   Int_t           Ndata_sbs_gemCeR_hit_TSprob_Vmax;
   Double_t        sbs_gemCeR_hit_TSprob_Vmax[47];   //[Ndata.sbs.gemCeR.hit.TSprob_Vmax]
   Int_t           Ndata_sbs_gemCeR_hit_Tavg;
   Double_t        sbs_gemCeR_hit_Tavg[47];   //[Ndata.sbs.gemCeR.hit.Tavg]
   Int_t           Ndata_sbs_gemCeR_hit_Tavg_corr;
   Double_t        sbs_gemCeR_hit_Tavg_corr[47];   //[Ndata.sbs.gemCeR.hit.Tavg_corr]
   Int_t           Ndata_sbs_gemCeR_hit_Tavg_deconv;
   Double_t        sbs_gemCeR_hit_Tavg_deconv[47];   //[Ndata.sbs.gemCeR.hit.Tavg_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_Tavg_fit;
   Double_t        sbs_gemCeR_hit_Tavg_fit[47];   //[Ndata.sbs.gemCeR.hit.Tavg_fit]
   Int_t           Ndata_sbs_gemCeR_hit_Ugain;
   Double_t        sbs_gemCeR_hit_Ugain[47];   //[Ndata.sbs.gemCeR.hit.Ugain]
   Int_t           Ndata_sbs_gemCeR_hit_Utime;
   Double_t        sbs_gemCeR_hit_Utime[47];   //[Ndata.sbs.gemCeR.hit.Utime]
   Int_t           Ndata_sbs_gemCeR_hit_UtimeDeconv;
   Double_t        sbs_gemCeR_hit_UtimeDeconv[47];   //[Ndata.sbs.gemCeR.hit.UtimeDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_UtimeFit;
   Double_t        sbs_gemCeR_hit_UtimeFit[47];   //[Ndata.sbs.gemCeR.hit.UtimeFit]
   Int_t           Ndata_sbs_gemCeR_hit_UtimeMaxStrip;
   Double_t        sbs_gemCeR_hit_UtimeMaxStrip[47];   //[Ndata.sbs.gemCeR.hit.UtimeMaxStrip]
   Int_t           Ndata_sbs_gemCeR_hit_UtimeMaxStripDeconv;
   Double_t        sbs_gemCeR_hit_UtimeMaxStripDeconv[47];   //[Ndata.sbs.gemCeR.hit.UtimeMaxStripDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_UtimeMaxStripFit;
   Double_t        sbs_gemCeR_hit_UtimeMaxStripFit[47];   //[Ndata.sbs.gemCeR.hit.UtimeMaxStripFit]
   Int_t           Ndata_sbs_gemCeR_hit_Vgain;
   Double_t        sbs_gemCeR_hit_Vgain[47];   //[Ndata.sbs.gemCeR.hit.Vgain]
   Int_t           Ndata_sbs_gemCeR_hit_Vtime;
   Double_t        sbs_gemCeR_hit_Vtime[47];   //[Ndata.sbs.gemCeR.hit.Vtime]
   Int_t           Ndata_sbs_gemCeR_hit_VtimeDeconv;
   Double_t        sbs_gemCeR_hit_VtimeDeconv[47];   //[Ndata.sbs.gemCeR.hit.VtimeDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_VtimeFit;
   Double_t        sbs_gemCeR_hit_VtimeFit[47];   //[Ndata.sbs.gemCeR.hit.VtimeFit]
   Int_t           Ndata_sbs_gemCeR_hit_VtimeMaxStrip;
   Double_t        sbs_gemCeR_hit_VtimeMaxStrip[47];   //[Ndata.sbs.gemCeR.hit.VtimeMaxStrip]
   Int_t           Ndata_sbs_gemCeR_hit_VtimeMaxStripDeconv;
   Double_t        sbs_gemCeR_hit_VtimeMaxStripDeconv[47];   //[Ndata.sbs.gemCeR.hit.VtimeMaxStripDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_VtimeMaxStripFit;
   Double_t        sbs_gemCeR_hit_VtimeMaxStripFit[47];   //[Ndata.sbs.gemCeR.hit.VtimeMaxStripFit]
   Int_t           Ndata_sbs_gemCeR_hit_adc_id_U;
   Double_t        sbs_gemCeR_hit_adc_id_U[47];   //[Ndata.sbs.gemCeR.hit.adc_id_U]
   Int_t           Ndata_sbs_gemCeR_hit_adc_id_V;
   Double_t        sbs_gemCeR_hit_adc_id_V[47];   //[Ndata.sbs.gemCeR.hit.adc_id_V]
   Int_t           Ndata_sbs_gemCeR_hit_ccor_clust;
   Double_t        sbs_gemCeR_hit_ccor_clust[47];   //[Ndata.sbs.gemCeR.hit.ccor_clust]
   Int_t           Ndata_sbs_gemCeR_hit_ccor_clust_deconv;
   Double_t        sbs_gemCeR_hit_ccor_clust_deconv[47];   //[Ndata.sbs.gemCeR.hit.ccor_clust_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_ccor_strip;
   Double_t        sbs_gemCeR_hit_ccor_strip[47];   //[Ndata.sbs.gemCeR.hit.ccor_strip]
   Int_t           Ndata_sbs_gemCeR_hit_ccor_strip_deconv;
   Double_t        sbs_gemCeR_hit_ccor_strip_deconv[47];   //[Ndata.sbs.gemCeR.hit.ccor_strip_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_crate_U;
   Double_t        sbs_gemCeR_hit_crate_U[47];   //[Ndata.sbs.gemCeR.hit.crate_U]
   Int_t           Ndata_sbs_gemCeR_hit_crate_V;
   Double_t        sbs_gemCeR_hit_crate_V[47];   //[Ndata.sbs.gemCeR.hit.crate_V]
   Int_t           Ndata_sbs_gemCeR_hit_deltat;
   Double_t        sbs_gemCeR_hit_deltat[47];   //[Ndata.sbs.gemCeR.hit.deltat]
   Int_t           Ndata_sbs_gemCeR_hit_deltat_deconv;
   Double_t        sbs_gemCeR_hit_deltat_deconv[47];   //[Ndata.sbs.gemCeR.hit.deltat_deconv]
   Int_t           Ndata_sbs_gemCeR_hit_deltat_fit;
   Double_t        sbs_gemCeR_hit_deltat_fit[47];   //[Ndata.sbs.gemCeR.hit.deltat_fit]
   Int_t           Ndata_sbs_gemCeR_hit_eresidu;
   Double_t        sbs_gemCeR_hit_eresidu[47];   //[Ndata.sbs.gemCeR.hit.eresidu]
   Int_t           Ndata_sbs_gemCeR_hit_eresidv;
   Double_t        sbs_gemCeR_hit_eresidv[47];   //[Ndata.sbs.gemCeR.hit.eresidv]
   Int_t           Ndata_sbs_gemCeR_hit_icombomaxUclustDeconv;
   Double_t        sbs_gemCeR_hit_icombomaxUclustDeconv[47];   //[Ndata.sbs.gemCeR.hit.icombomaxUclustDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_icombomaxUstripDeconv;
   Double_t        sbs_gemCeR_hit_icombomaxUstripDeconv[47];   //[Ndata.sbs.gemCeR.hit.icombomaxUstripDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_icombomaxVclustDeconv;
   Double_t        sbs_gemCeR_hit_icombomaxVclustDeconv[47];   //[Ndata.sbs.gemCeR.hit.icombomaxVclustDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_icombomaxVstripDeconv;
   Double_t        sbs_gemCeR_hit_icombomaxVstripDeconv[47];   //[Ndata.sbs.gemCeR.hit.icombomaxVstripDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_isampmaxUclust;
   Double_t        sbs_gemCeR_hit_isampmaxUclust[47];   //[Ndata.sbs.gemCeR.hit.isampmaxUclust]
   Int_t           Ndata_sbs_gemCeR_hit_isampmaxUclustDeconv;
   Double_t        sbs_gemCeR_hit_isampmaxUclustDeconv[47];   //[Ndata.sbs.gemCeR.hit.isampmaxUclustDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_isampmaxUstrip;
   Double_t        sbs_gemCeR_hit_isampmaxUstrip[47];   //[Ndata.sbs.gemCeR.hit.isampmaxUstrip]
   Int_t           Ndata_sbs_gemCeR_hit_isampmaxUstripDeconv;
   Double_t        sbs_gemCeR_hit_isampmaxUstripDeconv[47];   //[Ndata.sbs.gemCeR.hit.isampmaxUstripDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_isampmaxVclust;
   Double_t        sbs_gemCeR_hit_isampmaxVclust[47];   //[Ndata.sbs.gemCeR.hit.isampmaxVclust]
   Int_t           Ndata_sbs_gemCeR_hit_isampmaxVclustDeconv;
   Double_t        sbs_gemCeR_hit_isampmaxVclustDeconv[47];   //[Ndata.sbs.gemCeR.hit.isampmaxVclustDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_isampmaxVstrip;
   Double_t        sbs_gemCeR_hit_isampmaxVstrip[47];   //[Ndata.sbs.gemCeR.hit.isampmaxVstrip]
   Int_t           Ndata_sbs_gemCeR_hit_isampmaxVstripDeconv;
   Double_t        sbs_gemCeR_hit_isampmaxVstripDeconv[47];   //[Ndata.sbs.gemCeR.hit.isampmaxVstripDeconv]
   Int_t           Ndata_sbs_gemCeR_hit_layer;
   Double_t        sbs_gemCeR_hit_layer[47];   //[Ndata.sbs.gemCeR.hit.layer]
   Int_t           Ndata_sbs_gemCeR_hit_module;
   Double_t        sbs_gemCeR_hit_module[47];   //[Ndata.sbs.gemCeR.hit.module]
   Int_t           Ndata_sbs_gemCeR_hit_mpd_U;
   Double_t        sbs_gemCeR_hit_mpd_U[47];   //[Ndata.sbs.gemCeR.hit.mpd_U]
   Int_t           Ndata_sbs_gemCeR_hit_mpd_V;
   Double_t        sbs_gemCeR_hit_mpd_V[47];   //[Ndata.sbs.gemCeR.hit.mpd_V]
   Int_t           Ndata_sbs_gemCeR_hit_nstripu;
   Double_t        sbs_gemCeR_hit_nstripu[47];   //[Ndata.sbs.gemCeR.hit.nstripu]
   Int_t           Ndata_sbs_gemCeR_hit_nstripv;
   Double_t        sbs_gemCeR_hit_nstripv[47];   //[Ndata.sbs.gemCeR.hit.nstripv]
   Int_t           Ndata_sbs_gemCeR_hit_residu;
   Double_t        sbs_gemCeR_hit_residu[47];   //[Ndata.sbs.gemCeR.hit.residu]
   Int_t           Ndata_sbs_gemCeR_hit_residv;
   Double_t        sbs_gemCeR_hit_residv[47];   //[Ndata.sbs.gemCeR.hit.residv]
   Int_t           Ndata_sbs_gemCeR_hit_trackindex;
   Double_t        sbs_gemCeR_hit_trackindex[47];   //[Ndata.sbs.gemCeR.hit.trackindex]
   Int_t           Ndata_sbs_gemCeR_hit_u;
   Double_t        sbs_gemCeR_hit_u[47];   //[Ndata.sbs.gemCeR.hit.u]
   Int_t           Ndata_sbs_gemCeR_hit_uTScorr_MaxStripU;
   Double_t        sbs_gemCeR_hit_uTScorr_MaxStripU[47];   //[Ndata.sbs.gemCeR.hit.uTScorr_MaxStripU]
   Int_t           Ndata_sbs_gemCeR_hit_uTScorr_MaxStripV;
   Double_t        sbs_gemCeR_hit_uTScorr_MaxStripV[47];   //[Ndata.sbs.gemCeR.hit.uTScorr_MaxStripV]
   Int_t           Ndata_sbs_gemCeR_hit_uTScorr_Uclust;
   Double_t        sbs_gemCeR_hit_uTScorr_Uclust[47];   //[Ndata.sbs.gemCeR.hit.uTScorr_Uclust]
   Int_t           Ndata_sbs_gemCeR_hit_uTScorr_Vclust;
   Double_t        sbs_gemCeR_hit_uTScorr_Vclust[47];   //[Ndata.sbs.gemCeR.hit.uTScorr_Vclust]
   Int_t           Ndata_sbs_gemCeR_hit_umoment;
   Double_t        sbs_gemCeR_hit_umoment[47];   //[Ndata.sbs.gemCeR.hit.umoment]
   Int_t           Ndata_sbs_gemCeR_hit_usigma;
   Double_t        sbs_gemCeR_hit_usigma[47];   //[Ndata.sbs.gemCeR.hit.usigma]
   Int_t           Ndata_sbs_gemCeR_hit_ustriphi;
   Double_t        sbs_gemCeR_hit_ustriphi[47];   //[Ndata.sbs.gemCeR.hit.ustriphi]
   Int_t           Ndata_sbs_gemCeR_hit_ustriplo;
   Double_t        sbs_gemCeR_hit_ustriplo[47];   //[Ndata.sbs.gemCeR.hit.ustriplo]
   Int_t           Ndata_sbs_gemCeR_hit_ustripmax;
   Double_t        sbs_gemCeR_hit_ustripmax[47];   //[Ndata.sbs.gemCeR.hit.ustripmax]
   Int_t           Ndata_sbs_gemCeR_hit_v;
   Double_t        sbs_gemCeR_hit_v[47];   //[Ndata.sbs.gemCeR.hit.v]
   Int_t           Ndata_sbs_gemCeR_hit_vmoment;
   Double_t        sbs_gemCeR_hit_vmoment[47];   //[Ndata.sbs.gemCeR.hit.vmoment]
   Int_t           Ndata_sbs_gemCeR_hit_vsigma;
   Double_t        sbs_gemCeR_hit_vsigma[47];   //[Ndata.sbs.gemCeR.hit.vsigma]
   Int_t           Ndata_sbs_gemCeR_hit_vstriphi;
   Double_t        sbs_gemCeR_hit_vstriphi[47];   //[Ndata.sbs.gemCeR.hit.vstriphi]
   Int_t           Ndata_sbs_gemCeR_hit_vstriplo;
   Double_t        sbs_gemCeR_hit_vstriplo[47];   //[Ndata.sbs.gemCeR.hit.vstriplo]
   Int_t           Ndata_sbs_gemCeR_hit_vstripmax;
   Double_t        sbs_gemCeR_hit_vstripmax[47];   //[Ndata.sbs.gemCeR.hit.vstripmax]
   Int_t           Ndata_sbs_gemCeR_hit_wTScorr_MaxStripU;
   Double_t        sbs_gemCeR_hit_wTScorr_MaxStripU[47];   //[Ndata.sbs.gemCeR.hit.wTScorr_MaxStripU]
   Int_t           Ndata_sbs_gemCeR_hit_wTScorr_MaxStripV;
   Double_t        sbs_gemCeR_hit_wTScorr_MaxStripV[47];   //[Ndata.sbs.gemCeR.hit.wTScorr_MaxStripV]
   Int_t           Ndata_sbs_gemCeR_hit_wTScorr_Uclust;
   Double_t        sbs_gemCeR_hit_wTScorr_Uclust[47];   //[Ndata.sbs.gemCeR.hit.wTScorr_Uclust]
   Int_t           Ndata_sbs_gemCeR_hit_wTScorr_Vclust;
   Double_t        sbs_gemCeR_hit_wTScorr_Vclust[47];   //[Ndata.sbs.gemCeR.hit.wTScorr_Vclust]
   Int_t           Ndata_sbs_gemCeR_hit_xglobal;
   Double_t        sbs_gemCeR_hit_xglobal[47];   //[Ndata.sbs.gemCeR.hit.xglobal]
   Int_t           Ndata_sbs_gemCeR_hit_xlocal;
   Double_t        sbs_gemCeR_hit_xlocal[47];   //[Ndata.sbs.gemCeR.hit.xlocal]
   Int_t           Ndata_sbs_gemCeR_hit_yglobal;
   Double_t        sbs_gemCeR_hit_yglobal[47];   //[Ndata.sbs.gemCeR.hit.yglobal]
   Int_t           Ndata_sbs_gemCeR_hit_ylocal;
   Double_t        sbs_gemCeR_hit_ylocal[47];   //[Ndata.sbs.gemCeR.hit.ylocal]
   Int_t           Ndata_sbs_gemCeR_hit_zglobal;
   Double_t        sbs_gemCeR_hit_zglobal[47];   //[Ndata.sbs.gemCeR.hit.zglobal]
   Int_t           Ndata_sbs_gemCeR_n2Dhit_layer;
   Double_t        sbs_gemCeR_n2Dhit_layer[4];   //[Ndata.sbs.gemCeR.n2Dhit_layer]
   Int_t           Ndata_sbs_gemCeR_nclustu_layer;
   Double_t        sbs_gemCeR_nclustu_layer[4];   //[Ndata.sbs.gemCeR.nclustu_layer]
   Int_t           Ndata_sbs_gemCeR_nclustv_layer;
   Double_t        sbs_gemCeR_nclustv_layer[4];   //[Ndata.sbs.gemCeR.nclustv_layer]
   Int_t           Ndata_sbs_gemCeR_nstripsu_layer;
   Double_t        sbs_gemCeR_nstripsu_layer[4];   //[Ndata.sbs.gemCeR.nstripsu_layer]
   Int_t           Ndata_sbs_gemCeR_nstripsv_layer;
   Double_t        sbs_gemCeR_nstripsv_layer[4];   //[Ndata.sbs.gemCeR.nstripsv_layer]
   Int_t           Ndata_sbs_gemCeR_track_chi2ndf;
   Double_t        sbs_gemCeR_track_chi2ndf[12];   //[Ndata.sbs.gemCeR.track.chi2ndf]
   Int_t           Ndata_sbs_gemCeR_track_chi2ndf_hitquality;
   Double_t        sbs_gemCeR_track_chi2ndf_hitquality[12];   //[Ndata.sbs.gemCeR.track.chi2ndf_hitquality]
   Int_t           Ndata_sbs_gemCeR_track_ngoodhits;
   Double_t        sbs_gemCeR_track_ngoodhits[12];   //[Ndata.sbs.gemCeR.track.ngoodhits]
   Int_t           Ndata_sbs_gemCeR_track_nhits;
   Double_t        sbs_gemCeR_track_nhits[12];   //[Ndata.sbs.gemCeR.track.nhits]
   Int_t           Ndata_sbs_gemCeR_track_phi;
   Double_t        sbs_gemCeR_track_phi[1];   //[Ndata.sbs.gemCeR.track.phi]
   Int_t           Ndata_sbs_gemCeR_track_sclose;
   Double_t        sbs_gemCeR_track_sclose[1];   //[Ndata.sbs.gemCeR.track.sclose]
   Int_t           Ndata_sbs_gemCeR_track_t0;
   Double_t        sbs_gemCeR_track_t0[12];   //[Ndata.sbs.gemCeR.track.t0]
   Int_t           Ndata_sbs_gemCeR_track_theta;
   Double_t        sbs_gemCeR_track_theta[1];   //[Ndata.sbs.gemCeR.track.theta]
   Int_t           Ndata_sbs_gemCeR_track_x;
   Double_t        sbs_gemCeR_track_x[12];   //[Ndata.sbs.gemCeR.track.x]
   Int_t           Ndata_sbs_gemCeR_track_xp;
   Double_t        sbs_gemCeR_track_xp[12];   //[Ndata.sbs.gemCeR.track.xp]
   Int_t           Ndata_sbs_gemCeR_track_y;
   Double_t        sbs_gemCeR_track_y[12];   //[Ndata.sbs.gemCeR.track.y]
   Int_t           Ndata_sbs_gemCeR_track_yp;
   Double_t        sbs_gemCeR_track_yp[12];   //[Ndata.sbs.gemCeR.track.yp]
   Int_t           Ndata_sbs_gemCeR_track_zclose;
   Double_t        sbs_gemCeR_track_zclose[1];   //[Ndata.sbs.gemCeR.track.zclose]
   Int_t           Ndata_sbs_hcal_Ref_tdc;
   Double_t        sbs_hcal_Ref_tdc[3];   //[Ndata.sbs.hcal.Ref.tdc]
   Int_t           Ndata_sbs_hcal_Ref_tdc_mult;
   Double_t        sbs_hcal_Ref_tdc_mult[3];   //[Ndata.sbs.hcal.Ref.tdc_mult]
   Int_t           Ndata_sbs_hcal_Ref_tdcelemID;
   Double_t        sbs_hcal_Ref_tdcelemID[3];   //[Ndata.sbs.hcal.Ref.tdcelemID]
   Int_t           Ndata_sbs_hcal_a_amp_p;
   Double_t        sbs_hcal_a_amp_p[30];   //[Ndata.sbs.hcal.a_amp_p]
   Int_t           Ndata_sbs_hcal_a_c;
   Double_t        sbs_hcal_a_c[30];   //[Ndata.sbs.hcal.a_c]
   Int_t           Ndata_sbs_hcal_a_p;
   Double_t        sbs_hcal_a_p[30];   //[Ndata.sbs.hcal.a_p]
   Int_t           Ndata_sbs_hcal_a_time;
   Double_t        sbs_hcal_a_time[30];   //[Ndata.sbs.hcal.a_time]
   Int_t           Ndata_sbs_hcal_adccol;
   Double_t        sbs_hcal_adccol[30];   //[Ndata.sbs.hcal.adccol]
   Int_t           Ndata_sbs_hcal_adcelemID;
   Double_t        sbs_hcal_adcelemID[30];   //[Ndata.sbs.hcal.adcelemID]
   Int_t           Ndata_sbs_hcal_adcrow;
   Double_t        sbs_hcal_adcrow[30];   //[Ndata.sbs.hcal.adcrow]
   Int_t           Ndata_sbs_hcal_adcxpos;
   Double_t        sbs_hcal_adcxpos[30];   //[Ndata.sbs.hcal.adcxpos]
   Int_t           Ndata_sbs_hcal_adcypos;
   Double_t        sbs_hcal_adcypos[30];   //[Ndata.sbs.hcal.adcypos]
   Int_t           Ndata_sbs_hcal_clus_adctime;
   Double_t        sbs_hcal_clus_adctime[17];   //[Ndata.sbs.hcal.clus.adctime]
   Int_t           Ndata_sbs_hcal_clus_again;
   Double_t        sbs_hcal_clus_again[17];   //[Ndata.sbs.hcal.clus.again]
   Int_t           Ndata_sbs_hcal_clus_atimeblk;
   Double_t        sbs_hcal_clus_atimeblk[17];   //[Ndata.sbs.hcal.clus.atimeblk]
   Int_t           Ndata_sbs_hcal_clus_col;
   Double_t        sbs_hcal_clus_col[17];   //[Ndata.sbs.hcal.clus.col]
   Int_t           Ndata_sbs_hcal_clus_col_goodtdc;
   Double_t        sbs_hcal_clus_col_goodtdc[17];   //[Ndata.sbs.hcal.clus.col_goodtdc]
   Int_t           Ndata_sbs_hcal_clus_e;
   Double_t        sbs_hcal_clus_e[17];   //[Ndata.sbs.hcal.clus.e]
   Int_t           Ndata_sbs_hcal_clus_e_goodtdc;
   Double_t        sbs_hcal_clus_e_goodtdc[17];   //[Ndata.sbs.hcal.clus.e_goodtdc]
   Int_t           Ndata_sbs_hcal_clus_eblk;
   Double_t        sbs_hcal_clus_eblk[17];   //[Ndata.sbs.hcal.clus.eblk]
   Int_t           Ndata_sbs_hcal_clus_eblk_goodtdc;
   Double_t        sbs_hcal_clus_eblk_goodtdc[17];   //[Ndata.sbs.hcal.clus.eblk_goodtdc]
   Int_t           Ndata_sbs_hcal_clus_id;
   Double_t        sbs_hcal_clus_id[17];   //[Ndata.sbs.hcal.clus.id]
   Int_t           Ndata_sbs_hcal_clus_id_goodtdc;
   Double_t        sbs_hcal_clus_id_goodtdc[17];   //[Ndata.sbs.hcal.clus.id_goodtdc]
   Int_t           Ndata_sbs_hcal_clus_nblk;
   Double_t        sbs_hcal_clus_nblk[17];   //[Ndata.sbs.hcal.clus.nblk]
   Int_t           Ndata_sbs_hcal_clus_nblk_goodtdc;
   Double_t        sbs_hcal_clus_nblk_goodtdc[17];   //[Ndata.sbs.hcal.clus.nblk_goodtdc]
   Int_t           Ndata_sbs_hcal_clus_row;
   Double_t        sbs_hcal_clus_row[17];   //[Ndata.sbs.hcal.clus.row]
   Int_t           Ndata_sbs_hcal_clus_row_goodtdc;
   Double_t        sbs_hcal_clus_row_goodtdc[17];   //[Ndata.sbs.hcal.clus.row_goodtdc]
   Int_t           Ndata_sbs_hcal_clus_tdctime;
   Double_t        sbs_hcal_clus_tdctime[17];   //[Ndata.sbs.hcal.clus.tdctime]
   Int_t           Ndata_sbs_hcal_clus_tdctime_tw;
   Double_t        sbs_hcal_clus_tdctime_tw[17];   //[Ndata.sbs.hcal.clus.tdctime_tw]
   Int_t           Ndata_sbs_hcal_clus_tdctimeblk;
   Double_t        sbs_hcal_clus_tdctimeblk[17];   //[Ndata.sbs.hcal.clus.tdctimeblk]
   Int_t           Ndata_sbs_hcal_clus_tdctimeblk_tw;
   Double_t        sbs_hcal_clus_tdctimeblk_tw[17];   //[Ndata.sbs.hcal.clus.tdctimeblk_tw]
   Int_t           Ndata_sbs_hcal_clus_x;
   Double_t        sbs_hcal_clus_x[17];   //[Ndata.sbs.hcal.clus.x]
   Int_t           Ndata_sbs_hcal_clus_y;
   Double_t        sbs_hcal_clus_y[17];   //[Ndata.sbs.hcal.clus.y]
   Int_t           Ndata_sbs_hcal_clus_blk_again;
   Double_t        sbs_hcal_clus_blk_again[14];   //[Ndata.sbs.hcal.clus_blk.again]
   Int_t           Ndata_sbs_hcal_clus_blk_atime;
   Double_t        sbs_hcal_clus_blk_atime[14];   //[Ndata.sbs.hcal.clus_blk.atime]
   Int_t           Ndata_sbs_hcal_clus_blk_col;
   Double_t        sbs_hcal_clus_blk_col[14];   //[Ndata.sbs.hcal.clus_blk.col]
   Int_t           Ndata_sbs_hcal_clus_blk_e;
   Double_t        sbs_hcal_clus_blk_e[14];   //[Ndata.sbs.hcal.clus_blk.e]
   Int_t           Ndata_sbs_hcal_clus_blk_id;
   Double_t        sbs_hcal_clus_blk_id[14];   //[Ndata.sbs.hcal.clus_blk.id]
   Int_t           Ndata_sbs_hcal_clus_blk_row;
   Double_t        sbs_hcal_clus_blk_row[14];   //[Ndata.sbs.hcal.clus_blk.row]
   Int_t           Ndata_sbs_hcal_clus_blk_tdctime;
   Double_t        sbs_hcal_clus_blk_tdctime[14];   //[Ndata.sbs.hcal.clus_blk.tdctime]
   Int_t           Ndata_sbs_hcal_clus_blk_tdctime_tw;
   Double_t        sbs_hcal_clus_blk_tdctime_tw[14];   //[Ndata.sbs.hcal.clus_blk.tdctime_tw]
   Int_t           Ndata_sbs_hcal_clus_blk_x;
   Double_t        sbs_hcal_clus_blk_x[14];   //[Ndata.sbs.hcal.clus_blk.x]
   Int_t           Ndata_sbs_hcal_clus_blk_y;
   Double_t        sbs_hcal_clus_blk_y[14];   //[Ndata.sbs.hcal.clus_blk.y]
   Int_t           Ndata_sbs_hcal_ped;
   Double_t        sbs_hcal_ped[30];   //[Ndata.sbs.hcal.ped]
   Int_t           Ndata_sbs_tdctrig_Ref_tdc;
   Double_t        sbs_tdctrig_Ref_tdc[1];   //[Ndata.sbs.tdctrig.Ref.tdc]
   Int_t           Ndata_sbs_tdctrig_Ref_tdc_mult;
   Double_t        sbs_tdctrig_Ref_tdc_mult[1];   //[Ndata.sbs.tdctrig.Ref.tdc_mult]
   Int_t           Ndata_sbs_tdctrig_Ref_tdcelemID;
   Double_t        sbs_tdctrig_Ref_tdcelemID[1];   //[Ndata.sbs.tdctrig.Ref.tdcelemID]
   Int_t           Ndata_sbs_tdctrig_tdc;
   Double_t        sbs_tdctrig_tdc[2];   //[Ndata.sbs.tdctrig.tdc]
   Int_t           Ndata_sbs_tdctrig_tdc_mult;
   Double_t        sbs_tdctrig_tdc_mult[2];   //[Ndata.sbs.tdctrig.tdc_mult]
   Int_t           Ndata_sbs_tdctrig_tdccol;
   Double_t        sbs_tdctrig_tdccol[2];   //[Ndata.sbs.tdctrig.tdccol]
   Int_t           Ndata_sbs_tdctrig_tdcelemID;
   Double_t        sbs_tdctrig_tdcelemID[2];   //[Ndata.sbs.tdctrig.tdcelemID]
   Int_t           Ndata_sbs_tdctrig_tdclayer;
   Double_t        sbs_tdctrig_tdclayer[2];   //[Ndata.sbs.tdctrig.tdclayer]
   Int_t           Ndata_sbs_tdctrig_tdcrow;
   Double_t        sbs_tdctrig_tdcrow[2];   //[Ndata.sbs.tdctrig.tdcrow]
   Int_t           Ndata_sbs_tr_beta;
   Double_t        sbs_tr_beta[1];   //[Ndata.sbs.tr.beta]
   Int_t           Ndata_sbs_tr_chi2;
   Double_t        sbs_tr_chi2[1];   //[Ndata.sbs.tr.chi2]
   Int_t           Ndata_sbs_tr_d_ph;
   Double_t        sbs_tr_d_ph[1];   //[Ndata.sbs.tr.d_ph]
   Int_t           Ndata_sbs_tr_d_th;
   Double_t        sbs_tr_d_th[1];   //[Ndata.sbs.tr.d_th]
   Int_t           Ndata_sbs_tr_d_x;
   Double_t        sbs_tr_d_x[1];   //[Ndata.sbs.tr.d_x]
   Int_t           Ndata_sbs_tr_d_y;
   Double_t        sbs_tr_d_y[1];   //[Ndata.sbs.tr.d_y]
   Int_t           Ndata_sbs_tr_dbeta;
   Double_t        sbs_tr_dbeta[1];   //[Ndata.sbs.tr.dbeta]
   Int_t           Ndata_sbs_tr_dtime;
   Double_t        sbs_tr_dtime[1];   //[Ndata.sbs.tr.dtime]
   Int_t           Ndata_sbs_tr_flag;
   Double_t        sbs_tr_flag[1];   //[Ndata.sbs.tr.flag]
   Int_t           Ndata_sbs_tr_ndof;
   Double_t        sbs_tr_ndof[1];   //[Ndata.sbs.tr.ndof]
   Int_t           Ndata_sbs_tr_p;
   Double_t        sbs_tr_p[1];   //[Ndata.sbs.tr.p]
   Int_t           Ndata_sbs_tr_pathl;
   Double_t        sbs_tr_pathl[1];   //[Ndata.sbs.tr.pathl]
   Int_t           Ndata_sbs_tr_ph;
   Double_t        sbs_tr_ph[1];   //[Ndata.sbs.tr.ph]
   Int_t           Ndata_sbs_tr_px;
   Double_t        sbs_tr_px[1];   //[Ndata.sbs.tr.px]
   Int_t           Ndata_sbs_tr_py;
   Double_t        sbs_tr_py[1];   //[Ndata.sbs.tr.py]
   Int_t           Ndata_sbs_tr_pz;
   Double_t        sbs_tr_pz[1];   //[Ndata.sbs.tr.pz]
   Int_t           Ndata_sbs_tr_r_ph;
   Double_t        sbs_tr_r_ph[1];   //[Ndata.sbs.tr.r_ph]
   Int_t           Ndata_sbs_tr_r_th;
   Double_t        sbs_tr_r_th[1];   //[Ndata.sbs.tr.r_th]
   Int_t           Ndata_sbs_tr_r_x;
   Double_t        sbs_tr_r_x[1];   //[Ndata.sbs.tr.r_x]
   Int_t           Ndata_sbs_tr_r_y;
   Double_t        sbs_tr_r_y[1];   //[Ndata.sbs.tr.r_y]
   Int_t           Ndata_sbs_tr_tg_dp;
   Double_t        sbs_tr_tg_dp[1];   //[Ndata.sbs.tr.tg_dp]
   Int_t           Ndata_sbs_tr_tg_ph;
   Double_t        sbs_tr_tg_ph[1];   //[Ndata.sbs.tr.tg_ph]
   Int_t           Ndata_sbs_tr_tg_th;
   Double_t        sbs_tr_tg_th[1];   //[Ndata.sbs.tr.tg_th]
   Int_t           Ndata_sbs_tr_tg_y;
   Double_t        sbs_tr_tg_y[1];   //[Ndata.sbs.tr.tg_y]
   Int_t           Ndata_sbs_tr_th;
   Double_t        sbs_tr_th[1];   //[Ndata.sbs.tr.th]
   Int_t           Ndata_sbs_tr_time;
   Double_t        sbs_tr_time[1];   //[Ndata.sbs.tr.time]
   Int_t           Ndata_sbs_tr_vx;
   Double_t        sbs_tr_vx[1];   //[Ndata.sbs.tr.vx]
   Int_t           Ndata_sbs_tr_vy;
   Double_t        sbs_tr_vy[1];   //[Ndata.sbs.tr.vy]
   Int_t           Ndata_sbs_tr_vz;
   Double_t        sbs_tr_vz[1];   //[Ndata.sbs.tr.vz]
   Int_t           Ndata_sbs_tr_x;
   Double_t        sbs_tr_x[1];   //[Ndata.sbs.tr.x]
   Int_t           Ndata_sbs_tr_y;
   Double_t        sbs_tr_y[1];   //[Ndata.sbs.tr.y]
   Int_t           Ndata_sbs_trig_a_amp_p;
   Double_t        sbs_trig_a_amp_p[8];   //[Ndata.sbs.trig.a_amp_p]
   Int_t           Ndata_sbs_trig_a_p;
   Double_t        sbs_trig_a_p[8];   //[Ndata.sbs.trig.a_p]
   Int_t           Ndata_sbs_trig_a_time;
   Double_t        sbs_trig_a_time[8];   //[Ndata.sbs.trig.a_time]
   Int_t           Ndata_sbs_trig_adcelemID;
   Double_t        sbs_trig_adcelemID[8];   //[Ndata.sbs.trig.adcelemID]
   Int_t           Ndata_sbs_x_bcp;
   Double_t        sbs_x_bcp[2];   //[Ndata.sbs.x_bcp]
   Int_t           Ndata_sbs_x_bcp_FPP;
   Double_t        sbs_x_bcp_FPP[1];   //[Ndata.sbs.x_bcp_FPP]
   Int_t           Ndata_sbs_x_bcp_FT;
   Double_t        sbs_x_bcp_FT[1];   //[Ndata.sbs.x_bcp_FT]
   Int_t           Ndata_sbs_x_fcp;
   Double_t        sbs_x_fcp[2];   //[Ndata.sbs.x_fcp]
   Int_t           Ndata_sbs_x_fcp_FPP;
   Double_t        sbs_x_fcp_FPP[1];   //[Ndata.sbs.x_fcp_FPP]
   Int_t           Ndata_sbs_x_fcp_FT;
   Double_t        sbs_x_fcp_FT[1];   //[Ndata.sbs.x_fcp_FT]
   Int_t           Ndata_sbs_y_bcp;
   Double_t        sbs_y_bcp[2];   //[Ndata.sbs.y_bcp]
   Int_t           Ndata_sbs_y_bcp_FPP;
   Double_t        sbs_y_bcp_FPP[1];   //[Ndata.sbs.y_bcp_FPP]
   Int_t           Ndata_sbs_y_bcp_FT;
   Double_t        sbs_y_bcp_FT[1];   //[Ndata.sbs.y_bcp_FT]
   Int_t           Ndata_sbs_y_fcp;
   Double_t        sbs_y_fcp[2];   //[Ndata.sbs.y_fcp]
   Int_t           Ndata_sbs_y_fcp_FPP;
   Double_t        sbs_y_fcp_FPP[1];   //[Ndata.sbs.y_fcp_FPP]
   Int_t           Ndata_sbs_y_fcp_FT;
   Double_t        sbs_y_fcp_FT[1];   //[Ndata.sbs.y_fcp_FT]
   Int_t           Ndata_sbs_z_bcp;
   Double_t        sbs_z_bcp[2];   //[Ndata.sbs.z_bcp]
   Int_t           Ndata_sbs_z_bcp_FPP;
   Double_t        sbs_z_bcp_FPP[1];   //[Ndata.sbs.z_bcp_FPP]
   Int_t           Ndata_sbs_z_bcp_FT;
   Double_t        sbs_z_bcp_FT[1];   //[Ndata.sbs.z_bcp_FT]
   Int_t           Ndata_sbs_z_fcp;
   Double_t        sbs_z_fcp[2];   //[Ndata.sbs.z_fcp]
   Int_t           Ndata_sbs_z_fcp_FPP;
   Double_t        sbs_z_fcp_FPP[1];   //[Ndata.sbs.z_fcp_FPP]
   Int_t           Ndata_sbs_z_fcp_FT;
   Double_t        sbs_z_fcp_FT[1];   //[Ndata.sbs.z_fcp_FT]
   Double_t        BB_gold_beta;
   Double_t        BB_gold_dp;
   Double_t        BB_gold_index;
   Double_t        BB_gold_ok;
   Double_t        BB_gold_p;
   Double_t        BB_gold_ph;
   Double_t        BB_gold_px;
   Double_t        BB_gold_py;
   Double_t        BB_gold_pz;
   Double_t        BB_gold_th;
   Double_t        BB_gold_x;
   Double_t        BB_gold_y;
   Double_t        Lrb_BPMA_rawcur_1;
   Double_t        Lrb_BPMA_rawcur_2;
   Double_t        Lrb_BPMA_rawcur_3;
   Double_t        Lrb_BPMA_rawcur_4;
   Double_t        Lrb_BPMA_rotpos1;
   Double_t        Lrb_BPMA_rotpos2;
   Double_t        Lrb_BPMA_x;
   Double_t        Lrb_BPMA_y;
   Double_t        Lrb_BPMA_z;
   Double_t        Lrb_BPMB_rawcur_1;
   Double_t        Lrb_BPMB_rawcur_2;
   Double_t        Lrb_BPMB_rawcur_3;
   Double_t        Lrb_BPMB_rawcur_4;
   Double_t        Lrb_BPMB_rotpos1;
   Double_t        Lrb_BPMB_rotpos2;
   Double_t        Lrb_BPMB_x;
   Double_t        Lrb_BPMB_y;
   Double_t        Lrb_BPMB_z;
   Double_t        Lrb_Raster_bpma_x;
   Double_t        Lrb_Raster_bpma_y;
   Double_t        Lrb_Raster_bpma_z;
   Double_t        Lrb_Raster_bpmb_x;
   Double_t        Lrb_Raster_bpmb_y;
   Double_t        Lrb_Raster_bpmb_z;
   Double_t        Lrb_Raster_rawcur_x;
   Double_t        Lrb_Raster_rawcur_y;
   Double_t        Lrb_Raster_rawslope_x;
   Double_t        Lrb_Raster_rawslope_y;
   Double_t        Lrb_Raster_target_dir_x;
   Double_t        Lrb_Raster_target_dir_y;
   Double_t        Lrb_Raster_target_dir_z;
   Double_t        Lrb_Raster_target_x;
   Double_t        Lrb_Raster_target_y;
   Double_t        Lrb_Raster_target_z;
   Double_t        Lrb_Raster2_bpma_x;
   Double_t        Lrb_Raster2_bpma_y;
   Double_t        Lrb_Raster2_bpma_z;
   Double_t        Lrb_Raster2_bpmb_x;
   Double_t        Lrb_Raster2_bpmb_y;
   Double_t        Lrb_Raster2_bpmb_z;
   Double_t        Lrb_Raster2_rawcur_x;
   Double_t        Lrb_Raster2_rawcur_y;
   Double_t        Lrb_Raster2_rawslope_x;
   Double_t        Lrb_Raster2_rawslope_y;
   Double_t        Lrb_Raster2_target_dir_x;
   Double_t        Lrb_Raster2_target_dir_y;
   Double_t        Lrb_Raster2_target_dir_z;
   Double_t        Lrb_Raster2_target_x;
   Double_t        Lrb_Raster2_target_y;
   Double_t        Lrb_Raster2_target_z;
   Double_t        SBS_gold_beta;
   Double_t        SBS_gold_dp;
   Double_t        SBS_gold_index;
   Double_t        SBS_gold_ok;
   Double_t        SBS_gold_p;
   Double_t        SBS_gold_ph;
   Double_t        SBS_gold_px;
   Double_t        SBS_gold_py;
   Double_t        SBS_gold_pz;
   Double_t        SBS_gold_th;
   Double_t        SBS_gold_x;
   Double_t        SBS_gold_y;
   Double_t        SBSrb_BPMA_rawcur_1;
   Double_t        SBSrb_BPMA_rawcur_2;
   Double_t        SBSrb_BPMA_rawcur_3;
   Double_t        SBSrb_BPMA_rawcur_4;
   Double_t        SBSrb_BPMA_rotpos1;
   Double_t        SBSrb_BPMA_rotpos2;
   Double_t        SBSrb_BPMA_x;
   Double_t        SBSrb_BPMA_y;
   Double_t        SBSrb_BPMA_z;
   Double_t        SBSrb_BPMB_rawcur_1;
   Double_t        SBSrb_BPMB_rawcur_2;
   Double_t        SBSrb_BPMB_rawcur_3;
   Double_t        SBSrb_BPMB_rawcur_4;
   Double_t        SBSrb_BPMB_rotpos1;
   Double_t        SBSrb_BPMB_rotpos2;
   Double_t        SBSrb_BPMB_x;
   Double_t        SBSrb_BPMB_y;
   Double_t        SBSrb_BPMB_z;
   Double_t        SBSrb_Raster_bpma_x;
   Double_t        SBSrb_Raster_bpma_y;
   Double_t        SBSrb_Raster_bpma_z;
   Double_t        SBSrb_Raster_bpmb_x;
   Double_t        SBSrb_Raster_bpmb_y;
   Double_t        SBSrb_Raster_bpmb_z;
   Double_t        SBSrb_Raster_rawcur_x;
   Double_t        SBSrb_Raster_rawcur_y;
   Double_t        SBSrb_Raster_rawslope_x;
   Double_t        SBSrb_Raster_rawslope_y;
   Double_t        SBSrb_Raster_target_dir_x;
   Double_t        SBSrb_Raster_target_dir_y;
   Double_t        SBSrb_Raster_target_dir_z;
   Double_t        SBSrb_Raster_target_x;
   Double_t        SBSrb_Raster_target_y;
   Double_t        SBSrb_Raster_target_z;
   Double_t        SBSrb_Raster2_bpma_x;
   Double_t        SBSrb_Raster2_bpma_y;
   Double_t        SBSrb_Raster2_bpma_z;
   Double_t        SBSrb_Raster2_bpmb_x;
   Double_t        SBSrb_Raster2_bpmb_y;
   Double_t        SBSrb_Raster2_bpmb_z;
   Double_t        SBSrb_Raster2_rawcur_x;
   Double_t        SBSrb_Raster2_rawcur_y;
   Double_t        SBSrb_Raster2_rawslope_x;
   Double_t        SBSrb_Raster2_rawslope_y;
   Double_t        SBSrb_Raster2_target_dir_x;
   Double_t        SBSrb_Raster2_target_dir_y;
   Double_t        SBSrb_Raster2_target_dir_z;
   Double_t        SBSrb_Raster2_target_x;
   Double_t        SBSrb_Raster2_target_y;
   Double_t        SBSrb_Raster2_target_z;
   Double_t        bb_gem_hit_ngoodhits;
   Double_t        bb_gem_m0_clust_nclustu;
   Double_t        bb_gem_m0_clust_nclustu_tot;
   Double_t        bb_gem_m0_clust_nclustv;
   Double_t        bb_gem_m0_clust_nclustv_tot;
   Double_t        bb_gem_m0_strip_nstrips_keep;
   Double_t        bb_gem_m0_strip_nstrips_keepU;
   Double_t        bb_gem_m0_strip_nstrips_keepV;
   Double_t        bb_gem_m0_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m0_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m0_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m0_strip_nstripsfired;
   Double_t        bb_gem_m1_clust_nclustu;
   Double_t        bb_gem_m1_clust_nclustu_tot;
   Double_t        bb_gem_m1_clust_nclustv;
   Double_t        bb_gem_m1_clust_nclustv_tot;
   Double_t        bb_gem_m1_strip_nstrips_keep;
   Double_t        bb_gem_m1_strip_nstrips_keepU;
   Double_t        bb_gem_m1_strip_nstrips_keepV;
   Double_t        bb_gem_m1_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m1_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m1_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m1_strip_nstripsfired;
   Double_t        bb_gem_m2_clust_nclustu;
   Double_t        bb_gem_m2_clust_nclustu_tot;
   Double_t        bb_gem_m2_clust_nclustv;
   Double_t        bb_gem_m2_clust_nclustv_tot;
   Double_t        bb_gem_m2_strip_nstrips_keep;
   Double_t        bb_gem_m2_strip_nstrips_keepU;
   Double_t        bb_gem_m2_strip_nstrips_keepV;
   Double_t        bb_gem_m2_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m2_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m2_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m2_strip_nstripsfired;
   Double_t        bb_gem_m3_clust_nclustu;
   Double_t        bb_gem_m3_clust_nclustu_tot;
   Double_t        bb_gem_m3_clust_nclustv;
   Double_t        bb_gem_m3_clust_nclustv_tot;
   Double_t        bb_gem_m3_strip_nstrips_keep;
   Double_t        bb_gem_m3_strip_nstrips_keepU;
   Double_t        bb_gem_m3_strip_nstrips_keepV;
   Double_t        bb_gem_m3_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m3_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m3_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m3_strip_nstripsfired;
   Double_t        bb_gem_m4_clust_nclustu;
   Double_t        bb_gem_m4_clust_nclustu_tot;
   Double_t        bb_gem_m4_clust_nclustv;
   Double_t        bb_gem_m4_clust_nclustv_tot;
   Double_t        bb_gem_m4_strip_nstrips_keep;
   Double_t        bb_gem_m4_strip_nstrips_keepU;
   Double_t        bb_gem_m4_strip_nstrips_keepV;
   Double_t        bb_gem_m4_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m4_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m4_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m4_strip_nstripsfired;
   Double_t        bb_gem_m5_clust_nclustu;
   Double_t        bb_gem_m5_clust_nclustu_tot;
   Double_t        bb_gem_m5_clust_nclustv;
   Double_t        bb_gem_m5_clust_nclustv_tot;
   Double_t        bb_gem_m5_strip_nstrips_keep;
   Double_t        bb_gem_m5_strip_nstrips_keepU;
   Double_t        bb_gem_m5_strip_nstrips_keepV;
   Double_t        bb_gem_m5_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m5_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m5_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m5_strip_nstripsfired;
   Double_t        bb_gem_m6_clust_nclustu;
   Double_t        bb_gem_m6_clust_nclustu_tot;
   Double_t        bb_gem_m6_clust_nclustv;
   Double_t        bb_gem_m6_clust_nclustv_tot;
   Double_t        bb_gem_m6_strip_nstrips_keep;
   Double_t        bb_gem_m6_strip_nstrips_keepU;
   Double_t        bb_gem_m6_strip_nstrips_keepV;
   Double_t        bb_gem_m6_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m6_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m6_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m6_strip_nstripsfired;
   Double_t        bb_gem_m7_clust_nclustu;
   Double_t        bb_gem_m7_clust_nclustu_tot;
   Double_t        bb_gem_m7_clust_nclustv;
   Double_t        bb_gem_m7_clust_nclustv_tot;
   Double_t        bb_gem_m7_strip_nstrips_keep;
   Double_t        bb_gem_m7_strip_nstrips_keepU;
   Double_t        bb_gem_m7_strip_nstrips_keepV;
   Double_t        bb_gem_m7_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m7_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m7_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m7_strip_nstripsfired;
   Double_t        bb_gem_nlayershit;
   Double_t        bb_gem_nlayershitu;
   Double_t        bb_gem_nlayershituv;
   Double_t        bb_gem_nlayershitv;
   Double_t        bb_gem_track_besttrack;
   Double_t        bb_gem_track_ntrack;
   Double_t        bb_gem_trigtime;
   Double_t        bb_grinch_tdc_bestcluster;
   Double_t        bb_grinch_tdc_clus_adc;
   Double_t        bb_grinch_tdc_clus_dx;
   Double_t        bb_grinch_tdc_clus_dy;
   Double_t        bb_grinch_tdc_clus_mirrorindex;
   Double_t        bb_grinch_tdc_clus_size;
   Double_t        bb_grinch_tdc_clus_t_mean;
   Double_t        bb_grinch_tdc_clus_t_mean_corr;
   Double_t        bb_grinch_tdc_clus_t_rms;
   Double_t        bb_grinch_tdc_clus_t_rms_corr;
   Double_t        bb_grinch_tdc_clus_tot_mean;
   Double_t        bb_grinch_tdc_clus_trackindex;
   Double_t        bb_grinch_tdc_clus_x_mean;
   Double_t        bb_grinch_tdc_clus_y_mean;
   Double_t        bb_grinch_tdc_nclus;
   Double_t        bb_grinch_tdc_ngoodhits;
   Double_t        bb_grinch_tdc_ntrackmatch;
   Double_t        bb_hodotdc_nclus;
   Double_t        bb_hodotdc_rftime;
   Double_t        bb_hodotdc_trigphase;
   Double_t        bb_hodotdc_trigphasecorr;
   Double_t        bb_hodotdc_trigtime;
   Double_t        bb_ps_againblk;
   Double_t        bb_ps_atimeblk;
   Double_t        bb_ps_colblk;
   Double_t        bb_ps_e;
   Double_t        bb_ps_eblk;
   Double_t        bb_ps_idblk;
   Double_t        bb_ps_index;
   Double_t        bb_ps_nblk;
   Double_t        bb_ps_nclus;
   Double_t        bb_ps_ngoodADChits;
   Double_t        bb_ps_rowblk;
   Double_t        bb_ps_x;
   Double_t        bb_ps_y;
   Double_t        bb_sh_againblk;
   Double_t        bb_sh_atimeblk;
   Double_t        bb_sh_colblk;
   Double_t        bb_sh_e;
   Double_t        bb_sh_eblk;
   Double_t        bb_sh_idblk;
   Double_t        bb_sh_index;
   Double_t        bb_sh_nblk;
   Double_t        bb_sh_nclus;
   Double_t        bb_sh_ngoodADChits;
   Double_t        bb_sh_rowblk;
   Double_t        bb_sh_x;
   Double_t        bb_sh_y;
   Double_t        bb_tdctrig_rftime;
   Double_t        bb_tdctrig_trigtime;
   Double_t        bb_tr_n;
   Double_t        bb_ts_over_threshold;
   Double_t        e_kine_Q2;
   Double_t        e_kine_W2;
   Double_t        e_kine_angle;
   Double_t        e_kine_epsilon;
   Double_t        e_kine_nu;
   Double_t        e_kine_omega;
   Double_t        e_kine_ph_q;
   Double_t        e_kine_q3m;
   Double_t        e_kine_q_x;
   Double_t        e_kine_q_y;
   Double_t        e_kine_q_z;
   Double_t        e_kine_th_q;
   Double_t        e_kine_x_bj;
   Double_t        g_datatype;
   Double_t        g_evlen;
   Double_t        g_evnum;
   Double_t        g_evtime;
   Double_t        g_evtyp;
   Double_t        g_runnum;
   Double_t        g_runtime;
   Double_t        g_runtype;
   Double_t        g_trigbits;
   Double_t        sbs_HCALdir_x;
   Double_t        sbs_HCALdir_y;
   Double_t        sbs_HCALdir_z;
   Double_t        sbs_HCALph_n;
   Double_t        sbs_HCALth_n;
   Double_t        sbs_gemCeF_hit_ngoodhits;
   Double_t        sbs_gemCeF_m0_clust_nclustu;
   Double_t        sbs_gemCeF_m0_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m0_clust_nclustv;
   Double_t        sbs_gemCeF_m0_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m0_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m0_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m0_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m0_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m0_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m0_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m0_strip_nstripsfired;
   Double_t        sbs_gemCeF_m1_clust_nclustu;
   Double_t        sbs_gemCeF_m1_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m1_clust_nclustv;
   Double_t        sbs_gemCeF_m1_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m1_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m1_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m1_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m1_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m1_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m1_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m1_strip_nstripsfired;
   Double_t        sbs_gemCeF_m2_clust_nclustu;
   Double_t        sbs_gemCeF_m2_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m2_clust_nclustv;
   Double_t        sbs_gemCeF_m2_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m2_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m2_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m2_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m2_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m2_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m2_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m2_strip_nstripsfired;
   Double_t        sbs_gemCeF_m3_clust_nclustu;
   Double_t        sbs_gemCeF_m3_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m3_clust_nclustv;
   Double_t        sbs_gemCeF_m3_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m3_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m3_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m3_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m3_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m3_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m3_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m3_strip_nstripsfired;
   Double_t        sbs_gemCeF_m4_clust_nclustu;
   Double_t        sbs_gemCeF_m4_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m4_clust_nclustv;
   Double_t        sbs_gemCeF_m4_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m4_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m4_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m4_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m4_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m4_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m4_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m4_strip_nstripsfired;
   Double_t        sbs_gemCeF_m5_clust_nclustu;
   Double_t        sbs_gemCeF_m5_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m5_clust_nclustv;
   Double_t        sbs_gemCeF_m5_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m5_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m5_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m5_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m5_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m5_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m5_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m5_strip_nstripsfired;
   Double_t        sbs_gemCeF_m6_clust_nclustu;
   Double_t        sbs_gemCeF_m6_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m6_clust_nclustv;
   Double_t        sbs_gemCeF_m6_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m6_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m6_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m6_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m6_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m6_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m6_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m6_strip_nstripsfired;
   Double_t        sbs_gemCeF_m7_clust_nclustu;
   Double_t        sbs_gemCeF_m7_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m7_clust_nclustv;
   Double_t        sbs_gemCeF_m7_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m7_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m7_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m7_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m7_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m7_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m7_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m7_strip_nstripsfired;
   Double_t        sbs_gemCeF_m8_clust_nclustu;
   Double_t        sbs_gemCeF_m8_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m8_clust_nclustv;
   Double_t        sbs_gemCeF_m8_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m8_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m8_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m8_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m8_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m8_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m8_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m8_strip_nstripsfired;
   Double_t        sbs_gemCeF_m9_clust_nclustu;
   Double_t        sbs_gemCeF_m9_clust_nclustu_tot;
   Double_t        sbs_gemCeF_m9_clust_nclustv;
   Double_t        sbs_gemCeF_m9_clust_nclustv_tot;
   Double_t        sbs_gemCeF_m9_strip_nstrips_keep;
   Double_t        sbs_gemCeF_m9_strip_nstrips_keepU;
   Double_t        sbs_gemCeF_m9_strip_nstrips_keepV;
   Double_t        sbs_gemCeF_m9_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeF_m9_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeF_m9_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeF_m9_strip_nstripsfired;
   Double_t        sbs_gemCeF_nlayershit;
   Double_t        sbs_gemCeF_nlayershitu;
   Double_t        sbs_gemCeF_nlayershituv;
   Double_t        sbs_gemCeF_nlayershitv;
   Double_t        sbs_gemCeF_track_besttrack;
   Double_t        sbs_gemCeF_track_ntrack;
   Double_t        sbs_gemCeR_hit_ngoodhits;
   Double_t        sbs_gemCeR_m0_clust_nclustu;
   Double_t        sbs_gemCeR_m0_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m0_clust_nclustv;
   Double_t        sbs_gemCeR_m0_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m0_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m0_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m0_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m0_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m0_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m0_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m0_strip_nstripsfired;
   Double_t        sbs_gemCeR_m1_clust_nclustu;
   Double_t        sbs_gemCeR_m1_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m1_clust_nclustv;
   Double_t        sbs_gemCeR_m1_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m1_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m1_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m1_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m1_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m1_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m1_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m1_strip_nstripsfired;
   Double_t        sbs_gemCeR_m10_clust_nclustu;
   Double_t        sbs_gemCeR_m10_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m10_clust_nclustv;
   Double_t        sbs_gemCeR_m10_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m10_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m10_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m10_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m10_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m10_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m10_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m10_strip_nstripsfired;
   Double_t        sbs_gemCeR_m11_clust_nclustu;
   Double_t        sbs_gemCeR_m11_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m11_clust_nclustv;
   Double_t        sbs_gemCeR_m11_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m11_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m11_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m11_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m11_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m11_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m11_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m11_strip_nstripsfired;
   Double_t        sbs_gemCeR_m12_clust_nclustu;
   Double_t        sbs_gemCeR_m12_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m12_clust_nclustv;
   Double_t        sbs_gemCeR_m12_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m12_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m12_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m12_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m12_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m12_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m12_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m12_strip_nstripsfired;
   Double_t        sbs_gemCeR_m13_clust_nclustu;
   Double_t        sbs_gemCeR_m13_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m13_clust_nclustv;
   Double_t        sbs_gemCeR_m13_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m13_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m13_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m13_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m13_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m13_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m13_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m13_strip_nstripsfired;
   Double_t        sbs_gemCeR_m14_clust_nclustu;
   Double_t        sbs_gemCeR_m14_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m14_clust_nclustv;
   Double_t        sbs_gemCeR_m14_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m14_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m14_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m14_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m14_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m14_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m14_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m14_strip_nstripsfired;
   Double_t        sbs_gemCeR_m15_clust_nclustu;
   Double_t        sbs_gemCeR_m15_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m15_clust_nclustv;
   Double_t        sbs_gemCeR_m15_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m15_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m15_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m15_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m15_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m15_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m15_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m15_strip_nstripsfired;
   Double_t        sbs_gemCeR_m2_clust_nclustu;
   Double_t        sbs_gemCeR_m2_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m2_clust_nclustv;
   Double_t        sbs_gemCeR_m2_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m2_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m2_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m2_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m2_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m2_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m2_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m2_strip_nstripsfired;
   Double_t        sbs_gemCeR_m3_clust_nclustu;
   Double_t        sbs_gemCeR_m3_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m3_clust_nclustv;
   Double_t        sbs_gemCeR_m3_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m3_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m3_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m3_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m3_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m3_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m3_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m3_strip_nstripsfired;
   Double_t        sbs_gemCeR_m4_clust_nclustu;
   Double_t        sbs_gemCeR_m4_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m4_clust_nclustv;
   Double_t        sbs_gemCeR_m4_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m4_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m4_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m4_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m4_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m4_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m4_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m4_strip_nstripsfired;
   Double_t        sbs_gemCeR_m5_clust_nclustu;
   Double_t        sbs_gemCeR_m5_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m5_clust_nclustv;
   Double_t        sbs_gemCeR_m5_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m5_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m5_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m5_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m5_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m5_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m5_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m5_strip_nstripsfired;
   Double_t        sbs_gemCeR_m6_clust_nclustu;
   Double_t        sbs_gemCeR_m6_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m6_clust_nclustv;
   Double_t        sbs_gemCeR_m6_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m6_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m6_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m6_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m6_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m6_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m6_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m6_strip_nstripsfired;
   Double_t        sbs_gemCeR_m7_clust_nclustu;
   Double_t        sbs_gemCeR_m7_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m7_clust_nclustv;
   Double_t        sbs_gemCeR_m7_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m7_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m7_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m7_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m7_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m7_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m7_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m7_strip_nstripsfired;
   Double_t        sbs_gemCeR_m8_clust_nclustu;
   Double_t        sbs_gemCeR_m8_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m8_clust_nclustv;
   Double_t        sbs_gemCeR_m8_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m8_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m8_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m8_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m8_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m8_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m8_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m8_strip_nstripsfired;
   Double_t        sbs_gemCeR_m9_clust_nclustu;
   Double_t        sbs_gemCeR_m9_clust_nclustu_tot;
   Double_t        sbs_gemCeR_m9_clust_nclustv;
   Double_t        sbs_gemCeR_m9_clust_nclustv_tot;
   Double_t        sbs_gemCeR_m9_strip_nstrips_keep;
   Double_t        sbs_gemCeR_m9_strip_nstrips_keepU;
   Double_t        sbs_gemCeR_m9_strip_nstrips_keepV;
   Double_t        sbs_gemCeR_m9_strip_nstrips_keep_lmax;
   Double_t        sbs_gemCeR_m9_strip_nstrips_keep_lmaxU;
   Double_t        sbs_gemCeR_m9_strip_nstrips_keep_lmaxV;
   Double_t        sbs_gemCeR_m9_strip_nstripsfired;
   Double_t        sbs_gemCeR_nlayershit;
   Double_t        sbs_gemCeR_nlayershitu;
   Double_t        sbs_gemCeR_nlayershituv;
   Double_t        sbs_gemCeR_nlayershitv;
   Double_t        sbs_gemCeR_track_besttrack;
   Double_t        sbs_gemCeR_track_ntrack;
   Double_t        sbs_hcal_adctime;
   Double_t        sbs_hcal_againblk;
   Double_t        sbs_hcal_atimeblk;
   Double_t        sbs_hcal_colblk;
   Double_t        sbs_hcal_colblk_goodtdc;
   Double_t        sbs_hcal_e;
   Double_t        sbs_hcal_e_goodtdc;
   Double_t        sbs_hcal_eblk;
   Double_t        sbs_hcal_eblk_goodtdc;
   Double_t        sbs_hcal_idblk;
   Double_t        sbs_hcal_idblk_goodtdc;
   Double_t        sbs_hcal_index;
   Double_t        sbs_hcal_nblk;
   Double_t        sbs_hcal_nblk_goodtdc;
   Double_t        sbs_hcal_nclus;
   Double_t        sbs_hcal_ngoodADChits;
   Double_t        sbs_hcal_rftime;
   Double_t        sbs_hcal_rowblk;
   Double_t        sbs_hcal_rowblk_goodtdc;
   Double_t        sbs_hcal_tdctime;
   Double_t        sbs_hcal_tdctime_tw;
   Double_t        sbs_hcal_tdctimeblk;
   Double_t        sbs_hcal_tdctimeblk_tw;
   Double_t        sbs_hcal_trigtime;
   Double_t        sbs_hcal_x;
   Double_t        sbs_hcal_y;
   Double_t        sbs_tdctrig_ngoodADChits;
   Double_t        sbs_tdctrig_ngoodTDChits;
   Double_t        sbs_tdctrig_nhits;
   Double_t        sbs_tdctrig_nrefhits;
   Double_t        sbs_tdctrig_rftime;
   Double_t        sbs_tdctrig_trigphase;
   Double_t        sbs_tdctrig_trigphasecorr;
   Double_t        sbs_tdctrig_trigtime;
   Double_t        sbs_tr_n;
   Double_t        scalhel_errcode;
   Double_t        scalhel_evtcount;
   Double_t        scalhel_hel;
   Double_t        scalhel_lhrs_fadc_hel;
   Double_t        scalhel_lhrs_fadc_pat;
   Double_t        scalhel_lhrs_fadc_tsettle;
   Double_t        scalhel_patcount;
   Double_t        scalhel_patphase;
   Double_t        scalhel_seed;
   Double_t        singletrack_bb;
   Double_t        anytrack_bb;
   Double_t        HALLA_p;
   Double_t        hac_bcm_average;
   Double_t        IPM1H04A_XPOS;
   Double_t        IPM1H04A_YPOS;
   Double_t        IPM1H04E_XPOS;
   Double_t        IPM1H04E_YPOS;
   Double_t        IGL1I00OD16_16;
 //THaEvent        *Event_Branch;
   ULong64_t       fEvtHdr_fEvtTime;
   UInt_t          fEvtHdr_fEvtNum;
   UInt_t          fEvtHdr_fEvtType;
   UInt_t          fEvtHdr_fEvtLen;
   Int_t           fEvtHdr_fHelicity;
   UInt_t          fEvtHdr_fTrigBits;
   UInt_t          fEvtHdr_fRun;

   // List of branches
   TBranch        *b_ax_new;   //!
   TBranch        *b_bx_new;   //!
   TBranch        *b_ay_new;   //!
   TBranch        *b_by_new;   //!
   TBranch        *b_targx;   //!
   TBranch        *b_targy;   //!
   TBranch        *b_scalhel_true_hel;   //!
   TBranch        *b_scalhel_hel_stable;   //!
   TBranch        *b_Ndata_bb_bbtrig_a_amp_p;   //!
   TBranch        *b_bb_bbtrig_a_amp_p;   //!
   TBranch        *b_Ndata_bb_bbtrig_a_time;   //!
   TBranch        *b_bb_bbtrig_a_time;   //!
   TBranch        *b_Ndata_bb_bbtrig_adcelemID;   //!
   TBranch        *b_bb_bbtrig_adcelemID;   //!
   TBranch        *b_Ndata_bb_bbtrig_tdc;   //!
   TBranch        *b_bb_bbtrig_tdc;   //!
   TBranch        *b_Ndata_bb_bbtrig_tdcelemID;   //!
   TBranch        *b_bb_bbtrig_tdcelemID;   //!
   TBranch        *b_Ndata_bb_eps_over_etot;   //!
   TBranch        *b_bb_eps_over_etot;   //!
   TBranch        *b_Ndata_bb_etot_over_p;   //!
   TBranch        *b_bb_etot_over_p;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCU;   //!
   TBranch        *b_bb_gem_hit_ADCU;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCU_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCU_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCV;   //!
   TBranch        *b_bb_gem_hit_ADCV;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCV_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCV_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCasym;   //!
   TBranch        *b_bb_gem_hit_ADCasym;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCasym_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCasym_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCavg;   //!
   TBranch        *b_bb_gem_hit_ADCavg;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCavg_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCavg_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac0_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac0_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac0_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac0_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac1_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac1_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac1_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac1_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac2_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac2_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac2_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac2_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac3_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac3_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac3_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac3_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac4_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac4_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac4_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac4_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac5_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac5_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac5_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac5_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxcomboUclust_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCmaxcomboUclust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxcomboVclust_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCmaxcomboVclust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampU;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampU;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampUclust;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampUclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampUclust_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampUclust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampV;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampV;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampVclust;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampVclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampVclust_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampVclust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxstripU;   //!
   TBranch        *b_bb_gem_hit_ADCmaxstripU;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxstripV;   //!
   TBranch        *b_bb_gem_hit_ADCmaxstripV;   //!
   TBranch        *b_Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_U;   //!
   TBranch        *b_bb_gem_hit_BUILD_ALL_SAMPLES_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_V;   //!
   TBranch        *b_bb_gem_hit_BUILD_ALL_SAMPLES_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_CM_GOOD_U;   //!
   TBranch        *b_bb_gem_hit_CM_GOOD_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_CM_GOOD_V;   //!
   TBranch        *b_bb_gem_hit_CM_GOOD_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC0_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC0_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC0_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC0_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC1_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC1_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC1_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC1_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC2_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC2_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC2_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC2_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC3_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC3_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC3_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC3_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC4_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC4_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC4_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC4_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC5_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC5_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC5_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC5_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxcomboU;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxcomboU;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxcomboV;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxcomboV;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxsampU;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxsampU;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxsampV;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxsampV;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxstripU;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxstripU;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxstripV;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxstripV;   //!
   TBranch        *b_Ndata_bb_gem_hit_ENABLE_CM_U;   //!
   TBranch        *b_bb_gem_hit_ENABLE_CM_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_ENABLE_CM_V;   //!
   TBranch        *b_bb_gem_hit_ENABLE_CM_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_TSchi2_Umax;   //!
   TBranch        *b_bb_gem_hit_TSchi2_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_TSchi2_Vmax;   //!
   TBranch        *b_bb_gem_hit_TSchi2_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_TSprob_Umax;   //!
   TBranch        *b_bb_gem_hit_TSprob_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_TSprob_Vmax;   //!
   TBranch        *b_bb_gem_hit_TSprob_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_Tavg;   //!
   TBranch        *b_bb_gem_hit_Tavg;   //!
   TBranch        *b_Ndata_bb_gem_hit_Tavg_corr;   //!
   TBranch        *b_bb_gem_hit_Tavg_corr;   //!
   TBranch        *b_Ndata_bb_gem_hit_Tavg_deconv;   //!
   TBranch        *b_bb_gem_hit_Tavg_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_Tavg_fit;   //!
   TBranch        *b_bb_gem_hit_Tavg_fit;   //!
   TBranch        *b_Ndata_bb_gem_hit_Ugain;   //!
   TBranch        *b_bb_gem_hit_Ugain;   //!
   TBranch        *b_Ndata_bb_gem_hit_Utime;   //!
   TBranch        *b_bb_gem_hit_Utime;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeDeconv;   //!
   TBranch        *b_bb_gem_hit_UtimeDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeFit;   //!
   TBranch        *b_bb_gem_hit_UtimeFit;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeMaxStrip;   //!
   TBranch        *b_bb_gem_hit_UtimeMaxStrip;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeMaxStripDeconv;   //!
   TBranch        *b_bb_gem_hit_UtimeMaxStripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeMaxStripFit;   //!
   TBranch        *b_bb_gem_hit_UtimeMaxStripFit;   //!
   TBranch        *b_Ndata_bb_gem_hit_Vgain;   //!
   TBranch        *b_bb_gem_hit_Vgain;   //!
   TBranch        *b_Ndata_bb_gem_hit_Vtime;   //!
   TBranch        *b_bb_gem_hit_Vtime;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeDeconv;   //!
   TBranch        *b_bb_gem_hit_VtimeDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeFit;   //!
   TBranch        *b_bb_gem_hit_VtimeFit;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeMaxStrip;   //!
   TBranch        *b_bb_gem_hit_VtimeMaxStrip;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeMaxStripDeconv;   //!
   TBranch        *b_bb_gem_hit_VtimeMaxStripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeMaxStripFit;   //!
   TBranch        *b_bb_gem_hit_VtimeMaxStripFit;   //!
   TBranch        *b_Ndata_bb_gem_hit_adc_id_U;   //!
   TBranch        *b_bb_gem_hit_adc_id_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_adc_id_V;   //!
   TBranch        *b_bb_gem_hit_adc_id_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_ccor_clust;   //!
   TBranch        *b_bb_gem_hit_ccor_clust;   //!
   TBranch        *b_Ndata_bb_gem_hit_ccor_clust_deconv;   //!
   TBranch        *b_bb_gem_hit_ccor_clust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ccor_strip;   //!
   TBranch        *b_bb_gem_hit_ccor_strip;   //!
   TBranch        *b_Ndata_bb_gem_hit_ccor_strip_deconv;   //!
   TBranch        *b_bb_gem_hit_ccor_strip_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_crate_U;   //!
   TBranch        *b_bb_gem_hit_crate_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_crate_V;   //!
   TBranch        *b_bb_gem_hit_crate_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_deltat;   //!
   TBranch        *b_bb_gem_hit_deltat;   //!
   TBranch        *b_Ndata_bb_gem_hit_deltat_deconv;   //!
   TBranch        *b_bb_gem_hit_deltat_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_deltat_fit;   //!
   TBranch        *b_bb_gem_hit_deltat_fit;   //!
   TBranch        *b_Ndata_bb_gem_hit_eresidu;   //!
   TBranch        *b_bb_gem_hit_eresidu;   //!
   TBranch        *b_Ndata_bb_gem_hit_eresidv;   //!
   TBranch        *b_bb_gem_hit_eresidv;   //!
   TBranch        *b_Ndata_bb_gem_hit_icombomaxUclustDeconv;   //!
   TBranch        *b_bb_gem_hit_icombomaxUclustDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_icombomaxUstripDeconv;   //!
   TBranch        *b_bb_gem_hit_icombomaxUstripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_icombomaxVclustDeconv;   //!
   TBranch        *b_bb_gem_hit_icombomaxVclustDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_icombomaxVstripDeconv;   //!
   TBranch        *b_bb_gem_hit_icombomaxVstripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxUclust;   //!
   TBranch        *b_bb_gem_hit_isampmaxUclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxUclustDeconv;   //!
   TBranch        *b_bb_gem_hit_isampmaxUclustDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxUstrip;   //!
   TBranch        *b_bb_gem_hit_isampmaxUstrip;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxUstripDeconv;   //!
   TBranch        *b_bb_gem_hit_isampmaxUstripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxVclust;   //!
   TBranch        *b_bb_gem_hit_isampmaxVclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxVclustDeconv;   //!
   TBranch        *b_bb_gem_hit_isampmaxVclustDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxVstrip;   //!
   TBranch        *b_bb_gem_hit_isampmaxVstrip;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxVstripDeconv;   //!
   TBranch        *b_bb_gem_hit_isampmaxVstripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_layer;   //!
   TBranch        *b_bb_gem_hit_layer;   //!
   TBranch        *b_Ndata_bb_gem_hit_module;   //!
   TBranch        *b_bb_gem_hit_module;   //!
   TBranch        *b_Ndata_bb_gem_hit_mpd_U;   //!
   TBranch        *b_bb_gem_hit_mpd_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_mpd_V;   //!
   TBranch        *b_bb_gem_hit_mpd_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_nstripu;   //!
   TBranch        *b_bb_gem_hit_nstripu;   //!
   TBranch        *b_Ndata_bb_gem_hit_nstripv;   //!
   TBranch        *b_bb_gem_hit_nstripv;   //!
   TBranch        *b_Ndata_bb_gem_hit_residu;   //!
   TBranch        *b_bb_gem_hit_residu;   //!
   TBranch        *b_Ndata_bb_gem_hit_residv;   //!
   TBranch        *b_bb_gem_hit_residv;   //!
   TBranch        *b_Ndata_bb_gem_hit_trackindex;   //!
   TBranch        *b_bb_gem_hit_trackindex;   //!
   TBranch        *b_Ndata_bb_gem_hit_u;   //!
   TBranch        *b_bb_gem_hit_u;   //!
   TBranch        *b_Ndata_bb_gem_hit_uTScorr_MaxStripU;   //!
   TBranch        *b_bb_gem_hit_uTScorr_MaxStripU;   //!
   TBranch        *b_Ndata_bb_gem_hit_uTScorr_MaxStripV;   //!
   TBranch        *b_bb_gem_hit_uTScorr_MaxStripV;   //!
   TBranch        *b_Ndata_bb_gem_hit_uTScorr_Uclust;   //!
   TBranch        *b_bb_gem_hit_uTScorr_Uclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_uTScorr_Vclust;   //!
   TBranch        *b_bb_gem_hit_uTScorr_Vclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_umoment;   //!
   TBranch        *b_bb_gem_hit_umoment;   //!
   TBranch        *b_Ndata_bb_gem_hit_usigma;   //!
   TBranch        *b_bb_gem_hit_usigma;   //!
   TBranch        *b_Ndata_bb_gem_hit_ustriphi;   //!
   TBranch        *b_bb_gem_hit_ustriphi;   //!
   TBranch        *b_Ndata_bb_gem_hit_ustriplo;   //!
   TBranch        *b_bb_gem_hit_ustriplo;   //!
   TBranch        *b_Ndata_bb_gem_hit_ustripmax;   //!
   TBranch        *b_bb_gem_hit_ustripmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_v;   //!
   TBranch        *b_bb_gem_hit_v;   //!
   TBranch        *b_Ndata_bb_gem_hit_vmoment;   //!
   TBranch        *b_bb_gem_hit_vmoment;   //!
   TBranch        *b_Ndata_bb_gem_hit_vsigma;   //!
   TBranch        *b_bb_gem_hit_vsigma;   //!
   TBranch        *b_Ndata_bb_gem_hit_vstriphi;   //!
   TBranch        *b_bb_gem_hit_vstriphi;   //!
   TBranch        *b_Ndata_bb_gem_hit_vstriplo;   //!
   TBranch        *b_bb_gem_hit_vstriplo;   //!
   TBranch        *b_Ndata_bb_gem_hit_vstripmax;   //!
   TBranch        *b_bb_gem_hit_vstripmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_wTScorr_MaxStripU;   //!
   TBranch        *b_bb_gem_hit_wTScorr_MaxStripU;   //!
   TBranch        *b_Ndata_bb_gem_hit_wTScorr_MaxStripV;   //!
   TBranch        *b_bb_gem_hit_wTScorr_MaxStripV;   //!
   TBranch        *b_Ndata_bb_gem_hit_wTScorr_Uclust;   //!
   TBranch        *b_bb_gem_hit_wTScorr_Uclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_wTScorr_Vclust;   //!
   TBranch        *b_bb_gem_hit_wTScorr_Vclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_xglobal;   //!
   TBranch        *b_bb_gem_hit_xglobal;   //!
   TBranch        *b_Ndata_bb_gem_hit_xlocal;   //!
   TBranch        *b_bb_gem_hit_xlocal;   //!
   TBranch        *b_Ndata_bb_gem_hit_yglobal;   //!
   TBranch        *b_bb_gem_hit_yglobal;   //!
   TBranch        *b_Ndata_bb_gem_hit_ylocal;   //!
   TBranch        *b_bb_gem_hit_ylocal;   //!
   TBranch        *b_Ndata_bb_gem_hit_zglobal;   //!
   TBranch        *b_bb_gem_hit_zglobal;   //!
   TBranch        *b_Ndata_bb_gem_n2Dhit_layer;   //!
   TBranch        *b_bb_gem_n2Dhit_layer;   //!
   TBranch        *b_Ndata_bb_gem_nclustu_layer;   //!
   TBranch        *b_bb_gem_nclustu_layer;   //!
   TBranch        *b_Ndata_bb_gem_nclustv_layer;   //!
   TBranch        *b_bb_gem_nclustv_layer;   //!
   TBranch        *b_Ndata_bb_gem_nstripsu_layer;   //!
   TBranch        *b_bb_gem_nstripsu_layer;   //!
   TBranch        *b_Ndata_bb_gem_nstripsv_layer;   //!
   TBranch        *b_bb_gem_nstripsv_layer;   //!
   TBranch        *b_Ndata_bb_gem_track_chi2ndf;   //!
   TBranch        *b_bb_gem_track_chi2ndf;   //!
   TBranch        *b_Ndata_bb_gem_track_chi2ndf_hitquality;   //!
   TBranch        *b_bb_gem_track_chi2ndf_hitquality;   //!
   TBranch        *b_Ndata_bb_gem_track_ngoodhits;   //!
   TBranch        *b_bb_gem_track_ngoodhits;   //!
   TBranch        *b_Ndata_bb_gem_track_nhits;   //!
   TBranch        *b_bb_gem_track_nhits;   //!
   TBranch        *b_Ndata_bb_gem_track_t0;   //!
   TBranch        *b_bb_gem_track_t0;   //!
   TBranch        *b_Ndata_bb_gem_track_x;   //!
   TBranch        *b_bb_gem_track_x;   //!
   TBranch        *b_Ndata_bb_gem_track_xp;   //!
   TBranch        *b_bb_gem_track_xp;   //!
   TBranch        *b_Ndata_bb_gem_track_y;   //!
   TBranch        *b_bb_gem_track_y;   //!
   TBranch        *b_Ndata_bb_gem_track_yp;   //!
   TBranch        *b_bb_gem_track_yp;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_adc;   //!
   TBranch        *b_bb_grinch_tdc_allclus_adc;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_dx;   //!
   TBranch        *b_bb_grinch_tdc_allclus_dx;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_dy;   //!
   TBranch        *b_bb_grinch_tdc_allclus_dy;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_mirrorindex;   //!
   TBranch        *b_bb_grinch_tdc_allclus_mirrorindex;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_size;   //!
   TBranch        *b_bb_grinch_tdc_allclus_size;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_t_mean;   //!
   TBranch        *b_bb_grinch_tdc_allclus_t_mean;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_t_mean_corr;   //!
   TBranch        *b_bb_grinch_tdc_allclus_t_mean_corr;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_t_rms;   //!
   TBranch        *b_bb_grinch_tdc_allclus_t_rms;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_t_rms_corr;   //!
   TBranch        *b_bb_grinch_tdc_allclus_t_rms_corr;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_tot_mean;   //!
   TBranch        *b_bb_grinch_tdc_allclus_tot_mean;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_trackindex;   //!
   TBranch        *b_bb_grinch_tdc_allclus_trackindex;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_x_mean;   //!
   TBranch        *b_bb_grinch_tdc_allclus_x_mean;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_y_mean;   //!
   TBranch        *b_bb_grinch_tdc_allclus_y_mean;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_amp;   //!
   TBranch        *b_bb_grinch_tdc_hit_amp;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_clustindex;   //!
   TBranch        *b_bb_grinch_tdc_hit_clustindex;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_col;   //!
   TBranch        *b_bb_grinch_tdc_hit_col;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_pmtnum;   //!
   TBranch        *b_bb_grinch_tdc_hit_pmtnum;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_row;   //!
   TBranch        *b_bb_grinch_tdc_hit_row;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_time;   //!
   TBranch        *b_bb_grinch_tdc_hit_time;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_time_corr;   //!
   TBranch        *b_bb_grinch_tdc_hit_time_corr;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_trackindex;   //!
   TBranch        *b_bb_grinch_tdc_hit_trackindex;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_xhit;   //!
   TBranch        *b_bb_grinch_tdc_hit_xhit;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_yhit;   //!
   TBranch        *b_bb_grinch_tdc_hit_yhit;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdc;   //!
   TBranch        *b_bb_hodotdc_Ref_tdc;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdc_mult;   //!
   TBranch        *b_bb_hodotdc_Ref_tdc_mult;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdc_te;   //!
   TBranch        *b_bb_hodotdc_Ref_tdc_te;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdc_tot;   //!
   TBranch        *b_bb_hodotdc_Ref_tdc_tot;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdcelemID;   //!
   TBranch        *b_bb_hodotdc_Ref_tdcelemID;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_etof;   //!
   TBranch        *b_bb_hodotdc_allclus_etof;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_iclust;   //!
   TBranch        *b_bb_hodotdc_allclus_iclust;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_id;   //!
   TBranch        *b_bb_hodotdc_allclus_id;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_itrack;   //!
   TBranch        *b_bb_hodotdc_allclus_itrack;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_size;   //!
   TBranch        *b_bb_hodotdc_allclus_size;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_tdiff;   //!
   TBranch        *b_bb_hodotdc_allclus_tdiff;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_tfinal;   //!
   TBranch        *b_bb_hodotdc_allclus_tfinal;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_tleft;   //!
   TBranch        *b_bb_hodotdc_allclus_tleft;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_tmean;   //!
   TBranch        *b_bb_hodotdc_allclus_tmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_tmeanRFcorr;   //!
   TBranch        *b_bb_hodotdc_allclus_tmeanRFcorr;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_totleft;   //!
   TBranch        *b_bb_hodotdc_allclus_totleft;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_totmean;   //!
   TBranch        *b_bb_hodotdc_allclus_totmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_totright;   //!
   TBranch        *b_bb_hodotdc_allclus_totright;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_tright;   //!
   TBranch        *b_bb_hodotdc_allclus_tright;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_xmean;   //!
   TBranch        *b_bb_hodotdc_allclus_xmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_ymean;   //!
   TBranch        *b_bb_hodotdc_allclus_ymean;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_etof;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_etof;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_iclust;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_iclust;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_id;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_id;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_itrack;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_itrack;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_meantime;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_meantime;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_meantot;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_meantot;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_tfinal;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_tfinal;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_timediff;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_timediff;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_timehitpos;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_timehitpos;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_tleft;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_tleft;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_tmeanRFcorr;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_tmeanRFcorr;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_totleft;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_totleft;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_totright;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_totright;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_tright;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_tright;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_vpos;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_vpos;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_etof;   //!
   TBranch        *b_bb_hodotdc_clus_etof;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_id;   //!
   TBranch        *b_bb_hodotdc_clus_id;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_size;   //!
   TBranch        *b_bb_hodotdc_clus_size;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_tdiff;   //!
   TBranch        *b_bb_hodotdc_clus_tdiff;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_tfinal;   //!
   TBranch        *b_bb_hodotdc_clus_tfinal;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_tleft;   //!
   TBranch        *b_bb_hodotdc_clus_tleft;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_tmean;   //!
   TBranch        *b_bb_hodotdc_clus_tmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_tmeanRFcorr;   //!
   TBranch        *b_bb_hodotdc_clus_tmeanRFcorr;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_totleft;   //!
   TBranch        *b_bb_hodotdc_clus_totleft;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_totmean;   //!
   TBranch        *b_bb_hodotdc_clus_totmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_totright;   //!
   TBranch        *b_bb_hodotdc_clus_totright;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_trackindex;   //!
   TBranch        *b_bb_hodotdc_clus_trackindex;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_tright;   //!
   TBranch        *b_bb_hodotdc_clus_tright;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_xmean;   //!
   TBranch        *b_bb_hodotdc_clus_xmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_ymean;   //!
   TBranch        *b_bb_hodotdc_clus_ymean;   //!
   TBranch        *b_Ndata_bb_ps_clus_adctime;   //!
   TBranch        *b_bb_ps_clus_adctime;   //!
   TBranch        *b_Ndata_bb_ps_clus_again;   //!
   TBranch        *b_bb_ps_clus_again;   //!
   TBranch        *b_Ndata_bb_ps_clus_atimeblk;   //!
   TBranch        *b_bb_ps_clus_atimeblk;   //!
   TBranch        *b_Ndata_bb_ps_clus_col;   //!
   TBranch        *b_bb_ps_clus_col;   //!
   TBranch        *b_Ndata_bb_ps_clus_col_goodtdc;   //!
   TBranch        *b_bb_ps_clus_col_goodtdc;   //!
   TBranch        *b_Ndata_bb_ps_clus_e;   //!
   TBranch        *b_bb_ps_clus_e;   //!
   TBranch        *b_Ndata_bb_ps_clus_e_goodtdc;   //!
   TBranch        *b_bb_ps_clus_e_goodtdc;   //!
   TBranch        *b_Ndata_bb_ps_clus_eblk;   //!
   TBranch        *b_bb_ps_clus_eblk;   //!
   TBranch        *b_Ndata_bb_ps_clus_eblk_goodtdc;   //!
   TBranch        *b_bb_ps_clus_eblk_goodtdc;   //!
   TBranch        *b_Ndata_bb_ps_clus_id;   //!
   TBranch        *b_bb_ps_clus_id;   //!
   TBranch        *b_Ndata_bb_ps_clus_id_goodtdc;   //!
   TBranch        *b_bb_ps_clus_id_goodtdc;   //!
   TBranch        *b_Ndata_bb_ps_clus_nblk;   //!
   TBranch        *b_bb_ps_clus_nblk;   //!
   TBranch        *b_Ndata_bb_ps_clus_nblk_goodtdc;   //!
   TBranch        *b_bb_ps_clus_nblk_goodtdc;   //!
   TBranch        *b_Ndata_bb_ps_clus_row;   //!
   TBranch        *b_bb_ps_clus_row;   //!
   TBranch        *b_Ndata_bb_ps_clus_row_goodtdc;   //!
   TBranch        *b_bb_ps_clus_row_goodtdc;   //!
   TBranch        *b_Ndata_bb_ps_clus_tdctime;   //!
   TBranch        *b_bb_ps_clus_tdctime;   //!
   TBranch        *b_Ndata_bb_ps_clus_tdctime_tw;   //!
   TBranch        *b_bb_ps_clus_tdctime_tw;   //!
   TBranch        *b_Ndata_bb_ps_clus_tdctimeblk;   //!
   TBranch        *b_bb_ps_clus_tdctimeblk;   //!
   TBranch        *b_Ndata_bb_ps_clus_tdctimeblk_tw;   //!
   TBranch        *b_bb_ps_clus_tdctimeblk_tw;   //!
   TBranch        *b_Ndata_bb_ps_clus_x;   //!
   TBranch        *b_bb_ps_clus_x;   //!
   TBranch        *b_Ndata_bb_ps_clus_y;   //!
   TBranch        *b_bb_ps_clus_y;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_again;   //!
   TBranch        *b_bb_ps_clus_blk_again;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_atime;   //!
   TBranch        *b_bb_ps_clus_blk_atime;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_col;   //!
   TBranch        *b_bb_ps_clus_blk_col;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_e;   //!
   TBranch        *b_bb_ps_clus_blk_e;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_id;   //!
   TBranch        *b_bb_ps_clus_blk_id;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_row;   //!
   TBranch        *b_bb_ps_clus_blk_row;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_tdctime;   //!
   TBranch        *b_bb_ps_clus_blk_tdctime;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_tdctime_tw;   //!
   TBranch        *b_bb_ps_clus_blk_tdctime_tw;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_x;   //!
   TBranch        *b_bb_ps_clus_blk_x;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_y;   //!
   TBranch        *b_bb_ps_clus_blk_y;   //!
   TBranch        *b_Ndata_bb_sh_clus_adctime;   //!
   TBranch        *b_bb_sh_clus_adctime;   //!
   TBranch        *b_Ndata_bb_sh_clus_again;   //!
   TBranch        *b_bb_sh_clus_again;   //!
   TBranch        *b_Ndata_bb_sh_clus_atimeblk;   //!
   TBranch        *b_bb_sh_clus_atimeblk;   //!
   TBranch        *b_Ndata_bb_sh_clus_col;   //!
   TBranch        *b_bb_sh_clus_col;   //!
   TBranch        *b_Ndata_bb_sh_clus_col_goodtdc;   //!
   TBranch        *b_bb_sh_clus_col_goodtdc;   //!
   TBranch        *b_Ndata_bb_sh_clus_e;   //!
   TBranch        *b_bb_sh_clus_e;   //!
   TBranch        *b_Ndata_bb_sh_clus_e_goodtdc;   //!
   TBranch        *b_bb_sh_clus_e_goodtdc;   //!
   TBranch        *b_Ndata_bb_sh_clus_eblk;   //!
   TBranch        *b_bb_sh_clus_eblk;   //!
   TBranch        *b_Ndata_bb_sh_clus_eblk_goodtdc;   //!
   TBranch        *b_bb_sh_clus_eblk_goodtdc;   //!
   TBranch        *b_Ndata_bb_sh_clus_id;   //!
   TBranch        *b_bb_sh_clus_id;   //!
   TBranch        *b_Ndata_bb_sh_clus_id_goodtdc;   //!
   TBranch        *b_bb_sh_clus_id_goodtdc;   //!
   TBranch        *b_Ndata_bb_sh_clus_nblk;   //!
   TBranch        *b_bb_sh_clus_nblk;   //!
   TBranch        *b_Ndata_bb_sh_clus_nblk_goodtdc;   //!
   TBranch        *b_bb_sh_clus_nblk_goodtdc;   //!
   TBranch        *b_Ndata_bb_sh_clus_row;   //!
   TBranch        *b_bb_sh_clus_row;   //!
   TBranch        *b_Ndata_bb_sh_clus_row_goodtdc;   //!
   TBranch        *b_bb_sh_clus_row_goodtdc;   //!
   TBranch        *b_Ndata_bb_sh_clus_tdctime;   //!
   TBranch        *b_bb_sh_clus_tdctime;   //!
   TBranch        *b_Ndata_bb_sh_clus_tdctime_tw;   //!
   TBranch        *b_bb_sh_clus_tdctime_tw;   //!
   TBranch        *b_Ndata_bb_sh_clus_tdctimeblk;   //!
   TBranch        *b_bb_sh_clus_tdctimeblk;   //!
   TBranch        *b_Ndata_bb_sh_clus_tdctimeblk_tw;   //!
   TBranch        *b_bb_sh_clus_tdctimeblk_tw;   //!
   TBranch        *b_Ndata_bb_sh_clus_x;   //!
   TBranch        *b_bb_sh_clus_x;   //!
   TBranch        *b_Ndata_bb_sh_clus_y;   //!
   TBranch        *b_bb_sh_clus_y;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_again;   //!
   TBranch        *b_bb_sh_clus_blk_again;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_atime;   //!
   TBranch        *b_bb_sh_clus_blk_atime;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_col;   //!
   TBranch        *b_bb_sh_clus_blk_col;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_e;   //!
   TBranch        *b_bb_sh_clus_blk_e;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_id;   //!
   TBranch        *b_bb_sh_clus_blk_id;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_row;   //!
   TBranch        *b_bb_sh_clus_blk_row;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_tdctime;   //!
   TBranch        *b_bb_sh_clus_blk_tdctime;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_tdctime_tw;   //!
   TBranch        *b_bb_sh_clus_blk_tdctime_tw;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_x;   //!
   TBranch        *b_bb_sh_clus_blk_x;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_y;   //!
   TBranch        *b_bb_sh_clus_blk_y;   //!
   TBranch        *b_Ndata_bb_tdctrig_tdc;   //!
   TBranch        *b_bb_tdctrig_tdc;   //!
   TBranch        *b_Ndata_bb_tdctrig_tdcelemID;   //!
   TBranch        *b_bb_tdctrig_tdcelemID;   //!
   TBranch        *b_Ndata_bb_tr_beta;   //!
   TBranch        *b_bb_tr_beta;   //!
   TBranch        *b_Ndata_bb_tr_chi2;   //!
   TBranch        *b_bb_tr_chi2;   //!
   TBranch        *b_Ndata_bb_tr_d_ph;   //!
   TBranch        *b_bb_tr_d_ph;   //!
   TBranch        *b_Ndata_bb_tr_d_th;   //!
   TBranch        *b_bb_tr_d_th;   //!
   TBranch        *b_Ndata_bb_tr_d_x;   //!
   TBranch        *b_bb_tr_d_x;   //!
   TBranch        *b_Ndata_bb_tr_d_y;   //!
   TBranch        *b_bb_tr_d_y;   //!
   TBranch        *b_Ndata_bb_tr_dbeta;   //!
   TBranch        *b_bb_tr_dbeta;   //!
   TBranch        *b_Ndata_bb_tr_dtime;   //!
   TBranch        *b_bb_tr_dtime;   //!
   TBranch        *b_Ndata_bb_tr_flag;   //!
   TBranch        *b_bb_tr_flag;   //!
   TBranch        *b_Ndata_bb_tr_ndof;   //!
   TBranch        *b_bb_tr_ndof;   //!
   TBranch        *b_Ndata_bb_tr_p;   //!
   TBranch        *b_bb_tr_p;   //!
   TBranch        *b_Ndata_bb_tr_pathl;   //!
   TBranch        *b_bb_tr_pathl;   //!
   TBranch        *b_Ndata_bb_tr_ph;   //!
   TBranch        *b_bb_tr_ph;   //!
   TBranch        *b_Ndata_bb_tr_px;   //!
   TBranch        *b_bb_tr_px;   //!
   TBranch        *b_Ndata_bb_tr_py;   //!
   TBranch        *b_bb_tr_py;   //!
   TBranch        *b_Ndata_bb_tr_pz;   //!
   TBranch        *b_bb_tr_pz;   //!
   TBranch        *b_Ndata_bb_tr_r_ph;   //!
   TBranch        *b_bb_tr_r_ph;   //!
   TBranch        *b_Ndata_bb_tr_r_th;   //!
   TBranch        *b_bb_tr_r_th;   //!
   TBranch        *b_Ndata_bb_tr_r_x;   //!
   TBranch        *b_bb_tr_r_x;   //!
   TBranch        *b_Ndata_bb_tr_r_y;   //!
   TBranch        *b_bb_tr_r_y;   //!
   TBranch        *b_Ndata_bb_tr_tg_dp;   //!
   TBranch        *b_bb_tr_tg_dp;   //!
   TBranch        *b_Ndata_bb_tr_tg_ph;   //!
   TBranch        *b_bb_tr_tg_ph;   //!
   TBranch        *b_Ndata_bb_tr_tg_th;   //!
   TBranch        *b_bb_tr_tg_th;   //!
   TBranch        *b_Ndata_bb_tr_tg_x;   //!
   TBranch        *b_bb_tr_tg_x;   //!
   TBranch        *b_Ndata_bb_tr_tg_y;   //!
   TBranch        *b_bb_tr_tg_y;   //!
   TBranch        *b_Ndata_bb_tr_th;   //!
   TBranch        *b_bb_tr_th;   //!
   TBranch        *b_Ndata_bb_tr_time;   //!
   TBranch        *b_bb_tr_time;   //!
   TBranch        *b_Ndata_bb_tr_vx;   //!
   TBranch        *b_bb_tr_vx;   //!
   TBranch        *b_Ndata_bb_tr_vy;   //!
   TBranch        *b_bb_tr_vy;   //!
   TBranch        *b_Ndata_bb_tr_vz;   //!
   TBranch        *b_bb_tr_vz;   //!
   TBranch        *b_Ndata_bb_tr_x;   //!
   TBranch        *b_bb_tr_x;   //!
   TBranch        *b_Ndata_bb_tr_y;   //!
   TBranch        *b_bb_tr_y;   //!
   TBranch        *b_Ndata_bb_x_bcp;   //!
   TBranch        *b_bb_x_bcp;   //!
   TBranch        *b_Ndata_bb_x_fcp;   //!
   TBranch        *b_bb_x_fcp;   //!
   TBranch        *b_Ndata_bb_y_bcp;   //!
   TBranch        *b_bb_y_bcp;   //!
   TBranch        *b_Ndata_bb_y_fcp;   //!
   TBranch        *b_bb_y_fcp;   //!
   TBranch        *b_Ndata_bb_z_bcp;   //!
   TBranch        *b_bb_z_bcp;   //!
   TBranch        *b_Ndata_bb_z_fcp;   //!
   TBranch        *b_bb_z_fcp;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCU;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCU;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCU_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCU_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCV;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCV;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCV_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCV_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCasym;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCasym;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCasym_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCasym_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCavg;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCavg;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCavg_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCavg_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac0_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac0_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac0_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac0_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac1_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac1_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac1_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac1_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac2_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac2_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac2_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac2_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac3_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac3_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac3_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac3_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac4_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac4_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac4_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac4_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac5_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac5_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCfrac5_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCfrac5_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxcomboUclust_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxcomboUclust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxcomboVclust_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxcomboVclust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxsampU;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxsampU;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxsampUclust;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxsampUclust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxsampUclust_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxsampUclust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxsampV;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxsampV;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxsampVclust;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxsampVclust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxsampVclust_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxsampVclust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxstripU;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxstripU;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ADCmaxstripV;   //!
   TBranch        *b_sbs_gemCeF_hit_ADCmaxstripV;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_U;   //!
   TBranch        *b_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_U;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_V;   //!
   TBranch        *b_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_V;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_CM_GOOD_U;   //!
   TBranch        *b_sbs_gemCeF_hit_CM_GOOD_U;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_CM_GOOD_V;   //!
   TBranch        *b_sbs_gemCeF_hit_CM_GOOD_V;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC0_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC0_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC0_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC0_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC1_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC1_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC1_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC1_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC2_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC2_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC2_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC2_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC3_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC3_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC3_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC3_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC4_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC4_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC4_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC4_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC5_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC5_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADC5_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADC5_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADCmaxcomboU;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADCmaxcomboU;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADCmaxcomboV;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADCmaxcomboV;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADCmaxsampU;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADCmaxsampU;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADCmaxsampV;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADCmaxsampV;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADCmaxstripU;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADCmaxstripU;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_DeconvADCmaxstripV;   //!
   TBranch        *b_sbs_gemCeF_hit_DeconvADCmaxstripV;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ENABLE_CM_U;   //!
   TBranch        *b_sbs_gemCeF_hit_ENABLE_CM_U;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ENABLE_CM_V;   //!
   TBranch        *b_sbs_gemCeF_hit_ENABLE_CM_V;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_TSchi2_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_TSchi2_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_TSchi2_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_TSchi2_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_TSprob_Umax;   //!
   TBranch        *b_sbs_gemCeF_hit_TSprob_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_TSprob_Vmax;   //!
   TBranch        *b_sbs_gemCeF_hit_TSprob_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_Tavg;   //!
   TBranch        *b_sbs_gemCeF_hit_Tavg;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_Tavg_corr;   //!
   TBranch        *b_sbs_gemCeF_hit_Tavg_corr;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_Tavg_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_Tavg_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_Tavg_fit;   //!
   TBranch        *b_sbs_gemCeF_hit_Tavg_fit;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_Ugain;   //!
   TBranch        *b_sbs_gemCeF_hit_Ugain;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_Utime;   //!
   TBranch        *b_sbs_gemCeF_hit_Utime;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_UtimeDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_UtimeDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_UtimeFit;   //!
   TBranch        *b_sbs_gemCeF_hit_UtimeFit;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_UtimeMaxStrip;   //!
   TBranch        *b_sbs_gemCeF_hit_UtimeMaxStrip;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_UtimeMaxStripDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_UtimeMaxStripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_UtimeMaxStripFit;   //!
   TBranch        *b_sbs_gemCeF_hit_UtimeMaxStripFit;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_Vgain;   //!
   TBranch        *b_sbs_gemCeF_hit_Vgain;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_Vtime;   //!
   TBranch        *b_sbs_gemCeF_hit_Vtime;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_VtimeDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_VtimeDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_VtimeFit;   //!
   TBranch        *b_sbs_gemCeF_hit_VtimeFit;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_VtimeMaxStrip;   //!
   TBranch        *b_sbs_gemCeF_hit_VtimeMaxStrip;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_VtimeMaxStripDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_VtimeMaxStripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_VtimeMaxStripFit;   //!
   TBranch        *b_sbs_gemCeF_hit_VtimeMaxStripFit;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_adc_id_U;   //!
   TBranch        *b_sbs_gemCeF_hit_adc_id_U;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_adc_id_V;   //!
   TBranch        *b_sbs_gemCeF_hit_adc_id_V;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ccor_clust;   //!
   TBranch        *b_sbs_gemCeF_hit_ccor_clust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ccor_clust_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ccor_clust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ccor_strip;   //!
   TBranch        *b_sbs_gemCeF_hit_ccor_strip;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ccor_strip_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_ccor_strip_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_crate_U;   //!
   TBranch        *b_sbs_gemCeF_hit_crate_U;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_crate_V;   //!
   TBranch        *b_sbs_gemCeF_hit_crate_V;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_deltat;   //!
   TBranch        *b_sbs_gemCeF_hit_deltat;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_deltat_deconv;   //!
   TBranch        *b_sbs_gemCeF_hit_deltat_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_deltat_fit;   //!
   TBranch        *b_sbs_gemCeF_hit_deltat_fit;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_eresidu;   //!
   TBranch        *b_sbs_gemCeF_hit_eresidu;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_eresidv;   //!
   TBranch        *b_sbs_gemCeF_hit_eresidv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_icombomaxUclustDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_icombomaxUclustDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_icombomaxUstripDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_icombomaxUstripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_icombomaxVclustDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_icombomaxVclustDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_icombomaxVstripDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_icombomaxVstripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_isampmaxUclust;   //!
   TBranch        *b_sbs_gemCeF_hit_isampmaxUclust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_isampmaxUclustDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_isampmaxUclustDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_isampmaxUstrip;   //!
   TBranch        *b_sbs_gemCeF_hit_isampmaxUstrip;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_isampmaxUstripDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_isampmaxUstripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_isampmaxVclust;   //!
   TBranch        *b_sbs_gemCeF_hit_isampmaxVclust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_isampmaxVclustDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_isampmaxVclustDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_isampmaxVstrip;   //!
   TBranch        *b_sbs_gemCeF_hit_isampmaxVstrip;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_isampmaxVstripDeconv;   //!
   TBranch        *b_sbs_gemCeF_hit_isampmaxVstripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_layer;   //!
   TBranch        *b_sbs_gemCeF_hit_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_module;   //!
   TBranch        *b_sbs_gemCeF_hit_module;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_mpd_U;   //!
   TBranch        *b_sbs_gemCeF_hit_mpd_U;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_mpd_V;   //!
   TBranch        *b_sbs_gemCeF_hit_mpd_V;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_nstripu;   //!
   TBranch        *b_sbs_gemCeF_hit_nstripu;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_nstripv;   //!
   TBranch        *b_sbs_gemCeF_hit_nstripv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_residu;   //!
   TBranch        *b_sbs_gemCeF_hit_residu;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_residv;   //!
   TBranch        *b_sbs_gemCeF_hit_residv;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_trackindex;   //!
   TBranch        *b_sbs_gemCeF_hit_trackindex;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_u;   //!
   TBranch        *b_sbs_gemCeF_hit_u;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_uTScorr_MaxStripU;   //!
   TBranch        *b_sbs_gemCeF_hit_uTScorr_MaxStripU;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_uTScorr_MaxStripV;   //!
   TBranch        *b_sbs_gemCeF_hit_uTScorr_MaxStripV;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_uTScorr_Uclust;   //!
   TBranch        *b_sbs_gemCeF_hit_uTScorr_Uclust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_uTScorr_Vclust;   //!
   TBranch        *b_sbs_gemCeF_hit_uTScorr_Vclust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_umoment;   //!
   TBranch        *b_sbs_gemCeF_hit_umoment;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_usigma;   //!
   TBranch        *b_sbs_gemCeF_hit_usigma;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ustriphi;   //!
   TBranch        *b_sbs_gemCeF_hit_ustriphi;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ustriplo;   //!
   TBranch        *b_sbs_gemCeF_hit_ustriplo;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ustripmax;   //!
   TBranch        *b_sbs_gemCeF_hit_ustripmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_v;   //!
   TBranch        *b_sbs_gemCeF_hit_v;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_vmoment;   //!
   TBranch        *b_sbs_gemCeF_hit_vmoment;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_vsigma;   //!
   TBranch        *b_sbs_gemCeF_hit_vsigma;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_vstriphi;   //!
   TBranch        *b_sbs_gemCeF_hit_vstriphi;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_vstriplo;   //!
   TBranch        *b_sbs_gemCeF_hit_vstriplo;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_vstripmax;   //!
   TBranch        *b_sbs_gemCeF_hit_vstripmax;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_wTScorr_MaxStripU;   //!
   TBranch        *b_sbs_gemCeF_hit_wTScorr_MaxStripU;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_wTScorr_MaxStripV;   //!
   TBranch        *b_sbs_gemCeF_hit_wTScorr_MaxStripV;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_wTScorr_Uclust;   //!
   TBranch        *b_sbs_gemCeF_hit_wTScorr_Uclust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_wTScorr_Vclust;   //!
   TBranch        *b_sbs_gemCeF_hit_wTScorr_Vclust;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_xglobal;   //!
   TBranch        *b_sbs_gemCeF_hit_xglobal;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_xlocal;   //!
   TBranch        *b_sbs_gemCeF_hit_xlocal;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_yglobal;   //!
   TBranch        *b_sbs_gemCeF_hit_yglobal;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_ylocal;   //!
   TBranch        *b_sbs_gemCeF_hit_ylocal;   //!
   TBranch        *b_Ndata_sbs_gemCeF_hit_zglobal;   //!
   TBranch        *b_sbs_gemCeF_hit_zglobal;   //!
   TBranch        *b_Ndata_sbs_gemCeF_n2Dhit_layer;   //!
   TBranch        *b_sbs_gemCeF_n2Dhit_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeF_nclustu_layer;   //!
   TBranch        *b_sbs_gemCeF_nclustu_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeF_nclustv_layer;   //!
   TBranch        *b_sbs_gemCeF_nclustv_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeF_nstripsu_layer;   //!
   TBranch        *b_sbs_gemCeF_nstripsu_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeF_nstripsv_layer;   //!
   TBranch        *b_sbs_gemCeF_nstripsv_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_chi2ndf;   //!
   TBranch        *b_sbs_gemCeF_track_chi2ndf;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_chi2ndf_hitquality;   //!
   TBranch        *b_sbs_gemCeF_track_chi2ndf_hitquality;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_ngoodhits;   //!
   TBranch        *b_sbs_gemCeF_track_ngoodhits;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_nhits;   //!
   TBranch        *b_sbs_gemCeF_track_nhits;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_t0;   //!
   TBranch        *b_sbs_gemCeF_track_t0;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_x;   //!
   TBranch        *b_sbs_gemCeF_track_x;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_xp;   //!
   TBranch        *b_sbs_gemCeF_track_xp;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_y;   //!
   TBranch        *b_sbs_gemCeF_track_y;   //!
   TBranch        *b_Ndata_sbs_gemCeF_track_yp;   //!
   TBranch        *b_sbs_gemCeF_track_yp;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCU;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCU;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCU_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCU_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCV;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCV;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCV_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCV_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCasym;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCasym;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCasym_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCasym_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCavg;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCavg;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCavg_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCavg_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac0_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac0_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac0_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac0_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac1_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac1_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac1_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac1_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac2_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac2_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac2_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac2_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac3_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac3_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac3_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac3_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac4_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac4_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac4_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac4_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac5_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac5_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCfrac5_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCfrac5_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxcomboUclust_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxcomboUclust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxcomboVclust_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxcomboVclust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxsampU;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxsampU;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxsampUclust;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxsampUclust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxsampUclust_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxsampUclust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxsampV;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxsampV;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxsampVclust;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxsampVclust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxsampVclust_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxsampVclust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxstripU;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxstripU;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ADCmaxstripV;   //!
   TBranch        *b_sbs_gemCeR_hit_ADCmaxstripV;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_U;   //!
   TBranch        *b_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_U;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_V;   //!
   TBranch        *b_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_V;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_CM_GOOD_U;   //!
   TBranch        *b_sbs_gemCeR_hit_CM_GOOD_U;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_CM_GOOD_V;   //!
   TBranch        *b_sbs_gemCeR_hit_CM_GOOD_V;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC0_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC0_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC0_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC0_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC1_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC1_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC1_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC1_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC2_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC2_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC2_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC2_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC3_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC3_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC3_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC3_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC4_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC4_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC4_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC4_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC5_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC5_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADC5_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADC5_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADCmaxcomboU;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADCmaxcomboU;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADCmaxcomboV;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADCmaxcomboV;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADCmaxsampU;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADCmaxsampU;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADCmaxsampV;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADCmaxsampV;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADCmaxstripU;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADCmaxstripU;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_DeconvADCmaxstripV;   //!
   TBranch        *b_sbs_gemCeR_hit_DeconvADCmaxstripV;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ENABLE_CM_U;   //!
   TBranch        *b_sbs_gemCeR_hit_ENABLE_CM_U;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ENABLE_CM_V;   //!
   TBranch        *b_sbs_gemCeR_hit_ENABLE_CM_V;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_TSchi2_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_TSchi2_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_TSchi2_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_TSchi2_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_TSprob_Umax;   //!
   TBranch        *b_sbs_gemCeR_hit_TSprob_Umax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_TSprob_Vmax;   //!
   TBranch        *b_sbs_gemCeR_hit_TSprob_Vmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_Tavg;   //!
   TBranch        *b_sbs_gemCeR_hit_Tavg;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_Tavg_corr;   //!
   TBranch        *b_sbs_gemCeR_hit_Tavg_corr;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_Tavg_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_Tavg_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_Tavg_fit;   //!
   TBranch        *b_sbs_gemCeR_hit_Tavg_fit;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_Ugain;   //!
   TBranch        *b_sbs_gemCeR_hit_Ugain;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_Utime;   //!
   TBranch        *b_sbs_gemCeR_hit_Utime;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_UtimeDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_UtimeDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_UtimeFit;   //!
   TBranch        *b_sbs_gemCeR_hit_UtimeFit;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_UtimeMaxStrip;   //!
   TBranch        *b_sbs_gemCeR_hit_UtimeMaxStrip;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_UtimeMaxStripDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_UtimeMaxStripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_UtimeMaxStripFit;   //!
   TBranch        *b_sbs_gemCeR_hit_UtimeMaxStripFit;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_Vgain;   //!
   TBranch        *b_sbs_gemCeR_hit_Vgain;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_Vtime;   //!
   TBranch        *b_sbs_gemCeR_hit_Vtime;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_VtimeDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_VtimeDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_VtimeFit;   //!
   TBranch        *b_sbs_gemCeR_hit_VtimeFit;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_VtimeMaxStrip;   //!
   TBranch        *b_sbs_gemCeR_hit_VtimeMaxStrip;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_VtimeMaxStripDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_VtimeMaxStripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_VtimeMaxStripFit;   //!
   TBranch        *b_sbs_gemCeR_hit_VtimeMaxStripFit;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_adc_id_U;   //!
   TBranch        *b_sbs_gemCeR_hit_adc_id_U;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_adc_id_V;   //!
   TBranch        *b_sbs_gemCeR_hit_adc_id_V;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ccor_clust;   //!
   TBranch        *b_sbs_gemCeR_hit_ccor_clust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ccor_clust_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ccor_clust_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ccor_strip;   //!
   TBranch        *b_sbs_gemCeR_hit_ccor_strip;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ccor_strip_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_ccor_strip_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_crate_U;   //!
   TBranch        *b_sbs_gemCeR_hit_crate_U;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_crate_V;   //!
   TBranch        *b_sbs_gemCeR_hit_crate_V;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_deltat;   //!
   TBranch        *b_sbs_gemCeR_hit_deltat;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_deltat_deconv;   //!
   TBranch        *b_sbs_gemCeR_hit_deltat_deconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_deltat_fit;   //!
   TBranch        *b_sbs_gemCeR_hit_deltat_fit;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_eresidu;   //!
   TBranch        *b_sbs_gemCeR_hit_eresidu;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_eresidv;   //!
   TBranch        *b_sbs_gemCeR_hit_eresidv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_icombomaxUclustDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_icombomaxUclustDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_icombomaxUstripDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_icombomaxUstripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_icombomaxVclustDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_icombomaxVclustDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_icombomaxVstripDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_icombomaxVstripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_isampmaxUclust;   //!
   TBranch        *b_sbs_gemCeR_hit_isampmaxUclust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_isampmaxUclustDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_isampmaxUclustDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_isampmaxUstrip;   //!
   TBranch        *b_sbs_gemCeR_hit_isampmaxUstrip;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_isampmaxUstripDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_isampmaxUstripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_isampmaxVclust;   //!
   TBranch        *b_sbs_gemCeR_hit_isampmaxVclust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_isampmaxVclustDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_isampmaxVclustDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_isampmaxVstrip;   //!
   TBranch        *b_sbs_gemCeR_hit_isampmaxVstrip;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_isampmaxVstripDeconv;   //!
   TBranch        *b_sbs_gemCeR_hit_isampmaxVstripDeconv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_layer;   //!
   TBranch        *b_sbs_gemCeR_hit_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_module;   //!
   TBranch        *b_sbs_gemCeR_hit_module;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_mpd_U;   //!
   TBranch        *b_sbs_gemCeR_hit_mpd_U;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_mpd_V;   //!
   TBranch        *b_sbs_gemCeR_hit_mpd_V;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_nstripu;   //!
   TBranch        *b_sbs_gemCeR_hit_nstripu;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_nstripv;   //!
   TBranch        *b_sbs_gemCeR_hit_nstripv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_residu;   //!
   TBranch        *b_sbs_gemCeR_hit_residu;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_residv;   //!
   TBranch        *b_sbs_gemCeR_hit_residv;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_trackindex;   //!
   TBranch        *b_sbs_gemCeR_hit_trackindex;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_u;   //!
   TBranch        *b_sbs_gemCeR_hit_u;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_uTScorr_MaxStripU;   //!
   TBranch        *b_sbs_gemCeR_hit_uTScorr_MaxStripU;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_uTScorr_MaxStripV;   //!
   TBranch        *b_sbs_gemCeR_hit_uTScorr_MaxStripV;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_uTScorr_Uclust;   //!
   TBranch        *b_sbs_gemCeR_hit_uTScorr_Uclust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_uTScorr_Vclust;   //!
   TBranch        *b_sbs_gemCeR_hit_uTScorr_Vclust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_umoment;   //!
   TBranch        *b_sbs_gemCeR_hit_umoment;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_usigma;   //!
   TBranch        *b_sbs_gemCeR_hit_usigma;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ustriphi;   //!
   TBranch        *b_sbs_gemCeR_hit_ustriphi;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ustriplo;   //!
   TBranch        *b_sbs_gemCeR_hit_ustriplo;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ustripmax;   //!
   TBranch        *b_sbs_gemCeR_hit_ustripmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_v;   //!
   TBranch        *b_sbs_gemCeR_hit_v;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_vmoment;   //!
   TBranch        *b_sbs_gemCeR_hit_vmoment;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_vsigma;   //!
   TBranch        *b_sbs_gemCeR_hit_vsigma;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_vstriphi;   //!
   TBranch        *b_sbs_gemCeR_hit_vstriphi;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_vstriplo;   //!
   TBranch        *b_sbs_gemCeR_hit_vstriplo;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_vstripmax;   //!
   TBranch        *b_sbs_gemCeR_hit_vstripmax;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_wTScorr_MaxStripU;   //!
   TBranch        *b_sbs_gemCeR_hit_wTScorr_MaxStripU;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_wTScorr_MaxStripV;   //!
   TBranch        *b_sbs_gemCeR_hit_wTScorr_MaxStripV;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_wTScorr_Uclust;   //!
   TBranch        *b_sbs_gemCeR_hit_wTScorr_Uclust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_wTScorr_Vclust;   //!
   TBranch        *b_sbs_gemCeR_hit_wTScorr_Vclust;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_xglobal;   //!
   TBranch        *b_sbs_gemCeR_hit_xglobal;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_xlocal;   //!
   TBranch        *b_sbs_gemCeR_hit_xlocal;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_yglobal;   //!
   TBranch        *b_sbs_gemCeR_hit_yglobal;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_ylocal;   //!
   TBranch        *b_sbs_gemCeR_hit_ylocal;   //!
   TBranch        *b_Ndata_sbs_gemCeR_hit_zglobal;   //!
   TBranch        *b_sbs_gemCeR_hit_zglobal;   //!
   TBranch        *b_Ndata_sbs_gemCeR_n2Dhit_layer;   //!
   TBranch        *b_sbs_gemCeR_n2Dhit_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeR_nclustu_layer;   //!
   TBranch        *b_sbs_gemCeR_nclustu_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeR_nclustv_layer;   //!
   TBranch        *b_sbs_gemCeR_nclustv_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeR_nstripsu_layer;   //!
   TBranch        *b_sbs_gemCeR_nstripsu_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeR_nstripsv_layer;   //!
   TBranch        *b_sbs_gemCeR_nstripsv_layer;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_chi2ndf;   //!
   TBranch        *b_sbs_gemCeR_track_chi2ndf;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_chi2ndf_hitquality;   //!
   TBranch        *b_sbs_gemCeR_track_chi2ndf_hitquality;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_ngoodhits;   //!
   TBranch        *b_sbs_gemCeR_track_ngoodhits;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_nhits;   //!
   TBranch        *b_sbs_gemCeR_track_nhits;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_phi;   //!
   TBranch        *b_sbs_gemCeR_track_phi;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_sclose;   //!
   TBranch        *b_sbs_gemCeR_track_sclose;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_t0;   //!
   TBranch        *b_sbs_gemCeR_track_t0;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_theta;   //!
   TBranch        *b_sbs_gemCeR_track_theta;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_x;   //!
   TBranch        *b_sbs_gemCeR_track_x;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_xp;   //!
   TBranch        *b_sbs_gemCeR_track_xp;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_y;   //!
   TBranch        *b_sbs_gemCeR_track_y;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_yp;   //!
   TBranch        *b_sbs_gemCeR_track_yp;   //!
   TBranch        *b_Ndata_sbs_gemCeR_track_zclose;   //!
   TBranch        *b_sbs_gemCeR_track_zclose;   //!
   TBranch        *b_Ndata_sbs_hcal_Ref_tdc;   //!
   TBranch        *b_sbs_hcal_Ref_tdc;   //!
   TBranch        *b_Ndata_sbs_hcal_Ref_tdc_mult;   //!
   TBranch        *b_sbs_hcal_Ref_tdc_mult;   //!
   TBranch        *b_Ndata_sbs_hcal_Ref_tdcelemID;   //!
   TBranch        *b_sbs_hcal_Ref_tdcelemID;   //!
   TBranch        *b_Ndata_sbs_hcal_a_amp_p;   //!
   TBranch        *b_sbs_hcal_a_amp_p;   //!
   TBranch        *b_Ndata_sbs_hcal_a_c;   //!
   TBranch        *b_sbs_hcal_a_c;   //!
   TBranch        *b_Ndata_sbs_hcal_a_p;   //!
   TBranch        *b_sbs_hcal_a_p;   //!
   TBranch        *b_Ndata_sbs_hcal_a_time;   //!
   TBranch        *b_sbs_hcal_a_time;   //!
   TBranch        *b_Ndata_sbs_hcal_adccol;   //!
   TBranch        *b_sbs_hcal_adccol;   //!
   TBranch        *b_Ndata_sbs_hcal_adcelemID;   //!
   TBranch        *b_sbs_hcal_adcelemID;   //!
   TBranch        *b_Ndata_sbs_hcal_adcrow;   //!
   TBranch        *b_sbs_hcal_adcrow;   //!
   TBranch        *b_Ndata_sbs_hcal_adcxpos;   //!
   TBranch        *b_sbs_hcal_adcxpos;   //!
   TBranch        *b_Ndata_sbs_hcal_adcypos;   //!
   TBranch        *b_sbs_hcal_adcypos;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_adctime;   //!
   TBranch        *b_sbs_hcal_clus_adctime;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_again;   //!
   TBranch        *b_sbs_hcal_clus_again;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_atimeblk;   //!
   TBranch        *b_sbs_hcal_clus_atimeblk;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_col;   //!
   TBranch        *b_sbs_hcal_clus_col;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_col_goodtdc;   //!
   TBranch        *b_sbs_hcal_clus_col_goodtdc;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_e;   //!
   TBranch        *b_sbs_hcal_clus_e;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_e_goodtdc;   //!
   TBranch        *b_sbs_hcal_clus_e_goodtdc;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_eblk;   //!
   TBranch        *b_sbs_hcal_clus_eblk;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_eblk_goodtdc;   //!
   TBranch        *b_sbs_hcal_clus_eblk_goodtdc;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_id;   //!
   TBranch        *b_sbs_hcal_clus_id;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_id_goodtdc;   //!
   TBranch        *b_sbs_hcal_clus_id_goodtdc;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_nblk;   //!
   TBranch        *b_sbs_hcal_clus_nblk;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_nblk_goodtdc;   //!
   TBranch        *b_sbs_hcal_clus_nblk_goodtdc;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_row;   //!
   TBranch        *b_sbs_hcal_clus_row;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_row_goodtdc;   //!
   TBranch        *b_sbs_hcal_clus_row_goodtdc;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_tdctime;   //!
   TBranch        *b_sbs_hcal_clus_tdctime;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_tdctime_tw;   //!
   TBranch        *b_sbs_hcal_clus_tdctime_tw;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_tdctimeblk;   //!
   TBranch        *b_sbs_hcal_clus_tdctimeblk;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_tdctimeblk_tw;   //!
   TBranch        *b_sbs_hcal_clus_tdctimeblk_tw;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_x;   //!
   TBranch        *b_sbs_hcal_clus_x;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_y;   //!
   TBranch        *b_sbs_hcal_clus_y;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_again;   //!
   TBranch        *b_sbs_hcal_clus_blk_again;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_atime;   //!
   TBranch        *b_sbs_hcal_clus_blk_atime;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_col;   //!
   TBranch        *b_sbs_hcal_clus_blk_col;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_e;   //!
   TBranch        *b_sbs_hcal_clus_blk_e;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_id;   //!
   TBranch        *b_sbs_hcal_clus_blk_id;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_row;   //!
   TBranch        *b_sbs_hcal_clus_blk_row;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_tdctime;   //!
   TBranch        *b_sbs_hcal_clus_blk_tdctime;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_tdctime_tw;   //!
   TBranch        *b_sbs_hcal_clus_blk_tdctime_tw;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_x;   //!
   TBranch        *b_sbs_hcal_clus_blk_x;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_y;   //!
   TBranch        *b_sbs_hcal_clus_blk_y;   //!
   TBranch        *b_Ndata_sbs_hcal_ped;   //!
   TBranch        *b_sbs_hcal_ped;   //!
   TBranch        *b_Ndata_sbs_tdctrig_Ref_tdc;   //!
   TBranch        *b_sbs_tdctrig_Ref_tdc;   //!
   TBranch        *b_Ndata_sbs_tdctrig_Ref_tdc_mult;   //!
   TBranch        *b_sbs_tdctrig_Ref_tdc_mult;   //!
   TBranch        *b_Ndata_sbs_tdctrig_Ref_tdcelemID;   //!
   TBranch        *b_sbs_tdctrig_Ref_tdcelemID;   //!
   TBranch        *b_Ndata_sbs_tdctrig_tdc;   //!
   TBranch        *b_sbs_tdctrig_tdc;   //!
   TBranch        *b_Ndata_sbs_tdctrig_tdc_mult;   //!
   TBranch        *b_sbs_tdctrig_tdc_mult;   //!
   TBranch        *b_Ndata_sbs_tdctrig_tdccol;   //!
   TBranch        *b_sbs_tdctrig_tdccol;   //!
   TBranch        *b_Ndata_sbs_tdctrig_tdcelemID;   //!
   TBranch        *b_sbs_tdctrig_tdcelemID;   //!
   TBranch        *b_Ndata_sbs_tdctrig_tdclayer;   //!
   TBranch        *b_sbs_tdctrig_tdclayer;   //!
   TBranch        *b_Ndata_sbs_tdctrig_tdcrow;   //!
   TBranch        *b_sbs_tdctrig_tdcrow;   //!
   TBranch        *b_Ndata_sbs_tr_beta;   //!
   TBranch        *b_sbs_tr_beta;   //!
   TBranch        *b_Ndata_sbs_tr_chi2;   //!
   TBranch        *b_sbs_tr_chi2;   //!
   TBranch        *b_Ndata_sbs_tr_d_ph;   //!
   TBranch        *b_sbs_tr_d_ph;   //!
   TBranch        *b_Ndata_sbs_tr_d_th;   //!
   TBranch        *b_sbs_tr_d_th;   //!
   TBranch        *b_Ndata_sbs_tr_d_x;   //!
   TBranch        *b_sbs_tr_d_x;   //!
   TBranch        *b_Ndata_sbs_tr_d_y;   //!
   TBranch        *b_sbs_tr_d_y;   //!
   TBranch        *b_Ndata_sbs_tr_dbeta;   //!
   TBranch        *b_sbs_tr_dbeta;   //!
   TBranch        *b_Ndata_sbs_tr_dtime;   //!
   TBranch        *b_sbs_tr_dtime;   //!
   TBranch        *b_Ndata_sbs_tr_flag;   //!
   TBranch        *b_sbs_tr_flag;   //!
   TBranch        *b_Ndata_sbs_tr_ndof;   //!
   TBranch        *b_sbs_tr_ndof;   //!
   TBranch        *b_Ndata_sbs_tr_p;   //!
   TBranch        *b_sbs_tr_p;   //!
   TBranch        *b_Ndata_sbs_tr_pathl;   //!
   TBranch        *b_sbs_tr_pathl;   //!
   TBranch        *b_Ndata_sbs_tr_ph;   //!
   TBranch        *b_sbs_tr_ph;   //!
   TBranch        *b_Ndata_sbs_tr_px;   //!
   TBranch        *b_sbs_tr_px;   //!
   TBranch        *b_Ndata_sbs_tr_py;   //!
   TBranch        *b_sbs_tr_py;   //!
   TBranch        *b_Ndata_sbs_tr_pz;   //!
   TBranch        *b_sbs_tr_pz;   //!
   TBranch        *b_Ndata_sbs_tr_r_ph;   //!
   TBranch        *b_sbs_tr_r_ph;   //!
   TBranch        *b_Ndata_sbs_tr_r_th;   //!
   TBranch        *b_sbs_tr_r_th;   //!
   TBranch        *b_Ndata_sbs_tr_r_x;   //!
   TBranch        *b_sbs_tr_r_x;   //!
   TBranch        *b_Ndata_sbs_tr_r_y;   //!
   TBranch        *b_sbs_tr_r_y;   //!
   TBranch        *b_Ndata_sbs_tr_tg_dp;   //!
   TBranch        *b_sbs_tr_tg_dp;   //!
   TBranch        *b_Ndata_sbs_tr_tg_ph;   //!
   TBranch        *b_sbs_tr_tg_ph;   //!
   TBranch        *b_Ndata_sbs_tr_tg_th;   //!
   TBranch        *b_sbs_tr_tg_th;   //!
   TBranch        *b_Ndata_sbs_tr_tg_y;   //!
   TBranch        *b_sbs_tr_tg_y;   //!
   TBranch        *b_Ndata_sbs_tr_th;   //!
   TBranch        *b_sbs_tr_th;   //!
   TBranch        *b_Ndata_sbs_tr_time;   //!
   TBranch        *b_sbs_tr_time;   //!
   TBranch        *b_Ndata_sbs_tr_vx;   //!
   TBranch        *b_sbs_tr_vx;   //!
   TBranch        *b_Ndata_sbs_tr_vy;   //!
   TBranch        *b_sbs_tr_vy;   //!
   TBranch        *b_Ndata_sbs_tr_vz;   //!
   TBranch        *b_sbs_tr_vz;   //!
   TBranch        *b_Ndata_sbs_tr_x;   //!
   TBranch        *b_sbs_tr_x;   //!
   TBranch        *b_Ndata_sbs_tr_y;   //!
   TBranch        *b_sbs_tr_y;   //!
   TBranch        *b_Ndata_sbs_trig_a_amp_p;   //!
   TBranch        *b_sbs_trig_a_amp_p;   //!
   TBranch        *b_Ndata_sbs_trig_a_p;   //!
   TBranch        *b_sbs_trig_a_p;   //!
   TBranch        *b_Ndata_sbs_trig_a_time;   //!
   TBranch        *b_sbs_trig_a_time;   //!
   TBranch        *b_Ndata_sbs_trig_adcelemID;   //!
   TBranch        *b_sbs_trig_adcelemID;   //!
   TBranch        *b_Ndata_sbs_x_bcp;   //!
   TBranch        *b_sbs_x_bcp;   //!
   TBranch        *b_Ndata_sbs_x_bcp_FPP;   //!
   TBranch        *b_sbs_x_bcp_FPP;   //!
   TBranch        *b_Ndata_sbs_x_bcp_FT;   //!
   TBranch        *b_sbs_x_bcp_FT;   //!
   TBranch        *b_Ndata_sbs_x_fcp;   //!
   TBranch        *b_sbs_x_fcp;   //!
   TBranch        *b_Ndata_sbs_x_fcp_FPP;   //!
   TBranch        *b_sbs_x_fcp_FPP;   //!
   TBranch        *b_Ndata_sbs_x_fcp_FT;   //!
   TBranch        *b_sbs_x_fcp_FT;   //!
   TBranch        *b_Ndata_sbs_y_bcp;   //!
   TBranch        *b_sbs_y_bcp;   //!
   TBranch        *b_Ndata_sbs_y_bcp_FPP;   //!
   TBranch        *b_sbs_y_bcp_FPP;   //!
   TBranch        *b_Ndata_sbs_y_bcp_FT;   //!
   TBranch        *b_sbs_y_bcp_FT;   //!
   TBranch        *b_Ndata_sbs_y_fcp;   //!
   TBranch        *b_sbs_y_fcp;   //!
   TBranch        *b_Ndata_sbs_y_fcp_FPP;   //!
   TBranch        *b_sbs_y_fcp_FPP;   //!
   TBranch        *b_Ndata_sbs_y_fcp_FT;   //!
   TBranch        *b_sbs_y_fcp_FT;   //!
   TBranch        *b_Ndata_sbs_z_bcp;   //!
   TBranch        *b_sbs_z_bcp;   //!
   TBranch        *b_Ndata_sbs_z_bcp_FPP;   //!
   TBranch        *b_sbs_z_bcp_FPP;   //!
   TBranch        *b_Ndata_sbs_z_bcp_FT;   //!
   TBranch        *b_sbs_z_bcp_FT;   //!
   TBranch        *b_Ndata_sbs_z_fcp;   //!
   TBranch        *b_sbs_z_fcp;   //!
   TBranch        *b_Ndata_sbs_z_fcp_FPP;   //!
   TBranch        *b_sbs_z_fcp_FPP;   //!
   TBranch        *b_Ndata_sbs_z_fcp_FT;   //!
   TBranch        *b_sbs_z_fcp_FT;   //!
   TBranch        *b_BB_gold_beta;   //!
   TBranch        *b_BB_gold_dp;   //!
   TBranch        *b_BB_gold_index;   //!
   TBranch        *b_BB_gold_ok;   //!
   TBranch        *b_BB_gold_p;   //!
   TBranch        *b_BB_gold_ph;   //!
   TBranch        *b_BB_gold_px;   //!
   TBranch        *b_BB_gold_py;   //!
   TBranch        *b_BB_gold_pz;   //!
   TBranch        *b_BB_gold_th;   //!
   TBranch        *b_BB_gold_x;   //!
   TBranch        *b_BB_gold_y;   //!
   TBranch        *b_Lrb_BPMA_rawcur_1;   //!
   TBranch        *b_Lrb_BPMA_rawcur_2;   //!
   TBranch        *b_Lrb_BPMA_rawcur_3;   //!
   TBranch        *b_Lrb_BPMA_rawcur_4;   //!
   TBranch        *b_Lrb_BPMA_rotpos1;   //!
   TBranch        *b_Lrb_BPMA_rotpos2;   //!
   TBranch        *b_Lrb_BPMA_x;   //!
   TBranch        *b_Lrb_BPMA_y;   //!
   TBranch        *b_Lrb_BPMA_z;   //!
   TBranch        *b_Lrb_BPMB_rawcur_1;   //!
   TBranch        *b_Lrb_BPMB_rawcur_2;   //!
   TBranch        *b_Lrb_BPMB_rawcur_3;   //!
   TBranch        *b_Lrb_BPMB_rawcur_4;   //!
   TBranch        *b_Lrb_BPMB_rotpos1;   //!
   TBranch        *b_Lrb_BPMB_rotpos2;   //!
   TBranch        *b_Lrb_BPMB_x;   //!
   TBranch        *b_Lrb_BPMB_y;   //!
   TBranch        *b_Lrb_BPMB_z;   //!
   TBranch        *b_Lrb_Raster_bpma_x;   //!
   TBranch        *b_Lrb_Raster_bpma_y;   //!
   TBranch        *b_Lrb_Raster_bpma_z;   //!
   TBranch        *b_Lrb_Raster_bpmb_x;   //!
   TBranch        *b_Lrb_Raster_bpmb_y;   //!
   TBranch        *b_Lrb_Raster_bpmb_z;   //!
   TBranch        *b_Lrb_Raster_rawcur_x;   //!
   TBranch        *b_Lrb_Raster_rawcur_y;   //!
   TBranch        *b_Lrb_Raster_rawslope_x;   //!
   TBranch        *b_Lrb_Raster_rawslope_y;   //!
   TBranch        *b_Lrb_Raster_target_dir_x;   //!
   TBranch        *b_Lrb_Raster_target_dir_y;   //!
   TBranch        *b_Lrb_Raster_target_dir_z;   //!
   TBranch        *b_Lrb_Raster_target_x;   //!
   TBranch        *b_Lrb_Raster_target_y;   //!
   TBranch        *b_Lrb_Raster_target_z;   //!
   TBranch        *b_Lrb_Raster2_bpma_x;   //!
   TBranch        *b_Lrb_Raster2_bpma_y;   //!
   TBranch        *b_Lrb_Raster2_bpma_z;   //!
   TBranch        *b_Lrb_Raster2_bpmb_x;   //!
   TBranch        *b_Lrb_Raster2_bpmb_y;   //!
   TBranch        *b_Lrb_Raster2_bpmb_z;   //!
   TBranch        *b_Lrb_Raster2_rawcur_x;   //!
   TBranch        *b_Lrb_Raster2_rawcur_y;   //!
   TBranch        *b_Lrb_Raster2_rawslope_x;   //!
   TBranch        *b_Lrb_Raster2_rawslope_y;   //!
   TBranch        *b_Lrb_Raster2_target_dir_x;   //!
   TBranch        *b_Lrb_Raster2_target_dir_y;   //!
   TBranch        *b_Lrb_Raster2_target_dir_z;   //!
   TBranch        *b_Lrb_Raster2_target_x;   //!
   TBranch        *b_Lrb_Raster2_target_y;   //!
   TBranch        *b_Lrb_Raster2_target_z;   //!
   TBranch        *b_SBS_gold_beta;   //!
   TBranch        *b_SBS_gold_dp;   //!
   TBranch        *b_SBS_gold_index;   //!
   TBranch        *b_SBS_gold_ok;   //!
   TBranch        *b_SBS_gold_p;   //!
   TBranch        *b_SBS_gold_ph;   //!
   TBranch        *b_SBS_gold_px;   //!
   TBranch        *b_SBS_gold_py;   //!
   TBranch        *b_SBS_gold_pz;   //!
   TBranch        *b_SBS_gold_th;   //!
   TBranch        *b_SBS_gold_x;   //!
   TBranch        *b_SBS_gold_y;   //!
   TBranch        *b_SBSrb_BPMA_rawcur_1;   //!
   TBranch        *b_SBSrb_BPMA_rawcur_2;   //!
   TBranch        *b_SBSrb_BPMA_rawcur_3;   //!
   TBranch        *b_SBSrb_BPMA_rawcur_4;   //!
   TBranch        *b_SBSrb_BPMA_rotpos1;   //!
   TBranch        *b_SBSrb_BPMA_rotpos2;   //!
   TBranch        *b_SBSrb_BPMA_x;   //!
   TBranch        *b_SBSrb_BPMA_y;   //!
   TBranch        *b_SBSrb_BPMA_z;   //!
   TBranch        *b_SBSrb_BPMB_rawcur_1;   //!
   TBranch        *b_SBSrb_BPMB_rawcur_2;   //!
   TBranch        *b_SBSrb_BPMB_rawcur_3;   //!
   TBranch        *b_SBSrb_BPMB_rawcur_4;   //!
   TBranch        *b_SBSrb_BPMB_rotpos1;   //!
   TBranch        *b_SBSrb_BPMB_rotpos2;   //!
   TBranch        *b_SBSrb_BPMB_x;   //!
   TBranch        *b_SBSrb_BPMB_y;   //!
   TBranch        *b_SBSrb_BPMB_z;   //!
   TBranch        *b_SBSrb_Raster_bpma_x;   //!
   TBranch        *b_SBSrb_Raster_bpma_y;   //!
   TBranch        *b_SBSrb_Raster_bpma_z;   //!
   TBranch        *b_SBSrb_Raster_bpmb_x;   //!
   TBranch        *b_SBSrb_Raster_bpmb_y;   //!
   TBranch        *b_SBSrb_Raster_bpmb_z;   //!
   TBranch        *b_SBSrb_Raster_rawcur_x;   //!
   TBranch        *b_SBSrb_Raster_rawcur_y;   //!
   TBranch        *b_SBSrb_Raster_rawslope_x;   //!
   TBranch        *b_SBSrb_Raster_rawslope_y;   //!
   TBranch        *b_SBSrb_Raster_target_dir_x;   //!
   TBranch        *b_SBSrb_Raster_target_dir_y;   //!
   TBranch        *b_SBSrb_Raster_target_dir_z;   //!
   TBranch        *b_SBSrb_Raster_target_x;   //!
   TBranch        *b_SBSrb_Raster_target_y;   //!
   TBranch        *b_SBSrb_Raster_target_z;   //!
   TBranch        *b_SBSrb_Raster2_bpma_x;   //!
   TBranch        *b_SBSrb_Raster2_bpma_y;   //!
   TBranch        *b_SBSrb_Raster2_bpma_z;   //!
   TBranch        *b_SBSrb_Raster2_bpmb_x;   //!
   TBranch        *b_SBSrb_Raster2_bpmb_y;   //!
   TBranch        *b_SBSrb_Raster2_bpmb_z;   //!
   TBranch        *b_SBSrb_Raster2_rawcur_x;   //!
   TBranch        *b_SBSrb_Raster2_rawcur_y;   //!
   TBranch        *b_SBSrb_Raster2_rawslope_x;   //!
   TBranch        *b_SBSrb_Raster2_rawslope_y;   //!
   TBranch        *b_SBSrb_Raster2_target_dir_x;   //!
   TBranch        *b_SBSrb_Raster2_target_dir_y;   //!
   TBranch        *b_SBSrb_Raster2_target_dir_z;   //!
   TBranch        *b_SBSrb_Raster2_target_x;   //!
   TBranch        *b_SBSrb_Raster2_target_y;   //!
   TBranch        *b_SBSrb_Raster2_target_z;   //!
   TBranch        *b_bb_gem_hit_ngoodhits;   //!
   TBranch        *b_bb_gem_m0_clust_nclustu;   //!
   TBranch        *b_bb_gem_m0_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m0_clust_nclustv;   //!
   TBranch        *b_bb_gem_m0_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m0_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m1_clust_nclustu;   //!
   TBranch        *b_bb_gem_m1_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m1_clust_nclustv;   //!
   TBranch        *b_bb_gem_m1_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m1_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m2_clust_nclustu;   //!
   TBranch        *b_bb_gem_m2_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m2_clust_nclustv;   //!
   TBranch        *b_bb_gem_m2_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m2_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m3_clust_nclustu;   //!
   TBranch        *b_bb_gem_m3_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m3_clust_nclustv;   //!
   TBranch        *b_bb_gem_m3_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m3_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m4_clust_nclustu;   //!
   TBranch        *b_bb_gem_m4_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m4_clust_nclustv;   //!
   TBranch        *b_bb_gem_m4_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m4_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m5_clust_nclustu;   //!
   TBranch        *b_bb_gem_m5_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m5_clust_nclustv;   //!
   TBranch        *b_bb_gem_m5_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m5_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m6_clust_nclustu;   //!
   TBranch        *b_bb_gem_m6_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m6_clust_nclustv;   //!
   TBranch        *b_bb_gem_m6_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m6_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m7_clust_nclustu;   //!
   TBranch        *b_bb_gem_m7_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m7_clust_nclustv;   //!
   TBranch        *b_bb_gem_m7_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m7_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_nlayershit;   //!
   TBranch        *b_bb_gem_nlayershitu;   //!
   TBranch        *b_bb_gem_nlayershituv;   //!
   TBranch        *b_bb_gem_nlayershitv;   //!
   TBranch        *b_bb_gem_track_besttrack;   //!
   TBranch        *b_bb_gem_track_ntrack;   //!
   TBranch        *b_bb_gem_trigtime;   //!
   TBranch        *b_bb_grinch_tdc_bestcluster;   //!
   TBranch        *b_bb_grinch_tdc_clus_adc;   //!
   TBranch        *b_bb_grinch_tdc_clus_dx;   //!
   TBranch        *b_bb_grinch_tdc_clus_dy;   //!
   TBranch        *b_bb_grinch_tdc_clus_mirrorindex;   //!
   TBranch        *b_bb_grinch_tdc_clus_size;   //!
   TBranch        *b_bb_grinch_tdc_clus_t_mean;   //!
   TBranch        *b_bb_grinch_tdc_clus_t_mean_corr;   //!
   TBranch        *b_bb_grinch_tdc_clus_t_rms;   //!
   TBranch        *b_bb_grinch_tdc_clus_t_rms_corr;   //!
   TBranch        *b_bb_grinch_tdc_clus_tot_mean;   //!
   TBranch        *b_bb_grinch_tdc_clus_trackindex;   //!
   TBranch        *b_bb_grinch_tdc_clus_x_mean;   //!
   TBranch        *b_bb_grinch_tdc_clus_y_mean;   //!
   TBranch        *b_bb_grinch_tdc_nclus;   //!
   TBranch        *b_bb_grinch_tdc_ngoodhits;   //!
   TBranch        *b_bb_grinch_tdc_ntrackmatch;   //!
   TBranch        *b_bb_hodotdc_nclus;   //!
   TBranch        *b_bb_hodotdc_rftime;   //!
   TBranch        *b_bb_hodotdc_trigphase;   //!
   TBranch        *b_bb_hodotdc_trigphasecorr;   //!
   TBranch        *b_bb_hodotdc_trigtime;   //!
   TBranch        *b_bb_ps_againblk;   //!
   TBranch        *b_bb_ps_atimeblk;   //!
   TBranch        *b_bb_ps_colblk;   //!
   TBranch        *b_bb_ps_e;   //!
   TBranch        *b_bb_ps_eblk;   //!
   TBranch        *b_bb_ps_idblk;   //!
   TBranch        *b_bb_ps_index;   //!
   TBranch        *b_bb_ps_nblk;   //!
   TBranch        *b_bb_ps_nclus;   //!
   TBranch        *b_bb_ps_ngoodADChits;   //!
   TBranch        *b_bb_ps_rowblk;   //!
   TBranch        *b_bb_ps_x;   //!
   TBranch        *b_bb_ps_y;   //!
   TBranch        *b_bb_sh_againblk;   //!
   TBranch        *b_bb_sh_atimeblk;   //!
   TBranch        *b_bb_sh_colblk;   //!
   TBranch        *b_bb_sh_e;   //!
   TBranch        *b_bb_sh_eblk;   //!
   TBranch        *b_bb_sh_idblk;   //!
   TBranch        *b_bb_sh_index;   //!
   TBranch        *b_bb_sh_nblk;   //!
   TBranch        *b_bb_sh_nclus;   //!
   TBranch        *b_bb_sh_ngoodADChits;   //!
   TBranch        *b_bb_sh_rowblk;   //!
   TBranch        *b_bb_sh_x;   //!
   TBranch        *b_bb_sh_y;   //!
   TBranch        *b_bb_tdctrig_rftime;   //!
   TBranch        *b_bb_tdctrig_trigtime;   //!
   TBranch        *b_bb_tr_n;   //!
   TBranch        *b_bb_ts_over_threshold;   //!
   TBranch        *b_e_kine_Q2;   //!
   TBranch        *b_e_kine_W2;   //!
   TBranch        *b_e_kine_angle;   //!
   TBranch        *b_e_kine_epsilon;   //!
   TBranch        *b_e_kine_nu;   //!
   TBranch        *b_e_kine_omega;   //!
   TBranch        *b_e_kine_ph_q;   //!
   TBranch        *b_e_kine_q3m;   //!
   TBranch        *b_e_kine_q_x;   //!
   TBranch        *b_e_kine_q_y;   //!
   TBranch        *b_e_kine_q_z;   //!
   TBranch        *b_e_kine_th_q;   //!
   TBranch        *b_e_kine_x_bj;   //!
   TBranch        *b_g_datatype;   //!
   TBranch        *b_g_evlen;   //!
   TBranch        *b_g_evnum;   //!
   TBranch        *b_g_evtime;   //!
   TBranch        *b_g_evtyp;   //!
   TBranch        *b_g_runnum;   //!
   TBranch        *b_g_runtime;   //!
   TBranch        *b_g_runtype;   //!
   TBranch        *b_g_trigbits;   //!
   TBranch        *b_sbs_HCALdir_x;   //!
   TBranch        *b_sbs_HCALdir_y;   //!
   TBranch        *b_sbs_HCALdir_z;   //!
   TBranch        *b_sbs_HCALph_n;   //!
   TBranch        *b_sbs_HCALth_n;   //!
   TBranch        *b_sbs_gemCeF_hit_ngoodhits;   //!
   TBranch        *b_sbs_gemCeF_m0_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m0_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m0_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m0_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m0_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m0_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m0_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m0_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m0_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m0_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m0_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m1_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m1_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m1_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m1_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m1_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m1_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m1_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m1_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m1_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m1_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m1_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m2_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m2_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m2_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m2_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m2_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m2_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m2_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m2_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m2_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m2_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m2_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m3_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m3_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m3_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m3_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m3_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m3_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m3_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m3_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m3_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m3_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m3_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m4_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m4_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m4_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m4_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m4_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m4_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m4_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m4_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m4_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m4_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m4_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m5_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m5_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m5_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m5_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m5_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m5_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m5_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m5_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m5_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m5_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m5_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m6_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m6_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m6_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m6_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m6_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m6_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m6_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m6_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m6_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m6_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m6_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m7_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m7_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m7_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m7_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m7_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m7_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m7_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m7_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m7_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m7_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m7_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m8_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m8_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m8_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m8_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m8_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m8_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m8_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m8_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m8_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m8_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m8_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_m9_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeF_m9_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeF_m9_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeF_m9_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeF_m9_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeF_m9_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeF_m9_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeF_m9_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeF_m9_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeF_m9_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeF_m9_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeF_nlayershit;   //!
   TBranch        *b_sbs_gemCeF_nlayershitu;   //!
   TBranch        *b_sbs_gemCeF_nlayershituv;   //!
   TBranch        *b_sbs_gemCeF_nlayershitv;   //!
   TBranch        *b_sbs_gemCeF_track_besttrack;   //!
   TBranch        *b_sbs_gemCeF_track_ntrack;   //!
   TBranch        *b_sbs_gemCeR_hit_ngoodhits;   //!
   TBranch        *b_sbs_gemCeR_m0_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m0_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m0_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m0_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m0_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m0_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m0_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m0_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m0_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m0_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m0_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m1_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m1_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m1_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m1_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m1_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m1_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m1_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m1_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m1_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m1_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m1_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m10_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m10_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m10_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m10_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m10_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m10_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m10_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m10_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m10_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m10_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m10_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m11_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m11_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m11_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m11_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m11_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m11_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m11_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m11_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m11_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m11_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m11_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m12_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m12_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m12_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m12_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m12_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m12_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m12_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m12_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m12_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m12_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m12_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m13_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m13_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m13_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m13_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m13_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m13_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m13_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m13_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m13_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m13_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m13_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m14_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m14_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m14_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m14_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m14_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m14_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m14_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m14_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m14_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m14_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m14_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m15_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m15_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m15_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m15_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m15_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m15_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m15_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m15_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m15_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m15_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m15_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m2_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m2_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m2_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m2_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m2_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m2_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m2_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m2_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m2_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m2_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m2_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m3_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m3_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m3_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m3_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m3_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m3_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m3_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m3_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m3_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m3_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m3_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m4_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m4_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m4_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m4_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m4_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m4_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m4_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m4_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m4_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m4_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m4_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m5_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m5_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m5_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m5_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m5_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m5_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m5_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m5_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m5_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m5_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m5_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m6_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m6_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m6_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m6_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m6_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m6_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m6_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m6_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m6_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m6_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m6_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m7_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m7_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m7_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m7_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m7_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m7_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m7_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m7_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m7_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m7_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m7_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m8_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m8_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m8_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m8_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m8_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m8_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m8_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m8_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m8_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m8_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m8_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_m9_clust_nclustu;   //!
   TBranch        *b_sbs_gemCeR_m9_clust_nclustu_tot;   //!
   TBranch        *b_sbs_gemCeR_m9_clust_nclustv;   //!
   TBranch        *b_sbs_gemCeR_m9_clust_nclustv_tot;   //!
   TBranch        *b_sbs_gemCeR_m9_strip_nstrips_keep;   //!
   TBranch        *b_sbs_gemCeR_m9_strip_nstrips_keepU;   //!
   TBranch        *b_sbs_gemCeR_m9_strip_nstrips_keepV;   //!
   TBranch        *b_sbs_gemCeR_m9_strip_nstrips_keep_lmax;   //!
   TBranch        *b_sbs_gemCeR_m9_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_sbs_gemCeR_m9_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_sbs_gemCeR_m9_strip_nstripsfired;   //!
   TBranch        *b_sbs_gemCeR_nlayershit;   //!
   TBranch        *b_sbs_gemCeR_nlayershitu;   //!
   TBranch        *b_sbs_gemCeR_nlayershituv;   //!
   TBranch        *b_sbs_gemCeR_nlayershitv;   //!
   TBranch        *b_sbs_gemCeR_track_besttrack;   //!
   TBranch        *b_sbs_gemCeR_track_ntrack;   //!
   TBranch        *b_sbs_hcal_adctime;   //!
   TBranch        *b_sbs_hcal_againblk;   //!
   TBranch        *b_sbs_hcal_atimeblk;   //!
   TBranch        *b_sbs_hcal_colblk;   //!
   TBranch        *b_sbs_hcal_colblk_goodtdc;   //!
   TBranch        *b_sbs_hcal_e;   //!
   TBranch        *b_sbs_hcal_e_goodtdc;   //!
   TBranch        *b_sbs_hcal_eblk;   //!
   TBranch        *b_sbs_hcal_eblk_goodtdc;   //!
   TBranch        *b_sbs_hcal_idblk;   //!
   TBranch        *b_sbs_hcal_idblk_goodtdc;   //!
   TBranch        *b_sbs_hcal_index;   //!
   TBranch        *b_sbs_hcal_nblk;   //!
   TBranch        *b_sbs_hcal_nblk_goodtdc;   //!
   TBranch        *b_sbs_hcal_nclus;   //!
   TBranch        *b_sbs_hcal_ngoodADChits;   //!
   TBranch        *b_sbs_hcal_rftime;   //!
   TBranch        *b_sbs_hcal_rowblk;   //!
   TBranch        *b_sbs_hcal_rowblk_goodtdc;   //!
   TBranch        *b_sbs_hcal_tdctime;   //!
   TBranch        *b_sbs_hcal_tdctime_tw;   //!
   TBranch        *b_sbs_hcal_tdctimeblk;   //!
   TBranch        *b_sbs_hcal_tdctimeblk_tw;   //!
   TBranch        *b_sbs_hcal_trigtime;   //!
   TBranch        *b_sbs_hcal_x;   //!
   TBranch        *b_sbs_hcal_y;   //!
   TBranch        *b_sbs_tdctrig_ngoodADChits;   //!
   TBranch        *b_sbs_tdctrig_ngoodTDChits;   //!
   TBranch        *b_sbs_tdctrig_nhits;   //!
   TBranch        *b_sbs_tdctrig_nrefhits;   //!
   TBranch        *b_sbs_tdctrig_rftime;   //!
   TBranch        *b_sbs_tdctrig_trigphase;   //!
   TBranch        *b_sbs_tdctrig_trigphasecorr;   //!
   TBranch        *b_sbs_tdctrig_trigtime;   //!
   TBranch        *b_sbs_tr_n;   //!
   TBranch        *b_scalhel_errcode;   //!
   TBranch        *b_scalhel_evtcount;   //!
   TBranch        *b_scalhel_hel;   //!
   TBranch        *b_scalhel_lhrs_fadc_hel;   //!
   TBranch        *b_scalhel_lhrs_fadc_pat;   //!
   TBranch        *b_scalhel_lhrs_fadc_tsettle;   //!
   TBranch        *b_scalhel_patcount;   //!
   TBranch        *b_scalhel_patphase;   //!
   TBranch        *b_scalhel_seed;   //!
   TBranch        *b_singletrack_bb;   //!
   TBranch        *b_anytrack_bb;   //!
   TBranch        *b_HALLA_p;   //!
   TBranch        *b_hac_bcm_average;   //!
   TBranch        *b_IPM1H04A_XPOS;   //!
   TBranch        *b_IPM1H04A_YPOS;   //!
   TBranch        *b_IPM1H04E_XPOS;   //!
   TBranch        *b_IPM1H04E_YPOS;   //!
   TBranch        *b_IGL1I00OD16_16;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtTime;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtNum;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtType;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtLen;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fHelicity;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fTrigBits;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fRun;   //!

   BB_optics_tree(TTree *tree=0);
   virtual ~BB_optics_tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef BB_optics_tree_cxx
BB_optics_tree::BB_optics_tree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("T",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("T","");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg0_0.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg10_10.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg1_1.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg2_2.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg3_3.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg4_4.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg5_5.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg6_6.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg7_7.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg8_8.root/T");
      chain->Add("/volatile/halla/sbs/puckett/GENRP_REPLAYS/Optics/WithSieveOffsets/rootfiles/e1217004_fullreplay_303_stream0_2_seg9_9.root/T");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

BB_optics_tree::~BB_optics_tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t BB_optics_tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t BB_optics_tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void BB_optics_tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ax_new", &ax_new, &b_ax_new);
   fChain->SetBranchAddress("bx_new", &bx_new, &b_bx_new);
   fChain->SetBranchAddress("ay_new", &ay_new, &b_ay_new);
   fChain->SetBranchAddress("by_new", &by_new, &b_by_new);
   fChain->SetBranchAddress("targx", &targx, &b_targx);
   fChain->SetBranchAddress("targy", &targy, &b_targy);
   fChain->SetBranchAddress("scalhel.true_hel", &scalhel_true_hel, &b_scalhel_true_hel);
   fChain->SetBranchAddress("scalhel.hel_stable", &scalhel_hel_stable, &b_scalhel_hel_stable);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.a_amp_p", &Ndata_bb_bbtrig_a_amp_p, &b_Ndata_bb_bbtrig_a_amp_p);
   fChain->SetBranchAddress("bb.bbtrig.a_amp_p", bb_bbtrig_a_amp_p, &b_bb_bbtrig_a_amp_p);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.a_time", &Ndata_bb_bbtrig_a_time, &b_Ndata_bb_bbtrig_a_time);
   fChain->SetBranchAddress("bb.bbtrig.a_time", bb_bbtrig_a_time, &b_bb_bbtrig_a_time);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.adcelemID", &Ndata_bb_bbtrig_adcelemID, &b_Ndata_bb_bbtrig_adcelemID);
   fChain->SetBranchAddress("bb.bbtrig.adcelemID", bb_bbtrig_adcelemID, &b_bb_bbtrig_adcelemID);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.tdc", &Ndata_bb_bbtrig_tdc, &b_Ndata_bb_bbtrig_tdc);
   fChain->SetBranchAddress("bb.bbtrig.tdc", bb_bbtrig_tdc, &b_bb_bbtrig_tdc);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.tdcelemID", &Ndata_bb_bbtrig_tdcelemID, &b_Ndata_bb_bbtrig_tdcelemID);
   fChain->SetBranchAddress("bb.bbtrig.tdcelemID", bb_bbtrig_tdcelemID, &b_bb_bbtrig_tdcelemID);
   fChain->SetBranchAddress("Ndata.bb.eps_over_etot", &Ndata_bb_eps_over_etot, &b_Ndata_bb_eps_over_etot);
   fChain->SetBranchAddress("bb.eps_over_etot", bb_eps_over_etot, &b_bb_eps_over_etot);
   fChain->SetBranchAddress("Ndata.bb.etot_over_p", &Ndata_bb_etot_over_p, &b_Ndata_bb_etot_over_p);
   fChain->SetBranchAddress("bb.etot_over_p", bb_etot_over_p, &b_bb_etot_over_p);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCU", &Ndata_bb_gem_hit_ADCU, &b_Ndata_bb_gem_hit_ADCU);
   fChain->SetBranchAddress("bb.gem.hit.ADCU", bb_gem_hit_ADCU, &b_bb_gem_hit_ADCU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCU_deconv", &Ndata_bb_gem_hit_ADCU_deconv, &b_Ndata_bb_gem_hit_ADCU_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCU_deconv", bb_gem_hit_ADCU_deconv, &b_bb_gem_hit_ADCU_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCV", &Ndata_bb_gem_hit_ADCV, &b_Ndata_bb_gem_hit_ADCV);
   fChain->SetBranchAddress("bb.gem.hit.ADCV", bb_gem_hit_ADCV, &b_bb_gem_hit_ADCV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCV_deconv", &Ndata_bb_gem_hit_ADCV_deconv, &b_Ndata_bb_gem_hit_ADCV_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCV_deconv", bb_gem_hit_ADCV_deconv, &b_bb_gem_hit_ADCV_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCasym", &Ndata_bb_gem_hit_ADCasym, &b_Ndata_bb_gem_hit_ADCasym);
   fChain->SetBranchAddress("bb.gem.hit.ADCasym", bb_gem_hit_ADCasym, &b_bb_gem_hit_ADCasym);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCasym_deconv", &Ndata_bb_gem_hit_ADCasym_deconv, &b_Ndata_bb_gem_hit_ADCasym_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCasym_deconv", bb_gem_hit_ADCasym_deconv, &b_bb_gem_hit_ADCasym_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCavg", &Ndata_bb_gem_hit_ADCavg, &b_Ndata_bb_gem_hit_ADCavg);
   fChain->SetBranchAddress("bb.gem.hit.ADCavg", bb_gem_hit_ADCavg, &b_bb_gem_hit_ADCavg);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCavg_deconv", &Ndata_bb_gem_hit_ADCavg_deconv, &b_Ndata_bb_gem_hit_ADCavg_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCavg_deconv", bb_gem_hit_ADCavg_deconv, &b_bb_gem_hit_ADCavg_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac0_Umax", &Ndata_bb_gem_hit_ADCfrac0_Umax, &b_Ndata_bb_gem_hit_ADCfrac0_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac0_Umax", bb_gem_hit_ADCfrac0_Umax, &b_bb_gem_hit_ADCfrac0_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac0_Vmax", &Ndata_bb_gem_hit_ADCfrac0_Vmax, &b_Ndata_bb_gem_hit_ADCfrac0_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac0_Vmax", bb_gem_hit_ADCfrac0_Vmax, &b_bb_gem_hit_ADCfrac0_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac1_Umax", &Ndata_bb_gem_hit_ADCfrac1_Umax, &b_Ndata_bb_gem_hit_ADCfrac1_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac1_Umax", bb_gem_hit_ADCfrac1_Umax, &b_bb_gem_hit_ADCfrac1_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac1_Vmax", &Ndata_bb_gem_hit_ADCfrac1_Vmax, &b_Ndata_bb_gem_hit_ADCfrac1_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac1_Vmax", bb_gem_hit_ADCfrac1_Vmax, &b_bb_gem_hit_ADCfrac1_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac2_Umax", &Ndata_bb_gem_hit_ADCfrac2_Umax, &b_Ndata_bb_gem_hit_ADCfrac2_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac2_Umax", bb_gem_hit_ADCfrac2_Umax, &b_bb_gem_hit_ADCfrac2_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac2_Vmax", &Ndata_bb_gem_hit_ADCfrac2_Vmax, &b_Ndata_bb_gem_hit_ADCfrac2_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac2_Vmax", bb_gem_hit_ADCfrac2_Vmax, &b_bb_gem_hit_ADCfrac2_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac3_Umax", &Ndata_bb_gem_hit_ADCfrac3_Umax, &b_Ndata_bb_gem_hit_ADCfrac3_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac3_Umax", bb_gem_hit_ADCfrac3_Umax, &b_bb_gem_hit_ADCfrac3_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac3_Vmax", &Ndata_bb_gem_hit_ADCfrac3_Vmax, &b_Ndata_bb_gem_hit_ADCfrac3_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac3_Vmax", bb_gem_hit_ADCfrac3_Vmax, &b_bb_gem_hit_ADCfrac3_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac4_Umax", &Ndata_bb_gem_hit_ADCfrac4_Umax, &b_Ndata_bb_gem_hit_ADCfrac4_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac4_Umax", bb_gem_hit_ADCfrac4_Umax, &b_bb_gem_hit_ADCfrac4_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac4_Vmax", &Ndata_bb_gem_hit_ADCfrac4_Vmax, &b_Ndata_bb_gem_hit_ADCfrac4_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac4_Vmax", bb_gem_hit_ADCfrac4_Vmax, &b_bb_gem_hit_ADCfrac4_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac5_Umax", &Ndata_bb_gem_hit_ADCfrac5_Umax, &b_Ndata_bb_gem_hit_ADCfrac5_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac5_Umax", bb_gem_hit_ADCfrac5_Umax, &b_bb_gem_hit_ADCfrac5_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac5_Vmax", &Ndata_bb_gem_hit_ADCfrac5_Vmax, &b_Ndata_bb_gem_hit_ADCfrac5_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac5_Vmax", bb_gem_hit_ADCfrac5_Vmax, &b_bb_gem_hit_ADCfrac5_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxcomboUclust_deconv", &Ndata_bb_gem_hit_ADCmaxcomboUclust_deconv, &b_Ndata_bb_gem_hit_ADCmaxcomboUclust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxcomboUclust_deconv", bb_gem_hit_ADCmaxcomboUclust_deconv, &b_bb_gem_hit_ADCmaxcomboUclust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxcomboVclust_deconv", &Ndata_bb_gem_hit_ADCmaxcomboVclust_deconv, &b_Ndata_bb_gem_hit_ADCmaxcomboVclust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxcomboVclust_deconv", bb_gem_hit_ADCmaxcomboVclust_deconv, &b_bb_gem_hit_ADCmaxcomboVclust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampU", &Ndata_bb_gem_hit_ADCmaxsampU, &b_Ndata_bb_gem_hit_ADCmaxsampU);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampU", bb_gem_hit_ADCmaxsampU, &b_bb_gem_hit_ADCmaxsampU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampUclust", &Ndata_bb_gem_hit_ADCmaxsampUclust, &b_Ndata_bb_gem_hit_ADCmaxsampUclust);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampUclust", bb_gem_hit_ADCmaxsampUclust, &b_bb_gem_hit_ADCmaxsampUclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampUclust_deconv", &Ndata_bb_gem_hit_ADCmaxsampUclust_deconv, &b_Ndata_bb_gem_hit_ADCmaxsampUclust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampUclust_deconv", bb_gem_hit_ADCmaxsampUclust_deconv, &b_bb_gem_hit_ADCmaxsampUclust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampV", &Ndata_bb_gem_hit_ADCmaxsampV, &b_Ndata_bb_gem_hit_ADCmaxsampV);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampV", bb_gem_hit_ADCmaxsampV, &b_bb_gem_hit_ADCmaxsampV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampVclust", &Ndata_bb_gem_hit_ADCmaxsampVclust, &b_Ndata_bb_gem_hit_ADCmaxsampVclust);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampVclust", bb_gem_hit_ADCmaxsampVclust, &b_bb_gem_hit_ADCmaxsampVclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampVclust_deconv", &Ndata_bb_gem_hit_ADCmaxsampVclust_deconv, &b_Ndata_bb_gem_hit_ADCmaxsampVclust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampVclust_deconv", bb_gem_hit_ADCmaxsampVclust_deconv, &b_bb_gem_hit_ADCmaxsampVclust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxstripU", &Ndata_bb_gem_hit_ADCmaxstripU, &b_Ndata_bb_gem_hit_ADCmaxstripU);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxstripU", bb_gem_hit_ADCmaxstripU, &b_bb_gem_hit_ADCmaxstripU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxstripV", &Ndata_bb_gem_hit_ADCmaxstripV, &b_Ndata_bb_gem_hit_ADCmaxstripV);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxstripV", bb_gem_hit_ADCmaxstripV, &b_bb_gem_hit_ADCmaxstripV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.BUILD_ALL_SAMPLES_U", &Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_U, &b_Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_U);
   fChain->SetBranchAddress("bb.gem.hit.BUILD_ALL_SAMPLES_U", bb_gem_hit_BUILD_ALL_SAMPLES_U, &b_bb_gem_hit_BUILD_ALL_SAMPLES_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.BUILD_ALL_SAMPLES_V", &Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_V, &b_Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_V);
   fChain->SetBranchAddress("bb.gem.hit.BUILD_ALL_SAMPLES_V", bb_gem_hit_BUILD_ALL_SAMPLES_V, &b_bb_gem_hit_BUILD_ALL_SAMPLES_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.CM_GOOD_U", &Ndata_bb_gem_hit_CM_GOOD_U, &b_Ndata_bb_gem_hit_CM_GOOD_U);
   fChain->SetBranchAddress("bb.gem.hit.CM_GOOD_U", bb_gem_hit_CM_GOOD_U, &b_bb_gem_hit_CM_GOOD_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.CM_GOOD_V", &Ndata_bb_gem_hit_CM_GOOD_V, &b_Ndata_bb_gem_hit_CM_GOOD_V);
   fChain->SetBranchAddress("bb.gem.hit.CM_GOOD_V", bb_gem_hit_CM_GOOD_V, &b_bb_gem_hit_CM_GOOD_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC0_Umax", &Ndata_bb_gem_hit_DeconvADC0_Umax, &b_Ndata_bb_gem_hit_DeconvADC0_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC0_Umax", bb_gem_hit_DeconvADC0_Umax, &b_bb_gem_hit_DeconvADC0_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC0_Vmax", &Ndata_bb_gem_hit_DeconvADC0_Vmax, &b_Ndata_bb_gem_hit_DeconvADC0_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC0_Vmax", bb_gem_hit_DeconvADC0_Vmax, &b_bb_gem_hit_DeconvADC0_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC1_Umax", &Ndata_bb_gem_hit_DeconvADC1_Umax, &b_Ndata_bb_gem_hit_DeconvADC1_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC1_Umax", bb_gem_hit_DeconvADC1_Umax, &b_bb_gem_hit_DeconvADC1_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC1_Vmax", &Ndata_bb_gem_hit_DeconvADC1_Vmax, &b_Ndata_bb_gem_hit_DeconvADC1_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC1_Vmax", bb_gem_hit_DeconvADC1_Vmax, &b_bb_gem_hit_DeconvADC1_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC2_Umax", &Ndata_bb_gem_hit_DeconvADC2_Umax, &b_Ndata_bb_gem_hit_DeconvADC2_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC2_Umax", bb_gem_hit_DeconvADC2_Umax, &b_bb_gem_hit_DeconvADC2_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC2_Vmax", &Ndata_bb_gem_hit_DeconvADC2_Vmax, &b_Ndata_bb_gem_hit_DeconvADC2_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC2_Vmax", bb_gem_hit_DeconvADC2_Vmax, &b_bb_gem_hit_DeconvADC2_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC3_Umax", &Ndata_bb_gem_hit_DeconvADC3_Umax, &b_Ndata_bb_gem_hit_DeconvADC3_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC3_Umax", bb_gem_hit_DeconvADC3_Umax, &b_bb_gem_hit_DeconvADC3_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC3_Vmax", &Ndata_bb_gem_hit_DeconvADC3_Vmax, &b_Ndata_bb_gem_hit_DeconvADC3_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC3_Vmax", bb_gem_hit_DeconvADC3_Vmax, &b_bb_gem_hit_DeconvADC3_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC4_Umax", &Ndata_bb_gem_hit_DeconvADC4_Umax, &b_Ndata_bb_gem_hit_DeconvADC4_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC4_Umax", bb_gem_hit_DeconvADC4_Umax, &b_bb_gem_hit_DeconvADC4_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC4_Vmax", &Ndata_bb_gem_hit_DeconvADC4_Vmax, &b_Ndata_bb_gem_hit_DeconvADC4_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC4_Vmax", bb_gem_hit_DeconvADC4_Vmax, &b_bb_gem_hit_DeconvADC4_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC5_Umax", &Ndata_bb_gem_hit_DeconvADC5_Umax, &b_Ndata_bb_gem_hit_DeconvADC5_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC5_Umax", bb_gem_hit_DeconvADC5_Umax, &b_bb_gem_hit_DeconvADC5_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC5_Vmax", &Ndata_bb_gem_hit_DeconvADC5_Vmax, &b_Ndata_bb_gem_hit_DeconvADC5_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC5_Vmax", bb_gem_hit_DeconvADC5_Vmax, &b_bb_gem_hit_DeconvADC5_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxcomboU", &Ndata_bb_gem_hit_DeconvADCmaxcomboU, &b_Ndata_bb_gem_hit_DeconvADCmaxcomboU);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxcomboU", bb_gem_hit_DeconvADCmaxcomboU, &b_bb_gem_hit_DeconvADCmaxcomboU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxcomboV", &Ndata_bb_gem_hit_DeconvADCmaxcomboV, &b_Ndata_bb_gem_hit_DeconvADCmaxcomboV);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxcomboV", bb_gem_hit_DeconvADCmaxcomboV, &b_bb_gem_hit_DeconvADCmaxcomboV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxsampU", &Ndata_bb_gem_hit_DeconvADCmaxsampU, &b_Ndata_bb_gem_hit_DeconvADCmaxsampU);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxsampU", bb_gem_hit_DeconvADCmaxsampU, &b_bb_gem_hit_DeconvADCmaxsampU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxsampV", &Ndata_bb_gem_hit_DeconvADCmaxsampV, &b_Ndata_bb_gem_hit_DeconvADCmaxsampV);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxsampV", bb_gem_hit_DeconvADCmaxsampV, &b_bb_gem_hit_DeconvADCmaxsampV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxstripU", &Ndata_bb_gem_hit_DeconvADCmaxstripU, &b_Ndata_bb_gem_hit_DeconvADCmaxstripU);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxstripU", bb_gem_hit_DeconvADCmaxstripU, &b_bb_gem_hit_DeconvADCmaxstripU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxstripV", &Ndata_bb_gem_hit_DeconvADCmaxstripV, &b_Ndata_bb_gem_hit_DeconvADCmaxstripV);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxstripV", bb_gem_hit_DeconvADCmaxstripV, &b_bb_gem_hit_DeconvADCmaxstripV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ENABLE_CM_U", &Ndata_bb_gem_hit_ENABLE_CM_U, &b_Ndata_bb_gem_hit_ENABLE_CM_U);
   fChain->SetBranchAddress("bb.gem.hit.ENABLE_CM_U", bb_gem_hit_ENABLE_CM_U, &b_bb_gem_hit_ENABLE_CM_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ENABLE_CM_V", &Ndata_bb_gem_hit_ENABLE_CM_V, &b_Ndata_bb_gem_hit_ENABLE_CM_V);
   fChain->SetBranchAddress("bb.gem.hit.ENABLE_CM_V", bb_gem_hit_ENABLE_CM_V, &b_bb_gem_hit_ENABLE_CM_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.TSchi2_Umax", &Ndata_bb_gem_hit_TSchi2_Umax, &b_Ndata_bb_gem_hit_TSchi2_Umax);
   fChain->SetBranchAddress("bb.gem.hit.TSchi2_Umax", bb_gem_hit_TSchi2_Umax, &b_bb_gem_hit_TSchi2_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.TSchi2_Vmax", &Ndata_bb_gem_hit_TSchi2_Vmax, &b_Ndata_bb_gem_hit_TSchi2_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.TSchi2_Vmax", bb_gem_hit_TSchi2_Vmax, &b_bb_gem_hit_TSchi2_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.TSprob_Umax", &Ndata_bb_gem_hit_TSprob_Umax, &b_Ndata_bb_gem_hit_TSprob_Umax);
   fChain->SetBranchAddress("bb.gem.hit.TSprob_Umax", bb_gem_hit_TSprob_Umax, &b_bb_gem_hit_TSprob_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.TSprob_Vmax", &Ndata_bb_gem_hit_TSprob_Vmax, &b_Ndata_bb_gem_hit_TSprob_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.TSprob_Vmax", bb_gem_hit_TSprob_Vmax, &b_bb_gem_hit_TSprob_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Tavg", &Ndata_bb_gem_hit_Tavg, &b_Ndata_bb_gem_hit_Tavg);
   fChain->SetBranchAddress("bb.gem.hit.Tavg", bb_gem_hit_Tavg, &b_bb_gem_hit_Tavg);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Tavg_corr", &Ndata_bb_gem_hit_Tavg_corr, &b_Ndata_bb_gem_hit_Tavg_corr);
   fChain->SetBranchAddress("bb.gem.hit.Tavg_corr", bb_gem_hit_Tavg_corr, &b_bb_gem_hit_Tavg_corr);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Tavg_deconv", &Ndata_bb_gem_hit_Tavg_deconv, &b_Ndata_bb_gem_hit_Tavg_deconv);
   fChain->SetBranchAddress("bb.gem.hit.Tavg_deconv", bb_gem_hit_Tavg_deconv, &b_bb_gem_hit_Tavg_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Tavg_fit", &Ndata_bb_gem_hit_Tavg_fit, &b_Ndata_bb_gem_hit_Tavg_fit);
   fChain->SetBranchAddress("bb.gem.hit.Tavg_fit", bb_gem_hit_Tavg_fit, &b_bb_gem_hit_Tavg_fit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Ugain", &Ndata_bb_gem_hit_Ugain, &b_Ndata_bb_gem_hit_Ugain);
   fChain->SetBranchAddress("bb.gem.hit.Ugain", bb_gem_hit_Ugain, &b_bb_gem_hit_Ugain);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Utime", &Ndata_bb_gem_hit_Utime, &b_Ndata_bb_gem_hit_Utime);
   fChain->SetBranchAddress("bb.gem.hit.Utime", bb_gem_hit_Utime, &b_bb_gem_hit_Utime);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeDeconv", &Ndata_bb_gem_hit_UtimeDeconv, &b_Ndata_bb_gem_hit_UtimeDeconv);
   fChain->SetBranchAddress("bb.gem.hit.UtimeDeconv", bb_gem_hit_UtimeDeconv, &b_bb_gem_hit_UtimeDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeFit", &Ndata_bb_gem_hit_UtimeFit, &b_Ndata_bb_gem_hit_UtimeFit);
   fChain->SetBranchAddress("bb.gem.hit.UtimeFit", bb_gem_hit_UtimeFit, &b_bb_gem_hit_UtimeFit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeMaxStrip", &Ndata_bb_gem_hit_UtimeMaxStrip, &b_Ndata_bb_gem_hit_UtimeMaxStrip);
   fChain->SetBranchAddress("bb.gem.hit.UtimeMaxStrip", bb_gem_hit_UtimeMaxStrip, &b_bb_gem_hit_UtimeMaxStrip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeMaxStripDeconv", &Ndata_bb_gem_hit_UtimeMaxStripDeconv, &b_Ndata_bb_gem_hit_UtimeMaxStripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.UtimeMaxStripDeconv", bb_gem_hit_UtimeMaxStripDeconv, &b_bb_gem_hit_UtimeMaxStripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeMaxStripFit", &Ndata_bb_gem_hit_UtimeMaxStripFit, &b_Ndata_bb_gem_hit_UtimeMaxStripFit);
   fChain->SetBranchAddress("bb.gem.hit.UtimeMaxStripFit", bb_gem_hit_UtimeMaxStripFit, &b_bb_gem_hit_UtimeMaxStripFit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Vgain", &Ndata_bb_gem_hit_Vgain, &b_Ndata_bb_gem_hit_Vgain);
   fChain->SetBranchAddress("bb.gem.hit.Vgain", bb_gem_hit_Vgain, &b_bb_gem_hit_Vgain);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Vtime", &Ndata_bb_gem_hit_Vtime, &b_Ndata_bb_gem_hit_Vtime);
   fChain->SetBranchAddress("bb.gem.hit.Vtime", bb_gem_hit_Vtime, &b_bb_gem_hit_Vtime);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeDeconv", &Ndata_bb_gem_hit_VtimeDeconv, &b_Ndata_bb_gem_hit_VtimeDeconv);
   fChain->SetBranchAddress("bb.gem.hit.VtimeDeconv", bb_gem_hit_VtimeDeconv, &b_bb_gem_hit_VtimeDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeFit", &Ndata_bb_gem_hit_VtimeFit, &b_Ndata_bb_gem_hit_VtimeFit);
   fChain->SetBranchAddress("bb.gem.hit.VtimeFit", bb_gem_hit_VtimeFit, &b_bb_gem_hit_VtimeFit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeMaxStrip", &Ndata_bb_gem_hit_VtimeMaxStrip, &b_Ndata_bb_gem_hit_VtimeMaxStrip);
   fChain->SetBranchAddress("bb.gem.hit.VtimeMaxStrip", bb_gem_hit_VtimeMaxStrip, &b_bb_gem_hit_VtimeMaxStrip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeMaxStripDeconv", &Ndata_bb_gem_hit_VtimeMaxStripDeconv, &b_Ndata_bb_gem_hit_VtimeMaxStripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.VtimeMaxStripDeconv", bb_gem_hit_VtimeMaxStripDeconv, &b_bb_gem_hit_VtimeMaxStripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeMaxStripFit", &Ndata_bb_gem_hit_VtimeMaxStripFit, &b_Ndata_bb_gem_hit_VtimeMaxStripFit);
   fChain->SetBranchAddress("bb.gem.hit.VtimeMaxStripFit", bb_gem_hit_VtimeMaxStripFit, &b_bb_gem_hit_VtimeMaxStripFit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.adc_id_U", &Ndata_bb_gem_hit_adc_id_U, &b_Ndata_bb_gem_hit_adc_id_U);
   fChain->SetBranchAddress("bb.gem.hit.adc_id_U", bb_gem_hit_adc_id_U, &b_bb_gem_hit_adc_id_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.adc_id_V", &Ndata_bb_gem_hit_adc_id_V, &b_Ndata_bb_gem_hit_adc_id_V);
   fChain->SetBranchAddress("bb.gem.hit.adc_id_V", bb_gem_hit_adc_id_V, &b_bb_gem_hit_adc_id_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ccor_clust", &Ndata_bb_gem_hit_ccor_clust, &b_Ndata_bb_gem_hit_ccor_clust);
   fChain->SetBranchAddress("bb.gem.hit.ccor_clust", bb_gem_hit_ccor_clust, &b_bb_gem_hit_ccor_clust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ccor_clust_deconv", &Ndata_bb_gem_hit_ccor_clust_deconv, &b_Ndata_bb_gem_hit_ccor_clust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ccor_clust_deconv", bb_gem_hit_ccor_clust_deconv, &b_bb_gem_hit_ccor_clust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ccor_strip", &Ndata_bb_gem_hit_ccor_strip, &b_Ndata_bb_gem_hit_ccor_strip);
   fChain->SetBranchAddress("bb.gem.hit.ccor_strip", bb_gem_hit_ccor_strip, &b_bb_gem_hit_ccor_strip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ccor_strip_deconv", &Ndata_bb_gem_hit_ccor_strip_deconv, &b_Ndata_bb_gem_hit_ccor_strip_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ccor_strip_deconv", bb_gem_hit_ccor_strip_deconv, &b_bb_gem_hit_ccor_strip_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.crate_U", &Ndata_bb_gem_hit_crate_U, &b_Ndata_bb_gem_hit_crate_U);
   fChain->SetBranchAddress("bb.gem.hit.crate_U", bb_gem_hit_crate_U, &b_bb_gem_hit_crate_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.crate_V", &Ndata_bb_gem_hit_crate_V, &b_Ndata_bb_gem_hit_crate_V);
   fChain->SetBranchAddress("bb.gem.hit.crate_V", bb_gem_hit_crate_V, &b_bb_gem_hit_crate_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.deltat", &Ndata_bb_gem_hit_deltat, &b_Ndata_bb_gem_hit_deltat);
   fChain->SetBranchAddress("bb.gem.hit.deltat", bb_gem_hit_deltat, &b_bb_gem_hit_deltat);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.deltat_deconv", &Ndata_bb_gem_hit_deltat_deconv, &b_Ndata_bb_gem_hit_deltat_deconv);
   fChain->SetBranchAddress("bb.gem.hit.deltat_deconv", bb_gem_hit_deltat_deconv, &b_bb_gem_hit_deltat_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.deltat_fit", &Ndata_bb_gem_hit_deltat_fit, &b_Ndata_bb_gem_hit_deltat_fit);
   fChain->SetBranchAddress("bb.gem.hit.deltat_fit", bb_gem_hit_deltat_fit, &b_bb_gem_hit_deltat_fit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.eresidu", &Ndata_bb_gem_hit_eresidu, &b_Ndata_bb_gem_hit_eresidu);
   fChain->SetBranchAddress("bb.gem.hit.eresidu", bb_gem_hit_eresidu, &b_bb_gem_hit_eresidu);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.eresidv", &Ndata_bb_gem_hit_eresidv, &b_Ndata_bb_gem_hit_eresidv);
   fChain->SetBranchAddress("bb.gem.hit.eresidv", bb_gem_hit_eresidv, &b_bb_gem_hit_eresidv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.icombomaxUclustDeconv", &Ndata_bb_gem_hit_icombomaxUclustDeconv, &b_Ndata_bb_gem_hit_icombomaxUclustDeconv);
   fChain->SetBranchAddress("bb.gem.hit.icombomaxUclustDeconv", bb_gem_hit_icombomaxUclustDeconv, &b_bb_gem_hit_icombomaxUclustDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.icombomaxUstripDeconv", &Ndata_bb_gem_hit_icombomaxUstripDeconv, &b_Ndata_bb_gem_hit_icombomaxUstripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.icombomaxUstripDeconv", bb_gem_hit_icombomaxUstripDeconv, &b_bb_gem_hit_icombomaxUstripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.icombomaxVclustDeconv", &Ndata_bb_gem_hit_icombomaxVclustDeconv, &b_Ndata_bb_gem_hit_icombomaxVclustDeconv);
   fChain->SetBranchAddress("bb.gem.hit.icombomaxVclustDeconv", bb_gem_hit_icombomaxVclustDeconv, &b_bb_gem_hit_icombomaxVclustDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.icombomaxVstripDeconv", &Ndata_bb_gem_hit_icombomaxVstripDeconv, &b_Ndata_bb_gem_hit_icombomaxVstripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.icombomaxVstripDeconv", bb_gem_hit_icombomaxVstripDeconv, &b_bb_gem_hit_icombomaxVstripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxUclust", &Ndata_bb_gem_hit_isampmaxUclust, &b_Ndata_bb_gem_hit_isampmaxUclust);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxUclust", bb_gem_hit_isampmaxUclust, &b_bb_gem_hit_isampmaxUclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxUclustDeconv", &Ndata_bb_gem_hit_isampmaxUclustDeconv, &b_Ndata_bb_gem_hit_isampmaxUclustDeconv);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxUclustDeconv", bb_gem_hit_isampmaxUclustDeconv, &b_bb_gem_hit_isampmaxUclustDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxUstrip", &Ndata_bb_gem_hit_isampmaxUstrip, &b_Ndata_bb_gem_hit_isampmaxUstrip);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxUstrip", bb_gem_hit_isampmaxUstrip, &b_bb_gem_hit_isampmaxUstrip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxUstripDeconv", &Ndata_bb_gem_hit_isampmaxUstripDeconv, &b_Ndata_bb_gem_hit_isampmaxUstripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxUstripDeconv", bb_gem_hit_isampmaxUstripDeconv, &b_bb_gem_hit_isampmaxUstripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxVclust", &Ndata_bb_gem_hit_isampmaxVclust, &b_Ndata_bb_gem_hit_isampmaxVclust);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxVclust", bb_gem_hit_isampmaxVclust, &b_bb_gem_hit_isampmaxVclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxVclustDeconv", &Ndata_bb_gem_hit_isampmaxVclustDeconv, &b_Ndata_bb_gem_hit_isampmaxVclustDeconv);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxVclustDeconv", bb_gem_hit_isampmaxVclustDeconv, &b_bb_gem_hit_isampmaxVclustDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxVstrip", &Ndata_bb_gem_hit_isampmaxVstrip, &b_Ndata_bb_gem_hit_isampmaxVstrip);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxVstrip", bb_gem_hit_isampmaxVstrip, &b_bb_gem_hit_isampmaxVstrip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxVstripDeconv", &Ndata_bb_gem_hit_isampmaxVstripDeconv, &b_Ndata_bb_gem_hit_isampmaxVstripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxVstripDeconv", bb_gem_hit_isampmaxVstripDeconv, &b_bb_gem_hit_isampmaxVstripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.layer", &Ndata_bb_gem_hit_layer, &b_Ndata_bb_gem_hit_layer);
   fChain->SetBranchAddress("bb.gem.hit.layer", bb_gem_hit_layer, &b_bb_gem_hit_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.module", &Ndata_bb_gem_hit_module, &b_Ndata_bb_gem_hit_module);
   fChain->SetBranchAddress("bb.gem.hit.module", bb_gem_hit_module, &b_bb_gem_hit_module);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.mpd_U", &Ndata_bb_gem_hit_mpd_U, &b_Ndata_bb_gem_hit_mpd_U);
   fChain->SetBranchAddress("bb.gem.hit.mpd_U", bb_gem_hit_mpd_U, &b_bb_gem_hit_mpd_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.mpd_V", &Ndata_bb_gem_hit_mpd_V, &b_Ndata_bb_gem_hit_mpd_V);
   fChain->SetBranchAddress("bb.gem.hit.mpd_V", bb_gem_hit_mpd_V, &b_bb_gem_hit_mpd_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.nstripu", &Ndata_bb_gem_hit_nstripu, &b_Ndata_bb_gem_hit_nstripu);
   fChain->SetBranchAddress("bb.gem.hit.nstripu", bb_gem_hit_nstripu, &b_bb_gem_hit_nstripu);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.nstripv", &Ndata_bb_gem_hit_nstripv, &b_Ndata_bb_gem_hit_nstripv);
   fChain->SetBranchAddress("bb.gem.hit.nstripv", bb_gem_hit_nstripv, &b_bb_gem_hit_nstripv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.residu", &Ndata_bb_gem_hit_residu, &b_Ndata_bb_gem_hit_residu);
   fChain->SetBranchAddress("bb.gem.hit.residu", bb_gem_hit_residu, &b_bb_gem_hit_residu);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.residv", &Ndata_bb_gem_hit_residv, &b_Ndata_bb_gem_hit_residv);
   fChain->SetBranchAddress("bb.gem.hit.residv", bb_gem_hit_residv, &b_bb_gem_hit_residv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.trackindex", &Ndata_bb_gem_hit_trackindex, &b_Ndata_bb_gem_hit_trackindex);
   fChain->SetBranchAddress("bb.gem.hit.trackindex", bb_gem_hit_trackindex, &b_bb_gem_hit_trackindex);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.u", &Ndata_bb_gem_hit_u, &b_Ndata_bb_gem_hit_u);
   fChain->SetBranchAddress("bb.gem.hit.u", bb_gem_hit_u, &b_bb_gem_hit_u);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.uTScorr_MaxStripU", &Ndata_bb_gem_hit_uTScorr_MaxStripU, &b_Ndata_bb_gem_hit_uTScorr_MaxStripU);
   fChain->SetBranchAddress("bb.gem.hit.uTScorr_MaxStripU", bb_gem_hit_uTScorr_MaxStripU, &b_bb_gem_hit_uTScorr_MaxStripU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.uTScorr_MaxStripV", &Ndata_bb_gem_hit_uTScorr_MaxStripV, &b_Ndata_bb_gem_hit_uTScorr_MaxStripV);
   fChain->SetBranchAddress("bb.gem.hit.uTScorr_MaxStripV", bb_gem_hit_uTScorr_MaxStripV, &b_bb_gem_hit_uTScorr_MaxStripV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.uTScorr_Uclust", &Ndata_bb_gem_hit_uTScorr_Uclust, &b_Ndata_bb_gem_hit_uTScorr_Uclust);
   fChain->SetBranchAddress("bb.gem.hit.uTScorr_Uclust", bb_gem_hit_uTScorr_Uclust, &b_bb_gem_hit_uTScorr_Uclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.uTScorr_Vclust", &Ndata_bb_gem_hit_uTScorr_Vclust, &b_Ndata_bb_gem_hit_uTScorr_Vclust);
   fChain->SetBranchAddress("bb.gem.hit.uTScorr_Vclust", bb_gem_hit_uTScorr_Vclust, &b_bb_gem_hit_uTScorr_Vclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.umoment", &Ndata_bb_gem_hit_umoment, &b_Ndata_bb_gem_hit_umoment);
   fChain->SetBranchAddress("bb.gem.hit.umoment", bb_gem_hit_umoment, &b_bb_gem_hit_umoment);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.usigma", &Ndata_bb_gem_hit_usigma, &b_Ndata_bb_gem_hit_usigma);
   fChain->SetBranchAddress("bb.gem.hit.usigma", bb_gem_hit_usigma, &b_bb_gem_hit_usigma);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ustriphi", &Ndata_bb_gem_hit_ustriphi, &b_Ndata_bb_gem_hit_ustriphi);
   fChain->SetBranchAddress("bb.gem.hit.ustriphi", bb_gem_hit_ustriphi, &b_bb_gem_hit_ustriphi);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ustriplo", &Ndata_bb_gem_hit_ustriplo, &b_Ndata_bb_gem_hit_ustriplo);
   fChain->SetBranchAddress("bb.gem.hit.ustriplo", bb_gem_hit_ustriplo, &b_bb_gem_hit_ustriplo);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ustripmax", &Ndata_bb_gem_hit_ustripmax, &b_Ndata_bb_gem_hit_ustripmax);
   fChain->SetBranchAddress("bb.gem.hit.ustripmax", bb_gem_hit_ustripmax, &b_bb_gem_hit_ustripmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.v", &Ndata_bb_gem_hit_v, &b_Ndata_bb_gem_hit_v);
   fChain->SetBranchAddress("bb.gem.hit.v", bb_gem_hit_v, &b_bb_gem_hit_v);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vmoment", &Ndata_bb_gem_hit_vmoment, &b_Ndata_bb_gem_hit_vmoment);
   fChain->SetBranchAddress("bb.gem.hit.vmoment", bb_gem_hit_vmoment, &b_bb_gem_hit_vmoment);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vsigma", &Ndata_bb_gem_hit_vsigma, &b_Ndata_bb_gem_hit_vsigma);
   fChain->SetBranchAddress("bb.gem.hit.vsigma", bb_gem_hit_vsigma, &b_bb_gem_hit_vsigma);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vstriphi", &Ndata_bb_gem_hit_vstriphi, &b_Ndata_bb_gem_hit_vstriphi);
   fChain->SetBranchAddress("bb.gem.hit.vstriphi", bb_gem_hit_vstriphi, &b_bb_gem_hit_vstriphi);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vstriplo", &Ndata_bb_gem_hit_vstriplo, &b_Ndata_bb_gem_hit_vstriplo);
   fChain->SetBranchAddress("bb.gem.hit.vstriplo", bb_gem_hit_vstriplo, &b_bb_gem_hit_vstriplo);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vstripmax", &Ndata_bb_gem_hit_vstripmax, &b_Ndata_bb_gem_hit_vstripmax);
   fChain->SetBranchAddress("bb.gem.hit.vstripmax", bb_gem_hit_vstripmax, &b_bb_gem_hit_vstripmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.wTScorr_MaxStripU", &Ndata_bb_gem_hit_wTScorr_MaxStripU, &b_Ndata_bb_gem_hit_wTScorr_MaxStripU);
   fChain->SetBranchAddress("bb.gem.hit.wTScorr_MaxStripU", bb_gem_hit_wTScorr_MaxStripU, &b_bb_gem_hit_wTScorr_MaxStripU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.wTScorr_MaxStripV", &Ndata_bb_gem_hit_wTScorr_MaxStripV, &b_Ndata_bb_gem_hit_wTScorr_MaxStripV);
   fChain->SetBranchAddress("bb.gem.hit.wTScorr_MaxStripV", bb_gem_hit_wTScorr_MaxStripV, &b_bb_gem_hit_wTScorr_MaxStripV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.wTScorr_Uclust", &Ndata_bb_gem_hit_wTScorr_Uclust, &b_Ndata_bb_gem_hit_wTScorr_Uclust);
   fChain->SetBranchAddress("bb.gem.hit.wTScorr_Uclust", bb_gem_hit_wTScorr_Uclust, &b_bb_gem_hit_wTScorr_Uclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.wTScorr_Vclust", &Ndata_bb_gem_hit_wTScorr_Vclust, &b_Ndata_bb_gem_hit_wTScorr_Vclust);
   fChain->SetBranchAddress("bb.gem.hit.wTScorr_Vclust", bb_gem_hit_wTScorr_Vclust, &b_bb_gem_hit_wTScorr_Vclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.xglobal", &Ndata_bb_gem_hit_xglobal, &b_Ndata_bb_gem_hit_xglobal);
   fChain->SetBranchAddress("bb.gem.hit.xglobal", bb_gem_hit_xglobal, &b_bb_gem_hit_xglobal);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.xlocal", &Ndata_bb_gem_hit_xlocal, &b_Ndata_bb_gem_hit_xlocal);
   fChain->SetBranchAddress("bb.gem.hit.xlocal", bb_gem_hit_xlocal, &b_bb_gem_hit_xlocal);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.yglobal", &Ndata_bb_gem_hit_yglobal, &b_Ndata_bb_gem_hit_yglobal);
   fChain->SetBranchAddress("bb.gem.hit.yglobal", bb_gem_hit_yglobal, &b_bb_gem_hit_yglobal);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ylocal", &Ndata_bb_gem_hit_ylocal, &b_Ndata_bb_gem_hit_ylocal);
   fChain->SetBranchAddress("bb.gem.hit.ylocal", bb_gem_hit_ylocal, &b_bb_gem_hit_ylocal);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.zglobal", &Ndata_bb_gem_hit_zglobal, &b_Ndata_bb_gem_hit_zglobal);
   fChain->SetBranchAddress("bb.gem.hit.zglobal", bb_gem_hit_zglobal, &b_bb_gem_hit_zglobal);
   fChain->SetBranchAddress("Ndata.bb.gem.n2Dhit_layer", &Ndata_bb_gem_n2Dhit_layer, &b_Ndata_bb_gem_n2Dhit_layer);
   fChain->SetBranchAddress("bb.gem.n2Dhit_layer", bb_gem_n2Dhit_layer, &b_bb_gem_n2Dhit_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.nclustu_layer", &Ndata_bb_gem_nclustu_layer, &b_Ndata_bb_gem_nclustu_layer);
   fChain->SetBranchAddress("bb.gem.nclustu_layer", bb_gem_nclustu_layer, &b_bb_gem_nclustu_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.nclustv_layer", &Ndata_bb_gem_nclustv_layer, &b_Ndata_bb_gem_nclustv_layer);
   fChain->SetBranchAddress("bb.gem.nclustv_layer", bb_gem_nclustv_layer, &b_bb_gem_nclustv_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.nstripsu_layer", &Ndata_bb_gem_nstripsu_layer, &b_Ndata_bb_gem_nstripsu_layer);
   fChain->SetBranchAddress("bb.gem.nstripsu_layer", bb_gem_nstripsu_layer, &b_bb_gem_nstripsu_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.nstripsv_layer", &Ndata_bb_gem_nstripsv_layer, &b_Ndata_bb_gem_nstripsv_layer);
   fChain->SetBranchAddress("bb.gem.nstripsv_layer", bb_gem_nstripsv_layer, &b_bb_gem_nstripsv_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.track.chi2ndf", &Ndata_bb_gem_track_chi2ndf, &b_Ndata_bb_gem_track_chi2ndf);
   fChain->SetBranchAddress("bb.gem.track.chi2ndf", bb_gem_track_chi2ndf, &b_bb_gem_track_chi2ndf);
   fChain->SetBranchAddress("Ndata.bb.gem.track.chi2ndf_hitquality", &Ndata_bb_gem_track_chi2ndf_hitquality, &b_Ndata_bb_gem_track_chi2ndf_hitquality);
   fChain->SetBranchAddress("bb.gem.track.chi2ndf_hitquality", bb_gem_track_chi2ndf_hitquality, &b_bb_gem_track_chi2ndf_hitquality);
   fChain->SetBranchAddress("Ndata.bb.gem.track.ngoodhits", &Ndata_bb_gem_track_ngoodhits, &b_Ndata_bb_gem_track_ngoodhits);
   fChain->SetBranchAddress("bb.gem.track.ngoodhits", bb_gem_track_ngoodhits, &b_bb_gem_track_ngoodhits);
   fChain->SetBranchAddress("Ndata.bb.gem.track.nhits", &Ndata_bb_gem_track_nhits, &b_Ndata_bb_gem_track_nhits);
   fChain->SetBranchAddress("bb.gem.track.nhits", bb_gem_track_nhits, &b_bb_gem_track_nhits);
   fChain->SetBranchAddress("Ndata.bb.gem.track.t0", &Ndata_bb_gem_track_t0, &b_Ndata_bb_gem_track_t0);
   fChain->SetBranchAddress("bb.gem.track.t0", bb_gem_track_t0, &b_bb_gem_track_t0);
   fChain->SetBranchAddress("Ndata.bb.gem.track.x", &Ndata_bb_gem_track_x, &b_Ndata_bb_gem_track_x);
   fChain->SetBranchAddress("bb.gem.track.x", bb_gem_track_x, &b_bb_gem_track_x);
   fChain->SetBranchAddress("Ndata.bb.gem.track.xp", &Ndata_bb_gem_track_xp, &b_Ndata_bb_gem_track_xp);
   fChain->SetBranchAddress("bb.gem.track.xp", bb_gem_track_xp, &b_bb_gem_track_xp);
   fChain->SetBranchAddress("Ndata.bb.gem.track.y", &Ndata_bb_gem_track_y, &b_Ndata_bb_gem_track_y);
   fChain->SetBranchAddress("bb.gem.track.y", bb_gem_track_y, &b_bb_gem_track_y);
   fChain->SetBranchAddress("Ndata.bb.gem.track.yp", &Ndata_bb_gem_track_yp, &b_Ndata_bb_gem_track_yp);
   fChain->SetBranchAddress("bb.gem.track.yp", bb_gem_track_yp, &b_bb_gem_track_yp);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.adc", &Ndata_bb_grinch_tdc_allclus_adc, &b_Ndata_bb_grinch_tdc_allclus_adc);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.adc", bb_grinch_tdc_allclus_adc, &b_bb_grinch_tdc_allclus_adc);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.dx", &Ndata_bb_grinch_tdc_allclus_dx, &b_Ndata_bb_grinch_tdc_allclus_dx);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.dx", bb_grinch_tdc_allclus_dx, &b_bb_grinch_tdc_allclus_dx);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.dy", &Ndata_bb_grinch_tdc_allclus_dy, &b_Ndata_bb_grinch_tdc_allclus_dy);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.dy", bb_grinch_tdc_allclus_dy, &b_bb_grinch_tdc_allclus_dy);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.mirrorindex", &Ndata_bb_grinch_tdc_allclus_mirrorindex, &b_Ndata_bb_grinch_tdc_allclus_mirrorindex);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.mirrorindex", bb_grinch_tdc_allclus_mirrorindex, &b_bb_grinch_tdc_allclus_mirrorindex);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.size", &Ndata_bb_grinch_tdc_allclus_size, &b_Ndata_bb_grinch_tdc_allclus_size);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.size", bb_grinch_tdc_allclus_size, &b_bb_grinch_tdc_allclus_size);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.t_mean", &Ndata_bb_grinch_tdc_allclus_t_mean, &b_Ndata_bb_grinch_tdc_allclus_t_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.t_mean", bb_grinch_tdc_allclus_t_mean, &b_bb_grinch_tdc_allclus_t_mean);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.t_mean_corr", &Ndata_bb_grinch_tdc_allclus_t_mean_corr, &b_Ndata_bb_grinch_tdc_allclus_t_mean_corr);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.t_mean_corr", bb_grinch_tdc_allclus_t_mean_corr, &b_bb_grinch_tdc_allclus_t_mean_corr);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.t_rms", &Ndata_bb_grinch_tdc_allclus_t_rms, &b_Ndata_bb_grinch_tdc_allclus_t_rms);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.t_rms", bb_grinch_tdc_allclus_t_rms, &b_bb_grinch_tdc_allclus_t_rms);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.t_rms_corr", &Ndata_bb_grinch_tdc_allclus_t_rms_corr, &b_Ndata_bb_grinch_tdc_allclus_t_rms_corr);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.t_rms_corr", bb_grinch_tdc_allclus_t_rms_corr, &b_bb_grinch_tdc_allclus_t_rms_corr);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.tot_mean", &Ndata_bb_grinch_tdc_allclus_tot_mean, &b_Ndata_bb_grinch_tdc_allclus_tot_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.tot_mean", bb_grinch_tdc_allclus_tot_mean, &b_bb_grinch_tdc_allclus_tot_mean);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.trackindex", &Ndata_bb_grinch_tdc_allclus_trackindex, &b_Ndata_bb_grinch_tdc_allclus_trackindex);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.trackindex", bb_grinch_tdc_allclus_trackindex, &b_bb_grinch_tdc_allclus_trackindex);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.x_mean", &Ndata_bb_grinch_tdc_allclus_x_mean, &b_Ndata_bb_grinch_tdc_allclus_x_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.x_mean", bb_grinch_tdc_allclus_x_mean, &b_bb_grinch_tdc_allclus_x_mean);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.y_mean", &Ndata_bb_grinch_tdc_allclus_y_mean, &b_Ndata_bb_grinch_tdc_allclus_y_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.y_mean", bb_grinch_tdc_allclus_y_mean, &b_bb_grinch_tdc_allclus_y_mean);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.amp", &Ndata_bb_grinch_tdc_hit_amp, &b_Ndata_bb_grinch_tdc_hit_amp);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.amp", bb_grinch_tdc_hit_amp, &b_bb_grinch_tdc_hit_amp);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.clustindex", &Ndata_bb_grinch_tdc_hit_clustindex, &b_Ndata_bb_grinch_tdc_hit_clustindex);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.clustindex", bb_grinch_tdc_hit_clustindex, &b_bb_grinch_tdc_hit_clustindex);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.col", &Ndata_bb_grinch_tdc_hit_col, &b_Ndata_bb_grinch_tdc_hit_col);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.col", bb_grinch_tdc_hit_col, &b_bb_grinch_tdc_hit_col);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.pmtnum", &Ndata_bb_grinch_tdc_hit_pmtnum, &b_Ndata_bb_grinch_tdc_hit_pmtnum);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.pmtnum", bb_grinch_tdc_hit_pmtnum, &b_bb_grinch_tdc_hit_pmtnum);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.row", &Ndata_bb_grinch_tdc_hit_row, &b_Ndata_bb_grinch_tdc_hit_row);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.row", bb_grinch_tdc_hit_row, &b_bb_grinch_tdc_hit_row);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.time", &Ndata_bb_grinch_tdc_hit_time, &b_Ndata_bb_grinch_tdc_hit_time);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.time", bb_grinch_tdc_hit_time, &b_bb_grinch_tdc_hit_time);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.time_corr", &Ndata_bb_grinch_tdc_hit_time_corr, &b_Ndata_bb_grinch_tdc_hit_time_corr);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.time_corr", bb_grinch_tdc_hit_time_corr, &b_bb_grinch_tdc_hit_time_corr);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.trackindex", &Ndata_bb_grinch_tdc_hit_trackindex, &b_Ndata_bb_grinch_tdc_hit_trackindex);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.trackindex", bb_grinch_tdc_hit_trackindex, &b_bb_grinch_tdc_hit_trackindex);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.xhit", &Ndata_bb_grinch_tdc_hit_xhit, &b_Ndata_bb_grinch_tdc_hit_xhit);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.xhit", bb_grinch_tdc_hit_xhit, &b_bb_grinch_tdc_hit_xhit);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.yhit", &Ndata_bb_grinch_tdc_hit_yhit, &b_Ndata_bb_grinch_tdc_hit_yhit);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.yhit", bb_grinch_tdc_hit_yhit, &b_bb_grinch_tdc_hit_yhit);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc", &Ndata_bb_hodotdc_Ref_tdc, &b_Ndata_bb_hodotdc_Ref_tdc);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdc", bb_hodotdc_Ref_tdc, &b_bb_hodotdc_Ref_tdc);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_mult", &Ndata_bb_hodotdc_Ref_tdc_mult, &b_Ndata_bb_hodotdc_Ref_tdc_mult);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_mult", bb_hodotdc_Ref_tdc_mult, &b_bb_hodotdc_Ref_tdc_mult);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_te", &Ndata_bb_hodotdc_Ref_tdc_te, &b_Ndata_bb_hodotdc_Ref_tdc_te);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_te", bb_hodotdc_Ref_tdc_te, &b_bb_hodotdc_Ref_tdc_te);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_tot", &Ndata_bb_hodotdc_Ref_tdc_tot, &b_Ndata_bb_hodotdc_Ref_tdc_tot);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_tot", bb_hodotdc_Ref_tdc_tot, &b_bb_hodotdc_Ref_tdc_tot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdcelemID", &Ndata_bb_hodotdc_Ref_tdcelemID, &b_Ndata_bb_hodotdc_Ref_tdcelemID);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdcelemID", bb_hodotdc_Ref_tdcelemID, &b_bb_hodotdc_Ref_tdcelemID);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.etof", &Ndata_bb_hodotdc_allclus_etof, &b_Ndata_bb_hodotdc_allclus_etof);
   fChain->SetBranchAddress("bb.hodotdc.allclus.etof", bb_hodotdc_allclus_etof, &b_bb_hodotdc_allclus_etof);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.iclust", &Ndata_bb_hodotdc_allclus_iclust, &b_Ndata_bb_hodotdc_allclus_iclust);
   fChain->SetBranchAddress("bb.hodotdc.allclus.iclust", bb_hodotdc_allclus_iclust, &b_bb_hodotdc_allclus_iclust);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.id", &Ndata_bb_hodotdc_allclus_id, &b_Ndata_bb_hodotdc_allclus_id);
   fChain->SetBranchAddress("bb.hodotdc.allclus.id", bb_hodotdc_allclus_id, &b_bb_hodotdc_allclus_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.itrack", &Ndata_bb_hodotdc_allclus_itrack, &b_Ndata_bb_hodotdc_allclus_itrack);
   fChain->SetBranchAddress("bb.hodotdc.allclus.itrack", bb_hodotdc_allclus_itrack, &b_bb_hodotdc_allclus_itrack);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.size", &Ndata_bb_hodotdc_allclus_size, &b_Ndata_bb_hodotdc_allclus_size);
   fChain->SetBranchAddress("bb.hodotdc.allclus.size", bb_hodotdc_allclus_size, &b_bb_hodotdc_allclus_size);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tdiff", &Ndata_bb_hodotdc_allclus_tdiff, &b_Ndata_bb_hodotdc_allclus_tdiff);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tdiff", bb_hodotdc_allclus_tdiff, &b_bb_hodotdc_allclus_tdiff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tfinal", &Ndata_bb_hodotdc_allclus_tfinal, &b_Ndata_bb_hodotdc_allclus_tfinal);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tfinal", bb_hodotdc_allclus_tfinal, &b_bb_hodotdc_allclus_tfinal);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tleft", &Ndata_bb_hodotdc_allclus_tleft, &b_Ndata_bb_hodotdc_allclus_tleft);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tleft", bb_hodotdc_allclus_tleft, &b_bb_hodotdc_allclus_tleft);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tmean", &Ndata_bb_hodotdc_allclus_tmean, &b_Ndata_bb_hodotdc_allclus_tmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tmean", bb_hodotdc_allclus_tmean, &b_bb_hodotdc_allclus_tmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tmeanRFcorr", &Ndata_bb_hodotdc_allclus_tmeanRFcorr, &b_Ndata_bb_hodotdc_allclus_tmeanRFcorr);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tmeanRFcorr", bb_hodotdc_allclus_tmeanRFcorr, &b_bb_hodotdc_allclus_tmeanRFcorr);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.totleft", &Ndata_bb_hodotdc_allclus_totleft, &b_Ndata_bb_hodotdc_allclus_totleft);
   fChain->SetBranchAddress("bb.hodotdc.allclus.totleft", bb_hodotdc_allclus_totleft, &b_bb_hodotdc_allclus_totleft);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.totmean", &Ndata_bb_hodotdc_allclus_totmean, &b_Ndata_bb_hodotdc_allclus_totmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.totmean", bb_hodotdc_allclus_totmean, &b_bb_hodotdc_allclus_totmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.totright", &Ndata_bb_hodotdc_allclus_totright, &b_Ndata_bb_hodotdc_allclus_totright);
   fChain->SetBranchAddress("bb.hodotdc.allclus.totright", bb_hodotdc_allclus_totright, &b_bb_hodotdc_allclus_totright);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tright", &Ndata_bb_hodotdc_allclus_tright, &b_Ndata_bb_hodotdc_allclus_tright);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tright", bb_hodotdc_allclus_tright, &b_bb_hodotdc_allclus_tright);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.xmean", &Ndata_bb_hodotdc_allclus_xmean, &b_Ndata_bb_hodotdc_allclus_xmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.xmean", bb_hodotdc_allclus_xmean, &b_bb_hodotdc_allclus_xmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.ymean", &Ndata_bb_hodotdc_allclus_ymean, &b_Ndata_bb_hodotdc_allclus_ymean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.ymean", bb_hodotdc_allclus_ymean, &b_bb_hodotdc_allclus_ymean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.etof", &Ndata_bb_hodotdc_clus_bar_tdc_etof, &b_Ndata_bb_hodotdc_clus_bar_tdc_etof);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.etof", bb_hodotdc_clus_bar_tdc_etof, &b_bb_hodotdc_clus_bar_tdc_etof);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.iclust", &Ndata_bb_hodotdc_clus_bar_tdc_iclust, &b_Ndata_bb_hodotdc_clus_bar_tdc_iclust);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.iclust", bb_hodotdc_clus_bar_tdc_iclust, &b_bb_hodotdc_clus_bar_tdc_iclust);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.id", &Ndata_bb_hodotdc_clus_bar_tdc_id, &b_Ndata_bb_hodotdc_clus_bar_tdc_id);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.id", bb_hodotdc_clus_bar_tdc_id, &b_bb_hodotdc_clus_bar_tdc_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.itrack", &Ndata_bb_hodotdc_clus_bar_tdc_itrack, &b_Ndata_bb_hodotdc_clus_bar_tdc_itrack);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.itrack", bb_hodotdc_clus_bar_tdc_itrack, &b_bb_hodotdc_clus_bar_tdc_itrack);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.meantime", &Ndata_bb_hodotdc_clus_bar_tdc_meantime, &b_Ndata_bb_hodotdc_clus_bar_tdc_meantime);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.meantime", bb_hodotdc_clus_bar_tdc_meantime, &b_bb_hodotdc_clus_bar_tdc_meantime);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.meantot", &Ndata_bb_hodotdc_clus_bar_tdc_meantot, &b_Ndata_bb_hodotdc_clus_bar_tdc_meantot);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.meantot", bb_hodotdc_clus_bar_tdc_meantot, &b_bb_hodotdc_clus_bar_tdc_meantot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.tfinal", &Ndata_bb_hodotdc_clus_bar_tdc_tfinal, &b_Ndata_bb_hodotdc_clus_bar_tdc_tfinal);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.tfinal", bb_hodotdc_clus_bar_tdc_tfinal, &b_bb_hodotdc_clus_bar_tdc_tfinal);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.timediff", &Ndata_bb_hodotdc_clus_bar_tdc_timediff, &b_Ndata_bb_hodotdc_clus_bar_tdc_timediff);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.timediff", bb_hodotdc_clus_bar_tdc_timediff, &b_bb_hodotdc_clus_bar_tdc_timediff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.timehitpos", &Ndata_bb_hodotdc_clus_bar_tdc_timehitpos, &b_Ndata_bb_hodotdc_clus_bar_tdc_timehitpos);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.timehitpos", bb_hodotdc_clus_bar_tdc_timehitpos, &b_bb_hodotdc_clus_bar_tdc_timehitpos);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.tleft", &Ndata_bb_hodotdc_clus_bar_tdc_tleft, &b_Ndata_bb_hodotdc_clus_bar_tdc_tleft);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.tleft", bb_hodotdc_clus_bar_tdc_tleft, &b_bb_hodotdc_clus_bar_tdc_tleft);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.tmeanRFcorr", &Ndata_bb_hodotdc_clus_bar_tdc_tmeanRFcorr, &b_Ndata_bb_hodotdc_clus_bar_tdc_tmeanRFcorr);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.tmeanRFcorr", bb_hodotdc_clus_bar_tdc_tmeanRFcorr, &b_bb_hodotdc_clus_bar_tdc_tmeanRFcorr);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.totleft", &Ndata_bb_hodotdc_clus_bar_tdc_totleft, &b_Ndata_bb_hodotdc_clus_bar_tdc_totleft);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.totleft", bb_hodotdc_clus_bar_tdc_totleft, &b_bb_hodotdc_clus_bar_tdc_totleft);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.totright", &Ndata_bb_hodotdc_clus_bar_tdc_totright, &b_Ndata_bb_hodotdc_clus_bar_tdc_totright);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.totright", bb_hodotdc_clus_bar_tdc_totright, &b_bb_hodotdc_clus_bar_tdc_totright);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.tright", &Ndata_bb_hodotdc_clus_bar_tdc_tright, &b_Ndata_bb_hodotdc_clus_bar_tdc_tright);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.tright", bb_hodotdc_clus_bar_tdc_tright, &b_bb_hodotdc_clus_bar_tdc_tright);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.vpos", &Ndata_bb_hodotdc_clus_bar_tdc_vpos, &b_Ndata_bb_hodotdc_clus_bar_tdc_vpos);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.vpos", bb_hodotdc_clus_bar_tdc_vpos, &b_bb_hodotdc_clus_bar_tdc_vpos);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.etof", &Ndata_bb_hodotdc_clus_etof, &b_Ndata_bb_hodotdc_clus_etof);
   fChain->SetBranchAddress("bb.hodotdc.clus.etof", bb_hodotdc_clus_etof, &b_bb_hodotdc_clus_etof);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.id", &Ndata_bb_hodotdc_clus_id, &b_Ndata_bb_hodotdc_clus_id);
   fChain->SetBranchAddress("bb.hodotdc.clus.id", bb_hodotdc_clus_id, &b_bb_hodotdc_clus_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.size", &Ndata_bb_hodotdc_clus_size, &b_Ndata_bb_hodotdc_clus_size);
   fChain->SetBranchAddress("bb.hodotdc.clus.size", bb_hodotdc_clus_size, &b_bb_hodotdc_clus_size);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.tdiff", &Ndata_bb_hodotdc_clus_tdiff, &b_Ndata_bb_hodotdc_clus_tdiff);
   fChain->SetBranchAddress("bb.hodotdc.clus.tdiff", bb_hodotdc_clus_tdiff, &b_bb_hodotdc_clus_tdiff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.tfinal", &Ndata_bb_hodotdc_clus_tfinal, &b_Ndata_bb_hodotdc_clus_tfinal);
   fChain->SetBranchAddress("bb.hodotdc.clus.tfinal", bb_hodotdc_clus_tfinal, &b_bb_hodotdc_clus_tfinal);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.tleft", &Ndata_bb_hodotdc_clus_tleft, &b_Ndata_bb_hodotdc_clus_tleft);
   fChain->SetBranchAddress("bb.hodotdc.clus.tleft", bb_hodotdc_clus_tleft, &b_bb_hodotdc_clus_tleft);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.tmean", &Ndata_bb_hodotdc_clus_tmean, &b_Ndata_bb_hodotdc_clus_tmean);
   fChain->SetBranchAddress("bb.hodotdc.clus.tmean", bb_hodotdc_clus_tmean, &b_bb_hodotdc_clus_tmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.tmeanRFcorr", &Ndata_bb_hodotdc_clus_tmeanRFcorr, &b_Ndata_bb_hodotdc_clus_tmeanRFcorr);
   fChain->SetBranchAddress("bb.hodotdc.clus.tmeanRFcorr", bb_hodotdc_clus_tmeanRFcorr, &b_bb_hodotdc_clus_tmeanRFcorr);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.totleft", &Ndata_bb_hodotdc_clus_totleft, &b_Ndata_bb_hodotdc_clus_totleft);
   fChain->SetBranchAddress("bb.hodotdc.clus.totleft", bb_hodotdc_clus_totleft, &b_bb_hodotdc_clus_totleft);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.totmean", &Ndata_bb_hodotdc_clus_totmean, &b_Ndata_bb_hodotdc_clus_totmean);
   fChain->SetBranchAddress("bb.hodotdc.clus.totmean", bb_hodotdc_clus_totmean, &b_bb_hodotdc_clus_totmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.totright", &Ndata_bb_hodotdc_clus_totright, &b_Ndata_bb_hodotdc_clus_totright);
   fChain->SetBranchAddress("bb.hodotdc.clus.totright", bb_hodotdc_clus_totright, &b_bb_hodotdc_clus_totright);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.trackindex", &Ndata_bb_hodotdc_clus_trackindex, &b_Ndata_bb_hodotdc_clus_trackindex);
   fChain->SetBranchAddress("bb.hodotdc.clus.trackindex", bb_hodotdc_clus_trackindex, &b_bb_hodotdc_clus_trackindex);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.tright", &Ndata_bb_hodotdc_clus_tright, &b_Ndata_bb_hodotdc_clus_tright);
   fChain->SetBranchAddress("bb.hodotdc.clus.tright", bb_hodotdc_clus_tright, &b_bb_hodotdc_clus_tright);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.xmean", &Ndata_bb_hodotdc_clus_xmean, &b_Ndata_bb_hodotdc_clus_xmean);
   fChain->SetBranchAddress("bb.hodotdc.clus.xmean", bb_hodotdc_clus_xmean, &b_bb_hodotdc_clus_xmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.ymean", &Ndata_bb_hodotdc_clus_ymean, &b_Ndata_bb_hodotdc_clus_ymean);
   fChain->SetBranchAddress("bb.hodotdc.clus.ymean", bb_hodotdc_clus_ymean, &b_bb_hodotdc_clus_ymean);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.adctime", &Ndata_bb_ps_clus_adctime, &b_Ndata_bb_ps_clus_adctime);
   fChain->SetBranchAddress("bb.ps.clus.adctime", bb_ps_clus_adctime, &b_bb_ps_clus_adctime);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.again", &Ndata_bb_ps_clus_again, &b_Ndata_bb_ps_clus_again);
   fChain->SetBranchAddress("bb.ps.clus.again", bb_ps_clus_again, &b_bb_ps_clus_again);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.atimeblk", &Ndata_bb_ps_clus_atimeblk, &b_Ndata_bb_ps_clus_atimeblk);
   fChain->SetBranchAddress("bb.ps.clus.atimeblk", bb_ps_clus_atimeblk, &b_bb_ps_clus_atimeblk);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.col", &Ndata_bb_ps_clus_col, &b_Ndata_bb_ps_clus_col);
   fChain->SetBranchAddress("bb.ps.clus.col", bb_ps_clus_col, &b_bb_ps_clus_col);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.col_goodtdc", &Ndata_bb_ps_clus_col_goodtdc, &b_Ndata_bb_ps_clus_col_goodtdc);
   fChain->SetBranchAddress("bb.ps.clus.col_goodtdc", bb_ps_clus_col_goodtdc, &b_bb_ps_clus_col_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.e", &Ndata_bb_ps_clus_e, &b_Ndata_bb_ps_clus_e);
   fChain->SetBranchAddress("bb.ps.clus.e", bb_ps_clus_e, &b_bb_ps_clus_e);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.e_goodtdc", &Ndata_bb_ps_clus_e_goodtdc, &b_Ndata_bb_ps_clus_e_goodtdc);
   fChain->SetBranchAddress("bb.ps.clus.e_goodtdc", bb_ps_clus_e_goodtdc, &b_bb_ps_clus_e_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.eblk", &Ndata_bb_ps_clus_eblk, &b_Ndata_bb_ps_clus_eblk);
   fChain->SetBranchAddress("bb.ps.clus.eblk", bb_ps_clus_eblk, &b_bb_ps_clus_eblk);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.eblk_goodtdc", &Ndata_bb_ps_clus_eblk_goodtdc, &b_Ndata_bb_ps_clus_eblk_goodtdc);
   fChain->SetBranchAddress("bb.ps.clus.eblk_goodtdc", bb_ps_clus_eblk_goodtdc, &b_bb_ps_clus_eblk_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.id", &Ndata_bb_ps_clus_id, &b_Ndata_bb_ps_clus_id);
   fChain->SetBranchAddress("bb.ps.clus.id", bb_ps_clus_id, &b_bb_ps_clus_id);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.id_goodtdc", &Ndata_bb_ps_clus_id_goodtdc, &b_Ndata_bb_ps_clus_id_goodtdc);
   fChain->SetBranchAddress("bb.ps.clus.id_goodtdc", bb_ps_clus_id_goodtdc, &b_bb_ps_clus_id_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.nblk", &Ndata_bb_ps_clus_nblk, &b_Ndata_bb_ps_clus_nblk);
   fChain->SetBranchAddress("bb.ps.clus.nblk", bb_ps_clus_nblk, &b_bb_ps_clus_nblk);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.nblk_goodtdc", &Ndata_bb_ps_clus_nblk_goodtdc, &b_Ndata_bb_ps_clus_nblk_goodtdc);
   fChain->SetBranchAddress("bb.ps.clus.nblk_goodtdc", bb_ps_clus_nblk_goodtdc, &b_bb_ps_clus_nblk_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.row", &Ndata_bb_ps_clus_row, &b_Ndata_bb_ps_clus_row);
   fChain->SetBranchAddress("bb.ps.clus.row", bb_ps_clus_row, &b_bb_ps_clus_row);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.row_goodtdc", &Ndata_bb_ps_clus_row_goodtdc, &b_Ndata_bb_ps_clus_row_goodtdc);
   fChain->SetBranchAddress("bb.ps.clus.row_goodtdc", bb_ps_clus_row_goodtdc, &b_bb_ps_clus_row_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.tdctime", &Ndata_bb_ps_clus_tdctime, &b_Ndata_bb_ps_clus_tdctime);
   fChain->SetBranchAddress("bb.ps.clus.tdctime", bb_ps_clus_tdctime, &b_bb_ps_clus_tdctime);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.tdctime_tw", &Ndata_bb_ps_clus_tdctime_tw, &b_Ndata_bb_ps_clus_tdctime_tw);
   fChain->SetBranchAddress("bb.ps.clus.tdctime_tw", bb_ps_clus_tdctime_tw, &b_bb_ps_clus_tdctime_tw);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.tdctimeblk", &Ndata_bb_ps_clus_tdctimeblk, &b_Ndata_bb_ps_clus_tdctimeblk);
   fChain->SetBranchAddress("bb.ps.clus.tdctimeblk", bb_ps_clus_tdctimeblk, &b_bb_ps_clus_tdctimeblk);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.tdctimeblk_tw", &Ndata_bb_ps_clus_tdctimeblk_tw, &b_Ndata_bb_ps_clus_tdctimeblk_tw);
   fChain->SetBranchAddress("bb.ps.clus.tdctimeblk_tw", bb_ps_clus_tdctimeblk_tw, &b_bb_ps_clus_tdctimeblk_tw);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.x", &Ndata_bb_ps_clus_x, &b_Ndata_bb_ps_clus_x);
   fChain->SetBranchAddress("bb.ps.clus.x", bb_ps_clus_x, &b_bb_ps_clus_x);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.y", &Ndata_bb_ps_clus_y, &b_Ndata_bb_ps_clus_y);
   fChain->SetBranchAddress("bb.ps.clus.y", bb_ps_clus_y, &b_bb_ps_clus_y);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.again", &Ndata_bb_ps_clus_blk_again, &b_Ndata_bb_ps_clus_blk_again);
   fChain->SetBranchAddress("bb.ps.clus_blk.again", bb_ps_clus_blk_again, &b_bb_ps_clus_blk_again);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.atime", &Ndata_bb_ps_clus_blk_atime, &b_Ndata_bb_ps_clus_blk_atime);
   fChain->SetBranchAddress("bb.ps.clus_blk.atime", bb_ps_clus_blk_atime, &b_bb_ps_clus_blk_atime);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.col", &Ndata_bb_ps_clus_blk_col, &b_Ndata_bb_ps_clus_blk_col);
   fChain->SetBranchAddress("bb.ps.clus_blk.col", bb_ps_clus_blk_col, &b_bb_ps_clus_blk_col);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.e", &Ndata_bb_ps_clus_blk_e, &b_Ndata_bb_ps_clus_blk_e);
   fChain->SetBranchAddress("bb.ps.clus_blk.e", bb_ps_clus_blk_e, &b_bb_ps_clus_blk_e);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.id", &Ndata_bb_ps_clus_blk_id, &b_Ndata_bb_ps_clus_blk_id);
   fChain->SetBranchAddress("bb.ps.clus_blk.id", bb_ps_clus_blk_id, &b_bb_ps_clus_blk_id);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.row", &Ndata_bb_ps_clus_blk_row, &b_Ndata_bb_ps_clus_blk_row);
   fChain->SetBranchAddress("bb.ps.clus_blk.row", bb_ps_clus_blk_row, &b_bb_ps_clus_blk_row);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.tdctime", &Ndata_bb_ps_clus_blk_tdctime, &b_Ndata_bb_ps_clus_blk_tdctime);
   fChain->SetBranchAddress("bb.ps.clus_blk.tdctime", bb_ps_clus_blk_tdctime, &b_bb_ps_clus_blk_tdctime);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.tdctime_tw", &Ndata_bb_ps_clus_blk_tdctime_tw, &b_Ndata_bb_ps_clus_blk_tdctime_tw);
   fChain->SetBranchAddress("bb.ps.clus_blk.tdctime_tw", bb_ps_clus_blk_tdctime_tw, &b_bb_ps_clus_blk_tdctime_tw);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.x", &Ndata_bb_ps_clus_blk_x, &b_Ndata_bb_ps_clus_blk_x);
   fChain->SetBranchAddress("bb.ps.clus_blk.x", bb_ps_clus_blk_x, &b_bb_ps_clus_blk_x);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.y", &Ndata_bb_ps_clus_blk_y, &b_Ndata_bb_ps_clus_blk_y);
   fChain->SetBranchAddress("bb.ps.clus_blk.y", bb_ps_clus_blk_y, &b_bb_ps_clus_blk_y);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.adctime", &Ndata_bb_sh_clus_adctime, &b_Ndata_bb_sh_clus_adctime);
   fChain->SetBranchAddress("bb.sh.clus.adctime", bb_sh_clus_adctime, &b_bb_sh_clus_adctime);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.again", &Ndata_bb_sh_clus_again, &b_Ndata_bb_sh_clus_again);
   fChain->SetBranchAddress("bb.sh.clus.again", bb_sh_clus_again, &b_bb_sh_clus_again);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.atimeblk", &Ndata_bb_sh_clus_atimeblk, &b_Ndata_bb_sh_clus_atimeblk);
   fChain->SetBranchAddress("bb.sh.clus.atimeblk", bb_sh_clus_atimeblk, &b_bb_sh_clus_atimeblk);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.col", &Ndata_bb_sh_clus_col, &b_Ndata_bb_sh_clus_col);
   fChain->SetBranchAddress("bb.sh.clus.col", bb_sh_clus_col, &b_bb_sh_clus_col);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.col_goodtdc", &Ndata_bb_sh_clus_col_goodtdc, &b_Ndata_bb_sh_clus_col_goodtdc);
   fChain->SetBranchAddress("bb.sh.clus.col_goodtdc", bb_sh_clus_col_goodtdc, &b_bb_sh_clus_col_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.e", &Ndata_bb_sh_clus_e, &b_Ndata_bb_sh_clus_e);
   fChain->SetBranchAddress("bb.sh.clus.e", bb_sh_clus_e, &b_bb_sh_clus_e);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.e_goodtdc", &Ndata_bb_sh_clus_e_goodtdc, &b_Ndata_bb_sh_clus_e_goodtdc);
   fChain->SetBranchAddress("bb.sh.clus.e_goodtdc", bb_sh_clus_e_goodtdc, &b_bb_sh_clus_e_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.eblk", &Ndata_bb_sh_clus_eblk, &b_Ndata_bb_sh_clus_eblk);
   fChain->SetBranchAddress("bb.sh.clus.eblk", bb_sh_clus_eblk, &b_bb_sh_clus_eblk);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.eblk_goodtdc", &Ndata_bb_sh_clus_eblk_goodtdc, &b_Ndata_bb_sh_clus_eblk_goodtdc);
   fChain->SetBranchAddress("bb.sh.clus.eblk_goodtdc", bb_sh_clus_eblk_goodtdc, &b_bb_sh_clus_eblk_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.id", &Ndata_bb_sh_clus_id, &b_Ndata_bb_sh_clus_id);
   fChain->SetBranchAddress("bb.sh.clus.id", bb_sh_clus_id, &b_bb_sh_clus_id);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.id_goodtdc", &Ndata_bb_sh_clus_id_goodtdc, &b_Ndata_bb_sh_clus_id_goodtdc);
   fChain->SetBranchAddress("bb.sh.clus.id_goodtdc", bb_sh_clus_id_goodtdc, &b_bb_sh_clus_id_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.nblk", &Ndata_bb_sh_clus_nblk, &b_Ndata_bb_sh_clus_nblk);
   fChain->SetBranchAddress("bb.sh.clus.nblk", bb_sh_clus_nblk, &b_bb_sh_clus_nblk);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.nblk_goodtdc", &Ndata_bb_sh_clus_nblk_goodtdc, &b_Ndata_bb_sh_clus_nblk_goodtdc);
   fChain->SetBranchAddress("bb.sh.clus.nblk_goodtdc", bb_sh_clus_nblk_goodtdc, &b_bb_sh_clus_nblk_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.row", &Ndata_bb_sh_clus_row, &b_Ndata_bb_sh_clus_row);
   fChain->SetBranchAddress("bb.sh.clus.row", bb_sh_clus_row, &b_bb_sh_clus_row);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.row_goodtdc", &Ndata_bb_sh_clus_row_goodtdc, &b_Ndata_bb_sh_clus_row_goodtdc);
   fChain->SetBranchAddress("bb.sh.clus.row_goodtdc", bb_sh_clus_row_goodtdc, &b_bb_sh_clus_row_goodtdc);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.tdctime", &Ndata_bb_sh_clus_tdctime, &b_Ndata_bb_sh_clus_tdctime);
   fChain->SetBranchAddress("bb.sh.clus.tdctime", bb_sh_clus_tdctime, &b_bb_sh_clus_tdctime);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.tdctime_tw", &Ndata_bb_sh_clus_tdctime_tw, &b_Ndata_bb_sh_clus_tdctime_tw);
   fChain->SetBranchAddress("bb.sh.clus.tdctime_tw", bb_sh_clus_tdctime_tw, &b_bb_sh_clus_tdctime_tw);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.tdctimeblk", &Ndata_bb_sh_clus_tdctimeblk, &b_Ndata_bb_sh_clus_tdctimeblk);
   fChain->SetBranchAddress("bb.sh.clus.tdctimeblk", bb_sh_clus_tdctimeblk, &b_bb_sh_clus_tdctimeblk);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.tdctimeblk_tw", &Ndata_bb_sh_clus_tdctimeblk_tw, &b_Ndata_bb_sh_clus_tdctimeblk_tw);
   fChain->SetBranchAddress("bb.sh.clus.tdctimeblk_tw", bb_sh_clus_tdctimeblk_tw, &b_bb_sh_clus_tdctimeblk_tw);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.x", &Ndata_bb_sh_clus_x, &b_Ndata_bb_sh_clus_x);
   fChain->SetBranchAddress("bb.sh.clus.x", bb_sh_clus_x, &b_bb_sh_clus_x);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.y", &Ndata_bb_sh_clus_y, &b_Ndata_bb_sh_clus_y);
   fChain->SetBranchAddress("bb.sh.clus.y", bb_sh_clus_y, &b_bb_sh_clus_y);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.again", &Ndata_bb_sh_clus_blk_again, &b_Ndata_bb_sh_clus_blk_again);
   fChain->SetBranchAddress("bb.sh.clus_blk.again", bb_sh_clus_blk_again, &b_bb_sh_clus_blk_again);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.atime", &Ndata_bb_sh_clus_blk_atime, &b_Ndata_bb_sh_clus_blk_atime);
   fChain->SetBranchAddress("bb.sh.clus_blk.atime", bb_sh_clus_blk_atime, &b_bb_sh_clus_blk_atime);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.col", &Ndata_bb_sh_clus_blk_col, &b_Ndata_bb_sh_clus_blk_col);
   fChain->SetBranchAddress("bb.sh.clus_blk.col", bb_sh_clus_blk_col, &b_bb_sh_clus_blk_col);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.e", &Ndata_bb_sh_clus_blk_e, &b_Ndata_bb_sh_clus_blk_e);
   fChain->SetBranchAddress("bb.sh.clus_blk.e", bb_sh_clus_blk_e, &b_bb_sh_clus_blk_e);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.id", &Ndata_bb_sh_clus_blk_id, &b_Ndata_bb_sh_clus_blk_id);
   fChain->SetBranchAddress("bb.sh.clus_blk.id", bb_sh_clus_blk_id, &b_bb_sh_clus_blk_id);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.row", &Ndata_bb_sh_clus_blk_row, &b_Ndata_bb_sh_clus_blk_row);
   fChain->SetBranchAddress("bb.sh.clus_blk.row", bb_sh_clus_blk_row, &b_bb_sh_clus_blk_row);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.tdctime", &Ndata_bb_sh_clus_blk_tdctime, &b_Ndata_bb_sh_clus_blk_tdctime);
   fChain->SetBranchAddress("bb.sh.clus_blk.tdctime", bb_sh_clus_blk_tdctime, &b_bb_sh_clus_blk_tdctime);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.tdctime_tw", &Ndata_bb_sh_clus_blk_tdctime_tw, &b_Ndata_bb_sh_clus_blk_tdctime_tw);
   fChain->SetBranchAddress("bb.sh.clus_blk.tdctime_tw", bb_sh_clus_blk_tdctime_tw, &b_bb_sh_clus_blk_tdctime_tw);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.x", &Ndata_bb_sh_clus_blk_x, &b_Ndata_bb_sh_clus_blk_x);
   fChain->SetBranchAddress("bb.sh.clus_blk.x", bb_sh_clus_blk_x, &b_bb_sh_clus_blk_x);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.y", &Ndata_bb_sh_clus_blk_y, &b_Ndata_bb_sh_clus_blk_y);
   fChain->SetBranchAddress("bb.sh.clus_blk.y", bb_sh_clus_blk_y, &b_bb_sh_clus_blk_y);
   fChain->SetBranchAddress("Ndata.bb.tdctrig.tdc", &Ndata_bb_tdctrig_tdc, &b_Ndata_bb_tdctrig_tdc);
   fChain->SetBranchAddress("bb.tdctrig.tdc", bb_tdctrig_tdc, &b_bb_tdctrig_tdc);
   fChain->SetBranchAddress("Ndata.bb.tdctrig.tdcelemID", &Ndata_bb_tdctrig_tdcelemID, &b_Ndata_bb_tdctrig_tdcelemID);
   fChain->SetBranchAddress("bb.tdctrig.tdcelemID", bb_tdctrig_tdcelemID, &b_bb_tdctrig_tdcelemID);
   fChain->SetBranchAddress("Ndata.bb.tr.beta", &Ndata_bb_tr_beta, &b_Ndata_bb_tr_beta);
   fChain->SetBranchAddress("bb.tr.beta", bb_tr_beta, &b_bb_tr_beta);
   fChain->SetBranchAddress("Ndata.bb.tr.chi2", &Ndata_bb_tr_chi2, &b_Ndata_bb_tr_chi2);
   fChain->SetBranchAddress("bb.tr.chi2", bb_tr_chi2, &b_bb_tr_chi2);
   fChain->SetBranchAddress("Ndata.bb.tr.d_ph", &Ndata_bb_tr_d_ph, &b_Ndata_bb_tr_d_ph);
   fChain->SetBranchAddress("bb.tr.d_ph", bb_tr_d_ph, &b_bb_tr_d_ph);
   fChain->SetBranchAddress("Ndata.bb.tr.d_th", &Ndata_bb_tr_d_th, &b_Ndata_bb_tr_d_th);
   fChain->SetBranchAddress("bb.tr.d_th", bb_tr_d_th, &b_bb_tr_d_th);
   fChain->SetBranchAddress("Ndata.bb.tr.d_x", &Ndata_bb_tr_d_x, &b_Ndata_bb_tr_d_x);
   fChain->SetBranchAddress("bb.tr.d_x", bb_tr_d_x, &b_bb_tr_d_x);
   fChain->SetBranchAddress("Ndata.bb.tr.d_y", &Ndata_bb_tr_d_y, &b_Ndata_bb_tr_d_y);
   fChain->SetBranchAddress("bb.tr.d_y", bb_tr_d_y, &b_bb_tr_d_y);
   fChain->SetBranchAddress("Ndata.bb.tr.dbeta", &Ndata_bb_tr_dbeta, &b_Ndata_bb_tr_dbeta);
   fChain->SetBranchAddress("bb.tr.dbeta", bb_tr_dbeta, &b_bb_tr_dbeta);
   fChain->SetBranchAddress("Ndata.bb.tr.dtime", &Ndata_bb_tr_dtime, &b_Ndata_bb_tr_dtime);
   fChain->SetBranchAddress("bb.tr.dtime", bb_tr_dtime, &b_bb_tr_dtime);
   fChain->SetBranchAddress("Ndata.bb.tr.flag", &Ndata_bb_tr_flag, &b_Ndata_bb_tr_flag);
   fChain->SetBranchAddress("bb.tr.flag", bb_tr_flag, &b_bb_tr_flag);
   fChain->SetBranchAddress("Ndata.bb.tr.ndof", &Ndata_bb_tr_ndof, &b_Ndata_bb_tr_ndof);
   fChain->SetBranchAddress("bb.tr.ndof", bb_tr_ndof, &b_bb_tr_ndof);
   fChain->SetBranchAddress("Ndata.bb.tr.p", &Ndata_bb_tr_p, &b_Ndata_bb_tr_p);
   fChain->SetBranchAddress("bb.tr.p", bb_tr_p, &b_bb_tr_p);
   fChain->SetBranchAddress("Ndata.bb.tr.pathl", &Ndata_bb_tr_pathl, &b_Ndata_bb_tr_pathl);
   fChain->SetBranchAddress("bb.tr.pathl", bb_tr_pathl, &b_bb_tr_pathl);
   fChain->SetBranchAddress("Ndata.bb.tr.ph", &Ndata_bb_tr_ph, &b_Ndata_bb_tr_ph);
   fChain->SetBranchAddress("bb.tr.ph", bb_tr_ph, &b_bb_tr_ph);
   fChain->SetBranchAddress("Ndata.bb.tr.px", &Ndata_bb_tr_px, &b_Ndata_bb_tr_px);
   fChain->SetBranchAddress("bb.tr.px", bb_tr_px, &b_bb_tr_px);
   fChain->SetBranchAddress("Ndata.bb.tr.py", &Ndata_bb_tr_py, &b_Ndata_bb_tr_py);
   fChain->SetBranchAddress("bb.tr.py", bb_tr_py, &b_bb_tr_py);
   fChain->SetBranchAddress("Ndata.bb.tr.pz", &Ndata_bb_tr_pz, &b_Ndata_bb_tr_pz);
   fChain->SetBranchAddress("bb.tr.pz", bb_tr_pz, &b_bb_tr_pz);
   fChain->SetBranchAddress("Ndata.bb.tr.r_ph", &Ndata_bb_tr_r_ph, &b_Ndata_bb_tr_r_ph);
   fChain->SetBranchAddress("bb.tr.r_ph", bb_tr_r_ph, &b_bb_tr_r_ph);
   fChain->SetBranchAddress("Ndata.bb.tr.r_th", &Ndata_bb_tr_r_th, &b_Ndata_bb_tr_r_th);
   fChain->SetBranchAddress("bb.tr.r_th", bb_tr_r_th, &b_bb_tr_r_th);
   fChain->SetBranchAddress("Ndata.bb.tr.r_x", &Ndata_bb_tr_r_x, &b_Ndata_bb_tr_r_x);
   fChain->SetBranchAddress("bb.tr.r_x", bb_tr_r_x, &b_bb_tr_r_x);
   fChain->SetBranchAddress("Ndata.bb.tr.r_y", &Ndata_bb_tr_r_y, &b_Ndata_bb_tr_r_y);
   fChain->SetBranchAddress("bb.tr.r_y", bb_tr_r_y, &b_bb_tr_r_y);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_dp", &Ndata_bb_tr_tg_dp, &b_Ndata_bb_tr_tg_dp);
   fChain->SetBranchAddress("bb.tr.tg_dp", bb_tr_tg_dp, &b_bb_tr_tg_dp);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_ph", &Ndata_bb_tr_tg_ph, &b_Ndata_bb_tr_tg_ph);
   fChain->SetBranchAddress("bb.tr.tg_ph", bb_tr_tg_ph, &b_bb_tr_tg_ph);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_th", &Ndata_bb_tr_tg_th, &b_Ndata_bb_tr_tg_th);
   fChain->SetBranchAddress("bb.tr.tg_th", bb_tr_tg_th, &b_bb_tr_tg_th);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_x", &Ndata_bb_tr_tg_x, &b_Ndata_bb_tr_tg_x);
   fChain->SetBranchAddress("bb.tr.tg_x", bb_tr_tg_x, &b_bb_tr_tg_x);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_y", &Ndata_bb_tr_tg_y, &b_Ndata_bb_tr_tg_y);
   fChain->SetBranchAddress("bb.tr.tg_y", bb_tr_tg_y, &b_bb_tr_tg_y);
   fChain->SetBranchAddress("Ndata.bb.tr.th", &Ndata_bb_tr_th, &b_Ndata_bb_tr_th);
   fChain->SetBranchAddress("bb.tr.th", bb_tr_th, &b_bb_tr_th);
   fChain->SetBranchAddress("Ndata.bb.tr.time", &Ndata_bb_tr_time, &b_Ndata_bb_tr_time);
   fChain->SetBranchAddress("bb.tr.time", bb_tr_time, &b_bb_tr_time);
   fChain->SetBranchAddress("Ndata.bb.tr.vx", &Ndata_bb_tr_vx, &b_Ndata_bb_tr_vx);
   fChain->SetBranchAddress("bb.tr.vx", bb_tr_vx, &b_bb_tr_vx);
   fChain->SetBranchAddress("Ndata.bb.tr.vy", &Ndata_bb_tr_vy, &b_Ndata_bb_tr_vy);
   fChain->SetBranchAddress("bb.tr.vy", bb_tr_vy, &b_bb_tr_vy);
   fChain->SetBranchAddress("Ndata.bb.tr.vz", &Ndata_bb_tr_vz, &b_Ndata_bb_tr_vz);
   fChain->SetBranchAddress("bb.tr.vz", bb_tr_vz, &b_bb_tr_vz);
   fChain->SetBranchAddress("Ndata.bb.tr.x", &Ndata_bb_tr_x, &b_Ndata_bb_tr_x);
   fChain->SetBranchAddress("bb.tr.x", bb_tr_x, &b_bb_tr_x);
   fChain->SetBranchAddress("Ndata.bb.tr.y", &Ndata_bb_tr_y, &b_Ndata_bb_tr_y);
   fChain->SetBranchAddress("bb.tr.y", bb_tr_y, &b_bb_tr_y);
   fChain->SetBranchAddress("Ndata.bb.x_bcp", &Ndata_bb_x_bcp, &b_Ndata_bb_x_bcp);
   fChain->SetBranchAddress("bb.x_bcp", bb_x_bcp, &b_bb_x_bcp);
   fChain->SetBranchAddress("Ndata.bb.x_fcp", &Ndata_bb_x_fcp, &b_Ndata_bb_x_fcp);
   fChain->SetBranchAddress("bb.x_fcp", bb_x_fcp, &b_bb_x_fcp);
   fChain->SetBranchAddress("Ndata.bb.y_bcp", &Ndata_bb_y_bcp, &b_Ndata_bb_y_bcp);
   fChain->SetBranchAddress("bb.y_bcp", bb_y_bcp, &b_bb_y_bcp);
   fChain->SetBranchAddress("Ndata.bb.y_fcp", &Ndata_bb_y_fcp, &b_Ndata_bb_y_fcp);
   fChain->SetBranchAddress("bb.y_fcp", bb_y_fcp, &b_bb_y_fcp);
   fChain->SetBranchAddress("Ndata.bb.z_bcp", &Ndata_bb_z_bcp, &b_Ndata_bb_z_bcp);
   fChain->SetBranchAddress("bb.z_bcp", bb_z_bcp, &b_bb_z_bcp);
   fChain->SetBranchAddress("Ndata.bb.z_fcp", &Ndata_bb_z_fcp, &b_Ndata_bb_z_fcp);
   fChain->SetBranchAddress("bb.z_fcp", bb_z_fcp, &b_bb_z_fcp);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCU", &Ndata_sbs_gemCeF_hit_ADCU, &b_Ndata_sbs_gemCeF_hit_ADCU);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCU", sbs_gemCeF_hit_ADCU, &b_sbs_gemCeF_hit_ADCU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCU_deconv", &Ndata_sbs_gemCeF_hit_ADCU_deconv, &b_Ndata_sbs_gemCeF_hit_ADCU_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCU_deconv", sbs_gemCeF_hit_ADCU_deconv, &b_sbs_gemCeF_hit_ADCU_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCV", &Ndata_sbs_gemCeF_hit_ADCV, &b_Ndata_sbs_gemCeF_hit_ADCV);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCV", sbs_gemCeF_hit_ADCV, &b_sbs_gemCeF_hit_ADCV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCV_deconv", &Ndata_sbs_gemCeF_hit_ADCV_deconv, &b_Ndata_sbs_gemCeF_hit_ADCV_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCV_deconv", sbs_gemCeF_hit_ADCV_deconv, &b_sbs_gemCeF_hit_ADCV_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCasym", &Ndata_sbs_gemCeF_hit_ADCasym, &b_Ndata_sbs_gemCeF_hit_ADCasym);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCasym", sbs_gemCeF_hit_ADCasym, &b_sbs_gemCeF_hit_ADCasym);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCasym_deconv", &Ndata_sbs_gemCeF_hit_ADCasym_deconv, &b_Ndata_sbs_gemCeF_hit_ADCasym_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCasym_deconv", sbs_gemCeF_hit_ADCasym_deconv, &b_sbs_gemCeF_hit_ADCasym_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCavg", &Ndata_sbs_gemCeF_hit_ADCavg, &b_Ndata_sbs_gemCeF_hit_ADCavg);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCavg", sbs_gemCeF_hit_ADCavg, &b_sbs_gemCeF_hit_ADCavg);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCavg_deconv", &Ndata_sbs_gemCeF_hit_ADCavg_deconv, &b_Ndata_sbs_gemCeF_hit_ADCavg_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCavg_deconv", sbs_gemCeF_hit_ADCavg_deconv, &b_sbs_gemCeF_hit_ADCavg_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac0_Umax", &Ndata_sbs_gemCeF_hit_ADCfrac0_Umax, &b_Ndata_sbs_gemCeF_hit_ADCfrac0_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac0_Umax", sbs_gemCeF_hit_ADCfrac0_Umax, &b_sbs_gemCeF_hit_ADCfrac0_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac0_Vmax", &Ndata_sbs_gemCeF_hit_ADCfrac0_Vmax, &b_Ndata_sbs_gemCeF_hit_ADCfrac0_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac0_Vmax", sbs_gemCeF_hit_ADCfrac0_Vmax, &b_sbs_gemCeF_hit_ADCfrac0_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac1_Umax", &Ndata_sbs_gemCeF_hit_ADCfrac1_Umax, &b_Ndata_sbs_gemCeF_hit_ADCfrac1_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac1_Umax", sbs_gemCeF_hit_ADCfrac1_Umax, &b_sbs_gemCeF_hit_ADCfrac1_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac1_Vmax", &Ndata_sbs_gemCeF_hit_ADCfrac1_Vmax, &b_Ndata_sbs_gemCeF_hit_ADCfrac1_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac1_Vmax", sbs_gemCeF_hit_ADCfrac1_Vmax, &b_sbs_gemCeF_hit_ADCfrac1_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac2_Umax", &Ndata_sbs_gemCeF_hit_ADCfrac2_Umax, &b_Ndata_sbs_gemCeF_hit_ADCfrac2_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac2_Umax", sbs_gemCeF_hit_ADCfrac2_Umax, &b_sbs_gemCeF_hit_ADCfrac2_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac2_Vmax", &Ndata_sbs_gemCeF_hit_ADCfrac2_Vmax, &b_Ndata_sbs_gemCeF_hit_ADCfrac2_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac2_Vmax", sbs_gemCeF_hit_ADCfrac2_Vmax, &b_sbs_gemCeF_hit_ADCfrac2_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac3_Umax", &Ndata_sbs_gemCeF_hit_ADCfrac3_Umax, &b_Ndata_sbs_gemCeF_hit_ADCfrac3_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac3_Umax", sbs_gemCeF_hit_ADCfrac3_Umax, &b_sbs_gemCeF_hit_ADCfrac3_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac3_Vmax", &Ndata_sbs_gemCeF_hit_ADCfrac3_Vmax, &b_Ndata_sbs_gemCeF_hit_ADCfrac3_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac3_Vmax", sbs_gemCeF_hit_ADCfrac3_Vmax, &b_sbs_gemCeF_hit_ADCfrac3_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac4_Umax", &Ndata_sbs_gemCeF_hit_ADCfrac4_Umax, &b_Ndata_sbs_gemCeF_hit_ADCfrac4_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac4_Umax", sbs_gemCeF_hit_ADCfrac4_Umax, &b_sbs_gemCeF_hit_ADCfrac4_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac4_Vmax", &Ndata_sbs_gemCeF_hit_ADCfrac4_Vmax, &b_Ndata_sbs_gemCeF_hit_ADCfrac4_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac4_Vmax", sbs_gemCeF_hit_ADCfrac4_Vmax, &b_sbs_gemCeF_hit_ADCfrac4_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac5_Umax", &Ndata_sbs_gemCeF_hit_ADCfrac5_Umax, &b_Ndata_sbs_gemCeF_hit_ADCfrac5_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac5_Umax", sbs_gemCeF_hit_ADCfrac5_Umax, &b_sbs_gemCeF_hit_ADCfrac5_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCfrac5_Vmax", &Ndata_sbs_gemCeF_hit_ADCfrac5_Vmax, &b_Ndata_sbs_gemCeF_hit_ADCfrac5_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCfrac5_Vmax", sbs_gemCeF_hit_ADCfrac5_Vmax, &b_sbs_gemCeF_hit_ADCfrac5_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxcomboUclust_deconv", &Ndata_sbs_gemCeF_hit_ADCmaxcomboUclust_deconv, &b_Ndata_sbs_gemCeF_hit_ADCmaxcomboUclust_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxcomboUclust_deconv", sbs_gemCeF_hit_ADCmaxcomboUclust_deconv, &b_sbs_gemCeF_hit_ADCmaxcomboUclust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxcomboVclust_deconv", &Ndata_sbs_gemCeF_hit_ADCmaxcomboVclust_deconv, &b_Ndata_sbs_gemCeF_hit_ADCmaxcomboVclust_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxcomboVclust_deconv", sbs_gemCeF_hit_ADCmaxcomboVclust_deconv, &b_sbs_gemCeF_hit_ADCmaxcomboVclust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxsampU", &Ndata_sbs_gemCeF_hit_ADCmaxsampU, &b_Ndata_sbs_gemCeF_hit_ADCmaxsampU);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxsampU", sbs_gemCeF_hit_ADCmaxsampU, &b_sbs_gemCeF_hit_ADCmaxsampU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxsampUclust", &Ndata_sbs_gemCeF_hit_ADCmaxsampUclust, &b_Ndata_sbs_gemCeF_hit_ADCmaxsampUclust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxsampUclust", sbs_gemCeF_hit_ADCmaxsampUclust, &b_sbs_gemCeF_hit_ADCmaxsampUclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxsampUclust_deconv", &Ndata_sbs_gemCeF_hit_ADCmaxsampUclust_deconv, &b_Ndata_sbs_gemCeF_hit_ADCmaxsampUclust_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxsampUclust_deconv", sbs_gemCeF_hit_ADCmaxsampUclust_deconv, &b_sbs_gemCeF_hit_ADCmaxsampUclust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxsampV", &Ndata_sbs_gemCeF_hit_ADCmaxsampV, &b_Ndata_sbs_gemCeF_hit_ADCmaxsampV);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxsampV", sbs_gemCeF_hit_ADCmaxsampV, &b_sbs_gemCeF_hit_ADCmaxsampV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxsampVclust", &Ndata_sbs_gemCeF_hit_ADCmaxsampVclust, &b_Ndata_sbs_gemCeF_hit_ADCmaxsampVclust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxsampVclust", sbs_gemCeF_hit_ADCmaxsampVclust, &b_sbs_gemCeF_hit_ADCmaxsampVclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxsampVclust_deconv", &Ndata_sbs_gemCeF_hit_ADCmaxsampVclust_deconv, &b_Ndata_sbs_gemCeF_hit_ADCmaxsampVclust_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxsampVclust_deconv", sbs_gemCeF_hit_ADCmaxsampVclust_deconv, &b_sbs_gemCeF_hit_ADCmaxsampVclust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxstripU", &Ndata_sbs_gemCeF_hit_ADCmaxstripU, &b_Ndata_sbs_gemCeF_hit_ADCmaxstripU);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxstripU", sbs_gemCeF_hit_ADCmaxstripU, &b_sbs_gemCeF_hit_ADCmaxstripU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ADCmaxstripV", &Ndata_sbs_gemCeF_hit_ADCmaxstripV, &b_Ndata_sbs_gemCeF_hit_ADCmaxstripV);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ADCmaxstripV", sbs_gemCeF_hit_ADCmaxstripV, &b_sbs_gemCeF_hit_ADCmaxstripV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.BUILD_ALL_SAMPLES_U", &Ndata_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_U, &b_Ndata_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_U);
   fChain->SetBranchAddress("sbs.gemCeF.hit.BUILD_ALL_SAMPLES_U", sbs_gemCeF_hit_BUILD_ALL_SAMPLES_U, &b_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.BUILD_ALL_SAMPLES_V", &Ndata_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_V, &b_Ndata_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_V);
   fChain->SetBranchAddress("sbs.gemCeF.hit.BUILD_ALL_SAMPLES_V", sbs_gemCeF_hit_BUILD_ALL_SAMPLES_V, &b_sbs_gemCeF_hit_BUILD_ALL_SAMPLES_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.CM_GOOD_U", &Ndata_sbs_gemCeF_hit_CM_GOOD_U, &b_Ndata_sbs_gemCeF_hit_CM_GOOD_U);
   fChain->SetBranchAddress("sbs.gemCeF.hit.CM_GOOD_U", sbs_gemCeF_hit_CM_GOOD_U, &b_sbs_gemCeF_hit_CM_GOOD_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.CM_GOOD_V", &Ndata_sbs_gemCeF_hit_CM_GOOD_V, &b_Ndata_sbs_gemCeF_hit_CM_GOOD_V);
   fChain->SetBranchAddress("sbs.gemCeF.hit.CM_GOOD_V", sbs_gemCeF_hit_CM_GOOD_V, &b_sbs_gemCeF_hit_CM_GOOD_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC0_Umax", &Ndata_sbs_gemCeF_hit_DeconvADC0_Umax, &b_Ndata_sbs_gemCeF_hit_DeconvADC0_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC0_Umax", sbs_gemCeF_hit_DeconvADC0_Umax, &b_sbs_gemCeF_hit_DeconvADC0_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC0_Vmax", &Ndata_sbs_gemCeF_hit_DeconvADC0_Vmax, &b_Ndata_sbs_gemCeF_hit_DeconvADC0_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC0_Vmax", sbs_gemCeF_hit_DeconvADC0_Vmax, &b_sbs_gemCeF_hit_DeconvADC0_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC1_Umax", &Ndata_sbs_gemCeF_hit_DeconvADC1_Umax, &b_Ndata_sbs_gemCeF_hit_DeconvADC1_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC1_Umax", sbs_gemCeF_hit_DeconvADC1_Umax, &b_sbs_gemCeF_hit_DeconvADC1_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC1_Vmax", &Ndata_sbs_gemCeF_hit_DeconvADC1_Vmax, &b_Ndata_sbs_gemCeF_hit_DeconvADC1_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC1_Vmax", sbs_gemCeF_hit_DeconvADC1_Vmax, &b_sbs_gemCeF_hit_DeconvADC1_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC2_Umax", &Ndata_sbs_gemCeF_hit_DeconvADC2_Umax, &b_Ndata_sbs_gemCeF_hit_DeconvADC2_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC2_Umax", sbs_gemCeF_hit_DeconvADC2_Umax, &b_sbs_gemCeF_hit_DeconvADC2_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC2_Vmax", &Ndata_sbs_gemCeF_hit_DeconvADC2_Vmax, &b_Ndata_sbs_gemCeF_hit_DeconvADC2_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC2_Vmax", sbs_gemCeF_hit_DeconvADC2_Vmax, &b_sbs_gemCeF_hit_DeconvADC2_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC3_Umax", &Ndata_sbs_gemCeF_hit_DeconvADC3_Umax, &b_Ndata_sbs_gemCeF_hit_DeconvADC3_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC3_Umax", sbs_gemCeF_hit_DeconvADC3_Umax, &b_sbs_gemCeF_hit_DeconvADC3_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC3_Vmax", &Ndata_sbs_gemCeF_hit_DeconvADC3_Vmax, &b_Ndata_sbs_gemCeF_hit_DeconvADC3_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC3_Vmax", sbs_gemCeF_hit_DeconvADC3_Vmax, &b_sbs_gemCeF_hit_DeconvADC3_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC4_Umax", &Ndata_sbs_gemCeF_hit_DeconvADC4_Umax, &b_Ndata_sbs_gemCeF_hit_DeconvADC4_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC4_Umax", sbs_gemCeF_hit_DeconvADC4_Umax, &b_sbs_gemCeF_hit_DeconvADC4_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC4_Vmax", &Ndata_sbs_gemCeF_hit_DeconvADC4_Vmax, &b_Ndata_sbs_gemCeF_hit_DeconvADC4_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC4_Vmax", sbs_gemCeF_hit_DeconvADC4_Vmax, &b_sbs_gemCeF_hit_DeconvADC4_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC5_Umax", &Ndata_sbs_gemCeF_hit_DeconvADC5_Umax, &b_Ndata_sbs_gemCeF_hit_DeconvADC5_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC5_Umax", sbs_gemCeF_hit_DeconvADC5_Umax, &b_sbs_gemCeF_hit_DeconvADC5_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADC5_Vmax", &Ndata_sbs_gemCeF_hit_DeconvADC5_Vmax, &b_Ndata_sbs_gemCeF_hit_DeconvADC5_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADC5_Vmax", sbs_gemCeF_hit_DeconvADC5_Vmax, &b_sbs_gemCeF_hit_DeconvADC5_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADCmaxcomboU", &Ndata_sbs_gemCeF_hit_DeconvADCmaxcomboU, &b_Ndata_sbs_gemCeF_hit_DeconvADCmaxcomboU);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADCmaxcomboU", sbs_gemCeF_hit_DeconvADCmaxcomboU, &b_sbs_gemCeF_hit_DeconvADCmaxcomboU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADCmaxcomboV", &Ndata_sbs_gemCeF_hit_DeconvADCmaxcomboV, &b_Ndata_sbs_gemCeF_hit_DeconvADCmaxcomboV);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADCmaxcomboV", sbs_gemCeF_hit_DeconvADCmaxcomboV, &b_sbs_gemCeF_hit_DeconvADCmaxcomboV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADCmaxsampU", &Ndata_sbs_gemCeF_hit_DeconvADCmaxsampU, &b_Ndata_sbs_gemCeF_hit_DeconvADCmaxsampU);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADCmaxsampU", sbs_gemCeF_hit_DeconvADCmaxsampU, &b_sbs_gemCeF_hit_DeconvADCmaxsampU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADCmaxsampV", &Ndata_sbs_gemCeF_hit_DeconvADCmaxsampV, &b_Ndata_sbs_gemCeF_hit_DeconvADCmaxsampV);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADCmaxsampV", sbs_gemCeF_hit_DeconvADCmaxsampV, &b_sbs_gemCeF_hit_DeconvADCmaxsampV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADCmaxstripU", &Ndata_sbs_gemCeF_hit_DeconvADCmaxstripU, &b_Ndata_sbs_gemCeF_hit_DeconvADCmaxstripU);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADCmaxstripU", sbs_gemCeF_hit_DeconvADCmaxstripU, &b_sbs_gemCeF_hit_DeconvADCmaxstripU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.DeconvADCmaxstripV", &Ndata_sbs_gemCeF_hit_DeconvADCmaxstripV, &b_Ndata_sbs_gemCeF_hit_DeconvADCmaxstripV);
   fChain->SetBranchAddress("sbs.gemCeF.hit.DeconvADCmaxstripV", sbs_gemCeF_hit_DeconvADCmaxstripV, &b_sbs_gemCeF_hit_DeconvADCmaxstripV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ENABLE_CM_U", &Ndata_sbs_gemCeF_hit_ENABLE_CM_U, &b_Ndata_sbs_gemCeF_hit_ENABLE_CM_U);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ENABLE_CM_U", sbs_gemCeF_hit_ENABLE_CM_U, &b_sbs_gemCeF_hit_ENABLE_CM_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ENABLE_CM_V", &Ndata_sbs_gemCeF_hit_ENABLE_CM_V, &b_Ndata_sbs_gemCeF_hit_ENABLE_CM_V);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ENABLE_CM_V", sbs_gemCeF_hit_ENABLE_CM_V, &b_sbs_gemCeF_hit_ENABLE_CM_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.TSchi2_Umax", &Ndata_sbs_gemCeF_hit_TSchi2_Umax, &b_Ndata_sbs_gemCeF_hit_TSchi2_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.TSchi2_Umax", sbs_gemCeF_hit_TSchi2_Umax, &b_sbs_gemCeF_hit_TSchi2_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.TSchi2_Vmax", &Ndata_sbs_gemCeF_hit_TSchi2_Vmax, &b_Ndata_sbs_gemCeF_hit_TSchi2_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.TSchi2_Vmax", sbs_gemCeF_hit_TSchi2_Vmax, &b_sbs_gemCeF_hit_TSchi2_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.TSprob_Umax", &Ndata_sbs_gemCeF_hit_TSprob_Umax, &b_Ndata_sbs_gemCeF_hit_TSprob_Umax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.TSprob_Umax", sbs_gemCeF_hit_TSprob_Umax, &b_sbs_gemCeF_hit_TSprob_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.TSprob_Vmax", &Ndata_sbs_gemCeF_hit_TSprob_Vmax, &b_Ndata_sbs_gemCeF_hit_TSprob_Vmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.TSprob_Vmax", sbs_gemCeF_hit_TSprob_Vmax, &b_sbs_gemCeF_hit_TSprob_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.Tavg", &Ndata_sbs_gemCeF_hit_Tavg, &b_Ndata_sbs_gemCeF_hit_Tavg);
   fChain->SetBranchAddress("sbs.gemCeF.hit.Tavg", sbs_gemCeF_hit_Tavg, &b_sbs_gemCeF_hit_Tavg);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.Tavg_corr", &Ndata_sbs_gemCeF_hit_Tavg_corr, &b_Ndata_sbs_gemCeF_hit_Tavg_corr);
   fChain->SetBranchAddress("sbs.gemCeF.hit.Tavg_corr", sbs_gemCeF_hit_Tavg_corr, &b_sbs_gemCeF_hit_Tavg_corr);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.Tavg_deconv", &Ndata_sbs_gemCeF_hit_Tavg_deconv, &b_Ndata_sbs_gemCeF_hit_Tavg_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.Tavg_deconv", sbs_gemCeF_hit_Tavg_deconv, &b_sbs_gemCeF_hit_Tavg_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.Tavg_fit", &Ndata_sbs_gemCeF_hit_Tavg_fit, &b_Ndata_sbs_gemCeF_hit_Tavg_fit);
   fChain->SetBranchAddress("sbs.gemCeF.hit.Tavg_fit", sbs_gemCeF_hit_Tavg_fit, &b_sbs_gemCeF_hit_Tavg_fit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.Ugain", &Ndata_sbs_gemCeF_hit_Ugain, &b_Ndata_sbs_gemCeF_hit_Ugain);
   fChain->SetBranchAddress("sbs.gemCeF.hit.Ugain", sbs_gemCeF_hit_Ugain, &b_sbs_gemCeF_hit_Ugain);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.Utime", &Ndata_sbs_gemCeF_hit_Utime, &b_Ndata_sbs_gemCeF_hit_Utime);
   fChain->SetBranchAddress("sbs.gemCeF.hit.Utime", sbs_gemCeF_hit_Utime, &b_sbs_gemCeF_hit_Utime);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.UtimeDeconv", &Ndata_sbs_gemCeF_hit_UtimeDeconv, &b_Ndata_sbs_gemCeF_hit_UtimeDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.UtimeDeconv", sbs_gemCeF_hit_UtimeDeconv, &b_sbs_gemCeF_hit_UtimeDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.UtimeFit", &Ndata_sbs_gemCeF_hit_UtimeFit, &b_Ndata_sbs_gemCeF_hit_UtimeFit);
   fChain->SetBranchAddress("sbs.gemCeF.hit.UtimeFit", sbs_gemCeF_hit_UtimeFit, &b_sbs_gemCeF_hit_UtimeFit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.UtimeMaxStrip", &Ndata_sbs_gemCeF_hit_UtimeMaxStrip, &b_Ndata_sbs_gemCeF_hit_UtimeMaxStrip);
   fChain->SetBranchAddress("sbs.gemCeF.hit.UtimeMaxStrip", sbs_gemCeF_hit_UtimeMaxStrip, &b_sbs_gemCeF_hit_UtimeMaxStrip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.UtimeMaxStripDeconv", &Ndata_sbs_gemCeF_hit_UtimeMaxStripDeconv, &b_Ndata_sbs_gemCeF_hit_UtimeMaxStripDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.UtimeMaxStripDeconv", sbs_gemCeF_hit_UtimeMaxStripDeconv, &b_sbs_gemCeF_hit_UtimeMaxStripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.UtimeMaxStripFit", &Ndata_sbs_gemCeF_hit_UtimeMaxStripFit, &b_Ndata_sbs_gemCeF_hit_UtimeMaxStripFit);
   fChain->SetBranchAddress("sbs.gemCeF.hit.UtimeMaxStripFit", sbs_gemCeF_hit_UtimeMaxStripFit, &b_sbs_gemCeF_hit_UtimeMaxStripFit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.Vgain", &Ndata_sbs_gemCeF_hit_Vgain, &b_Ndata_sbs_gemCeF_hit_Vgain);
   fChain->SetBranchAddress("sbs.gemCeF.hit.Vgain", sbs_gemCeF_hit_Vgain, &b_sbs_gemCeF_hit_Vgain);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.Vtime", &Ndata_sbs_gemCeF_hit_Vtime, &b_Ndata_sbs_gemCeF_hit_Vtime);
   fChain->SetBranchAddress("sbs.gemCeF.hit.Vtime", sbs_gemCeF_hit_Vtime, &b_sbs_gemCeF_hit_Vtime);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.VtimeDeconv", &Ndata_sbs_gemCeF_hit_VtimeDeconv, &b_Ndata_sbs_gemCeF_hit_VtimeDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.VtimeDeconv", sbs_gemCeF_hit_VtimeDeconv, &b_sbs_gemCeF_hit_VtimeDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.VtimeFit", &Ndata_sbs_gemCeF_hit_VtimeFit, &b_Ndata_sbs_gemCeF_hit_VtimeFit);
   fChain->SetBranchAddress("sbs.gemCeF.hit.VtimeFit", sbs_gemCeF_hit_VtimeFit, &b_sbs_gemCeF_hit_VtimeFit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.VtimeMaxStrip", &Ndata_sbs_gemCeF_hit_VtimeMaxStrip, &b_Ndata_sbs_gemCeF_hit_VtimeMaxStrip);
   fChain->SetBranchAddress("sbs.gemCeF.hit.VtimeMaxStrip", sbs_gemCeF_hit_VtimeMaxStrip, &b_sbs_gemCeF_hit_VtimeMaxStrip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.VtimeMaxStripDeconv", &Ndata_sbs_gemCeF_hit_VtimeMaxStripDeconv, &b_Ndata_sbs_gemCeF_hit_VtimeMaxStripDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.VtimeMaxStripDeconv", sbs_gemCeF_hit_VtimeMaxStripDeconv, &b_sbs_gemCeF_hit_VtimeMaxStripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.VtimeMaxStripFit", &Ndata_sbs_gemCeF_hit_VtimeMaxStripFit, &b_Ndata_sbs_gemCeF_hit_VtimeMaxStripFit);
   fChain->SetBranchAddress("sbs.gemCeF.hit.VtimeMaxStripFit", sbs_gemCeF_hit_VtimeMaxStripFit, &b_sbs_gemCeF_hit_VtimeMaxStripFit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.adc_id_U", &Ndata_sbs_gemCeF_hit_adc_id_U, &b_Ndata_sbs_gemCeF_hit_adc_id_U);
   fChain->SetBranchAddress("sbs.gemCeF.hit.adc_id_U", sbs_gemCeF_hit_adc_id_U, &b_sbs_gemCeF_hit_adc_id_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.adc_id_V", &Ndata_sbs_gemCeF_hit_adc_id_V, &b_Ndata_sbs_gemCeF_hit_adc_id_V);
   fChain->SetBranchAddress("sbs.gemCeF.hit.adc_id_V", sbs_gemCeF_hit_adc_id_V, &b_sbs_gemCeF_hit_adc_id_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ccor_clust", &Ndata_sbs_gemCeF_hit_ccor_clust, &b_Ndata_sbs_gemCeF_hit_ccor_clust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ccor_clust", sbs_gemCeF_hit_ccor_clust, &b_sbs_gemCeF_hit_ccor_clust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ccor_clust_deconv", &Ndata_sbs_gemCeF_hit_ccor_clust_deconv, &b_Ndata_sbs_gemCeF_hit_ccor_clust_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ccor_clust_deconv", sbs_gemCeF_hit_ccor_clust_deconv, &b_sbs_gemCeF_hit_ccor_clust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ccor_strip", &Ndata_sbs_gemCeF_hit_ccor_strip, &b_Ndata_sbs_gemCeF_hit_ccor_strip);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ccor_strip", sbs_gemCeF_hit_ccor_strip, &b_sbs_gemCeF_hit_ccor_strip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ccor_strip_deconv", &Ndata_sbs_gemCeF_hit_ccor_strip_deconv, &b_Ndata_sbs_gemCeF_hit_ccor_strip_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ccor_strip_deconv", sbs_gemCeF_hit_ccor_strip_deconv, &b_sbs_gemCeF_hit_ccor_strip_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.crate_U", &Ndata_sbs_gemCeF_hit_crate_U, &b_Ndata_sbs_gemCeF_hit_crate_U);
   fChain->SetBranchAddress("sbs.gemCeF.hit.crate_U", sbs_gemCeF_hit_crate_U, &b_sbs_gemCeF_hit_crate_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.crate_V", &Ndata_sbs_gemCeF_hit_crate_V, &b_Ndata_sbs_gemCeF_hit_crate_V);
   fChain->SetBranchAddress("sbs.gemCeF.hit.crate_V", sbs_gemCeF_hit_crate_V, &b_sbs_gemCeF_hit_crate_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.deltat", &Ndata_sbs_gemCeF_hit_deltat, &b_Ndata_sbs_gemCeF_hit_deltat);
   fChain->SetBranchAddress("sbs.gemCeF.hit.deltat", sbs_gemCeF_hit_deltat, &b_sbs_gemCeF_hit_deltat);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.deltat_deconv", &Ndata_sbs_gemCeF_hit_deltat_deconv, &b_Ndata_sbs_gemCeF_hit_deltat_deconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.deltat_deconv", sbs_gemCeF_hit_deltat_deconv, &b_sbs_gemCeF_hit_deltat_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.deltat_fit", &Ndata_sbs_gemCeF_hit_deltat_fit, &b_Ndata_sbs_gemCeF_hit_deltat_fit);
   fChain->SetBranchAddress("sbs.gemCeF.hit.deltat_fit", sbs_gemCeF_hit_deltat_fit, &b_sbs_gemCeF_hit_deltat_fit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.eresidu", &Ndata_sbs_gemCeF_hit_eresidu, &b_Ndata_sbs_gemCeF_hit_eresidu);
   fChain->SetBranchAddress("sbs.gemCeF.hit.eresidu", sbs_gemCeF_hit_eresidu, &b_sbs_gemCeF_hit_eresidu);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.eresidv", &Ndata_sbs_gemCeF_hit_eresidv, &b_Ndata_sbs_gemCeF_hit_eresidv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.eresidv", sbs_gemCeF_hit_eresidv, &b_sbs_gemCeF_hit_eresidv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.icombomaxUclustDeconv", &Ndata_sbs_gemCeF_hit_icombomaxUclustDeconv, &b_Ndata_sbs_gemCeF_hit_icombomaxUclustDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.icombomaxUclustDeconv", sbs_gemCeF_hit_icombomaxUclustDeconv, &b_sbs_gemCeF_hit_icombomaxUclustDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.icombomaxUstripDeconv", &Ndata_sbs_gemCeF_hit_icombomaxUstripDeconv, &b_Ndata_sbs_gemCeF_hit_icombomaxUstripDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.icombomaxUstripDeconv", sbs_gemCeF_hit_icombomaxUstripDeconv, &b_sbs_gemCeF_hit_icombomaxUstripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.icombomaxVclustDeconv", &Ndata_sbs_gemCeF_hit_icombomaxVclustDeconv, &b_Ndata_sbs_gemCeF_hit_icombomaxVclustDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.icombomaxVclustDeconv", sbs_gemCeF_hit_icombomaxVclustDeconv, &b_sbs_gemCeF_hit_icombomaxVclustDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.icombomaxVstripDeconv", &Ndata_sbs_gemCeF_hit_icombomaxVstripDeconv, &b_Ndata_sbs_gemCeF_hit_icombomaxVstripDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.icombomaxVstripDeconv", sbs_gemCeF_hit_icombomaxVstripDeconv, &b_sbs_gemCeF_hit_icombomaxVstripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.isampmaxUclust", &Ndata_sbs_gemCeF_hit_isampmaxUclust, &b_Ndata_sbs_gemCeF_hit_isampmaxUclust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.isampmaxUclust", sbs_gemCeF_hit_isampmaxUclust, &b_sbs_gemCeF_hit_isampmaxUclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.isampmaxUclustDeconv", &Ndata_sbs_gemCeF_hit_isampmaxUclustDeconv, &b_Ndata_sbs_gemCeF_hit_isampmaxUclustDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.isampmaxUclustDeconv", sbs_gemCeF_hit_isampmaxUclustDeconv, &b_sbs_gemCeF_hit_isampmaxUclustDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.isampmaxUstrip", &Ndata_sbs_gemCeF_hit_isampmaxUstrip, &b_Ndata_sbs_gemCeF_hit_isampmaxUstrip);
   fChain->SetBranchAddress("sbs.gemCeF.hit.isampmaxUstrip", sbs_gemCeF_hit_isampmaxUstrip, &b_sbs_gemCeF_hit_isampmaxUstrip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.isampmaxUstripDeconv", &Ndata_sbs_gemCeF_hit_isampmaxUstripDeconv, &b_Ndata_sbs_gemCeF_hit_isampmaxUstripDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.isampmaxUstripDeconv", sbs_gemCeF_hit_isampmaxUstripDeconv, &b_sbs_gemCeF_hit_isampmaxUstripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.isampmaxVclust", &Ndata_sbs_gemCeF_hit_isampmaxVclust, &b_Ndata_sbs_gemCeF_hit_isampmaxVclust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.isampmaxVclust", sbs_gemCeF_hit_isampmaxVclust, &b_sbs_gemCeF_hit_isampmaxVclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.isampmaxVclustDeconv", &Ndata_sbs_gemCeF_hit_isampmaxVclustDeconv, &b_Ndata_sbs_gemCeF_hit_isampmaxVclustDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.isampmaxVclustDeconv", sbs_gemCeF_hit_isampmaxVclustDeconv, &b_sbs_gemCeF_hit_isampmaxVclustDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.isampmaxVstrip", &Ndata_sbs_gemCeF_hit_isampmaxVstrip, &b_Ndata_sbs_gemCeF_hit_isampmaxVstrip);
   fChain->SetBranchAddress("sbs.gemCeF.hit.isampmaxVstrip", sbs_gemCeF_hit_isampmaxVstrip, &b_sbs_gemCeF_hit_isampmaxVstrip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.isampmaxVstripDeconv", &Ndata_sbs_gemCeF_hit_isampmaxVstripDeconv, &b_Ndata_sbs_gemCeF_hit_isampmaxVstripDeconv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.isampmaxVstripDeconv", sbs_gemCeF_hit_isampmaxVstripDeconv, &b_sbs_gemCeF_hit_isampmaxVstripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.layer", &Ndata_sbs_gemCeF_hit_layer, &b_Ndata_sbs_gemCeF_hit_layer);
   fChain->SetBranchAddress("sbs.gemCeF.hit.layer", sbs_gemCeF_hit_layer, &b_sbs_gemCeF_hit_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.module", &Ndata_sbs_gemCeF_hit_module, &b_Ndata_sbs_gemCeF_hit_module);
   fChain->SetBranchAddress("sbs.gemCeF.hit.module", sbs_gemCeF_hit_module, &b_sbs_gemCeF_hit_module);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.mpd_U", &Ndata_sbs_gemCeF_hit_mpd_U, &b_Ndata_sbs_gemCeF_hit_mpd_U);
   fChain->SetBranchAddress("sbs.gemCeF.hit.mpd_U", sbs_gemCeF_hit_mpd_U, &b_sbs_gemCeF_hit_mpd_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.mpd_V", &Ndata_sbs_gemCeF_hit_mpd_V, &b_Ndata_sbs_gemCeF_hit_mpd_V);
   fChain->SetBranchAddress("sbs.gemCeF.hit.mpd_V", sbs_gemCeF_hit_mpd_V, &b_sbs_gemCeF_hit_mpd_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.nstripu", &Ndata_sbs_gemCeF_hit_nstripu, &b_Ndata_sbs_gemCeF_hit_nstripu);
   fChain->SetBranchAddress("sbs.gemCeF.hit.nstripu", sbs_gemCeF_hit_nstripu, &b_sbs_gemCeF_hit_nstripu);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.nstripv", &Ndata_sbs_gemCeF_hit_nstripv, &b_Ndata_sbs_gemCeF_hit_nstripv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.nstripv", sbs_gemCeF_hit_nstripv, &b_sbs_gemCeF_hit_nstripv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.residu", &Ndata_sbs_gemCeF_hit_residu, &b_Ndata_sbs_gemCeF_hit_residu);
   fChain->SetBranchAddress("sbs.gemCeF.hit.residu", sbs_gemCeF_hit_residu, &b_sbs_gemCeF_hit_residu);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.residv", &Ndata_sbs_gemCeF_hit_residv, &b_Ndata_sbs_gemCeF_hit_residv);
   fChain->SetBranchAddress("sbs.gemCeF.hit.residv", sbs_gemCeF_hit_residv, &b_sbs_gemCeF_hit_residv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.trackindex", &Ndata_sbs_gemCeF_hit_trackindex, &b_Ndata_sbs_gemCeF_hit_trackindex);
   fChain->SetBranchAddress("sbs.gemCeF.hit.trackindex", sbs_gemCeF_hit_trackindex, &b_sbs_gemCeF_hit_trackindex);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.u", &Ndata_sbs_gemCeF_hit_u, &b_Ndata_sbs_gemCeF_hit_u);
   fChain->SetBranchAddress("sbs.gemCeF.hit.u", sbs_gemCeF_hit_u, &b_sbs_gemCeF_hit_u);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.uTScorr_MaxStripU", &Ndata_sbs_gemCeF_hit_uTScorr_MaxStripU, &b_Ndata_sbs_gemCeF_hit_uTScorr_MaxStripU);
   fChain->SetBranchAddress("sbs.gemCeF.hit.uTScorr_MaxStripU", sbs_gemCeF_hit_uTScorr_MaxStripU, &b_sbs_gemCeF_hit_uTScorr_MaxStripU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.uTScorr_MaxStripV", &Ndata_sbs_gemCeF_hit_uTScorr_MaxStripV, &b_Ndata_sbs_gemCeF_hit_uTScorr_MaxStripV);
   fChain->SetBranchAddress("sbs.gemCeF.hit.uTScorr_MaxStripV", sbs_gemCeF_hit_uTScorr_MaxStripV, &b_sbs_gemCeF_hit_uTScorr_MaxStripV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.uTScorr_Uclust", &Ndata_sbs_gemCeF_hit_uTScorr_Uclust, &b_Ndata_sbs_gemCeF_hit_uTScorr_Uclust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.uTScorr_Uclust", sbs_gemCeF_hit_uTScorr_Uclust, &b_sbs_gemCeF_hit_uTScorr_Uclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.uTScorr_Vclust", &Ndata_sbs_gemCeF_hit_uTScorr_Vclust, &b_Ndata_sbs_gemCeF_hit_uTScorr_Vclust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.uTScorr_Vclust", sbs_gemCeF_hit_uTScorr_Vclust, &b_sbs_gemCeF_hit_uTScorr_Vclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.umoment", &Ndata_sbs_gemCeF_hit_umoment, &b_Ndata_sbs_gemCeF_hit_umoment);
   fChain->SetBranchAddress("sbs.gemCeF.hit.umoment", sbs_gemCeF_hit_umoment, &b_sbs_gemCeF_hit_umoment);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.usigma", &Ndata_sbs_gemCeF_hit_usigma, &b_Ndata_sbs_gemCeF_hit_usigma);
   fChain->SetBranchAddress("sbs.gemCeF.hit.usigma", sbs_gemCeF_hit_usigma, &b_sbs_gemCeF_hit_usigma);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ustriphi", &Ndata_sbs_gemCeF_hit_ustriphi, &b_Ndata_sbs_gemCeF_hit_ustriphi);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ustriphi", sbs_gemCeF_hit_ustriphi, &b_sbs_gemCeF_hit_ustriphi);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ustriplo", &Ndata_sbs_gemCeF_hit_ustriplo, &b_Ndata_sbs_gemCeF_hit_ustriplo);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ustriplo", sbs_gemCeF_hit_ustriplo, &b_sbs_gemCeF_hit_ustriplo);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ustripmax", &Ndata_sbs_gemCeF_hit_ustripmax, &b_Ndata_sbs_gemCeF_hit_ustripmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ustripmax", sbs_gemCeF_hit_ustripmax, &b_sbs_gemCeF_hit_ustripmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.v", &Ndata_sbs_gemCeF_hit_v, &b_Ndata_sbs_gemCeF_hit_v);
   fChain->SetBranchAddress("sbs.gemCeF.hit.v", sbs_gemCeF_hit_v, &b_sbs_gemCeF_hit_v);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.vmoment", &Ndata_sbs_gemCeF_hit_vmoment, &b_Ndata_sbs_gemCeF_hit_vmoment);
   fChain->SetBranchAddress("sbs.gemCeF.hit.vmoment", sbs_gemCeF_hit_vmoment, &b_sbs_gemCeF_hit_vmoment);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.vsigma", &Ndata_sbs_gemCeF_hit_vsigma, &b_Ndata_sbs_gemCeF_hit_vsigma);
   fChain->SetBranchAddress("sbs.gemCeF.hit.vsigma", sbs_gemCeF_hit_vsigma, &b_sbs_gemCeF_hit_vsigma);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.vstriphi", &Ndata_sbs_gemCeF_hit_vstriphi, &b_Ndata_sbs_gemCeF_hit_vstriphi);
   fChain->SetBranchAddress("sbs.gemCeF.hit.vstriphi", sbs_gemCeF_hit_vstriphi, &b_sbs_gemCeF_hit_vstriphi);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.vstriplo", &Ndata_sbs_gemCeF_hit_vstriplo, &b_Ndata_sbs_gemCeF_hit_vstriplo);
   fChain->SetBranchAddress("sbs.gemCeF.hit.vstriplo", sbs_gemCeF_hit_vstriplo, &b_sbs_gemCeF_hit_vstriplo);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.vstripmax", &Ndata_sbs_gemCeF_hit_vstripmax, &b_Ndata_sbs_gemCeF_hit_vstripmax);
   fChain->SetBranchAddress("sbs.gemCeF.hit.vstripmax", sbs_gemCeF_hit_vstripmax, &b_sbs_gemCeF_hit_vstripmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.wTScorr_MaxStripU", &Ndata_sbs_gemCeF_hit_wTScorr_MaxStripU, &b_Ndata_sbs_gemCeF_hit_wTScorr_MaxStripU);
   fChain->SetBranchAddress("sbs.gemCeF.hit.wTScorr_MaxStripU", sbs_gemCeF_hit_wTScorr_MaxStripU, &b_sbs_gemCeF_hit_wTScorr_MaxStripU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.wTScorr_MaxStripV", &Ndata_sbs_gemCeF_hit_wTScorr_MaxStripV, &b_Ndata_sbs_gemCeF_hit_wTScorr_MaxStripV);
   fChain->SetBranchAddress("sbs.gemCeF.hit.wTScorr_MaxStripV", sbs_gemCeF_hit_wTScorr_MaxStripV, &b_sbs_gemCeF_hit_wTScorr_MaxStripV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.wTScorr_Uclust", &Ndata_sbs_gemCeF_hit_wTScorr_Uclust, &b_Ndata_sbs_gemCeF_hit_wTScorr_Uclust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.wTScorr_Uclust", sbs_gemCeF_hit_wTScorr_Uclust, &b_sbs_gemCeF_hit_wTScorr_Uclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.wTScorr_Vclust", &Ndata_sbs_gemCeF_hit_wTScorr_Vclust, &b_Ndata_sbs_gemCeF_hit_wTScorr_Vclust);
   fChain->SetBranchAddress("sbs.gemCeF.hit.wTScorr_Vclust", sbs_gemCeF_hit_wTScorr_Vclust, &b_sbs_gemCeF_hit_wTScorr_Vclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.xglobal", &Ndata_sbs_gemCeF_hit_xglobal, &b_Ndata_sbs_gemCeF_hit_xglobal);
   fChain->SetBranchAddress("sbs.gemCeF.hit.xglobal", sbs_gemCeF_hit_xglobal, &b_sbs_gemCeF_hit_xglobal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.xlocal", &Ndata_sbs_gemCeF_hit_xlocal, &b_Ndata_sbs_gemCeF_hit_xlocal);
   fChain->SetBranchAddress("sbs.gemCeF.hit.xlocal", sbs_gemCeF_hit_xlocal, &b_sbs_gemCeF_hit_xlocal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.yglobal", &Ndata_sbs_gemCeF_hit_yglobal, &b_Ndata_sbs_gemCeF_hit_yglobal);
   fChain->SetBranchAddress("sbs.gemCeF.hit.yglobal", sbs_gemCeF_hit_yglobal, &b_sbs_gemCeF_hit_yglobal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.ylocal", &Ndata_sbs_gemCeF_hit_ylocal, &b_Ndata_sbs_gemCeF_hit_ylocal);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ylocal", sbs_gemCeF_hit_ylocal, &b_sbs_gemCeF_hit_ylocal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.hit.zglobal", &Ndata_sbs_gemCeF_hit_zglobal, &b_Ndata_sbs_gemCeF_hit_zglobal);
   fChain->SetBranchAddress("sbs.gemCeF.hit.zglobal", sbs_gemCeF_hit_zglobal, &b_sbs_gemCeF_hit_zglobal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.n2Dhit_layer", &Ndata_sbs_gemCeF_n2Dhit_layer, &b_Ndata_sbs_gemCeF_n2Dhit_layer);
   fChain->SetBranchAddress("sbs.gemCeF.n2Dhit_layer", sbs_gemCeF_n2Dhit_layer, &b_sbs_gemCeF_n2Dhit_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.nclustu_layer", &Ndata_sbs_gemCeF_nclustu_layer, &b_Ndata_sbs_gemCeF_nclustu_layer);
   fChain->SetBranchAddress("sbs.gemCeF.nclustu_layer", sbs_gemCeF_nclustu_layer, &b_sbs_gemCeF_nclustu_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.nclustv_layer", &Ndata_sbs_gemCeF_nclustv_layer, &b_Ndata_sbs_gemCeF_nclustv_layer);
   fChain->SetBranchAddress("sbs.gemCeF.nclustv_layer", sbs_gemCeF_nclustv_layer, &b_sbs_gemCeF_nclustv_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.nstripsu_layer", &Ndata_sbs_gemCeF_nstripsu_layer, &b_Ndata_sbs_gemCeF_nstripsu_layer);
   fChain->SetBranchAddress("sbs.gemCeF.nstripsu_layer", sbs_gemCeF_nstripsu_layer, &b_sbs_gemCeF_nstripsu_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.nstripsv_layer", &Ndata_sbs_gemCeF_nstripsv_layer, &b_Ndata_sbs_gemCeF_nstripsv_layer);
   fChain->SetBranchAddress("sbs.gemCeF.nstripsv_layer", sbs_gemCeF_nstripsv_layer, &b_sbs_gemCeF_nstripsv_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.chi2ndf", &Ndata_sbs_gemCeF_track_chi2ndf, &b_Ndata_sbs_gemCeF_track_chi2ndf);
   fChain->SetBranchAddress("sbs.gemCeF.track.chi2ndf", sbs_gemCeF_track_chi2ndf, &b_sbs_gemCeF_track_chi2ndf);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.chi2ndf_hitquality", &Ndata_sbs_gemCeF_track_chi2ndf_hitquality, &b_Ndata_sbs_gemCeF_track_chi2ndf_hitquality);
   fChain->SetBranchAddress("sbs.gemCeF.track.chi2ndf_hitquality", sbs_gemCeF_track_chi2ndf_hitquality, &b_sbs_gemCeF_track_chi2ndf_hitquality);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.ngoodhits", &Ndata_sbs_gemCeF_track_ngoodhits, &b_Ndata_sbs_gemCeF_track_ngoodhits);
   fChain->SetBranchAddress("sbs.gemCeF.track.ngoodhits", sbs_gemCeF_track_ngoodhits, &b_sbs_gemCeF_track_ngoodhits);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.nhits", &Ndata_sbs_gemCeF_track_nhits, &b_Ndata_sbs_gemCeF_track_nhits);
   fChain->SetBranchAddress("sbs.gemCeF.track.nhits", sbs_gemCeF_track_nhits, &b_sbs_gemCeF_track_nhits);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.t0", &Ndata_sbs_gemCeF_track_t0, &b_Ndata_sbs_gemCeF_track_t0);
   fChain->SetBranchAddress("sbs.gemCeF.track.t0", sbs_gemCeF_track_t0, &b_sbs_gemCeF_track_t0);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.x", &Ndata_sbs_gemCeF_track_x, &b_Ndata_sbs_gemCeF_track_x);
   fChain->SetBranchAddress("sbs.gemCeF.track.x", sbs_gemCeF_track_x, &b_sbs_gemCeF_track_x);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.xp", &Ndata_sbs_gemCeF_track_xp, &b_Ndata_sbs_gemCeF_track_xp);
   fChain->SetBranchAddress("sbs.gemCeF.track.xp", sbs_gemCeF_track_xp, &b_sbs_gemCeF_track_xp);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.y", &Ndata_sbs_gemCeF_track_y, &b_Ndata_sbs_gemCeF_track_y);
   fChain->SetBranchAddress("sbs.gemCeF.track.y", sbs_gemCeF_track_y, &b_sbs_gemCeF_track_y);
   fChain->SetBranchAddress("Ndata.sbs.gemCeF.track.yp", &Ndata_sbs_gemCeF_track_yp, &b_Ndata_sbs_gemCeF_track_yp);
   fChain->SetBranchAddress("sbs.gemCeF.track.yp", sbs_gemCeF_track_yp, &b_sbs_gemCeF_track_yp);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCU", &Ndata_sbs_gemCeR_hit_ADCU, &b_Ndata_sbs_gemCeR_hit_ADCU);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCU", sbs_gemCeR_hit_ADCU, &b_sbs_gemCeR_hit_ADCU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCU_deconv", &Ndata_sbs_gemCeR_hit_ADCU_deconv, &b_Ndata_sbs_gemCeR_hit_ADCU_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCU_deconv", sbs_gemCeR_hit_ADCU_deconv, &b_sbs_gemCeR_hit_ADCU_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCV", &Ndata_sbs_gemCeR_hit_ADCV, &b_Ndata_sbs_gemCeR_hit_ADCV);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCV", sbs_gemCeR_hit_ADCV, &b_sbs_gemCeR_hit_ADCV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCV_deconv", &Ndata_sbs_gemCeR_hit_ADCV_deconv, &b_Ndata_sbs_gemCeR_hit_ADCV_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCV_deconv", sbs_gemCeR_hit_ADCV_deconv, &b_sbs_gemCeR_hit_ADCV_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCasym", &Ndata_sbs_gemCeR_hit_ADCasym, &b_Ndata_sbs_gemCeR_hit_ADCasym);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCasym", sbs_gemCeR_hit_ADCasym, &b_sbs_gemCeR_hit_ADCasym);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCasym_deconv", &Ndata_sbs_gemCeR_hit_ADCasym_deconv, &b_Ndata_sbs_gemCeR_hit_ADCasym_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCasym_deconv", sbs_gemCeR_hit_ADCasym_deconv, &b_sbs_gemCeR_hit_ADCasym_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCavg", &Ndata_sbs_gemCeR_hit_ADCavg, &b_Ndata_sbs_gemCeR_hit_ADCavg);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCavg", sbs_gemCeR_hit_ADCavg, &b_sbs_gemCeR_hit_ADCavg);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCavg_deconv", &Ndata_sbs_gemCeR_hit_ADCavg_deconv, &b_Ndata_sbs_gemCeR_hit_ADCavg_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCavg_deconv", sbs_gemCeR_hit_ADCavg_deconv, &b_sbs_gemCeR_hit_ADCavg_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac0_Umax", &Ndata_sbs_gemCeR_hit_ADCfrac0_Umax, &b_Ndata_sbs_gemCeR_hit_ADCfrac0_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac0_Umax", sbs_gemCeR_hit_ADCfrac0_Umax, &b_sbs_gemCeR_hit_ADCfrac0_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac0_Vmax", &Ndata_sbs_gemCeR_hit_ADCfrac0_Vmax, &b_Ndata_sbs_gemCeR_hit_ADCfrac0_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac0_Vmax", sbs_gemCeR_hit_ADCfrac0_Vmax, &b_sbs_gemCeR_hit_ADCfrac0_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac1_Umax", &Ndata_sbs_gemCeR_hit_ADCfrac1_Umax, &b_Ndata_sbs_gemCeR_hit_ADCfrac1_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac1_Umax", sbs_gemCeR_hit_ADCfrac1_Umax, &b_sbs_gemCeR_hit_ADCfrac1_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac1_Vmax", &Ndata_sbs_gemCeR_hit_ADCfrac1_Vmax, &b_Ndata_sbs_gemCeR_hit_ADCfrac1_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac1_Vmax", sbs_gemCeR_hit_ADCfrac1_Vmax, &b_sbs_gemCeR_hit_ADCfrac1_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac2_Umax", &Ndata_sbs_gemCeR_hit_ADCfrac2_Umax, &b_Ndata_sbs_gemCeR_hit_ADCfrac2_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac2_Umax", sbs_gemCeR_hit_ADCfrac2_Umax, &b_sbs_gemCeR_hit_ADCfrac2_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac2_Vmax", &Ndata_sbs_gemCeR_hit_ADCfrac2_Vmax, &b_Ndata_sbs_gemCeR_hit_ADCfrac2_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac2_Vmax", sbs_gemCeR_hit_ADCfrac2_Vmax, &b_sbs_gemCeR_hit_ADCfrac2_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac3_Umax", &Ndata_sbs_gemCeR_hit_ADCfrac3_Umax, &b_Ndata_sbs_gemCeR_hit_ADCfrac3_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac3_Umax", sbs_gemCeR_hit_ADCfrac3_Umax, &b_sbs_gemCeR_hit_ADCfrac3_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac3_Vmax", &Ndata_sbs_gemCeR_hit_ADCfrac3_Vmax, &b_Ndata_sbs_gemCeR_hit_ADCfrac3_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac3_Vmax", sbs_gemCeR_hit_ADCfrac3_Vmax, &b_sbs_gemCeR_hit_ADCfrac3_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac4_Umax", &Ndata_sbs_gemCeR_hit_ADCfrac4_Umax, &b_Ndata_sbs_gemCeR_hit_ADCfrac4_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac4_Umax", sbs_gemCeR_hit_ADCfrac4_Umax, &b_sbs_gemCeR_hit_ADCfrac4_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac4_Vmax", &Ndata_sbs_gemCeR_hit_ADCfrac4_Vmax, &b_Ndata_sbs_gemCeR_hit_ADCfrac4_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac4_Vmax", sbs_gemCeR_hit_ADCfrac4_Vmax, &b_sbs_gemCeR_hit_ADCfrac4_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac5_Umax", &Ndata_sbs_gemCeR_hit_ADCfrac5_Umax, &b_Ndata_sbs_gemCeR_hit_ADCfrac5_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac5_Umax", sbs_gemCeR_hit_ADCfrac5_Umax, &b_sbs_gemCeR_hit_ADCfrac5_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCfrac5_Vmax", &Ndata_sbs_gemCeR_hit_ADCfrac5_Vmax, &b_Ndata_sbs_gemCeR_hit_ADCfrac5_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCfrac5_Vmax", sbs_gemCeR_hit_ADCfrac5_Vmax, &b_sbs_gemCeR_hit_ADCfrac5_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxcomboUclust_deconv", &Ndata_sbs_gemCeR_hit_ADCmaxcomboUclust_deconv, &b_Ndata_sbs_gemCeR_hit_ADCmaxcomboUclust_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxcomboUclust_deconv", sbs_gemCeR_hit_ADCmaxcomboUclust_deconv, &b_sbs_gemCeR_hit_ADCmaxcomboUclust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxcomboVclust_deconv", &Ndata_sbs_gemCeR_hit_ADCmaxcomboVclust_deconv, &b_Ndata_sbs_gemCeR_hit_ADCmaxcomboVclust_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxcomboVclust_deconv", sbs_gemCeR_hit_ADCmaxcomboVclust_deconv, &b_sbs_gemCeR_hit_ADCmaxcomboVclust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxsampU", &Ndata_sbs_gemCeR_hit_ADCmaxsampU, &b_Ndata_sbs_gemCeR_hit_ADCmaxsampU);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxsampU", sbs_gemCeR_hit_ADCmaxsampU, &b_sbs_gemCeR_hit_ADCmaxsampU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxsampUclust", &Ndata_sbs_gemCeR_hit_ADCmaxsampUclust, &b_Ndata_sbs_gemCeR_hit_ADCmaxsampUclust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxsampUclust", sbs_gemCeR_hit_ADCmaxsampUclust, &b_sbs_gemCeR_hit_ADCmaxsampUclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxsampUclust_deconv", &Ndata_sbs_gemCeR_hit_ADCmaxsampUclust_deconv, &b_Ndata_sbs_gemCeR_hit_ADCmaxsampUclust_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxsampUclust_deconv", sbs_gemCeR_hit_ADCmaxsampUclust_deconv, &b_sbs_gemCeR_hit_ADCmaxsampUclust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxsampV", &Ndata_sbs_gemCeR_hit_ADCmaxsampV, &b_Ndata_sbs_gemCeR_hit_ADCmaxsampV);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxsampV", sbs_gemCeR_hit_ADCmaxsampV, &b_sbs_gemCeR_hit_ADCmaxsampV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxsampVclust", &Ndata_sbs_gemCeR_hit_ADCmaxsampVclust, &b_Ndata_sbs_gemCeR_hit_ADCmaxsampVclust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxsampVclust", sbs_gemCeR_hit_ADCmaxsampVclust, &b_sbs_gemCeR_hit_ADCmaxsampVclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxsampVclust_deconv", &Ndata_sbs_gemCeR_hit_ADCmaxsampVclust_deconv, &b_Ndata_sbs_gemCeR_hit_ADCmaxsampVclust_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxsampVclust_deconv", sbs_gemCeR_hit_ADCmaxsampVclust_deconv, &b_sbs_gemCeR_hit_ADCmaxsampVclust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxstripU", &Ndata_sbs_gemCeR_hit_ADCmaxstripU, &b_Ndata_sbs_gemCeR_hit_ADCmaxstripU);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxstripU", sbs_gemCeR_hit_ADCmaxstripU, &b_sbs_gemCeR_hit_ADCmaxstripU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ADCmaxstripV", &Ndata_sbs_gemCeR_hit_ADCmaxstripV, &b_Ndata_sbs_gemCeR_hit_ADCmaxstripV);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ADCmaxstripV", sbs_gemCeR_hit_ADCmaxstripV, &b_sbs_gemCeR_hit_ADCmaxstripV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.BUILD_ALL_SAMPLES_U", &Ndata_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_U, &b_Ndata_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_U);
   fChain->SetBranchAddress("sbs.gemCeR.hit.BUILD_ALL_SAMPLES_U", sbs_gemCeR_hit_BUILD_ALL_SAMPLES_U, &b_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.BUILD_ALL_SAMPLES_V", &Ndata_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_V, &b_Ndata_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_V);
   fChain->SetBranchAddress("sbs.gemCeR.hit.BUILD_ALL_SAMPLES_V", sbs_gemCeR_hit_BUILD_ALL_SAMPLES_V, &b_sbs_gemCeR_hit_BUILD_ALL_SAMPLES_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.CM_GOOD_U", &Ndata_sbs_gemCeR_hit_CM_GOOD_U, &b_Ndata_sbs_gemCeR_hit_CM_GOOD_U);
   fChain->SetBranchAddress("sbs.gemCeR.hit.CM_GOOD_U", sbs_gemCeR_hit_CM_GOOD_U, &b_sbs_gemCeR_hit_CM_GOOD_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.CM_GOOD_V", &Ndata_sbs_gemCeR_hit_CM_GOOD_V, &b_Ndata_sbs_gemCeR_hit_CM_GOOD_V);
   fChain->SetBranchAddress("sbs.gemCeR.hit.CM_GOOD_V", sbs_gemCeR_hit_CM_GOOD_V, &b_sbs_gemCeR_hit_CM_GOOD_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC0_Umax", &Ndata_sbs_gemCeR_hit_DeconvADC0_Umax, &b_Ndata_sbs_gemCeR_hit_DeconvADC0_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC0_Umax", sbs_gemCeR_hit_DeconvADC0_Umax, &b_sbs_gemCeR_hit_DeconvADC0_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC0_Vmax", &Ndata_sbs_gemCeR_hit_DeconvADC0_Vmax, &b_Ndata_sbs_gemCeR_hit_DeconvADC0_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC0_Vmax", sbs_gemCeR_hit_DeconvADC0_Vmax, &b_sbs_gemCeR_hit_DeconvADC0_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC1_Umax", &Ndata_sbs_gemCeR_hit_DeconvADC1_Umax, &b_Ndata_sbs_gemCeR_hit_DeconvADC1_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC1_Umax", sbs_gemCeR_hit_DeconvADC1_Umax, &b_sbs_gemCeR_hit_DeconvADC1_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC1_Vmax", &Ndata_sbs_gemCeR_hit_DeconvADC1_Vmax, &b_Ndata_sbs_gemCeR_hit_DeconvADC1_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC1_Vmax", sbs_gemCeR_hit_DeconvADC1_Vmax, &b_sbs_gemCeR_hit_DeconvADC1_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC2_Umax", &Ndata_sbs_gemCeR_hit_DeconvADC2_Umax, &b_Ndata_sbs_gemCeR_hit_DeconvADC2_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC2_Umax", sbs_gemCeR_hit_DeconvADC2_Umax, &b_sbs_gemCeR_hit_DeconvADC2_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC2_Vmax", &Ndata_sbs_gemCeR_hit_DeconvADC2_Vmax, &b_Ndata_sbs_gemCeR_hit_DeconvADC2_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC2_Vmax", sbs_gemCeR_hit_DeconvADC2_Vmax, &b_sbs_gemCeR_hit_DeconvADC2_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC3_Umax", &Ndata_sbs_gemCeR_hit_DeconvADC3_Umax, &b_Ndata_sbs_gemCeR_hit_DeconvADC3_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC3_Umax", sbs_gemCeR_hit_DeconvADC3_Umax, &b_sbs_gemCeR_hit_DeconvADC3_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC3_Vmax", &Ndata_sbs_gemCeR_hit_DeconvADC3_Vmax, &b_Ndata_sbs_gemCeR_hit_DeconvADC3_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC3_Vmax", sbs_gemCeR_hit_DeconvADC3_Vmax, &b_sbs_gemCeR_hit_DeconvADC3_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC4_Umax", &Ndata_sbs_gemCeR_hit_DeconvADC4_Umax, &b_Ndata_sbs_gemCeR_hit_DeconvADC4_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC4_Umax", sbs_gemCeR_hit_DeconvADC4_Umax, &b_sbs_gemCeR_hit_DeconvADC4_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC4_Vmax", &Ndata_sbs_gemCeR_hit_DeconvADC4_Vmax, &b_Ndata_sbs_gemCeR_hit_DeconvADC4_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC4_Vmax", sbs_gemCeR_hit_DeconvADC4_Vmax, &b_sbs_gemCeR_hit_DeconvADC4_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC5_Umax", &Ndata_sbs_gemCeR_hit_DeconvADC5_Umax, &b_Ndata_sbs_gemCeR_hit_DeconvADC5_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC5_Umax", sbs_gemCeR_hit_DeconvADC5_Umax, &b_sbs_gemCeR_hit_DeconvADC5_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADC5_Vmax", &Ndata_sbs_gemCeR_hit_DeconvADC5_Vmax, &b_Ndata_sbs_gemCeR_hit_DeconvADC5_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADC5_Vmax", sbs_gemCeR_hit_DeconvADC5_Vmax, &b_sbs_gemCeR_hit_DeconvADC5_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADCmaxcomboU", &Ndata_sbs_gemCeR_hit_DeconvADCmaxcomboU, &b_Ndata_sbs_gemCeR_hit_DeconvADCmaxcomboU);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADCmaxcomboU", sbs_gemCeR_hit_DeconvADCmaxcomboU, &b_sbs_gemCeR_hit_DeconvADCmaxcomboU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADCmaxcomboV", &Ndata_sbs_gemCeR_hit_DeconvADCmaxcomboV, &b_Ndata_sbs_gemCeR_hit_DeconvADCmaxcomboV);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADCmaxcomboV", sbs_gemCeR_hit_DeconvADCmaxcomboV, &b_sbs_gemCeR_hit_DeconvADCmaxcomboV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADCmaxsampU", &Ndata_sbs_gemCeR_hit_DeconvADCmaxsampU, &b_Ndata_sbs_gemCeR_hit_DeconvADCmaxsampU);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADCmaxsampU", sbs_gemCeR_hit_DeconvADCmaxsampU, &b_sbs_gemCeR_hit_DeconvADCmaxsampU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADCmaxsampV", &Ndata_sbs_gemCeR_hit_DeconvADCmaxsampV, &b_Ndata_sbs_gemCeR_hit_DeconvADCmaxsampV);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADCmaxsampV", sbs_gemCeR_hit_DeconvADCmaxsampV, &b_sbs_gemCeR_hit_DeconvADCmaxsampV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADCmaxstripU", &Ndata_sbs_gemCeR_hit_DeconvADCmaxstripU, &b_Ndata_sbs_gemCeR_hit_DeconvADCmaxstripU);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADCmaxstripU", sbs_gemCeR_hit_DeconvADCmaxstripU, &b_sbs_gemCeR_hit_DeconvADCmaxstripU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.DeconvADCmaxstripV", &Ndata_sbs_gemCeR_hit_DeconvADCmaxstripV, &b_Ndata_sbs_gemCeR_hit_DeconvADCmaxstripV);
   fChain->SetBranchAddress("sbs.gemCeR.hit.DeconvADCmaxstripV", sbs_gemCeR_hit_DeconvADCmaxstripV, &b_sbs_gemCeR_hit_DeconvADCmaxstripV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ENABLE_CM_U", &Ndata_sbs_gemCeR_hit_ENABLE_CM_U, &b_Ndata_sbs_gemCeR_hit_ENABLE_CM_U);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ENABLE_CM_U", sbs_gemCeR_hit_ENABLE_CM_U, &b_sbs_gemCeR_hit_ENABLE_CM_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ENABLE_CM_V", &Ndata_sbs_gemCeR_hit_ENABLE_CM_V, &b_Ndata_sbs_gemCeR_hit_ENABLE_CM_V);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ENABLE_CM_V", sbs_gemCeR_hit_ENABLE_CM_V, &b_sbs_gemCeR_hit_ENABLE_CM_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.TSchi2_Umax", &Ndata_sbs_gemCeR_hit_TSchi2_Umax, &b_Ndata_sbs_gemCeR_hit_TSchi2_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.TSchi2_Umax", sbs_gemCeR_hit_TSchi2_Umax, &b_sbs_gemCeR_hit_TSchi2_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.TSchi2_Vmax", &Ndata_sbs_gemCeR_hit_TSchi2_Vmax, &b_Ndata_sbs_gemCeR_hit_TSchi2_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.TSchi2_Vmax", sbs_gemCeR_hit_TSchi2_Vmax, &b_sbs_gemCeR_hit_TSchi2_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.TSprob_Umax", &Ndata_sbs_gemCeR_hit_TSprob_Umax, &b_Ndata_sbs_gemCeR_hit_TSprob_Umax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.TSprob_Umax", sbs_gemCeR_hit_TSprob_Umax, &b_sbs_gemCeR_hit_TSprob_Umax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.TSprob_Vmax", &Ndata_sbs_gemCeR_hit_TSprob_Vmax, &b_Ndata_sbs_gemCeR_hit_TSprob_Vmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.TSprob_Vmax", sbs_gemCeR_hit_TSprob_Vmax, &b_sbs_gemCeR_hit_TSprob_Vmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.Tavg", &Ndata_sbs_gemCeR_hit_Tavg, &b_Ndata_sbs_gemCeR_hit_Tavg);
   fChain->SetBranchAddress("sbs.gemCeR.hit.Tavg", sbs_gemCeR_hit_Tavg, &b_sbs_gemCeR_hit_Tavg);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.Tavg_corr", &Ndata_sbs_gemCeR_hit_Tavg_corr, &b_Ndata_sbs_gemCeR_hit_Tavg_corr);
   fChain->SetBranchAddress("sbs.gemCeR.hit.Tavg_corr", sbs_gemCeR_hit_Tavg_corr, &b_sbs_gemCeR_hit_Tavg_corr);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.Tavg_deconv", &Ndata_sbs_gemCeR_hit_Tavg_deconv, &b_Ndata_sbs_gemCeR_hit_Tavg_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.Tavg_deconv", sbs_gemCeR_hit_Tavg_deconv, &b_sbs_gemCeR_hit_Tavg_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.Tavg_fit", &Ndata_sbs_gemCeR_hit_Tavg_fit, &b_Ndata_sbs_gemCeR_hit_Tavg_fit);
   fChain->SetBranchAddress("sbs.gemCeR.hit.Tavg_fit", sbs_gemCeR_hit_Tavg_fit, &b_sbs_gemCeR_hit_Tavg_fit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.Ugain", &Ndata_sbs_gemCeR_hit_Ugain, &b_Ndata_sbs_gemCeR_hit_Ugain);
   fChain->SetBranchAddress("sbs.gemCeR.hit.Ugain", sbs_gemCeR_hit_Ugain, &b_sbs_gemCeR_hit_Ugain);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.Utime", &Ndata_sbs_gemCeR_hit_Utime, &b_Ndata_sbs_gemCeR_hit_Utime);
   fChain->SetBranchAddress("sbs.gemCeR.hit.Utime", sbs_gemCeR_hit_Utime, &b_sbs_gemCeR_hit_Utime);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.UtimeDeconv", &Ndata_sbs_gemCeR_hit_UtimeDeconv, &b_Ndata_sbs_gemCeR_hit_UtimeDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.UtimeDeconv", sbs_gemCeR_hit_UtimeDeconv, &b_sbs_gemCeR_hit_UtimeDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.UtimeFit", &Ndata_sbs_gemCeR_hit_UtimeFit, &b_Ndata_sbs_gemCeR_hit_UtimeFit);
   fChain->SetBranchAddress("sbs.gemCeR.hit.UtimeFit", sbs_gemCeR_hit_UtimeFit, &b_sbs_gemCeR_hit_UtimeFit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.UtimeMaxStrip", &Ndata_sbs_gemCeR_hit_UtimeMaxStrip, &b_Ndata_sbs_gemCeR_hit_UtimeMaxStrip);
   fChain->SetBranchAddress("sbs.gemCeR.hit.UtimeMaxStrip", sbs_gemCeR_hit_UtimeMaxStrip, &b_sbs_gemCeR_hit_UtimeMaxStrip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.UtimeMaxStripDeconv", &Ndata_sbs_gemCeR_hit_UtimeMaxStripDeconv, &b_Ndata_sbs_gemCeR_hit_UtimeMaxStripDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.UtimeMaxStripDeconv", sbs_gemCeR_hit_UtimeMaxStripDeconv, &b_sbs_gemCeR_hit_UtimeMaxStripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.UtimeMaxStripFit", &Ndata_sbs_gemCeR_hit_UtimeMaxStripFit, &b_Ndata_sbs_gemCeR_hit_UtimeMaxStripFit);
   fChain->SetBranchAddress("sbs.gemCeR.hit.UtimeMaxStripFit", sbs_gemCeR_hit_UtimeMaxStripFit, &b_sbs_gemCeR_hit_UtimeMaxStripFit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.Vgain", &Ndata_sbs_gemCeR_hit_Vgain, &b_Ndata_sbs_gemCeR_hit_Vgain);
   fChain->SetBranchAddress("sbs.gemCeR.hit.Vgain", sbs_gemCeR_hit_Vgain, &b_sbs_gemCeR_hit_Vgain);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.Vtime", &Ndata_sbs_gemCeR_hit_Vtime, &b_Ndata_sbs_gemCeR_hit_Vtime);
   fChain->SetBranchAddress("sbs.gemCeR.hit.Vtime", sbs_gemCeR_hit_Vtime, &b_sbs_gemCeR_hit_Vtime);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.VtimeDeconv", &Ndata_sbs_gemCeR_hit_VtimeDeconv, &b_Ndata_sbs_gemCeR_hit_VtimeDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.VtimeDeconv", sbs_gemCeR_hit_VtimeDeconv, &b_sbs_gemCeR_hit_VtimeDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.VtimeFit", &Ndata_sbs_gemCeR_hit_VtimeFit, &b_Ndata_sbs_gemCeR_hit_VtimeFit);
   fChain->SetBranchAddress("sbs.gemCeR.hit.VtimeFit", sbs_gemCeR_hit_VtimeFit, &b_sbs_gemCeR_hit_VtimeFit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.VtimeMaxStrip", &Ndata_sbs_gemCeR_hit_VtimeMaxStrip, &b_Ndata_sbs_gemCeR_hit_VtimeMaxStrip);
   fChain->SetBranchAddress("sbs.gemCeR.hit.VtimeMaxStrip", sbs_gemCeR_hit_VtimeMaxStrip, &b_sbs_gemCeR_hit_VtimeMaxStrip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.VtimeMaxStripDeconv", &Ndata_sbs_gemCeR_hit_VtimeMaxStripDeconv, &b_Ndata_sbs_gemCeR_hit_VtimeMaxStripDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.VtimeMaxStripDeconv", sbs_gemCeR_hit_VtimeMaxStripDeconv, &b_sbs_gemCeR_hit_VtimeMaxStripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.VtimeMaxStripFit", &Ndata_sbs_gemCeR_hit_VtimeMaxStripFit, &b_Ndata_sbs_gemCeR_hit_VtimeMaxStripFit);
   fChain->SetBranchAddress("sbs.gemCeR.hit.VtimeMaxStripFit", sbs_gemCeR_hit_VtimeMaxStripFit, &b_sbs_gemCeR_hit_VtimeMaxStripFit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.adc_id_U", &Ndata_sbs_gemCeR_hit_adc_id_U, &b_Ndata_sbs_gemCeR_hit_adc_id_U);
   fChain->SetBranchAddress("sbs.gemCeR.hit.adc_id_U", sbs_gemCeR_hit_adc_id_U, &b_sbs_gemCeR_hit_adc_id_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.adc_id_V", &Ndata_sbs_gemCeR_hit_adc_id_V, &b_Ndata_sbs_gemCeR_hit_adc_id_V);
   fChain->SetBranchAddress("sbs.gemCeR.hit.adc_id_V", sbs_gemCeR_hit_adc_id_V, &b_sbs_gemCeR_hit_adc_id_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ccor_clust", &Ndata_sbs_gemCeR_hit_ccor_clust, &b_Ndata_sbs_gemCeR_hit_ccor_clust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ccor_clust", sbs_gemCeR_hit_ccor_clust, &b_sbs_gemCeR_hit_ccor_clust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ccor_clust_deconv", &Ndata_sbs_gemCeR_hit_ccor_clust_deconv, &b_Ndata_sbs_gemCeR_hit_ccor_clust_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ccor_clust_deconv", sbs_gemCeR_hit_ccor_clust_deconv, &b_sbs_gemCeR_hit_ccor_clust_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ccor_strip", &Ndata_sbs_gemCeR_hit_ccor_strip, &b_Ndata_sbs_gemCeR_hit_ccor_strip);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ccor_strip", sbs_gemCeR_hit_ccor_strip, &b_sbs_gemCeR_hit_ccor_strip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ccor_strip_deconv", &Ndata_sbs_gemCeR_hit_ccor_strip_deconv, &b_Ndata_sbs_gemCeR_hit_ccor_strip_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ccor_strip_deconv", sbs_gemCeR_hit_ccor_strip_deconv, &b_sbs_gemCeR_hit_ccor_strip_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.crate_U", &Ndata_sbs_gemCeR_hit_crate_U, &b_Ndata_sbs_gemCeR_hit_crate_U);
   fChain->SetBranchAddress("sbs.gemCeR.hit.crate_U", sbs_gemCeR_hit_crate_U, &b_sbs_gemCeR_hit_crate_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.crate_V", &Ndata_sbs_gemCeR_hit_crate_V, &b_Ndata_sbs_gemCeR_hit_crate_V);
   fChain->SetBranchAddress("sbs.gemCeR.hit.crate_V", sbs_gemCeR_hit_crate_V, &b_sbs_gemCeR_hit_crate_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.deltat", &Ndata_sbs_gemCeR_hit_deltat, &b_Ndata_sbs_gemCeR_hit_deltat);
   fChain->SetBranchAddress("sbs.gemCeR.hit.deltat", sbs_gemCeR_hit_deltat, &b_sbs_gemCeR_hit_deltat);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.deltat_deconv", &Ndata_sbs_gemCeR_hit_deltat_deconv, &b_Ndata_sbs_gemCeR_hit_deltat_deconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.deltat_deconv", sbs_gemCeR_hit_deltat_deconv, &b_sbs_gemCeR_hit_deltat_deconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.deltat_fit", &Ndata_sbs_gemCeR_hit_deltat_fit, &b_Ndata_sbs_gemCeR_hit_deltat_fit);
   fChain->SetBranchAddress("sbs.gemCeR.hit.deltat_fit", sbs_gemCeR_hit_deltat_fit, &b_sbs_gemCeR_hit_deltat_fit);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.eresidu", &Ndata_sbs_gemCeR_hit_eresidu, &b_Ndata_sbs_gemCeR_hit_eresidu);
   fChain->SetBranchAddress("sbs.gemCeR.hit.eresidu", sbs_gemCeR_hit_eresidu, &b_sbs_gemCeR_hit_eresidu);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.eresidv", &Ndata_sbs_gemCeR_hit_eresidv, &b_Ndata_sbs_gemCeR_hit_eresidv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.eresidv", sbs_gemCeR_hit_eresidv, &b_sbs_gemCeR_hit_eresidv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.icombomaxUclustDeconv", &Ndata_sbs_gemCeR_hit_icombomaxUclustDeconv, &b_Ndata_sbs_gemCeR_hit_icombomaxUclustDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.icombomaxUclustDeconv", sbs_gemCeR_hit_icombomaxUclustDeconv, &b_sbs_gemCeR_hit_icombomaxUclustDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.icombomaxUstripDeconv", &Ndata_sbs_gemCeR_hit_icombomaxUstripDeconv, &b_Ndata_sbs_gemCeR_hit_icombomaxUstripDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.icombomaxUstripDeconv", sbs_gemCeR_hit_icombomaxUstripDeconv, &b_sbs_gemCeR_hit_icombomaxUstripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.icombomaxVclustDeconv", &Ndata_sbs_gemCeR_hit_icombomaxVclustDeconv, &b_Ndata_sbs_gemCeR_hit_icombomaxVclustDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.icombomaxVclustDeconv", sbs_gemCeR_hit_icombomaxVclustDeconv, &b_sbs_gemCeR_hit_icombomaxVclustDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.icombomaxVstripDeconv", &Ndata_sbs_gemCeR_hit_icombomaxVstripDeconv, &b_Ndata_sbs_gemCeR_hit_icombomaxVstripDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.icombomaxVstripDeconv", sbs_gemCeR_hit_icombomaxVstripDeconv, &b_sbs_gemCeR_hit_icombomaxVstripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.isampmaxUclust", &Ndata_sbs_gemCeR_hit_isampmaxUclust, &b_Ndata_sbs_gemCeR_hit_isampmaxUclust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.isampmaxUclust", sbs_gemCeR_hit_isampmaxUclust, &b_sbs_gemCeR_hit_isampmaxUclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.isampmaxUclustDeconv", &Ndata_sbs_gemCeR_hit_isampmaxUclustDeconv, &b_Ndata_sbs_gemCeR_hit_isampmaxUclustDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.isampmaxUclustDeconv", sbs_gemCeR_hit_isampmaxUclustDeconv, &b_sbs_gemCeR_hit_isampmaxUclustDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.isampmaxUstrip", &Ndata_sbs_gemCeR_hit_isampmaxUstrip, &b_Ndata_sbs_gemCeR_hit_isampmaxUstrip);
   fChain->SetBranchAddress("sbs.gemCeR.hit.isampmaxUstrip", sbs_gemCeR_hit_isampmaxUstrip, &b_sbs_gemCeR_hit_isampmaxUstrip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.isampmaxUstripDeconv", &Ndata_sbs_gemCeR_hit_isampmaxUstripDeconv, &b_Ndata_sbs_gemCeR_hit_isampmaxUstripDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.isampmaxUstripDeconv", sbs_gemCeR_hit_isampmaxUstripDeconv, &b_sbs_gemCeR_hit_isampmaxUstripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.isampmaxVclust", &Ndata_sbs_gemCeR_hit_isampmaxVclust, &b_Ndata_sbs_gemCeR_hit_isampmaxVclust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.isampmaxVclust", sbs_gemCeR_hit_isampmaxVclust, &b_sbs_gemCeR_hit_isampmaxVclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.isampmaxVclustDeconv", &Ndata_sbs_gemCeR_hit_isampmaxVclustDeconv, &b_Ndata_sbs_gemCeR_hit_isampmaxVclustDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.isampmaxVclustDeconv", sbs_gemCeR_hit_isampmaxVclustDeconv, &b_sbs_gemCeR_hit_isampmaxVclustDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.isampmaxVstrip", &Ndata_sbs_gemCeR_hit_isampmaxVstrip, &b_Ndata_sbs_gemCeR_hit_isampmaxVstrip);
   fChain->SetBranchAddress("sbs.gemCeR.hit.isampmaxVstrip", sbs_gemCeR_hit_isampmaxVstrip, &b_sbs_gemCeR_hit_isampmaxVstrip);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.isampmaxVstripDeconv", &Ndata_sbs_gemCeR_hit_isampmaxVstripDeconv, &b_Ndata_sbs_gemCeR_hit_isampmaxVstripDeconv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.isampmaxVstripDeconv", sbs_gemCeR_hit_isampmaxVstripDeconv, &b_sbs_gemCeR_hit_isampmaxVstripDeconv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.layer", &Ndata_sbs_gemCeR_hit_layer, &b_Ndata_sbs_gemCeR_hit_layer);
   fChain->SetBranchAddress("sbs.gemCeR.hit.layer", sbs_gemCeR_hit_layer, &b_sbs_gemCeR_hit_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.module", &Ndata_sbs_gemCeR_hit_module, &b_Ndata_sbs_gemCeR_hit_module);
   fChain->SetBranchAddress("sbs.gemCeR.hit.module", sbs_gemCeR_hit_module, &b_sbs_gemCeR_hit_module);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.mpd_U", &Ndata_sbs_gemCeR_hit_mpd_U, &b_Ndata_sbs_gemCeR_hit_mpd_U);
   fChain->SetBranchAddress("sbs.gemCeR.hit.mpd_U", sbs_gemCeR_hit_mpd_U, &b_sbs_gemCeR_hit_mpd_U);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.mpd_V", &Ndata_sbs_gemCeR_hit_mpd_V, &b_Ndata_sbs_gemCeR_hit_mpd_V);
   fChain->SetBranchAddress("sbs.gemCeR.hit.mpd_V", sbs_gemCeR_hit_mpd_V, &b_sbs_gemCeR_hit_mpd_V);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.nstripu", &Ndata_sbs_gemCeR_hit_nstripu, &b_Ndata_sbs_gemCeR_hit_nstripu);
   fChain->SetBranchAddress("sbs.gemCeR.hit.nstripu", sbs_gemCeR_hit_nstripu, &b_sbs_gemCeR_hit_nstripu);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.nstripv", &Ndata_sbs_gemCeR_hit_nstripv, &b_Ndata_sbs_gemCeR_hit_nstripv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.nstripv", sbs_gemCeR_hit_nstripv, &b_sbs_gemCeR_hit_nstripv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.residu", &Ndata_sbs_gemCeR_hit_residu, &b_Ndata_sbs_gemCeR_hit_residu);
   fChain->SetBranchAddress("sbs.gemCeR.hit.residu", sbs_gemCeR_hit_residu, &b_sbs_gemCeR_hit_residu);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.residv", &Ndata_sbs_gemCeR_hit_residv, &b_Ndata_sbs_gemCeR_hit_residv);
   fChain->SetBranchAddress("sbs.gemCeR.hit.residv", sbs_gemCeR_hit_residv, &b_sbs_gemCeR_hit_residv);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.trackindex", &Ndata_sbs_gemCeR_hit_trackindex, &b_Ndata_sbs_gemCeR_hit_trackindex);
   fChain->SetBranchAddress("sbs.gemCeR.hit.trackindex", sbs_gemCeR_hit_trackindex, &b_sbs_gemCeR_hit_trackindex);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.u", &Ndata_sbs_gemCeR_hit_u, &b_Ndata_sbs_gemCeR_hit_u);
   fChain->SetBranchAddress("sbs.gemCeR.hit.u", sbs_gemCeR_hit_u, &b_sbs_gemCeR_hit_u);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.uTScorr_MaxStripU", &Ndata_sbs_gemCeR_hit_uTScorr_MaxStripU, &b_Ndata_sbs_gemCeR_hit_uTScorr_MaxStripU);
   fChain->SetBranchAddress("sbs.gemCeR.hit.uTScorr_MaxStripU", sbs_gemCeR_hit_uTScorr_MaxStripU, &b_sbs_gemCeR_hit_uTScorr_MaxStripU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.uTScorr_MaxStripV", &Ndata_sbs_gemCeR_hit_uTScorr_MaxStripV, &b_Ndata_sbs_gemCeR_hit_uTScorr_MaxStripV);
   fChain->SetBranchAddress("sbs.gemCeR.hit.uTScorr_MaxStripV", sbs_gemCeR_hit_uTScorr_MaxStripV, &b_sbs_gemCeR_hit_uTScorr_MaxStripV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.uTScorr_Uclust", &Ndata_sbs_gemCeR_hit_uTScorr_Uclust, &b_Ndata_sbs_gemCeR_hit_uTScorr_Uclust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.uTScorr_Uclust", sbs_gemCeR_hit_uTScorr_Uclust, &b_sbs_gemCeR_hit_uTScorr_Uclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.uTScorr_Vclust", &Ndata_sbs_gemCeR_hit_uTScorr_Vclust, &b_Ndata_sbs_gemCeR_hit_uTScorr_Vclust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.uTScorr_Vclust", sbs_gemCeR_hit_uTScorr_Vclust, &b_sbs_gemCeR_hit_uTScorr_Vclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.umoment", &Ndata_sbs_gemCeR_hit_umoment, &b_Ndata_sbs_gemCeR_hit_umoment);
   fChain->SetBranchAddress("sbs.gemCeR.hit.umoment", sbs_gemCeR_hit_umoment, &b_sbs_gemCeR_hit_umoment);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.usigma", &Ndata_sbs_gemCeR_hit_usigma, &b_Ndata_sbs_gemCeR_hit_usigma);
   fChain->SetBranchAddress("sbs.gemCeR.hit.usigma", sbs_gemCeR_hit_usigma, &b_sbs_gemCeR_hit_usigma);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ustriphi", &Ndata_sbs_gemCeR_hit_ustriphi, &b_Ndata_sbs_gemCeR_hit_ustriphi);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ustriphi", sbs_gemCeR_hit_ustriphi, &b_sbs_gemCeR_hit_ustriphi);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ustriplo", &Ndata_sbs_gemCeR_hit_ustriplo, &b_Ndata_sbs_gemCeR_hit_ustriplo);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ustriplo", sbs_gemCeR_hit_ustriplo, &b_sbs_gemCeR_hit_ustriplo);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ustripmax", &Ndata_sbs_gemCeR_hit_ustripmax, &b_Ndata_sbs_gemCeR_hit_ustripmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ustripmax", sbs_gemCeR_hit_ustripmax, &b_sbs_gemCeR_hit_ustripmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.v", &Ndata_sbs_gemCeR_hit_v, &b_Ndata_sbs_gemCeR_hit_v);
   fChain->SetBranchAddress("sbs.gemCeR.hit.v", sbs_gemCeR_hit_v, &b_sbs_gemCeR_hit_v);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.vmoment", &Ndata_sbs_gemCeR_hit_vmoment, &b_Ndata_sbs_gemCeR_hit_vmoment);
   fChain->SetBranchAddress("sbs.gemCeR.hit.vmoment", sbs_gemCeR_hit_vmoment, &b_sbs_gemCeR_hit_vmoment);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.vsigma", &Ndata_sbs_gemCeR_hit_vsigma, &b_Ndata_sbs_gemCeR_hit_vsigma);
   fChain->SetBranchAddress("sbs.gemCeR.hit.vsigma", sbs_gemCeR_hit_vsigma, &b_sbs_gemCeR_hit_vsigma);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.vstriphi", &Ndata_sbs_gemCeR_hit_vstriphi, &b_Ndata_sbs_gemCeR_hit_vstriphi);
   fChain->SetBranchAddress("sbs.gemCeR.hit.vstriphi", sbs_gemCeR_hit_vstriphi, &b_sbs_gemCeR_hit_vstriphi);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.vstriplo", &Ndata_sbs_gemCeR_hit_vstriplo, &b_Ndata_sbs_gemCeR_hit_vstriplo);
   fChain->SetBranchAddress("sbs.gemCeR.hit.vstriplo", sbs_gemCeR_hit_vstriplo, &b_sbs_gemCeR_hit_vstriplo);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.vstripmax", &Ndata_sbs_gemCeR_hit_vstripmax, &b_Ndata_sbs_gemCeR_hit_vstripmax);
   fChain->SetBranchAddress("sbs.gemCeR.hit.vstripmax", sbs_gemCeR_hit_vstripmax, &b_sbs_gemCeR_hit_vstripmax);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.wTScorr_MaxStripU", &Ndata_sbs_gemCeR_hit_wTScorr_MaxStripU, &b_Ndata_sbs_gemCeR_hit_wTScorr_MaxStripU);
   fChain->SetBranchAddress("sbs.gemCeR.hit.wTScorr_MaxStripU", sbs_gemCeR_hit_wTScorr_MaxStripU, &b_sbs_gemCeR_hit_wTScorr_MaxStripU);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.wTScorr_MaxStripV", &Ndata_sbs_gemCeR_hit_wTScorr_MaxStripV, &b_Ndata_sbs_gemCeR_hit_wTScorr_MaxStripV);
   fChain->SetBranchAddress("sbs.gemCeR.hit.wTScorr_MaxStripV", sbs_gemCeR_hit_wTScorr_MaxStripV, &b_sbs_gemCeR_hit_wTScorr_MaxStripV);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.wTScorr_Uclust", &Ndata_sbs_gemCeR_hit_wTScorr_Uclust, &b_Ndata_sbs_gemCeR_hit_wTScorr_Uclust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.wTScorr_Uclust", sbs_gemCeR_hit_wTScorr_Uclust, &b_sbs_gemCeR_hit_wTScorr_Uclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.wTScorr_Vclust", &Ndata_sbs_gemCeR_hit_wTScorr_Vclust, &b_Ndata_sbs_gemCeR_hit_wTScorr_Vclust);
   fChain->SetBranchAddress("sbs.gemCeR.hit.wTScorr_Vclust", sbs_gemCeR_hit_wTScorr_Vclust, &b_sbs_gemCeR_hit_wTScorr_Vclust);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.xglobal", &Ndata_sbs_gemCeR_hit_xglobal, &b_Ndata_sbs_gemCeR_hit_xglobal);
   fChain->SetBranchAddress("sbs.gemCeR.hit.xglobal", sbs_gemCeR_hit_xglobal, &b_sbs_gemCeR_hit_xglobal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.xlocal", &Ndata_sbs_gemCeR_hit_xlocal, &b_Ndata_sbs_gemCeR_hit_xlocal);
   fChain->SetBranchAddress("sbs.gemCeR.hit.xlocal", sbs_gemCeR_hit_xlocal, &b_sbs_gemCeR_hit_xlocal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.yglobal", &Ndata_sbs_gemCeR_hit_yglobal, &b_Ndata_sbs_gemCeR_hit_yglobal);
   fChain->SetBranchAddress("sbs.gemCeR.hit.yglobal", sbs_gemCeR_hit_yglobal, &b_sbs_gemCeR_hit_yglobal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.ylocal", &Ndata_sbs_gemCeR_hit_ylocal, &b_Ndata_sbs_gemCeR_hit_ylocal);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ylocal", sbs_gemCeR_hit_ylocal, &b_sbs_gemCeR_hit_ylocal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.hit.zglobal", &Ndata_sbs_gemCeR_hit_zglobal, &b_Ndata_sbs_gemCeR_hit_zglobal);
   fChain->SetBranchAddress("sbs.gemCeR.hit.zglobal", sbs_gemCeR_hit_zglobal, &b_sbs_gemCeR_hit_zglobal);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.n2Dhit_layer", &Ndata_sbs_gemCeR_n2Dhit_layer, &b_Ndata_sbs_gemCeR_n2Dhit_layer);
   fChain->SetBranchAddress("sbs.gemCeR.n2Dhit_layer", sbs_gemCeR_n2Dhit_layer, &b_sbs_gemCeR_n2Dhit_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.nclustu_layer", &Ndata_sbs_gemCeR_nclustu_layer, &b_Ndata_sbs_gemCeR_nclustu_layer);
   fChain->SetBranchAddress("sbs.gemCeR.nclustu_layer", sbs_gemCeR_nclustu_layer, &b_sbs_gemCeR_nclustu_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.nclustv_layer", &Ndata_sbs_gemCeR_nclustv_layer, &b_Ndata_sbs_gemCeR_nclustv_layer);
   fChain->SetBranchAddress("sbs.gemCeR.nclustv_layer", sbs_gemCeR_nclustv_layer, &b_sbs_gemCeR_nclustv_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.nstripsu_layer", &Ndata_sbs_gemCeR_nstripsu_layer, &b_Ndata_sbs_gemCeR_nstripsu_layer);
   fChain->SetBranchAddress("sbs.gemCeR.nstripsu_layer", sbs_gemCeR_nstripsu_layer, &b_sbs_gemCeR_nstripsu_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.nstripsv_layer", &Ndata_sbs_gemCeR_nstripsv_layer, &b_Ndata_sbs_gemCeR_nstripsv_layer);
   fChain->SetBranchAddress("sbs.gemCeR.nstripsv_layer", sbs_gemCeR_nstripsv_layer, &b_sbs_gemCeR_nstripsv_layer);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.chi2ndf", &Ndata_sbs_gemCeR_track_chi2ndf, &b_Ndata_sbs_gemCeR_track_chi2ndf);
   fChain->SetBranchAddress("sbs.gemCeR.track.chi2ndf", sbs_gemCeR_track_chi2ndf, &b_sbs_gemCeR_track_chi2ndf);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.chi2ndf_hitquality", &Ndata_sbs_gemCeR_track_chi2ndf_hitquality, &b_Ndata_sbs_gemCeR_track_chi2ndf_hitquality);
   fChain->SetBranchAddress("sbs.gemCeR.track.chi2ndf_hitquality", sbs_gemCeR_track_chi2ndf_hitquality, &b_sbs_gemCeR_track_chi2ndf_hitquality);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.ngoodhits", &Ndata_sbs_gemCeR_track_ngoodhits, &b_Ndata_sbs_gemCeR_track_ngoodhits);
   fChain->SetBranchAddress("sbs.gemCeR.track.ngoodhits", sbs_gemCeR_track_ngoodhits, &b_sbs_gemCeR_track_ngoodhits);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.nhits", &Ndata_sbs_gemCeR_track_nhits, &b_Ndata_sbs_gemCeR_track_nhits);
   fChain->SetBranchAddress("sbs.gemCeR.track.nhits", sbs_gemCeR_track_nhits, &b_sbs_gemCeR_track_nhits);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.phi", &Ndata_sbs_gemCeR_track_phi, &b_Ndata_sbs_gemCeR_track_phi);
   fChain->SetBranchAddress("sbs.gemCeR.track.phi", sbs_gemCeR_track_phi, &b_sbs_gemCeR_track_phi);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.sclose", &Ndata_sbs_gemCeR_track_sclose, &b_Ndata_sbs_gemCeR_track_sclose);
   fChain->SetBranchAddress("sbs.gemCeR.track.sclose", sbs_gemCeR_track_sclose, &b_sbs_gemCeR_track_sclose);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.t0", &Ndata_sbs_gemCeR_track_t0, &b_Ndata_sbs_gemCeR_track_t0);
   fChain->SetBranchAddress("sbs.gemCeR.track.t0", sbs_gemCeR_track_t0, &b_sbs_gemCeR_track_t0);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.theta", &Ndata_sbs_gemCeR_track_theta, &b_Ndata_sbs_gemCeR_track_theta);
   fChain->SetBranchAddress("sbs.gemCeR.track.theta", sbs_gemCeR_track_theta, &b_sbs_gemCeR_track_theta);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.x", &Ndata_sbs_gemCeR_track_x, &b_Ndata_sbs_gemCeR_track_x);
   fChain->SetBranchAddress("sbs.gemCeR.track.x", sbs_gemCeR_track_x, &b_sbs_gemCeR_track_x);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.xp", &Ndata_sbs_gemCeR_track_xp, &b_Ndata_sbs_gemCeR_track_xp);
   fChain->SetBranchAddress("sbs.gemCeR.track.xp", sbs_gemCeR_track_xp, &b_sbs_gemCeR_track_xp);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.y", &Ndata_sbs_gemCeR_track_y, &b_Ndata_sbs_gemCeR_track_y);
   fChain->SetBranchAddress("sbs.gemCeR.track.y", sbs_gemCeR_track_y, &b_sbs_gemCeR_track_y);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.yp", &Ndata_sbs_gemCeR_track_yp, &b_Ndata_sbs_gemCeR_track_yp);
   fChain->SetBranchAddress("sbs.gemCeR.track.yp", sbs_gemCeR_track_yp, &b_sbs_gemCeR_track_yp);
   fChain->SetBranchAddress("Ndata.sbs.gemCeR.track.zclose", &Ndata_sbs_gemCeR_track_zclose, &b_Ndata_sbs_gemCeR_track_zclose);
   fChain->SetBranchAddress("sbs.gemCeR.track.zclose", sbs_gemCeR_track_zclose, &b_sbs_gemCeR_track_zclose);
   fChain->SetBranchAddress("Ndata.sbs.hcal.Ref.tdc", &Ndata_sbs_hcal_Ref_tdc, &b_Ndata_sbs_hcal_Ref_tdc);
   fChain->SetBranchAddress("sbs.hcal.Ref.tdc", sbs_hcal_Ref_tdc, &b_sbs_hcal_Ref_tdc);
   fChain->SetBranchAddress("Ndata.sbs.hcal.Ref.tdc_mult", &Ndata_sbs_hcal_Ref_tdc_mult, &b_Ndata_sbs_hcal_Ref_tdc_mult);
   fChain->SetBranchAddress("sbs.hcal.Ref.tdc_mult", sbs_hcal_Ref_tdc_mult, &b_sbs_hcal_Ref_tdc_mult);
   fChain->SetBranchAddress("Ndata.sbs.hcal.Ref.tdcelemID", &Ndata_sbs_hcal_Ref_tdcelemID, &b_Ndata_sbs_hcal_Ref_tdcelemID);
   fChain->SetBranchAddress("sbs.hcal.Ref.tdcelemID", sbs_hcal_Ref_tdcelemID, &b_sbs_hcal_Ref_tdcelemID);
   fChain->SetBranchAddress("Ndata.sbs.hcal.a_amp_p", &Ndata_sbs_hcal_a_amp_p, &b_Ndata_sbs_hcal_a_amp_p);
   fChain->SetBranchAddress("sbs.hcal.a_amp_p", sbs_hcal_a_amp_p, &b_sbs_hcal_a_amp_p);
   fChain->SetBranchAddress("Ndata.sbs.hcal.a_c", &Ndata_sbs_hcal_a_c, &b_Ndata_sbs_hcal_a_c);
   fChain->SetBranchAddress("sbs.hcal.a_c", sbs_hcal_a_c, &b_sbs_hcal_a_c);
   fChain->SetBranchAddress("Ndata.sbs.hcal.a_p", &Ndata_sbs_hcal_a_p, &b_Ndata_sbs_hcal_a_p);
   fChain->SetBranchAddress("sbs.hcal.a_p", sbs_hcal_a_p, &b_sbs_hcal_a_p);
   fChain->SetBranchAddress("Ndata.sbs.hcal.a_time", &Ndata_sbs_hcal_a_time, &b_Ndata_sbs_hcal_a_time);
   fChain->SetBranchAddress("sbs.hcal.a_time", sbs_hcal_a_time, &b_sbs_hcal_a_time);
   fChain->SetBranchAddress("Ndata.sbs.hcal.adccol", &Ndata_sbs_hcal_adccol, &b_Ndata_sbs_hcal_adccol);
   fChain->SetBranchAddress("sbs.hcal.adccol", sbs_hcal_adccol, &b_sbs_hcal_adccol);
   fChain->SetBranchAddress("Ndata.sbs.hcal.adcelemID", &Ndata_sbs_hcal_adcelemID, &b_Ndata_sbs_hcal_adcelemID);
   fChain->SetBranchAddress("sbs.hcal.adcelemID", sbs_hcal_adcelemID, &b_sbs_hcal_adcelemID);
   fChain->SetBranchAddress("Ndata.sbs.hcal.adcrow", &Ndata_sbs_hcal_adcrow, &b_Ndata_sbs_hcal_adcrow);
   fChain->SetBranchAddress("sbs.hcal.adcrow", sbs_hcal_adcrow, &b_sbs_hcal_adcrow);
   fChain->SetBranchAddress("Ndata.sbs.hcal.adcxpos", &Ndata_sbs_hcal_adcxpos, &b_Ndata_sbs_hcal_adcxpos);
   fChain->SetBranchAddress("sbs.hcal.adcxpos", sbs_hcal_adcxpos, &b_sbs_hcal_adcxpos);
   fChain->SetBranchAddress("Ndata.sbs.hcal.adcypos", &Ndata_sbs_hcal_adcypos, &b_Ndata_sbs_hcal_adcypos);
   fChain->SetBranchAddress("sbs.hcal.adcypos", sbs_hcal_adcypos, &b_sbs_hcal_adcypos);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.adctime", &Ndata_sbs_hcal_clus_adctime, &b_Ndata_sbs_hcal_clus_adctime);
   fChain->SetBranchAddress("sbs.hcal.clus.adctime", sbs_hcal_clus_adctime, &b_sbs_hcal_clus_adctime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.again", &Ndata_sbs_hcal_clus_again, &b_Ndata_sbs_hcal_clus_again);
   fChain->SetBranchAddress("sbs.hcal.clus.again", sbs_hcal_clus_again, &b_sbs_hcal_clus_again);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.atimeblk", &Ndata_sbs_hcal_clus_atimeblk, &b_Ndata_sbs_hcal_clus_atimeblk);
   fChain->SetBranchAddress("sbs.hcal.clus.atimeblk", sbs_hcal_clus_atimeblk, &b_sbs_hcal_clus_atimeblk);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.col", &Ndata_sbs_hcal_clus_col, &b_Ndata_sbs_hcal_clus_col);
   fChain->SetBranchAddress("sbs.hcal.clus.col", sbs_hcal_clus_col, &b_sbs_hcal_clus_col);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.col_goodtdc", &Ndata_sbs_hcal_clus_col_goodtdc, &b_Ndata_sbs_hcal_clus_col_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.clus.col_goodtdc", sbs_hcal_clus_col_goodtdc, &b_sbs_hcal_clus_col_goodtdc);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.e", &Ndata_sbs_hcal_clus_e, &b_Ndata_sbs_hcal_clus_e);
   fChain->SetBranchAddress("sbs.hcal.clus.e", sbs_hcal_clus_e, &b_sbs_hcal_clus_e);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.e_goodtdc", &Ndata_sbs_hcal_clus_e_goodtdc, &b_Ndata_sbs_hcal_clus_e_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.clus.e_goodtdc", sbs_hcal_clus_e_goodtdc, &b_sbs_hcal_clus_e_goodtdc);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.eblk", &Ndata_sbs_hcal_clus_eblk, &b_Ndata_sbs_hcal_clus_eblk);
   fChain->SetBranchAddress("sbs.hcal.clus.eblk", sbs_hcal_clus_eblk, &b_sbs_hcal_clus_eblk);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.eblk_goodtdc", &Ndata_sbs_hcal_clus_eblk_goodtdc, &b_Ndata_sbs_hcal_clus_eblk_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.clus.eblk_goodtdc", sbs_hcal_clus_eblk_goodtdc, &b_sbs_hcal_clus_eblk_goodtdc);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.id", &Ndata_sbs_hcal_clus_id, &b_Ndata_sbs_hcal_clus_id);
   fChain->SetBranchAddress("sbs.hcal.clus.id", sbs_hcal_clus_id, &b_sbs_hcal_clus_id);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.id_goodtdc", &Ndata_sbs_hcal_clus_id_goodtdc, &b_Ndata_sbs_hcal_clus_id_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.clus.id_goodtdc", sbs_hcal_clus_id_goodtdc, &b_sbs_hcal_clus_id_goodtdc);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.nblk", &Ndata_sbs_hcal_clus_nblk, &b_Ndata_sbs_hcal_clus_nblk);
   fChain->SetBranchAddress("sbs.hcal.clus.nblk", sbs_hcal_clus_nblk, &b_sbs_hcal_clus_nblk);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.nblk_goodtdc", &Ndata_sbs_hcal_clus_nblk_goodtdc, &b_Ndata_sbs_hcal_clus_nblk_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.clus.nblk_goodtdc", sbs_hcal_clus_nblk_goodtdc, &b_sbs_hcal_clus_nblk_goodtdc);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.row", &Ndata_sbs_hcal_clus_row, &b_Ndata_sbs_hcal_clus_row);
   fChain->SetBranchAddress("sbs.hcal.clus.row", sbs_hcal_clus_row, &b_sbs_hcal_clus_row);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.row_goodtdc", &Ndata_sbs_hcal_clus_row_goodtdc, &b_Ndata_sbs_hcal_clus_row_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.clus.row_goodtdc", sbs_hcal_clus_row_goodtdc, &b_sbs_hcal_clus_row_goodtdc);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.tdctime", &Ndata_sbs_hcal_clus_tdctime, &b_Ndata_sbs_hcal_clus_tdctime);
   fChain->SetBranchAddress("sbs.hcal.clus.tdctime", sbs_hcal_clus_tdctime, &b_sbs_hcal_clus_tdctime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.tdctime_tw", &Ndata_sbs_hcal_clus_tdctime_tw, &b_Ndata_sbs_hcal_clus_tdctime_tw);
   fChain->SetBranchAddress("sbs.hcal.clus.tdctime_tw", sbs_hcal_clus_tdctime_tw, &b_sbs_hcal_clus_tdctime_tw);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.tdctimeblk", &Ndata_sbs_hcal_clus_tdctimeblk, &b_Ndata_sbs_hcal_clus_tdctimeblk);
   fChain->SetBranchAddress("sbs.hcal.clus.tdctimeblk", sbs_hcal_clus_tdctimeblk, &b_sbs_hcal_clus_tdctimeblk);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.tdctimeblk_tw", &Ndata_sbs_hcal_clus_tdctimeblk_tw, &b_Ndata_sbs_hcal_clus_tdctimeblk_tw);
   fChain->SetBranchAddress("sbs.hcal.clus.tdctimeblk_tw", sbs_hcal_clus_tdctimeblk_tw, &b_sbs_hcal_clus_tdctimeblk_tw);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.x", &Ndata_sbs_hcal_clus_x, &b_Ndata_sbs_hcal_clus_x);
   fChain->SetBranchAddress("sbs.hcal.clus.x", sbs_hcal_clus_x, &b_sbs_hcal_clus_x);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.y", &Ndata_sbs_hcal_clus_y, &b_Ndata_sbs_hcal_clus_y);
   fChain->SetBranchAddress("sbs.hcal.clus.y", sbs_hcal_clus_y, &b_sbs_hcal_clus_y);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.again", &Ndata_sbs_hcal_clus_blk_again, &b_Ndata_sbs_hcal_clus_blk_again);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.again", sbs_hcal_clus_blk_again, &b_sbs_hcal_clus_blk_again);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.atime", &Ndata_sbs_hcal_clus_blk_atime, &b_Ndata_sbs_hcal_clus_blk_atime);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.atime", sbs_hcal_clus_blk_atime, &b_sbs_hcal_clus_blk_atime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.col", &Ndata_sbs_hcal_clus_blk_col, &b_Ndata_sbs_hcal_clus_blk_col);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.col", sbs_hcal_clus_blk_col, &b_sbs_hcal_clus_blk_col);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.e", &Ndata_sbs_hcal_clus_blk_e, &b_Ndata_sbs_hcal_clus_blk_e);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.e", sbs_hcal_clus_blk_e, &b_sbs_hcal_clus_blk_e);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.id", &Ndata_sbs_hcal_clus_blk_id, &b_Ndata_sbs_hcal_clus_blk_id);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.id", sbs_hcal_clus_blk_id, &b_sbs_hcal_clus_blk_id);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.row", &Ndata_sbs_hcal_clus_blk_row, &b_Ndata_sbs_hcal_clus_blk_row);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.row", sbs_hcal_clus_blk_row, &b_sbs_hcal_clus_blk_row);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.tdctime", &Ndata_sbs_hcal_clus_blk_tdctime, &b_Ndata_sbs_hcal_clus_blk_tdctime);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.tdctime", sbs_hcal_clus_blk_tdctime, &b_sbs_hcal_clus_blk_tdctime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.tdctime_tw", &Ndata_sbs_hcal_clus_blk_tdctime_tw, &b_Ndata_sbs_hcal_clus_blk_tdctime_tw);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.tdctime_tw", sbs_hcal_clus_blk_tdctime_tw, &b_sbs_hcal_clus_blk_tdctime_tw);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.x", &Ndata_sbs_hcal_clus_blk_x, &b_Ndata_sbs_hcal_clus_blk_x);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.x", sbs_hcal_clus_blk_x, &b_sbs_hcal_clus_blk_x);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.y", &Ndata_sbs_hcal_clus_blk_y, &b_Ndata_sbs_hcal_clus_blk_y);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.y", sbs_hcal_clus_blk_y, &b_sbs_hcal_clus_blk_y);
   fChain->SetBranchAddress("Ndata.sbs.hcal.ped", &Ndata_sbs_hcal_ped, &b_Ndata_sbs_hcal_ped);
   fChain->SetBranchAddress("sbs.hcal.ped", sbs_hcal_ped, &b_sbs_hcal_ped);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.Ref.tdc", &Ndata_sbs_tdctrig_Ref_tdc, &b_Ndata_sbs_tdctrig_Ref_tdc);
   fChain->SetBranchAddress("sbs.tdctrig.Ref.tdc", sbs_tdctrig_Ref_tdc, &b_sbs_tdctrig_Ref_tdc);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.Ref.tdc_mult", &Ndata_sbs_tdctrig_Ref_tdc_mult, &b_Ndata_sbs_tdctrig_Ref_tdc_mult);
   fChain->SetBranchAddress("sbs.tdctrig.Ref.tdc_mult", sbs_tdctrig_Ref_tdc_mult, &b_sbs_tdctrig_Ref_tdc_mult);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.Ref.tdcelemID", &Ndata_sbs_tdctrig_Ref_tdcelemID, &b_Ndata_sbs_tdctrig_Ref_tdcelemID);
   fChain->SetBranchAddress("sbs.tdctrig.Ref.tdcelemID", sbs_tdctrig_Ref_tdcelemID, &b_sbs_tdctrig_Ref_tdcelemID);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.tdc", &Ndata_sbs_tdctrig_tdc, &b_Ndata_sbs_tdctrig_tdc);
   fChain->SetBranchAddress("sbs.tdctrig.tdc", sbs_tdctrig_tdc, &b_sbs_tdctrig_tdc);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.tdc_mult", &Ndata_sbs_tdctrig_tdc_mult, &b_Ndata_sbs_tdctrig_tdc_mult);
   fChain->SetBranchAddress("sbs.tdctrig.tdc_mult", sbs_tdctrig_tdc_mult, &b_sbs_tdctrig_tdc_mult);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.tdccol", &Ndata_sbs_tdctrig_tdccol, &b_Ndata_sbs_tdctrig_tdccol);
   fChain->SetBranchAddress("sbs.tdctrig.tdccol", sbs_tdctrig_tdccol, &b_sbs_tdctrig_tdccol);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.tdcelemID", &Ndata_sbs_tdctrig_tdcelemID, &b_Ndata_sbs_tdctrig_tdcelemID);
   fChain->SetBranchAddress("sbs.tdctrig.tdcelemID", sbs_tdctrig_tdcelemID, &b_sbs_tdctrig_tdcelemID);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.tdclayer", &Ndata_sbs_tdctrig_tdclayer, &b_Ndata_sbs_tdctrig_tdclayer);
   fChain->SetBranchAddress("sbs.tdctrig.tdclayer", sbs_tdctrig_tdclayer, &b_sbs_tdctrig_tdclayer);
   fChain->SetBranchAddress("Ndata.sbs.tdctrig.tdcrow", &Ndata_sbs_tdctrig_tdcrow, &b_Ndata_sbs_tdctrig_tdcrow);
   fChain->SetBranchAddress("sbs.tdctrig.tdcrow", sbs_tdctrig_tdcrow, &b_sbs_tdctrig_tdcrow);
   fChain->SetBranchAddress("Ndata.sbs.tr.beta", &Ndata_sbs_tr_beta, &b_Ndata_sbs_tr_beta);
   fChain->SetBranchAddress("sbs.tr.beta", sbs_tr_beta, &b_sbs_tr_beta);
   fChain->SetBranchAddress("Ndata.sbs.tr.chi2", &Ndata_sbs_tr_chi2, &b_Ndata_sbs_tr_chi2);
   fChain->SetBranchAddress("sbs.tr.chi2", sbs_tr_chi2, &b_sbs_tr_chi2);
   fChain->SetBranchAddress("Ndata.sbs.tr.d_ph", &Ndata_sbs_tr_d_ph, &b_Ndata_sbs_tr_d_ph);
   fChain->SetBranchAddress("sbs.tr.d_ph", sbs_tr_d_ph, &b_sbs_tr_d_ph);
   fChain->SetBranchAddress("Ndata.sbs.tr.d_th", &Ndata_sbs_tr_d_th, &b_Ndata_sbs_tr_d_th);
   fChain->SetBranchAddress("sbs.tr.d_th", sbs_tr_d_th, &b_sbs_tr_d_th);
   fChain->SetBranchAddress("Ndata.sbs.tr.d_x", &Ndata_sbs_tr_d_x, &b_Ndata_sbs_tr_d_x);
   fChain->SetBranchAddress("sbs.tr.d_x", sbs_tr_d_x, &b_sbs_tr_d_x);
   fChain->SetBranchAddress("Ndata.sbs.tr.d_y", &Ndata_sbs_tr_d_y, &b_Ndata_sbs_tr_d_y);
   fChain->SetBranchAddress("sbs.tr.d_y", sbs_tr_d_y, &b_sbs_tr_d_y);
   fChain->SetBranchAddress("Ndata.sbs.tr.dbeta", &Ndata_sbs_tr_dbeta, &b_Ndata_sbs_tr_dbeta);
   fChain->SetBranchAddress("sbs.tr.dbeta", sbs_tr_dbeta, &b_sbs_tr_dbeta);
   fChain->SetBranchAddress("Ndata.sbs.tr.dtime", &Ndata_sbs_tr_dtime, &b_Ndata_sbs_tr_dtime);
   fChain->SetBranchAddress("sbs.tr.dtime", sbs_tr_dtime, &b_sbs_tr_dtime);
   fChain->SetBranchAddress("Ndata.sbs.tr.flag", &Ndata_sbs_tr_flag, &b_Ndata_sbs_tr_flag);
   fChain->SetBranchAddress("sbs.tr.flag", sbs_tr_flag, &b_sbs_tr_flag);
   fChain->SetBranchAddress("Ndata.sbs.tr.ndof", &Ndata_sbs_tr_ndof, &b_Ndata_sbs_tr_ndof);
   fChain->SetBranchAddress("sbs.tr.ndof", sbs_tr_ndof, &b_sbs_tr_ndof);
   fChain->SetBranchAddress("Ndata.sbs.tr.p", &Ndata_sbs_tr_p, &b_Ndata_sbs_tr_p);
   fChain->SetBranchAddress("sbs.tr.p", sbs_tr_p, &b_sbs_tr_p);
   fChain->SetBranchAddress("Ndata.sbs.tr.pathl", &Ndata_sbs_tr_pathl, &b_Ndata_sbs_tr_pathl);
   fChain->SetBranchAddress("sbs.tr.pathl", sbs_tr_pathl, &b_sbs_tr_pathl);
   fChain->SetBranchAddress("Ndata.sbs.tr.ph", &Ndata_sbs_tr_ph, &b_Ndata_sbs_tr_ph);
   fChain->SetBranchAddress("sbs.tr.ph", sbs_tr_ph, &b_sbs_tr_ph);
   fChain->SetBranchAddress("Ndata.sbs.tr.px", &Ndata_sbs_tr_px, &b_Ndata_sbs_tr_px);
   fChain->SetBranchAddress("sbs.tr.px", sbs_tr_px, &b_sbs_tr_px);
   fChain->SetBranchAddress("Ndata.sbs.tr.py", &Ndata_sbs_tr_py, &b_Ndata_sbs_tr_py);
   fChain->SetBranchAddress("sbs.tr.py", sbs_tr_py, &b_sbs_tr_py);
   fChain->SetBranchAddress("Ndata.sbs.tr.pz", &Ndata_sbs_tr_pz, &b_Ndata_sbs_tr_pz);
   fChain->SetBranchAddress("sbs.tr.pz", sbs_tr_pz, &b_sbs_tr_pz);
   fChain->SetBranchAddress("Ndata.sbs.tr.r_ph", &Ndata_sbs_tr_r_ph, &b_Ndata_sbs_tr_r_ph);
   fChain->SetBranchAddress("sbs.tr.r_ph", sbs_tr_r_ph, &b_sbs_tr_r_ph);
   fChain->SetBranchAddress("Ndata.sbs.tr.r_th", &Ndata_sbs_tr_r_th, &b_Ndata_sbs_tr_r_th);
   fChain->SetBranchAddress("sbs.tr.r_th", sbs_tr_r_th, &b_sbs_tr_r_th);
   fChain->SetBranchAddress("Ndata.sbs.tr.r_x", &Ndata_sbs_tr_r_x, &b_Ndata_sbs_tr_r_x);
   fChain->SetBranchAddress("sbs.tr.r_x", sbs_tr_r_x, &b_sbs_tr_r_x);
   fChain->SetBranchAddress("Ndata.sbs.tr.r_y", &Ndata_sbs_tr_r_y, &b_Ndata_sbs_tr_r_y);
   fChain->SetBranchAddress("sbs.tr.r_y", sbs_tr_r_y, &b_sbs_tr_r_y);
   fChain->SetBranchAddress("Ndata.sbs.tr.tg_dp", &Ndata_sbs_tr_tg_dp, &b_Ndata_sbs_tr_tg_dp);
   fChain->SetBranchAddress("sbs.tr.tg_dp", sbs_tr_tg_dp, &b_sbs_tr_tg_dp);
   fChain->SetBranchAddress("Ndata.sbs.tr.tg_ph", &Ndata_sbs_tr_tg_ph, &b_Ndata_sbs_tr_tg_ph);
   fChain->SetBranchAddress("sbs.tr.tg_ph", sbs_tr_tg_ph, &b_sbs_tr_tg_ph);
   fChain->SetBranchAddress("Ndata.sbs.tr.tg_th", &Ndata_sbs_tr_tg_th, &b_Ndata_sbs_tr_tg_th);
   fChain->SetBranchAddress("sbs.tr.tg_th", sbs_tr_tg_th, &b_sbs_tr_tg_th);
   fChain->SetBranchAddress("Ndata.sbs.tr.tg_y", &Ndata_sbs_tr_tg_y, &b_Ndata_sbs_tr_tg_y);
   fChain->SetBranchAddress("sbs.tr.tg_y", sbs_tr_tg_y, &b_sbs_tr_tg_y);
   fChain->SetBranchAddress("Ndata.sbs.tr.th", &Ndata_sbs_tr_th, &b_Ndata_sbs_tr_th);
   fChain->SetBranchAddress("sbs.tr.th", sbs_tr_th, &b_sbs_tr_th);
   fChain->SetBranchAddress("Ndata.sbs.tr.time", &Ndata_sbs_tr_time, &b_Ndata_sbs_tr_time);
   fChain->SetBranchAddress("sbs.tr.time", sbs_tr_time, &b_sbs_tr_time);
   fChain->SetBranchAddress("Ndata.sbs.tr.vx", &Ndata_sbs_tr_vx, &b_Ndata_sbs_tr_vx);
   fChain->SetBranchAddress("sbs.tr.vx", sbs_tr_vx, &b_sbs_tr_vx);
   fChain->SetBranchAddress("Ndata.sbs.tr.vy", &Ndata_sbs_tr_vy, &b_Ndata_sbs_tr_vy);
   fChain->SetBranchAddress("sbs.tr.vy", sbs_tr_vy, &b_sbs_tr_vy);
   fChain->SetBranchAddress("Ndata.sbs.tr.vz", &Ndata_sbs_tr_vz, &b_Ndata_sbs_tr_vz);
   fChain->SetBranchAddress("sbs.tr.vz", sbs_tr_vz, &b_sbs_tr_vz);
   fChain->SetBranchAddress("Ndata.sbs.tr.x", &Ndata_sbs_tr_x, &b_Ndata_sbs_tr_x);
   fChain->SetBranchAddress("sbs.tr.x", sbs_tr_x, &b_sbs_tr_x);
   fChain->SetBranchAddress("Ndata.sbs.tr.y", &Ndata_sbs_tr_y, &b_Ndata_sbs_tr_y);
   fChain->SetBranchAddress("sbs.tr.y", sbs_tr_y, &b_sbs_tr_y);
   fChain->SetBranchAddress("Ndata.sbs.trig.a_amp_p", &Ndata_sbs_trig_a_amp_p, &b_Ndata_sbs_trig_a_amp_p);
   fChain->SetBranchAddress("sbs.trig.a_amp_p", sbs_trig_a_amp_p, &b_sbs_trig_a_amp_p);
   fChain->SetBranchAddress("Ndata.sbs.trig.a_p", &Ndata_sbs_trig_a_p, &b_Ndata_sbs_trig_a_p);
   fChain->SetBranchAddress("sbs.trig.a_p", sbs_trig_a_p, &b_sbs_trig_a_p);
   fChain->SetBranchAddress("Ndata.sbs.trig.a_time", &Ndata_sbs_trig_a_time, &b_Ndata_sbs_trig_a_time);
   fChain->SetBranchAddress("sbs.trig.a_time", sbs_trig_a_time, &b_sbs_trig_a_time);
   fChain->SetBranchAddress("Ndata.sbs.trig.adcelemID", &Ndata_sbs_trig_adcelemID, &b_Ndata_sbs_trig_adcelemID);
   fChain->SetBranchAddress("sbs.trig.adcelemID", sbs_trig_adcelemID, &b_sbs_trig_adcelemID);
   fChain->SetBranchAddress("Ndata.sbs.x_bcp", &Ndata_sbs_x_bcp, &b_Ndata_sbs_x_bcp);
   fChain->SetBranchAddress("sbs.x_bcp", sbs_x_bcp, &b_sbs_x_bcp);
   fChain->SetBranchAddress("Ndata.sbs.x_bcp_FPP", &Ndata_sbs_x_bcp_FPP, &b_Ndata_sbs_x_bcp_FPP);
   fChain->SetBranchAddress("sbs.x_bcp_FPP", sbs_x_bcp_FPP, &b_sbs_x_bcp_FPP);
   fChain->SetBranchAddress("Ndata.sbs.x_bcp_FT", &Ndata_sbs_x_bcp_FT, &b_Ndata_sbs_x_bcp_FT);
   fChain->SetBranchAddress("sbs.x_bcp_FT", sbs_x_bcp_FT, &b_sbs_x_bcp_FT);
   fChain->SetBranchAddress("Ndata.sbs.x_fcp", &Ndata_sbs_x_fcp, &b_Ndata_sbs_x_fcp);
   fChain->SetBranchAddress("sbs.x_fcp", sbs_x_fcp, &b_sbs_x_fcp);
   fChain->SetBranchAddress("Ndata.sbs.x_fcp_FPP", &Ndata_sbs_x_fcp_FPP, &b_Ndata_sbs_x_fcp_FPP);
   fChain->SetBranchAddress("sbs.x_fcp_FPP", sbs_x_fcp_FPP, &b_sbs_x_fcp_FPP);
   fChain->SetBranchAddress("Ndata.sbs.x_fcp_FT", &Ndata_sbs_x_fcp_FT, &b_Ndata_sbs_x_fcp_FT);
   fChain->SetBranchAddress("sbs.x_fcp_FT", sbs_x_fcp_FT, &b_sbs_x_fcp_FT);
   fChain->SetBranchAddress("Ndata.sbs.y_bcp", &Ndata_sbs_y_bcp, &b_Ndata_sbs_y_bcp);
   fChain->SetBranchAddress("sbs.y_bcp", sbs_y_bcp, &b_sbs_y_bcp);
   fChain->SetBranchAddress("Ndata.sbs.y_bcp_FPP", &Ndata_sbs_y_bcp_FPP, &b_Ndata_sbs_y_bcp_FPP);
   fChain->SetBranchAddress("sbs.y_bcp_FPP", sbs_y_bcp_FPP, &b_sbs_y_bcp_FPP);
   fChain->SetBranchAddress("Ndata.sbs.y_bcp_FT", &Ndata_sbs_y_bcp_FT, &b_Ndata_sbs_y_bcp_FT);
   fChain->SetBranchAddress("sbs.y_bcp_FT", sbs_y_bcp_FT, &b_sbs_y_bcp_FT);
   fChain->SetBranchAddress("Ndata.sbs.y_fcp", &Ndata_sbs_y_fcp, &b_Ndata_sbs_y_fcp);
   fChain->SetBranchAddress("sbs.y_fcp", sbs_y_fcp, &b_sbs_y_fcp);
   fChain->SetBranchAddress("Ndata.sbs.y_fcp_FPP", &Ndata_sbs_y_fcp_FPP, &b_Ndata_sbs_y_fcp_FPP);
   fChain->SetBranchAddress("sbs.y_fcp_FPP", sbs_y_fcp_FPP, &b_sbs_y_fcp_FPP);
   fChain->SetBranchAddress("Ndata.sbs.y_fcp_FT", &Ndata_sbs_y_fcp_FT, &b_Ndata_sbs_y_fcp_FT);
   fChain->SetBranchAddress("sbs.y_fcp_FT", sbs_y_fcp_FT, &b_sbs_y_fcp_FT);
   fChain->SetBranchAddress("Ndata.sbs.z_bcp", &Ndata_sbs_z_bcp, &b_Ndata_sbs_z_bcp);
   fChain->SetBranchAddress("sbs.z_bcp", sbs_z_bcp, &b_sbs_z_bcp);
   fChain->SetBranchAddress("Ndata.sbs.z_bcp_FPP", &Ndata_sbs_z_bcp_FPP, &b_Ndata_sbs_z_bcp_FPP);
   fChain->SetBranchAddress("sbs.z_bcp_FPP", sbs_z_bcp_FPP, &b_sbs_z_bcp_FPP);
   fChain->SetBranchAddress("Ndata.sbs.z_bcp_FT", &Ndata_sbs_z_bcp_FT, &b_Ndata_sbs_z_bcp_FT);
   fChain->SetBranchAddress("sbs.z_bcp_FT", sbs_z_bcp_FT, &b_sbs_z_bcp_FT);
   fChain->SetBranchAddress("Ndata.sbs.z_fcp", &Ndata_sbs_z_fcp, &b_Ndata_sbs_z_fcp);
   fChain->SetBranchAddress("sbs.z_fcp", sbs_z_fcp, &b_sbs_z_fcp);
   fChain->SetBranchAddress("Ndata.sbs.z_fcp_FPP", &Ndata_sbs_z_fcp_FPP, &b_Ndata_sbs_z_fcp_FPP);
   fChain->SetBranchAddress("sbs.z_fcp_FPP", sbs_z_fcp_FPP, &b_sbs_z_fcp_FPP);
   fChain->SetBranchAddress("Ndata.sbs.z_fcp_FT", &Ndata_sbs_z_fcp_FT, &b_Ndata_sbs_z_fcp_FT);
   fChain->SetBranchAddress("sbs.z_fcp_FT", sbs_z_fcp_FT, &b_sbs_z_fcp_FT);
   fChain->SetBranchAddress("BB.gold.beta", &BB_gold_beta, &b_BB_gold_beta);
   fChain->SetBranchAddress("BB.gold.dp", &BB_gold_dp, &b_BB_gold_dp);
   fChain->SetBranchAddress("BB.gold.index", &BB_gold_index, &b_BB_gold_index);
   fChain->SetBranchAddress("BB.gold.ok", &BB_gold_ok, &b_BB_gold_ok);
   fChain->SetBranchAddress("BB.gold.p", &BB_gold_p, &b_BB_gold_p);
   fChain->SetBranchAddress("BB.gold.ph", &BB_gold_ph, &b_BB_gold_ph);
   fChain->SetBranchAddress("BB.gold.px", &BB_gold_px, &b_BB_gold_px);
   fChain->SetBranchAddress("BB.gold.py", &BB_gold_py, &b_BB_gold_py);
   fChain->SetBranchAddress("BB.gold.pz", &BB_gold_pz, &b_BB_gold_pz);
   fChain->SetBranchAddress("BB.gold.th", &BB_gold_th, &b_BB_gold_th);
   fChain->SetBranchAddress("BB.gold.x", &BB_gold_x, &b_BB_gold_x);
   fChain->SetBranchAddress("BB.gold.y", &BB_gold_y, &b_BB_gold_y);
   fChain->SetBranchAddress("Lrb.BPMA.rawcur.1", &Lrb_BPMA_rawcur_1, &b_Lrb_BPMA_rawcur_1);
   fChain->SetBranchAddress("Lrb.BPMA.rawcur.2", &Lrb_BPMA_rawcur_2, &b_Lrb_BPMA_rawcur_2);
   fChain->SetBranchAddress("Lrb.BPMA.rawcur.3", &Lrb_BPMA_rawcur_3, &b_Lrb_BPMA_rawcur_3);
   fChain->SetBranchAddress("Lrb.BPMA.rawcur.4", &Lrb_BPMA_rawcur_4, &b_Lrb_BPMA_rawcur_4);
   fChain->SetBranchAddress("Lrb.BPMA.rotpos1", &Lrb_BPMA_rotpos1, &b_Lrb_BPMA_rotpos1);
   fChain->SetBranchAddress("Lrb.BPMA.rotpos2", &Lrb_BPMA_rotpos2, &b_Lrb_BPMA_rotpos2);
   fChain->SetBranchAddress("Lrb.BPMA.x", &Lrb_BPMA_x, &b_Lrb_BPMA_x);
   fChain->SetBranchAddress("Lrb.BPMA.y", &Lrb_BPMA_y, &b_Lrb_BPMA_y);
   fChain->SetBranchAddress("Lrb.BPMA.z", &Lrb_BPMA_z, &b_Lrb_BPMA_z);
   fChain->SetBranchAddress("Lrb.BPMB.rawcur.1", &Lrb_BPMB_rawcur_1, &b_Lrb_BPMB_rawcur_1);
   fChain->SetBranchAddress("Lrb.BPMB.rawcur.2", &Lrb_BPMB_rawcur_2, &b_Lrb_BPMB_rawcur_2);
   fChain->SetBranchAddress("Lrb.BPMB.rawcur.3", &Lrb_BPMB_rawcur_3, &b_Lrb_BPMB_rawcur_3);
   fChain->SetBranchAddress("Lrb.BPMB.rawcur.4", &Lrb_BPMB_rawcur_4, &b_Lrb_BPMB_rawcur_4);
   fChain->SetBranchAddress("Lrb.BPMB.rotpos1", &Lrb_BPMB_rotpos1, &b_Lrb_BPMB_rotpos1);
   fChain->SetBranchAddress("Lrb.BPMB.rotpos2", &Lrb_BPMB_rotpos2, &b_Lrb_BPMB_rotpos2);
   fChain->SetBranchAddress("Lrb.BPMB.x", &Lrb_BPMB_x, &b_Lrb_BPMB_x);
   fChain->SetBranchAddress("Lrb.BPMB.y", &Lrb_BPMB_y, &b_Lrb_BPMB_y);
   fChain->SetBranchAddress("Lrb.BPMB.z", &Lrb_BPMB_z, &b_Lrb_BPMB_z);
   fChain->SetBranchAddress("Lrb.Raster.bpma.x", &Lrb_Raster_bpma_x, &b_Lrb_Raster_bpma_x);
   fChain->SetBranchAddress("Lrb.Raster.bpma.y", &Lrb_Raster_bpma_y, &b_Lrb_Raster_bpma_y);
   fChain->SetBranchAddress("Lrb.Raster.bpma.z", &Lrb_Raster_bpma_z, &b_Lrb_Raster_bpma_z);
   fChain->SetBranchAddress("Lrb.Raster.bpmb.x", &Lrb_Raster_bpmb_x, &b_Lrb_Raster_bpmb_x);
   fChain->SetBranchAddress("Lrb.Raster.bpmb.y", &Lrb_Raster_bpmb_y, &b_Lrb_Raster_bpmb_y);
   fChain->SetBranchAddress("Lrb.Raster.bpmb.z", &Lrb_Raster_bpmb_z, &b_Lrb_Raster_bpmb_z);
   fChain->SetBranchAddress("Lrb.Raster.rawcur.x", &Lrb_Raster_rawcur_x, &b_Lrb_Raster_rawcur_x);
   fChain->SetBranchAddress("Lrb.Raster.rawcur.y", &Lrb_Raster_rawcur_y, &b_Lrb_Raster_rawcur_y);
   fChain->SetBranchAddress("Lrb.Raster.rawslope.x", &Lrb_Raster_rawslope_x, &b_Lrb_Raster_rawslope_x);
   fChain->SetBranchAddress("Lrb.Raster.rawslope.y", &Lrb_Raster_rawslope_y, &b_Lrb_Raster_rawslope_y);
   fChain->SetBranchAddress("Lrb.Raster.target.dir.x", &Lrb_Raster_target_dir_x, &b_Lrb_Raster_target_dir_x);
   fChain->SetBranchAddress("Lrb.Raster.target.dir.y", &Lrb_Raster_target_dir_y, &b_Lrb_Raster_target_dir_y);
   fChain->SetBranchAddress("Lrb.Raster.target.dir.z", &Lrb_Raster_target_dir_z, &b_Lrb_Raster_target_dir_z);
   fChain->SetBranchAddress("Lrb.Raster.target.x", &Lrb_Raster_target_x, &b_Lrb_Raster_target_x);
   fChain->SetBranchAddress("Lrb.Raster.target.y", &Lrb_Raster_target_y, &b_Lrb_Raster_target_y);
   fChain->SetBranchAddress("Lrb.Raster.target.z", &Lrb_Raster_target_z, &b_Lrb_Raster_target_z);
   fChain->SetBranchAddress("Lrb.Raster2.bpma.x", &Lrb_Raster2_bpma_x, &b_Lrb_Raster2_bpma_x);
   fChain->SetBranchAddress("Lrb.Raster2.bpma.y", &Lrb_Raster2_bpma_y, &b_Lrb_Raster2_bpma_y);
   fChain->SetBranchAddress("Lrb.Raster2.bpma.z", &Lrb_Raster2_bpma_z, &b_Lrb_Raster2_bpma_z);
   fChain->SetBranchAddress("Lrb.Raster2.bpmb.x", &Lrb_Raster2_bpmb_x, &b_Lrb_Raster2_bpmb_x);
   fChain->SetBranchAddress("Lrb.Raster2.bpmb.y", &Lrb_Raster2_bpmb_y, &b_Lrb_Raster2_bpmb_y);
   fChain->SetBranchAddress("Lrb.Raster2.bpmb.z", &Lrb_Raster2_bpmb_z, &b_Lrb_Raster2_bpmb_z);
   fChain->SetBranchAddress("Lrb.Raster2.rawcur.x", &Lrb_Raster2_rawcur_x, &b_Lrb_Raster2_rawcur_x);
   fChain->SetBranchAddress("Lrb.Raster2.rawcur.y", &Lrb_Raster2_rawcur_y, &b_Lrb_Raster2_rawcur_y);
   fChain->SetBranchAddress("Lrb.Raster2.rawslope.x", &Lrb_Raster2_rawslope_x, &b_Lrb_Raster2_rawslope_x);
   fChain->SetBranchAddress("Lrb.Raster2.rawslope.y", &Lrb_Raster2_rawslope_y, &b_Lrb_Raster2_rawslope_y);
   fChain->SetBranchAddress("Lrb.Raster2.target.dir.x", &Lrb_Raster2_target_dir_x, &b_Lrb_Raster2_target_dir_x);
   fChain->SetBranchAddress("Lrb.Raster2.target.dir.y", &Lrb_Raster2_target_dir_y, &b_Lrb_Raster2_target_dir_y);
   fChain->SetBranchAddress("Lrb.Raster2.target.dir.z", &Lrb_Raster2_target_dir_z, &b_Lrb_Raster2_target_dir_z);
   fChain->SetBranchAddress("Lrb.Raster2.target.x", &Lrb_Raster2_target_x, &b_Lrb_Raster2_target_x);
   fChain->SetBranchAddress("Lrb.Raster2.target.y", &Lrb_Raster2_target_y, &b_Lrb_Raster2_target_y);
   fChain->SetBranchAddress("Lrb.Raster2.target.z", &Lrb_Raster2_target_z, &b_Lrb_Raster2_target_z);
   fChain->SetBranchAddress("SBS.gold.beta", &SBS_gold_beta, &b_SBS_gold_beta);
   fChain->SetBranchAddress("SBS.gold.dp", &SBS_gold_dp, &b_SBS_gold_dp);
   fChain->SetBranchAddress("SBS.gold.index", &SBS_gold_index, &b_SBS_gold_index);
   fChain->SetBranchAddress("SBS.gold.ok", &SBS_gold_ok, &b_SBS_gold_ok);
   fChain->SetBranchAddress("SBS.gold.p", &SBS_gold_p, &b_SBS_gold_p);
   fChain->SetBranchAddress("SBS.gold.ph", &SBS_gold_ph, &b_SBS_gold_ph);
   fChain->SetBranchAddress("SBS.gold.px", &SBS_gold_px, &b_SBS_gold_px);
   fChain->SetBranchAddress("SBS.gold.py", &SBS_gold_py, &b_SBS_gold_py);
   fChain->SetBranchAddress("SBS.gold.pz", &SBS_gold_pz, &b_SBS_gold_pz);
   fChain->SetBranchAddress("SBS.gold.th", &SBS_gold_th, &b_SBS_gold_th);
   fChain->SetBranchAddress("SBS.gold.x", &SBS_gold_x, &b_SBS_gold_x);
   fChain->SetBranchAddress("SBS.gold.y", &SBS_gold_y, &b_SBS_gold_y);
   fChain->SetBranchAddress("SBSrb.BPMA.rawcur.1", &SBSrb_BPMA_rawcur_1, &b_SBSrb_BPMA_rawcur_1);
   fChain->SetBranchAddress("SBSrb.BPMA.rawcur.2", &SBSrb_BPMA_rawcur_2, &b_SBSrb_BPMA_rawcur_2);
   fChain->SetBranchAddress("SBSrb.BPMA.rawcur.3", &SBSrb_BPMA_rawcur_3, &b_SBSrb_BPMA_rawcur_3);
   fChain->SetBranchAddress("SBSrb.BPMA.rawcur.4", &SBSrb_BPMA_rawcur_4, &b_SBSrb_BPMA_rawcur_4);
   fChain->SetBranchAddress("SBSrb.BPMA.rotpos1", &SBSrb_BPMA_rotpos1, &b_SBSrb_BPMA_rotpos1);
   fChain->SetBranchAddress("SBSrb.BPMA.rotpos2", &SBSrb_BPMA_rotpos2, &b_SBSrb_BPMA_rotpos2);
   fChain->SetBranchAddress("SBSrb.BPMA.x", &SBSrb_BPMA_x, &b_SBSrb_BPMA_x);
   fChain->SetBranchAddress("SBSrb.BPMA.y", &SBSrb_BPMA_y, &b_SBSrb_BPMA_y);
   fChain->SetBranchAddress("SBSrb.BPMA.z", &SBSrb_BPMA_z, &b_SBSrb_BPMA_z);
   fChain->SetBranchAddress("SBSrb.BPMB.rawcur.1", &SBSrb_BPMB_rawcur_1, &b_SBSrb_BPMB_rawcur_1);
   fChain->SetBranchAddress("SBSrb.BPMB.rawcur.2", &SBSrb_BPMB_rawcur_2, &b_SBSrb_BPMB_rawcur_2);
   fChain->SetBranchAddress("SBSrb.BPMB.rawcur.3", &SBSrb_BPMB_rawcur_3, &b_SBSrb_BPMB_rawcur_3);
   fChain->SetBranchAddress("SBSrb.BPMB.rawcur.4", &SBSrb_BPMB_rawcur_4, &b_SBSrb_BPMB_rawcur_4);
   fChain->SetBranchAddress("SBSrb.BPMB.rotpos1", &SBSrb_BPMB_rotpos1, &b_SBSrb_BPMB_rotpos1);
   fChain->SetBranchAddress("SBSrb.BPMB.rotpos2", &SBSrb_BPMB_rotpos2, &b_SBSrb_BPMB_rotpos2);
   fChain->SetBranchAddress("SBSrb.BPMB.x", &SBSrb_BPMB_x, &b_SBSrb_BPMB_x);
   fChain->SetBranchAddress("SBSrb.BPMB.y", &SBSrb_BPMB_y, &b_SBSrb_BPMB_y);
   fChain->SetBranchAddress("SBSrb.BPMB.z", &SBSrb_BPMB_z, &b_SBSrb_BPMB_z);
   fChain->SetBranchAddress("SBSrb.Raster.bpma.x", &SBSrb_Raster_bpma_x, &b_SBSrb_Raster_bpma_x);
   fChain->SetBranchAddress("SBSrb.Raster.bpma.y", &SBSrb_Raster_bpma_y, &b_SBSrb_Raster_bpma_y);
   fChain->SetBranchAddress("SBSrb.Raster.bpma.z", &SBSrb_Raster_bpma_z, &b_SBSrb_Raster_bpma_z);
   fChain->SetBranchAddress("SBSrb.Raster.bpmb.x", &SBSrb_Raster_bpmb_x, &b_SBSrb_Raster_bpmb_x);
   fChain->SetBranchAddress("SBSrb.Raster.bpmb.y", &SBSrb_Raster_bpmb_y, &b_SBSrb_Raster_bpmb_y);
   fChain->SetBranchAddress("SBSrb.Raster.bpmb.z", &SBSrb_Raster_bpmb_z, &b_SBSrb_Raster_bpmb_z);
   fChain->SetBranchAddress("SBSrb.Raster.rawcur.x", &SBSrb_Raster_rawcur_x, &b_SBSrb_Raster_rawcur_x);
   fChain->SetBranchAddress("SBSrb.Raster.rawcur.y", &SBSrb_Raster_rawcur_y, &b_SBSrb_Raster_rawcur_y);
   fChain->SetBranchAddress("SBSrb.Raster.rawslope.x", &SBSrb_Raster_rawslope_x, &b_SBSrb_Raster_rawslope_x);
   fChain->SetBranchAddress("SBSrb.Raster.rawslope.y", &SBSrb_Raster_rawslope_y, &b_SBSrb_Raster_rawslope_y);
   fChain->SetBranchAddress("SBSrb.Raster.target.dir.x", &SBSrb_Raster_target_dir_x, &b_SBSrb_Raster_target_dir_x);
   fChain->SetBranchAddress("SBSrb.Raster.target.dir.y", &SBSrb_Raster_target_dir_y, &b_SBSrb_Raster_target_dir_y);
   fChain->SetBranchAddress("SBSrb.Raster.target.dir.z", &SBSrb_Raster_target_dir_z, &b_SBSrb_Raster_target_dir_z);
   fChain->SetBranchAddress("SBSrb.Raster.target.x", &SBSrb_Raster_target_x, &b_SBSrb_Raster_target_x);
   fChain->SetBranchAddress("SBSrb.Raster.target.y", &SBSrb_Raster_target_y, &b_SBSrb_Raster_target_y);
   fChain->SetBranchAddress("SBSrb.Raster.target.z", &SBSrb_Raster_target_z, &b_SBSrb_Raster_target_z);
   fChain->SetBranchAddress("SBSrb.Raster2.bpma.x", &SBSrb_Raster2_bpma_x, &b_SBSrb_Raster2_bpma_x);
   fChain->SetBranchAddress("SBSrb.Raster2.bpma.y", &SBSrb_Raster2_bpma_y, &b_SBSrb_Raster2_bpma_y);
   fChain->SetBranchAddress("SBSrb.Raster2.bpma.z", &SBSrb_Raster2_bpma_z, &b_SBSrb_Raster2_bpma_z);
   fChain->SetBranchAddress("SBSrb.Raster2.bpmb.x", &SBSrb_Raster2_bpmb_x, &b_SBSrb_Raster2_bpmb_x);
   fChain->SetBranchAddress("SBSrb.Raster2.bpmb.y", &SBSrb_Raster2_bpmb_y, &b_SBSrb_Raster2_bpmb_y);
   fChain->SetBranchAddress("SBSrb.Raster2.bpmb.z", &SBSrb_Raster2_bpmb_z, &b_SBSrb_Raster2_bpmb_z);
   fChain->SetBranchAddress("SBSrb.Raster2.rawcur.x", &SBSrb_Raster2_rawcur_x, &b_SBSrb_Raster2_rawcur_x);
   fChain->SetBranchAddress("SBSrb.Raster2.rawcur.y", &SBSrb_Raster2_rawcur_y, &b_SBSrb_Raster2_rawcur_y);
   fChain->SetBranchAddress("SBSrb.Raster2.rawslope.x", &SBSrb_Raster2_rawslope_x, &b_SBSrb_Raster2_rawslope_x);
   fChain->SetBranchAddress("SBSrb.Raster2.rawslope.y", &SBSrb_Raster2_rawslope_y, &b_SBSrb_Raster2_rawslope_y);
   fChain->SetBranchAddress("SBSrb.Raster2.target.dir.x", &SBSrb_Raster2_target_dir_x, &b_SBSrb_Raster2_target_dir_x);
   fChain->SetBranchAddress("SBSrb.Raster2.target.dir.y", &SBSrb_Raster2_target_dir_y, &b_SBSrb_Raster2_target_dir_y);
   fChain->SetBranchAddress("SBSrb.Raster2.target.dir.z", &SBSrb_Raster2_target_dir_z, &b_SBSrb_Raster2_target_dir_z);
   fChain->SetBranchAddress("SBSrb.Raster2.target.x", &SBSrb_Raster2_target_x, &b_SBSrb_Raster2_target_x);
   fChain->SetBranchAddress("SBSrb.Raster2.target.y", &SBSrb_Raster2_target_y, &b_SBSrb_Raster2_target_y);
   fChain->SetBranchAddress("SBSrb.Raster2.target.z", &SBSrb_Raster2_target_z, &b_SBSrb_Raster2_target_z);
   fChain->SetBranchAddress("bb.gem.hit.ngoodhits", &bb_gem_hit_ngoodhits, &b_bb_gem_hit_ngoodhits);
   fChain->SetBranchAddress("bb.gem.m0.clust.nclustu", &bb_gem_m0_clust_nclustu, &b_bb_gem_m0_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m0.clust.nclustu_tot", &bb_gem_m0_clust_nclustu_tot, &b_bb_gem_m0_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m0.clust.nclustv", &bb_gem_m0_clust_nclustv, &b_bb_gem_m0_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m0.clust.nclustv_tot", &bb_gem_m0_clust_nclustv_tot, &b_bb_gem_m0_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keep", &bb_gem_m0_strip_nstrips_keep, &b_bb_gem_m0_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keepU", &bb_gem_m0_strip_nstrips_keepU, &b_bb_gem_m0_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keepV", &bb_gem_m0_strip_nstrips_keepV, &b_bb_gem_m0_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keep_lmax", &bb_gem_m0_strip_nstrips_keep_lmax, &b_bb_gem_m0_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keep_lmaxU", &bb_gem_m0_strip_nstrips_keep_lmaxU, &b_bb_gem_m0_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keep_lmaxV", &bb_gem_m0_strip_nstrips_keep_lmaxV, &b_bb_gem_m0_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstripsfired", &bb_gem_m0_strip_nstripsfired, &b_bb_gem_m0_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m1.clust.nclustu", &bb_gem_m1_clust_nclustu, &b_bb_gem_m1_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m1.clust.nclustu_tot", &bb_gem_m1_clust_nclustu_tot, &b_bb_gem_m1_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m1.clust.nclustv", &bb_gem_m1_clust_nclustv, &b_bb_gem_m1_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m1.clust.nclustv_tot", &bb_gem_m1_clust_nclustv_tot, &b_bb_gem_m1_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keep", &bb_gem_m1_strip_nstrips_keep, &b_bb_gem_m1_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keepU", &bb_gem_m1_strip_nstrips_keepU, &b_bb_gem_m1_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keepV", &bb_gem_m1_strip_nstrips_keepV, &b_bb_gem_m1_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keep_lmax", &bb_gem_m1_strip_nstrips_keep_lmax, &b_bb_gem_m1_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keep_lmaxU", &bb_gem_m1_strip_nstrips_keep_lmaxU, &b_bb_gem_m1_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keep_lmaxV", &bb_gem_m1_strip_nstrips_keep_lmaxV, &b_bb_gem_m1_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstripsfired", &bb_gem_m1_strip_nstripsfired, &b_bb_gem_m1_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m2.clust.nclustu", &bb_gem_m2_clust_nclustu, &b_bb_gem_m2_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m2.clust.nclustu_tot", &bb_gem_m2_clust_nclustu_tot, &b_bb_gem_m2_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m2.clust.nclustv", &bb_gem_m2_clust_nclustv, &b_bb_gem_m2_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m2.clust.nclustv_tot", &bb_gem_m2_clust_nclustv_tot, &b_bb_gem_m2_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keep", &bb_gem_m2_strip_nstrips_keep, &b_bb_gem_m2_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keepU", &bb_gem_m2_strip_nstrips_keepU, &b_bb_gem_m2_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keepV", &bb_gem_m2_strip_nstrips_keepV, &b_bb_gem_m2_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keep_lmax", &bb_gem_m2_strip_nstrips_keep_lmax, &b_bb_gem_m2_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keep_lmaxU", &bb_gem_m2_strip_nstrips_keep_lmaxU, &b_bb_gem_m2_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keep_lmaxV", &bb_gem_m2_strip_nstrips_keep_lmaxV, &b_bb_gem_m2_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstripsfired", &bb_gem_m2_strip_nstripsfired, &b_bb_gem_m2_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m3.clust.nclustu", &bb_gem_m3_clust_nclustu, &b_bb_gem_m3_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m3.clust.nclustu_tot", &bb_gem_m3_clust_nclustu_tot, &b_bb_gem_m3_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m3.clust.nclustv", &bb_gem_m3_clust_nclustv, &b_bb_gem_m3_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m3.clust.nclustv_tot", &bb_gem_m3_clust_nclustv_tot, &b_bb_gem_m3_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keep", &bb_gem_m3_strip_nstrips_keep, &b_bb_gem_m3_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keepU", &bb_gem_m3_strip_nstrips_keepU, &b_bb_gem_m3_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keepV", &bb_gem_m3_strip_nstrips_keepV, &b_bb_gem_m3_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keep_lmax", &bb_gem_m3_strip_nstrips_keep_lmax, &b_bb_gem_m3_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keep_lmaxU", &bb_gem_m3_strip_nstrips_keep_lmaxU, &b_bb_gem_m3_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keep_lmaxV", &bb_gem_m3_strip_nstrips_keep_lmaxV, &b_bb_gem_m3_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstripsfired", &bb_gem_m3_strip_nstripsfired, &b_bb_gem_m3_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m4.clust.nclustu", &bb_gem_m4_clust_nclustu, &b_bb_gem_m4_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m4.clust.nclustu_tot", &bb_gem_m4_clust_nclustu_tot, &b_bb_gem_m4_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m4.clust.nclustv", &bb_gem_m4_clust_nclustv, &b_bb_gem_m4_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m4.clust.nclustv_tot", &bb_gem_m4_clust_nclustv_tot, &b_bb_gem_m4_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keep", &bb_gem_m4_strip_nstrips_keep, &b_bb_gem_m4_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keepU", &bb_gem_m4_strip_nstrips_keepU, &b_bb_gem_m4_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keepV", &bb_gem_m4_strip_nstrips_keepV, &b_bb_gem_m4_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keep_lmax", &bb_gem_m4_strip_nstrips_keep_lmax, &b_bb_gem_m4_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keep_lmaxU", &bb_gem_m4_strip_nstrips_keep_lmaxU, &b_bb_gem_m4_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keep_lmaxV", &bb_gem_m4_strip_nstrips_keep_lmaxV, &b_bb_gem_m4_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstripsfired", &bb_gem_m4_strip_nstripsfired, &b_bb_gem_m4_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m5.clust.nclustu", &bb_gem_m5_clust_nclustu, &b_bb_gem_m5_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m5.clust.nclustu_tot", &bb_gem_m5_clust_nclustu_tot, &b_bb_gem_m5_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m5.clust.nclustv", &bb_gem_m5_clust_nclustv, &b_bb_gem_m5_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m5.clust.nclustv_tot", &bb_gem_m5_clust_nclustv_tot, &b_bb_gem_m5_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keep", &bb_gem_m5_strip_nstrips_keep, &b_bb_gem_m5_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keepU", &bb_gem_m5_strip_nstrips_keepU, &b_bb_gem_m5_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keepV", &bb_gem_m5_strip_nstrips_keepV, &b_bb_gem_m5_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keep_lmax", &bb_gem_m5_strip_nstrips_keep_lmax, &b_bb_gem_m5_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keep_lmaxU", &bb_gem_m5_strip_nstrips_keep_lmaxU, &b_bb_gem_m5_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keep_lmaxV", &bb_gem_m5_strip_nstrips_keep_lmaxV, &b_bb_gem_m5_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstripsfired", &bb_gem_m5_strip_nstripsfired, &b_bb_gem_m5_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m6.clust.nclustu", &bb_gem_m6_clust_nclustu, &b_bb_gem_m6_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m6.clust.nclustu_tot", &bb_gem_m6_clust_nclustu_tot, &b_bb_gem_m6_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m6.clust.nclustv", &bb_gem_m6_clust_nclustv, &b_bb_gem_m6_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m6.clust.nclustv_tot", &bb_gem_m6_clust_nclustv_tot, &b_bb_gem_m6_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keep", &bb_gem_m6_strip_nstrips_keep, &b_bb_gem_m6_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keepU", &bb_gem_m6_strip_nstrips_keepU, &b_bb_gem_m6_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keepV", &bb_gem_m6_strip_nstrips_keepV, &b_bb_gem_m6_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keep_lmax", &bb_gem_m6_strip_nstrips_keep_lmax, &b_bb_gem_m6_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keep_lmaxU", &bb_gem_m6_strip_nstrips_keep_lmaxU, &b_bb_gem_m6_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keep_lmaxV", &bb_gem_m6_strip_nstrips_keep_lmaxV, &b_bb_gem_m6_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstripsfired", &bb_gem_m6_strip_nstripsfired, &b_bb_gem_m6_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m7.clust.nclustu", &bb_gem_m7_clust_nclustu, &b_bb_gem_m7_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m7.clust.nclustu_tot", &bb_gem_m7_clust_nclustu_tot, &b_bb_gem_m7_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m7.clust.nclustv", &bb_gem_m7_clust_nclustv, &b_bb_gem_m7_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m7.clust.nclustv_tot", &bb_gem_m7_clust_nclustv_tot, &b_bb_gem_m7_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keep", &bb_gem_m7_strip_nstrips_keep, &b_bb_gem_m7_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keepU", &bb_gem_m7_strip_nstrips_keepU, &b_bb_gem_m7_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keepV", &bb_gem_m7_strip_nstrips_keepV, &b_bb_gem_m7_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keep_lmax", &bb_gem_m7_strip_nstrips_keep_lmax, &b_bb_gem_m7_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keep_lmaxU", &bb_gem_m7_strip_nstrips_keep_lmaxU, &b_bb_gem_m7_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keep_lmaxV", &bb_gem_m7_strip_nstrips_keep_lmaxV, &b_bb_gem_m7_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstripsfired", &bb_gem_m7_strip_nstripsfired, &b_bb_gem_m7_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.nlayershit", &bb_gem_nlayershit, &b_bb_gem_nlayershit);
   fChain->SetBranchAddress("bb.gem.nlayershitu", &bb_gem_nlayershitu, &b_bb_gem_nlayershitu);
   fChain->SetBranchAddress("bb.gem.nlayershituv", &bb_gem_nlayershituv, &b_bb_gem_nlayershituv);
   fChain->SetBranchAddress("bb.gem.nlayershitv", &bb_gem_nlayershitv, &b_bb_gem_nlayershitv);
   fChain->SetBranchAddress("bb.gem.track.besttrack", &bb_gem_track_besttrack, &b_bb_gem_track_besttrack);
   fChain->SetBranchAddress("bb.gem.track.ntrack", &bb_gem_track_ntrack, &b_bb_gem_track_ntrack);
   fChain->SetBranchAddress("bb.gem.trigtime", &bb_gem_trigtime, &b_bb_gem_trigtime);
   fChain->SetBranchAddress("bb.grinch_tdc.bestcluster", &bb_grinch_tdc_bestcluster, &b_bb_grinch_tdc_bestcluster);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.adc", &bb_grinch_tdc_clus_adc, &b_bb_grinch_tdc_clus_adc);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.dx", &bb_grinch_tdc_clus_dx, &b_bb_grinch_tdc_clus_dx);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.dy", &bb_grinch_tdc_clus_dy, &b_bb_grinch_tdc_clus_dy);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.mirrorindex", &bb_grinch_tdc_clus_mirrorindex, &b_bb_grinch_tdc_clus_mirrorindex);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.size", &bb_grinch_tdc_clus_size, &b_bb_grinch_tdc_clus_size);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.t_mean", &bb_grinch_tdc_clus_t_mean, &b_bb_grinch_tdc_clus_t_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.t_mean_corr", &bb_grinch_tdc_clus_t_mean_corr, &b_bb_grinch_tdc_clus_t_mean_corr);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.t_rms", &bb_grinch_tdc_clus_t_rms, &b_bb_grinch_tdc_clus_t_rms);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.t_rms_corr", &bb_grinch_tdc_clus_t_rms_corr, &b_bb_grinch_tdc_clus_t_rms_corr);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.tot_mean", &bb_grinch_tdc_clus_tot_mean, &b_bb_grinch_tdc_clus_tot_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.trackindex", &bb_grinch_tdc_clus_trackindex, &b_bb_grinch_tdc_clus_trackindex);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.x_mean", &bb_grinch_tdc_clus_x_mean, &b_bb_grinch_tdc_clus_x_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.y_mean", &bb_grinch_tdc_clus_y_mean, &b_bb_grinch_tdc_clus_y_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.nclus", &bb_grinch_tdc_nclus, &b_bb_grinch_tdc_nclus);
   fChain->SetBranchAddress("bb.grinch_tdc.ngoodhits", &bb_grinch_tdc_ngoodhits, &b_bb_grinch_tdc_ngoodhits);
   fChain->SetBranchAddress("bb.grinch_tdc.ntrackmatch", &bb_grinch_tdc_ntrackmatch, &b_bb_grinch_tdc_ntrackmatch);
   fChain->SetBranchAddress("bb.hodotdc.nclus", &bb_hodotdc_nclus, &b_bb_hodotdc_nclus);
   fChain->SetBranchAddress("bb.hodotdc.rftime", &bb_hodotdc_rftime, &b_bb_hodotdc_rftime);
   fChain->SetBranchAddress("bb.hodotdc.trigphase", &bb_hodotdc_trigphase, &b_bb_hodotdc_trigphase);
   fChain->SetBranchAddress("bb.hodotdc.trigphasecorr", &bb_hodotdc_trigphasecorr, &b_bb_hodotdc_trigphasecorr);
   fChain->SetBranchAddress("bb.hodotdc.trigtime", &bb_hodotdc_trigtime, &b_bb_hodotdc_trigtime);
   fChain->SetBranchAddress("bb.ps.againblk", &bb_ps_againblk, &b_bb_ps_againblk);
   fChain->SetBranchAddress("bb.ps.atimeblk", &bb_ps_atimeblk, &b_bb_ps_atimeblk);
   fChain->SetBranchAddress("bb.ps.colblk", &bb_ps_colblk, &b_bb_ps_colblk);
   fChain->SetBranchAddress("bb.ps.e", &bb_ps_e, &b_bb_ps_e);
   fChain->SetBranchAddress("bb.ps.eblk", &bb_ps_eblk, &b_bb_ps_eblk);
   fChain->SetBranchAddress("bb.ps.idblk", &bb_ps_idblk, &b_bb_ps_idblk);
   fChain->SetBranchAddress("bb.ps.index", &bb_ps_index, &b_bb_ps_index);
   fChain->SetBranchAddress("bb.ps.nblk", &bb_ps_nblk, &b_bb_ps_nblk);
   fChain->SetBranchAddress("bb.ps.nclus", &bb_ps_nclus, &b_bb_ps_nclus);
   fChain->SetBranchAddress("bb.ps.ngoodADChits", &bb_ps_ngoodADChits, &b_bb_ps_ngoodADChits);
   fChain->SetBranchAddress("bb.ps.rowblk", &bb_ps_rowblk, &b_bb_ps_rowblk);
   fChain->SetBranchAddress("bb.ps.x", &bb_ps_x, &b_bb_ps_x);
   fChain->SetBranchAddress("bb.ps.y", &bb_ps_y, &b_bb_ps_y);
   fChain->SetBranchAddress("bb.sh.againblk", &bb_sh_againblk, &b_bb_sh_againblk);
   fChain->SetBranchAddress("bb.sh.atimeblk", &bb_sh_atimeblk, &b_bb_sh_atimeblk);
   fChain->SetBranchAddress("bb.sh.colblk", &bb_sh_colblk, &b_bb_sh_colblk);
   fChain->SetBranchAddress("bb.sh.e", &bb_sh_e, &b_bb_sh_e);
   fChain->SetBranchAddress("bb.sh.eblk", &bb_sh_eblk, &b_bb_sh_eblk);
   fChain->SetBranchAddress("bb.sh.idblk", &bb_sh_idblk, &b_bb_sh_idblk);
   fChain->SetBranchAddress("bb.sh.index", &bb_sh_index, &b_bb_sh_index);
   fChain->SetBranchAddress("bb.sh.nblk", &bb_sh_nblk, &b_bb_sh_nblk);
   fChain->SetBranchAddress("bb.sh.nclus", &bb_sh_nclus, &b_bb_sh_nclus);
   fChain->SetBranchAddress("bb.sh.ngoodADChits", &bb_sh_ngoodADChits, &b_bb_sh_ngoodADChits);
   fChain->SetBranchAddress("bb.sh.rowblk", &bb_sh_rowblk, &b_bb_sh_rowblk);
   fChain->SetBranchAddress("bb.sh.x", &bb_sh_x, &b_bb_sh_x);
   fChain->SetBranchAddress("bb.sh.y", &bb_sh_y, &b_bb_sh_y);
   fChain->SetBranchAddress("bb.tdctrig.rftime", &bb_tdctrig_rftime, &b_bb_tdctrig_rftime);
   fChain->SetBranchAddress("bb.tdctrig.trigtime", &bb_tdctrig_trigtime, &b_bb_tdctrig_trigtime);
   fChain->SetBranchAddress("bb.tr.n", &bb_tr_n, &b_bb_tr_n);
   fChain->SetBranchAddress("bb.ts.over_threshold", &bb_ts_over_threshold, &b_bb_ts_over_threshold);
   fChain->SetBranchAddress("e.kine.Q2", &e_kine_Q2, &b_e_kine_Q2);
   fChain->SetBranchAddress("e.kine.W2", &e_kine_W2, &b_e_kine_W2);
   fChain->SetBranchAddress("e.kine.angle", &e_kine_angle, &b_e_kine_angle);
   fChain->SetBranchAddress("e.kine.epsilon", &e_kine_epsilon, &b_e_kine_epsilon);
   fChain->SetBranchAddress("e.kine.nu", &e_kine_nu, &b_e_kine_nu);
   fChain->SetBranchAddress("e.kine.omega", &e_kine_omega, &b_e_kine_omega);
   fChain->SetBranchAddress("e.kine.ph_q", &e_kine_ph_q, &b_e_kine_ph_q);
   fChain->SetBranchAddress("e.kine.q3m", &e_kine_q3m, &b_e_kine_q3m);
   fChain->SetBranchAddress("e.kine.q_x", &e_kine_q_x, &b_e_kine_q_x);
   fChain->SetBranchAddress("e.kine.q_y", &e_kine_q_y, &b_e_kine_q_y);
   fChain->SetBranchAddress("e.kine.q_z", &e_kine_q_z, &b_e_kine_q_z);
   fChain->SetBranchAddress("e.kine.th_q", &e_kine_th_q, &b_e_kine_th_q);
   fChain->SetBranchAddress("e.kine.x_bj", &e_kine_x_bj, &b_e_kine_x_bj);
   fChain->SetBranchAddress("g.datatype", &g_datatype, &b_g_datatype);
   fChain->SetBranchAddress("g.evlen", &g_evlen, &b_g_evlen);
   fChain->SetBranchAddress("g.evnum", &g_evnum, &b_g_evnum);
   fChain->SetBranchAddress("g.evtime", &g_evtime, &b_g_evtime);
   fChain->SetBranchAddress("g.evtyp", &g_evtyp, &b_g_evtyp);
   fChain->SetBranchAddress("g.runnum", &g_runnum, &b_g_runnum);
   fChain->SetBranchAddress("g.runtime", &g_runtime, &b_g_runtime);
   fChain->SetBranchAddress("g.runtype", &g_runtype, &b_g_runtype);
   fChain->SetBranchAddress("g.trigbits", &g_trigbits, &b_g_trigbits);
   fChain->SetBranchAddress("sbs.HCALdir_x", &sbs_HCALdir_x, &b_sbs_HCALdir_x);
   fChain->SetBranchAddress("sbs.HCALdir_y", &sbs_HCALdir_y, &b_sbs_HCALdir_y);
   fChain->SetBranchAddress("sbs.HCALdir_z", &sbs_HCALdir_z, &b_sbs_HCALdir_z);
   fChain->SetBranchAddress("sbs.HCALph_n", &sbs_HCALph_n, &b_sbs_HCALph_n);
   fChain->SetBranchAddress("sbs.HCALth_n", &sbs_HCALth_n, &b_sbs_HCALth_n);
   fChain->SetBranchAddress("sbs.gemCeF.hit.ngoodhits", &sbs_gemCeF_hit_ngoodhits, &b_sbs_gemCeF_hit_ngoodhits);
   fChain->SetBranchAddress("sbs.gemCeF.m0.clust.nclustu", &sbs_gemCeF_m0_clust_nclustu, &b_sbs_gemCeF_m0_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m0.clust.nclustu_tot", &sbs_gemCeF_m0_clust_nclustu_tot, &b_sbs_gemCeF_m0_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m0.clust.nclustv", &sbs_gemCeF_m0_clust_nclustv, &b_sbs_gemCeF_m0_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m0.clust.nclustv_tot", &sbs_gemCeF_m0_clust_nclustv_tot, &b_sbs_gemCeF_m0_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m0.strip.nstrips_keep", &sbs_gemCeF_m0_strip_nstrips_keep, &b_sbs_gemCeF_m0_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m0.strip.nstrips_keepU", &sbs_gemCeF_m0_strip_nstrips_keepU, &b_sbs_gemCeF_m0_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m0.strip.nstrips_keepV", &sbs_gemCeF_m0_strip_nstrips_keepV, &b_sbs_gemCeF_m0_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m0.strip.nstrips_keep_lmax", &sbs_gemCeF_m0_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m0_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m0.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m0_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m0_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m0.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m0_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m0_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m0.strip.nstripsfired", &sbs_gemCeF_m0_strip_nstripsfired, &b_sbs_gemCeF_m0_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m1.clust.nclustu", &sbs_gemCeF_m1_clust_nclustu, &b_sbs_gemCeF_m1_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m1.clust.nclustu_tot", &sbs_gemCeF_m1_clust_nclustu_tot, &b_sbs_gemCeF_m1_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m1.clust.nclustv", &sbs_gemCeF_m1_clust_nclustv, &b_sbs_gemCeF_m1_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m1.clust.nclustv_tot", &sbs_gemCeF_m1_clust_nclustv_tot, &b_sbs_gemCeF_m1_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m1.strip.nstrips_keep", &sbs_gemCeF_m1_strip_nstrips_keep, &b_sbs_gemCeF_m1_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m1.strip.nstrips_keepU", &sbs_gemCeF_m1_strip_nstrips_keepU, &b_sbs_gemCeF_m1_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m1.strip.nstrips_keepV", &sbs_gemCeF_m1_strip_nstrips_keepV, &b_sbs_gemCeF_m1_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m1.strip.nstrips_keep_lmax", &sbs_gemCeF_m1_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m1_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m1.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m1_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m1_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m1.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m1_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m1_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m1.strip.nstripsfired", &sbs_gemCeF_m1_strip_nstripsfired, &b_sbs_gemCeF_m1_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m2.clust.nclustu", &sbs_gemCeF_m2_clust_nclustu, &b_sbs_gemCeF_m2_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m2.clust.nclustu_tot", &sbs_gemCeF_m2_clust_nclustu_tot, &b_sbs_gemCeF_m2_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m2.clust.nclustv", &sbs_gemCeF_m2_clust_nclustv, &b_sbs_gemCeF_m2_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m2.clust.nclustv_tot", &sbs_gemCeF_m2_clust_nclustv_tot, &b_sbs_gemCeF_m2_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m2.strip.nstrips_keep", &sbs_gemCeF_m2_strip_nstrips_keep, &b_sbs_gemCeF_m2_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m2.strip.nstrips_keepU", &sbs_gemCeF_m2_strip_nstrips_keepU, &b_sbs_gemCeF_m2_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m2.strip.nstrips_keepV", &sbs_gemCeF_m2_strip_nstrips_keepV, &b_sbs_gemCeF_m2_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m2.strip.nstrips_keep_lmax", &sbs_gemCeF_m2_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m2_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m2.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m2_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m2_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m2.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m2_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m2_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m2.strip.nstripsfired", &sbs_gemCeF_m2_strip_nstripsfired, &b_sbs_gemCeF_m2_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m3.clust.nclustu", &sbs_gemCeF_m3_clust_nclustu, &b_sbs_gemCeF_m3_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m3.clust.nclustu_tot", &sbs_gemCeF_m3_clust_nclustu_tot, &b_sbs_gemCeF_m3_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m3.clust.nclustv", &sbs_gemCeF_m3_clust_nclustv, &b_sbs_gemCeF_m3_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m3.clust.nclustv_tot", &sbs_gemCeF_m3_clust_nclustv_tot, &b_sbs_gemCeF_m3_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m3.strip.nstrips_keep", &sbs_gemCeF_m3_strip_nstrips_keep, &b_sbs_gemCeF_m3_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m3.strip.nstrips_keepU", &sbs_gemCeF_m3_strip_nstrips_keepU, &b_sbs_gemCeF_m3_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m3.strip.nstrips_keepV", &sbs_gemCeF_m3_strip_nstrips_keepV, &b_sbs_gemCeF_m3_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m3.strip.nstrips_keep_lmax", &sbs_gemCeF_m3_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m3_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m3.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m3_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m3_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m3.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m3_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m3_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m3.strip.nstripsfired", &sbs_gemCeF_m3_strip_nstripsfired, &b_sbs_gemCeF_m3_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m4.clust.nclustu", &sbs_gemCeF_m4_clust_nclustu, &b_sbs_gemCeF_m4_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m4.clust.nclustu_tot", &sbs_gemCeF_m4_clust_nclustu_tot, &b_sbs_gemCeF_m4_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m4.clust.nclustv", &sbs_gemCeF_m4_clust_nclustv, &b_sbs_gemCeF_m4_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m4.clust.nclustv_tot", &sbs_gemCeF_m4_clust_nclustv_tot, &b_sbs_gemCeF_m4_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m4.strip.nstrips_keep", &sbs_gemCeF_m4_strip_nstrips_keep, &b_sbs_gemCeF_m4_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m4.strip.nstrips_keepU", &sbs_gemCeF_m4_strip_nstrips_keepU, &b_sbs_gemCeF_m4_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m4.strip.nstrips_keepV", &sbs_gemCeF_m4_strip_nstrips_keepV, &b_sbs_gemCeF_m4_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m4.strip.nstrips_keep_lmax", &sbs_gemCeF_m4_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m4_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m4.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m4_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m4_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m4.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m4_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m4_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m4.strip.nstripsfired", &sbs_gemCeF_m4_strip_nstripsfired, &b_sbs_gemCeF_m4_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m5.clust.nclustu", &sbs_gemCeF_m5_clust_nclustu, &b_sbs_gemCeF_m5_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m5.clust.nclustu_tot", &sbs_gemCeF_m5_clust_nclustu_tot, &b_sbs_gemCeF_m5_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m5.clust.nclustv", &sbs_gemCeF_m5_clust_nclustv, &b_sbs_gemCeF_m5_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m5.clust.nclustv_tot", &sbs_gemCeF_m5_clust_nclustv_tot, &b_sbs_gemCeF_m5_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m5.strip.nstrips_keep", &sbs_gemCeF_m5_strip_nstrips_keep, &b_sbs_gemCeF_m5_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m5.strip.nstrips_keepU", &sbs_gemCeF_m5_strip_nstrips_keepU, &b_sbs_gemCeF_m5_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m5.strip.nstrips_keepV", &sbs_gemCeF_m5_strip_nstrips_keepV, &b_sbs_gemCeF_m5_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m5.strip.nstrips_keep_lmax", &sbs_gemCeF_m5_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m5_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m5.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m5_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m5_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m5.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m5_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m5_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m5.strip.nstripsfired", &sbs_gemCeF_m5_strip_nstripsfired, &b_sbs_gemCeF_m5_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m6.clust.nclustu", &sbs_gemCeF_m6_clust_nclustu, &b_sbs_gemCeF_m6_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m6.clust.nclustu_tot", &sbs_gemCeF_m6_clust_nclustu_tot, &b_sbs_gemCeF_m6_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m6.clust.nclustv", &sbs_gemCeF_m6_clust_nclustv, &b_sbs_gemCeF_m6_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m6.clust.nclustv_tot", &sbs_gemCeF_m6_clust_nclustv_tot, &b_sbs_gemCeF_m6_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m6.strip.nstrips_keep", &sbs_gemCeF_m6_strip_nstrips_keep, &b_sbs_gemCeF_m6_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m6.strip.nstrips_keepU", &sbs_gemCeF_m6_strip_nstrips_keepU, &b_sbs_gemCeF_m6_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m6.strip.nstrips_keepV", &sbs_gemCeF_m6_strip_nstrips_keepV, &b_sbs_gemCeF_m6_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m6.strip.nstrips_keep_lmax", &sbs_gemCeF_m6_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m6_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m6.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m6_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m6_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m6.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m6_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m6_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m6.strip.nstripsfired", &sbs_gemCeF_m6_strip_nstripsfired, &b_sbs_gemCeF_m6_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m7.clust.nclustu", &sbs_gemCeF_m7_clust_nclustu, &b_sbs_gemCeF_m7_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m7.clust.nclustu_tot", &sbs_gemCeF_m7_clust_nclustu_tot, &b_sbs_gemCeF_m7_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m7.clust.nclustv", &sbs_gemCeF_m7_clust_nclustv, &b_sbs_gemCeF_m7_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m7.clust.nclustv_tot", &sbs_gemCeF_m7_clust_nclustv_tot, &b_sbs_gemCeF_m7_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m7.strip.nstrips_keep", &sbs_gemCeF_m7_strip_nstrips_keep, &b_sbs_gemCeF_m7_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m7.strip.nstrips_keepU", &sbs_gemCeF_m7_strip_nstrips_keepU, &b_sbs_gemCeF_m7_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m7.strip.nstrips_keepV", &sbs_gemCeF_m7_strip_nstrips_keepV, &b_sbs_gemCeF_m7_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m7.strip.nstrips_keep_lmax", &sbs_gemCeF_m7_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m7_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m7.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m7_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m7_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m7.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m7_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m7_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m7.strip.nstripsfired", &sbs_gemCeF_m7_strip_nstripsfired, &b_sbs_gemCeF_m7_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m8.clust.nclustu", &sbs_gemCeF_m8_clust_nclustu, &b_sbs_gemCeF_m8_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m8.clust.nclustu_tot", &sbs_gemCeF_m8_clust_nclustu_tot, &b_sbs_gemCeF_m8_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m8.clust.nclustv", &sbs_gemCeF_m8_clust_nclustv, &b_sbs_gemCeF_m8_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m8.clust.nclustv_tot", &sbs_gemCeF_m8_clust_nclustv_tot, &b_sbs_gemCeF_m8_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m8.strip.nstrips_keep", &sbs_gemCeF_m8_strip_nstrips_keep, &b_sbs_gemCeF_m8_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m8.strip.nstrips_keepU", &sbs_gemCeF_m8_strip_nstrips_keepU, &b_sbs_gemCeF_m8_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m8.strip.nstrips_keepV", &sbs_gemCeF_m8_strip_nstrips_keepV, &b_sbs_gemCeF_m8_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m8.strip.nstrips_keep_lmax", &sbs_gemCeF_m8_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m8_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m8.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m8_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m8_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m8.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m8_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m8_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m8.strip.nstripsfired", &sbs_gemCeF_m8_strip_nstripsfired, &b_sbs_gemCeF_m8_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.m9.clust.nclustu", &sbs_gemCeF_m9_clust_nclustu, &b_sbs_gemCeF_m9_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeF.m9.clust.nclustu_tot", &sbs_gemCeF_m9_clust_nclustu_tot, &b_sbs_gemCeF_m9_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m9.clust.nclustv", &sbs_gemCeF_m9_clust_nclustv, &b_sbs_gemCeF_m9_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeF.m9.clust.nclustv_tot", &sbs_gemCeF_m9_clust_nclustv_tot, &b_sbs_gemCeF_m9_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeF.m9.strip.nstrips_keep", &sbs_gemCeF_m9_strip_nstrips_keep, &b_sbs_gemCeF_m9_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeF.m9.strip.nstrips_keepU", &sbs_gemCeF_m9_strip_nstrips_keepU, &b_sbs_gemCeF_m9_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeF.m9.strip.nstrips_keepV", &sbs_gemCeF_m9_strip_nstrips_keepV, &b_sbs_gemCeF_m9_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeF.m9.strip.nstrips_keep_lmax", &sbs_gemCeF_m9_strip_nstrips_keep_lmax, &b_sbs_gemCeF_m9_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeF.m9.strip.nstrips_keep_lmaxU", &sbs_gemCeF_m9_strip_nstrips_keep_lmaxU, &b_sbs_gemCeF_m9_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeF.m9.strip.nstrips_keep_lmaxV", &sbs_gemCeF_m9_strip_nstrips_keep_lmaxV, &b_sbs_gemCeF_m9_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeF.m9.strip.nstripsfired", &sbs_gemCeF_m9_strip_nstripsfired, &b_sbs_gemCeF_m9_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeF.nlayershit", &sbs_gemCeF_nlayershit, &b_sbs_gemCeF_nlayershit);
   fChain->SetBranchAddress("sbs.gemCeF.nlayershitu", &sbs_gemCeF_nlayershitu, &b_sbs_gemCeF_nlayershitu);
   fChain->SetBranchAddress("sbs.gemCeF.nlayershituv", &sbs_gemCeF_nlayershituv, &b_sbs_gemCeF_nlayershituv);
   fChain->SetBranchAddress("sbs.gemCeF.nlayershitv", &sbs_gemCeF_nlayershitv, &b_sbs_gemCeF_nlayershitv);
   fChain->SetBranchAddress("sbs.gemCeF.track.besttrack", &sbs_gemCeF_track_besttrack, &b_sbs_gemCeF_track_besttrack);
   fChain->SetBranchAddress("sbs.gemCeF.track.ntrack", &sbs_gemCeF_track_ntrack, &b_sbs_gemCeF_track_ntrack);
   fChain->SetBranchAddress("sbs.gemCeR.hit.ngoodhits", &sbs_gemCeR_hit_ngoodhits, &b_sbs_gemCeR_hit_ngoodhits);
   fChain->SetBranchAddress("sbs.gemCeR.m0.clust.nclustu", &sbs_gemCeR_m0_clust_nclustu, &b_sbs_gemCeR_m0_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m0.clust.nclustu_tot", &sbs_gemCeR_m0_clust_nclustu_tot, &b_sbs_gemCeR_m0_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m0.clust.nclustv", &sbs_gemCeR_m0_clust_nclustv, &b_sbs_gemCeR_m0_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m0.clust.nclustv_tot", &sbs_gemCeR_m0_clust_nclustv_tot, &b_sbs_gemCeR_m0_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m0.strip.nstrips_keep", &sbs_gemCeR_m0_strip_nstrips_keep, &b_sbs_gemCeR_m0_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m0.strip.nstrips_keepU", &sbs_gemCeR_m0_strip_nstrips_keepU, &b_sbs_gemCeR_m0_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m0.strip.nstrips_keepV", &sbs_gemCeR_m0_strip_nstrips_keepV, &b_sbs_gemCeR_m0_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m0.strip.nstrips_keep_lmax", &sbs_gemCeR_m0_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m0_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m0.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m0_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m0_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m0.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m0_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m0_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m0.strip.nstripsfired", &sbs_gemCeR_m0_strip_nstripsfired, &b_sbs_gemCeR_m0_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m1.clust.nclustu", &sbs_gemCeR_m1_clust_nclustu, &b_sbs_gemCeR_m1_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m1.clust.nclustu_tot", &sbs_gemCeR_m1_clust_nclustu_tot, &b_sbs_gemCeR_m1_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m1.clust.nclustv", &sbs_gemCeR_m1_clust_nclustv, &b_sbs_gemCeR_m1_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m1.clust.nclustv_tot", &sbs_gemCeR_m1_clust_nclustv_tot, &b_sbs_gemCeR_m1_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m1.strip.nstrips_keep", &sbs_gemCeR_m1_strip_nstrips_keep, &b_sbs_gemCeR_m1_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m1.strip.nstrips_keepU", &sbs_gemCeR_m1_strip_nstrips_keepU, &b_sbs_gemCeR_m1_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m1.strip.nstrips_keepV", &sbs_gemCeR_m1_strip_nstrips_keepV, &b_sbs_gemCeR_m1_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m1.strip.nstrips_keep_lmax", &sbs_gemCeR_m1_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m1_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m1.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m1_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m1_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m1.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m1_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m1_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m1.strip.nstripsfired", &sbs_gemCeR_m1_strip_nstripsfired, &b_sbs_gemCeR_m1_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m10.clust.nclustu", &sbs_gemCeR_m10_clust_nclustu, &b_sbs_gemCeR_m10_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m10.clust.nclustu_tot", &sbs_gemCeR_m10_clust_nclustu_tot, &b_sbs_gemCeR_m10_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m10.clust.nclustv", &sbs_gemCeR_m10_clust_nclustv, &b_sbs_gemCeR_m10_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m10.clust.nclustv_tot", &sbs_gemCeR_m10_clust_nclustv_tot, &b_sbs_gemCeR_m10_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m10.strip.nstrips_keep", &sbs_gemCeR_m10_strip_nstrips_keep, &b_sbs_gemCeR_m10_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m10.strip.nstrips_keepU", &sbs_gemCeR_m10_strip_nstrips_keepU, &b_sbs_gemCeR_m10_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m10.strip.nstrips_keepV", &sbs_gemCeR_m10_strip_nstrips_keepV, &b_sbs_gemCeR_m10_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m10.strip.nstrips_keep_lmax", &sbs_gemCeR_m10_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m10_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m10.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m10_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m10_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m10.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m10_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m10_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m10.strip.nstripsfired", &sbs_gemCeR_m10_strip_nstripsfired, &b_sbs_gemCeR_m10_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m11.clust.nclustu", &sbs_gemCeR_m11_clust_nclustu, &b_sbs_gemCeR_m11_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m11.clust.nclustu_tot", &sbs_gemCeR_m11_clust_nclustu_tot, &b_sbs_gemCeR_m11_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m11.clust.nclustv", &sbs_gemCeR_m11_clust_nclustv, &b_sbs_gemCeR_m11_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m11.clust.nclustv_tot", &sbs_gemCeR_m11_clust_nclustv_tot, &b_sbs_gemCeR_m11_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m11.strip.nstrips_keep", &sbs_gemCeR_m11_strip_nstrips_keep, &b_sbs_gemCeR_m11_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m11.strip.nstrips_keepU", &sbs_gemCeR_m11_strip_nstrips_keepU, &b_sbs_gemCeR_m11_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m11.strip.nstrips_keepV", &sbs_gemCeR_m11_strip_nstrips_keepV, &b_sbs_gemCeR_m11_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m11.strip.nstrips_keep_lmax", &sbs_gemCeR_m11_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m11_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m11.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m11_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m11_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m11.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m11_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m11_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m11.strip.nstripsfired", &sbs_gemCeR_m11_strip_nstripsfired, &b_sbs_gemCeR_m11_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m12.clust.nclustu", &sbs_gemCeR_m12_clust_nclustu, &b_sbs_gemCeR_m12_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m12.clust.nclustu_tot", &sbs_gemCeR_m12_clust_nclustu_tot, &b_sbs_gemCeR_m12_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m12.clust.nclustv", &sbs_gemCeR_m12_clust_nclustv, &b_sbs_gemCeR_m12_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m12.clust.nclustv_tot", &sbs_gemCeR_m12_clust_nclustv_tot, &b_sbs_gemCeR_m12_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m12.strip.nstrips_keep", &sbs_gemCeR_m12_strip_nstrips_keep, &b_sbs_gemCeR_m12_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m12.strip.nstrips_keepU", &sbs_gemCeR_m12_strip_nstrips_keepU, &b_sbs_gemCeR_m12_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m12.strip.nstrips_keepV", &sbs_gemCeR_m12_strip_nstrips_keepV, &b_sbs_gemCeR_m12_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m12.strip.nstrips_keep_lmax", &sbs_gemCeR_m12_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m12_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m12.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m12_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m12_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m12.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m12_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m12_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m12.strip.nstripsfired", &sbs_gemCeR_m12_strip_nstripsfired, &b_sbs_gemCeR_m12_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m13.clust.nclustu", &sbs_gemCeR_m13_clust_nclustu, &b_sbs_gemCeR_m13_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m13.clust.nclustu_tot", &sbs_gemCeR_m13_clust_nclustu_tot, &b_sbs_gemCeR_m13_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m13.clust.nclustv", &sbs_gemCeR_m13_clust_nclustv, &b_sbs_gemCeR_m13_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m13.clust.nclustv_tot", &sbs_gemCeR_m13_clust_nclustv_tot, &b_sbs_gemCeR_m13_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m13.strip.nstrips_keep", &sbs_gemCeR_m13_strip_nstrips_keep, &b_sbs_gemCeR_m13_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m13.strip.nstrips_keepU", &sbs_gemCeR_m13_strip_nstrips_keepU, &b_sbs_gemCeR_m13_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m13.strip.nstrips_keepV", &sbs_gemCeR_m13_strip_nstrips_keepV, &b_sbs_gemCeR_m13_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m13.strip.nstrips_keep_lmax", &sbs_gemCeR_m13_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m13_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m13.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m13_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m13_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m13.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m13_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m13_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m13.strip.nstripsfired", &sbs_gemCeR_m13_strip_nstripsfired, &b_sbs_gemCeR_m13_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m14.clust.nclustu", &sbs_gemCeR_m14_clust_nclustu, &b_sbs_gemCeR_m14_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m14.clust.nclustu_tot", &sbs_gemCeR_m14_clust_nclustu_tot, &b_sbs_gemCeR_m14_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m14.clust.nclustv", &sbs_gemCeR_m14_clust_nclustv, &b_sbs_gemCeR_m14_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m14.clust.nclustv_tot", &sbs_gemCeR_m14_clust_nclustv_tot, &b_sbs_gemCeR_m14_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m14.strip.nstrips_keep", &sbs_gemCeR_m14_strip_nstrips_keep, &b_sbs_gemCeR_m14_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m14.strip.nstrips_keepU", &sbs_gemCeR_m14_strip_nstrips_keepU, &b_sbs_gemCeR_m14_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m14.strip.nstrips_keepV", &sbs_gemCeR_m14_strip_nstrips_keepV, &b_sbs_gemCeR_m14_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m14.strip.nstrips_keep_lmax", &sbs_gemCeR_m14_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m14_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m14.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m14_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m14_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m14.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m14_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m14_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m14.strip.nstripsfired", &sbs_gemCeR_m14_strip_nstripsfired, &b_sbs_gemCeR_m14_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m15.clust.nclustu", &sbs_gemCeR_m15_clust_nclustu, &b_sbs_gemCeR_m15_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m15.clust.nclustu_tot", &sbs_gemCeR_m15_clust_nclustu_tot, &b_sbs_gemCeR_m15_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m15.clust.nclustv", &sbs_gemCeR_m15_clust_nclustv, &b_sbs_gemCeR_m15_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m15.clust.nclustv_tot", &sbs_gemCeR_m15_clust_nclustv_tot, &b_sbs_gemCeR_m15_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m15.strip.nstrips_keep", &sbs_gemCeR_m15_strip_nstrips_keep, &b_sbs_gemCeR_m15_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m15.strip.nstrips_keepU", &sbs_gemCeR_m15_strip_nstrips_keepU, &b_sbs_gemCeR_m15_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m15.strip.nstrips_keepV", &sbs_gemCeR_m15_strip_nstrips_keepV, &b_sbs_gemCeR_m15_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m15.strip.nstrips_keep_lmax", &sbs_gemCeR_m15_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m15_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m15.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m15_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m15_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m15.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m15_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m15_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m15.strip.nstripsfired", &sbs_gemCeR_m15_strip_nstripsfired, &b_sbs_gemCeR_m15_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m2.clust.nclustu", &sbs_gemCeR_m2_clust_nclustu, &b_sbs_gemCeR_m2_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m2.clust.nclustu_tot", &sbs_gemCeR_m2_clust_nclustu_tot, &b_sbs_gemCeR_m2_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m2.clust.nclustv", &sbs_gemCeR_m2_clust_nclustv, &b_sbs_gemCeR_m2_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m2.clust.nclustv_tot", &sbs_gemCeR_m2_clust_nclustv_tot, &b_sbs_gemCeR_m2_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m2.strip.nstrips_keep", &sbs_gemCeR_m2_strip_nstrips_keep, &b_sbs_gemCeR_m2_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m2.strip.nstrips_keepU", &sbs_gemCeR_m2_strip_nstrips_keepU, &b_sbs_gemCeR_m2_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m2.strip.nstrips_keepV", &sbs_gemCeR_m2_strip_nstrips_keepV, &b_sbs_gemCeR_m2_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m2.strip.nstrips_keep_lmax", &sbs_gemCeR_m2_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m2_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m2.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m2_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m2_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m2.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m2_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m2_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m2.strip.nstripsfired", &sbs_gemCeR_m2_strip_nstripsfired, &b_sbs_gemCeR_m2_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m3.clust.nclustu", &sbs_gemCeR_m3_clust_nclustu, &b_sbs_gemCeR_m3_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m3.clust.nclustu_tot", &sbs_gemCeR_m3_clust_nclustu_tot, &b_sbs_gemCeR_m3_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m3.clust.nclustv", &sbs_gemCeR_m3_clust_nclustv, &b_sbs_gemCeR_m3_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m3.clust.nclustv_tot", &sbs_gemCeR_m3_clust_nclustv_tot, &b_sbs_gemCeR_m3_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m3.strip.nstrips_keep", &sbs_gemCeR_m3_strip_nstrips_keep, &b_sbs_gemCeR_m3_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m3.strip.nstrips_keepU", &sbs_gemCeR_m3_strip_nstrips_keepU, &b_sbs_gemCeR_m3_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m3.strip.nstrips_keepV", &sbs_gemCeR_m3_strip_nstrips_keepV, &b_sbs_gemCeR_m3_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m3.strip.nstrips_keep_lmax", &sbs_gemCeR_m3_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m3_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m3.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m3_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m3_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m3.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m3_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m3_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m3.strip.nstripsfired", &sbs_gemCeR_m3_strip_nstripsfired, &b_sbs_gemCeR_m3_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m4.clust.nclustu", &sbs_gemCeR_m4_clust_nclustu, &b_sbs_gemCeR_m4_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m4.clust.nclustu_tot", &sbs_gemCeR_m4_clust_nclustu_tot, &b_sbs_gemCeR_m4_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m4.clust.nclustv", &sbs_gemCeR_m4_clust_nclustv, &b_sbs_gemCeR_m4_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m4.clust.nclustv_tot", &sbs_gemCeR_m4_clust_nclustv_tot, &b_sbs_gemCeR_m4_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m4.strip.nstrips_keep", &sbs_gemCeR_m4_strip_nstrips_keep, &b_sbs_gemCeR_m4_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m4.strip.nstrips_keepU", &sbs_gemCeR_m4_strip_nstrips_keepU, &b_sbs_gemCeR_m4_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m4.strip.nstrips_keepV", &sbs_gemCeR_m4_strip_nstrips_keepV, &b_sbs_gemCeR_m4_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m4.strip.nstrips_keep_lmax", &sbs_gemCeR_m4_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m4_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m4.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m4_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m4_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m4.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m4_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m4_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m4.strip.nstripsfired", &sbs_gemCeR_m4_strip_nstripsfired, &b_sbs_gemCeR_m4_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m5.clust.nclustu", &sbs_gemCeR_m5_clust_nclustu, &b_sbs_gemCeR_m5_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m5.clust.nclustu_tot", &sbs_gemCeR_m5_clust_nclustu_tot, &b_sbs_gemCeR_m5_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m5.clust.nclustv", &sbs_gemCeR_m5_clust_nclustv, &b_sbs_gemCeR_m5_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m5.clust.nclustv_tot", &sbs_gemCeR_m5_clust_nclustv_tot, &b_sbs_gemCeR_m5_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m5.strip.nstrips_keep", &sbs_gemCeR_m5_strip_nstrips_keep, &b_sbs_gemCeR_m5_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m5.strip.nstrips_keepU", &sbs_gemCeR_m5_strip_nstrips_keepU, &b_sbs_gemCeR_m5_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m5.strip.nstrips_keepV", &sbs_gemCeR_m5_strip_nstrips_keepV, &b_sbs_gemCeR_m5_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m5.strip.nstrips_keep_lmax", &sbs_gemCeR_m5_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m5_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m5.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m5_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m5_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m5.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m5_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m5_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m5.strip.nstripsfired", &sbs_gemCeR_m5_strip_nstripsfired, &b_sbs_gemCeR_m5_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m6.clust.nclustu", &sbs_gemCeR_m6_clust_nclustu, &b_sbs_gemCeR_m6_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m6.clust.nclustu_tot", &sbs_gemCeR_m6_clust_nclustu_tot, &b_sbs_gemCeR_m6_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m6.clust.nclustv", &sbs_gemCeR_m6_clust_nclustv, &b_sbs_gemCeR_m6_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m6.clust.nclustv_tot", &sbs_gemCeR_m6_clust_nclustv_tot, &b_sbs_gemCeR_m6_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m6.strip.nstrips_keep", &sbs_gemCeR_m6_strip_nstrips_keep, &b_sbs_gemCeR_m6_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m6.strip.nstrips_keepU", &sbs_gemCeR_m6_strip_nstrips_keepU, &b_sbs_gemCeR_m6_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m6.strip.nstrips_keepV", &sbs_gemCeR_m6_strip_nstrips_keepV, &b_sbs_gemCeR_m6_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m6.strip.nstrips_keep_lmax", &sbs_gemCeR_m6_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m6_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m6.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m6_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m6_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m6.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m6_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m6_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m6.strip.nstripsfired", &sbs_gemCeR_m6_strip_nstripsfired, &b_sbs_gemCeR_m6_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m7.clust.nclustu", &sbs_gemCeR_m7_clust_nclustu, &b_sbs_gemCeR_m7_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m7.clust.nclustu_tot", &sbs_gemCeR_m7_clust_nclustu_tot, &b_sbs_gemCeR_m7_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m7.clust.nclustv", &sbs_gemCeR_m7_clust_nclustv, &b_sbs_gemCeR_m7_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m7.clust.nclustv_tot", &sbs_gemCeR_m7_clust_nclustv_tot, &b_sbs_gemCeR_m7_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m7.strip.nstrips_keep", &sbs_gemCeR_m7_strip_nstrips_keep, &b_sbs_gemCeR_m7_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m7.strip.nstrips_keepU", &sbs_gemCeR_m7_strip_nstrips_keepU, &b_sbs_gemCeR_m7_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m7.strip.nstrips_keepV", &sbs_gemCeR_m7_strip_nstrips_keepV, &b_sbs_gemCeR_m7_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m7.strip.nstrips_keep_lmax", &sbs_gemCeR_m7_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m7_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m7.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m7_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m7_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m7.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m7_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m7_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m7.strip.nstripsfired", &sbs_gemCeR_m7_strip_nstripsfired, &b_sbs_gemCeR_m7_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m8.clust.nclustu", &sbs_gemCeR_m8_clust_nclustu, &b_sbs_gemCeR_m8_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m8.clust.nclustu_tot", &sbs_gemCeR_m8_clust_nclustu_tot, &b_sbs_gemCeR_m8_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m8.clust.nclustv", &sbs_gemCeR_m8_clust_nclustv, &b_sbs_gemCeR_m8_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m8.clust.nclustv_tot", &sbs_gemCeR_m8_clust_nclustv_tot, &b_sbs_gemCeR_m8_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m8.strip.nstrips_keep", &sbs_gemCeR_m8_strip_nstrips_keep, &b_sbs_gemCeR_m8_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m8.strip.nstrips_keepU", &sbs_gemCeR_m8_strip_nstrips_keepU, &b_sbs_gemCeR_m8_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m8.strip.nstrips_keepV", &sbs_gemCeR_m8_strip_nstrips_keepV, &b_sbs_gemCeR_m8_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m8.strip.nstrips_keep_lmax", &sbs_gemCeR_m8_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m8_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m8.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m8_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m8_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m8.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m8_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m8_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m8.strip.nstripsfired", &sbs_gemCeR_m8_strip_nstripsfired, &b_sbs_gemCeR_m8_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.m9.clust.nclustu", &sbs_gemCeR_m9_clust_nclustu, &b_sbs_gemCeR_m9_clust_nclustu);
   fChain->SetBranchAddress("sbs.gemCeR.m9.clust.nclustu_tot", &sbs_gemCeR_m9_clust_nclustu_tot, &b_sbs_gemCeR_m9_clust_nclustu_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m9.clust.nclustv", &sbs_gemCeR_m9_clust_nclustv, &b_sbs_gemCeR_m9_clust_nclustv);
   fChain->SetBranchAddress("sbs.gemCeR.m9.clust.nclustv_tot", &sbs_gemCeR_m9_clust_nclustv_tot, &b_sbs_gemCeR_m9_clust_nclustv_tot);
   fChain->SetBranchAddress("sbs.gemCeR.m9.strip.nstrips_keep", &sbs_gemCeR_m9_strip_nstrips_keep, &b_sbs_gemCeR_m9_strip_nstrips_keep);
   fChain->SetBranchAddress("sbs.gemCeR.m9.strip.nstrips_keepU", &sbs_gemCeR_m9_strip_nstrips_keepU, &b_sbs_gemCeR_m9_strip_nstrips_keepU);
   fChain->SetBranchAddress("sbs.gemCeR.m9.strip.nstrips_keepV", &sbs_gemCeR_m9_strip_nstrips_keepV, &b_sbs_gemCeR_m9_strip_nstrips_keepV);
   fChain->SetBranchAddress("sbs.gemCeR.m9.strip.nstrips_keep_lmax", &sbs_gemCeR_m9_strip_nstrips_keep_lmax, &b_sbs_gemCeR_m9_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("sbs.gemCeR.m9.strip.nstrips_keep_lmaxU", &sbs_gemCeR_m9_strip_nstrips_keep_lmaxU, &b_sbs_gemCeR_m9_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("sbs.gemCeR.m9.strip.nstrips_keep_lmaxV", &sbs_gemCeR_m9_strip_nstrips_keep_lmaxV, &b_sbs_gemCeR_m9_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("sbs.gemCeR.m9.strip.nstripsfired", &sbs_gemCeR_m9_strip_nstripsfired, &b_sbs_gemCeR_m9_strip_nstripsfired);
   fChain->SetBranchAddress("sbs.gemCeR.nlayershit", &sbs_gemCeR_nlayershit, &b_sbs_gemCeR_nlayershit);
   fChain->SetBranchAddress("sbs.gemCeR.nlayershitu", &sbs_gemCeR_nlayershitu, &b_sbs_gemCeR_nlayershitu);
   fChain->SetBranchAddress("sbs.gemCeR.nlayershituv", &sbs_gemCeR_nlayershituv, &b_sbs_gemCeR_nlayershituv);
   fChain->SetBranchAddress("sbs.gemCeR.nlayershitv", &sbs_gemCeR_nlayershitv, &b_sbs_gemCeR_nlayershitv);
   fChain->SetBranchAddress("sbs.gemCeR.track.besttrack", &sbs_gemCeR_track_besttrack, &b_sbs_gemCeR_track_besttrack);
   fChain->SetBranchAddress("sbs.gemCeR.track.ntrack", &sbs_gemCeR_track_ntrack, &b_sbs_gemCeR_track_ntrack);
   fChain->SetBranchAddress("sbs.hcal.adctime", &sbs_hcal_adctime, &b_sbs_hcal_adctime);
   fChain->SetBranchAddress("sbs.hcal.againblk", &sbs_hcal_againblk, &b_sbs_hcal_againblk);
   fChain->SetBranchAddress("sbs.hcal.atimeblk", &sbs_hcal_atimeblk, &b_sbs_hcal_atimeblk);
   fChain->SetBranchAddress("sbs.hcal.colblk", &sbs_hcal_colblk, &b_sbs_hcal_colblk);
   fChain->SetBranchAddress("sbs.hcal.colblk_goodtdc", &sbs_hcal_colblk_goodtdc, &b_sbs_hcal_colblk_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.e", &sbs_hcal_e, &b_sbs_hcal_e);
   fChain->SetBranchAddress("sbs.hcal.e_goodtdc", &sbs_hcal_e_goodtdc, &b_sbs_hcal_e_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.eblk", &sbs_hcal_eblk, &b_sbs_hcal_eblk);
   fChain->SetBranchAddress("sbs.hcal.eblk_goodtdc", &sbs_hcal_eblk_goodtdc, &b_sbs_hcal_eblk_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.idblk", &sbs_hcal_idblk, &b_sbs_hcal_idblk);
   fChain->SetBranchAddress("sbs.hcal.idblk_goodtdc", &sbs_hcal_idblk_goodtdc, &b_sbs_hcal_idblk_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.index", &sbs_hcal_index, &b_sbs_hcal_index);
   fChain->SetBranchAddress("sbs.hcal.nblk", &sbs_hcal_nblk, &b_sbs_hcal_nblk);
   fChain->SetBranchAddress("sbs.hcal.nblk_goodtdc", &sbs_hcal_nblk_goodtdc, &b_sbs_hcal_nblk_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.nclus", &sbs_hcal_nclus, &b_sbs_hcal_nclus);
   fChain->SetBranchAddress("sbs.hcal.ngoodADChits", &sbs_hcal_ngoodADChits, &b_sbs_hcal_ngoodADChits);
   fChain->SetBranchAddress("sbs.hcal.rftime", &sbs_hcal_rftime, &b_sbs_hcal_rftime);
   fChain->SetBranchAddress("sbs.hcal.rowblk", &sbs_hcal_rowblk, &b_sbs_hcal_rowblk);
   fChain->SetBranchAddress("sbs.hcal.rowblk_goodtdc", &sbs_hcal_rowblk_goodtdc, &b_sbs_hcal_rowblk_goodtdc);
   fChain->SetBranchAddress("sbs.hcal.tdctime", &sbs_hcal_tdctime, &b_sbs_hcal_tdctime);
   fChain->SetBranchAddress("sbs.hcal.tdctime_tw", &sbs_hcal_tdctime_tw, &b_sbs_hcal_tdctime_tw);
   fChain->SetBranchAddress("sbs.hcal.tdctimeblk", &sbs_hcal_tdctimeblk, &b_sbs_hcal_tdctimeblk);
   fChain->SetBranchAddress("sbs.hcal.tdctimeblk_tw", &sbs_hcal_tdctimeblk_tw, &b_sbs_hcal_tdctimeblk_tw);
   fChain->SetBranchAddress("sbs.hcal.trigtime", &sbs_hcal_trigtime, &b_sbs_hcal_trigtime);
   fChain->SetBranchAddress("sbs.hcal.x", &sbs_hcal_x, &b_sbs_hcal_x);
   fChain->SetBranchAddress("sbs.hcal.y", &sbs_hcal_y, &b_sbs_hcal_y);
   fChain->SetBranchAddress("sbs.tdctrig.ngoodADChits", &sbs_tdctrig_ngoodADChits, &b_sbs_tdctrig_ngoodADChits);
   fChain->SetBranchAddress("sbs.tdctrig.ngoodTDChits", &sbs_tdctrig_ngoodTDChits, &b_sbs_tdctrig_ngoodTDChits);
   fChain->SetBranchAddress("sbs.tdctrig.nhits", &sbs_tdctrig_nhits, &b_sbs_tdctrig_nhits);
   fChain->SetBranchAddress("sbs.tdctrig.nrefhits", &sbs_tdctrig_nrefhits, &b_sbs_tdctrig_nrefhits);
   fChain->SetBranchAddress("sbs.tdctrig.rftime", &sbs_tdctrig_rftime, &b_sbs_tdctrig_rftime);
   fChain->SetBranchAddress("sbs.tdctrig.trigphase", &sbs_tdctrig_trigphase, &b_sbs_tdctrig_trigphase);
   fChain->SetBranchAddress("sbs.tdctrig.trigphasecorr", &sbs_tdctrig_trigphasecorr, &b_sbs_tdctrig_trigphasecorr);
   fChain->SetBranchAddress("sbs.tdctrig.trigtime", &sbs_tdctrig_trigtime, &b_sbs_tdctrig_trigtime);
   fChain->SetBranchAddress("sbs.tr.n", &sbs_tr_n, &b_sbs_tr_n);
   fChain->SetBranchAddress("scalhel.errcode", &scalhel_errcode, &b_scalhel_errcode);
   fChain->SetBranchAddress("scalhel.evtcount", &scalhel_evtcount, &b_scalhel_evtcount);
   fChain->SetBranchAddress("scalhel.hel", &scalhel_hel, &b_scalhel_hel);
   fChain->SetBranchAddress("scalhel.lhrs.fadc.hel", &scalhel_lhrs_fadc_hel, &b_scalhel_lhrs_fadc_hel);
   fChain->SetBranchAddress("scalhel.lhrs.fadc.pat", &scalhel_lhrs_fadc_pat, &b_scalhel_lhrs_fadc_pat);
   fChain->SetBranchAddress("scalhel.lhrs.fadc.tsettle", &scalhel_lhrs_fadc_tsettle, &b_scalhel_lhrs_fadc_tsettle);
   fChain->SetBranchAddress("scalhel.patcount", &scalhel_patcount, &b_scalhel_patcount);
   fChain->SetBranchAddress("scalhel.patphase", &scalhel_patphase, &b_scalhel_patphase);
   fChain->SetBranchAddress("scalhel.seed", &scalhel_seed, &b_scalhel_seed);
   fChain->SetBranchAddress("singletrack_bb", &singletrack_bb, &b_singletrack_bb);
   fChain->SetBranchAddress("anytrack_bb", &anytrack_bb, &b_anytrack_bb);
   fChain->SetBranchAddress("HALLA_p", &HALLA_p, &b_HALLA_p);
   fChain->SetBranchAddress("hac_bcm_average", &hac_bcm_average, &b_hac_bcm_average);
   fChain->SetBranchAddress("IPM1H04A.XPOS", &IPM1H04A_XPOS, &b_IPM1H04A_XPOS);
   fChain->SetBranchAddress("IPM1H04A.YPOS", &IPM1H04A_YPOS, &b_IPM1H04A_YPOS);
   fChain->SetBranchAddress("IPM1H04E.XPOS", &IPM1H04E_XPOS, &b_IPM1H04E_XPOS);
   fChain->SetBranchAddress("IPM1H04E.YPOS", &IPM1H04E_YPOS, &b_IPM1H04E_YPOS);
   fChain->SetBranchAddress("IGL1I00OD16_16", &IGL1I00OD16_16, &b_IGL1I00OD16_16);
   fChain->SetBranchAddress("fEvtHdr.fEvtTime", &fEvtHdr_fEvtTime, &b_Event_Branch_fEvtHdr_fEvtTime);
   fChain->SetBranchAddress("fEvtHdr.fEvtNum", &fEvtHdr_fEvtNum, &b_Event_Branch_fEvtHdr_fEvtNum);
   fChain->SetBranchAddress("fEvtHdr.fEvtType", &fEvtHdr_fEvtType, &b_Event_Branch_fEvtHdr_fEvtType);
   fChain->SetBranchAddress("fEvtHdr.fEvtLen", &fEvtHdr_fEvtLen, &b_Event_Branch_fEvtHdr_fEvtLen);
   fChain->SetBranchAddress("fEvtHdr.fHelicity", &fEvtHdr_fHelicity, &b_Event_Branch_fEvtHdr_fHelicity);
   fChain->SetBranchAddress("fEvtHdr.fTrigBits", &fEvtHdr_fTrigBits, &b_Event_Branch_fEvtHdr_fTrigBits);
   fChain->SetBranchAddress("fEvtHdr.fRun", &fEvtHdr_fRun, &b_Event_Branch_fEvtHdr_fRun);
   Notify();
}

bool BB_optics_tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void BB_optics_tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t BB_optics_tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef BB_optics_tree_cxx
