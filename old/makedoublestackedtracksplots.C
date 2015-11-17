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
void makedoublestackedtracksplots(  ) {
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
  
  const int nhpc = 4; //number of histograms per canvas
  const int ncanvases = 4;
  const int nstacks = ncanvases;
  THStack *hs[nstacks];
  TCanvas *c[ncanvases];
  TH1F *h[ncanvases][nhpc];
  
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
    int file_data=0; //associate a year with a file
    if(year == 2011) file_data = 0;
    if(year == 2015) file_data = 2;
    int file_MC = file_data+1;//=1 for 2011, =3 for 2015
    int B0;
    TString Bdecay;
    TString branch;
    TString tracktype;
    if(ci%2==0){//every other canvas
      tracktype = "nTracks";
    } else{
      tracktype = "nLongTracks";
    }
    TString cistring = Form("%d",ci);
    cout<<"loop "<<ci<<" indicators and strings created:"<<endl<<"year: "<<year<<endl;
    cout<<"data file: "<<file_data<<endl<<"MC file: "<<file_MC<<endl;

    //create the plots
    placeholder = "c"+cistring;
    placeholder2=yearstring+tracktype;
    c[ci] = new TCanvas(placeholder,placeholder2,1200,800); //create the canvases
    c[ci]->cd();
    gStyle->SetOptStat("");
    TLegend* leg = new TLegend(0.7, 0.7, .97, .93);//declare legend
    placeholder = "hs"+cistring;
    hs[ci] = new THStack(placeholder,"");
    cout<<"starting histogram loop..."<<endl;
    for(int hi=0;hi<nhpc;hi++){ //loop over histograms in a canvas; data,MC for B0=0 then B0=1
      if((int)floor(hi/2)%2 ==0){//alternate sets of 2 histograms
        B0=0;
        Bdecay = "B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}";
        branch="Tuple_b2D0MuX/DecayTree";
      } else{
        B0=1;
        Bdecay = "B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}";
        branch="Tuple_b2DpMuX/DecayTree";
      }
      //create convenient strings
      TString histring = Form("%d",hi);
      TString hname = "h"+cistring+histring;
      
      //create histograms and stack
      if(tracktype=="nTracks") h[ci][hi] = new TH1F(hname,tracktype,104,0,1144);
      if(tracktype=="nLongTracks") h[ci][hi] = new TH1F(hname,tracktype,131,0,262);
      cout<<"histogram loop "<<hi<<" strings and histograms created"<<endl;

      //navigate files
      cout<<"navigating file..."<<endl;
      TTree *MyTree;
      int MC;
      if((hi%2)==0){//alternate data and MC
        MC=0; //indicates data
      } else MC=1; //indicates MC
      if(MC==0){
        if(file_data==0){
          if(B0==0) f[file_data]->GetObject("tupleb2D0Mu/tupleb2D0Mu",MyTree);
          if(B0==1) f[file_data]->GetObject("tupleb2DpMu/tupleb2DpMu",MyTree);
        } else f[file_data]->GetObject(branch,MyTree);
      } else f[file_MC]->GetObject(branch,MyTree);
      //draw histograms
      cout<<"drawing histogram "<<hi<<"..."<<endl;
      h[ci][hi]->SetLineColor(hi+1);
      placeholder = tracktype+">>"+hname;
      MyTree->Draw(placeholder,"","norm");
      cout<<"stacking histogram "<<hi<<"..."<<endl;
      hs[ci]->Add(h[ci][hi]);//stack histograms
      if(MC==0) placeholder = Bdecay+", data";
      if(MC==1) placeholder = Bdecay+", MC";
      leg->AddEntry(h[ci][hi],placeholder,"l");//fill legend
    }
    //draw stacked histograms
    cout<<"drawing stack "<<ci<<"..."<<endl;
    placeholder = yearstring+": "+tracktype;
    hs[ci]->SetTitle(placeholder);
    hs[ci]->Draw("nostack");
    leg->Draw();
    //save stuff:
    cout<<"saving files..."<<endl;
    if(ci==ncanvases-1){//if final canvas
      c[ci]->Print("output/doublestackedtracksplots/doublestackedtracksplots.pdf)");
    } else{
      c[ci]->Print("output/doublestackedtracksplots/doublestackedtracksplots.pdf(");
    }
    placeholder = "output/doublestackedtracksplots/c"+cistring+".C";
    c[ci]->SaveAs(placeholder);
    cout<<endl;
  }
  gROOT->SetBatch(kFALSE);
  cout<<"done"<<endl;
}
