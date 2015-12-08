//-----------------------------------------------------------------------------
// Implementation file for class : maketracksplots
//
// 2015-10-07 : Michael Wilkinson
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
void maketracksplots(  ) {
  gROOT->SetBatch(kTRUE);
  TFile *f1 = TFile::Open("/afs/cern.ch/work/m/mwilkins//Strp20r1_SL_D0andDp_MD.root");
  TFile *f2 = TFile::Open("/afs/cern.ch/work/m/mwilkins//MC_2011_Bd_D0Xmunu_cocktail_Tuples.root");
  TFile *f3 = TFile::Open("/afs/cern.ch/work/m/mwilkins//B2DMuNuX_tuples_05082015.root");
  TFile *f4 = TFile::Open("/afs/cern.ch/work/m/mwilkins//MC_2015_Bu_D0Xmunu_cocktail_12873441_MC2015_S22_noPID_Tuples.root");

  THStack *hs1 = new THStack("hs1","");
  TCanvas *c1 = new TCanvas("c1","2011nTracks",1200,800);
  gStyle->SetOptStat("");
  f1->cd("tupleb2D0Mu");
  tupleb2D0Mu->Draw("nTracks>>h11","","norm");
  TH1F *h11 = (TH1F*)gPad->GetPrimitive("h11");
  hs1->Add(h11);
  f2->cd("Tuple_b2D0MuX");
  DecayTree->SetLineColor(kRed);
  DecayTree->Draw("nTracks>>h12","","norm");
  TH1F *h12 = (TH1F*)gPad->GetPrimitive("h12");
  hs1->Add(h12);
  hs1->SetTitle("2011: B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}: nTracks");
  hs1->Draw("nostack");
  c1->Print("tracksplots.pdf(");

  THStack *hs2 = new THStack("hs2","");
  TCanvas *c2 = new TCanvas("c2","2011nLongTracks",1200,800);
  gStyle->SetOptStat("");
  f1->cd("tupleb2D0Mu");
  tupleb2D0Mu->Draw("nLongTracks>>h21","","norm");
  TH1F *h21 = (TH1F*)gPad->GetPrimitive("h21");
  hs2->Add(h21);
  f2->cd("Tuple_b2D0MuX");
  DecayTree->SetLineColor(kRed);
  DecayTree->Draw("nLongTracks>>h22","","norm");
  TH1F *h22 = (TH1F*)gPad->GetPrimitive("h22");
  hs2->Add(h22);
  hs2->SetTitle("2011: B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}: nLongTracks");
  hs2->Draw("nostack");
  c2->Print("tracksplots.pdf(");

  THStack *hs3 = new THStack("hs3","");
  TCanvas *c3 = new TCanvas("c3","2011nTracks",1200,800);
  gStyle->SetOptStat("");
  f1->cd("tupleb2DpMu");
  tupleb2DpMu->Draw("nTracks>>h31","","norm");
  TH1F *h31 = (TH1F*)gPad->GetPrimitive("h31");
  hs3->Add(h31);
  f2->cd("Tuple_b2DpMuX");
  DecayTree->SetLineColor(kRed);
  DecayTree->Draw("nTracks>>h32","","norm");
  TH1F *h32 = (TH1F*)gPad->GetPrimitive("h32");
  hs3->Add(h32);
  hs3->SetTitle("2011: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nTracks");
  hs3->Draw("nostack");
  c3->Print("tracksplots.pdf(");

  THStack *hs4 = new THStack("hs4","");
  TCanvas *c4 = new TCanvas("c4","2011nLongTracks",1200,800);
  gStyle->SetOptStat("");
  f1->cd("tupleb2DpMu");
  tupleb2DpMu->Draw("nLongTracks>>h41","","norm");
  TH1F *h41 = (TH1F*)gPad->GetPrimitive("h41");
  hs4->Add(h41);
  f2->cd("Tuple_b2DpMuX");
  DecayTree->SetLineColor(kRed);
  DecayTree->Draw("nLongTracks>>h42","","norm");
  TH1F *h42 = (TH1F*)gPad->GetPrimitive("h42");
  hs4->Add(h42);
  hs4->SetTitle("2011: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nLongTracks");
  hs4->Draw("nostack");
  c4->Print("tracksplots.pdf(");

  THStack *hs5 = new THStack("hs5","");
  TCanvas *c5 = new TCanvas("c5","2015nTracks",1200,800);
  gStyle->SetOptStat("");
  f3->cd("Tuple_b2D0MuX");
  DecayTree->Draw("nTracks>>h51","","norm");
  TH1F *h51 = (TH1F*)gPad->GetPrimitive("h51");
  hs5->Add(h51);
  f4->cd("Tuple_b2D0MuX");
  DecayTree->SetLineColor(kRed);
  DecayTree->Draw("nTracks>>h52","","norm");
  TH1F *h52 = (TH1F*)gPad->GetPrimitive("h52");
  hs5->Add(h52);
  hs5->SetTitle("2015: B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}: nTracks");
  hs5->Draw("nostack");
  c5->Print("tracksplots.pdf(");

  THStack *hs6 = new THStack("hs6","");
  TCanvas *c6 = new TCanvas("c6","2015nLongTracks",1200,800);
  gStyle->SetOptStat("");
  f3->cd("Tuple_b2D0MuX");
  DecayTree->Draw("nLongTracks>>h61","","norm");
  TH1F *h61 = (TH1F*)gPad->GetPrimitive("h61");
  hs6->Add(h61);
  f4->cd("Tuple_b2D0MuX");
  DecayTree->SetLineColor(kRed);
  DecayTree->Draw("nLongTracks>>h62","","norm");
  TH1F *h62 = (TH1F*)gPad->GetPrimitive("h62");
  hs6->Add(h62);
  hs6->SetTitle("2015: B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}: nLongTracks");
  hs6->Draw("nostack");
  c6->Print("tracksplots.pdf(");

  THStack *hs7 = new THStack("hs7","");
  TCanvas *c7 = new TCanvas("c7","2015nTracks",1200,800);
  gStyle->SetOptStat("");
  f3->cd("Tuple_b2DpMuX");
  DecayTree->Draw("nTracks>>h71","","norm");
  TH1F *h71 = (TH1F*)gPad->GetPrimitive("h71");
  hs7->Add(h71);
  f4->cd("Tuple_b2DpMuX");
  DecayTree->SetLineColor(kRed);
  DecayTree->Draw("nTracks>>h72","","norm");
  TH1F *h72 = (TH1F*)gPad->GetPrimitive("h72");
  hs7->Add(h72);
  hs7->SetTitle("2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nTracks");
  hs7->Draw("nostack");
  c7->Print("tracksplots.pdf(");

  THStack *hs8 = new THStack("hs8","");
  TCanvas *c8 = new TCanvas("c8","2015nLongTracks",1200,800);
  gStyle->SetOptStat("");
  f3->cd("Tuple_b2DpMuX");
  DecayTree->Draw("nLongTracks>>h81","","norm");
  TH1F *h81 = (TH1F*)gPad->GetPrimitive("h81");
  hs8->Add(h81);
  f4->cd("Tuple_b2DpMuX");
  DecayTree->SetLineColor(kRed);
  DecayTree->Draw("nLongTracks>>h82","","norm");
  TH1F *h82 = (TH1F*)gPad->GetPrimitive("h82");
  hs8->Add(h82);
  hs8->SetTitle("2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nLongTracks");
  hs8->Draw("nostack");
  c8->Print("tracksplots.pdf)");

  gROOT->SetBatch(kFALSE);
}
