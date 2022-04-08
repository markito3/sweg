#include <iostream>
#include "src/my_class.h"

using namespace std;

int main() {
  my_class mine;
  float my_a = 7.0;
  mine.set_a(my_a);
  float a_out = mine.get_a();
  cout << a_out << endl;
}
