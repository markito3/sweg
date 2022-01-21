{
  TFile f("hist.root");
  f.ls();
  example_name->Draw(); // non-C++ root extension
  Double_t entries = example_name->GetEntries();
  Double_t mean = example_name->GetMean(1);
  Double_t sigma = example_name->GetMean(11);
  Double_t rms = example_name->GetStdDev(1);
  cout << entries << " " << mean << " " << sigma << " " << rms << endl;
}
