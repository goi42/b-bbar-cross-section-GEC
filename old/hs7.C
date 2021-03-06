{
//=========Macro generated from canvas: c7/2015nTracks
//=========  (Fri Oct  9 20:53:04 2015) by ROOT version5.34/32
   TCanvas *c7 = new TCanvas("c7", "2015nTracks",0,0,1200,800);
   gStyle->SetOptStat(0);
   c7->Range(-143,-0.005564239,1287,0.05007815);
   c7->SetFillColor(0);
   c7->SetBorderMode(0);
   c7->SetBorderSize(2);
   c7->SetFrameBorderMode(0);
   c7->SetFrameBorderMode(0);
   
   THStack *hs7 = new THStack();
   hs7->SetName("hs7");
   hs7->SetTitle("2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nTracks");
   
   TH1F *hs7_stack_7 = new TH1F("hs7_stack_7","2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nTracks",104,0,1144);
   hs7_stack_7->SetMinimum(0);
   hs7_stack_7->SetMaximum(0.04451391);
   hs7_stack_7->SetDirectory(0);
   hs7_stack_7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hs7_stack_7->SetLineColor(ci);
   hs7_stack_7->GetXaxis()->SetLabelFont(42);
   hs7_stack_7->GetXaxis()->SetLabelSize(0.035);
   hs7_stack_7->GetXaxis()->SetTitleSize(0.035);
   hs7_stack_7->GetXaxis()->SetTitleFont(42);
   hs7_stack_7->GetYaxis()->SetLabelFont(42);
   hs7_stack_7->GetYaxis()->SetLabelSize(0.035);
   hs7_stack_7->GetYaxis()->SetTitleSize(0.035);
   hs7_stack_7->GetYaxis()->SetTitleFont(42);
   hs7_stack_7->GetZaxis()->SetLabelFont(42);
   hs7_stack_7->GetZaxis()->SetLabelSize(0.035);
   hs7_stack_7->GetZaxis()->SetTitleSize(0.035);
   hs7_stack_7->GetZaxis()->SetTitleFont(42);
   hs7->SetHistogram(hs7_stack_7);
   
   
   TH1F *h71 = new TH1F("h71","nTracks",104,0,1144);
   h71->SetBinContent(1,1.279309e-06);
   h71->SetBinContent(2,0.0002072481);
   h71->SetBinContent(3,0.001210226);
   h71->SetBinContent(4,0.003496351);
   h71->SetBinContent(5,0.006538548);
   h71->SetBinContent(6,0.01014748);
   h71->SetBinContent(7,0.01379607);
   h71->SetBinContent(8,0.01783485);
   h71->SetBinContent(9,0.0209973);
   h71->SetBinContent(10,0.02459088);
   h71->SetBinContent(11,0.02825993);
   h71->SetBinContent(12,0.02937933);
   h71->SetBinContent(13,0.0311742);
   h71->SetBinContent(14,0.03211833);
   h71->SetBinContent(15,0.0323614);
   h71->SetBinContent(16,0.03227697);
   h71->SetBinContent(17,0.03192643);
   h71->SetBinContent(18,0.03167441);
   h71->SetBinContent(19,0.03075715);
   h71->SetBinContent(20,0.03035928);
   h71->SetBinContent(21,0.02906718);
   h71->SetBinContent(22,0.02836868);
   h71->SetBinContent(23,0.02714694);
   h71->SetBinContent(24,0.02659811);
   h71->SetBinContent(25,0.02546337);
   h71->SetBinContent(26,0.02393587);
   h71->SetBinContent(27,0.02300709);
   h71->SetBinContent(28,0.02136446);
   h71->SetBinContent(29,0.0205457);
   h71->SetBinContent(30,0.0190374);
   h71->SetBinContent(31,0.01857045);
   h71->SetBinContent(32,0.0173986);
   h71->SetBinContent(33,0.01638411);
   h71->SetBinContent(34,0.01524169);
   h71->SetBinContent(35,0.01538497);
   h71->SetBinContent(36,0.01402251);
   h71->SetBinContent(37,0.01328051);
   h71->SetBinContent(38,0.01247326);
   h71->SetBinContent(39,0.01209843);
   h71->SetBinContent(40,0.01146005);
   h71->SetBinContent(41,0.01075771);
   h71->SetBinContent(42,0.01026773);
   h71->SetBinContent(43,0.009743217);
   h71->SetBinContent(44,0.009299297);
   h71->SetBinContent(45,0.008873287);
   h71->SetBinContent(46,0.008924459);
   h71->SetBinContent(47,0.008261777);
   h71->SetBinContent(48,0.007778198);
   h71->SetBinContent(49,0.007463489);
   h71->SetBinContent(50,0.007237051);
   h71->SetBinContent(51,0.006825113);
   h71->SetBinContent(52,0.006564134);
   h71->SetBinContent(53,0.006440041);
   h71->SetBinContent(54,0.005699322);
   h71->SetBinContent(55,0.005541966);
   h71->SetBinContent(56,0.005509984);
   h71->SetBinContent(57,0.005356467);
   h71->SetBinContent(58,0.005153057);
   h71->SetBinContent(59,0.004815319);
   h71->SetBinContent(60,0.004638774);
   h71->SetBinContent(61,0.004448157);
   h71->SetBinContent(62,0.003923641);
   h71->SetBinContent(63,0.003910847);
   h71->SetBinContent(64,0.003770123);
   h71->SetBinContent(65,0.003733024);
   h71->SetBinContent(66,0.003303176);
   h71->SetBinContent(67,0.003226417);
   h71->SetBinContent(68,0.003168848);
   h71->SetBinContent(69,0.003069062);
   h71->SetBinContent(70,0.002751793);
   h71->SetBinContent(71,0.002449877);
   h71->SetBinContent(72,0.002255422);
   h71->SetBinContent(73,0.002133887);
   h71->SetBinContent(74,0.002000839);
   h71->SetBinContent(75,0.001828133);
   h71->SetBinContent(76,0.001594019);
   h71->SetBinContent(77,0.00125884);
   h71->SetBinContent(78,0.001116837);
   h71->SetBinContent(79,0.001093809);
   h71->SetBinContent(80,0.0007675854);
   h71->SetBinContent(81,0.000633258);
   h71->SetBinContent(82,0.0005168408);
   h71->SetBinContent(83,0.0004400823);
   h71->SetBinContent(84,0.0003671617);
   h71->SetBinContent(85,0.0002801687);
   h71->SetBinContent(86,0.0001995722);
   h71->SetBinContent(87,0.0001560757);
   h71->SetBinContent(88,0.0001279309);
   h71->SetBinContent(89,9.97861e-05);
   h71->SetBinContent(90,7.547923e-05);
   h71->SetBinContent(91,5.117236e-05);
   h71->SetBinContent(92,3.070342e-05);
   h71->SetBinContent(93,6.268614e-05);
   h71->SetBinContent(94,1.918963e-05);
   h71->SetBinContent(95,1.535171e-05);
   h71->SetBinContent(96,6.396545e-06);
   h71->SetBinContent(97,1.279309e-06);
   h71->SetBinContent(98,1.279309e-06);
   h71->SetBinContent(101,3.837927e-06);
   h71->SetEntries(781672);
   h71->SetStats(0);

   ci = TColor::GetColor("#000099");
   h71->SetLineColor(ci);
   h71->GetXaxis()->SetRange(1,100);
   h71->GetXaxis()->SetLabelFont(42);
   h71->GetXaxis()->SetLabelSize(0.035);
   h71->GetXaxis()->SetTitleSize(0.035);
   h71->GetXaxis()->SetTitleFont(42);
   h71->GetYaxis()->SetLabelFont(42);
   h71->GetYaxis()->SetLabelSize(0.035);
   h71->GetYaxis()->SetTitleSize(0.035);
   h71->GetYaxis()->SetTitleFont(42);
   h71->GetZaxis()->SetLabelFont(42);
   h71->GetZaxis()->SetLabelSize(0.035);
   h71->GetZaxis()->SetTitleSize(0.035);
   h71->GetZaxis()->SetTitleFont(42);
   hs7->Add(h71,"");
   
   TH1F *h72 = new TH1F("h72","nTracks",103,0,824);
   h72->SetBinContent(2,7.29049e-05);
   h72->SetBinContent(3,0.001130026);
   h72->SetBinContent(4,0.005540772);
   h72->SetBinContent(5,0.009113112);
   h72->SetBinContent(6,0.01665877);
   h72->SetBinContent(7,0.01702329);
   h72->SetBinContent(8,0.01975723);
   h72->SetBinContent(9,0.02340247);
   h72->SetBinContent(10,0.02701126);
   h72->SetBinContent(11,0.03266139);
   h72->SetBinContent(12,0.03430175);
   h72->SetBinContent(13,0.03729085);
   h72->SetBinContent(14,0.03637954);
   h72->SetBinContent(15,0.0423942);
   h72->SetBinContent(16,0.04108191);
   h72->SetBinContent(17,0.03911348);
   h72->SetBinContent(18,0.03656181);
   h72->SetBinContent(19,0.03882186);
   h72->SetBinContent(20,0.03452047);
   h72->SetBinContent(21,0.03298946);
   h72->SetBinContent(22,0.03441111);
   h72->SetBinContent(23,0.03510371);
   h72->SetBinContent(24,0.02624576);
   h72->SetBinContent(25,0.03014617);
   h72->SetBinContent(26,0.02690191);
   h72->SetBinContent(27,0.02573543);
   h72->SetBinContent(28,0.0208508);
   h72->SetBinContent(29,0.02063209);
   h72->SetBinContent(30,0.02092371);
   h72->SetBinContent(31,0.01629424);
   h72->SetBinContent(32,0.01724201);
   h72->SetBinContent(33,0.01614843);
   h72->SetBinContent(34,0.01607553);
   h72->SetBinContent(35,0.01458098);
   h72->SetBinContent(36,0.01191995);
   h72->SetBinContent(37,0.01173769);
   h72->SetBinContent(38,0.009186016);
   h72->SetBinContent(39,0.009586994);
   h72->SetBinContent(40,0.008274706);
   h72->SetBinContent(41,0.008238253);
   h72->SetBinContent(42,0.007399847);
   h72->SetBinContent(43,0.0052127);
   h72->SetBinContent(44,0.005941749);
   h72->SetBinContent(45,0.004447198);
   h72->SetBinContent(46,0.005467867);
   h72->SetBinContent(47,0.003535887);
   h72->SetBinContent(48,0.004374294);
   h72->SetBinContent(49,0.003608792);
   h72->SetBinContent(50,0.002952648);
   h72->SetBinContent(51,0.004228484);
   h72->SetBinContent(52,0.003900412);
   h72->SetBinContent(53,0.002697481);
   h72->SetBinContent(54,0.002260052);
   h72->SetBinContent(55,0.004520103);
   h72->SetBinContent(56,0.00207779);
   h72->SetBinContent(57,0.001749718);
   h72->SetBinContent(58,0.002369409);
   h72->SetBinContent(59,0.002588124);
   h72->SetBinContent(60,0.00149455);
   h72->SetBinContent(61,0.002806838);
   h72->SetBinContent(62,0.001676813);
   h72->SetBinContent(63,0.0008019538);
   h72->SetBinContent(64,0.001348741);
   h72->SetBinContent(65,0.0009113112);
   h72->SetBinContent(66,0.0007655014);
   h72->SetBinContent(67,0.002041337);
   h72->SetBinContent(68,0.0005103343);
   h72->SetBinContent(69,0.0006196916);
   h72->SetBinContent(70,0.0008748588);
   h72->SetBinContent(71,0.0004738818);
   h72->SetBinContent(72,0.0005832392);
   h72->SetBinContent(73,0.0009842161);
   h72->SetBinContent(74,0.0006925965);
   h72->SetBinContent(75,0.001093573);
   h72->SetBinContent(76,0.0005832392);
   h72->SetBinContent(77,0.0006561441);
   h72->SetBinContent(78,0.0002551671);
   h72->SetBinContent(79,0.0001458098);
   h72->SetBinContent(80,0.0004738818);
   h72->SetBinContent(81,0.0005832392);
   h72->SetBinContent(82,0.0001822622);
   h72->SetBinContent(83,0.0009113112);
   h72->SetBinContent(84,0.0001822622);
   h72->SetBinContent(85,7.29049e-05);
   h72->SetBinContent(86,0.0003645245);
   h72->SetBinContent(87,0.0002916196);
   h72->SetBinContent(88,0.000328072);
   h72->SetBinContent(89,0.0002916196);
   h72->SetBinContent(90,0.0001093573);
   h72->SetBinContent(91,0.0001458098);
   h72->SetBinContent(93,0.0002916196);
   h72->SetBinContent(95,0.0002551671);
   h72->SetBinContent(96,0.0001093573);
   h72->SetBinContent(98,0.0006196916);
   h72->SetBinContent(99,7.29049e-05);
   h72->SetEntries(27433);
   h72->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   h72->SetLineColor(ci);
   h72->GetXaxis()->SetRange(1,100);
   h72->GetXaxis()->SetLabelFont(42);
   h72->GetXaxis()->SetLabelSize(0.035);
   h72->GetXaxis()->SetTitleSize(0.035);
   h72->GetXaxis()->SetTitleFont(42);
   h72->GetYaxis()->SetLabelFont(42);
   h72->GetYaxis()->SetLabelSize(0.035);
   h72->GetYaxis()->SetTitleSize(0.035);
   h72->GetYaxis()->SetTitleFont(42);
   h72->GetZaxis()->SetLabelFont(42);
   h72->GetZaxis()->SetLabelSize(0.035);
   h72->GetZaxis()->SetTitleSize(0.035);
   h72->GetZaxis()->SetTitleFont(42);
   hs7->Add(h72,"");
   hs7->Draw("nostack");
   
   TPaveText *pt = new TPaveText(0.2270401,0.9234974,0.7729599,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("2015: B^{0}->(D^{-}->K^{+} #pi^{-} #pi^{-})#mu^{+}: nTracks");
   pt->Draw();
   c7->Modified();
   c7->cd();
   c7->SetSelected(c7);
}
