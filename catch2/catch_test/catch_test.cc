#include <iostream>
#include "const_func.h"
using namespace std;

int main() 
{
  int b = 7;
  function_w_ref(b);
  cout << "comes back as " << b << endl;
  function_w_const_ref(b);
  cout << "comes back as " << b << endl;
  int* ptr;
  ptr = new int;
  *ptr = 9;
  function_w_ref(*ptr);
  cout << "comes back as " << *ptr << endl;
  function_w_ptr(ptr);
  cout << "comes back as " << *ptr << endl;
  function_w_const_ptr(ptr);
  cout << "comes back as " << *ptr << endl;
  b = 12;
  function_w_val(b);
  cout << "comes back as " << b << endl;
  return b;
}
