// Replay script for SBS-GEn
// October 2022
//
// Requires Podd 1.7.4

//#if !defined(__CLING__) || defined(__ROOTCLING__)
//R__LOAD_LIBRARY($SBSOFFLINE/lib64/libsbs.so);
#include <iostream>

#include "TSystem.h"
#include "THaGlobals.h"
#include "TString.h"
#include "TFile.h"
#include "TList.h"
#include "TObject.h"
#include "TClonesArray.h"

#include "THaEvData.h"
#include "MultiFileRun.h"
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
//#include "SBSGEMStand.h"
#include "SBSTimingHodoscope.h"
#include "SBSGEMSpectrometerTracker.h"
#include "SBSGEMPolarimeterTracker.h"
#include "SBSGEMTrackerBase.h"
#include "SBSRasteredBeam.h"
#include "LHRSScalerEvtHandler.h"
#include "SBSScalerEvtHandler.h"
#include "SBSScalerHelicity.h"
//#endif


using namespace std;

void replay_genrp_StraightThrough(UInt_t runnum=10491, Long_t nevents=-1, Long_t firstevent=1, const char *fname_prefix="e1217004", UInt_t firstsegment=0, UInt_t maxsegments=1, Int_t maxstream=2, Int_t pedestalmode=0, Int_t cmplots=0, Int_t usesbsgems=1)
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
  tdctrig->SetModeTDC(SBSModeTDC::kTDC);
  tdctrig->SetStoreEmptyElements(kFALSE);
  bigbite->AddDetector( tdctrig );

  //SBSGenericDetector *grinch_tdc = new SBSGenericDetector("grinch_tdc","GRINCH TDC data");
  //SBSCherenkovDetector *grinch_tdc = new SBSCherenkovDetector("grinch_tdc","GRINCH TDC data");
  SBSGRINCH *grinch_tdc = new SBSGRINCH("grinch_tdc","GRINCH TDC data");
  //SBSGenericDetector *grinch_adc = new SBSGenericDetector("grinch_adc","GRINCH ADC data");
  //grinch_adc->SetModeADC(SBSModeADC::kWaveform);
  //grinch_adc->SetModeTDC(SBSModeTDC::kNone);
  //grinch_adc->SetStoreEmptyElements(kFALSE);
  //grinch_adc->SetStoreRawHits(kFALSE);

  grinch_tdc->SetModeTDC(SBSModeTDC::kTDC);
  //grinch_tdc->SetModeTDC(SBSModeTDC::kCommonStartTDC);
  grinch_tdc->SetModeADC(SBSModeADC::kNone);
  grinch_tdc->SetStoreEmptyElements(kFALSE);
  grinch_tdc->SetStoreRawHits(kFALSE);
  grinch_tdc->SetDisableRefTDC(true);
  //bigbite->AddDetector(grinch_adc);
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
  bbgem->SetPedestalMode( pm );
  bbgem->SetMakeCommonModePlots( cmplots );
  bigbite->AddDetector(bbgem);
  gHaApps->Add(bigbite);

  SBSEArm *harm = new SBSEArm("sbs","Hadron Arm with HCal");
  SBSHCal* hcal =  new SBSHCal("hcal","HCAL");
  //hcal->SetStoreRawHits(kTRUE);
  hcal->SetStoreEmptyElements(kFALSE);
  harm->AddDetector(hcal);

  SBSGenericDetector* activeAna_adc =  new SBSGenericDetector("activeAna_adc","HAll A gen rp active analyzer");
  //SBSCalorimeter* activeAna_adc =  new SBSCalorimeter("activeAna_adc","HAll A gen rp active analyzer")
  activeAna_adc->SetDisableRefADC(kTRUE);//haven't implemented reference time yet
  activeAna_adc->SetModeADC(SBSModeADC::kWaveform);
  activeAna_adc->SetModeTDC(SBSModeTDC::kNone);
  activeAna_adc->SetStoreRawHits(kTRUE);
  activeAna_adc->SetStoreEmptyElements(kFALSE);
  harm->AddDetector(activeAna_adc);

  SBSGenericDetector* hodoPR_adc =  new SBSGenericDetector("hodoPR_adc","HAll A gen rp side hodoscope");
  //SBSCalorimeter* hodoPR_adc =  new SBSCalorimeter("hodoPR_adc","HAll A gen rp side hodoscope");
  hodoPR_adc->SetDisableRefADC(kTRUE);//haven't implemented reference time yet
  hodoPR_adc->SetModeADC(SBSModeADC::kWaveform);
  hodoPR_adc->SetModeTDC(SBSModeTDC::kNone);
  hodoPR_adc->SetStoreRawHits(kTRUE);
  hodoPR_adc->SetStoreEmptyElements(kFALSE);
  harm->AddDetector(hodoPR_adc);

  SBSGenericDetector* activeAna_tdc =  new SBSGenericDetector("activeAna_tdc","HAll A gen rp active analyzer");
  //SBSCalorimeter* activeAna_tdc =  new SBSCalorimeter("activeAna_tdc","HAll A gen rp active analyzer");
  activeAna_tdc->SetModeTDC(SBSModeTDC::kTDC);
  //activeAna_tdc->SetModeTDC(SBSModeTDC::kCommonStartTDC);
  activeAna_tdc->SetModeADC(SBSModeADC::kNone);
  activeAna_tdc->SetDisableRefTDC(true);
  activeAna_tdc->SetStoreRawHits(kTRUE);
  activeAna_tdc->SetStoreEmptyElements(kFALSE);
  //harm->AddDetector(activeAna_tdc);

  SBSGenericDetector* hodoPR_tdc =  new SBSGenericDetector("hodoPR_tdc","HAll A gen rp side hodoscope");
  //SBSCalorimeter* hodoPR_tdc =  new SBSCalorimeter("hodoPR_tdc","HAll A gen rp side hodoscope");
  hodoPR_tdc->SetModeTDC(SBSModeTDC::kTDC);
  //hodoPR_tdc->SetModeTDC(SBSModeTDC::kCommonStartTDC);
  hodoPR_tdc->SetModeADC(SBSModeADC::kNone);
  hodoPR_tdc->SetDisableRefTDC(true);
  hodoPR_tdc->SetStoreRawHits(kTRUE);
  hodoPR_tdc->SetStoreEmptyElements(kFALSE);
  harm->AddDetector(hodoPR_tdc);


  SBSGenericDetector* sbstrig = new SBSGenericDetector("trig","HCal trigs");
  sbstrig->SetModeADC(SBSModeADC::kWaveform);
  //sbstrig->SetStoreRawHits(kTRUE);
  sbstrig->SetStoreEmptyElements(kFALSE);
  harm->AddDetector( sbstrig );


  SBSGEMSpectrometerTracker *sbs_gem = new SBSGEMSpectrometerTracker("gem", "All SBS GEN-RP GEMs combined");
  sbs_gem->SetPedestalMode( pm );
  sbs_gem->SetMakeCommonModePlots( cmplots );
  if( usesbsgems != 0 ) {
    harm->AddDetector( sbs_gem );
    if( usesbsgems < 0 ){
      sbs_gem->SetNonTrackingMode( 1 );
    }
  }
  harm->SetPolarimeterMode( false );

  SBSGenericDetector *tdctrig_sbs = new SBSGenericDetector("tdctrig", "SBS trigger TDCs");
  tdctrig_sbs->SetModeADC(SBSModeADC::kNone);
  //  tdctrig_sbs->SetModeTDC(SBSModeTDC::kTDC);
  tdctrig_sbs->SetModeTDC(SBSModeTDC::kTDCSimple);
  tdctrig_sbs->SetStoreEmptyElements(kFALSE);
  harm->AddDetector( tdctrig_sbs );
  
  // SBSGEMSpectrometerTracker *gemCeF = new SBSGEMSpectrometerTracker("gemCeF", "Super BigBite Hall A inline front GEM data");
  // gemCeF->SetPedestalMode( pm );
  // gemCeF->SetMakeCommonModePlots( cmplots );
  // if (usesbsgems != 0 ) harm->AddDetector(gemCeF);
  
  // SBSGEMPolarimeterTracker *gemCeR = new SBSGEMPolarimeterTracker("gemCeR", "Super BigBite Hall A inline rear GEM data");
  // gemCeR->SetPedestalMode( pm );
  // gemCeR->SetMakeCommonModePlots( cmplots );
  // if (usesbsgems != 0 ) harm->AddDetector(gemCeR);

  //SBSGEMSpectrometerTracker *gemPR = new SBSGEMSpectrometerTracker("gemPR", "Super BigBite Hall A side GEM data for genrp");
  //gemPR->SetPedestalMode( pm );
  //gemPR->SetMakeCommonModePlots( cmplots );
  //if (usesbsgems != 0 ) harm->AddDetector(gemPR);

  gHaApps->Add(harm);
  //bigbite->SetDebug(2);
  //harm->SetDebug(2);

  // add decoder
  THaApparatus* decL = new THaDecData("DL","Misc. Decoder Data");
  gHaApps->Add( decL );

  // add *rastered* beam
  THaApparatus* Lrb = new SBSRasteredBeam("Lrb","Raster Beamline for FADC");
  gHaApps->Add(Lrb);

  Lrb->AddDetector( new SBSScalerHelicity("scalhel","Scaler Helicity info"));

  THaApparatus* sbs = new SBSRasteredBeam("SBSrb","Raster Beamline for FADC");
  gHaApps->Add(sbs);



  gHaPhysics->Add( new THaGoldenTrack( "BB.gold", "BigBite golden track", "bb" ));
  gHaPhysics->Add( new THaPrimaryKine( "e.kine", "electron kinematics", "bb", 0.0, 0.938272 ));

  //gHaEvtHandlers->Add (new THaScalerEvtHandler("Left","HA scaler event type 140"));
  //gHaEvtHandlers->Add (new THaScalerEvtHandler("SBS","HA scaler event type 141"));


  LHRSScalerEvtHandler *lScaler = new LHRSScalerEvtHandler("Left","HA scaler event type 140");
  // lScaler->SetDebugFile(&debugFile);
  gHaEvtHandlers->Add(lScaler);

  SBSScalerEvtHandler *sbsScaler = new SBSScalerEvtHandler("sbs","SBS Scaler Bank event type 1");
  //sbsScaler->AddEvtType(1);             // Repeat for each event type with scaler banks
  sbsScaler->SetUseFirstEvent(kTRUE);
  gHaEvtHandlers->Add(sbsScaler);

  //THaInterface::SetDecoder( SBSSimDecoder::Class() );

  TString prefix = gSystem->Getenv("DATA_DIR");

  vector<string> pathlist;
  if( !prefix.IsNull() )
    pathlist.push_back( prefix.Data() );

  if( prefix != "/adaqeb[1-3]/data1" )
    pathlist.push_back( "/adaqeb[1-3]/data1" );

  if( prefix != "/adaq1/data1/sbs" )
    pathlist.push_back( "/adaq1/data1/sbs" );

  // Do not use wildcard filenames with this directory
  if( prefix != "/cache/halla/sbs/raw" )
    pathlist.push_back( "/cache/halla/sbs/raw" );

  if( prefix != "/cache/halla/sbs/GEnRP/raw" )
    pathlist.push_back( "/cache/halla/sbs/GEnRP/raw" );

  for( const auto& path: pathlist ) {
    cout << "search paths = " << path << endl;
  }

  TString ftest(fname_prefix);
  bool test_data = ( ftest == "bbgem" || ftest == "e1209019_trigtest" );

  // Build list of files we'd like to analyze. These are candidates. If some of them
  // do not exist, they will be quietly skipped by the MultiFileRun class. A list of
  // the actually found files will be printed during initialization.
  vector<string> filenames;
  Int_t actual_maxstream = test_data ? 0 : maxstream;
  for( Int_t istream = 0; istream <= actual_maxstream; ++istream ) {
    for( UInt_t iseg = firstsegment; iseg < firstsegment + maxsegments; ++iseg ) {
      TString codafilename;
      if( test_data )
	codafilename.Form("%s_%u.evio.%u", fname_prefix, runnum, istream);
      else
	codafilename.Form("%s_%u.evio.%d.%u", fname_prefix, runnum, istream, iseg);
      cout << "codafilename = " << codafilename << endl;
      filenames.emplace_back(codafilename.Data());
    }
  }
  if( filenames.empty() ) {
    cout << "No files. Check your parameters." << endl;
    return;
  }

  auto* run = new Podd::MultiFileRun(pathlist, filenames);
  run->SetFirstSegment(firstsegment);  // Starting segment number
  run->SetMaxSegments(maxsegments);    // Number of segments
  run->SetMaxStreams(maxstream+1);  // Number of streams

  // Count physics events sequentially, i.e. always starting at 1, for each invocation of
  // analyzer->Process(). This count will be compared to the run's event range, so it
  // can be specified independently of absolute event numbers. This is relevant if
  // the analysis starts with a segment > 0. Actual (raw, CODA) physics event numbers
  // will then start with some largish number (the first event number in the continuation
  // segment), but the analyzer's count will still start at 1 for that analysis,
  // so you can give the run an event range of, say, 1-50000 to analyze 50k events,
  // regardless of what segments are being replayed. The event header written for each
  // entry in the output ROOT tree does contain the actual CODA event number, which is
  // what you usually want for analysis.

  analyzer->SetCountMode(THaAnalyzer::kCountPhysics);

  if( nevents > 0 ) run->SetLastEvent(firstevent+nevents-1);
  run->SetFirstEvent( firstevent );
  run->SetDataRequired(THaRunBase::kDate|THaRunBase::kRunNumber);
  Int_t st = run->Init();
  if( st != THaRunBase::READ_OK ) {
    cerr << "========= Error initializing run" << endl;
    return;
  }

  cout << "n segments to analyze = " << run->GetNFiles() << endl;

  prefix = gSystem->Getenv("OUT_DIR");

  TString outfilename;
  UInt_t lastsegment = run->GetLastSegment();
  if( nevents > 0 ){
    outfilename.Form( "%s/%s_replayed_%u_stream%d_%d_seg%u_%u_firstevent%ld_nevent%ld.root", prefix.Data(), fname_prefix, runnum,
		      0, maxstream, firstsegment, lastsegment, firstevent, nevents );
  } else {
    outfilename.Form( "%s/%s_fullreplay_%u_stream%d_%d_seg%u_%u.root", prefix.Data(), fname_prefix, runnum,
		      0, maxstream, firstsegment, lastsegment );
  }


  analyzer->EnableHelicity();

  analyzer->SetVerbosity(2);
  analyzer->SetMarkInterval(100);

  analyzer->EnableBenchmarks();

  // Define the analysis parameters
  analyzer->SetOutFile( outfilename.Data() );

  // File to record cuts accounting information
  prefix = gSystem->Getenv("LOG_DIR");
  analyzer->SetSummaryFile(Form("%s/%s_%d_stream%d_%d_seg%d_%d.log", prefix.Data(), fname_prefix, runnum,
				0, maxstream, firstsegment, lastsegment));

  prefix = gSystem->Getenv("SBS_REPLAY");
  prefix += "/replay/";

  TString odef_filename = "replay_genrp_StraightThrough.odef";

  //no need to define SBS GEM output if we aren't analyzing the data
  if( usesbsgems == 0 ) odef_filename = "replay_genrp_noSBSGEMs.odef";

  odef_filename.Prepend( prefix );

  analyzer->SetOdefFile( odef_filename );

  //added cut list in order to have
  //on the farm we only write out events with a track in BigBite
  //TString cdef_filename = "replay_gen_farm.cdef";
  TString cdef_filename = "replay_genrp_full.cdef";

  //the above cdef file includes almost no significant cuts (basically just any hit in BigBite shower or preshower
  cdef_filename.Prepend( prefix );

  analyzer->SetCutFile( cdef_filename );
  //analyzer->SetCompressionLevel(0); // turn off compression

  st = analyzer->Init(run);
  if( st != 0 ) {
    cerr << "========= Error initializing analyzer" << endl;
    return;
  }
  analyzer->Process(run);     // start the actual analysis

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
