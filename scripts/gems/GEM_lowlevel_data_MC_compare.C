// Standalone ROOT 6 macro. See GEM_lowlevel_compare_README.md.
// root -l -b -q 'GEM_lowlevel_data_MC_compare.C+("compare_ft.cfg","ft_compare")'
#ifdef __ROOTCLING__
// Only the entry point needs a dictionary. Internal ownership/reader objects are
// never persisted; avoiding their dictionaries also supports older ROOT 6 builds.
void GEM_lowlevel_data_MC_compare(const char* config="compare_ft.cfg",const char* output_prefix="gem_lowlevel_compare");
#else
#include <TFile.h>
#include <TTree.h>
#include <TLeaf.h>
#include <TBranch.h>
#include <TTreeFormula.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TLine.h>
#include <TGraphErrors.h>
#include <TNamed.h>
#include <TParameter.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TROOT.h>
#include <TKey.h>
#include <TDirectory.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <glob.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <limits>
#include <cstdlib>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

namespace GEMCompare {
using std::string;
string trim(string s) {
  auto a=s.find_first_not_of(" \t\r\n"), b=s.find_last_not_of(" \t\r\n");
  return a==string::npos ? "" : s.substr(a,b-a+1);
}
string replace(string s,const string& a,const string& b) {
  size_t p=0; while((p=s.find(a,p))!=string::npos){s.replace(p,a.size(),b);p+=b.size();} return s;
}
string json(const string& s) {
  std::ostringstream o; o<<'"'; for(unsigned char c:s) {
    if(c=='"'||c=='\\') o<<'\\'<<c;
    else if(c=='\n') o<<"\\n"; else if(c=='\r') o<<"\\r";
    else if(c=='\t') o<<"\\t"; else if(c<32) o<<"?"; else o<<c;
  } o<<'"'; return o.str();
}
string csv(const string& s) {return '"'+replace(s,"\"","\"\"")+'"';}
std::vector<string> split(const string& s,char sep=',') {
  std::vector<string> out; std::istringstream in(s); string x;
  while(std::getline(in,x,sep)) if(!trim(x).empty()) out.push_back(trim(x)); return out;
}
double number(const string& s) {
  size_t n=0; double x=std::stod(s,&n);
  if(n!=s.size()||!std::isfinite(x)) throw std::runtime_error("Invalid number: "+s); return x;
}
std::vector<double> edges(const string& s) {
  std::vector<double> e; for(auto& x:split(s)) e.push_back(number(x));
  if(e.size()<2||!std::is_sorted(e.begin(),e.end())||std::adjacent_find(e.begin(),e.end())!=e.end())
    throw std::runtime_error("Bin edges must be strictly increasing: "+s); return e;
}
struct Config {
  std::vector<string> patterns[2],files[2];
  string cut[2]={"1","1"}, signal[2]={"1","1"},weight[2]={"1","1"};
  string label[2]={"Data","MC"}, mode[2]={"periodic full-readout + online ZS","3"};
  string calibration[2]={"unspecified","unspecified"};
  string tree="T",detector="sbs.gemFT",catalog;
  string source="combined",baseline="saved";
  std::vector<int> modules;
  std::vector<string> views={"inclusive","ontrack","offtrack","full_readout"};
  std::vector<double> charge={0,500,1500,4000,10000,30000};
  std::vector<double> occupancy={0,4,12,32,129};
  Long64_t maxevents=-1;
  int nmodules=14,pdfpages=0,pdfmodule=-1;
  double mincharge=200,rawrail=4095;
  bool pdf=true,besttrack=false,strict=false,extensions=true;
};
void addcut(string& dst,const string& line) {
  if(dst=="1") dst="("+line+")"; else dst+=" && ("+line+")";
}
Config readConfig(const string& path) {
  Config c; c.catalog=string(gSystem->DirName(__FILE__))+"/GEM_lowlevel_catalog.tsv";
  std::ifstream in(path); if(!in) throw std::runtime_error("Cannot read config: "+path);
  enum {Dat,MC,DatCut,MCCut,Settings} section=Dat; string line;
  while(std::getline(in,line)) {
    line=trim(line); if(line.empty()||line[0]=='#') continue;
    if(line=="endDatlist"){section=MC;continue;} if(line=="endMClist"){section=DatCut;continue;}
    if(line=="endcutDat"){section=MCCut;continue;} if(line=="endcutMC"){section=Settings;continue;}
    if(line=="endcfg") break;
    if(section==Dat||section==MC){c.patterns[section==Dat?0:1].push_back(line);continue;}
    if(section==DatCut||section==MCCut){addcut(c.cut[section==DatCut?0:1],line);continue;}
    auto p=line.find_first_of(" \t="); if(p==string::npos) throw std::runtime_error("Config expects key value: "+line);
    string k=line.substr(0,p),v=trim(line.substr(p)); if(!v.empty()&&v[0]=='=') v=trim(v.substr(1));
    if(k=="spectrometer"||k=="sepctrometer") {
      if(k=="sepctrometer") std::cerr<<"Warning: accepting legacy sepctrometer spelling\n";
      auto dot=c.detector.find('.'); c.detector=v+c.detector.substr(dot);
    }
    else if(k=="gemtracker") {auto dot=c.detector.find('.');c.detector=c.detector.substr(0,dot)+".gem"+v;}
    else if(k=="detector") c.detector=v;
    else if(k=="nmodules") c.nmodules=number(v);
    else if(k=="modules") {for(auto& s:split(v)) c.modules.push_back(number(s));}
    else if(k=="views") c.views=split(v);
    else if(k=="input_source") c.source=v;
    else if(k=="baseline_source") c.baseline=v;
    else if(k=="catalog") c.catalog=v;
    else if(k=="tree_name") c.tree=v;
    else if(k=="data_label") c.label[0]=v;
    else if(k=="mc_label") c.label[1]=v;
    else if(k=="data_signal_cut") c.signal[0]=v;
    else if(k=="mc_signal_cut") c.signal[1]=v;
    else if(k=="data_weight") c.weight[0]=v;
    else if(k=="mc_weight") c.weight[1]=v;
    else if(k=="data_readout") c.mode[0]=v;
    else if(k=="mc_input_mode") c.mode[1]=v;
    else if(k=="data_calibration") c.calibration[0]=v;
    else if(k=="mc_calibration") c.calibration[1]=v;
    else if(k=="max_events") c.maxevents=number(v);
    else if(k=="charge_edges") c.charge=edges(v);
    else if(k=="occupancy_edges") c.occupancy=edges(v);
    else if(k=="min_pulse_charge") c.mincharge=number(v);
    else if(k=="raw_rail") c.rawrail=number(v);
    else if(k=="make_pdf") c.pdf=number(v)!=0;
    else if(k=="pdf_max_pages") c.pdfpages=number(v);
    else if(k=="pdf_module") c.pdfmodule=number(v);
    else if(k=="best_track_only") c.besttrack=number(v)!=0;
    else if(k=="strict_optional") c.strict=number(v)!=0;
    else if(k=="saved_electronics") c.extensions=number(v)!=0;
    else throw std::runtime_error("Unknown config key: "+k);
  }
  if(section!=Settings) throw std::runtime_error("Config lacks file-list/cut section terminators");
  if(c.nmodules<1||c.nmodules>1000) throw std::runtime_error("Invalid nmodules");
  if(c.modules.empty()) for(int m=0;m<c.nmodules;m++) c.modules.push_back(m);
  std::sort(c.modules.begin(),c.modules.end());
  if(std::adjacent_find(c.modules.begin(),c.modules.end())!=c.modules.end()) throw std::runtime_error("Duplicate module");
  for(int m:c.modules) if(m<0||m>=c.nmodules) throw std::runtime_error("Module outside nmodules");
  for(auto& v:c.views) if(v!="inclusive"&&v!="ontrack"&&v!="offtrack"&&v!="full_readout") throw std::runtime_error("Unknown view: "+v);
  if(c.source!="hist"&&c.source!="tree"&&c.source!="combined") throw std::runtime_error("input_source must be hist/tree/combined");
  if(c.baseline!="saved"&&c.baseline!="tree") throw std::runtime_error("baseline_source must be saved/tree");
  if(c.source=="hist"&&c.baseline=="tree") throw std::runtime_error("Tree baseline requires tree/combined input_source");
  if(c.mincharge<=0||c.rawrail<=0) throw std::runtime_error("min_pulse_charge/raw_rail must be positive");
  for(int d=0;d<2;d++) {
    std::set<string> seen;
    for(auto pattern:c.patterns[d]) {
      TString expanded(pattern); gSystem->ExpandPathName(expanded); glob_t result={};
      int rc=glob(expanded.Data(),GLOB_TILDE,nullptr,&result);
      if(rc!=0||result.gl_pathc==0){globfree(&result);throw std::runtime_error("No files match: "+pattern);}
      for(size_t i=0;i<result.gl_pathc;i++) {
        char* real=realpath(result.gl_pathv[i],nullptr); string name=real?real:result.gl_pathv[i]; free(real);
        if(seen.insert(name).second) c.files[d].push_back(name);
        else std::cerr<<"Deduplicated input: "<<name<<"\n";
      } globfree(&result);
    }
    std::sort(c.files[d].begin(),c.files[d].end());
    if(c.files[d].empty()) throw std::runtime_error("Both data and MC file lists are required");
    if(c.baseline=="saved"&&(c.cut[d]!="1"||c.weight[d]!="1"))
      std::cerr<<"Warning: "<<c.label[d]<<" saved histograms retain ORIGINAL replay cuts/weights; tree selections apply only to tree diagnostics. Use baseline_source tree to rebuild GUI histograms.\n";
  } return c;
}
struct Spec {string name,title,var,cut,scope;int module=-1,bins=0;double lo=0,hi=0;bool saved=false;};
std::vector<Spec> readCatalog(const Config& c) {
  std::ifstream in(c.catalog); if(!in) throw std::runtime_error("Cannot read catalog: "+c.catalog);
  std::vector<Spec> out; string line;
  while(std::getline(in,line)) {
    if(line.empty()||line[0]=='#') continue;
    auto f=split(line,'\t'); if(f.size()!=3) throw std::runtime_error("Bad catalog row: "+line);
    Spec s;s.name=f[0];s.module=number(f[1]);
    if(std::find(c.modules.begin(),c.modules.end(),s.module)==c.modules.end()) continue;
    if(f[2]=="module") {s.saved=true;s.scope="saved pre-ZS full-readout samples; original Decode gate, no custom cuts";}
    else {
      std::istringstream def(f[2]);string kind,name;
      def>>kind>>name>>std::quoted(s.title,'\'')>>s.var>>s.bins>>s.lo>>s.hi;
      if(!def||kind!="th1d"||name!=s.name||s.bins<=0||s.hi<=s.lo) throw std::runtime_error("Invalid GUI definition: "+f[2]);
      if(!(def>>s.cut)) s.cut="1"; // .odef permits omission of the cut.
      s.scope="retained strips / clusters; original .odef selection: "+s.cut;
      s.var=replace(s.var,"[I]","");s.cut=replace(s.cut,"[I]","");
      if(s.cut=="nocut") s.cut="1";
    } out.push_back(s);
  }
  if(out.empty()) throw std::runtime_error("Catalog has no selected modules");
  // A catalog is detector-specific: never silently reuse FT geometry for FPP.
  string token=replace(c.detector,".","_");
  for(auto& s:out) if(s.name.find(token)==string::npos) throw std::runtime_error("Catalog does not match detector "+c.detector);
  return out;
}
struct Plot {
  std::unique_ptr<TH1> h; string group,scope,normal="density"; int module=-1;
  double exposure=0; string denominator;
};
struct Sample {
  std::map<string,Plot> plots;
  Long64_t total=0,visited=0,selected=0,signal=0; double sumw=0,signalw=0;
  Long64_t nonfinite=0,malformed=0;
};
struct Issue {int dataset;string file,plot,reason;};
struct Context {
  Config c; std::vector<Spec> specs; Sample s[2]; std::vector<Issue> issues;
  std::set<string> invalid[2];
  void issue(int d,const string& file,const string& plot,const string& reason) {
    issues.push_back({d,file,plot,reason});
    if(d>=0) invalid[d].insert(plot);
    if(c.strict) throw std::runtime_error(plot+": "+reason+" in "+file);
  }
};
std::unique_ptr<TH1> clone(const TH1& h,const string& n) {
  auto p=std::unique_ptr<TH1>(dynamic_cast<TH1*>(h.Clone(n.c_str())));p->SetDirectory(nullptr);return p;
}
bool sameAxis(const TAxis& a,const TAxis& b) {
  if(a.GetNbins()!=b.GetNbins()) return false;
  for(int i=1;i<=a.GetNbins()+1;i++) if(std::abs(a.GetBinLowEdge(i)-b.GetBinLowEdge(i))>1e-9*std::max(1.,std::abs(a.GetBinLowEdge(i)))) return false;
  return true;
}
bool compatible(const TH1& a,const TH1& b) {
  return a.IsA()==b.IsA()&&a.GetDimension()==b.GetDimension()&&sameAxis(*a.GetXaxis(),*b.GetXaxis())
    &&(a.GetDimension()<2||sameAxis(*a.GetYaxis(),*b.GetYaxis()));
}
Plot& book(Sample& s,const string& name,TH1* h,const string& group,const string& scope,int module,const string& norm="density") {
  h->SetDirectory(nullptr);if(h->GetSumw2N()==0&&!dynamic_cast<TProfile*>(h))h->Sumw2();Plot p;p.h.reset(h);p.group=group;p.scope=scope;p.module=module;p.normal=norm;
  auto r=s.plots.emplace(name,std::move(p));if(!r.second) throw std::runtime_error("Duplicate plot: "+name); return r.first->second;
}
void importHist(Context& x,int d,TFile& f,const string& path,const string& name,int m,const string& group,const string& scope,Long64_t entries) {
  TH1* h=nullptr;f.GetObject(name.c_str(),h);
  if(!h){x.issue(d,path,name,"missing saved histogram");return;}
  if(h->GetDimension()>2){x.issue(d,path,name,"unsupported dimension");return;}
  auto& plots=x.s[d].plots;auto it=plots.find(name);
  if(it==plots.end()) {
    Plot p;p.h=clone(*h,name);if(p.h->GetSumw2N()==0)p.h->Sumw2();p.module=m;p.group=group;p.scope=scope;
    if(group=="GUI"&&entries>0){p.exposure=entries;p.denominator="all replay tree entries (original .odef cuts)";}
    plots.emplace(name,std::move(p));
  } else {
    if(!compatible(*it->second.h,*h)) throw std::runtime_error("Incompatible saved histogram bins/class in "+path+": "+name);
    it->second.h->Add(h);if(group=="GUI") it->second.exposure+=entries;
  }
}
// Dynamic TLeaf reading uses ROOT's actual array lengths; no generated fixed buffers.
struct Leaf {
  TLeaf* p=nullptr;
  int size() const{return p?p->GetLen():0;}
  double get(int i=0) const {return p&&i>=0&&i<size()?p->GetValue(i):std::numeric_limits<double>::quiet_NaN();}
};
Leaf getLeaf(TTree& t,const string& n) {
  TLeaf* p=t.GetLeaf(n.c_str());if(!p) return {};
  static const std::set<string> types={"Double_t","Float_t","Int_t","UInt_t","Short_t","UShort_t","Char_t","UChar_t","Bool_t","Long64_t","ULong64_t","Long_t","ULong_t"};
  if(!types.count(p->GetTypeName())) throw std::runtime_error("Unsupported leaf type: "+n+" "+p->GetTypeName());
  t.SetBranchStatus(p->GetBranch()->GetName(),1);
  if(p->GetLeafCount()) t.SetBranchStatus(p->GetLeafCount()->GetBranch()->GetName(),1);return {p};
}
void enableExpression(TTree& t,const string& expr,int depth=0) {
  if(depth>16) throw std::runtime_error("Recursive tree alias in expression");
  static const std::regex token("[A-Za-z_][A-Za-z0-9_.]*");
  for(auto i=std::sregex_iterator(expr.begin(),expr.end(),token);i!=std::sregex_iterator();++i) {
    const string name=i->str();
    if(auto* alias=t.GetAlias(name.c_str())) enableExpression(t,alias,depth+1);
    else getLeaf(t,name);
  }
}
std::unique_ptr<TTreeFormula> formula(TTree& t,const string& name,const string& expr) {
  // ROOT requires branches enabled while compiling formulas, before GetLeaf()
  // can be used to inspect the resulting formula. Activate identifiers first.
  enableExpression(t,expr);
  auto p=std::unique_ptr<TTreeFormula>(new TTreeFormula(name.c_str(),expr.c_str(),&t));
  if(p->GetNdim()<=0) return nullptr;
  for(int i=0;i<p->GetNcodes();i++) if(auto l=p->GetLeaf(i)) {
    t.SetBranchStatus(l->GetBranch()->GetName(),1);
    if(l->GetLeafCount()) t.SetBranchStatus(l->GetLeafCount()->GetBranch()->GetName(),1);
  } return p;
}
struct GuiReader {const Spec* spec=nullptr;TTreeFormula* value=nullptr;TTreeFormula* cut=nullptr;};
struct Module {
  int m=0;string prefix;
  Leaf strip,isU,charge,adcmax,time,width,samples,raw,ontrack,itrack,build,enable,cmgood,mode;
  Leaf cn[2],csize[2],ccharge[2],clo[2],cseed[2];
  bool valid=false;
};
string base(int m,const string& axis,const string& view) {return "m"+std::to_string(m)+"_"+axis+"_"+view+"_";}
void bookModule(Context& x,int d,int m) {
  auto& s=x.s[d];
  auto h1=[&](string n,string title,int nb,double lo,double hi,string g,string sc,string norm="density") {
    return &book(s,n,new TH1D(n.c_str(),title.c_str(),nb,lo,hi),g,sc,m,norm);
  };
  auto h2=[&](string n,string title,int nx,double xl,double xh,int ny,double yl,double yh,string g,string sc) {
    return &book(s,n,new TH2D(n.c_str(),title.c_str(),nx,xl,xh,ny,yl,yh),g,sc,m);
  };
  string pre="m"+std::to_string(m)+"_";
  h2(pre+"UV_strip_multiplicity","Retained strip multiplicity;U strips;V strips",80,-.5,799.5,80,-.5,799.5,"Occupancy","inclusive selected events; counts after replay ZS");
  h2(pre+"UV_cluster_multiplicity","Positive cluster multiplicity;U clusters;V clusters",60,-.5,59.5,60,-.5,59.5,"Occupancy","inclusive selected events; existing clusters");
  for(auto axis:{string("U"),string("V")}) {
    for(const auto& view:x.c.views) {
      string b=base(m,axis,view),sc="tree "+view+" retained strips; configured inclusive cut; gain-corrected samples";
      h1(b+"charge","Strip charge;ADC sum;strips",200,-500,30000,"Amplitude",sc);
      h1(b+"peak_sample","Pulse peak;sample index;strips",6,-.5,5.5,"Timing",sc);
      h1(b+"strip_index","Retained channel activity;physical strip index;strips",8192,-.5,8191.5,"Occupancy",sc);
      h1(b+"apv_occupancy","Retained occupancy;strips / physical APV / event;APV-events",129,-.5,128.5,"Occupancy",sc+(view=="full_readout"?"; only APVs with at least one retained strip carrying full-readout flags":"; includes empty APVs up to physical range in GUI catalog"));
      h2(b+"sum_vs_max","Amplitude relation;ADC sum;ADC maximum",100,0,30000,100,-100,5000,"Amplitude",sc);
      h2(b+"peak_vs_charge","Peak versus charge;ADC sum;sample index",100,0,30000,6,-.5,5.5,"Timing",sc);
      h2(b+"time_vs_charge","Mean time versus charge;ADC sum;mean time (ns)",100,0,30000,100,-30,180,"Timing",sc);
      h2(b+"width_vs_charge","Pulse width versus charge;ADC sum;time RMS (ns)",100,0,30000,80,0,80,"Timing",sc);
      h2(b+"time_vs_apv","Timing map;physical APV index;mean time (ns)",64,-.5,63.5,100,-30,180,"Timing",sc);
      h2(b+"absolute_samples","Absolute waveform;sample index;ADC",6,-.5,5.5,200,-500,5000,"Pulse",sc);
      h2(b+"fraction_samples","Normalized waveform;sample index;ADC[k] / sum(ADC)",6,-.5,5.5,160,-.5,1.5,"Pulse",sc+"; sum(samples) > min_pulse_charge; signed samples preserved");
      h1(b+"early_fraction","Early charge fraction;(ADC[0]+ADC[1]) / sum;strips",160,-.5,1.5,"Pulse",sc);
      h1(b+"late_fraction","Late charge fraction;(ADC[4]+ADC[5]) / sum;strips",160,-.5,1.5,"Pulse",sc);
      h2(b+"peak_fraction_vs_charge","Peak fraction;sum(samples);max(samples) / sum",100,0,30000,100,0,1.5,"Pulse",sc);
      h2(b+"raw_rail_vs_apv","Raw transport rail indicator;physical APV index;any sample >= raw_rail",64,-.5,63.5,2,-.5,1.5,"Rails",sc+"; raw transport, not a hardware saturation assertion");
      for(auto tag:{string("rail"),string("no_rail")}) h2(b+"fraction_samples_"+tag,"Rail-conditioned waveform;sample index;fraction",6,-.5,5.5,160,-.5,1.5,"Rails",sc);
      h2(b+"sample_correlation","Retained-pulse Pearson correlation;sample index;sample index",6,-.5,5.5,6,-.5,5.5,"Pulse",sc+"; covariance includes charge/time mixture, not unbiased noise")->normal="value";
    }
    string b=base(m,axis,"inclusive"),sc="inclusive selected events; existing positive clusters and retained strips";
    h2(b+"cluster_size_vs_charge","Cluster size;cluster ADC sum;strips / cluster",100,0,60000,30,.5,30.5,"Sharing",sc);
    h2(b+"neighbor_fraction","Retained sharing about cluster seed;strip - seed;strip charge / retained cluster charge",17,-8.5,8.5,120,-.1,1.1,"Sharing",sc+"; bounds validated, sub-threshold wings absent");
    h2(b+"neighbor_dt","Neighbor timing;strip - seed;time - seed time (ns)",17,-8.5,8.5,100,-50,50,"Sharing",sc);
    h2(b+"neighbor_correlation","Neighbor waveform correlation;strip - seed;Pearson r",17,-8.5,8.5,100,-1,1,"Sharing",sc);
    h1(b+"neighbor_spacing","Spacing of retained strips;physical strip separation;adjacent pairs",128,.5,128.5,"Occupancy",sc);
    for(size_t q=0;q+1<x.c.charge.size();q++) h2(b+"fraction_chargebin"+std::to_string(q),"Charge-conditioned waveform;sample index;sample fraction",6,-.5,5.5,160,-.5,1.5,"Conditional",sc);
    for(size_t q=0;q+1<x.c.occupancy.size();q++) h2(b+"fraction_occupancybin"+std::to_string(q),"APV-occupancy-conditioned waveform;sample index;sample fraction",6,-.5,5.5,160,-.5,1.5,"Conditional",sc);
    h2(b+"peak_vs_charge_slice","Charge / peak-sample distribution;ADC sum;peak sample",100,0,30000,6,-.5,5.5,"Conditional",sc);
    h2(b+"charge_vs_file","File stability;file index;ADC sum",x.c.files[d].size(),-.5,x.c.files[d].size()-.5,100,0,30000,"Stability",sc);
  }
}
struct Moments {
  double w=0;std::array<double,6> sum{};std::array<std::array<double,6>,6> cross{};
  void add(const std::array<double,6>& a,double weight) {
    w+=weight;for(int i=0;i<6;i++){sum[i]+=weight*a[i];for(int j=0;j<6;j++) cross[i][j]+=weight*a[i]*a[j];}
  }
  void store(TH2& h) {
    if(w<=0) return;
    for(int i=0;i<6;i++) for(int j=0;j<6;j++) {
      double vi=cross[i][i]/w-std::pow(sum[i]/w,2),vj=cross[j][j]/w-std::pow(sum[j]/w,2);
      double cov=cross[i][j]/w-sum[i]*sum[j]/(w*w);
      if(vi>0&&vj>0) h.SetBinContent(i+1,j+1,std::max(-1.,std::min(1.,cov/std::sqrt(vi*vj))));
    }h.SetEntries(w);
  }
};
int slice(double value,const std::vector<double>& e) {
  if(value<e.front()||value>=e.back()) return -1;
  return std::upper_bound(e.begin(),e.end(),value)-e.begin()-1;
}
void fill(Sample& s,const string& n,double a,double w) {
  auto it=s.plots.find(n);if(it==s.plots.end()) return;
  if(std::isfinite(a)) it->second.h->Fill(a,w);else ++s.nonfinite;
}
void fill2(Sample& s,const string& n,double a,double b,double w) {
  auto it=s.plots.find(n);if(it==s.plots.end()) return;
  if(std::isfinite(a)&&std::isfinite(b)) static_cast<TH2*>(it->second.h.get())->Fill(a,b,w);else ++s.nonfinite;
}
int apvCount(const Context& x,int m,int axis) {
  const string target="h"+replace(x.c.detector,".","_")+"_m"+std::to_string(m)+"_strip"+(axis==0?"U":"V")+"_all";
  for(const auto& s:x.specs) if(s.name==target) return (s.bins+127)/128;
  return 0; // No inferred denominator when geometry is absent.
}
bool integer(double x) {return std::isfinite(x)&&std::abs(x-std::round(x))<1e-6;}
void processModule(Context& x,int d,Module& r,double w,bool signal,int fileindex,std::map<string,Moments>& moments) {
  auto& s=x.s[d];const int n=r.strip.size();
  const int apvs[2]={apvCount(x,r.m,0),apvCount(x,r.m,1)};
  auto length=[&](const Leaf& l,int expect){return !l.p||l.size()==expect;};
  if(!length(r.isU,n)||!length(r.charge,n)||!length(r.adcmax,n)||!length(r.time,n)||!length(r.width,n)
     ||!length(r.ontrack,n)||!length(r.itrack,n)||!length(r.build,n)||!length(r.enable,n)||!length(r.cmgood,n)
     ||!length(r.samples,6*n)||!length(r.raw,6*n)) {++s.malformed;throw std::runtime_error("Array length mismatch in "+r.prefix+" (expected N strips / 6*N samples)");}
  std::vector<int> index[2];std::map<int,int> channel[2];std::map<int,int> occupancy[2];
  for(int i=0;i<n;i++) {
    double st=r.strip.get(i),u=r.isU.get(i);
    if(!integer(st)||st<0||st>8191||!integer(u)||(u!=0&&u!=1)) throw std::runtime_error("Invalid physical strip/axis in "+r.prefix);
    int a=u?0:1,p=std::lround(st);
    if(!channel[a].emplace(p,i).second) throw std::runtime_error("Duplicate physical strip/axis in "+r.prefix);
    if(apvs[a]>0&&p/128>=apvs[a]) throw std::runtime_error("Strip outside catalog geometry in "+r.prefix);
    index[a].push_back(i);occupancy[a][p/128]++;
  }
  fill2(s,"m"+std::to_string(r.m)+"_UV_strip_multiplicity",index[0].size(),index[1].size(),w);
  if(r.cn[0].p&&r.cn[1].p) fill2(s,"m"+std::to_string(r.m)+"_UV_cluster_multiplicity",r.cn[0].get(),r.cn[1].get(),w);
  for(int axis=0;axis<2;axis++) {
    const string a=axis==0?"U":"V",inc=base(r.m,a,"inclusive");
    std::map<string,std::map<int,int>> selectedOcc;std::map<int,bool> fullAPV;
    for(const auto& v:x.c.views) selectedOcc[v]={};
    int previous=-1;
    for(auto& pair:channel[axis]) {
      if(previous>=0) fill(s,inc+"neighbor_spacing",pair.first-previous,w);previous=pair.first;
    }
    for(int i:index[axis]) {
      int p=std::lround(r.strip.get(i)),apv=p/128;
      bool on=r.ontrack.p&&r.ontrack.get(i)!=0;
      if(x.c.besttrack) on=on&&r.itrack.p&&r.itrack.get(i)==0;
      bool full=r.build.p&&r.enable.p&&r.build.get(i)!=0&&r.enable.get(i)==0;
      if(full) fullAPV[apv]=true;
      std::array<double,6> samples{};bool have=r.samples.p;
      double sum=0,max=-std::numeric_limits<double>::infinity();int peak=0;
      if(have) for(int k=0;k<6;k++) {
        samples[k]=r.samples.get(6*i+k);if(!std::isfinite(samples[k])){have=false;++s.nonfinite;break;}
        sum+=samples[k];if(samples[k]>max){max=samples[k];peak=k;}
      }
      bool rail=false,rawok=r.raw.p;
      if(rawok) for(int k=0;k<6;k++) {double z=r.raw.get(6*i+k);if(!std::isfinite(z)){rawok=false;++s.nonfinite;break;}rail=rail||z>=x.c.rawrail;}
      for(const auto& v:x.c.views) {
        bool accept=v=="inclusive"||(v=="ontrack"&&on&&signal)||(v=="offtrack"&&r.ontrack.p&&!on)||(v=="full_readout"&&full);
        if(!accept) continue;string b=base(r.m,a,v);selectedOcc[v][apv]++;
        fill(s,b+"charge",r.charge.get(i),w);fill(s,b+"strip_index",p,w);
        if(r.adcmax.p) fill2(s,b+"sum_vs_max",r.charge.get(i),r.adcmax.get(i),w);
        if(r.time.p) {fill2(s,b+"time_vs_charge",r.charge.get(i),r.time.get(i),w);fill2(s,b+"time_vs_apv",apv,r.time.get(i),w);}
        if(r.width.p) fill2(s,b+"width_vs_charge",r.charge.get(i),r.width.get(i),w);
        if(rawok) fill2(s,b+"raw_rail_vs_apv",apv,rail,w);
        if(!have) continue;
        fill(s,b+"peak_sample",peak,w);fill2(s,b+"peak_vs_charge",r.charge.get(i),peak,w);
        for(int k=0;k<6;k++) fill2(s,b+"absolute_samples",k,samples[k],w);
        moments[b+"sample_correlation"].add(samples,w);
        if(sum<=x.c.mincharge) continue;
        for(int k=0;k<6;k++) {
          fill2(s,b+"fraction_samples",k,samples[k]/sum,w);
          if(rawok) fill2(s,b+"fraction_samples_"+(rail?"rail":"no_rail"),k,samples[k]/sum,w);
        }
        fill(s,b+"early_fraction",(samples[0]+samples[1])/sum,w);fill(s,b+"late_fraction",(samples[4]+samples[5])/sum,w);
        fill2(s,b+"peak_fraction_vs_charge",sum,max/sum,w);
      }
      fill2(s,inc+"charge_vs_file",fileindex,r.charge.get(i),w);
      if(have&&sum>x.c.mincharge&&on&&signal) {
        int q=slice(sum,x.c.charge),o=slice(occupancy[axis][apv],x.c.occupancy);
        for(int k=0;k<6;k++) {
          if(q>=0) fill2(s,inc+"fraction_chargebin"+std::to_string(q),k,samples[k]/sum,w);
          if(o>=0) fill2(s,inc+"fraction_occupancybin"+std::to_string(o),k,samples[k]/sum,w);
        }fill2(s,inc+"peak_vs_charge_slice",sum,peak,w);
      }
    }
    // Includes empty physical APVs in inclusive/ontrack/offtrack views.
    // Full-readout APVs with NO retained strips cannot be recovered from strip flags.
    for(const auto& v:x.c.views) for(int apv=0;apv<apvs[axis];apv++) {
      if(v=="full_readout"&&!fullAPV[apv]) continue;
      if(v=="ontrack"&&(!r.ontrack.p||!signal||(x.c.besttrack&&!r.itrack.p))) continue;
      if(v=="offtrack"&&!r.ontrack.p) continue;
      fill(s,base(r.m,a,v)+"apv_occupancy",selectedOcc[v][apv],w);
    }
    if(!r.csize[axis].p||!r.ccharge[axis].p) continue;
    int nc=r.csize[axis].size();
    if(r.ccharge[axis].size()!=nc||(r.clo[axis].p&&r.clo[axis].size()!=nc)||(r.cseed[axis].p&&r.cseed[axis].size()!=nc))
      throw std::runtime_error("Cluster array length mismatch in "+r.prefix);
    // Positive cluster count may differ from arrays when negative-cluster studies are enabled.
    int positive=nc;
    if(r.cn[axis].p){double count=r.cn[axis].get();if(!integer(count)||count<0||count>nc) throw std::runtime_error("Invalid positive cluster count");positive=count;}
    for(int j=0;j<positive;j++) {
      fill2(s,inc+"cluster_size_vs_charge",r.ccharge[axis].get(j),r.csize[axis].get(j),w);
      if(!r.clo[axis].p||!r.cseed[axis].p) continue;
      double lo0=r.clo[axis].get(j),sz0=r.csize[axis].get(j),seed0=r.cseed[axis].get(j);
      if(!integer(lo0)||!integer(sz0)||!integer(seed0)||sz0<1) {++s.malformed;continue;}
      int lo=lo0,sz=sz0,seed=seed0;
      auto seedIt=channel[axis].find(seed);if(seedIt==channel[axis].end()||seed<lo||seed>=lo+sz){++s.malformed;continue;}
      std::vector<int> members;double total=0;
      for(auto it=channel[axis].lower_bound(lo);it!=channel[axis].end()&&it->first<lo+sz;++it){members.push_back(it->second);total+=r.charge.get(it->second);}
      if(int(members.size())!=sz||!std::isfinite(total)||total<=x.c.mincharge){++s.malformed;continue;}
      int si=seedIt->second;
      for(int i:members) {
        int distance=std::lround(r.strip.get(i))-seed;
        fill2(s,inc+"neighbor_fraction",distance,r.charge.get(i)/total,w);
        if(r.time.p) fill2(s,inc+"neighbor_dt",distance,r.time.get(i)-r.time.get(si),w);
        if(r.samples.p) {
          double ax=0,ay=0,xx=0,yy=0,xy=0;
          for(int k=0;k<6;k++){double u=r.samples.get(6*i+k),v=r.samples.get(6*si+k);ax+=u;ay+=v;xx+=u*u;yy+=v*v;xy+=u*v;}
          double vx=xx-ax*ax/6,vy=yy-ay*ay/6;
          if(vx>0&&vy>0) fill2(s,inc+"neighbor_correlation",distance,std::max(-1.,std::min(1.,(xy-ax*ay/6)/std::sqrt(vx*vy))),w);
        }
      }
    }
  }
}
void pruneUnavailable(Context& x,int d,const Module& r,const string& file) {
  std::vector<string> remove;
  for(auto& item:x.s[d].plots) {
    const auto& n=item.first;const auto& p=item.second;if(p.module!=r.m) continue;
    // Saved objects have h... names; only generated tree names are pruned.
    if(n.find("m"+std::to_string(r.m)+"_")!=0) continue;
    string why;
    if(n.find("_ontrack_")!=string::npos&&(!r.ontrack.p||(x.c.besttrack&&!r.itrack.p))) why="missing track association";
    else if(n.find("_offtrack_")!=string::npos&&!r.ontrack.p) why="missing track association";
    else if(n.find("_full_readout_")!=string::npos&&(!r.build.p||!r.enable.p)) why="missing readout flags";
    else if((n.find("fraction")!=string::npos||n.find("samples")!=string::npos||n.find("sample_correlation")!=string::npos||n.find("peak_")!=string::npos)&&!r.samples.p) why="missing six-sample arrays";
    else if(n.find("rail")!=string::npos&&!r.raw.p) why="missing raw sample arrays";
    else if(n.find("time_")!=string::npos||n.find("neighbor_dt")!=string::npos){if(!r.time.p) why="missing strip time";}
    else if(n.find("width_")!=string::npos&&!r.width.p) why="missing strip time RMS";
    else if(n.find("sum_vs_max")!=string::npos&&!r.adcmax.p) why="missing ADCmax";
    if(n.find("UV_cluster")!=string::npos&&(!r.cn[0].p||!r.cn[1].p)) why="missing cluster counts";
    bool u=n.find("_U_")!=string::npos;int a=u?0:1;
    if(n.find("cluster_size")!=string::npos&&(!r.csize[a].p||!r.ccharge[a].p)) why="missing cluster arrays";
    if(n.find("neighbor_")!=string::npos&&n.find("spacing")==string::npos&&(!r.clo[a].p||!r.cseed[a].p||!r.csize[a].p)) why="missing cluster bounds/seed";
    if(n.find("fraction_chargebin")!=string::npos||n.find("fraction_occupancybin")!=string::npos||n.find("peak_vs_charge_slice")!=string::npos) {
      if(!r.ontrack.p||(x.c.besttrack&&!r.itrack.p)) why="conditional signal proxy requires track association";
      item.second.scope+="; on-track + configured signal cut";
    }
    if(!why.empty()){x.issue(d,file,n,why);remove.push_back(n);}
  }
  for(auto& n:remove) x.s[d].plots.erase(n);
}
void process(Context& x,int d) {
  Sample& s=x.s[d];std::map<string,Moments> moments;int fileindex=0;
  for(const string& path:x.c.files[d]) {
    std::cout<<x.c.label[d]<<": "<<path<<std::endl;
    std::unique_ptr<TFile> file(TFile::Open(path.c_str(),"READ"));
    if(!file||file->IsZombie()) throw std::runtime_error("Cannot open ROOT file: "+path);
    TTree* tree=nullptr;file->GetObject(x.c.tree.c_str(),tree);Long64_t entries=tree?tree->GetEntries():0;
    s.total+=entries;
    // Full-readout marginals always retain their original Decode-time selection.
    for(const auto& spec:x.specs) if(spec.saved||x.c.baseline=="saved")
      importHist(x,d,*file,path,spec.name,spec.module,spec.saved?"Noise":"GUI",spec.scope,entries);
    if(x.c.extensions) for(int m:x.c.modules) {
      const string det=replace(x.c.detector,".","_")+"_m"+std::to_string(m);
      for(auto axis:{string("U"),string("V")}) {
        for(auto prefix:{string("hADCpedsub"+axis+"_allstrips_"),string("hADCs_by_APV_"+axis+"_"),string("hrawADCs_by_APV_"+axis+"_"),string("hCommonModeMean_by_APV_"+axis+"_")}) {
          string name=prefix+det;if(s.plots.count(name)&&fileindex==0) continue;
          // U all-channel histogram is already a catalog entry on every file.
          if(prefix=="hADCpedsubU_allstrips_") continue;
          importHist(x,d,*file,path,name,m,prefix.find("CommonMode")!=string::npos?"Common mode":"Noise","saved original Decode full-readout gate; no tree cuts/weights; ADC stage recorded by object name",entries);
        }
      }
    }
    if(x.c.source=="hist"){fileindex++;continue;}
    if(!tree) throw std::runtime_error("Missing tree "+x.c.tree+" in "+path);
    if(x.c.maxevents>=0&&s.visited>=x.c.maxevents){fileindex++;continue;}
    tree->SetBranchStatus("*",0);
    auto cut=formula(*tree,"event_cut",x.c.cut[d]);auto weight=formula(*tree,"event_weight",x.c.weight[d]);auto sig=formula(*tree,"signal_cut",x.c.signal[d]);
    if(!cut||!weight||!sig) throw std::runtime_error("Invalid event cut/weight/signal expression in "+path);
    std::vector<std::unique_ptr<TTreeFormula>> formulas;std::vector<GuiReader> gui;
    if(x.c.baseline=="tree") for(const auto& spec:x.specs) if(!spec.saved) {
      auto val=formula(*tree,(spec.name+"_value").c_str(),spec.var),sel=formula(*tree,(spec.name+"_cut").c_str(),spec.cut);
      if(!val||!sel){x.issue(d,path,spec.name,"missing branch/invalid .odef expression for tree reconstruction");s.plots.erase(spec.name);continue;}
      if(!s.plots.count(spec.name)) book(s,spec.name,new TH1D(spec.name.c_str(),spec.title.c_str(),spec.bins,spec.lo,spec.hi),"GUI (tree)","configured inclusive cut + .odef cut: "+spec.cut,spec.module);
      gui.push_back({&spec,val.get(),sel.get()});formulas.push_back(std::move(val));formulas.push_back(std::move(sel));
    }
    std::vector<Module> modules;
    for(int m:x.c.modules) {
      Module r;r.m=m;r.prefix=x.c.detector+".m"+std::to_string(m)+".";
      auto l=[&](const string& n){return getLeaf(*tree,r.prefix+n);};
      r.strip=l("strip.istrip");r.isU=l("strip.IsU");r.charge=l("strip.ADCsum");
      if(!r.strip.p||!r.isU.p||!r.charge.p) throw std::runtime_error("Missing required istrip/IsU/ADCsum in "+r.prefix+" in "+path+" (use input_source hist if module branches were not saved)");
      r.samples=l("strip.ADCsamples");r.raw=l("strip.rawADCsamples");r.time=l("strip.Tmean");r.width=l("strip.Tsigma");r.adcmax=l("strip.ADCmax");
      r.ontrack=l("strip.ontrack");r.itrack=l("strip.itrack");r.build=l("strip.BUILD_ALL_SAMPLES");r.enable=l("strip.ENABLE_CM");r.cmgood=l("strip.CM_GOOD");r.mode=l("mc_input_mode");
      for(int a=0;a<2;a++) {
        string axis=a==0?"u":"v";r.cn[a]=l("clust.nclust"+axis);r.csize[a]=l("clust.clust"+axis+"_strips");r.ccharge[a]=l("clust.clust"+axis+"_adc");r.clo[a]=l("clust.clust"+axis+"_istriplo");r.cseed[a]=l("clust.clust"+axis+"_istripmax");
      }
      if(fileindex==0) bookModule(x,d,m);
      pruneUnavailable(x,d,r,path);modules.push_back(r);
    }
    for(Long64_t event=0;event<entries;event++) {
      if(x.c.maxevents>=0&&s.visited>=x.c.maxevents) break;
      if(tree->GetEntry(event)<0) throw std::runtime_error("Tree read error: "+path);
      s.visited++;
      // Match existing macro semantics: event selection evaluates instance 0.
      double accepted=cut->EvalInstance(0);if(!std::isfinite(accepted)) {++s.nonfinite;continue;}if(!accepted) continue;
      double w=weight->EvalInstance(0),signalValue=sig->EvalInstance(0);
      if(!std::isfinite(w)||w<0) throw std::runtime_error("Nonfinite/negative event weight; shape quantiles require nonnegative weights");
      if(!std::isfinite(signalValue)) throw std::runtime_error("Nonfinite signal cut");
      bool signal=signalValue!=0;s.selected++;s.sumw+=w;if(signal){s.signal++;s.signalw+=w;}
      for(auto& g:gui) {
        int n=g.value->GetNdata(),nc=g.cut->GetNdata();
        if(nc!=1&&nc!=n&&n!=0) throw std::runtime_error("GUI variable/cut length mismatch: "+g.spec->name);
        for(int i=0;i<n;i++) if(g.cut->EvalInstance(nc==1?0:i)) fill(s,g.spec->name,g.value->EvalInstance(i),w);
      }
      for(auto& r:modules) {
        if(d==1&&r.mode.p&&x.c.mode[1]!="unspecified"&&integer(number(x.c.mode[1]))&&r.mode.get()!=number(x.c.mode[1]))
          throw std::runtime_error("MC input mode differs from configuration in "+r.prefix);
        processModule(x,d,r,w,signal,fileindex,moments);
      }
      if(event>0&&event%10000==0) std::cout<<"  "<<s.visited<<" visited, "<<s.selected<<" selected\n";
    }fileindex++;
  }
  for(auto& n:x.invalid[d]) s.plots.erase(n);
  for(auto& item:s.plots) if(item.second.group!="GUI"&&item.first.find("h")!=0) {
    auto& p=item.second;p.exposure=s.sumw;p.denominator="sum of weights of selected events";
    if(item.first.find("_ontrack_")!=string::npos){p.exposure=s.signalw;p.denominator="selected events passing configured signal cut (not events with a GEM track)";}
    if(item.first.find("_full_readout_")!=string::npos){p.exposure=0;p.denominator="unavailable: full-readout APVs with zero retained strips have no strip flags; shape only";}
  }
  for(auto& item:moments){auto it=s.plots.find(item.first);if(it!=s.plots.end()) item.second.store(*static_cast<TH2*>(it->second.h.get()));}
}
double visible(const TH1& h) {
  if(h.GetDimension()==1) return h.Integral(1,h.GetNbinsX());
  return static_cast<const TH2&>(h).Integral(1,h.GetNbinsX(),1,h.GetNbinsY());
}
double allbins(const TH1& h) {
  if(h.GetDimension()==1) return h.Integral(0,h.GetNbinsX()+1);
  return static_cast<const TH2&>(h).Integral(0,h.GetNbinsX()+1,0,h.GetNbinsY()+1);
}
std::array<double,3> quantiles(TH1& h) {
  std::array<double,3> q{};double p[3]={.16,.5,.84};if(visible(h)>0) h.GetQuantiles(3,q.data(),p);return q;
}
void derived(Sample& s) {
  std::vector<string> names;for(auto& item:s.plots) if(item.second.h->GetDimension()==2&&item.second.normal!="value") names.push_back(item.first);
  for(const auto& name:names) {
    auto& parent=s.plots.at(name);TH2& h=static_cast<TH2&>(*parent.h);
    string sc=parent.scope+"; Y visible bins only; quantile bands describe spread, not mean uncertainty";
    auto profile=std::unique_ptr<TProfile>(h.ProfileX((name+"_meanY").c_str(),1,h.GetNbinsY()));
    profile->SetDirectory(nullptr);profile->GetYaxis()->SetTitle(h.GetYaxis()->GetTitle());
    auto& p=book(s,name+"_meanY",profile.release(),parent.group+" profiles",sc,parent.module,"value");
    p.denominator="weighted observations in each X bin";
    std::vector<string> tags={"q16Y","medianY","q84Y","core_widthY"};
    if(parent.group=="Noise"||parent.group=="Common mode") {
      tags.push_back("positive_tail_5core");tags.push_back("negative_tail_5core");
    }
    for(auto tag:tags) {
      const string n=name+"_"+tag;
      std::vector<double> e;for(int i=1;i<=h.GetNbinsX()+1;i++) e.push_back(h.GetXaxis()->GetBinLowEdge(i));
      auto* result=new TH1D(n.c_str(),(tag+";"+h.GetXaxis()->GetTitle()+";"+h.GetYaxis()->GetTitle()).c_str(),h.GetNbinsX(),e.data());
      for(int i=1;i<=h.GetNbinsX();i++) {
        std::unique_ptr<TH1D> slice(h.ProjectionY("_temporary_projection",i,i));slice->SetDirectory(nullptr);
        if(visible(*slice)<=0) continue;auto q=quantiles(*slice);
        double value=tag=="q16Y"?q[0]:tag=="medianY"?q[1]:tag=="q84Y"?q[2]:(q[2]-q[0])/2;
        if(tag.find("tail")!=string::npos) {
          double width=(q[2]-q[0])/2,count=0;value=0;
          if(width>0) for(int b=1;b<=slice->GetNbinsX();b++) {
            double position=slice->GetBinCenter(b);
            if((tag=="positive_tail_5core"&&position>q[1]+5*width)||(tag=="negative_tail_5core"&&position<q[1]-5*width)) count+=slice->GetBinContent(b);
          }
          if(width>0)value=count/visible(*slice);
        }
        result->SetBinContent(i,value);result->SetBinError(i,0);
      }result->SetEntries(h.GetEntries());
      if(tag.find("tail")!=string::npos)result->GetYaxis()->SetTitle("Visible-bin tail probability beyond median +/- 5 core widths");
      book(s,n,result,parent.group+" quantiles",sc+(tag.find("tail")!=string::npos?"; signals/background contribute to positive tails; not calibrated noise-sigma units":""),parent.module,"value");
    }
  }
}
void writeIssues(Context& x,const string& prefix) {
  std::ofstream out(prefix+"_issues.csv");out<<"dataset,file,plot,reason\n";
  for(const auto& i:x.issues) out<<csv(i.dataset<0?"both":x.c.label[i.dataset])<<','<<csv(i.file)<<','<<csv(i.plot)<<','<<csv(i.reason)<<'\n';
}
void metadata(Context& x,const string& cfg,const string& prefix,TFile& out) {
  std::ifstream f(cfg);string contents((std::istreambuf_iterator<char>(f)),{});
  out.cd();TNamed config("configuration",contents.c_str());config.Write();
  std::ifstream cat(x.c.catalog);string cattext((std::istreambuf_iterator<char>(cat)),{});TNamed("GUI_catalog",cattext.c_str()).Write();
  string caveats="Saved marginals retain original Decode/.odef gates; no retroactive cuts or weights. Strip arrays are retained after replay ZS. Full_readout tree view uses retained-strip BUILD_ALL_SAMPLES && !ENABLE_CM flags and cannot identify completely empty APVs or distinguish periodic versus CM-error readout. Samples within events/APVs are correlated; ROOT bin errors are not event-bootstrap uncertainties. MC truth arrays are not used. raw_rail is a configurable transport threshold, not proof of hardware saturation. APV groups use physical strip/128; occupancy counts are not divided by an assumed live-channel mask.";
  TNamed notes("interpretation",caveats.c_str());notes.Write();
  std::ofstream j(prefix+"_provenance.json");
  j<<"{\n  \"macro_version\": \"1.0\",\n  \"ROOT_version\": "<<json(gROOT->GetVersion())<<",\n  \"configuration\": "<<json(contents)<<",\n  \"catalog\": "<<json(x.c.catalog)<<",\n  \"notes\": "<<json(caveats)<<",\n  \"datasets\": [\n";
  for(int d=0;d<2;d++) {
    auto& s=x.s[d];auto* dir=out.mkdir(d==0?"data":"mc");dir->cd();
    TParameter<Long64_t>("replay_entries",s.total).Write();TParameter<Long64_t>("visited_entries",s.visited).Write();TParameter<Long64_t>("selected_entries",s.selected).Write();TParameter<double>("selected_sum_weights",s.sumw).Write();
    TParameter<Long64_t>("signal_entries",s.signal).Write();TParameter<Long64_t>("nonfinite_values",s.nonfinite).Write();TParameter<Long64_t>("rejected_cluster_associations",s.malformed).Write();
    j<<"    {\"label\": "<<json(x.c.label[d])<<", \"readout\": "<<json(x.c.mode[d])<<", \"calibration\": "<<json(x.c.calibration[d])<<", \"event_cut\": "<<json(x.c.cut[d])<<", \"signal_cut\": "<<json(x.c.signal[d])<<", \"weight\": "<<json(x.c.weight[d])<<", \"replay_entries\": "<<s.total<<", \"visited\": "<<s.visited<<", \"selected\": "<<s.selected<<", \"sum_weights\": "<<s.sumw<<", \"files\": [";
    for(size_t k=0;k<x.c.files[d].size();k++){if(k) j<<", ";j<<json(x.c.files[d][k]);}j<<"]}"<<(d==0?",":"")<<"\n";
  }j<<"  ],\n  \"charge_edges\": [";for(size_t i=0;i<x.c.charge.size();i++){if(i)j<<',';j<<x.c.charge[i];}
  j<<"],\n  \"occupancy_edges\": [";for(size_t i=0;i<x.c.occupancy.size();i++){if(i)j<<',';j<<x.c.occupancy[i];}j<<"]\n}\n";
  out.cd();
}
void summary(Context& x,const string& prefix) {
  std::ofstream out(prefix+"_summary.csv");out<<std::setprecision(12);
  out<<"dataset,plot,group,module,status,entries,sum_weights_visible,sum_weights_all,flow_fraction,mean_x,rms_x,q16,median,q84,core_width,exposure,denominator,scope\n";
  for(int d=0;d<2;d++) for(auto& item:x.s[d].plots) {
    Plot& p=item.second;TH1& h=*p.h;double v=visible(h),a=allbins(h);bool value=p.normal=="value";
    out<<csv(x.c.label[d])<<','<<csv(item.first)<<','<<csv(p.group)<<','<<p.module<<','<<csv((value?h.GetEntries()>0:a>0)?"ok":"empty")<<','<<h.GetEntries()<<',';
    if(!value) out<<v<<','<<a<<','<<(a>0?(a-v)/a:0);else out<<",,";
    out<<','<<h.GetMean()<<','<<h.GetStdDev()<<',';
    if(h.GetDimension()==1&&!value&&v>0){auto q=quantiles(h);out<<q[0]<<','<<q[1]<<','<<q[2]<<','<<(q[2]-q[0])/2;}else out<<",,,";
    out<<','<<p.exposure<<','<<csv(p.denominator)<<','<<csv(p.scope)<<'\n';
  }
}
struct Display {
  std::unique_ptr<TH1> h[2]; //! transient drawing ownership; no ROOT streaming
  std::unique_ptr<TH1> ratio,mask;
  string name,group,scope;int module=-1;bool value=false,comparable=false;
};
std::unique_ptr<TH1> emptyRatio(const TH1& h,const string& name) {
  if(dynamic_cast<const TProfile*>(&h)) {
    std::vector<double> e;for(int i=1;i<=h.GetNbinsX()+1;i++)e.push_back(h.GetXaxis()->GetBinLowEdge(i));
    auto p=std::unique_ptr<TH1>(new TH1D(name.c_str(),h.GetTitle(),h.GetNbinsX(),e.data()));p->SetDirectory(nullptr);if(p->GetSumw2N()==0)p->Sumw2();return p;
  }
  auto p=clone(h,name);p->Reset();return p;
}
std::vector<Display> writePlots(Context& x,TFile& output,const string& prefix) {
  std::set<string> names;for(int d=0;d<2;d++) for(auto& p:x.s[d].plots) names.insert(p.first);
  std::vector<Display> displays;std::ofstream differences(prefix+"_differences.csv");
  differences<<"plot,status,median_data_minus_mc,core_width_data_over_mc,shape_L1,notes\n";
  auto* rd=output.GetDirectory("data");auto* rm=output.GetDirectory("mc");
  TDirectory* raw[2]={rd->mkdir("raw"),rm->mkdir("raw")};
  TDirectory* shape[2]={rd->mkdir("shape"),rm->mkdir("shape")};
  TDirectory* yield[2]={rd->mkdir("per_event"),rm->mkdir("per_event")};
  auto* ratios=output.mkdir("ratios");auto* masks=output.mkdir("ratio_valid_masks");auto* md=output.mkdir("plot_metadata");
  for(auto& n:names) {
    Display v;v.name=n;
    for(int d=0;d<2;d++) {
      auto it=x.s[d].plots.find(n);if(it==x.s[d].plots.end()) continue;
      Plot& p=it->second;v.group=p.group;v.module=p.module;v.scope=p.scope;v.value=p.normal=="value";
      raw[d]->cd();p.h->Write(n.c_str());
      v.h[d]=clone(*p.h,n+"_display");double integral=visible(*p.h);
      if(!v.value&&integral>0) v.h[d]->Scale(1./integral,"width");
      if(!v.value) {
        if(v.h[d]->GetDimension()==1)v.h[d]->GetYaxis()->SetTitle("Probability density");
        else v.h[d]->GetZaxis()->SetTitle("Probability density");
      }
      shape[d]->cd();v.h[d]->Write(n.c_str());
      if(!v.value&&p.exposure>0) {auto rate=clone(*p.h,n+"_rate");rate->Scale(1./p.exposure);yield[d]->cd();rate->Write(n.c_str());}
      md->cd();TNamed((string(d==0?"data_":"mc_")+n).c_str(),(p.scope+"; display="+p.normal+"; rate denominator="+p.denominator+"; exposure="+std::to_string(p.exposure)).c_str()).Write();
    }
    v.comparable=v.h[0]&&v.h[1]&&compatible(*v.h[0],*v.h[1]);
    if(v.h[0]&&v.h[1]&&!v.comparable) x.issue(-1,"",n,"data/MC histogram bins or classes differ; ratio skipped");
    if(v.comparable) {
      v.ratio=emptyRatio(*v.h[0],n+"_ratio");v.mask=emptyRatio(*v.h[0],n+"_valid");
      for(int b=0;b<v.ratio->GetNcells();b++) {
        double a=v.h[0]->GetBinContent(b),z=v.h[1]->GetBinContent(b);
        if(z==0||!std::isfinite(a)||!std::isfinite(z)) continue;
        double ea=v.h[0]->GetBinError(b),ez=v.h[1]->GetBinError(b);
        v.ratio->SetBinContent(b,a/z);v.ratio->SetBinError(b,std::hypot(ea/z,a*ez/(z*z)));v.mask->SetBinContent(b,1);
      }ratios->cd();v.ratio->Write(n.c_str());masks->cd();v.mask->Write(n.c_str());
    }
    bool populated=v.comparable&&(v.value?(v.h[0]->GetEntries()>0&&v.h[1]->GetEntries()>0):(visible(*v.h[0])>0&&visible(*v.h[1])>0));
    differences<<csv(n)<<','<<csv(!v.comparable?"missing_or_incompatible":!populated?"empty":"ok")<<',';
    if(v.comparable&&!v.value&&v.h[0]->GetDimension()==1&&visible(*v.h[0])>0&&visible(*v.h[1])>0) {
      auto q0=quantiles(*x.s[0].plots.at(n).h),q1=quantiles(*x.s[1].plots.at(n).h);
      double width1=q1[2]-q1[0],l1=0;
      for(int b=1;b<=v.h[0]->GetNbinsX();b++) l1+=std::abs(v.h[0]->GetBinContent(b)-v.h[1]->GetBinContent(b))*v.h[0]->GetBinWidth(b);
      differences<<q0[1]-q1[1]<<',';if(width1>0) differences<<(q0[2]-q0[0])/width1;differences<<','<<l1;
    }else differences<<",,";
    differences<<','<<csv("Effect sizes only; correlated entries; no automatic simulator diagnosis")<<'\n';
    displays.push_back(std::move(v));
  }return displays;
}
void text(double y,const string& msg,double size=.027) {TLatex t;t.SetNDC();t.SetTextSize(size);t.DrawLatex(.06,y,msg.c_str());}
void draw(Display& v,const Config& c) {
  auto* parent=static_cast<TPad*>(gPad);bool dim2=(v.h[0]?v.h[0]->GetDimension():v.h[1]->GetDimension())==2;
  for(int d=0;d<2;d++) if(v.h[d]) v.h[d]->SetTitle(v.name.c_str());
  if(dim2) {
    parent->Divide(2,1);double max=0;for(int d=0;d<2;d++) if(v.h[d])max=std::max(max,v.h[d]->GetMaximum());
    for(int d=0;d<2;d++) {
      parent->cd(d+1);gPad->SetRightMargin(.17);gPad->SetLeftMargin(.16);gPad->SetBottomMargin(.14);gPad->SetTopMargin(.15);
      if(v.h[d]){v.h[d]->SetMaximum(max>0?max:1);v.h[d]->GetYaxis()->CenterTitle();v.h[d]->GetYaxis()->SetTitleOffset(1.8);v.h[d]->GetYaxis()->SetLabelSize(.028);v.h[d]->GetYaxis()->SetTitleSize(.033);v.h[d]->Draw("COLZ");text(.88,c.label[d],.027);}
      else text(.5,c.label[d]+": unavailable",.05);
    }
    return;
  }
  parent->Divide(1,2);auto* top=static_cast<TPad*>(parent->GetPad(1));auto* bottom=static_cast<TPad*>(parent->GetPad(2));
  top->SetPad(0,.27,1,1);bottom->SetPad(0,0,1,.27);top->cd();top->SetBottomMargin(.12);
  const bool logADC=v.name.find("hADCpedsubU_allstrips_")==0||v.name.find("hADCpedsubV_allstrips_")==0;
  top->SetLogy(logADC);bottom->SetLogy(0);
  double max=0,minPositive=std::numeric_limits<double>::infinity();
  for(int d=0;d<2;d++) if(v.h[d]) {
    max=std::max(max,v.h[d]->GetMaximum());
    if(logADC)for(int b=1;b<=v.h[d]->GetNbinsX();b++) {
      double value=v.h[d]->GetBinContent(b);
      if(value>0)minPositive=std::min(minPositive,value);
    }
  }
  bool first=true;TLegend leg(.64,.70,.94,.87);leg.SetBorderSize(0);
  for(int d=0;d<2;d++) if(v.h[d]) {
    auto& h=*v.h[d];h.SetLineColor(d==0?kBlack:kRed+1);h.SetMarkerColor(d==0?kBlack:kRed+1);h.SetMarkerStyle(d==0?20:24);h.SetMarkerSize(.4);h.GetYaxis()->CenterTitle();h.GetYaxis()->SetTitleOffset(1.5);
    if(logADC)h.SetMinimum(std::isfinite(minPositive)?minPositive*.5:1e-6);
    h.SetMaximum(max>0?max*(logADC?3:1.2):1);h.Draw(first?"HIST E":"HIST E SAME");leg.AddEntry(&h,c.label[d].c_str(),"l");first=false;
  }leg.DrawClone();text(.04,v.value?"Value/profile (not area normalized)":"Unit-area density; flow bins excluded",.025);
  bottom->cd();bottom->SetBottomMargin(.28);bottom->SetTopMargin(.04);
  if(v.ratio){
    TGraphErrors points;double low=0,high=2;
    for(int b=1;b<=v.ratio->GetNbinsX();b++) if(v.mask->GetBinContent(b)>0) {
      double value=v.ratio->GetBinContent(b);int i=points.GetN();points.SetPoint(i,v.ratio->GetBinCenter(b),value);points.SetPointError(i,0,v.ratio->GetBinError(b));
      low=std::min(low,value*1.15);high=std::max(high,value*1.15);
    }
    v.ratio->SetTitle("");v.ratio->GetYaxis()->SetTitle("Data / MC");v.ratio->GetYaxis()->SetTitleSize(.10);v.ratio->GetYaxis()->SetLabelSize(.08);v.ratio->GetXaxis()->SetLabelSize(.10);v.ratio->GetXaxis()->SetTitleSize(.10);v.ratio->SetMinimum(low);v.ratio->SetMaximum(high);v.ratio->Draw("AXIS");
    points.SetMarkerStyle(20);points.SetMarkerSize(.35);points.SetLineColor(kBlack);points.DrawClone("P E SAME");
    TLine line(v.ratio->GetXaxis()->GetXmin(),1,v.ratio->GetXaxis()->GetXmax(),1);line.SetLineStyle(2);line.DrawClone();
  }
  else text(.5,"Ratio unavailable",.09);
}
void pdf(Context& x,std::vector<Display>& plots,const string& prefix) {
  if(!x.c.pdf) return;std::sort(plots.begin(),plots.end(),[](const Display& a,const Display& b){return std::tie(a.group,a.module,a.name)<std::tie(b.group,b.module,b.name);});
  TCanvas page("gem_compare_canvas","GEM comparison",1600,1100);const string file=prefix+".pdf";page.Print((file+"[").c_str());
  text(.92,"GEM real-data / MC diagnostics",.055);text(.84,x.c.label[0]+" versus "+x.c.label[1],.035);
  text(.77,"Saved histograms: original replay gates; tree plots: configured cuts");
  text(.71,"Full-readout noise: actual sample populations; no arbitrary factor of 100");
  text(.65,"Tree strip arrays: retained after ZS, including type-3 MC");
  text(.59,"Raw counts, profiles, quantiles and masks are preserved in ROOT output");
  text(.53,"Readout flag view cannot distinguish periodic from CM-error full readout");
  text(.47,"Histogram bin errors do not include within-event/APV correlations");
  text(.41,"Detailed prerequisites and skipped plots: *_issues.csv and README");
  text(.35,"PDF module filter: "+std::to_string(x.c.pdfmodule)+" (-1 = all); ROOT output includes every configured module");
  page.Print(file.c_str());int pages=1,count=0;string group;
  if(x.c.pdfpages>0&&pages>=x.c.pdfpages){page.Print((file+"]").c_str());return;}
  for(auto& v:plots) {
    if(x.c.pdfmodule>=0&&v.module!=x.c.pdfmodule) continue;
    // Keep quantile bounds in ROOT/CSV; PDF shows medians and core widths.
    if(v.name.find("_q16Y")!=string::npos||v.name.find("_q84Y")!=string::npos) continue;
    if(count==4||(!group.empty()&&v.group!=group)) {if(pages==1){page.Update();page.Print((prefix+"_preview.png").c_str());}page.Print(file.c_str());pages++;count=0;if(x.c.pdfpages>0&&pages>=x.c.pdfpages)break;}
    if(count==0){page.Clear();page.Divide(2,2);group=v.group;}
    page.cd(++count);draw(v,x.c);
  }
  if(count>0&&(x.c.pdfpages==0||pages<x.c.pdfpages)){if(pages==1){page.Update();page.Print((prefix+"_preview.png").c_str());}page.Print(file.c_str());}page.Print((file+"]").c_str());
}
} // namespace GEMCompare

void GEM_lowlevel_data_MC_compare(const char* config="compare_ft.cfg",const char* output_prefix="gem_lowlevel_compare") {
  using namespace GEMCompare;
  Context x;string prefix=output_prefix;bool previous=TH1::AddDirectoryStatus();int oldstats=gStyle->GetOptStat();
  TH1::AddDirectory(false);gStyle->SetOptStat(0);
  try {
    x.c=readConfig(config);x.specs=readCatalog(x.c);
    TString expanded(prefix);gSystem->ExpandPathName(expanded);prefix=expanded.Data();
    gSystem->mkdir(gSystem->DirName(prefix.c_str()),true);
    char* outputReal=realpath((prefix+".root").c_str(),nullptr);
    if(outputReal){string target=outputReal;free(outputReal);for(int d=0;d<2;d++)for(auto& input:x.c.files[d])if(input==target)throw std::runtime_error("Output ROOT path would overwrite an input: "+target);}
    std::cout<<"Selected GUI catalog entries: "<<x.specs.size()<<std::endl;
    process(x,0);process(x,1);
    for(int d=0;d<2;d++) derived(x.s[d]);
    x.issues.push_back({-1,"","unbiased_noise_covariance","requires paired pre-ZS quiet-channel records; retained strip samples are biased"});
    x.issues.push_back({-1,"","residual_CM_vs_occupancy","requires per-event pre-ZS APV residual measurements, absent from marginal histograms"});
    x.issues.push_back({-1,"","subthreshold_sharing","requires pre-ZS samples; not recoverable from retained strip arrays"});
    x.issues.push_back({-1,"","per_channel_noise_units_and_live_masks","not supplied: calibration/live-mask metadata; no inferred zero-RMS/dead-channel classification"});
    std::unique_ptr<TFile> out(TFile::Open((prefix+".root").c_str(),"RECREATE"));if(!out||out->IsZombie())throw std::runtime_error("Cannot create output ROOT file");
    metadata(x,config,prefix,*out);summary(x,prefix);auto plots=writePlots(x,*out,prefix);writeIssues(x,prefix);out->Close();pdf(x,plots,prefix);
    std::cout<<"Wrote "<<prefix<<".root, PDF (if enabled), summary/differences/issues CSV, and provenance JSON.\n";
    std::cout<<"Data/MC selected entries: "<<x.s[0].selected<<" / "<<x.s[1].selected<<"; issues: "<<x.issues.size()<<". Inspect issues and empty populations before interpretation.\n";
    gSystem->Unlink((prefix+"_ERROR.txt").c_str());
  } catch(const std::exception& e) {
    gSystem->mkdir(gSystem->DirName(prefix.c_str()),true);writeIssues(x,prefix);
    std::ofstream error(prefix+"_ERROR.txt");error<<e.what()<<'\n';error.close();
    TH1::AddDirectory(previous);gStyle->SetOptStat(oldstats);
    throw std::runtime_error(string("GEM comparison failed: ")+e.what());
  }
  TH1::AddDirectory(previous);gStyle->SetOptStat(oldstats);
}
#endif
