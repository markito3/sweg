{
  cout << "u_load_call_n starts\n";
  cout << "load named.C\n";
  gROOT->ProcessLine(".L named.C");
  cout << "call named\n";
  named();
  cout << "u_load_call_n ends\n";
}
