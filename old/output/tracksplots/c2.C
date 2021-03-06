{
//=========Macro generated from canvas: c2/2011nTracks
//=========  (Tue Oct 13 05:05:12 2015) by ROOT version5.34/32
   TCanvas *c2 = new TCanvas("c2", "2011nTracks",0,0,1200,800);
   gStyle->SetOptStat(0);
   c2->Range(-143,-0.009829393,1287,0.08846453);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetFrameBorderMode(0);
   c2->SetFrameBorderMode(0);
   
   THStack *hs2 = new THStack();
   hs2->SetName("hs2");
   hs2->SetTitle("2011: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nTracks");
   
   TH1F *hs2_stack_3 = new TH1F("hs2_stack_3","2011: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nTracks",104,0,1144);
   hs2_stack_3->SetMinimum(0);
   hs2_stack_3->SetMaximum(0.07863514);
   hs2_stack_3->SetDirectory(0);
   hs2_stack_3->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hs2_stack_3->SetLineColor(ci);
   hs2_stack_3->GetXaxis()->SetLabelFont(42);
   hs2_stack_3->GetXaxis()->SetLabelSize(0.035);
   hs2_stack_3->GetXaxis()->SetTitleSize(0.035);
   hs2_stack_3->GetXaxis()->SetTitleFont(42);
   hs2_stack_3->GetYaxis()->SetLabelFont(42);
   hs2_stack_3->GetYaxis()->SetLabelSize(0.035);
   hs2_stack_3->GetYaxis()->SetTitleSize(0.035);
   hs2_stack_3->GetYaxis()->SetTitleFont(42);
   hs2_stack_3->GetZaxis()->SetLabelFont(42);
   hs2_stack_3->GetZaxis()->SetLabelSize(0.035);
   hs2_stack_3->GetZaxis()->SetTitleSize(0.035);
   hs2_stack_3->GetZaxis()->SetTitleFont(42);
   hs2->SetHistogram(hs2_stack_3);
   
   
   TH1F *h20 = new TH1F("h20","nTracks",104,0,1144);
   h20->SetBinContent(1,7.187106e-07);
   h20->SetBinContent(2,0.0005677813);
   h20->SetBinContent(3,0.004728397);
   h20->SetBinContent(4,0.01314258);
   h20->SetBinContent(5,0.0239024);
   h20->SetBinContent(6,0.03547052);
   h20->SetBinContent(7,0.0460636);
   h20->SetBinContent(8,0.05500484);
   h20->SetBinContent(9,0.06170538);
   h20->SetBinContent(10,0.06492185);
   h20->SetBinContent(11,0.06641844);
   h20->SetBinContent(12,0.06523592);
   h20->SetBinContent(13,0.06233952);
   h20->SetBinContent(14,0.05847429);
   h20->SetBinContent(15,0.05393348);
   h20->SetBinContent(16,0.04925299);
   h20->SetBinContent(17,0.04438062);
   h20->SetBinContent(18,0.03967043);
   h20->SetBinContent(19,0.03540248);
   h20->SetBinContent(20,0.03147257);
   h20->SetBinContent(21,0.02765479);
   h20->SetBinContent(22,0.02448863);
   h20->SetBinContent(23,0.02112626);
   h20->SetBinContent(24,0.01826699);
   h20->SetBinContent(25,0.01550474);
   h20->SetBinContent(26,0.01281916);
   h20->SetBinContent(27,0.01049868);
   h20->SetBinContent(28,0.008788873);
   h20->SetBinContent(29,0.007231187);
   h20->SetBinContent(30,0.005960986);
   h20->SetBinContent(31,0.004953114);
   h20->SetBinContent(32,0.004138336);
   h20->SetBinContent(33,0.003464904);
   h20->SetBinContent(34,0.002944557);
   h20->SetBinContent(35,0.002556693);
   h20->SetBinContent(36,0.002174818);
   h20->SetBinContent(37,0.001910333);
   h20->SetBinContent(38,0.001671242);
   h20->SetBinContent(39,0.00146617);
   h20->SetBinContent(40,0.001281221);
   h20->SetBinContent(41,0.001135084);
   h20->SetBinContent(42,0.001022725);
   h20->SetBinContent(43,0.0008981486);
   h20->SetBinContent(44,0.0008056745);
   h20->SetBinContent(45,0.0007050551);
   h20->SetBinContent(46,0.0006202472);
   h20->SetBinContent(47,0.0005464596);
   h20->SetBinContent(48,0.0004913585);
   h20->SetBinContent(49,0.0004271537);
   h20->SetBinContent(50,0.0003737295);
   h20->SetBinContent(51,0.0003205449);
   h20->SetBinContent(52,0.000279818);
   h20->SetBinContent(53,0.0002438825);
   h20->SetBinContent(54,0.0001981245);
   h20->SetBinContent(55,0.0001648243);
   h20->SetBinContent(56,0.00014494);
   h20->SetBinContent(57,0.0001243369);
   h20->SetBinContent(58,0.0001094836);
   h20->SetBinContent(59,8.408914e-05);
   h20->SetBinContent(60,6.731923e-05);
   h20->SetBinContent(61,5.534072e-05);
   h20->SetBinContent(62,4.599748e-05);
   h20->SetBinContent(63,3.473768e-05);
   h20->SetBinContent(64,2.635272e-05);
   h20->SetBinContent(65,1.772819e-05);
   h20->SetBinContent(66,2.01239e-05);
   h20->SetBinContent(67,1.461378e-05);
   h20->SetBinContent(68,9.822378e-06);
   h20->SetBinContent(69,5.749685e-06);
   h20->SetBinContent(70,3.833123e-06);
   h20->SetBinContent(71,3.833123e-06);
   h20->SetBinContent(72,4.551834e-06);
   h20->SetBinContent(73,1.676991e-06);
   h20->SetBinContent(74,4.791404e-07);
   h20->SetBinContent(75,9.582808e-07);
   h20->SetBinContent(76,7.187106e-07);
   h20->SetEntries(4174142);
   h20->SetStats(0);
   h20->GetXaxis()->SetLabelFont(42);
   h20->GetXaxis()->SetLabelSize(0.035);
   h20->GetXaxis()->SetTitleSize(0.035);
   h20->GetXaxis()->SetTitleFont(42);
   h20->GetYaxis()->SetLabelFont(42);
   h20->GetYaxis()->SetLabelSize(0.035);
   h20->GetYaxis()->SetTitleSize(0.035);
   h20->GetYaxis()->SetTitleFont(42);
   h20->GetZaxis()->SetLabelFont(42);
   h20->GetZaxis()->SetLabelSize(0.035);
   h20->GetZaxis()->SetTitleSize(0.035);
   h20->GetZaxis()->SetTitleFont(42);
   hs2->Add(h20,"");
   
   TH1F *h21 = new TH1F("h21","nTracks",104,0,1144);
   h21->SetBinContent(2,0.001178054);
   h21->SetBinContent(3,0.0102659);
   h21->SetBinContent(4,0.033827);
   h21->SetBinContent(5,0.03769774);
   h21->SetBinContent(6,0.04846853);
   h21->SetBinContent(7,0.06311006);
   h21->SetBinContent(8,0.06529788);
   h21->SetBinContent(9,0.07068327);
   h21->SetBinContent(10,0.07489061);
   h21->SetBinContent(11,0.06630764);
   h21->SetBinContent(12,0.06563447);
   h21->SetBinContent(13,0.05923931);
   h21->SetBinContent(14,0.0622686);
   h21->SetBinContent(15,0.04846853);
   h21->SetBinContent(16,0.04325143);
   h21->SetBinContent(17,0.04358802);
   h21->SetBinContent(18,0.03534164);
   h21->SetBinContent(19,0.02558061);
   h21->SetBinContent(20,0.02558061);
   h21->SetBinContent(21,0.01918546);
   h21->SetBinContent(22,0.01952205);
   h21->SetBinContent(23,0.01228543);
   h21->SetBinContent(24,0.009761023);
   h21->SetBinContent(25,0.008582968);
   h21->SetBinContent(26,0.009256143);
   h21->SetBinContent(27,0.007068327);
   h21->SetBinContent(28,0.004207338);
   h21->SetBinContent(29,0.003029283);
   h21->SetBinContent(30,0.006395153);
   h21->SetBinContent(31,0.002524402);
   h21->SetBinContent(32,0.002692696);
   h21->SetBinContent(33,0.001178054);
   h21->SetBinContent(34,0.002019522);
   h21->SetBinContent(35,0.001851229);
   h21->SetBinContent(36,0.001514642);
   h21->SetBinContent(37,0.000336587);
   h21->SetBinContent(38,0.0005048805);
   h21->SetBinContent(39,0.002524402);
   h21->SetBinContent(40,0.001346348);
   h21->SetBinContent(41,0.0001682935);
   h21->SetBinContent(42,0.0005048805);
   h21->SetBinContent(43,0.000336587);
   h21->SetBinContent(47,0.0001682935);
   h21->SetBinContent(48,0.0001682935);
   h21->SetBinContent(49,0.0001682935);
   h21->SetBinContent(50,0.0001682935);
   h21->SetBinContent(52,0.001178054);
   h21->SetBinContent(53,0.0001682935);
   h21->SetBinContent(56,0.0001682935);
   h21->SetBinContent(57,0.0001682935);
   h21->SetBinContent(63,0.0001682935);
   h21->SetEntries(5942);
   h21->SetStats(0);
   h21->SetLineColor(2);
   h21->GetXaxis()->SetLabelFont(42);
   h21->GetXaxis()->SetLabelSize(0.035);
   h21->GetXaxis()->SetTitleSize(0.035);
   h21->GetXaxis()->SetTitleFont(42);
   h21->GetYaxis()->SetLabelFont(42);
   h21->GetYaxis()->SetLabelSize(0.035);
   h21->GetYaxis()->SetTitleSize(0.035);
   h21->GetYaxis()->SetTitleFont(42);
   h21->GetZaxis()->SetLabelFont(42);
   h21->GetZaxis()->SetLabelSize(0.035);
   h21->GetZaxis()->SetTitleSize(0.035);
   h21->GetZaxis()->SetTitleFont(42);
   hs2->Add(h21,"");
   hs2->Draw("nostack");
   
   TLegend *leg = new TLegend(0.7,0.7,0.97,0.93,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h20","data","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h21","MC","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2270401,0.9234974,0.7729599,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("2011: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nTracks");
   pt->Draw();
   c2->Modified();
   c2->cd();
   c2->SetSelected(c2);
}
