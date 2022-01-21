{
  // open a file
  TFile *file = new TFile("hist.root", "RECREATE");
  gDirectory->pwd();
  Float_t data;
  TH1F *h1 = new TH1F("example_name", "example_title", Int_t bins = 50, Double_t xlow = 0.0, Double_t xhigh = 10.0);
  for (Int_t i = 0; i < 100; i++) {
    data = float(i*i) / 1000.0;
    h1->Fill(data);
  }
  gDirectory->ls();
  h1->Draw();
  file->Write();
}
