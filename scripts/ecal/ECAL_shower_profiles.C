#include "gep_tree_MC.C"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
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
#include "TClonesArray.h"
#include "TGraph.h"
#include "TCanvas.h"

void get_shower_profile(TH1D *h, vector<double> &frac){
  //Make acceptance-averaged profiles:

  //double xmom_min=-1.0,xmom_max=1.0
  //vector<double> frac;

  int nbins = h->GetNbinsX();
  double tot = h->Integral();

  int binlow = 1;
  int binhigh = nbins;
  
  
  tot = h->Integral(binlow,binhigh);
  double min = h->GetBinLowEdge(binlow);
  double max = h->GetBinLowEdge(binhigh)+h->GetBinWidth(binhigh);

  //vector<double> frac;

  frac.clear();
  //  fracvect.clear();
  //momvect.clear();
  
  //frac.push_back(0.0);
  //  momvect.push_back(0.0);
  
  for(int bin=binlow; bin<=binhigh; bin++ ){
    frac.push_back( h->Integral(binlow,bin)/tot );
    cout << "bin, frac = " << bin << ", " << frac[frac.size()-1] << endl;
  }

  //nbins = frac.size()-1;
}

void ECAL_shower_profiles( const char *configfilename, const char *outfilename="ECAL_shower_profiles_temp.root" ){
  TFile *fout = new TFile(outfilename,"RECREATE");

  TChain *C = new TChain("T");

  ifstream configfile(configfilename);

  //let's do the standard list of root files and global cut definitions

  int nbinsmom = 100, mom_min = -1.0, mom_max = 1.0;
  int nbinsx=10, nbinsy=5;
  double xmin = -1.75, xmax = 1.75;
  double ymin = -0.75, ymax = 0.75;

  double Lx = 0.04345, Ly = 0.04362; //actual average block spacing = 43.4 mm!
  
  TString currentline;

  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endlist") ){
    if( !currentline.BeginsWith("#") ){
      C->Add(currentline.Data());
    }
  }

  TCut globalcut="";
  
  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endcut") ){
    if( !currentline.BeginsWith("#") ){
      globalcut += currentline.Data();
    }
  }

  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endconfig") ){
    if( !currentline.BeginsWith("#") ){
      TObjArray *tokens = currentline.Tokenize(" ");

      int ntokens = tokens->GetEntries();

      
      
      if( ntokens >= 2){
	TString skey = ( (TObjString*) (*tokens)[0] )->GetString();
	TString sval = ( (TObjString*) (*tokens)[1] )->GetString();
      
	
	if( skey == "nbinsx" ){
	  nbinsx = sval.Atoi();
	}
	if( skey == "nbinsy" ){
	  nbinsy = sval.Atoi();
	}
	if( skey == "xmin" ){
	  xmin = sval.Atof();
	}
	if( skey == "xmax" ){
	  xmax = sval.Atof();
	}
	
	if( skey == "ymin" ){
	  ymin = sval.Atof();
	}
	if( skey == "ymax" ){
	  ymax = sval.Atof();
	}

	if( skey == "nbinsmom" ){
	  nbinsmom = sval.Atoi();
	}

	if( skey == "mom_min" ){
	  mom_min = sval.Atof();
	}
	if( skey == "mom_max" ){
	  mom_max = sval.Atof();
	}
	
      }
    }
  }


  TClonesArray *Xmom_histos = new TClonesArray("TH1D",nbinsx*nbinsy);
  TClonesArray *Ymom_histos = new TClonesArray("TH1D",nbinsx*nbinsy);
  
  for( int ibinx=0; ibinx<nbinsx; ibinx++ ){
    for( int ibiny=0; ibiny<nbinsy; ibiny++ ){
      TString histname,histtitle;
      histname.Form( "ECAL_Xmom_iy%d_ix%d", ibiny, ibinx );
      histtitle.Form( "ECAL X shower x bin=%d ybin = %d; #bar{x}/L;",ibinx, ibiny);
      new( (*Xmom_histos)[ibiny+nbinsy*ibinx] ) TH1D( histname.Data(), histtitle.Data(), nbinsmom, mom_min, mom_max );

      histname.Form( "ECAL_Ymom_iy%d_ix%d", ibiny, ibinx );
      histtitle.Form( "ECAL Y shower x bin=%d ybin = %d; #bar{y}/L;",ibinx, ibiny);
      new( (*Ymom_histos)[ibiny+nbinsy*ibinx] ) TH1D( histname.Data(), histtitle.Data(), nbinsmom, mom_min, mom_max );
    }
  }

  long nevent = 0;

  gep_tree_MC *T = new gep_tree_MC(C);

  TTreeFormula *GlobalCut = new TTreeFormula( "GlobalCut", globalcut, C );

  C->SetBranchStatus("*",0);
  C->SetBranchStatus("heep.*",1);
  C->SetBranchStatus("MC.*",1); //For MC analysis, enable MC truth variables
  C->SetBranchStatus("earm.ecal.*",1);
  //  C->SetBranchStatus("
  
  int treenum=0, oldtreenum=-1;
  
  while( C->GetEntry( nevent++ ) ){
    if( nevent % 1000 == 0 ) cout << "event " << nevent << endl;

    treenum = C->GetTreeNumber();
    if( treenum != oldtreenum ){

      oldtreenum = treenum;

      GlobalCut->UpdateFormulaLeaves();
    }

    bool passedcut = GlobalCut->EvalInstance(0) != 0;

    if( passedcut ){

      int nhits_ecal = T->earm_ecal_nblk;

      double xmom = 0.0, ymom= 0.0;
      double E = 0.0;

      double Emax = 0.0;
      
      double xcellmax =0.0, ycellmax = 0.0;

      int imax=0;

      int rowmax = 0, colmax=0;
      
      //      int rowmin=1000, rowmax=-1, colmin=1000, colmax=-1;
      double xblklow, xblkhigh, yblklow, yblkhigh; 
      for( int ihit=0; ihit<nhits_ecal; ihit++ ){
	double eblk = T->earm_ecal_clus_blk_e[ihit];
	double xblk = T->earm_ecal_clus_blk_x[ihit];
	double yblk = T->earm_ecal_clus_blk_y[ihit];

	int rowblk = T->earm_ecal_clus_blk_row[ihit];
	int colblk = T->earm_ecal_clus_blk_col[ihit];
	
	E += eblk;
	xmom += xblk*eblk;
	ymom += yblk*eblk;

	if( ihit == 0 || eblk > Emax ){
	  imax = ihit;
	  Emax = eblk;
	  xcellmax = xblk;
	  ycellmax = yblk;
	  rowmax = rowblk;
	  colmax = colblk; 
	}

	if( ihit == 0 || xblk < xblklow ) xblklow = xblk;
	if( ihit == 0 || xblk > xblkhigh ) xblkhigh = xblk;
	if( ihit == 0 || yblk < yblklow ) yblklow = yblk;
	if( ihit == 0 || yblk > yblkhigh ) yblkhigh = yblk;
	
      }
      
      int binx = int( (xcellmax-xmin)/(xmax-xmin)*double(nbinsx) );
      int biny = int( (ycellmax-ymin)/(ymax-ymin)*double(nbinsy) );

      xmom /= E;
      ymom /= E;

      xmom -= xcellmax;
      ymom -= ycellmax;

      xmom /= Lx;
      ymom /= Ly;

      //Make sure cluster is at least two blocks along both x and y:
      if( xblkhigh - xblklow > 0.5*Lx && yblkhigh-yblklow > 0.5*Ly && rowmax > 0 && rowmax < 68 && binx >= 0 && binx < nbinsx && biny >= 0 && biny < nbinsy ){
      
	( (TH1D*) (*Xmom_histos)[biny+binx*nbinsy] )->Fill( xmom );
	( (TH1D*) (*Ymom_histos)[biny+binx*nbinsy] )->Fill( ymom );
      }
    }
    
  }

  //After we validate that the histograms look sensible, then we'll write the code to generate the "shower maps":

  TString dbfilename = outfilename;

  dbfilename.ReplaceAll(".root",".dat");

  ofstream dbfile(dbfilename.Data());

  TString templine;
  templine.Form("earm.ecal.nbinsxprof = %d", nbinsx );
  dbfile << templine << endl;
  templine.Form("earm.ecal.nbinsyprof = %d", nbinsy );
  dbfile << templine << endl;

  templine.Form( "earm.ecal.xminprof = %g", xmin );
  dbfile << templine << endl;
  templine.Form( "earm.ecal.xmaxprof = %g", xmax );
  dbfile << templine << endl;

  templine.Form( "earm.ecal.yminprof = %g", ymin );
  dbfile << templine << endl;
  templine.Form( "earm.ecal.ymaxprof = %g", ymax );
  dbfile << templine << endl;


  templine.Form( "earm.ecal.Lxprof = %g", Lx );
  dbfile << templine << endl;
  templine.Form( "earm.ecal.Lyprof = %g", Ly );
  dbfile << templine << endl;

  templine.Form( "earm.ecal.nbinsprof = %d", nbinsmom );
  dbfile << templine << endl << endl;
  
  TCanvas *c1 = new TCanvas("c1","c1",1200,900);
  c1->Divide(2,2,.001,.001); //plot histograms and S-curves:

  vector<vector<double> > xprofiles(nbinsx*nbinsy);
  vector<vector<double> > yprofiles(nbinsx*nbinsy);
  
  for( int binx=0; binx<nbinsx; binx++){
    for( int biny=0; biny<nbinsy; biny++ ){
      int bin = biny + nbinsy*binx;

      std::vector<double> fractemp;
      std::vector<double> momtemp;
      
      TH1D *htemp = ( (TH1D*) (*Xmom_histos)[bin] );

      for( int ibin=1; ibin<=nbinsmom; ibin++ ){
	momtemp.push_back( htemp->GetBinCenter(ibin) );
      }
      get_shower_profile( htemp, fractemp );

      TGraph *gscurvetemp = new TGraph( nbinsmom, &(momtemp[0]), &(fractemp[0]) );
      TString graphname = htemp->GetName();
      graphname.Prepend( "gScurveX_" );
      gscurvetemp->SetName( graphname.Data() );
      gscurvetemp->SetMarkerStyle(20);
      gscurvetemp->SetLineColor(2);
      gscurvetemp->SetMarkerColor(2);
      gscurvetemp->SetTitle( ";#bar{x}/L_{x}; Fraction" );
      
      c1->cd(1);
      htemp->Draw();
      c1->cd(2);
      gscurvetemp->Draw("AP");

      xprofiles[bin] = fractemp;
      
      htemp = ( (TH1D*) (*Ymom_histos)[bin] );

      vector<double> fracY, momY;
      
      for( int ibin = 1; ibin <= nbinsmom; ibin++ ){
	momY.push_back( htemp->GetBinCenter(ibin) );
      }
      get_shower_profile( htemp, fracY );

      yprofiles[bin] = fracY;
      
      TGraph *gscurveY = new TGraph( nbinsmom, &(momY[0]), &(fracY[0]) );
      graphname = htemp->GetName();
      graphname.Prepend( "gScurveY_" );
      gscurveY->SetName( graphname.Data() );
      gscurveY->SetMarkerStyle(20);
      gscurveY->SetLineColor(2);
      gscurveY->SetMarkerColor(2);

      gscurveY->SetTitle( ";#bar{y}/L_{y}; Fraction" );

      c1->cd(3);
      htemp->Draw();
      c1->cd(4);
      gscurveY->Draw("AP");
      
      TString pdffilename = outfilename;
      pdffilename.ReplaceAll(".root",".pdf");
      if( bin == 0 ) pdffilename += "(";
      if( bin+1 == nbinsx*nbinsy ) pdffilename += ")";
      
      c1->Print( pdffilename );
      
    }
  }

  dbfile << "earm.ecal.xprofiles = " << endl;
  int entriesperline = 16;
  for( int i=0; i<nbinsx*nbinsy; i++ ){
    TString dbentry;
    for( int j=0; j<xprofiles[i].size(); j++ ){
      dbentry.Form( "%15.8g  ", xprofiles[i][j] );
      dbfile << dbentry;
      if( (j+1)%entriesperline == 0 ) dbfile << endl;
    }
    dbentry.Form( "# X bin %d Y bin %d", i/nbinsy, i%nbinsy );
    dbfile << dbentry << endl;
  }

  dbfile << "earm.ecal.yprofiles = " << endl;
  entriesperline = 16;
  for( int i=0; i<nbinsx*nbinsy; i++ ){
    TString dbentry;
    for( int j=0; j<yprofiles[i].size(); j++ ){
      dbentry.Form( "%15.8g  ", yprofiles[i][j] );
      dbfile << dbentry;
      if( (j+1)%entriesperline == 0 ) dbfile << endl;
    }
    dbentry.Form( "# X bin %d Y bin %d", i/nbinsy, i%nbinsy );
    dbfile << dbentry << endl;
  }
  
  
  
  fout->cd();
  Xmom_histos->Compress();
  Ymom_histos->Compress();
  Xmom_histos->Write();
  Ymom_histos->Write();

}
