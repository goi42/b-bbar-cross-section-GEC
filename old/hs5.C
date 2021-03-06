{
//=========Macro generated from canvas: c5/2015nTracks
//=========  (Fri Oct  9 20:53:04 2015) by ROOT version5.34/32
   TCanvas *c5 = new TCanvas("c5", "2015nTracks",0,0,1200,800);
   gStyle->SetOptStat(0);
   c5->Range(-138.875,-0.006617421,1249.875,0.05955679);
   c5->SetFillColor(0);
   c5->SetBorderMode(0);
   c5->SetBorderSize(2);
   c5->SetFrameBorderMode(0);
   c5->SetFrameBorderMode(0);
   
   THStack *hs5 = new THStack();
   hs5->SetName("hs5");
   hs5->SetTitle("2015: B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}: nTracks");
   
   TH1F *hs5_stack_5 = new TH1F("hs5_stack_5","2015: B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}: nTracks",101,0,1111);
   hs5_stack_5->SetMinimum(0);
   hs5_stack_5->SetMaximum(0.05293937);
   hs5_stack_5->SetDirectory(0);
   hs5_stack_5->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hs5_stack_5->SetLineColor(ci);
   hs5_stack_5->GetXaxis()->SetLabelFont(42);
   hs5_stack_5->GetXaxis()->SetLabelSize(0.035);
   hs5_stack_5->GetXaxis()->SetTitleSize(0.035);
   hs5_stack_5->GetXaxis()->SetTitleFont(42);
   hs5_stack_5->GetYaxis()->SetLabelFont(42);
   hs5_stack_5->GetYaxis()->SetLabelSize(0.035);
   hs5_stack_5->GetYaxis()->SetTitleSize(0.035);
   hs5_stack_5->GetYaxis()->SetTitleFont(42);
   hs5_stack_5->GetZaxis()->SetLabelFont(42);
   hs5_stack_5->GetZaxis()->SetLabelSize(0.035);
   hs5_stack_5->GetZaxis()->SetTitleSize(0.035);
   hs5_stack_5->GetZaxis()->SetTitleFont(42);
   hs5->SetHistogram(hs5_stack_5);
   
   
   TH1F *h51 = new TH1F("h51","nTracks",101,0,1111);
   h51->SetBinContent(1,9.086242e-06);
   h51->SetBinContent(2,0.0005474461);
   h51->SetBinContent(3,0.00353682);
   h51->SetBinContent(4,0.007975449);
   h51->SetBinContent(5,0.01340448);
   h51->SetBinContent(6,0.01937414);
   h51->SetBinContent(7,0.02471912);
   h51->SetBinContent(8,0.02912141);
   h51->SetBinContent(9,0.03356685);
   h51->SetBinContent(10,0.03667434);
   h51->SetBinContent(11,0.03932526);
   h51->SetBinContent(12,0.04001581);
   h51->SetBinContent(13,0.04056326);
   h51->SetBinContent(14,0.04066093);
   h51->SetBinContent(15,0.0386824);
   h51->SetBinContent(16,0.03764203);
   h51->SetBinContent(17,0.03566804);
   h51->SetBinContent(18,0.03417109);
   h51->SetBinContent(19,0.03208352);
   h51->SetBinContent(20,0.03085006);
   h51->SetBinContent(21,0.02877613);
   h51->SetBinContent(22,0.02693162);
   h51->SetBinContent(23,0.02551644);
   h51->SetBinContent(24,0.02386501);
   h51->SetBinContent(25,0.02224766);
   h51->SetBinContent(26,0.02058715);
   h51->SetBinContent(27,0.01936732);
   h51->SetBinContent(28,0.01819293);
   h51->SetBinContent(29,0.0165256);
   h51->SetBinContent(30,0.01571238);
   h51->SetBinContent(31,0.01446984);
   h51->SetBinContent(32,0.01329772);
   h51->SetBinContent(33,0.01232776);
   h51->SetBinContent(34,0.01207789);
   h51->SetBinContent(35,0.01089668);
   h51->SetBinContent(36,0.01051505);
   h51->SetBinContent(37,0.009674576);
   h51->SetBinContent(38,0.009372459);
   h51->SetBinContent(39,0.008797754);
   h51->SetBinContent(40,0.008304825);
   h51->SetBinContent(41,0.007736935);
   h51->SetBinContent(42,0.007198575);
   h51->SetBinContent(43,0.006907816);
   h51->SetBinContent(44,0.006678388);
   h51->SetBinContent(45,0.005958303);
   h51->SetBinContent(46,0.005669815);
   h51->SetBinContent(47,0.0056471);
   h51->SetBinContent(48,0.005440387);
   h51->SetBinContent(49,0.005047407);
   h51->SetBinContent(50,0.004924743);
   h51->SetBinContent(51,0.004518134);
   h51->SetBinContent(52,0.004156956);
   h51->SetBinContent(53,0.004106981);
   h51->SetBinContent(54,0.003877554);
   h51->SetBinContent(55,0.003530005);
   h51->SetBinContent(56,0.003700372);
   h51->SetBinContent(57,0.003307392);
   h51->SetBinContent(58,0.003155197);
   h51->SetBinContent(59,0.003077965);
   h51->SetBinContent(60,0.003005275);
   h51->SetBinContent(61,0.00278039);
   h51->SetBinContent(62,0.002653183);
   h51->SetBinContent(63,0.002530518);
   h51->SetBinContent(64,0.00243057);
   h51->SetBinContent(65,0.002278375);
   h51->SetBinContent(66,0.002310177);
   h51->SetBinContent(67,0.002189784);
   h51->SetBinContent(68,0.00199443);
   h51->SetBinContent(69,0.001880852);
   h51->SetBinContent(70,0.001828606);
   h51->SetBinContent(71,0.001665054);
   h51->SetBinContent(72,0.001458342);
   h51->SetBinContent(73,0.001401553);
   h51->SetBinContent(74,0.001328863);
   h51->SetBinContent(75,0.001142595);
   h51->SetBinContent(76,0.001042646);
   h51->SetBinContent(77,0.0009086242);
   h51->SetBinContent(78,0.0007632443);
   h51->SetBinContent(79,0.0006996407);
   h51->SetBinContent(80,0.0005747048);
   h51->SetBinContent(81,0.0004815708);
   h51->SetBinContent(82,0.0004247818);
   h51->SetBinContent(83,0.0002862166);
   h51->SetBinContent(84,0.0002498717);
   h51->SetBinContent(85,0.0002589579);
   h51->SetBinContent(86,0.0002044405);
   h51->SetBinContent(87,0.0001431083);
   h51->SetBinContent(88,0.0001158496);
   h51->SetBinContent(89,7.723306e-05);
   h51->SetBinContent(90,5.451745e-05);
   h51->SetBinContent(91,5.451745e-05);
   h51->SetBinContent(92,4.088809e-05);
   h51->SetBinContent(93,1.817248e-05);
   h51->SetBinContent(94,1.362936e-05);
   h51->SetBinContent(95,9.086242e-06);
   h51->SetBinContent(96,6.814681e-06);
   h51->SetBinContent(97,4.543121e-06);
   h51->SetEntries(440226);
   h51->SetStats(0);

   ci = TColor::GetColor("#000099");
   h51->SetLineColor(ci);
   h51->GetXaxis()->SetRange(1,100);
   h51->GetXaxis()->SetLabelFont(42);
   h51->GetXaxis()->SetLabelSize(0.035);
   h51->GetXaxis()->SetTitleSize(0.035);
   h51->GetXaxis()->SetTitleFont(42);
   h51->GetYaxis()->SetLabelFont(42);
   h51->GetYaxis()->SetLabelSize(0.035);
   h51->GetYaxis()->SetTitleSize(0.035);
   h51->GetYaxis()->SetTitleFont(42);
   h51->GetZaxis()->SetLabelFont(42);
   h51->GetZaxis()->SetLabelSize(0.035);
   h51->GetZaxis()->SetTitleSize(0.035);
   h51->GetZaxis()->SetTitleFont(42);
   hs5->Add(h51,"");
   
   TH1F *h52 = new TH1F("h52","nTracks",106,0,848);
   h52->SetBinContent(2,0.0009498383);
   h52->SetBinContent(3,0.005891564);
   h52->SetBinContent(4,0.01678903);
   h52->SetBinContent(5,0.02377163);
   h52->SetBinContent(6,0.03144735);
   h52->SetBinContent(7,0.03498999);
   h52->SetBinContent(8,0.03982903);
   h52->SetBinContent(9,0.04376958);
   h52->SetBinContent(10,0.04750475);
   h52->SetBinContent(11,0.04667043);
   h52->SetBinContent(12,0.04895518);
   h52->SetBinContent(13,0.05041844);
   h52->SetBinContent(14,0.04794116);
   h52->SetBinContent(15,0.04849309);
   h52->SetBinContent(16,0.0464779);
   h52->SetBinContent(17,0.04257586);
   h52->SetBinContent(18,0.04006007);
   h52->SetBinContent(19,0.03746727);
   h52->SetBinContent(20,0.03338553);
   h52->SetBinContent(21,0.0308184);
   h52->SetBinContent(22,0.02828978);
   h52->SetBinContent(23,0.02537609);
   h52->SetBinContent(24,0.02377163);
   h52->SetBinContent(25,0.02153822);
   h52->SetBinContent(26,0.01930482);
   h52->SetBinContent(27,0.01667351);
   h52->SetBinContent(28,0.01536428);
   h52->SetBinContent(29,0.01405504);
   h52->SetBinContent(30,0.01197566);
   h52->SetBinContent(31,0.01117985);
   h52->SetBinContent(32,0.009883452);
   h52->SetBinContent(33,0.009023463);
   h52->SetBinContent(34,0.007881091);
   h52->SetBinContent(35,0.006892745);
   h52->SetBinContent(36,0.005827386);
   h52->SetBinContent(37,0.005673358);
   h52->SetBinContent(38,0.004967398);
   h52->SetBinContent(39,0.004762027);
   h52->SetBinContent(40,0.003516969);
   h52->SetBinContent(41,0.003581147);
   h52->SetBinContent(42,0.003067721);
   h52->SetBinContent(43,0.002733994);
   h52->SetBinContent(44,0.002348924);
   h52->SetBinContent(45,0.002631309);
   h52->SetBinContent(46,0.002182061);
   h52->SetBinContent(47,0.001553114);
   h52->SetBinContent(48,0.001989526);
   h52->SetBinContent(49,0.001578785);
   h52->SetBinContent(50,0.001373415);
   h52->SetBinContent(51,0.0009370026);
   h52->SetBinContent(52,0.001168044);
   h52->SetBinContent(53,0.001155209);
   h52->SetBinContent(54,0.0009498383);
   h52->SetBinContent(55,0.0007316322);
   h52->SetBinContent(56,0.0006032757);
   h52->SetBinContent(57,0.0007573035);
   h52->SetBinContent(58,0.0007829748);
   h52->SetBinContent(59,0.0005519331);
   h52->SetBinContent(60,0.0004235765);
   h52->SetBinContent(61,0.0005519331);
   h52->SetBinContent(62,0.0004235765);
   h52->SetBinContent(63,0.000256713);
   h52->SetBinContent(64,0.0003850696);
   h52->SetBinContent(65,0.0002823843);
   h52->SetBinContent(66,0.0002310417);
   h52->SetBinContent(67,0.0002310417);
   h52->SetBinContent(68,0.0001796991);
   h52->SetBinContent(69,0.0001283565);
   h52->SetBinContent(70,0.0001540278);
   h52->SetBinContent(71,0.0001668635);
   h52->SetBinContent(72,0.0001925348);
   h52->SetBinContent(73,0.0001796991);
   h52->SetBinContent(74,0.0001411922);
   h52->SetBinContent(75,0.0001155209);
   h52->SetBinContent(76,7.701392e-05);
   h52->SetBinContent(77,0.0001283565);
   h52->SetBinContent(78,0.0001155209);
   h52->SetBinContent(79,6.417826e-05);
   h52->SetBinContent(80,7.701392e-05);
   h52->SetBinContent(81,8.984956e-05);
   h52->SetBinContent(82,2.56713e-05);
   h52->SetBinContent(83,0.0001026852);
   h52->SetBinContent(84,3.850696e-05);
   h52->SetBinContent(85,1.283565e-05);
   h52->SetBinContent(86,5.134261e-05);
   h52->SetBinContent(87,5.134261e-05);
   h52->SetBinContent(88,5.134261e-05);
   h52->SetBinContent(89,1.283565e-05);
   h52->SetBinContent(90,1.283565e-05);
   h52->SetBinContent(91,1.283565e-05);
   h52->SetBinContent(93,2.56713e-05);
   h52->SetBinContent(94,2.56713e-05);
   h52->SetBinContent(95,1.283565e-05);
   h52->SetBinContent(98,8.984956e-05);
   h52->SetBinContent(100,1.283565e-05);
   h52->SetBinContent(101,1.283565e-05);
   h52->SetBinContent(102,1.283565e-05);
   h52->SetEntries(77908);
   h52->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   h52->SetLineColor(ci);
   h52->GetXaxis()->SetRange(1,100);
   h52->GetXaxis()->SetLabelFont(42);
   h52->GetXaxis()->SetLabelSize(0.035);
   h52->GetXaxis()->SetTitleSize(0.035);
   h52->GetXaxis()->SetTitleFont(42);
   h52->GetYaxis()->SetLabelFont(42);
   h52->GetYaxis()->SetLabelSize(0.035);
   h52->GetYaxis()->SetTitleSize(0.035);
   h52->GetYaxis()->SetTitleFont(42);
   h52->GetZaxis()->SetLabelFont(42);
   h52->GetZaxis()->SetLabelSize(0.035);
   h52->GetZaxis()->SetTitleSize(0.035);
   h52->GetZaxis()->SetTitleFont(42);
   hs5->Add(h52,"");
   hs5->Draw("nostack");
   
   TPaveText *pt = new TPaveText(0.246689,0.9234974,0.753311,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("2015: B^{-}->(D^{0}->K^{-} #pi^{+})#mu^{-}: nTracks");
   pt->Draw();
   c5->Modified();
   c5->cd();
   c5->SetSelected(c5);
}
