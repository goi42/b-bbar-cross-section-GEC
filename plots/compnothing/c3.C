{
//=========Macro generated from canvas: c3/c3
//=========  (Thu Oct 15 23:45:09 2015) by ROOT version5.34/32
   TCanvas *c3 = new TCanvas("c3", "c3",0,0,1200,800);
   gStyle->SetOptStat(0);
   c3->Range(-32.75,-0.005941927,294.75,0.05347734);
   c3->SetFillColor(0);
   c3->SetBorderMode(0);
   c3->SetBorderSize(2);
   c3->SetFrameBorderMode(0);
   c3->SetFrameBorderMode(0);
   
   THStack *hs3 = new THStack();
   hs3->SetName("hs3");
   hs3->SetTitle("2011: MC: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nLongTracks");
   
   TH1F *hs3_stack_4 = new TH1F("hs3_stack_4","2011: MC: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nLongTracks",131,0,262);
   hs3_stack_4->SetMinimum(0);
   hs3_stack_4->SetMaximum(0.04753541);
   hs3_stack_4->SetDirectory(0);
   hs3_stack_4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hs3_stack_4->SetLineColor(ci);
   hs3_stack_4->GetXaxis()->SetLabelFont(42);
   hs3_stack_4->GetXaxis()->SetLabelSize(0.035);
   hs3_stack_4->GetXaxis()->SetTitleSize(0.035);
   hs3_stack_4->GetXaxis()->SetTitleFont(42);
   hs3_stack_4->GetYaxis()->SetLabelFont(42);
   hs3_stack_4->GetYaxis()->SetLabelSize(0.035);
   hs3_stack_4->GetYaxis()->SetTitleSize(0.035);
   hs3_stack_4->GetYaxis()->SetTitleFont(42);
   hs3_stack_4->GetZaxis()->SetLabelFont(42);
   hs3_stack_4->GetZaxis()->SetLabelSize(0.035);
   hs3_stack_4->GetZaxis()->SetTitleSize(0.035);
   hs3_stack_4->GetZaxis()->SetTitleFont(42);
   hs3->SetHistogram(hs3_stack_4);
   
   
   TH1F *h30 = new TH1F("h30","nLongTracks",131,0,262);
   h30->SetBinContent(3,0.0005051249);
   h30->SetBinContent(4,0.003220171);
   h30->SetBinContent(5,0.007808389);
   h30->SetBinContent(6,0.01424873);
   h30->SetBinContent(7,0.02005767);
   h30->SetBinContent(8,0.02721361);
   h30->SetBinContent(9,0.03335929);
   h30->SetBinContent(10,0.03683202);
   h30->SetBinContent(11,0.03944184);
   h30->SetBinContent(12,0.04182013);
   h30->SetBinContent(13,0.04527182);
   h30->SetBinContent(14,0.04327237);
   h30->SetBinContent(15,0.04451413);
   h30->SetBinContent(16,0.04470355);
   h30->SetBinContent(17,0.04293562);
   h30->SetBinContent(18,0.04325132);
   h30->SetBinContent(19,0.03998905);
   h30->SetBinContent(20,0.03706354);
   h30->SetBinContent(21,0.03500095);
   h30->SetBinContent(22,0.03378023);
   h30->SetBinContent(23,0.03135984);
   h30->SetBinContent(24,0.03030749);
   h30->SetBinContent(25,0.02637173);
   h30->SetBinContent(26,0.02460379);
   h30->SetBinContent(27,0.02136257);
   h30->SetBinContent(28,0.0205207);
   h30->SetBinContent(29,0.01946836);
   h30->SetBinContent(30,0.01757414);
   h30->SetBinContent(31,0.01631133);
   h30->SetBinContent(32,0.01536422);
   h30->SetBinContent(33,0.01233347);
   h30->SetBinContent(34,0.0120809);
   h30->SetBinContent(35,0.01079705);
   h30->SetBinContent(36,0.009428998);
   h30->SetBinContent(37,0.009281671);
   h30->SetBinContent(38,0.007934671);
   h30->SetBinContent(39,0.007429546);
   h30->SetBinContent(40,0.006903374);
   h30->SetBinContent(41,0.005956265);
   h30->SetBinContent(42,0.005009155);
   h30->SetBinContent(43,0.004588218);
   h30->SetBinContent(44,0.004546124);
   h30->SetBinContent(45,0.004293562);
   h30->SetBinContent(46,0.004083093);
   h30->SetBinContent(47,0.003220171);
   h30->SetBinContent(48,0.003641109);
   h30->SetBinContent(49,0.002525625);
   h30->SetBinContent(50,0.002588765);
   h30->SetBinContent(51,0.002273062);
   h30->SetBinContent(52,0.002062593);
   h30->SetBinContent(53,0.001852125);
   h30->SetBinContent(54,0.00174689);
   h30->SetBinContent(55,0.001452234);
   h30->SetBinContent(56,0.001283859);
   h30->SetBinContent(57,0.001199672);
   h30->SetBinContent(58,0.001199672);
   h30->SetBinContent(59,0.0009471092);
   h30->SetBinContent(60,0.001178625);
   h30->SetBinContent(61,0.0008629217);
   h30->SetBinContent(62,0.0005893124);
   h30->SetBinContent(63,0.0007366405);
   h30->SetBinContent(64,0.0006945467);
   h30->SetBinContent(65,0.0006103592);
   h30->SetBinContent(66,0.0004630312);
   h30->SetBinContent(67,0.0004419843);
   h30->SetBinContent(68,0.0003367499);
   h30->SetBinContent(69,0.0005261718);
   h30->SetBinContent(70,0.0004419843);
   h30->SetBinContent(71,0.0003998906);
   h30->SetBinContent(72,0.0001894218);
   h30->SetBinContent(73,0.0003788437);
   h30->SetBinContent(74,0.0002525625);
   h30->SetBinContent(75,0.0003157031);
   h30->SetBinContent(76,0.0002736093);
   h30->SetBinContent(77,0.0001894218);
   h30->SetBinContent(78,0.0002525625);
   h30->SetBinContent(79,0.0002104687);
   h30->SetBinContent(80,0.0001052344);
   h30->SetBinContent(81,0.0002104687);
   h30->SetBinContent(82,0.0001052344);
   h30->SetBinContent(83,0.0001262812);
   h30->SetBinContent(84,8.418749e-05);
   h30->SetBinContent(85,8.418749e-05);
   h30->SetBinContent(86,0.000168375);
   h30->SetBinContent(87,0.0001262812);
   h30->SetBinContent(88,6.314061e-05);
   h30->SetBinContent(89,6.314061e-05);
   h30->SetBinContent(90,6.314061e-05);
   h30->SetBinContent(91,0.0001262812);
   h30->SetBinContent(92,0.0001262812);
   h30->SetBinContent(93,8.418749e-05);
   h30->SetBinContent(94,4.209374e-05);
   h30->SetBinContent(95,6.314061e-05);
   h30->SetBinContent(96,8.418749e-05);
   h30->SetBinContent(97,6.314061e-05);
   h30->SetBinContent(98,0.000168375);
   h30->SetBinContent(99,8.418749e-05);
   h30->SetBinContent(100,6.314061e-05);
   h30->SetBinContent(101,6.314061e-05);
   h30->SetBinContent(102,2.104687e-05);
   h30->SetBinContent(104,4.209374e-05);
   h30->SetBinContent(105,2.104687e-05);
   h30->SetBinContent(109,2.104687e-05);
   h30->SetBinContent(110,2.104687e-05);
   h30->SetBinContent(113,2.104687e-05);
   h30->SetBinContent(114,2.104687e-05);
   h30->SetBinContent(115,6.314061e-05);
   h30->SetBinContent(116,2.104687e-05);
   h30->SetBinContent(117,2.104687e-05);
   h30->SetBinContent(125,2.104687e-05);
   h30->SetEntries(47513);
   h30->SetStats(0);
   h30->GetXaxis()->SetLabelFont(42);
   h30->GetXaxis()->SetLabelSize(0.035);
   h30->GetXaxis()->SetTitleSize(0.035);
   h30->GetXaxis()->SetTitleFont(42);
   h30->GetYaxis()->SetLabelFont(42);
   h30->GetYaxis()->SetLabelSize(0.035);
   h30->GetYaxis()->SetTitleSize(0.035);
   h30->GetYaxis()->SetTitleFont(42);
   h30->GetZaxis()->SetLabelFont(42);
   h30->GetZaxis()->SetLabelSize(0.035);
   h30->GetZaxis()->SetTitleSize(0.035);
   h30->GetZaxis()->SetTitleFont(42);
   hs3->Add(h30,"");
   hs3->Draw("nostack");
   
   TPaveText *pt = new TPaveText(0.1501171,0.9234974,0.8498829,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("2011: MC: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nLongTracks");
   pt->Draw();
   c3->Modified();
   c3->cd();
   c3->SetSelected(c3);
}
