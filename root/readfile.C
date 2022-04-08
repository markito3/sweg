{
  float x, y, z;
  ifstream input("data.txt");
  if (!input) {
    cout << "could not open file\n";
    return 1;
  }
  while (input >> x >> y >> z) {
    cout << x << ' ' << y << ' ' << z << endl;
  }
  return 0;
}
