{
//=========Macro generated from canvas: c3/c3
//=========  (Thu Oct 15 23:48:23 2015) by ROOT version5.34/32
   TCanvas *c3 = new TCanvas("c3", "c3",0,0,1200,800);
   gStyle->SetOptStat(0);
   c3->Range(-32.75,-0.004917871,294.75,0.04426084);
   c3->SetFillColor(0);
   c3->SetBorderMode(0);
   c3->SetBorderSize(2);
   c3->SetFrameBorderMode(0);
   c3->SetFrameBorderMode(0);
   
   THStack *hs3 = new THStack();
   hs3->SetName("hs3");
   hs3->SetTitle("2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nLongTracks");
   
   TH1F *hs3_stack_4 = new TH1F("hs3_stack_4","2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nLongTracks",131,0,262);
   hs3_stack_4->SetMinimum(0);
   hs3_stack_4->SetMaximum(0.03934297);
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
   h30->SetBinContent(3,5.245167e-05);
   h30->SetBinContent(4,0.0003441341);
   h30->SetBinContent(5,0.0009518059);
   h30->SetBinContent(6,0.001757771);
   h30->SetBinContent(7,0.003190597);
   h30->SetBinContent(8,0.00449933);
   h30->SetBinContent(9,0.005957742);
   h30->SetBinContent(10,0.007582464);
   h30->SetBinContent(11,0.009308252);
   h30->SetBinContent(12,0.01117476);
   h30->SetBinContent(13,0.01277518);
   h30->SetBinContent(14,0.01436024);
   h30->SetBinContent(15,0.01587239);
   h30->SetBinContent(16,0.01700202);
   h30->SetBinContent(17,0.01831587);
   h30->SetBinContent(18,0.01948643);
   h30->SetBinContent(19,0.02015551);
   h30->SetBinContent(20,0.02083739);
   h30->SetBinContent(21,0.02117768);
   h30->SetBinContent(22,0.02141179);
   h30->SetBinContent(23,0.02200923);
   h30->SetBinContent(24,0.02167789);
   h30->SetBinContent(25,0.02201819);
   h30->SetBinContent(26,0.02207576);
   h30->SetBinContent(27,0.02151542);
   h30->SetBinContent(28,0.02112651);
   h30->SetBinContent(29,0.02063781);
   h30->SetBinContent(30,0.02076958);
   h30->SetBinContent(31,0.02026042);
   h30->SetBinContent(32,0.02038067);
   h30->SetBinContent(33,0.01898367);
   h30->SetBinContent(34,0.01915381);
   h30->SetBinContent(35,0.01829156);
   h30->SetBinContent(36,0.01783741);
   h30->SetBinContent(37,0.0173615);
   h30->SetBinContent(38,0.01686001);
   h30->SetBinContent(39,0.01634445);
   h30->SetBinContent(40,0.01590309);
   h30->SetBinContent(41,0.01510736);
   h30->SetBinContent(42,0.01460075);
   h30->SetBinContent(43,0.0139982);
   h30->SetBinContent(44,0.01352357);
   h30->SetBinContent(45,0.01294405);
   h30->SetBinContent(46,0.01265876);
   h30->SetBinContent(47,0.01205877);
   h30->SetBinContent(48,0.01161229);
   h30->SetBinContent(49,0.01100206);
   h30->SetBinContent(50,0.01093425);
   h30->SetBinContent(51,0.01020505);
   h30->SetBinContent(52,0.009890337);
   h30->SetBinContent(53,0.009637034);
   h30->SetBinContent(54,0.009524455);
   h30->SetBinContent(55,0.008887359);
   h30->SetBinContent(56,0.008777339);
   h30->SetBinContent(57,0.008443439);
   h30->SetBinContent(58,0.008191415);
   h30->SetBinContent(59,0.007587581);
   h30->SetBinContent(60,0.007521058);
   h30->SetBinContent(61,0.00703492);
   h30->SetBinContent(62,0.007179482);
   h30->SetBinContent(63,0.006585883);
   h30->SetBinContent(64,0.006438762);
   h30->SetBinContent(65,0.006392707);
   h30->SetBinContent(66,0.005851559);
   h30->SetBinContent(67,0.005833649);
   h30->SetBinContent(68,0.005710835);
   h30->SetBinContent(69,0.005419153);
   h30->SetBinContent(70,0.005296339);
   h30->SetBinContent(71,0.005028964);
   h30->SetBinContent(72,0.004934295);
   h30->SetBinContent(73,0.004999539);
   h30->SetBinContent(74,0.004830671);
   h30->SetBinContent(75,0.004496771);
   h30->SetBinContent(76,0.004453274);
   h30->SetBinContent(77,0.004578647);
   h30->SetBinContent(78,0.004157754);
   h30->SetBinContent(79,0.004006796);
   h30->SetBinContent(80,0.004051572);
   h30->SetBinContent(81,0.003744537);
   h30->SetBinContent(82,0.003854558);
   h30->SetBinContent(83,0.003593579);
   h30->SetBinContent(84,0.003410638);
   h30->SetBinContent(85,0.003456693);
   h30->SetBinContent(86,0.003218741);
   h30->SetBinContent(87,0.003103604);
   h30->SetBinContent(88,0.00311);
   h30->SetBinContent(89,0.003079297);
   h30->SetBinContent(90,0.002898914);
   h30->SetBinContent(91,0.0028132);
   h30->SetBinContent(92,0.002689108);
   h30->SetBinContent(93,0.002745397);
   h30->SetBinContent(94,0.002570132);
   h30->SetBinContent(95,0.002662242);
   h30->SetBinContent(96,0.002527914);
   h30->SetBinContent(97,0.002478021);
   h30->SetBinContent(98,0.002224718);
   h30->SetBinContent(99,0.002170987);
   h30->SetBinContent(100,0.002122374);
   h30->SetBinContent(101,0.002066084);
   h30->SetBinContent(102,0.00214796);
   h30->SetBinContent(103,0.001947108);
   h30->SetBinContent(104,0.00192536);
   h30->SetBinContent(105,0.001899774);
   h30->SetBinContent(106,0.001774402);
   h30->SetBinContent(107,0.001802546);
   h30->SetBinContent(108,0.001710436);
   h30->SetBinContent(109,0.001547964);
   h30->SetBinContent(110,0.001604253);
   h30->SetBinContent(111,0.001528774);
   h30->SetBinContent(112,0.001564595);
   h30->SetBinContent(113,0.001472485);
   h30->SetBinContent(114,0.001533891);
   h30->SetBinContent(115,0.001491674);
   h30->SetBinContent(116,0.001302337);
   h30->SetBinContent(117,0.001302337);
   h30->SetBinContent(118,0.001317688);
   h30->SetBinContent(119,0.001252444);
   h30->SetBinContent(120,0.001238371);
   h30->SetBinContent(121,0.001088692);
   h30->SetBinContent(122,0.001066944);
   h30->SetBinContent(123,0.0009940231);
   h30->SetBinContent(124,0.001093809);
   h30->SetBinContent(125,0.001043916);
   h30->SetEntries(781672);
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
   
   TH1F *h31 = new TH1F("h31","nLongTracks",131,0,262);
   h31->SetBinContent(3,0.0004947556);
   h31->SetBinContent(4,0.002407811);
   h31->SetBinContent(5,0.005805132);
   h31->SetBinContent(6,0.01025793);
   h31->SetBinContent(7,0.01494162);
   h31->SetBinContent(8,0.01784419);
   h31->SetBinContent(9,0.02358335);
   h31->SetBinContent(10,0.02670031);
   h31->SetBinContent(11,0.02960288);
   h31->SetBinContent(12,0.03280229);
   h31->SetBinContent(13,0.03445148);
   h31->SetBinContent(14,0.03356092);
   h31->SetBinContent(15,0.03676034);
   h31->SetBinContent(16,0.03689228);
   h31->SetBinContent(17,0.03746949);
   h31->SetBinContent(18,0.03557293);
   h31->SetBinContent(19,0.03618313);
   h31->SetBinContent(20,0.03577083);
   h31->SetBinContent(21,0.03379181);
   h31->SetBinContent(22,0.03349495);
   h31->SetBinContent(23,0.03280229);
   h31->SetBinContent(24,0.03013062);
   h31->SetBinContent(25,0.0295534);
   h31->SetBinContent(26,0.02749192);
   h31->SetBinContent(27,0.02630451);
   h31->SetBinContent(28,0.02519955);
   h31->SetBinContent(29,0.02157134);
   h31->SetBinContent(30,0.02028498);
   h31->SetBinContent(31,0.01805858);
   h31->SetBinContent(32,0.01960881);
   h31->SetBinContent(33,0.01690415);
   h31->SetBinContent(34,0.01652484);
   h31->SetBinContent(35,0.01405106);
   h31->SetBinContent(36,0.01231941);
   h31->SetBinContent(37,0.01256679);
   h31->SetBinContent(38,0.01170922);
   h31->SetBinContent(39,0.01202256);
   h31->SetBinContent(40,0.009070519);
   h31->SetBinContent(41,0.01030741);
   h31->SetBinContent(42,0.008509796);
   h31->SetBinContent(43,0.00801504);
   h31->SetBinContent(44,0.006877103);
   h31->SetBinContent(45,0.006646217);
   h31->SetBinContent(46,0.006266904);
   h31->SetBinContent(47,0.006613233);
   h31->SetBinContent(48,0.005673198);
   h31->SetBinContent(49,0.004304374);
   h31->SetBinContent(50,0.004403325);
   h31->SetBinContent(51,0.003694175);
   h31->SetBinContent(52,0.004040504);
   h31->SetBinContent(53,0.003265387);
   h31->SetBinContent(54,0.002556237);
   h31->SetBinContent(55,0.002787123);
   h31->SetBinContent(56,0.002721156);
   h31->SetBinContent(57,0.002704664);
   h31->SetBinContent(58,0.002523253);
   h31->SetBinContent(59,0.002028498);
   h31->SetBinContent(60,0.001896563);
   h31->SetBinContent(61,0.00133584);
   h31->SetBinContent(62,0.002077973);
   h31->SetBinContent(63,0.001500759);
   h31->SetBinContent(64,0.001385316);
   h31->SetBinContent(65,0.0009565275);
   h31->SetBinContent(66,0.001847088);
   h31->SetBinContent(67,0.0008740682);
   h31->SetBinContent(68,0.0008575764);
   h31->SetBinContent(69,0.0008740682);
   h31->SetBinContent(70,0.001319348);
   h31->SetBinContent(71,0.0008410845);
   h31->SetBinContent(72,0.0009235438);
   h31->SetBinContent(73,0.001022495);
   h31->SetBinContent(74,0.001385316);
   h31->SetBinContent(75,0.0009070519);
   h31->SetBinContent(76,0.0005277393);
   h31->SetBinContent(77,0.0006431823);
   h31->SetBinContent(78,0.0003628208);
   h31->SetBinContent(79,0.0008575764);
   h31->SetBinContent(80,0.0008081008);
   h31->SetBinContent(81,0.0005277393);
   h31->SetBinContent(82,0.0003463289);
   h31->SetBinContent(83,0.0004782637);
   h31->SetBinContent(84,0.0005112474);
   h31->SetBinContent(85,0.0003298371);
   h31->SetBinContent(86,0.0003793126);
   h31->SetBinContent(87,0.0005937067);
   h31->SetBinContent(88,0.0001814104);
   h31->SetBinContent(89,0.0002308859);
   h31->SetBinContent(90,0.0003958045);
   h31->SetBinContent(91,0.0003298371);
   h31->SetBinContent(92,0.0002968534);
   h31->SetBinContent(93,0.0001319348);
   h31->SetBinContent(94,0.0001979022);
   h31->SetBinContent(95,0.0002638696);
   h31->SetBinContent(96,0.0001649185);
   h31->SetBinContent(97,6.596741e-05);
   h31->SetBinContent(98,0.0002308859);
   h31->SetBinContent(99,0.0001814104);
   h31->SetBinContent(100,0.0003133452);
   h31->SetBinContent(101,0.000115443);
   h31->SetBinContent(102,8.245926e-05);
   h31->SetBinContent(103,0.000115443);
   h31->SetBinContent(104,0.0002473778);
   h31->SetBinContent(105,8.245926e-05);
   h31->SetBinContent(106,0.0001484267);
   h31->SetBinContent(107,4.947556e-05);
   h31->SetBinContent(108,0.000115443);
   h31->SetBinContent(109,9.895112e-05);
   h31->SetBinContent(110,0.0002968534);
   h31->SetBinContent(111,3.298371e-05);
   h31->SetBinContent(112,3.298371e-05);
   h31->SetBinContent(113,1.649185e-05);
   h31->SetBinContent(114,9.895112e-05);
   h31->SetBinContent(115,0.0001319348);
   h31->SetBinContent(116,4.947556e-05);
   h31->SetBinContent(118,4.947556e-05);
   h31->SetBinContent(119,0.0002473778);
   h31->SetBinContent(122,3.298371e-05);
   h31->SetBinContent(123,1.649185e-05);
   h31->SetBinContent(124,1.649185e-05);
   h31->SetBinContent(125,6.596741e-05);
   h31->SetEntries(60636);
   h31->SetStats(0);
   h31->SetLineColor(2);
   h31->GetXaxis()->SetLabelFont(42);
   h31->GetXaxis()->SetLabelSize(0.035);
   h31->GetXaxis()->SetTitleSize(0.035);
   h31->GetXaxis()->SetTitleFont(42);
   h31->GetYaxis()->SetLabelFont(42);
   h31->GetYaxis()->SetLabelSize(0.035);
   h31->GetYaxis()->SetTitleSize(0.035);
   h31->GetYaxis()->SetTitleFont(42);
   h31->GetZaxis()->SetLabelFont(42);
   h31->GetZaxis()->SetLabelSize(0.035);
   h31->GetZaxis()->SetTitleSize(0.035);
   h31->GetZaxis()->SetTitleFont(42);
   hs3->Add(h31,"");
   hs3->Draw("nostack");
   
   TLegend *leg = new TLegend(0.7,0.7,0.97,0.93,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h30","data","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h31","MC","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.1860702,0.9234974,0.8139298,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nLongTracks");
   pt->Draw();
   c3->Modified();
   c3->cd();
   c3->SetSelected(c3);
}
