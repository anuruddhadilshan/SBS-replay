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

#include "SBSEArm.h"
#include "SBSGEPEArm.h"
#include "SBSCDet.h"
#include "SBSHCal.h"
#include "SBSECal.h"
#include "SBSGEMSpectrometerTracker.h"
#include "SBSGEMPolarimeterTracker.h"
#include "SBSGEMTrackerBase.h"
#include "SBSGEPRegionOfInterestModule.h"
#include "SBSRasteredBeam.h"
#include "LHRSScalerEvtHandler.h"
#include "SBSScalerEvtHandler.h"
#include "SBSScalerHelicity.h"
#include "SBSGEPHeepCoinModule.h"
#include "SBSVTP.h"

using namespace std;

void replay_gep(UInt_t runnum, Long_t nevents=-1, Long_t firstevent=1, const char *fname_prefix="gep5", UInt_t firstsegment=0, UInt_t maxsegments=1, 
		Int_t maxstream=2, Int_t pedestalmode=0, Int_t cmplots=0, Int_t firststream=0, Int_t dogems=1, Int_t requiretrack=0, Int_t nontrackingmode=0)
{
    THaAnalyzer* analyzer = new THaAnalyzer;
    
    // Initialize Electron Arm.
    SBSGEPEArm* earm = new SBSGEPEArm("earm", "GEP electron arm");
    // // ECal
    SBSECal* ecal =  new SBSECal("ecal", "ECal");
    ecal->SetDataOutputLevel(2);
    ecal->SetStoreRawHits(kTRUE); // Enabling writing out waveform information.
    ecal->SetEnableMultiPulse(kTRUE); //Enabling finding all pulses above thres
    earm->AddDetector( ecal );
    // // ECal VTP
    SBSVTP* ecalvtp = new SBSVTP("ecal.vtp", "ECal VTP");
    earm->AddDetector( ecalvtp );
    // // CDet
    SBSCDet* cdet =  new SBSCDet("cdet", "coordinate detector");
    cdet->SetStoreRawHits(kTRUE);
    earm->AddDetector( cdet );

    gHaApps->Add(earm);


    // Initialize Hadron Arm.
    SBSEArm* harm = new SBSEArm("sbs", "GEP hadron arm");
    // // HCal
    SBSHCal* hcal = new SBSHCal("hcal", "HCAL");
    //Commenting these for production replays
    hcal->SetStoreRawHits(kFALSE);
    hcal->SetStoreEmptyElements(kFALSE);
    hcal->SetEnableMultiPulse(kTRUE); //Enabling finding all pulses above thres
    harm->AddDetector( hcal );
    // VTP
    SBSVTP* hcalvtp = new SBSVTP("hcal.vtp", "HCal VTP");
      harm->AddDetector( hcalvtp );
    // // HCal trigs
    SBSGenericDetector* sbstrig = new SBSGenericDetector("trig","HCal trigs");
    sbstrig->SetModeADC(SBSModeADC::kWaveform);
    sbstrig->SetStoreRawHits(kTRUE);
    sbstrig->SetStoreEmptyElements(kFALSE);
    harm->AddDetector( sbstrig );
    // // FT GEMs
    SBSGEMSpectrometerTracker* gemFT = new SBSGEMSpectrometerTracker("gemFT", "Front tracker");
    bool pm = ( pedestalmode != 0 );
    gemFT->SetPedestalMode( pm );
    gemFT->SetMakeCommonModePlots( cmplots );
    gemFT->SetNonTrackingMode( nontrackingmode );
    if( dogems != 0 )harm->AddDetector( gemFT );
    // // FPP GEMs
    SBSGEMPolarimeterTracker* gemFPP = new SBSGEMPolarimeterTracker("gemFPP", "Focal plane polarimeter");
    gemFPP->SetPedestalMode( pm );
    gemFPP->SetMakeCommonModePlots( cmplots );
    gemFPP->SetNonTrackingMode( nontrackingmode );
    if ( dogems != 0 )harm->AddDetector( gemFPP );
    
    gHaApps->Add(harm);


    // Region of interest module for FT and ECal communication.
    SBSGEPRegionOfInterestModule* ROI = new SBSGEPRegionOfInterestModule("FTROI", "GEP region of interest calculation", THaAnalyzer::kCoarseRecon);

    if( dogems != 0 ) analyzer->AddInterStage( ROI );

    //It seems necessary to add the SBS "golden track" for certain physics modules.
    gHaPhysics->Add( new THaGoldenTrack( "SBS.gold", "SBS golden track", "sbs" ) );
    // Add the "H(e,e'p) coincidence module"
    if( dogems != 0 ) gHaPhysics->Add( new SBSGEPHeepCoinModule( "heep", "H(e,e'p) GEP-style", "earm","sbs" ) );
    
    // add decoder
    THaApparatus* decL = new THaDecData("DL", "Misc. Decoder Data");
    gHaApps->Add( decL );

    // add *rastered* beam
    THaApparatus* Lrb = new SBSRasteredBeam("Lrb", "Raster Beamline for FADC");
    gHaApps->Add( Lrb );

    Lrb->AddDetector( new SBSScalerHelicity("scalhel", "Scaler Helicity info") );

    THaApparatus* sbs = new SBSRasteredBeam("SBSrb", "Raster Beamline for FADC");
    gHaApps->Add(sbs);

    LHRSScalerEvtHandler* lScaler = new LHRSScalerEvtHandler("Left", "HA scaler event type 140");;
    gHaEvtHandlers->Add(lScaler);

    SBSScalerEvtHandler* sbsScaler = new SBSScalerEvtHandler("sbsgep","SBS Scaler Bank event type 1" );
    sbsScaler->SetUseFirstEvent(kTRUE);
    gHaEvtHandlers->Add(sbsScaler);


    // Add evio files.
    TString prefix = gSystem->Getenv("DATA_DIR");
    
    vector<string> pathlist;
    if ( !prefix.IsNull() ) pathlist.push_back( prefix.Data() );
    if ( prefix != "/adaqeb1/data1" ) pathlist.push_back( "/adaqeb1/data1" );
    if ( prefix != "/adaqeb2/data1" ) pathlist.push_back( "/adaqeb2/data1" );
    if ( prefix != "/adaqeb3/data1" ) pathlist.push_back( "/adaqeb3/data1" );
    if ( prefix != "/cache/halla/sbs/GEp/raw" ) pathlist.push_back( "/cache/halla/sbs/GEp/raw" );
    if ( prefix != "/cache/mss/halla/sbs/GEp/raw" ) pathlist.push_back( "/cache/mss/halla/sbs/GEp/raw" );

    for ( const auto& path : pathlist ) cout << "search paths = " << path << endl;

    vector<string> filenames;

    maxstream = std::max(0,std::min(2,maxstream));
    
    firststream = std::max(0,std::min(maxstream,firststream));
    
    for ( Int_t istream = firststream; istream <= maxstream; ++istream )
    {
        for( UInt_t iseg = firstsegment; iseg < firstsegment + maxsegments; ++iseg )
        {
            TString codafilename;
            codafilename.Form("%s_%u.evio.%u.%u", fname_prefix, runnum, istream, iseg);
            cout << "codafilename = " << codafilename << endl;
            filenames.emplace_back(codafilename.Data());
        }
    }

    if ( filenames.empty() ) 
    {
        cerr << "No files. Check your parameters." << endl;
        return;
    }

    auto* run = new Podd::MultiFileRun(pathlist, filenames);
    run->SetFirstSegment(firstsegment); // Starting segment number.
    run->SetMaxSegments(maxsegments);   // Number of segments.
    run->SetMaxStreams(maxstream+1);    // Number of streams.

    analyzer->SetCountMode(THaAnalyzer::kCountPhysics);

    if ( nevents > 0 ) run->SetLastEvent(firstevent+nevents-1);
    run->SetFirstEvent(firstevent);
    run->SetDataRequired(THaRunBase::kDate|THaRunBase::kRunNumber);
    Int_t st = run->Init();

    if ( st != THaRunBase::READ_OK )
      {
        cerr << "========= Eroor initializing run" << endl;
        return;
      }
    
    cout << "n segments to analyze = " << run->GetNFiles() << endl;
    
    prefix = gSystem->Getenv("OUT_DIR");
    
    TString outfilename;
    UInt_t lastsegment = run->GetLastSegment();
    
    if ( nevents > 0 ){
      
      if ( dogems != 0 )
	{
	  outfilename.Form("%s/%s_replayed_%u_stream%d_%d_seg%u_%u_firstevent%ld_nevent%ld.root", prefix.Data(), fname_prefix, runnum, 
			   firststream, maxstream, firstsegment, lastsegment, firstevent, nevents);
	}
      else
	{
	  outfilename.Form("%s/%s_replayed_nogems_%u_stream%d_%d_seg%u_%u_firstevent%ld_nevent%ld.root", prefix.Data(), fname_prefix, runnum, 
			   firststream, maxstream, firstsegment, lastsegment, firstevent, nevents);
	}
      
    } else {
      if ( dogems != 0 )
	{
	  outfilename.Form("%s/%s_fullreplay_%u_stream%d_%d_seg%u_%u.root", prefix.Data(), fname_prefix, runnum,
			   firststream, maxstream, firstsegment, lastsegment);
	}
      else
	{
	  outfilename.Form("%s/%s_fullreplay_nogems_%u_stream%d_%d_seg%u_%u.root", prefix.Data(), fname_prefix, runnum,
			   firststream, maxstream, firstsegment, lastsegment);
	}        
    }
    
    

    analyzer->EnableHelicity();

    analyzer->SetVerbosity(2);
    analyzer->SetMarkInterval(100);

    analyzer->EnableBenchmarks();

    analyzer->SetOutFile( outfilename.Data() );

    prefix = gSystem->Getenv("LOG_DIR");
    analyzer->SetSummaryFile(Form("%s/%s_%d_stream%d_%d_seg%d_%d.log", prefix.Data(), fname_prefix, runnum,
	    firststream, maxstream, firstsegment, lastsegment));

    prefix = gSystem->Getenv("SBS_REPLAY");
    prefix += "/replay/";

    TString odef_filename = "replay_gep.odef"; // TO BE MADE!

    if( requiretrack > 0 ){
      odef_filename = "replay_gep_light.odef";
    }

    odef_filename.Prepend( prefix );

    analyzer->SetOdefFile( odef_filename );

    TString cdef_filename = "replay_gep.cdef"; // TO BE MADE!

    if( requiretrack > 0 ) cdef_filename = "replay_gep_farm.cdef";
    
    cdef_filename.Prepend( prefix );

    analyzer->SetCutFile( cdef_filename );

    st = analyzer->Init(run);
    if ( st != 0 )
    {
        cerr << "========= Error initializing analyzer" << endl;
        return;
    }

    analyzer->Process(run); // Start the actual analysis.

    // Clean up.
    analyzer->Close();
    delete analyzer;
    //gHaCuts->Clear();
    gHaVars->Clear();
    gHaPhysics->Delete();
    gHaApps->Delete();

}
