const int debug_level = 1;

#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>
#include <TTree.h>
#include <TMatrixTSym.h>
#include <TMatrixD.h>
#include <TRandom.h>
#define MAXRESIDS 1024
using namespace std;
using namespace TMath;

struct event {
  Int_t run;
  Int_t event;
  Double_t chisq;
};

int main()
{

  TFile *file = new TFile("tree.root", "RECREATE");

  int count = 0;

  TTree *tree = new TTree("tree_example", "an example of a ROOT tree");
  event ev;
  string treeDef = "run/I";
  treeDef += ":event";
  treeDef += ":chisq/D";
  tree->Branch("event", &ev.run, treeDef.c_str());
  Int_t nResids;
  Double_t resids[MAXRESIDS];
  tree->Branch("nResids", &nResids, "nResids/I");
  tree->Branch("resids", resids, "resids[nResids]/D");

  gRandom->SetSeed();

  Float_t x, y;
  ev.run = 1234;
  // loop over events
  for (int i = 1; i <= 1000; i++) {
    count++; // increment event count
    nResids = 0;
    // event number
    ev.event = count;
    Float_t random = gRandom->Rndm(1);
    nResids = (int)(10.0*random);
    cout << nResids << endl;
    random = gRandom->Rndm(1);
    ev.chisq = random*random;
    for (int j = 0; j < nResids; j++) {
      gRandom->Rannor(x,y);
      cout << x << " " << y << endl;
      resids[j] = (double)x;
    }
    tree->Fill();
  }
  
  tree->Print();
  file->Write();
  
  return 0;
  
}
