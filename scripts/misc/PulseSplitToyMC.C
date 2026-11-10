#include <vector>
#include "TF1.h"
#include "TRandom3.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TPaveText.h"
#include "TStyle.h"
#include "TLine.h"
#include "TFitResultPtr.h"
#include <algorithm>
#include <set>
#include <map>

using namespace std;

double PulseFunc(double *x, double *par ){
  double baseline = par[0];
  double ampl = par[1];
  double t0 = par[2];
  double tau = par[3];
  double t = x[0];
  
  return baseline + std::max(0.0,ampl*(t-t0)/tau * exp(1.0-(t-t0)/tau));
}

const int MAXNPULSE=5;

double MultiPulseFunc( double *x, double *par ){
  int npulse = int(par[0]);
  npulse = std::max(0,std::min(npulse,MAXNPULSE));

  double t = x[0];

  double baseline = par[1];
  double amplsum = 0.0;
  
  for( int i=0; i<npulse; i++ ){
    double ampl = par[2+3*i];
    double t0 = par[3+3*i];
    double tau = par[4+3*i];
    
    amplsum += std::max(0.0, ampl*(t-t0)/tau * exp(1.0-(t-t0)/tau));
  }
  
  return baseline + amplsum;
}

void GetEstimatedPulseParams( const vector<double> &Vsamps, double &t0, double &A, double &tau, double &ped, double tsamp=4.0, double thresh=0.005 ){

  //std::cout << "Threshold = " << thresh << std::endl;
  
  //Calculate all possible averages of four consecutive time samples and use the lowest one as the baseline estimation:

  double minped = 10000.0;
  
  for( int isamp=0; isamp<Vsamps.size()-4; isamp++ ){
    double pedsum = 0.0;
    for( int jsamp=isamp; jsamp<isamp+4; jsamp++ ){
      pedsum += Vsamps[jsamp]/4.;
    }

    minped = (isamp == 0 || pedsum < minped) ? pedsum : minped;
  }

  ped = minped;

  double ped_calc = ped;
  // double avgfirst = sumfirst4/4.;
  // double avglast = sumlast4/4.;

  // double ped_calc = std::min(avgfirst, avglast);

  // ped = ped_calc;
  
  //Search for threshold crossing (mimic standard FADC pulse-finding algo):

  int istart=4;

  bool threshcrossingfound=false;
  
  while( istart < Vsamps.size()-4 && Vsamps[istart]-ped_calc < thresh ){
    istart++;
  }

  //Default return values in case pulse-finding fails:
  // t0 = -1000.0;
  // A = 0.0;
  // tau = 100.0;
  
  if( istart < Vsamps.size()-4 ) threshcrossingfound = true;

  if( threshcrossingfound ){
    bool peakfound=false;

    int testbin=istart; 
    int peakbin = testbin;

    double Vmax = 0.0;
    
    while( !peakfound ){

      //Find the sample in which the 3-sample rolling average (ped-subtracted) peaks to reduce noise: 
      double Vavg = (Vsamps[testbin-1]+Vsamps[testbin]+Vsamps[testbin+1]-3.0*ped_calc)/3.0;

      //Note: for example, if testbin = 1, then
      // Vavg = (V0 + V1 + V2)/3 - ped
      // Vnext = (V1 + V2 + V3)/3 - ped
      // Vnext - Vavg = (V3-V0)/3 
      double Vnext = Vavg + (Vsamps[testbin+2]-Vsamps[testbin-1])/3.0;
      
      //      if( Vsamps[testbin+1] < Vsamps[testbin] ) {
      //if( Vavg > Vmax ){

      if( Vnext < Vavg ){
	peakfound=true;
	peakbin = testbin; 
	break;
      }
      testbin++;
      if( testbin == Vsamps.size()-4 ) break;
    }
    
    if( peakfound ){ //estimate time, Amplitude, etc
      A = Vsamps[peakbin] - ped_calc;

      double Aleft = Vsamps[peakbin-1] - ped_calc;
      double Aright = Vsamps[peakbin+1] - ped_calc;
      
      //      double tau_1 = tsamp/sqrt(1.0 - Aleft*Aright/(A*A)); //rough estimate (we'll have to see HOW rough)

      double Vmid = A/2.0;

      //      double t0default = tsamp*peakbin - tau_1;

      double tmid;
      bool goodtmid = false;
      //now estimate t0 using the standard FADC "fine time" algo (how exactly it relates to the true t0 we'll see)
      for( int i=istart-1; i<=peakbin; i++ ){
	if( Vsamps[i] - ped_calc < Vmid && Vsamps[i+1] - ped_calc >= Vmid ){
	  tmid = (i + (Vmid-(Vsamps[i]-ped_calc))/(Vsamps[i+1]-Vsamps[i]))*tsamp; //note: pedestal cancels in the denominator
	  goodtmid = true;
	}
      }

      // tavg = tleft*Aleft + tpeak * A + tright * Aright / (Aleft+A + Aright)
      // tleft = tpeak - tsamp
      // tright = tpeak + tsamp
      // tavg = (tpeak * Asum + (Aright-Aleft)*tsamp )/Asum = tpeak + (Aright-Aleft)*tsamp/Asum
      
      double tmax = tsamp * peakbin + (Aright-Aleft)*tsamp/(Aright+A+Aleft);
      
      //Another option:
      // tmid ~= t0 + 0.232*tau
      // tmax ~= t0 + tau
      // t0 = tmax - tau
      // tmid = tmax - tau + 0.232*tau = tmax - 0.768*tau
      // --> tau ~= (tmax-tmid)/0.768

      if( goodtmid ){
	tau = (tmax-tmid)/0.768;
	t0 = tmax-tau;
	//t0 = tmid - 0.232*tau_2; //estimated!
      } else {
	t0 = tsamp*(istart-0.5);
      }
    }
  } 
  
}

//Input deconvoluted samples, output deconvoluted pulses: 
void GetDeconvolutedPulses( const vector<double> &Vsamps, int &npulses, vector<double> &Apulse, vector<double> &t0pulse, double ped, double thresh, double Tsamp=4.0 ){

  //Input samples are ALREADY deconvoluted but not ped-subtracted. The pedestal will have already been calculated, and both the pedestal and the threshold will be provided externally:

  set<int> listofpeaks; 
  set<int> listofsamps; //sorted list of all above-threshold deconvoluted samples
  
  //Loop on all the deconvoluted samples and find all local maxima of the SUM of two deconvoluted ADC samples above threshold: 
  double Vleft = 0.0, Vright = 0.0;
  for( int isamp=0; isamp<Vsamps.size(); isamp++ ){
    Vleft = Vright = 0.0;
    if( isamp > 0 ){
      Vleft = Vsamps[isamp-1] - ped;
    }
    if( isamp+1<Vsamps.size() ){
      Vright = Vsamps[isamp+1] - ped;
    }

    double Vsamp = Vsamps[isamp]-ped;
    
    //double overthresh = (Vsamp >= thresh || (Vsamp+Vleft)>=sqrt(2.0*thresh) || (Vsamp+Vright)>=sqrt(2.0*thresh) );
    double overthresh = Vsamp >= thresh || std::max(Vsamp+Vleft,Vsamp+Vright) >= sqrt(2.0)*thresh;
    
    if( overthresh &&  Vsamp > Vleft && Vsamp > Vright ){
      //Also require the greater of the sum of two consecutive samples to be above sqrt(2)*thresh
      listofpeaks.insert(isamp);
    }

    //if( Vsamp >= thresh ){
    listofsamps.insert(isamp);
      //} 
  }

  // Next, calculate "peak prominence" for all peaks; if there is a local maximum in a consecutive grouping of above-threshold samples with
  // some higher peak to the left or right, then delete it if insufficiently prominent, as either a fraction of the nearby higher peak,
  // or as a multiple of the individual deconvoluted sample noise width:
  

  //vector<double> peakprominence(listofpeaks.size(),0.0);

  set<int> peakstoerase;
  
  for( auto ipeak : listofpeaks ){
    bool higherpeakleft=false;
    bool higherpeakright=false;

    double Vpeak = Vsamps[ipeak] - ped;

    double ValleyLeft = Vpeak;
    double ValleyRight = Vpeak;

    double Vpeakleft = 0.0, Vpeakright = 0.0;
    
    int testsamp=ipeak-1;
    while( listofsamps.find(testsamp) != listofsamps.end() ){
      double Vtest = Vsamps[testsamp]-ped;
      ValleyLeft = (Vtest < ValleyLeft) ? Vtest : ValleyLeft;

      if( listofpeaks.find(testsamp) != listofpeaks.end() && Vtest > Vpeak ){
	higherpeakleft = true;
	Vpeakleft = Vtest;
      }
      
      testsamp--; 
    }

    if( higherpeakleft ){ //if we found a higher peak to the left in a consecutive group of above-threshold samples, check this peak for significance:
      double prominence = Vpeak-ValleyLeft;
      if( prominence < thresh || prominence < 0.1 * Vpeakleft ) peakstoerase.insert(ipeak);
    }

    //now check to the right:
    testsamp = ipeak+1;
    while( listofsamps.find(testsamp) != listofsamps.end() ){
      double Vtest = Vsamps[testsamp]-ped;
      ValleyRight = (Vtest < ValleyRight) ? Vtest : ValleyRight;

      if( listofpeaks.find(testsamp) != listofpeaks.end() && Vtest > Vpeak ){
	higherpeakright = true;
	Vpeakright = Vtest;
      }
      testsamp++;
    }

    if( higherpeakright ){
      double prominence = Vpeak-ValleyRight;
      if( prominence < thresh || prominence < 0.1 * Vpeakright ) peakstoerase.insert(ipeak);
    }
  }

  for( auto ipeak : peakstoerase ){
    listofpeaks.erase(ipeak);
  }

  //npulses = listofpeaks.size();
 
  //Now loop on all the remaining peaks and calculate amplitude and time:

  //For amplitude, add the samples to the left and right (may increase noise)
  for( auto ipeak : listofpeaks ){
    double Asum = 0.0, tsum = 0.0;

    //Asum += Vsamps[ipeak]-ped;
    //tsum += (Vsamps[ipeak]-ped) * Tsamp * ipeak;

    double Vpeak = Vsamps[ipeak]-ped;    
    double Vleft = ipeak > 0 ? Vsamps[ipeak-1]-ped : 0.0;
    double Vright = ipeak+1<Vsamps.size() ? Vsamps[ipeak+1]-ped : 0.0;

    double Tpeak = Tsamp * ipeak, Tleft = Tsamp*(ipeak-1), Tright = Tsamp*(ipeak+1);
    
    Asum = std::max( Vpeak+Vleft, Vpeak+Vright );

    tsum = Vpeak+Vleft > Vpeak+Vright ? (Vpeak*Tpeak + Vleft*Tleft)/Asum : (Vpeak*Tpeak + Vright*Tright)/Asum;
   
    if( Asum >= thresh ){
      Apulse.push_back( Asum );
      t0pulse.push_back( tsum );
    }
  }

  npulses = Apulse.size();
  
}

void PulseSplitToyMC( int nsamp=62, double tsamp_ns=4.0, double t0avg_ns=95.0, double tau_avg_ns=20.0, double t0_sigma_ns=1.5, double tau_sigma_ns = 2.0, double sigma_samp=1.0, long NMAX=10000, double bgrate=5.e5, double thresh_nsigma=5.0, double thresh_nsigma_deconv=3.0 ){

  gStyle->SetOptFit();
  
  TRandom3 num(0);

  TF1 *PulseShapeFunc = new TF1("PulseShapeFunc", PulseFunc, -nsamp*tsamp_ns, tsamp_ns*(nsamp+2), 4 );

  PulseShapeFunc->SetParName(0,"BaseLine");
  PulseShapeFunc->SetParName(1,"Amplitude");
  PulseShapeFunc->SetParName(2,"Tstart");
  PulseShapeFunc->SetParName(3,"tau");

  PulseShapeFunc->SetNpx(1000);
  

  TF1 *MultiPulseFitFunc = new TF1("MultiPulseFitFunc", MultiPulseFunc, -nsamp*tsamp_ns, tsamp_ns*(nsamp+2), 3*MAXNPULSE+2 );

  MultiPulseFitFunc->SetNpx(1000);
  MultiPulseFitFunc->SetLineWidth(3);
  
  int nbits_ADC = 12; 

  double Vpp = 2.0; //Volts peak-to-peak;

  double pedmean_V = 0.1 * Vpp;

  double pedmean_raw = pow(2,nbits_ADC)*pedmean_V/Vpp; 

  //Let's take pulse amplitudes to be exponentially distributed starting at zero with a "decay rate" of 0.2*Vpp

  double xdeconv = tsamp_ns/tau_avg_ns;
  double deconv_weights[3] = { exp( xdeconv - 1.0 ) /xdeconv,
			       -2.0*exp(-1.0)/xdeconv,
			       exp(-1.0-xdeconv)/xdeconv };

  double sumsig2_deconv = 0.0;
  for( int i=0; i<3; i++ ){
    sumsig2_deconv += pow( deconv_weights[i] * sigma_samp * Vpp/pow(2,nbits_ADC), 2 );
  }
  double sigma_samp_deconv = sqrt(sumsig2_deconv);
  
  vector<double> dtsamp(nsamp,0.0);
  vector<double> tsamp(nsamp);
  vector<double> dFADCsamps_raw(nsamp,sigma_samp * Vpp/pow(2,nbits_ADC));
  for( int i=0; i<nsamp; i++ ){
    tsamp[i] = i*tsamp_ns;
  }
  
  long nevent=0;

  TCanvas *c1 = new TCanvas("c1","c1",1600,1200);

  TH2D *hframe = new TH2D("hframe","; time (ns); Voltage (V)",nsamp+1,-tsamp_ns/2.0,tsamp_ns*nsamp+tsamp_ns/2.0,200,0.0, Vpp);
  
  double thresh = thresh_nsigma * sigma_samp * Vpp / pow(2,nbits_ADC);

  double thresh_deconv = thresh_nsigma_deconv*sigma_samp_deconv;

  cout << "pulse finding threshold = " << thresh*1000.0 << " mV" << endl;
  cout << "deconvoluted pulse finding threshold = " << thresh_deconv*1000.0 << " mV" << endl;
  
  //What about 
  
  while( nevent<NMAX ){

    ULong64_t nbgpulses = num.Poisson( 2.0*nsamp*tsamp_ns/1.e9 * bgrate );

    vector<double> Abg(nbgpulses,0.0);
    vector<double> t0bg(nbgpulses,0.0);
    vector<double> taubg(nbgpulses,0.0);

    for( int i=0; i<nbgpulses; i++ ){
      Abg[i] = num.Exp( 0.1*Vpp );
      t0bg[i] = num.Uniform(-nsamp*tsamp_ns, nsamp*tsamp_ns);
      taubg[i] = num.Gaus( tau_avg_ns, tau_sigma_ns );
    }
    
    double Atrue = num.Exp( 0.1*Vpp );
    double t0true = num.Gaus(t0avg_ns, t0_sigma_ns);
    double tautrue = num.Gaus(tau_avg_ns, tau_sigma_ns);

    double truepulsepar[] = {pedmean_V, Atrue, t0true, tautrue};

    PulseShapeFunc->SetParameters(truepulsepar);
    
    vector<double> FADC_samps_raw(nsamp,0.0); //"smeared" FADC samps
    vector<double> Voltage_vs_time_true(nsamp,0.0); //"true" voltage vs time
    vector<double> FADC_samps_true(nsamp,0.0); //"true" FADC samps
    vector<double> Voltage_vs_time_raw(nsamp,0.0); //smeared for noise
    vector<double> FADC_samps_deconv(nsamp,0.0); //smeared and ped-subtracted and time-sample deconvoluted
    vector<double> dFADC_samps_deconv(nsamp,1.0*Vpp/pow(2,nbits_ADC));

    double Vmin = Vpp, Vmax = 0.0;
    
    for( int i=0; i<nsamp; i++ ){
      PulseShapeFunc->SetParameters( truepulsepar );
      
      Voltage_vs_time_true[i] = PulseShapeFunc->Eval( tsamp[i] );

      //Now superimpose background pulses, if applicable:
      for( int j=0; j<nbgpulses; j++ ){
	double bgpulseparams[] = { 0.0, Abg[j], t0bg[j], taubg[j] };
	PulseShapeFunc->SetParameters( bgpulseparams );
	// PulseShapeFunc->SetParameter( 0, 0.0 );
	// PulseShapeFunc->SetParameter( 1, Abg[j] );
	// PulseShapeFunc->SetParameter( 2, t0bg[j] );
	// PulseShapeFunc->SetParameter( 3, taubg[j] );
	Voltage_vs_time_true[i] += PulseShapeFunc->Eval( tsamp[i] );
      }
      
      FADC_samps_true[i] = Voltage_vs_time_true[i] * pow(2,nbits_ADC)/Vpp;
      FADC_samps_raw[i] = FADC_samps_true[i] + num.Gaus(0,sigma_samp);
      Voltage_vs_time_raw[i] = FADC_samps_raw[i] * Vpp / pow(2,nbits_ADC);

      Vmin = (Voltage_vs_time_raw[i] < Vmin) ? Voltage_vs_time_raw[i] : Vmin;
      Vmax = (Voltage_vs_time_raw[i] > Vmax) ? Voltage_vs_time_raw[i] : Vmax;
    }

    TGraphErrors *gSampsRaw = new TGraphErrors( nsamp, &(tsamp[0]), &(Voltage_vs_time_raw[0]), &(dtsamp[0]), &(dFADCsamps_raw[0]) );

    c1->Clear();
    c1->SetGrid();
    hframe->GetYaxis()->SetRangeUser( std::min( Vmin-0.5*Atrue, pedmean_V-2.0*thresh_deconv),
				      1.5*Vmax );
    hframe->Draw();

    gSampsRaw->SetMarkerStyle(20);

    gSampsRaw->Draw("PSAME");

    PulseShapeFunc->SetParameters(truepulsepar);

    PulseShapeFunc->SetLineStyle(1);
    PulseShapeFunc->SetLineColor(1);
    PulseShapeFunc->SetLineWidth(2);
    PulseShapeFunc->DrawCopy("C3SAME");

    //Loop on all the other pulses and plot their "true" shapes (up to a maximum of 5):
    for( int j=0; j<nbgpulses; j++ ){
      double pulseparams[] = {pedmean_V, Abg[j], t0bg[j], taubg[j]};

      PulseShapeFunc->SetParameters(pulseparams);
      PulseShapeFunc->SetLineStyle(3);
      PulseShapeFunc->SetLineColor(1);
      PulseShapeFunc->SetLineWidth(1);
      PulseShapeFunc->DrawCopy("C3SAME");
      
    }
    

    double ped_estimated = pedmean_V;
    double t0_estimated = -1000.0;
    double A_estimated = 0.0;
    double tau_estimated = 100.0;
    //Now grab "estimated" pulse shape params, and see how well we do:
    GetEstimatedPulseParams( Voltage_vs_time_raw, t0_estimated, A_estimated, tau_estimated, ped_estimated, tsamp_ns, thresh );    
    
    double estpulsepar[] = { ped_estimated, A_estimated, t0_estimated, tau_estimated };

    for( int i=0; i<nsamp; i++ ){
      double ADC[3] = { Voltage_vs_time_raw[i-2] - ped_estimated,
			Voltage_vs_time_raw[i-1] - ped_estimated,
			Voltage_vs_time_raw[i] - ped_estimated };

      //The deconvoluted samples are a weighted sum where the weights have effectively zero uncertainty, so basically:

      // DADC = sum_i w_i ADC_i
      // Delta (DADC) = sqrt(sumsq(w_i*dADC_i))

      double dADCsumsq = pow(deconv_weights[0],2)+pow(deconv_weights[1],2)+pow(deconv_weights[2],2);

      dFADC_samps_deconv[i] = dFADCsamps_raw[0]*sqrt(dADCsumsq);
      // for samples 1 and 0, calculation ASSUMES that ADC[-1] and ADC[-2] = 0
      
      if( i>=2 ){
	for( int j=0; j<3; j++ ){
	  FADC_samps_deconv[i] += deconv_weights[2-j]*ADC[j];
	  //dADCsumsq += pow(deconv_weights[2-j]*dFADCsamps_raw[i-(2-j)],2);
	}
	FADC_samps_deconv[i] += ped_estimated;
	
      } else if( i == 1 ){
      	FADC_samps_deconv[i] += deconv_weights[1]*ADC[1] + deconv_weights[0]*ADC[2]; 
      	FADC_samps_deconv[i] += ped_estimated;
      } else { //i==0:
      	FADC_samps_deconv[i] += deconv_weights[0]*ADC[2];
      	FADC_samps_deconv[i] += ped_estimated;
      }
    }
    
    int npulse_deconv = 0;
    vector<double> Apulse_deconv, t0pulse_deconv;

    GetDeconvolutedPulses( FADC_samps_deconv, npulse_deconv, Apulse_deconv, t0pulse_deconv, ped_estimated, thresh_deconv );

    //note that the pulses returned by this method are time-ordered! 
    
    //Deconvoluted pulse time is going to be roughly equivalent to tmid in general

    //First, find the pulse closest to "goodtimecut" (in our case t0avg)
    int bestpulse = -1;

    double mintdiff = 1000.0;
    
    for( int i=0; i<npulse_deconv; i++ ){
      double t0temp = t0pulse_deconv[i] - 0.232*tau_avg_ns;
      double tdifftemp = fabs(t0temp-t0avg_ns);
      if( i == 0 || tdifftemp < mintdiff ){
	bestpulse = i;
	mintdiff = tdifftemp;
      }
    }
    
    if( bestpulse >= 0 ){ //attempt to FIT the waveform; attempt to decide whether we need to add one more "pre-pulse"
      if( FADC_samps_deconv[0] - ped_estimated > thresh_deconv && t0pulse_deconv[0] > 2*tsamp_ns ){ //then it is likely we need an additional "pre-pulse":

	//To estimate the start time and amplitude:
	double Aest_avg = 0.0;
	double tpre_avg = 0.0;
	for( int i=0; i<3; i++ ){
	  double Vtemp = Voltage_vs_time_raw[i] - ped_estimated;
	  double Vtemp_next = Voltage_vs_time_raw[i+1] - ped_estimated;
	  double ndeconv = Vtemp/(Vtemp_next*exp(xdeconv)-Vtemp);

	  //This formula is equivalent to 1/(Vnext/V*e^x-1);
	  //Error propagation:
	  
	  
	  // if t0 = (i-ndeconv)*tsamp, then t - t0 = ndeconv*tsamp, and
	  // A_i = A*(ndeconv*tsamp)/tau * exp(1.0-ndeconv*tsamp/tau) = A*ndeconv*x * exp(1-ndeconv*x)
	  // --> A estimated = A_i / (ndeconv*x) * exp(ndeconv*x-1)
	  Aest_avg += Vtemp * exp( ndeconv*xdeconv - 1.0 )/(ndeconv * xdeconv);
	  
	  tpre_avg += (i-ndeconv)*tsamp_ns; //estimated start time of pulse
	}
	tpre_avg /= 3.;
	Aest_avg /= 3.;

	//add "pre-pulse" to the list of pulses:
	Apulse_deconv.push_back( Aest_avg );
	t0pulse_deconv.push_back( tpre_avg );
	npulse_deconv++;
      }

      for( int ipar=0; ipar<2+3*MAXNPULSE; ipar++ ){
	MultiPulseFitFunc->ReleaseParameter(ipar);
      }
      
      MultiPulseFitFunc->FixParameter( 0, double(std::min(MAXNPULSE,npulse_deconv)) );
      MultiPulseFitFunc->SetParameter( 1, ped_estimated );
      MultiPulseFitFunc->SetParameter( 2, Apulse_deconv[bestpulse] );
      MultiPulseFitFunc->SetParameter( 3, t0pulse_deconv[bestpulse] );
      MultiPulseFitFunc->SetParameter( 4, tau_avg_ns );
      MultiPulseFitFunc->SetParLimits( 4, 0.1*tau_avg_ns, 10.0*tau_avg_ns );

      int ipar=5;
      vector<bool> pulseused(npulse_deconv,false);
      pulseused[bestpulse] = true;
      
      while( ipar<3*MAXNPULSE+2 ){
	
	int ipulse_mintdiff = -1;
	double mintdiff = 1000.0;
	for( int ipulse=0; ipulse<npulse_deconv; ipulse++ ){
	  double tdiff = fabs( t0pulse_deconv[ipulse] - t0pulse_deconv[bestpulse] );
	  if( !pulseused[ipulse] && ( ipulse_mintdiff < 0 || tdiff < mintdiff) ){
	    mintdiff = tdiff;
	    ipulse_mintdiff = ipulse;
	  }
	}
	if( ipulse_mintdiff >= 0 ){
	  pulseused[ipulse_mintdiff] = true;
	  MultiPulseFitFunc->SetParameter( ipar, Apulse_deconv[ipulse_mintdiff] );
	  MultiPulseFitFunc->SetParameter( ipar+1, t0pulse_deconv[ipulse_mintdiff] );
	  MultiPulseFitFunc->SetParameter( ipar+2, tau_avg_ns );
	  MultiPulseFitFunc->SetParLimits( ipar+2, 0.1*tau_avg_ns, 10.0*tau_avg_ns );
	} else { //we ran out of pulses:
	  MultiPulseFitFunc->FixParameter( ipar, 0.0 );
	  MultiPulseFitFunc->FixParameter( ipar+1, -1000.0 );
	  MultiPulseFitFunc->FixParameter( ipar+2, tau_avg_ns );
	}
	ipar+=3;
      }

      //Here we go... hope this works:
      gSampsRaw->Fit( MultiPulseFitFunc, "BS", "", 0.0, (nsamp-1)*tsamp_ns );
    }
    
    TGraphErrors *gSampsDeconv = new TGraphErrors( nsamp, &(tsamp[0]), &(FADC_samps_deconv[0]), &(dtsamp[0]), &(dFADC_samps_deconv[0]) );

    gSampsDeconv->SetMarkerStyle(21);
    gSampsDeconv->SetMarkerColor(2);
    gSampsDeconv->SetLineColor(2);

    gSampsDeconv->Draw("PSAME");

 
 
      
    
    TLine Lthresh;
    Lthresh.SetLineWidth(2);
    Lthresh.SetLineColor(4);
    Lthresh.SetLineStyle(3);
    Lthresh.DrawLine( hframe->GetXaxis()->GetXmin(), ped_estimated + thresh_deconv, hframe->GetXaxis()->GetXmax(), ped_estimated + thresh_deconv );

    // PulseShapeFunc->SetParameters(estpulsepar);

    // PulseShapeFunc->SetLineColor(4);
    // PulseShapeFunc->SetLineStyle(9);
    // PulseShapeFunc->DrawCopy("C3SAME");

    //gSampsRaw->Fit(PulseShapeFunc,"S0Q","",t0_estimated - 3.*tsamp_ns, t0_estimated + 2.*tau_estimated);
    
    // PulseShapeFunc->SetLineColor(6);
    // PulseShapeFunc->SetLineStyle(10);
    // PulseShapeFunc->Draw("C3SAME");

    
   
    
    //Now we do a fit:
    
    
    //Now do a "fitted" version of the pulse
    
    TPaveText *ptemp = new TPaveText( tsamp_ns, pedmean_V + 0.3*Atrue, tsamp_ns*0.4*nsamp, 1.45*Vmax, "br" );
    ptemp->SetFillStyle(0);
    ptemp->SetBorderSize(0);
    ptemp->AddText("This pulse:");
    ptemp->AddText(Form("True Amplitude = %6.4g V", Atrue));
    ptemp->AddText(Form("True t0 = %6.4g ns", t0true));
    ptemp->AddText(Form("True tau = %6.4g ns", tautrue));
    // ptemp->AddText(Form("Est. Ampl. = %6.4g V", A_estimated));
    // ptemp->AddText(Form("Est. t0 = %6.4g ns", t0_estimated));
    // ptemp->AddText(Form("Est. tau = %6.4g ns", tau_estimated));
    // ptemp->AddText(Form("Est. ped = %6.4g V", ped_estimated));

    ptemp->Draw();
    
    c1->Update();
    gPad->Modified();
    gSystem->ProcessEvents();

    cout << "press enter for next pulse (q to quit)";

    TString reply;
    reply.ReadLine(cin,kFALSE);

    reply.ToLower();
    if( reply.BeginsWith("q") ) break;
    
    gSampsRaw->Delete();
    
    nevent++;
  }
  

}
  
