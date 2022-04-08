{
  float cput, vmem;
  int run;
  ifstream input("job_data.txt");
  if (!input) {
    cout << "could not open file\n";
    return 1;
  }
  TFile *file = new TFile("hist.root", "RECREATE");
  TH1F *h9001 = new TH1F("CPU Time (hours)", "CPU Time", 80, 0.0, 40.0);
  TH1F *h9002 = new TH1F("CPU Time (hours)", "CPU Time", 80, 0.0, 40.0);
  TH1F *h9003 = new TH1F("CPU Time (hours)", "CPU Time", 80, 0.0, 40.0);
  gDirectory->pwd();
  while (input >> run >> cput >> vmem) {
    // cout << run << ' ' << cput << ' ' << vmem << endl;
    if (run == 9001) {
      h9001->Fill(cput);
    } else if (run == 9002) {
      h9002->Fill(cput);
    } else if (run == 9003) {
      h9003->Fill(cput);
    } else {
      cout << "bad run number " << run << endl;
    }
  }
  gDirectory->ls();
  h9001->SetLineColor(kBlue);
  h9001->Draw();
  h9002->SetLineColor(kRed);
  h9002->Draw("same");
  h9003->SetLineColor(kGreen);
  h9003->Draw("same");

  leg = new TLegend(0.1,0.7,0.48,0.9);
  //  leg->SetHeader("The Legend Title");
  leg->AddEntry(h9001,"run 9001, nominal rate background","l");
  leg->AddEntry(h9002,"run 9002, high rate background","l");
  leg->AddEntry(h9003,"run 9003, no background","l");
  leg->Draw();

  file->Write();
  return 0;
}
