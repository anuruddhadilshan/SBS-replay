//#if !defined(__CLING__) || defined(__ROOTCLING__)
#include <iostream>

#include "TSystem.h"
#include "THaGlobals.h"
#include "TString.h"
#include "TFile.h"
#include "TList.h"
#include "TObject.h"
#include "TClonesArray.h"

#include "THaEvData.h"
#include "THaEvent.h"
#include "THaRun.h"
#include "THaAnalyzer.h"
#include "THaVarList.h"
#include "THaInterface.h"
#include "THaGoldenTrack.h"
#include "THaPrimaryKine.h"
#include "THaDecData.h"

#include "SBSBigBite.h"
#include "SBSBBShower.h"
#include "SBSBBTotalShower.h"
#include "SBSGRINCH.h"
//#include "SBSCherenkovDetector.h"
#include "SBSEArm.h"
#include "SBSHCal.h"
#include "SBSTimingHodoscope.h"
#include "SBSGEMSpectrometerTracker.h"
#include "SBSGEMTrackerBase.h"
#include "SBSRasteredBeam.h"
#include "LHRSScalerEvtHandler.h"
#include "SBSScalerEvtHandler.h"
//#endif

void replay_gmn(UInt_t runnum=10491, Long_t nevents=-1, Long_t firstevent=0, const char *fname_prefix="e1209019", UInt_t firstsegment=0, UInt_t maxsegments=1, Int_t pedestalmode=0, Int_t cmplots=0)
{

  THaAnalyzer* analyzer = new THaAnalyzer;
  
  SBSBigBite* bigbite = new SBSBigBite("bb", "BigBite spectrometer" );
  //bigbite->AddDetector( new SBSBBShower("ps", "BigBite preshower") );
  //bigbite->AddDetector( new SBSBBShower("sh", "BigBite shower") );
  SBSBBTotalShower* ts= new SBSBBTotalShower("ts", "sh", "ps", "BigBite shower");
  ts->SetDataOutputLevel(0);
  bigbite->AddDetector( ts );
  ts->SetStoreEmptyElements(kFALSE);
  ts->GetShower()->SetStoreEmptyElements(kFALSE);
  ts->GetPreShower()->SetStoreEmptyElements(kFALSE);

  SBSGenericDetector* bbtrig= new SBSGenericDetector("bbtrig","BigBite shower ADC trig");
  bbtrig->SetModeADC(SBSModeADC::kADC);
  bbtrig->SetModeTDC(SBSModeTDC::kTDC);
  bbtrig->SetStoreEmptyElements(kFALSE);
  bigbite->AddDetector( bbtrig );
  
  SBSGenericDetector* tdctrig= new SBSGenericDetector("tdctrig","BigBite shower TDC trig");
  tdctrig->SetModeADC(SBSModeADC::kNone);
  //  tdctrig->SetModeTDC(SBSModeTDC::kTDC);
  tdctrig->SetModeTDC(SBSModeTDC::kTDCSimple);
  tdctrig->SetStoreEmptyElements(kFALSE);
  bigbite->AddDetector( tdctrig );

  
  //SBSGenericDetector *grinch_tdc = new SBSGenericDetector("grinch_tdc","GRINCH TDC data");
  //SBSCherenkovDetector *grinch_tdc = new SBSCherenkovDetector("grinch_tdc","GRINCH TDC data");
  SBSGRINCH *grinch_tdc = new SBSGRINCH("grinch_tdc","GRINCH TDC data");
  SBSGenericDetector *grinch_adc = new SBSGenericDetector("grinch_adc","GRINCH ADC data");
  grinch_adc->SetModeADC(SBSModeADC::kWaveform);
  grinch_adc->SetModeTDC(SBSModeTDC::kNone);
  grinch_adc->SetStoreEmptyElements(kFALSE);
  grinch_adc->SetStoreRawHits(kFALSE);

  grinch_tdc->SetModeTDC(SBSModeTDC::kTDC);
  //grinch_tdc->SetModeTDC(SBSModeTDC::kCommonStartTDC);
  grinch_tdc->SetModeADC(SBSModeADC::kNone);
  grinch_tdc->SetStoreEmptyElements(kFALSE);
  grinch_tdc->SetStoreRawHits(kFALSE);
  grinch_tdc->SetDisableRefTDC(true);
  bigbite->AddDetector(grinch_adc);
  bigbite->AddDetector(grinch_tdc);
 
  SBSTimingHodoscope* hodotdc = new  SBSTimingHodoscope("hodotdc", "BigBite hodo");
  hodotdc->SetModeTDC(SBSModeTDC::kTDC);
  hodotdc->SetModeADC(SBSModeADC::kNone);
  hodotdc->SetStoreEmptyElements(kFALSE);
  hodotdc->SetDataOutputLevel(1);// => this adds in the output the elements belonging to the "main" cluster.
  
  SBSTimingHodoscope* hodoadc = new  SBSTimingHodoscope("hodoadc", "BigBite hodo");
  hodoadc->SetModeTDC(SBSModeTDC::kNone);
  hodoadc->SetModeADC(SBSModeADC::kADC);
  hodoadc->SetStoreEmptyElements(kFALSE);
  hodoadc->SetStoreRawHits(kFALSE);
  hodotdc->SetDataOutputLevel(0);
  //bigbite->AddDetector( new THaShower("ps", "BigBite preshower") );
  bigbite->AddDetector(hodotdc);
  bigbite->AddDetector(hodoadc);
  //bigbite->AddDetector( new SBSGEMSpectrometerTracker("gem", "GEM tracker") );
  SBSGEMSpectrometerTracker *bbgem = new SBSGEMSpectrometerTracker("gem", "BigBite Hall A GEM data");
  bool pm =  ( pedestalmode != 0 );
  //this will override the database setting:
  ( static_cast<SBSGEMTrackerBase *> (bbgem) )->SetPedestalMode( pm );
  ( static_cast<SBSGEMTrackerBase *> (bbgem) )->SetMakeCommonModePlots( cmplots );
  bigbite->AddDetector(bbgem);
  gHaApps->Add(bigbite);
    
  SBSEArm *harm = new SBSEArm("sbs","Hadron Arm with HCal");
  SBSHCal* hcal =  new SBSHCal("hcal","HCAL");
  //hcal->SetStoreRawHits(kTRUE);
  hcal->SetStoreEmptyElements(kFALSE);
  harm->AddDetector(hcal);

  SBSGenericDetector* sbstrig= new SBSGenericDetector("trig","HCal trigs");
  sbstrig->SetModeADC(SBSModeADC::kWaveform);
  //sbstrig->SetStoreRawHits(kTRUE);
  sbstrig->SetStoreEmptyElements(kFALSE);
  harm->AddDetector( sbstrig );  

  SBSGenericDetector *tdctrig_sbs = new SBSGenericDetector("tdctrig", "SBS trigger TDCs");
  tdctrig_sbs->SetModeADC(SBSModeADC::kNone);
  //  tdctrig_sbs->SetModeTDC(SBSModeTDC::kTDC);
  tdctrig_sbs->SetModeTDC(SBSModeTDC::kTDCSimple);
  tdctrig_sbs->SetStoreEmptyElements(kFALSE);
  harm->AddDetector( tdctrig_sbs );
  
  gHaApps->Add(harm);

  // add decoder
  THaApparatus* decL = new THaDecData("DL","Misc. Decoder Data");
  gHaApps->Add( decL );
  
  // add *rastered* beam
  THaApparatus* Lrb = new SBSRasteredBeam("Lrb","Raster Beamline for FADC");
  gHaApps->Add(Lrb);
  
  THaApparatus* sbs = new SBSRasteredBeam("SBSrb","Raster Beamline for FADC");
  gHaApps->Add(sbs);
  
  gHaPhysics->Add( new THaGoldenTrack( "BB.gold", "BigBite golden track", "bb" ));
  gHaPhysics->Add( new THaPrimaryKine( "e.kine", "electron kinematics", "bb", 0.0, 0.938272 ));
  
  //gHaEvtHandlers->Add (new THaScalerEvtHandler("Left","HA scaler event type 140"));
  //gHaEvtHandlers->Add (new THaScalerEvtHandler("SBS","HA scaler event type 141"));
  
  //bigbite->SetDebug(2);
  //harm->SetDebug(2);

  LHRSScalerEvtHandler *lScaler = new LHRSScalerEvtHandler("Left","HA scaler event type 140");
  // lScaler->SetDebugFile(&debugFile);
  gHaEvtHandlers->Add(lScaler);

  SBSScalerEvtHandler *sbsScaler = new SBSScalerEvtHandler("sbs","SBS Scaler Bank event type 1");
  //sbsScaler->AddEvtType(1);             // Repeat for each event type with scaler banks
  sbsScaler->SetUseFirstEvent(kTRUE);
  gHaEvtHandlers->Add(sbsScaler);
   
  //THaInterface::SetDecoder( SBSSimDecoder::Class() );
  THaEvent* event = new THaEvent;

  TString prefix = gSystem->Getenv("DATA_DIR");
  
  bool segmentexists = true;
  int segment=firstsegment; 

  int lastsegment=firstsegment;
  
  TDatime now = TDatime();
  
  
  //EPAF: copied the following from replay_BBGEM.C, as this script seems to be thought to handle splits properly.
  int stream = 0;
 
  TClonesArray *filelist = new TClonesArray("THaRun",10);

  vector<TString> pathlist;
  pathlist.push_back( prefix );

  if( prefix != "/adaqeb1/data1" )
    pathlist.push_back( "/adaqeb1/data1" );

  if( prefix != "/adaqeb2/data1" )
    pathlist.push_back( "/adaqeb2/data1" );

  if( prefix != "/adaqeb3/data1" )
    pathlist.push_back( "/adaqeb3/data1" );

  if( prefix != "/adaq1/data1/sbs" )
    pathlist.push_back( "/adaq1/data1/sbs" );

  if( prefix != "/cache/mss/halla/sbs/raw" )
    pathlist.push_back( "/cache/mss/halla/sbs/raw" );

  for( int i=0; i<pathlist.size(); i++ ){
    cout << "search paths = " << pathlist[i] << endl;
  }

  TDatime RunDate = TDatime(); 

  int max1 = maxsegments;

  int segcounter=0;
  
  // if( firstsegment > 0 ){
  //   TString codafilename;
  //   codafilename.Form( "%s_%d.evio.%d.%d", fname_prefix, runnum, stream, 0 );
    
  //   TString ftest(fname_prefix);

  //   if( ftest == "bbgem" || ftest == "e1209019_trigtest" ){
  //     codafilename.Form("%s_%d.evio.%d", fname_prefix, runnum, 0 );
  //   }

  //   new( (THaRun*) (*filelist)[segcounter] ) THaRun( pathlist, codafilename.Data(), "GMN run" );

  //   ( (THaRun*) (*filelist)[segcounter] )->SetDataRequired(THaRunBase::kDate|THaRunBase::kRunNumber);
  //   //( (THaRun*) (*filelist)[segcounter] )->Init();
  //   //Not sure if we need to call Init()
  //   ( (THaRun*) (*filelist)[segcounter] )->Init();
  //   RunDate = ( (THaRun*) (*filelist)[segcounter] )->GetDate();

  //   segcounter++;
  //   max1++;
  // }
  
  //This loop adds all file segments found to the list of THaRuns to process:
  while( segcounter < max1 && segment - firstsegment < maxsegments ){
    
    TString codafilename;
    //codafilename.Form( "%s/bbgem_%d.evio.%d", prefix.Data(), runnum, segment );
    codafilename.Form("%s_%d.evio.%d.%d", fname_prefix, runnum, stream, segment );

    TString ftest(fname_prefix);
    if( ftest == "bbgem" || ftest == "e1209019_trigtest" ){
      codafilename.Form("%s_%d.evio.%d", fname_prefix, runnum, segment );
    }

    segmentexists = false;

    cout << "codafilename = " << codafilename << endl;

    for( int ipath=0; ipath<pathlist.size(); ipath++ ){
      TString searchname;
      searchname.Form( "%s/%s", pathlist[ipath].Data(), codafilename.Data() );
      
      if( !gSystem->AccessPathName( searchname.Data() ) ){
	segmentexists = true;
	break;
      }
    }
   
    if( segmentexists ){
      new( (*filelist)[segcounter] ) THaRun( pathlist, codafilename.Data(), "GMN run" );
      cout << "Added segment " << segment << ", CODA file name = " << codafilename << endl;

      //( (THaRun*) (*filelist)[segcounter] )->SetDate( now );

      // if( stream == 0 && segment == 0 ){
      // 	( (THaRun*) (*filelist)[segcounter] )->SetDataRequired(THaRunBase::kDate|THaRunBase::kRunNumber);
      // 	( (THaRun*) (*filelist)[segcounter] )->Init();

      // 	RunDate = ( (THaRun*) (*filelist)[segcounter] )->GetDate();
      // }  else {
      // 	( (THaRun*) (*filelist)[segcounter] )->SetDataRequired(0);

      // 	cout << "Warning: setting date to " << RunDate.AsString() << " for stream " << stream << " segment " << segment 
      // 	     << endl; 

      // 	( (THaRun*) (*filelist)[segcounter] )->SetDate(RunDate);
      // 	( (THaRun*) (*filelist)[segcounter] )->SetNumber(UInt_t(runnum));
      // }
      //( (THaRun*) (*filelist)[segcounter] )->SetNumber( runnum );
      //( (THaRun*) (*filelist)[segcounter] )->Init();
    } // else {
    //   THaRun *rtemp = ( (THaRun*) (*filelist)[segcounter-1] ); //make otherwise identical copy of previous run in all respects except coda file name:
    //   new( (*filelist)[segcounter] ) THaRun( *rtemp );
    //   ( (THaRun*) (*filelist)[segcounter] )->SetFilename( codafilename.Data() );
    //   ( (THaRun*) (*filelist)[segcounter] )->SetNumber( runnum );
    //   cout << "Added segment " << segcounter << ", CODA file name = " << codafilename << endl;
    // }
    if( segmentexists ){
      segcounter++;
      lastsegment = segment;
    }
    segment++;
  }

  cout << "n segments to analyze = " << segcounter << endl;

  prefix = gSystem->Getenv("OUT_DIR");

  TString outfilename, outfilebase;

  if( nevents > 0 ){ 

    outfilebase.Form( "%s_replayed_%d_stream%d_seg%d_%d_firstevent%d_nevent%d", fname_prefix, runnum,
		      stream, firstsegment, lastsegment, firstevent, nevents );
    outfilename.Form( "%s/%s.root", prefix.Data(), outfilebase.Data());
  } else {
    outfilebase.Form( "%s_fullreplay_%d_stream%d_seg%d_%d", fname_prefix, runnum,
		      stream, firstsegment, lastsegment );
    outfilename.Form( "%s/%s.root", prefix.Data(), outfilebase.Data());
  }
 

  analyzer->SetVerbosity(2);
  analyzer->SetMarkInterval(100);

  analyzer->EnableBenchmarks();
  
  // Define the analysis parameters
  analyzer->SetEvent( event );
  analyzer->SetOutFile( outfilename.Data() );
  // File to record cuts accounting information
  
  prefix = gSystem->Getenv("LOG_DIR");
  // analyzer->SetSummaryFile(Form("%s/replay_gmn_%d_stream%d_seg%d_%d.log", prefix.Data(), runnum, 
  // 				stream, firstsegment, lastsegment));
  analyzer->SetSummaryFile(Form("%s/%s.log", prefix.Data(), outfilebase.Data()));

  prefix = gSystem->Getenv("SBS_REPLAY");
  
  prefix += "/replay/";
  //cout << "Hello World, if you get to this point you are reading the right script!" << endl;
  int myrun = (int) runnum;	
  TString odef_filename;
  TString ftest(fname_prefix);
  //These run number segments are determined by reviewing the run log and should be correct, but are arbitrary
  //modified odef_filename to handle the 3 different GEM configurations throughout the run. Doing this by runnum. ~E. Wertz
  if((myrun >= 10491) && (myrun <= 12703) && (ftest == "e1209019")){
    //GEM config 1: 2 UV layers, 2 INFN layers, 1 UVA XY
    odef_filename = "replay_gmn_1.odef";
  }
  else if((myrun >= 12078) && (myrun <= 13086) && (ftest == "e1209019")){
    //GEM config 2: 3 UV layers, 1 INFN layer, 1 UVA XY
    odef_filename = "replay_gmn_2.odef";
  }
  else if(((myrun >= 13095) && (myrun <= 13799) && (ftest == "e1209019")) || (ftest == "e1209016")){
    //GEM config 3: 4 UV layers, 1 UVA XY
    odef_filename = "replay_gmn_3.odef";
  }
  else{
    //Fail safe if for some reason a runnum is inputed that does not fall in these ranges. Replay will probably be wrong. But it shouldn't crash the scrip. Will give you most modules.
    odef_filename = "replay_gmn_1.odef";	
  }


  odef_filename.Prepend(prefix);
  //odef_filename.Prepend("/work/halla/sbs/ewertz/SBS-replay/replay/");

  analyzer->SetOdefFile( odef_filename );
  
  //added cut list in order to have 
  TString cdef_filename = "replay_gmn_farm.cdef";

  //cdef_filename = "replay_gmn.cdef";
  
  cdef_filename.Prepend( prefix );
  
  analyzer->SetCutFile( cdef_filename );
  //analyzer->SetCompressionLevel(0); // turn off compression

  filelist->Compress();

  for( int iseg=0; iseg<filelist->GetEntries(); iseg++ ){
    THaRun *run = ( (THaRun*) (*filelist)[iseg] );
    if( nevents > 0 ) run->SetLastEvent(firstevent+nevents-1); //not sure if this will work as we want it to for multiple file segments chained together

    run->SetFirstEvent( firstevent );
    
    run->SetDataRequired(THaRunBase::kDate|THaRunBase::kRunNumber);

    run->Init();
    
    if( run->GetSegment() >= firstsegment && run->GetSegment() - firstsegment < maxsegments ){
      //std::cout 
      analyzer->Process(run);     // start the actual analysis
    }
  }
  
  /*
  //old stuff
  //EPAF: copied the following from replay_BBGEM.C, as this script seems to be thought to handle splits properly.
  int segcounter=0;

  if( maxsegments <= 0 ) maxsegments = 1000000; 

  //This loop adds all file segments found to the list of THaRuns to process:
  while( segcounter < maxsegments && segment - firstsegment < maxsegments ){

  TString codafilename;
  //codafilename.Form( "%s/bbgem_%d.evio.%d", prefix.Data(), runnum, segment );
  codafilename.Form("%s/%s_%d.evio.0.%d", prefix.Data(), fname_prefix, runnum, segment );

  segmentexists = true;
    
  if( gSystem->AccessPathName( codafilename.Data() ) ){
  segmentexists = false;
  } else if( segcounter == 0 ){
  new( (*filelist)[segcounter] ) THaRun( codafilename.Data() );
  cout << "Added segment " << segcounter << ", CODA file name = " << codafilename << endl;
  //( (THaRun*) (*filelist)[segcounter] )->SetDate( now );
  ( (THaRun*) (*filelist)[segcounter] )->SetDataRequired(1);
  ( (THaRun*) (*filelist)[segcounter] )->SetNumber( runnum );
  ( (THaRun*) (*filelist)[segcounter] )->Init();
  } else {
  THaRun *rtemp = ( (THaRun*) (*filelist)[segcounter-1] ); //make otherwise identical copy of previous run in all respects except coda file name:
  new( (*filelist)[segcounter] ) THaRun( *rtemp );
  ( (THaRun*) (*filelist)[segcounter] )->SetFilename( codafilename.Data() );
  ( (THaRun*) (*filelist)[segcounter] )->SetNumber( runnum );
  cout << "Added segment " << segcounter << ", CODA file name = " << codafilename << endl;
  }
  if( segmentexists ){
  segcounter++;
  lastsegment = segment;
  }
  segment++;
  }

  cout << "n segments to analyze = " << segcounter << endl;

  prefix = gSystem->Getenv("OUT_DIR");

  TString outfilename;
  //outfilename.Form( "%s/gmn_replayed_%d_seg%d_%d.root", prefix.Data(), runnum,
  //		    firstsegment, lastsegment );

  outfilename.Form("%s/gmn_replayed_%d_nev%d.root", prefix.Data(), runnum, nevents );

  // Define the run(s) that we want to analyze.
  // We just set up one, but this could be many.
  //  THaRun* run = new THaRun( "prod12_4100V_TrigRate25_4.dat" );
  //THaRun* run = new THaRun( "5GEM_sample.dat" );
  //THaRun* run = new THaRun( "/Users/puckett/WORK/GEM_ALIGNMENT/RAWDATA/gem_cleanroom_2811.evio.31" );
  //THaRun* run = new THaRun( codafilename.Data() );
  //THaRun* run = new THaRun( "/Users/puckett/WORK/GEM_ALIGNMENT/RAWDATA/gem_cleanroom_2805.evio.0" );

  

  analyzer->SetVerbosity(2);
  analyzer->SetMarkInterval(100);

  analyzer->EnableBenchmarks();
  
  // Define the analysis parameters
  analyzer->SetEvent( event );
  analyzer->SetOutFile( outfilename.Data() );
  // File to record cuts accounting information
  analyzer->SetSummaryFile("replay_gmn.log"); // optional

  prefix = gSystem->Getenv("SBS_REPLAY");
  prefix += "/replay/";

  TString odef_filename = "replay_gmn.odef";
  
  odef_filename.Prepend( prefix );

  analyzer->SetOdefFile( odef_filename );
  
  //analyzer->SetCompressionLevel(0); // turn off compression

  filelist->Compress();

  for( int iseg=0; iseg<filelist->GetEntries(); iseg++ ){
  THaRun *run = ( (THaRun*) (*filelist)[iseg] );
  if( nevents > 0 ) run->SetLastEvent(nevents); //not sure if this will work as we want it to for multiple file segments chained together

  run->SetFirstEvent( firstevent );
    
  run->SetDataRequired(1);
    

  analyzer->Process(run);     // start the actual analysis
  }
  
  */
}


// int main(int argc, char *argv[])
// {
//   //does this int main actually get called when we run our script?
//   new THaInterface( "The Hall A analyzer", &argc, argv, 0, 0, 1 );
//   uint runnum = 220;
//   uint firstsegment = 0;
//   uint maxsegments = 0;
//   string name_prefix = "e1209019";
//   long firstevent=0;
//   long nevents=-1; 
//   int pedestalmode=0;
//   uint nev = -1;
//   if(argc<2 || argc>8){
//     cout << "Usage: replay_gmn runnum(uint) nevents(ulong) firstevent(ulong)" 
// 	 << endl 
// 	 << "                  name_prefix(string) firstsegment(uint) maxsegments(uint) "
// 	 << endl 
// 	 << "                  pedestalmode(int)"
// 	 << endl;
//     return -1;
//   }
//   if(argc>=2) runnum = atoi(argv[1]);
//   if(argc>=3) firstsegment = atoi(argv[2]);
//   if(argc>=4) maxsegments = atoi(argv[3]);
//   if(argc>=5) name_prefix = argv[4];
//   if(argc>=6) firstevent = atoi(argv[5]);
//   if(argc>=7) nevents = atoi(argv[6]);
//   if(argc>=8) pedestalmode = atoi(argv[7]);

//   replay_gmn(runnum, nevents, firstevent, 
// 	     name_prefix.c_str(), firstsegment, maxsegments, 
// 	     pedestalmode);
//   return 0;
// }
