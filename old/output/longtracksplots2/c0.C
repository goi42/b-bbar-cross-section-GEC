{
//=========Macro generated from canvas: c0/2011datanLongTracks
//=========  (Tue Oct 13 15:01:59 2015) by ROOT version5.34/32
   TCanvas *c0 = new TCanvas("c0", "2011datanLongTracks",0,0,1200,800);
   gStyle->SetOptStat(0);
   c0->Range(-32.75,-0.005305566,294.75,0.04775009);
   c0->SetFillColor(0);
   c0->SetBorderMode(0);
   c0->SetBorderSize(2);
   c0->SetFrameBorderMode(0);
   c0->SetFrameBorderMode(0);
   
   THStack *hs0 = new THStack();
   hs0->SetName("hs0");
   hs0->SetTitle("2011: data: nLongTracks");
   
   TH1F *hs0_stack_1 = new TH1F("hs0_stack_1","2011: data: nLongTracks",131,0,262);
   hs0_stack_1->SetMinimum(0);
   hs0_stack_1->SetMaximum(0.04244452);
   hs0_stack_1->SetDirectory(0);
   hs0_stack_1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hs0_stack_1->SetLineColor(ci);
   hs0_stack_1->GetXaxis()->SetLabelFont(42);
   hs0_stack_1->GetXaxis()->SetLabelSize(0.035);
   hs0_stack_1->GetXaxis()->SetTitleSize(0.035);
   hs0_stack_1->GetXaxis()->SetTitleFont(42);
   hs0_stack_1->GetYaxis()->SetLabelFont(42);
   hs0_stack_1->GetYaxis()->SetLabelSize(0.035);
   hs0_stack_1->GetYaxis()->SetTitleSize(0.035);
   hs0_stack_1->GetYaxis()->SetTitleFont(42);
   hs0_stack_1->GetZaxis()->SetLabelFont(42);
   hs0_stack_1->GetZaxis()->SetLabelSize(0.035);
   hs0_stack_1->GetZaxis()->SetTitleSize(0.035);
   hs0_stack_1->GetZaxis()->SetTitleFont(42);
   hs0->SetHistogram(hs0_stack_1);
   
   
   TH1F *h00 = new TH1F("h00","nLongTracks",131,0,262);
   h00->SetBinContent(2,4.097382e-05);
   h00->SetBinContent(3,0.000678507);
   h00->SetBinContent(4,0.002622569);
   h00->SetBinContent(5,0.005842672);
   h00->SetBinContent(6,0.00997054);
   h00->SetBinContent(7,0.01456107);
   h00->SetBinContent(8,0.01943891);
   h00->SetBinContent(9,0.02402139);
   h00->SetBinContent(10,0.02825852);
   h00->SetBinContent(11,0.03192275);
   h00->SetBinContent(12,0.03483555);
   h00->SetBinContent(13,0.03739252);
   h00->SetBinContent(14,0.03885855);
   h00->SetBinContent(15,0.04004411);
   h00->SetBinContent(16,0.04042336);
   h00->SetBinContent(17,0.04032507);
   h00->SetBinContent(18,0.03974924);
   h00->SetBinContent(19,0.03859685);
   h00->SetBinContent(20,0.03728642);
   h00->SetBinContent(21,0.03575771);
   h00->SetBinContent(22,0.034059);
   h00->SetBinContent(23,0.03251712);
   h00->SetBinContent(24,0.0306611);
   h00->SetBinContent(25,0.02874411);
   h00->SetBinContent(26,0.02697346);
   h00->SetBinContent(27,0.02515085);
   h00->SetBinContent(28,0.02357946);
   h00->SetBinContent(29,0.02195368);
   h00->SetBinContent(30,0.02033009);
   h00->SetBinContent(31,0.01893039);
   h00->SetBinContent(32,0.01756118);
   h00->SetBinContent(33,0.01621734);
   h00->SetBinContent(34,0.01502764);
   h00->SetBinContent(35,0.01397963);
   h00->SetBinContent(36,0.01273798);
   h00->SetBinContent(37,0.01175534);
   h00->SetBinContent(38,0.01073343);
   h00->SetBinContent(39,0.009961273);
   h00->SetBinContent(40,0.009151308);
   h00->SetBinContent(41,0.008339148);
   h00->SetBinContent(42,0.007633569);
   h00->SetBinContent(43,0.006937258);
   h00->SetBinContent(44,0.006432158);
   h00->SetBinContent(45,0.00567585);
   h00->SetBinContent(46,0.005253186);
   h00->SetBinContent(47,0.004809058);
   h00->SetBinContent(48,0.00438615);
   h00->SetBinContent(49,0.003904464);
   h00->SetBinContent(50,0.003583502);
   h00->SetBinContent(51,0.003234249);
   h00->SetBinContent(52,0.003008893);
   h00->SetBinContent(53,0.002658664);
   h00->SetBinContent(54,0.002477941);
   h00->SetBinContent(55,0.002252585);
   h00->SetBinContent(56,0.002051374);
   h00->SetBinContent(57,0.001885527);
   h00->SetBinContent(58,0.001727242);
   h00->SetBinContent(59,0.001591882);
   h00->SetBinContent(60,0.001460424);
   h00->SetBinContent(61,0.001335551);
   h00->SetBinContent(62,0.001221654);
   h00->SetBinContent(63,0.001137267);
   h00->SetBinContent(64,0.00104093);
   h00->SetBinContent(65,0.000993859);
   h00->SetBinContent(66,0.0009416662);
   h00->SetBinContent(67,0.0008367928);
   h00->SetBinContent(68,0.0008009406);
   h00->SetBinContent(69,0.0007175297);
   h00->SetBinContent(70,0.0006863115);
   h00->SetBinContent(71,0.0006733852);
   h00->SetBinContent(72,0.0006068028);
   h00->SetBinContent(73,0.0005650973);
   h00->SetBinContent(74,0.0005329036);
   h00->SetBinContent(75,0.000493637);
   h00->SetBinContent(76,0.0004829057);
   h00->SetBinContent(77,0.0004543704);
   h00->SetBinContent(78,0.0004092504);
   h00->SetBinContent(79,0.0003870563);
   h00->SetBinContent(80,0.00037413);
   h00->SetBinContent(81,0.0003465702);
   h00->SetBinContent(82,0.0003321806);
   h00->SetBinContent(83,0.0003197421);
   h00->SetBinContent(84,0.0002970602);
   h00->SetBinContent(85,0.0002782805);
   h00->SetBinContent(86,0.0002504769);
   h00->SetBinContent(87,0.0002443796);
   h00->SetBinContent(88,0.0002195026);
   h00->SetBinContent(89,0.0002092592);
   h00->SetBinContent(90,0.0002014546);
   h00->SetBinContent(91,0.0001907234);
   h00->SetBinContent(92,0.0001799921);
   h00->SetBinContent(93,0.0001716998);
   h00->SetBinContent(94,0.0001529202);
   h00->SetBinContent(95,0.0001404817);
   h00->SetBinContent(96,0.0001292627);
   h00->SetBinContent(97,0.0001282871);
   h00->SetBinContent(98,0.0001199948);
   h00->SetBinContent(99,0.0001095074);
   h00->SetBinContent(100,0.0001004834);
   h00->SetBinContent(101,9.438612e-05);
   h00->SetBinContent(102,8.926439e-05);
   h00->SetBinContent(103,8.145986e-05);
   h00->SetBinContent(104,7.146029e-05);
   h00->SetBinContent(105,7.853316e-05);
   h00->SetBinContent(106,6.609468e-05);
   h00->SetBinContent(107,5.438787e-05);
   h00->SetBinContent(108,6.194851e-05);
   h00->SetBinContent(109,5.170506e-05);
   h00->SetBinContent(110,5.194895e-05);
   h00->SetBinContent(111,4.292496e-05);
   h00->SetBinContent(112,5.04856e-05);
   h00->SetBinContent(113,3.85349e-05);
   h00->SetBinContent(114,3.804712e-05);
   h00->SetBinContent(115,3.707155e-05);
   h00->SetBinContent(116,2.804756e-05);
   h00->SetBinContent(117,2.487696e-05);
   h00->SetBinContent(118,3.170593e-05);
   h00->SetBinContent(119,2.707199e-05);
   h00->SetBinContent(120,2.512085e-05);
   h00->SetBinContent(121,2.341361e-05);
   h00->SetBinContent(122,1.902356e-05);
   h00->SetBinContent(123,2.292583e-05);
   h00->SetBinContent(124,1.756021e-05);
   h00->SetBinContent(125,1.658464e-05);
   h00->SetBinContent(126,1.902356e-05);
   h00->SetBinContent(127,1.390183e-05);
   h00->SetBinContent(128,1.438962e-05);
   h00->SetBinContent(129,1.243848e-05);
   h00->SetBinContent(130,1.243848e-05);
   h00->SetBinContent(131,1.414572e-05);
   h00->SetBinContent(132,0.000187065);
   h00->SetEntries(4100946);
   h00->SetStats(0);
   h00->GetXaxis()->SetLabelFont(42);
   h00->GetXaxis()->SetLabelSize(0.035);
   h00->GetXaxis()->SetTitleSize(0.035);
   h00->GetXaxis()->SetTitleFont(42);
   h00->GetYaxis()->SetLabelFont(42);
   h00->GetYaxis()->SetLabelSize(0.035);
   h00->GetYaxis()->SetTitleSize(0.035);
   h00->GetYaxis()->SetTitleFont(42);
   h00->GetZaxis()->SetLabelFont(42);
   h00->GetZaxis()->SetLabelSize(0.035);
   h00->GetZaxis()->SetTitleSize(0.035);
   h00->GetZaxis()->SetTitleFont(42);
   hs0->Add(h00,"");
   
   TH1F *h01 = new TH1F("h01","nLongTracks",131,0,262);
   h01->SetBinContent(3,0.0001554811);
   h01->SetBinContent(4,0.001038058);
   h01->SetBinContent(5,0.003085664);
   h01->SetBinContent(6,0.006157433);
   h01->SetBinContent(7,0.01003104);
   h01->SetBinContent(8,0.01441182);
   h01->SetBinContent(9,0.01883117);
   h01->SetBinContent(10,0.02337295);
   h01->SetBinContent(11,0.02730406);
   h01->SetBinContent(12,0.03092061);
   h01->SetBinContent(13,0.03384911);
   h01->SetBinContent(14,0.03617031);
   h01->SetBinContent(15,0.03796253);
   h01->SetBinContent(16,0.03913667);
   h01->SetBinContent(17,0.03950297);
   h01->SetBinContent(18,0.03956047);
   h01->SetBinContent(19,0.03903126);
   h01->SetBinContent(20,0.03815059);
   h01->SetBinContent(21,0.03708211);
   h01->SetBinContent(22,0.0357192);
   h01->SetBinContent(23,0.03428489);
   h01->SetBinContent(24,0.03258346);
   h01->SetBinContent(25,0.03082741);
   h01->SetBinContent(26,0.02902081);
   h01->SetBinContent(27,0.02733592);
   h01->SetBinContent(28,0.02562922);
   h01->SetBinContent(29,0.02402362);
   h01->SetBinContent(30,0.02235022);
   h01->SetBinContent(31,0.02097365);
   h01->SetBinContent(32,0.01944423);
   h01->SetBinContent(33,0.01794884);
   h01->SetBinContent(34,0.0167426);
   h01->SetBinContent(35,0.01536388);
   h01->SetBinContent(36,0.01438835);
   h01->SetBinContent(37,0.01322955);
   h01->SetBinContent(38,0.01211195);
   h01->SetBinContent(39,0.011238);
   h01->SetBinContent(40,0.0103468);
   h01->SetBinContent(41,0.009351144);
   h01->SetBinContent(42,0.008639141);
   h01->SetBinContent(43,0.007902223);
   h01->SetBinContent(44,0.00723502);
   h01->SetBinContent(45,0.006582431);
   h01->SetBinContent(46,0.006056814);
   h01->SetBinContent(47,0.005459086);
   h01->SetBinContent(48,0.004933469);
   h01->SetBinContent(49,0.004535303);
   h01->SetBinContent(50,0.004104317);
   h01->SetBinContent(51,0.003658237);
   h01->SetBinContent(52,0.003309902);
   h01->SetBinContent(53,0.003048052);
   h01->SetBinContent(54,0.002759849);
   h01->SetBinContent(55,0.002473802);
   h01->SetBinContent(56,0.002284302);
   h01->SetBinContent(57,0.002063658);
   h01->SetBinContent(58,0.001891646);
   h01->SetBinContent(59,0.001732092);
   h01->SetBinContent(60,0.001612787);
   h01->SetBinContent(61,0.001502584);
   h01->SetBinContent(62,0.001371779);
   h01->SetBinContent(63,0.001225641);
   h01->SetBinContent(64,0.001156405);
   h01->SetBinContent(65,0.001067046);
   h01->SetBinContent(66,0.0009489376);
   h01->SetBinContent(67,0.0009041379);
   h01->SetBinContent(68,0.0008607757);
   h01->SetBinContent(69,0.0007728534);
   h01->SetBinContent(70,0.0007409906);
   h01->SetBinContent(71,0.0006707966);
   h01->SetBinContent(72,0.0006530684);
   h01->SetBinContent(73,0.0006068313);
   h01->SetBinContent(74,0.000566344);
   h01->SetBinContent(75,0.0005299292);
   h01->SetBinContent(76,0.0005102845);
   h01->SetBinContent(77,0.0004640475);
   h01->SetBinContent(78,0.000423081);
   h01->SetBinContent(79,0.0004055923);
   h01->SetBinContent(80,0.0003732504);
   h01->SetBinContent(81,0.0003521682);
   h01->SetBinContent(82,0.0003394709);
   h01->SetBinContent(83,0.0003080873);
   h01->SetBinContent(84,0.0002980253);
   h01->SetBinContent(85,0.0002795784);
   h01->SetBinContent(86,0.0002628085);
   h01->SetBinContent(87,0.0002419659);
   h01->SetBinContent(88,0.00022855);
   h01->SetBinContent(89,0.0002081865);
   h01->SetBinContent(90,0.0002017181);
   h01->SetBinContent(91,0.0001916562);
   h01->SetBinContent(92,0.000182792);
   h01->SetBinContent(93,0.0001665013);
   h01->SetBinContent(94,0.0001566789);
   h01->SetBinContent(95,0.0001367946);
   h01->SetBinContent(96,0.0001308053);
   h01->SetBinContent(97,0.0001257744);
   h01->SetBinContent(98,0.0001157124);
   h01->SetBinContent(99,0.0001145146);
   h01->SetBinContent(100,9.439066e-05);
   h01->SetBinContent(101,9.510937e-05);
   h01->SetBinContent(102,8.792226e-05);
   h01->SetBinContent(103,9.151582e-05);
   h01->SetBinContent(104,7.498547e-05);
   h01->SetBinContent(105,7.809988e-05);
   h01->SetBinContent(106,7.163149e-05);
   h01->SetBinContent(107,6.132997e-05);
   h01->SetBinContent(108,5.821556e-05);
   h01->SetBinContent(109,5.246587e-05);
   h01->SetBinContent(110,4.98306e-05);
   h01->SetBinContent(111,4.192478e-05);
   h01->SetBinContent(112,4.264349e-05);
   h01->SetBinContent(113,4.168521e-05);
   h01->SetBinContent(114,3.713338e-05);
   h01->SetBinContent(115,3.401897e-05);
   h01->SetBinContent(116,3.401897e-05);
   h01->SetBinContent(117,2.683186e-05);
   h01->SetBinContent(118,2.994627e-05);
   h01->SetBinContent(119,2.659229e-05);
   h01->SetBinContent(120,2.563401e-05);
   h01->SetBinContent(121,2.443616e-05);
   h01->SetBinContent(122,1.916561e-05);
   h01->SetBinContent(123,1.676991e-05);
   h01->SetBinContent(124,1.796776e-05);
   h01->SetBinContent(125,1.940519e-05);
   h01->SetEntries(4174142);
   h01->SetStats(0);
   h01->SetLineColor(2);
   h01->GetXaxis()->SetLabelFont(42);
   h01->GetXaxis()->SetLabelSize(0.035);
   h01->GetXaxis()->SetTitleSize(0.035);
   h01->GetXaxis()->SetTitleFont(42);
   h01->GetYaxis()->SetLabelFont(42);
   h01->GetYaxis()->SetLabelSize(0.035);
   h01->GetYaxis()->SetTitleSize(0.035);
   h01->GetYaxis()->SetTitleFont(42);
   h01->GetZaxis()->SetLabelFont(42);
   h01->GetZaxis()->SetLabelSize(0.035);
   h01->GetZaxis()->SetTitleSize(0.035);
   h01->GetZaxis()->SetTitleFont(42);
   hs0->Add(h01,"");
   hs0->Draw("nostack");
   
   TLegend *leg = new TLegend(0.7,0.7,0.97,0.93,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h00","B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h01","B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2935117,0.9343782,0.7064883,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("2011: data: nLongTracks");
   pt->Draw();
   c0->Modified();
   c0->cd();
   c0->SetSelected(c0);
}
