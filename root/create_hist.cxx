#include <TFile.h>
#include <TH1F.h>

int main()
{
  // open a file
  TFile *file = new TFile("hist.root", "RECREATE");
  Float_t data;
  Int_t bins = 50;
  Double_t xlow = 0.0, xhigh = 10.0;
  TH1F *h1 = new TH1F("example_name", "example_title", bins = 50, xlow = 0.0, xhigh = 10.0);
  for (Int_t i = 0; i < 10000; i++) {
    data = float(i*i) / 10000000.0;
    h1->Fill(data);
  }
  gDirectory->ls();
  file->Write();
}
