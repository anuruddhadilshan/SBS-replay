#include "gep_tree_parsed.C"
#include "TChain.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "TCanvas.h"
#include "TPad.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TCut.h"
#include "TTreeFormula.h"
#include "TString.h"
#include "TObjString.h"
#include "TObjArray.h"
#include "TMath.h"

void GEPasym_quick_and_dirty(const char *configfilename, const char *outfilename){
  TCut trackquality_kin3 = "ntrackFPP>0&&ntrackFT>0&&abs(vz+0.1)<0.18&&((nhitsFT>4||ngoodhitsFT>2))&&((nhitsFPP>4||ngoodhitsFPP>2))&&scloseFPP<0.005";
  // Kin 3 cuts: 
  TCut dxdyHCALcut_kin3 = "sqrt(pow((xFPP+xpFPP*6.7-xHCAL-0.191)/0.052,2)+pow((yFPP+ypFPP*6.7-yHCAL+0.0107)/0.046,2))<=3.0";

  TH1::SetDefaultSumw2();
  
  TCut dppcut_kin3 = "abs(dpp-0.01605)<3.0*0.0132";

  TCut dtcut_kin3 = "((runnum>=4043&&abs(dtADC)<9)||(runnum<=4042&&abs(dtADC-9.1225+4.8794*xECAL+1.878*pow(xECAL,2))<=10.))";

  TCut dxdycut_kin3 = "sqrt(pow((dxECAL-(0.008907-0.0192*xECAL))/0.0134,2)+pow((dyECAL-(0.001+0.0048*xECAL+0.0146*pow(xECAL,2)+0.0099*pow(xECAL,3)))/0.0159,2))<=3.0";

  TFile *fout = new TFile(outfilename,"RECREATE");
  
  TChain *C = new TChain("Tout");

  gep_tree_parsed *T = new gep_tree_parsed(C);
  
  ifstream configfile(configfilename);

  if( !configfile ) return;

  TString currentline;
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endlist") ){
    if( !currentline.BeginsWith("#") ){
      C->Add(currentline.Data());
    }
  }

  TCut globalcut = "";
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endcut") ){
    if( !currentline.BeginsWith("#") ){
      globalcut += currentline;
    }
  }

  int nbinsphi = 18;
  int pTmin = 0.1, pTmax = 1.2;

  vector<int> rmin, rmax, IHWPrun;
  
  while( currentline.ReadLine(configfile) && !currentline.BeginsWith("endIHWPconfig") ){
    if( !currentline.BeginsWith("#") ){
      TObjArray *tokens = currentline.Tokenize(" ");
      if( tokens->GetEntries() >= 3 ){
	TString srmin = ( (TObjString*) (*tokens)[0] )->GetString();
	TString srmax = ( (TObjString*) (*tokens)[1] )->GetString();
	TString sIHWP = ( (TObjString*) (*tokens)[2] )->GetString();
	rmin.push_back( srmin.Atoi() );
	rmax.push_back( srmax.Atoi() );
	IHWPrun.push_back( sIHWP.Atoi() );
      }
    }
  }

  fout->cd();
  
  TH1D *hphiplus = new TH1D("hphiplus", "Helicity +; #varphi (rad);", 18,-TMath::Pi(), TMath::Pi() );
  TH1D *hphiminus = new TH1D("hphiminus", "Helicity -; #varphi (rad);", 18, -TMath::Pi(), TMath::Pi() );

  TH1D *hphisum = new TH1D("hphisum", "Helicity sum; #varphi (rad);", 18, -TMath::Pi(), TMath::Pi() );
  TH1D *hphidiff = new TH1D("hphidiff", "Helicity diff; #varphi (rad);", 18, -TMath::Pi(), TMath::Pi() );
  
  TTreeFormula *GlobalCut = new TTreeFormula( "GlobalCut", globalcut, C );

  int treenum = -1, oldtreenum = -1;
  
  long nevent = 0;
  while( C->GetEntry(nevent++) ){
    if( nevent % 10000 == 0 ) cout << "event " << nevent << ", run number = " << int(T->runnum) << endl;

    treenum = C->GetTreeNumber();
    if( treenum != oldtreenum ){
      std::cout << "Switching trees, run number, file num, file name, nevent = " << T->runnum << ", " << treenum << ", " 
		<< C->GetFile()->GetName() << ", " << nevent << std::endl;
      GlobalCut->UpdateFormulaLeaves();
      oldtreenum = treenum;
    }

    //Let -1 = OUT, 1 = IN:
    int IHWPstate = 0;

    //MOLLER measurement showed negative (positive) beam polarization for IHWP OUT (IN)
    // Therefore if we multiply the helicity state by the HWP sign we should get the correct helicity sign
    for( int i=0; i<rmin.size(); i++ ){
      if( T->runnum >= rmin[i] && T->runnum <= rmax[i] ){
	IHWPstate = IHWPrun[i];
      }
    }

    double pT = T->pp * sin(T->thetaFPP);
    
    bool passedcut = GlobalCut->EvalInstance(0) != 0;
    if( passedcut && pT >= 0.07 && pT <= 1.0 ){
      double helicity_state = T->helicity * IHWPstate;
      
      if( helicity_state > 0.5 ){ // + helicity
	hphiplus->Fill( T->phiFPP );
	hphisum->Fill( T->phiFPP );
	//hphidiff->Fill( T->phiFPP, 1.0 );
      } else if( helicity_state < -0.5 ){ // - helicity
	hphiminus->Fill( T->phiFPP );
	hphisum->Fill( T->phiFPP );
	//hphidiff->Fill( T->phiFPP, -1.0 );
      }
    }
  }

  hphisum->Add( hphiplus, hphiminus, 1, 1 );
  hphidiff->Add( hphiplus, hphiminus, 1, -1 );

  hphidiff->Divide(hphisum);

  fout->Write();
}
