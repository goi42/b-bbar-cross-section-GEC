{
//=========Macro generated from canvas: c6/c6
//=========  (Fri Oct 16 15:59:48 2015) by ROOT version5.34/32
   TCanvas *c6 = new TCanvas("c6", "c6",0,0,1200,800);
   gStyle->SetOptStat(0);
   c6->Range(849.9999,-0.004601846,9350,0.04141661);
   c6->SetFillColor(0);
   c6->SetBorderMode(0);
   c6->SetBorderSize(2);
   c6->SetFrameBorderMode(0);
   c6->SetFrameBorderMode(0);
   
   THStack *hs6 = new THStack();
   hs6->SetName("hs6");
   hs6->SetTitle("2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: B_MM");
   
   TH1F *hs6_stack_7 = new TH1F("hs6_stack_7","2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: B_MM",100,1700,8500);
   hs6_stack_7->SetMinimum(0);
   hs6_stack_7->SetMaximum(0.03681476);
   hs6_stack_7->SetDirectory(0);
   hs6_stack_7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hs6_stack_7->SetLineColor(ci);
   hs6_stack_7->GetXaxis()->SetLabelFont(42);
   hs6_stack_7->GetXaxis()->SetLabelSize(0.035);
   hs6_stack_7->GetXaxis()->SetTitleSize(0.035);
   hs6_stack_7->GetXaxis()->SetTitleFont(42);
   hs6_stack_7->GetYaxis()->SetLabelFont(42);
   hs6_stack_7->GetYaxis()->SetLabelSize(0.035);
   hs6_stack_7->GetYaxis()->SetTitleSize(0.035);
   hs6_stack_7->GetYaxis()->SetTitleFont(42);
   hs6_stack_7->GetZaxis()->SetLabelFont(42);
   hs6_stack_7->GetZaxis()->SetLabelSize(0.035);
   hs6_stack_7->GetZaxis()->SetTitleSize(0.035);
   hs6_stack_7->GetZaxis()->SetTitleFont(42);
   hs6->SetHistogram(hs6_stack_7);
   
   
   TH1F *h60 = new TH1F("h60","B_MM",100,1700,8500);
   h60->SetBinContent(8,0.002330901);
   h60->SetBinContent(9,0.004994422);
   h60->SetBinContent(10,0.006575648);
   h60->SetBinContent(11,0.008443439);
   h60->SetBinContent(12,0.01033937);
   h60->SetBinContent(13,0.01204086);
   h60->SetBinContent(14,0.01426813);
   h60->SetBinContent(15,0.01619861);
   h60->SetBinContent(16,0.01824167);
   h60->SetBinContent(17,0.02042545);
   h60->SetBinContent(18,0.02278705);
   h60->SetBinContent(19,0.02492478);
   h60->SetBinContent(20,0.0266173);
   h60->SetBinContent(21,0.02852603);
   h60->SetBinContent(22,0.0302032);
   h60->SetBinContent(23,0.03163219);
   h60->SetBinContent(24,0.03213368);
   h60->SetBinContent(25,0.03318272);
   h60->SetBinContent(26,0.03373026);
   h60->SetBinContent(27,0.03374561);
   h60->SetBinContent(28,0.03400787);
   h60->SetBinContent(29,0.03343986);
   h60->SetBinContent(30,0.03288592);
   h60->SetBinContent(31,0.0320339);
   h60->SetBinContent(32,0.03140448);
   h60->SetBinContent(33,0.0305499);
   h60->SetBinContent(34,0.02955715);
   h60->SetBinContent(35,0.02840194);
   h60->SetBinContent(36,0.02681687);
   h60->SetBinContent(37,0.02505527);
   h60->SetBinContent(38,0.02336274);
   h60->SetBinContent(39,0.02191073);
   h60->SetBinContent(40,0.02010178);
   h60->SetBinContent(41,0.01832354);
   h60->SetBinContent(42,0.01694317);
   h60->SetBinContent(43,0.01542463);
   h60->SetBinContent(44,0.01376664);
   h60->SetBinContent(45,0.01265492);
   h60->SetBinContent(46,0.01153937);
   h60->SetBinContent(47,0.01023703);
   h60->SetBinContent(48,0.009057508);
   h60->SetBinContent(49,0.008352608);
   h60->SetBinContent(50,0.007286944);
   h60->SetBinContent(51,0.006643451);
   h60->SetBinContent(52,0.006022986);
   h60->SetBinContent(53,0.005580346);
   h60->SetBinContent(54,0.005259239);
   h60->SetBinContent(55,0.004796129);
   h60->SetBinContent(56,0.004487816);
   h60->SetBinContent(57,0.004187178);
   h60->SetBinContent(58,0.003830251);
   h60->SetBinContent(59,0.003791872);
   h60->SetBinContent(60,0.003438782);
   h60->SetBinContent(61,0.003216183);
   h60->SetBinContent(62,0.002912987);
   h60->SetBinContent(63,0.002905311);
   h60->SetBinContent(64,0.002657125);
   h60->SetBinContent(65,0.002503608);
   h60->SetBinContent(66,0.002359046);
   h60->SetBinContent(67,0.002199132);
   h60->SetBinContent(68,0.002052012);
   h60->SetBinContent(69,0.001956063);
   h60->SetBinContent(70,0.001860115);
   h60->SetBinContent(71,0.001743698);
   h60->SetBinContent(72,0.001637515);
   h60->SetBinContent(73,0.001549243);
   h60->SetBinContent(74,0.001445619);
   h60->SetBinContent(75,0.001331761);
   h60->SetBinContent(76,0.001307454);
   h60->SetBinContent(77,0.001307454);
   h60->SetBinContent(78,0.001137306);
   h60->SetBinContent(79,0.00107334);
   h60->SetBinContent(80,0.001034961);
   h60->SetBinContent(81,0.0009185438);
   h60->SetBinContent(82,0.000960761);
   h60->SetBinContent(83,0.0008916783);
   h60->SetBinContent(84,0.0008277129);
   h60->SetBinContent(85,0.000786775);
   h60->SetBinContent(86,0.000736882);
   h60->SetBinContent(87,0.0007151337);
   h60->SetBinContent(88,0.0006767545);
   h60->SetBinContent(89,0.0006677993);
   h60->SetBinContent(90,0.0006716372);
   h60->SetBinContent(91,0.0005795269);
   h60->SetBinContent(92,0.0005462649);
   h60->SetBinContent(93,0.0003364583);
   h60->SetEntries(781672);
   h60->SetStats(0);
   h60->GetXaxis()->SetLabelFont(42);
   h60->GetXaxis()->SetLabelSize(0.035);
   h60->GetXaxis()->SetTitleSize(0.035);
   h60->GetXaxis()->SetTitleFont(42);
   h60->GetYaxis()->SetLabelFont(42);
   h60->GetYaxis()->SetLabelSize(0.035);
   h60->GetYaxis()->SetTitleSize(0.035);
   h60->GetYaxis()->SetTitleFont(42);
   h60->GetZaxis()->SetLabelFont(42);
   h60->GetZaxis()->SetLabelSize(0.035);
   h60->GetZaxis()->SetTitleSize(0.035);
   h60->GetZaxis()->SetTitleFont(42);
   hs6->Add(h60,"");
   
   TH1F *h61 = new TH1F("h61","B_MM",100,1700,8500);
   h61->SetBinContent(8,0.005739165);
   h61->SetBinContent(9,0.0115443);
   h61->SetBinContent(10,0.01443037);
   h61->SetBinContent(11,0.01611254);
   h61->SetBinContent(12,0.02035095);
   h61->SetBinContent(13,0.02147239);
   h61->SetBinContent(14,0.02241243);
   h61->SetBinContent(15,0.0252985);
   h61->SetBinContent(16,0.02648592);
   h61->SetBinContent(17,0.02747543);
   h61->SetBinContent(18,0.02757438);
   h61->SetBinContent(19,0.02900917);
   h61->SetBinContent(20,0.03070783);
   h61->SetBinContent(21,0.03260439);
   h61->SetBinContent(22,0.03222508);
   h61->SetBinContent(23,0.03286826);
   h61->SetBinContent(24,0.03255492);
   h61->SetBinContent(25,0.0331981);
   h61->SetBinContent(26,0.03506168);
   h61->SetBinContent(27,0.03456692);
   h61->SetBinContent(28,0.0350122);
   h61->SetBinContent(29,0.03281879);
   h61->SetBinContent(30,0.03469886);
   h61->SetBinContent(31,0.03232403);
   h61->SetBinContent(32,0.03169734);
   h61->SetBinContent(33,0.03098819);
   h61->SetBinContent(34,0.02945445);
   h61->SetBinContent(35,0.02775579);
   h61->SetBinContent(36,0.0267168);
   h61->SetBinContent(37,0.02397915);
   h61->SetBinContent(38,0.02203312);
   h61->SetBinContent(39,0.01926249);
   h61->SetBinContent(40,0.01753084);
   h61->SetBinContent(41,0.01617851);
   h61->SetBinContent(42,0.01459529);
   h61->SetBinContent(43,0.01246784);
   h61->SetBinContent(44,0.01068672);
   h61->SetBinContent(45,0.008377861);
   h61->SetBinContent(46,0.006250412);
   h61->SetBinContent(47,0.005788641);
   h61->SetBinContent(48,0.00453526);
   h61->SetBinContent(49,0.003611716);
   h61->SetBinContent(50,0.003133452);
   h61->SetBinContent(51,0.002539745);
   h61->SetBinContent(52,0.002457286);
   h61->SetBinContent(53,0.002176925);
   h61->SetBinContent(54,0.001979022);
   h61->SetBinContent(55,0.001995514);
   h61->SetBinContent(56,0.001863579);
   h61->SetBinContent(57,0.001434791);
   h61->SetBinContent(58,0.001269873);
   h61->SetBinContent(59,0.001187413);
   h61->SetBinContent(60,0.001137938);
   h61->SetBinContent(61,0.00133584);
   h61->SetBinContent(62,0.001434791);
   h61->SetBinContent(63,0.001253381);
   h61->SetBinContent(64,0.0009400356);
   h61->SetBinContent(65,0.00115443);
   h61->SetBinContent(66,0.0009730193);
   h61->SetBinContent(67,0.0007091497);
   h61->SetBinContent(68,0.0009895111);
   h61->SetBinContent(69,0.00089056);
   h61->SetBinContent(70,0.0008245927);
   h61->SetBinContent(71,0.0006596741);
   h61->SetBinContent(72,0.000676166);
   h61->SetBinContent(73,0.0006101985);
   h61->SetBinContent(74,0.0007586252);
   h61->SetBinContent(75,0.0007256416);
   h61->SetBinContent(76,0.0004947556);
   h61->SetBinContent(77,0.0006596741);
   h61->SetBinContent(78,0.0004617719);
   h61->SetBinContent(79,0.0002968534);
   h61->SetBinContent(80,0.0004947556);
   h61->SetBinContent(81,0.0003298371);
   h61->SetBinContent(82,0.0003463289);
   h61->SetBinContent(83,0.0004287882);
   h61->SetBinContent(84,0.0002803615);
   h61->SetBinContent(85,0.0003463289);
   h61->SetBinContent(86,0.0003463289);
   h61->SetBinContent(87,0.0003298371);
   h61->SetBinContent(88,0.0002473778);
   h61->SetBinContent(89,0.0002638696);
   h61->SetBinContent(90,0.0002638696);
   h61->SetBinContent(91,0.0003958045);
   h61->SetBinContent(92,0.0002143941);
   h61->SetBinContent(93,0.0002308859);
   h61->SetEntries(60636);
   h61->SetStats(0);
   h61->SetLineColor(2);
   h61->GetXaxis()->SetLabelFont(42);
   h61->GetXaxis()->SetLabelSize(0.035);
   h61->GetXaxis()->SetTitleSize(0.035);
   h61->GetXaxis()->SetTitleFont(42);
   h61->GetYaxis()->SetLabelFont(42);
   h61->GetYaxis()->SetLabelSize(0.035);
   h61->GetYaxis()->SetTitleSize(0.035);
   h61->GetYaxis()->SetTitleFont(42);
   h61->GetZaxis()->SetLabelFont(42);
   h61->GetZaxis()->SetLabelSize(0.035);
   h61->GetZaxis()->SetTitleSize(0.035);
   h61->GetZaxis()->SetTitleFont(42);
   hs6->Add(h61,"");
   hs6->Draw("nostack");
   
   TLegend *leg = new TLegend(0.7,0.7,0.97,0.93,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h60","data","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h61","MC","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2425084,0.9234974,0.7574916,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: B_MM");
   pt->Draw();
   c6->Modified();
   c6->cd();
   c6->SetSelected(c6);
}
