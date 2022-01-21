{
  TFile f("hist.root");
  f.ls();
  example_name->Draw(); // non-C++ root extension
}
