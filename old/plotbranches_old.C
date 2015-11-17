// Include files
#include <vector>
#include <TLegend.h>
#include <TTree.h>
#include "TROOT.h"
#include "TRint.h"
#include <TFile.h>
#include <THStack.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "TVector3.h"
#include "TPaveStats.h"
#include <math.h>
#include <TString.h>

// local


//-----------------------------------------------------------------------------
// Implementation file for class : plotbranches
//
// 2015-10-13 : Michael Wilkinson
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
void plotbranches(TString runmode = "d", TString drawopt = "norm"){
  gROOT->SetBatch(kTRUE);
  cout<<"If you want to use custom parameters, option 'b' for branch, 'c' to include cuts,";
  cout<<" or 'a' for all, including files, years, etc."<<endl;
  cout<<"Option 'C' saves canvases as .C files."<<endl<<endl;
  cout<<"This program handles 4 layers of variation in plots: year, decay, filetype, and branch."<<endl<<endl;
  TString placeholder;//this is to avoid adding strings in functions; assign right before use
  TString placeholder2;
  TString response;//this is for user input; assign right before use
  //------output location-------//
  TString outputlocation;
  TString filename;
  cout<<"Where should the output be stored? (make sure the directory exists; include / at end)"<<endl;
  cin>>outputlocation;
  cout<<"What should the output file be called? (include extension, e.g., 'plots.pdf')"<<endl;
  cin>>filename;
  //default parameters
  int nYears = 2;
  int nFileTypes = 2;
  int nDecays = 2;
  int nFiles = nYears*nDecays*nFileTypes;
  int nBranches = 1;
  vector<TString> year(nYears);
  year[0]="2011";
  year[1]="2015";
  vector<TString> filetype(nFileTypes);
  filetype[0]="data";
  filetype[1]="MC";
  vector<TString> decay(nDecays);
  decay[0]="B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}";
  decay[1]="B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}";
  vector<TFile*> f(nFiles);
  TString tuplelocation = "/afs/cern.ch/work/m/mwilkins/b_b-bar_cross-section/";
  placeholder = tuplelocation+"Strp20r1_SL_D0andDp_MD.root";
  f[0] = TFile::Open(placeholder);//2011 data B-D0                                                              
  placeholder = tuplelocation+"Strp20r1_SL_D0andDp_MD.root";
  f[1] = TFile::Open(placeholder);//2011 data B0D-                                                              
  placeholder = tuplelocation+"Bu_D0Xmunu_cocktail_12873441_MC2011_S20r1_noPID_Tuples.root";
  f[2] = TFile::Open(placeholder);//2011 MC B-D0                                                                
  placeholder = tuplelocation+"Bd_DpXmunu_cocktail_11874401_MC2011_S20r1_noPID_Tuples.root";
  f[3] = TFile::Open(placeholder);//2011 MC B0D-                                                                
  placeholder = tuplelocation+"B2DMuNuX_tuples_05082015.root";
  f[4] = TFile::Open(placeholder);//2015 data B-D0                                                              
  placeholder = tuplelocation+"B2DMuNuX_tuples_05082015.root";
  f[5] = TFile::Open(placeholder);//2015 data B0D-                                                              
  placeholder = tuplelocation+"Bu_D0Xmunu_cocktail_12873441_MC2015_S22_noPID_Tuples.root";
  f[6] = TFile::Open(placeholder);//2015 MC B-D0                                                                
  placeholder = tuplelocation+"Bd_DpXmunu_cocktail_11874401_MC2015_S22_noPID_Tuples.root";
  f[7] = TFile::Open(placeholder);//2015 MC B0D-                                                                
  vector<TString> tree(nFiles);
  tree[0] = "tupleb2D0Mu/tupleb2D0Mu";
  tree[1] = "tupleb2DpMu/tupleb2DpMu";
  tree[2] = "Tuple_b2D0MuX/DecayTree";
  tree[3] = "Tuple_b2DpMuX/DecayTree";
  tree[4] = "Tuple_b2D0MuX/DecayTree";
  tree[5] = "Tuple_b2DpMuX/DecayTree";
  tree[6] = "Tuple_b2D0MuX/DecayTree";
  tree[7] = "Tuple_b2DpMuX/DecayTree";
  vector<TString> branch(nBranches);
  branch[0]="nLongTracks";
  vector<Int_t> nBins(nBranches);
  nBins[0]=131;
  vector<Double_t> loBin(nBranches);
  loBin[0]=0;
  vector<Double_t> hiBin(nBranches);
  hiBin[0]=262;
  vector<TString> cut(nBranches);
  for(int i=0;i<nBranches;i++){
    cut[i]="";
  }
  
  //-----------------------------get custom parameters-----------------------//
  if(runmode.Contains("a")){
    //ask about years
    cout<<"how many years?"<<endl;
    cin>>nYears;
    year.resize(nYears);
    for(int yi=0; yi<nYears; yi++){
      cout<<"Year "<<yi<<"= ";
      cin>>year[yi];
    }
    //ask about decays
    cout<<"how many decays"<<endl;
    cin>>nDecays;
    decay.resize(nDecays);
    cout<<"name your decays (e.g., B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}):"<<endl;
    for(int di=0; di<nDecays; di++){
      cout<<"Decay "<<di<<"= ";
      cin>>decay[di];
    }
    //ask about file types
    cout<<"how many file types?"<<endl;
    cin>>nFileTypes;
    while(!(nFileTypes>0&&nFileTypes<=2)){
      cout<<endl<<"1 or 2?"<<endl;
      cin>>nFileTypes;
    }
    filetype.resize(nFileTypes);
    if(nFileTypes==2){
      while(!(response=="data"||response=="MC")){
        cout<<"data or MC first?"<<endl;
        cin>>response;
      }
      if(response=="MC"){
        filetype[0]="MC";
        filetype[1]="data";
      }
      if(response=="data"){
        filetype[0]="data";
        filetype[1]="MC";
      }
    }
    if(nFileTypes==1){
      filetype[0]="";
      while(!(filetype[0]=="data"||filetype[0]=="MC")){
        cout<<"data or MC?"<<endl;
        cin>>filetype[0];
      }
    }
    //ask for files
    nFiles=nYears*nFileTypes*nDecays;
    f.resize(nFiles);
    int fi=0;
    for(int yi=0; yi<nYears; yi++){
      for(int fti=0; fti<nFileTypes; fti++){
        for(int di=0; di<nDecays; di++){
          cout<<"File "<<fi<<" is for year "<<year[yi]<<", "<<filetype[fti]<<", "<<decay[di]<<endl;
          cout<<"where is it located? (e.g.,'~/folder/file.root')"<<endl;
          cin>>response;
          f[fi]=TFile::Open(response);
          fi++;
        }
      }
    }
    if(fi!=(nFiles)){
      cout<<"fi = "<<fi<<" and nFiles = "<<nFiles<<". Something is wrong with the code."<<endl;
    }
    //ask for specific trees (AKA decays)
    cout<<"Specify the folder and tree for your decay, e.g., 'Tuple_b2D0MuX/DecayTree':"<<endl;
    tree.resize(nFiles);
    for(int ti=0; ti<nFiles; ti++){
      cout<<"File "<<ti<<"has tree ";
      cin>>tree[ti];
    }
  }
  if(runmode.Contains("b")||runmode.Contains("a")){ //ask for branches
    cout<<"how many branches?"<<endl;
    cin>>nBranches;
    branch.resize(nBranches);
    cout<<"what are the names of the branches you want to draw?"<<endl;
    for(int bi=0; bi<nBranches; bi++){
      cout<<"branch "<<bi<<"= ";
      cin>>branch[bi];
      cout<<"Recommend:"<<endl;
      cout<<"nLongTracks: '131','0','262'"<<endl;
      cout<<"nTracks: '104','0','1144'"<<endl;
      cout<<"nBins = ";
      cin>>nBins[bi];
      cout<<"loBin = ";
      cin>>loBin[bi];
      cout<<"hiBin = ";
      cin>>hiBin[bi];
      cout<<endl;
    }
  }
  if(runmode.Contains("c")||runmode.Contains("a")){ //ask for cuts
    cout<<"what cuts would you like to make?"<<endl;
    for(int bi=0; bi<nBranches; bi++){
      cout<<"for branch "<<branch[bi]<<": "<<endl;
      cin>>cut[bi];
    }
  }
    
  //-------done getting custom parameters------//
  vector<TString> L[4];//used to sort year, decay, etc. into a hierarchy
  int nL[4];//lengths of the vectors in L[]
  TString Lresponse[4];//holds names of vectors in L[] as strings
  int nComparisons=-1000;
  cout<<"We can compare year, decay, filetype, and branch in a plot."<<endl<<"how many of these should be in a single plot? ";
  while(!(nComparisons>=0&&nComparisons<=4)){
    cout<<"0, 1, 2, 3, or 4?"<<endl;
    cin>>nComparisons;
  }
  vector<TString> comparison(nComparisons);//filled before canvas loop
  //-----what are we comparing?------//
  if(nComparisons>0) cout<<"Which are we comparing?"<<endl;
  for(int coi =0; coi<nComparisons; coi++){
    if(coi>0) cout<<"and"<<endl;
    cin>>comparison[coi];
    while(!(comparison[coi]=="year"||comparison[coi]=="decay"||comparison[coi]=="filetype"||comparison[coi]=="branch")){
      cout<<"year, decay, filetype, or branch?"<<endl;
      cin>>comparison[coi];
    }
    if(coi>0){
      while(comparison[coi]==comparison[coi-1]){
        cout<<"each response must be different"<<endl;
        cin>>comparison[coi];
      }
    }
    Lresponse[3-coi]=comparison[coi];//whatever you're comparing first is the lowest hierarchy
  }
  //---------establish hierarchy for non-compared things--------------//
  for(int i=0;i<(4-nComparisons);i++){
    Lresponse[i]="";
    while(!(Lresponse[i]=="year"||Lresponse[i]=="decay"||Lresponse[i]=="filetype"||Lresponse[i]=="branch")){
      cout<<"possible choices are 'year', 'decay', 'filetype', and 'branch'"<<endl;
      cout<<"thing to loop over #"<<i<<":"<<endl;
      cin>>Lresponse[i];
    }
    if(i>0){//make sure the last thing typed isn't the same as the one before
      while(Lresponse[i]==Lresponse[i-1]){
        cout<<"each response must be different"<<endl;
        cin>>Lresponse[i];
      }
    }
  }
  //------check that all levels are unique------//
  bool yes=kTRUE;//do any Lresponse[i] match any other?
  while(yes==kTRUE){
    yes=kFALSE;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(i!=j){
          while(Lresponse[i]==Lresponse[j]){
            yes=kTRUE;
            cout<<"all 4 levels must be unique"<<endl;
            cout<<"you entered "<<Lresponse[i]<<" for both level "<<i<<" and level "<<j<<endl;
            cout<<"please change "<<Lresponse[i]<<" to something unique or your output won't make sense"<<endl;
            cout<<"what would you like level "<<i<<" to be?"<<endl;
            cin>>Lresponse[i];
          }
        }
      }
    }
  }
  //------use repsonses to assign appropriate vectors to L[i]----//
  for(int i=0;i<4;i++){
    if(Lresponse[i]=="year") L[i]=year;
    if(Lresponse[i]=="decay") L[i]=decay;
    if(Lresponse[i]=="filetype") L[i]=filetype;
    if(Lresponse[i]=="branch") L[i]=branch;
    nL[i]=L[i].size();//and find their sizes
  }
  //------all parameters have been set-------//
  //------------------------------------canvas loop-----------------------------//
  //create necessary counters, canvases, legends, etc.
  cout<<endl;
  int nhpc = 1;
  for(int i=0; i<nComparisons; i++){
    if(comparison[i]=="year") nhpc*=nYears;
    if(comparison[i]=="decay") nhpc*=nDecays;
    if(comparison[i]=="filetype") nhpc*=nFileTypes;
    if(comparison[i]=="branch") nhpc*=nBranches;
  }
  int nCanvases = nYears*nDecays*nFileTypes*nBranches/nhpc;
  vector<TCanvas*> c(nCanvases);//each canvas holds one stack of histograms
  vector<TLegend*> leg(nCanvases);//one legend per canvas
  vector<THStack*> hs(nCanvases);//one stack per canvas
  vector< vector<TH1F*> > h;
  h.resize(nCanvases, vector<TH1F*>(nhpc));
  TCanvas *cf = new TCanvas("cf","combined");//canvas to hold everything
  float sqnc = sqrt(nCanvases), sqncu = ceil(sqnc), sqncd = floor(sqnc);
  while(sqncu*sqncd<nCanvases) sqncu++;
  cf->Divide(sqncu,sqncd);//canvas divided to be able to hold all other canvases
  TLegend *legf = new TLegend(0.84, 0.84, .99, .95);//legend for cf
  int Li[4];//counters to help with hierarchy in the loop; L[i][Li[i]] refers to the Lith element of the ith hierarchical element
  for(int i=0;i<4;i++){
    Li[i]=0;//initialize all elements to 0
  }
  int plL[4]; //products of things in lower levels to tell when to increment Lii
  for(int i=0;i<4;i++){
    plL[i]=1;//initialize all elements to 1
  }
  for(int i=0; i<4; i++){
    for(int j=3; j>i; j--){
      plL[i]*=nL[j];//find the products
    }
  }
  int yi=0, di=0, fti=0, bi=0;//these correspond to the Li[] counters but maybe work in situations Li[] don't
  int pli=0;//this counts the number of plots generated; helps iterate Li[i]
  
  cout<<"starting canvas loop..."<<endl;
  //actual start of the loop
  for(int ci=0; ci<nCanvases; ci++){
    cout<<ci<<" out of "<<nCanvases<<endl;

    //create necessary canvasy things
    TString cistring = Form("%d",ci);
    placeholder = "c"+cistring;
    c[ci] = new TCanvas(placeholder,placeholder,1200,800); //create the canvases
    c[ci]->cd();
    gStyle->SetOptStat("");
    leg[ci] = new TLegend(0.7, 0.7, .97, .93);//create legend
    placeholder = "hs"+cistring;
    hs[ci] = new THStack(placeholder,placeholder); //create the stack to hold the histograms
    TString stacktitle="";

    //histogram loop
    for(int hi=0; hi<nhpc; hi++){
      int file_num=yi*nDecays*nFileTypes+fti*nDecays+di;
      
      //create convenient strings
      TString histring = Form("%d",hi);
      TString hname = "h"+cistring+histring;
      //create histograms
      h[ci][hi] = new TH1F(hname,branch[bi],nBins[bi],loBin[bi],hiBin[bi]);
      cout<<"histogram loop "<<hi<<" strings and histograms created"<<endl;
      cout<<"using file "<<file_num<<endl;
      //navigate files
      cout<<"navigating file..."<<endl;
      TTree *MyTree;
      f[file_num]->GetObject(tree[file_num],MyTree);
      //draw histograms
      cout<<"drawing histogram "<<hi<<"..."<<endl;
      h[ci][hi]->SetLineColor(hi+1);
      placeholder = branch[bi]+">>"+hname;
      MyTree->Draw(placeholder,cut[bi],drawopt);
      pli++;
      cout<<"stacking histogram "<<hi<<"..."<<endl;
      hs[ci]->Add(h[ci][hi]);//stack histograms
      TString leglabel="";
      for(int i=0;i<4;i++){//loop over hierarchy levels
        //determine the name of the stack title
        bool yes=kFALSE;
        for(int j=0;j<nComparisons;j++) if(Lresponse[i]==comparison[j]) yes=kTRUE;//is this hierarchy level being compared?
        if(yes==kTRUE){//if it is, we want it in the legend entry
          if(leglabel!="") leglabel+=", ";
          if(Lresponse[i]=="year") leglabel+=year[yi];
          if(Lresponse[i]=="decay") leglabel+=decay[di];
          if(Lresponse[i]=="filetype") leglabel+=filetype[fti];
          if(Lresponse[i]=="branch") leglabel+=branch[bi];
        }
        if(hi==0){//since stacktitle reflects non-compared hierarchy levels, it only needs to change per canvas
          if(yes==kFALSE){//if it's not, we want it in the title
            if(stacktitle!="") stacktitle+=": ";
            if(Lresponse[i]=="year") stacktitle+=year[yi];
            if(Lresponse[i]=="decay") stacktitle+=decay[di];
            if(Lresponse[i]=="filetype") stacktitle+=filetype[fti];
            if(Lresponse[i]=="branch") stacktitle+=branch[bi];
          }
        }

        //iterate hierarchy counters
        if(plL[i]==1){Li[i]++;//if it's at the lowest hierarchy, iterate
        }else{ if((pli%plL[i]==0)&&(pli!=0))Li[i]++;}//if all variations of plots lower than it have been plotted, iterate
        if(Li[i]==nL[i]) Li[i]=0;
        if(Lresponse[i]=="year") yi=Li[i];
        if(Lresponse[i]=="decay") di=Li[i];
        if(Lresponse[i]=="filetype") fti=Li[i];
        if(Lresponse[i]=="branch") bi=Li[i];
      }
      leg[ci]->AddEntry(h[ci][hi],leglabel,"l");//fill legend
      if(ci==0) legf->AddEntry(h[ci][hi],leglabel,"l");//fill combined legend (each canvas has the same legend)
    }//end histogram loop

    //draw stacked histograms
    cout<<"drawing stack "<<ci<<": "<<stacktitle<<"..."<<endl;
    hs[ci]->SetTitle(stacktitle);
    hs[ci]->Draw("nostack");
    if(nComparisons>0) leg[ci]->Draw();
    cf->cd(ci+1);
    hs[ci]->Draw("nostack");//not using c[ci]->DrawClonePad(); because too many legends
    //save stuff:
    cout<<"saving files..."<<endl;
    placeholder = outputlocation+filename+"(";//the closing page is added after the loop
    c[ci]->Print(placeholder);
    if(runmode.Contains("C")){
      placeholder = outputlocation+"c"+cistring+"_"+stacktitle+".C";
      c[ci]->SaveAs(placeholder);
    }
    cout<<endl;
  }//end canvas loop
  cf->cd();
  if(nComparisons>0) legf->Draw();
  placeholder = outputlocation+filename+")";
  cf->Print(placeholder);
  for(int i=0;i<nBranches;i++) if(cut[bi]!="") cout<<"branch "<<branch[bi]<<" had cuts: "<<cut[bi]<<endl;
  gROOT->SetBatch(kFALSE);
  cout<<"done"<<endl;
}
  
