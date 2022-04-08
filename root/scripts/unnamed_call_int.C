{
  cout << "unnamed_call_int starts\n";
  cout << "load named_int.C\n";
  gROOT->ProcessLine(".L named_int.C");
  int j = 6;
  cout << "j = " << j << endl;
  cout << "call named_int\n";
  j = named_int();
  cout << "j = " << j << endl;
  cout << "unnamed_call_int ends\n";
}
