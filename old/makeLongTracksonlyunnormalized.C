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
//-----------------------------------------------------------------------------
// Implementation file for class : maketracksplots
//
// 2015-10-08 : Michael Wilkinson
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
void makeLongTracksonlyunnormalized(  ) {
  gROOT->SetBatch(kTRUE);
  TString tuplelocation = "/afs/cern.ch/work/m/mwilkins/b_b-bar_cross-section/";
  TString data2011tuple = tuplelocation+"Strp20r1_SL_D0andDp_MD.root";
  TString MC2011tuple = tuplelocation+"MC_2011_Bu_D0Xmunu_cocktail_12873441_MC2011_S20r1_noPID_Tuples.root";
  TString data2015tuple = tuplelocation+"B2DMuNuX_tuples_05082015.root";
  TString MC2015tuple = tuplelocation+"MC_2015_Bu_D0Xmunu_cocktail_12873441_MC2015_S22_noPID_Tuples.root";
  TFile *f[4];
  f[0] = TFile::Open(data2011tuple);
  f[1] = TFile::Open(MC2011tuple);
  f[2] = TFile::Open(data2015tuple);
  f[3] = TFile::Open(MC2015tuple);
  cout<<"files opened"<<endl;
  
  const int nhpc = 2; //number of histograms per canvas
  const int ncanvases = 4;
  const int nstacks = ncanvases;
  THStack *hs[nstacks];
  TCanvas *c[ncanvases];
  TH1F *h[ncanvases][nhpc];
  TLegend *leg[ncanvases];
  TString outputlocation = "output/longtracksplotsunnormalized/";//where the output will be saved
  TString plotfilename = "longtracksplotsunnormalized.pdf";//name of file that will hold drawn plots

  TCanvas *cf = new TCanvas("cf","combined");//canvas to hold everything
  float sqnc = sqrt(ncanvases), sqncu = ceil(sqnc), sqncd = floor(sqnc);
  while(sqncu*sqncd<ncanvases) sqncu++;
  cf->Divide(sqncu,sqncd);
  TLegend *legf = new TLegend(0.84, 0.84, .99, .95);

  TString placeholder; //to avoid adding strings within functions; assign immediately before use
  TString placeholder2;
  
  cout<<"starting canvas loop..."<<endl;
  for(int ci =0; ci<ncanvases; ci++){ //loop over canvases
    //create indicators and strings:
    int year;
    if(ci<(ncanvases/2)){//2011 for 1st half canvases, 2015 for 2nd half
      year = 2011;
    }else year = 2015;
    TString yearstring = Form("%d",year);
    TString filetype; //assigned in histogram loop
    TString tracktype = "nLongTracks";
    int B0;//assigned in histogram loop
    TString Bdecay;
    TString branch;

    TString cistring = Form("%d",ci);
    cout<<"loop "<<ci<<" indicators and strings created:"<<endl<<"year: "<<year<<endl;

    //create the plots
    placeholder = "c"+cistring;
    placeholder2=yearstring+filetype+tracktype;
    c[ci] = new TCanvas(placeholder,placeholder2,1200,800); //create the canvases
    c[ci]->cd();
    gStyle->SetOptStat("");
    leg[ci] = new TLegend(0.7, 0.7, .97, .93);//create legend
    placeholder = "hs"+cistring;
    hs[ci] = new THStack(placeholder,placeholder2); //create the stack to hold the histograms
    cout<<"starting histogram loop..."<<endl;
    for(int hi=0;hi<nhpc;hi++){ //loop over histograms in a canvas; B0=0 and B0=1
      if(hi%2==0){//true every other histogram
        filetype = "data";
      }else filetype = "MC";
      int file_num=-1000;//assign file_num based on combinations of data and MC
      if(year==2011){
        if(filetype=="data") file_num=0;
        if(filetype=="MC") file_num=1;
      }
      if(year==2015){
        if(filetype=="data") file_num=2;
        if(filetype=="MC") file_num=3;
      }
      cout<<"file_num: "<<file_num<<endl;
      if(ci%2 ==0){//every other canvas
        B0=0;
        Bdecay = "B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}";
        if((filetype=="data")&&(year==2011)){
          branch="tupleb2D0Mu/tupleb2D0Mu"; 
        } else branch="Tuple_b2D0MuX/DecayTree"; 
      } else{
        B0=1;
        Bdecay = "B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}";
        if((filetype=="data")&&(year==2011)){
          branch="tupleb2DpMu/tupleb2DpMu"; 
        } else branch="Tuple_b2DpMuX/DecayTree"; 
      }
      //create convenient strings
      TString histring = Form("%d",hi);
      TString hname = "h"+cistring+histring;
      
      //create histograms
      if(tracktype=="nLongTracks") h[ci][hi] = new TH1F(hname,tracktype,131,0,262);
      cout<<"histogram loop "<<hi<<" strings and histograms created"<<endl;
      //navigate files
      cout<<"navigating file..."<<endl;
      TTree *MyTree;
      f[file_num]->GetObject(branch,MyTree);
      //draw histograms
      cout<<"drawing histogram "<<hi<<"..."<<endl;
      cout<<"branch: "<<branch<<endl;
      h[ci][hi]->SetLineColor(hi+1);
      placeholder = tracktype+">>"+hname;
      MyTree->Draw(placeholder);
      cout<<"stacking histogram "<<hi<<"..."<<endl;
      hs[ci]->Add(h[ci][hi]);//stack histograms
      leg[ci]->AddEntry(h[ci][hi],filetype,"l");//fill legend
      if(ci==0) legf->AddEntry(h[ci][hi],filetype,"l");//fill combined legend; all the same, so using the first one is fine
    }
    //draw stacked histograms
    cout<<"drawing stack "<<ci<<"..."<<endl;
    placeholder = yearstring+": "+Bdecay+": "+tracktype;
    hs[ci]->SetTitle(placeholder);
    hs[ci]->Draw("nostack");
    leg[ci]->Draw();
    cf->cd(ci+1);
    hs[ci]->Draw("nostack");//not using c[ci]->DrawClonePad(); because too many legends
    //save stuff:
    cout<<"saving files..."<<endl;
    placeholder = outputlocation+plotfilename+"(";//the closing page is added after the loop
    c[ci]->Print(placeholder);
    placeholder = outputlocation+"c"+cistring+".C";
    c[ci]->SaveAs(placeholder);
    cout<<endl;
  }
  cf->cd();
  legf->Draw();
  placeholder = outputlocation+plotfilename+")";
  cf->Print(placeholder);
  gROOT->SetBatch(kFALSE);
  cout<<"done"<<endl;
}
