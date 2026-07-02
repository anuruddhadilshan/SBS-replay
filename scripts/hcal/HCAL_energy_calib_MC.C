#include "SBSGMN_tree.C"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TDecompSVD.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TString.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "TTreeFormula.h"
#include "TCut.h"
#include "TGraph.h"
#include "TH1D.h"
#include "TH2D.h"

void HCAL_energy_calib_test( const char *infilename, const char *outfilename="temp.root" ){

  TFile *fout = new TFile( outfilename, "RECREATE" );
  TChain *C = new TChain("Tout");

  ifstream configfile(infilename);

  TString currentline;

  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endlist") ){
    if( !currentline.BeginsWith("#") ){
      C->Add(currentline.Data());
    }
  }

  SBSGMN_tree *T = new SBSGMN_tree(C);
  
  //What configuration information do we need? Maybe none. But we do want to read a global cut:

  TCut globalcut = "";

  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endcut") ){
    if( !currentline.BeginsWith("#") ){
      globalcut += currentline.Data();
    }
  }

  TTreeFormula *GlobalCut = new TTreeFormula( "GlobalCut", globalcut, C );

  const int nchan = 12*24; //288
  TMatrixD Mhcal(nchan,nchan);
  TVectorD bhcal(nchan);
  TVectorD hcal_nhits_chan(nchan);
  TVectorD hcal_again_old(nchan);

  for( int i=0; i<nchan; i++ ){
    for( int j=0; j<nchan; j++ ){
      Mhcal(i,j) = 0.0;
    }
    bhcal(i) = 0.0;
    hcal_nhits_chan(i) = 0.0;
  }

  //chi2 = sum_i (E_i - sum_j c_j ADC_j)^2
  // dchi2/dc_k = -2 sum_i (E_i - sum_j c_j ADC_j) * ADC_k = 0
  // sum_i E_i * ADC_k = sum_i sum_j c_j ADC_j ADC_k
  
  long nevent=0;
  
  int treenum=0, currenttreenum=0;

  double Emin_HCAL = 0.01, Emax_HCAL = 1.0;
  
  while( C->GetEntry( nevent++ ) ){

    if( nevent % 10000 == 0 ) cout << nevent << endl;
    currenttreenum = C->GetTreeNumber();

    if( currenttreenum != treenum || nevent == 1 ){
      treenum = currenttreenum;
      GlobalCut->UpdateFormulaLeaves();
    }

    bool passed_global_cut = GlobalCut->EvalInstance(0) != 0;

    //assuming these are H(e,e'p) events:
    if( passed_global_cut && T->ibest_HCAL == 0 && T->nblkHCAL>0 ){
      double Tp = T->Q2 / (2.0*0.938272);
      vector<double> ADChcalhits(T->nblkHCAL,0.0);

      int ngoodhits=0;

      double T0 = T->atimeblkHCAL[0];

      int rowmax = int( T->rowblkHCAL[0] );
      int colmax = int( T->colblkHCAL[0] );
      
      for( int iblk=0; iblk<T->nblkHCAL; iblk++ ){

	if( (iblk == 0 || fabs( T->atimeblkHCAL[iblk] - T0 ) <= 10.0 ) && T->EHCAL >= Emin_HCAL && T->EHCAL <= Emax_HCAL && rowmax > 0 && rowmax < 23 && colmax > 0 && colmax < 11 ) {
	  ngoodhits++;
	  ADChcalhits[iblk] = (T->eblkHCAL[iblk]/T->againblkHCAL[iblk]);
	 
	  int chan = int( T->idblkHCAL[iblk] ) - 1;
	  
	  hcal_nhits_chan(chan) += 1.0;
	  bhcal[chan] += Tp * ADChcalhits[iblk];

	  hcal_again_old[chan] = T->againblkHCAL[iblk];
	}
      }

      for( int iblk=0; iblk<T->nblkHCAL; iblk++ ){
	int chan_i = int( T->idblkHCAL[iblk] ) - 1;
	for( int jblk=0; jblk<T->nblkHCAL; jblk++ ){
	  int chan_j = int( T->idblkHCAL[jblk] ) - 1;
	  Mhcal( chan_i, chan_j ) += ADChcalhits[iblk]*ADChcalhits[jblk];
	}
      } 
    }
  }

  //Zero out channels for which the number of good hits is less than, say, 500:

  //double sampfrac_target = 0.08;
  double sampfrac_target = 0.1134 * 0.08/0.065;
  
  
  int minhits=500;

  //we force all the gains for channels with insufficient statistics to be zero:

  set<int> bad_chan_list;

  double ngoodchan = 0.0;
  double avg_gain = 0.0;
  
  for( int ichan=0; ichan<nchan; ichan++ ){
    if( int(hcal_nhits_chan( ichan ) ) < minhits ){
      bhcal( ichan ) = 1.0;
      bad_chan_list.insert( ichan );
      for( int jchan=0; jchan<nchan; jchan++ ){
	if( jchan != ichan ){
	  Mhcal(ichan,jchan) = 0.0;
	  Mhcal(jchan,ichan) = 0.0;
	} else {
	  Mhcal(ichan,jchan) = 1.0;
	}
      }
    } 
  }

  TDecompSVD Ahcal(Mhcal);
  Ahcal.Solve(bhcal);

  for( int ichan = 0; ichan < nchan; ichan++ ){
    if( bad_chan_list.find( ichan ) == bad_chan_list.end() ){
      ngoodchan += 1.0;
      avg_gain += bhcal( ichan );
    }
  }

  //average calibrated gain:
  avg_gain /= ngoodchan;
  avg_gain *= sampfrac_target;

  fout->cd();
  TH1D *hEHCAL_old = new TH1D("hEHCAL_old",";Old HCAL energy (GeV);",500,0.0,2.5);
  TH1D *hEHCAL_calib = new TH1D("hEHCAL_calib",";Calibrated HCAL energy (GeV);", 500,0.0,2.5);

  TH1D *hSampFrac_old = new TH1D("hSampFrac_old", ";Old sampling fraction;",500,0.0,0.25);
  TH1D *hSampFrac_calib = new TH1D("hSampFrac_calib", ";Calibrated sampling fraction;",500,0,0.25);
  TH1D *hnblk_good_atime = new TH1D("hnblk_good_atime", ";Number of good hits in cluster;", 26,-0.5,25.5);

  TH1D *hNewGainRatio = new TH1D("hNewGain",";new gain/old gain (calibrated channels only);",100,0,2);

  TH2D *hEblkMax_vs_chan = new TH2D("hEblkMax_vs_chan",";max channel;E_{max} calibrated (GeV)", nchan, 0.5, nchan+0.5, 500, 0, 2.5 );
  TH2D *hEclust_vs_chan = new TH2D("hEclust_vs_chan", ";max channel;E_{clust} calibrated (GeV)", nchan, 0.5, nchan+0.5, 500, 0, 2.5 );

  TH2D *hSampFrac_vs_chan = new TH2D("hSampFrac_vs_chan",";max channel;Sampling Fraction (calibrated)", nchan, 0.5, nchan+0.5, 500, 0, 0.25);

  TH2D *hADCblk_vs_chan = new TH2D("hADCblk_vs_chan", ";channel; raw ADC (all blocks)", nchan, 0.5, nchan+0.5, 1000, 0, 1000 );
  TH2D *hADCmax_vs_chan = new TH2D("hADCmax_vs_chan", ";channel; raw ADC (max block)", nchan, 0.5, nchan+0.5, 1000, 0, 1000 );

  TH2D* hEHCAL_old_nblocks = new TH2D("hEHCAL_old_nblocks", ";Number of hits in cluster;Old HCAL energy (GeV)", 26,-0.5, 25.5, 500,0.0,2.5); 
  TH2D* hEHCAL_calib_nblocks = new TH2D("hEHCAL_calib_nblocks", ";Number of hits in cluster;Calibrated HCAL energy (GeV)", 26,-0.5, 25.5, 500,0.0,2.5); 
  TH2D* hEHCAL_calib_ngoodblocks = new TH2D("hEHCAL_calib_ngoodblocks", ";Number of good hits in cluster;Calibrated HCAL energy (GeV)", 26,-0.5, 25.5, 500,0.0,2.5);
  
  TH1D *hTp = new TH1D("hTp",";#nu = Q^{2}/(2M) = T_{p};", 1000, 0, 10 );
  
  vector<double> Channel, Gain;
  for( int ichan=0; ichan<nchan; ichan++ ){
    Channel.push_back( ichan+1 );
    if( bad_chan_list.find( ichan ) == bad_chan_list.end() ){
      Gain.push_back( bhcal( ichan ) * sampfrac_target );

      hNewGainRatio->Fill( Gain.back() / hcal_again_old[ichan] );
    } else {
      Gain.push_back( avg_gain );
    }
  }

  TGraph *HCAL_gain_vs_chan = new TGraph( nchan, &(Channel[0]), &(Gain[0]) );

 
  
  HCAL_gain_vs_chan->SetMarkerStyle(20);
  HCAL_gain_vs_chan->Write( "HCAL_gain_vs_chan" );
  
  //now loop over the events again for diagnostics:
  nevent = 0;
  treenum = 0;
  currenttreenum = 0;

  while( C->GetEntry( nevent++ ) ){
    currenttreenum = C->GetTreeNumber();

    if( nevent % 10000 == 0 ) cout << nevent << endl;
    
    if( currenttreenum != treenum || nevent == 1 ){
      treenum = currenttreenum;
      GlobalCut->UpdateFormulaLeaves();
    }

    bool passed_global_cut = GlobalCut->EvalInstance(0) != 0;

    //assuming these are H(e,e'p) events:
    if( passed_global_cut && T->ibest_HCAL == 0 && T->nblkHCAL>0 ){
      double Tp = T->Q2 / (2.0*0.938272);

      hTp->Fill( Tp );
      
      //calibrated energy:
      double Ecalib = 0.0;

      int ngoodhits=0;

      double T0 = T->atimeblkHCAL[0];

      double Esum_calib = 0.0;

      int chanmax = int( T->idblkHCAL[0] ) - 1;
      double ADCmax = T->eblkHCAL[0]/T->againblkHCAL[0];
      double Emax_calib = ADCmax * bhcal( chanmax ) * sampfrac_target;

      hADCmax_vs_chan->Fill( chanmax+1, ADCmax );
      
      for( int iblk=0; iblk<T->nblkHCAL; iblk++ ){
	if( iblk == 0 || fabs( T->atimeblkHCAL[iblk] - T0 ) <= 10.0 ) {
	  ngoodhits++;
	  int chan = int( T->idblkHCAL[iblk] ) - 1;

	  //grab OLD gain
	  double oldgain = T->againblkHCAL[iblk];
	  double ADC = T->eblkHCAL[iblk]/oldgain;

	  hADCblk_vs_chan->Fill( chan + 1, ADC );
	  //double Ecalib;
	  if( bad_chan_list.find(chan) == bad_chan_list.end() ){ //this channel was calibrated:
	    Ecalib = ADC * bhcal( chan ) * sampfrac_target;
	  } else {
	    Ecalib = ADC * avg_gain;
	  }

	  Esum_calib += Ecalib;
	}

       
      }

      if( bad_chan_list.find( chanmax ) == bad_chan_list.end() ){
	hEblkMax_vs_chan->Fill( chanmax+1, Emax_calib );
	hEclust_vs_chan->Fill( chanmax+1, Esum_calib );
	hSampFrac_vs_chan->Fill( chanmax+1, Esum_calib/Tp );
      }
      
      hEHCAL_old->Fill( T->EHCAL );
      hSampFrac_old->Fill( T->EHCAL/Tp );

      hEHCAL_calib->Fill( Esum_calib );
      hSampFrac_calib->Fill( Esum_calib/Tp );
	    
      hnblk_good_atime->Fill( ngoodhits );

      hEHCAL_old_nblocks->Fill(T->nblkHCAL, T->EHCAL);
      hEHCAL_calib_nblocks->Fill(T->nblkHCAL, Esum_calib);
      hEHCAL_calib_ngoodblocks->Fill( ngoodhits, Esum_calib);
    }
  }

  fout->Write();
      
}
