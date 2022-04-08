#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
using namespace std;

void function_w_ref(int &a) {
  cout << "parameter = " << a << endl;
  a++;
  return;
}

TEST_CASE("argument passed as a reference comes back incremented", "[functions]") {
  int z = 7;
  function_w_ref(z);
  REQUIRE( z == 9 );
}

void function_w_const_ref(const int &a) {
  cout << "parameter = " << a << endl;
  // a++; // can't increment
  return;
}

void function_w_ptr(int *a) {
  cout << "parameter value = " << *a << endl;
  (*a)++;
  cout << "incremented value = " << *a << endl;
  return;
}

void function_w_const_ptr(const int *a) {
  cout << "parameter value = " << *a << endl;
  // (*a)++; // can't increment this either
  cout << "incremented value = " << *a << endl;
  a++; // increment the point
  cout << "value from next memory location = " << *a << endl;
  a--; // put it back where you found it
  return;
}

void function_w_val(int a) {
  cout << "parameter value = " << a << endl;
  a++;
  cout << "incremented value = " << a << endl;
  return;
}
