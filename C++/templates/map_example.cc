#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
  
  map<string, string> my_map;
  my_map["a"] = "one";
  my_map["b"] = "two";

  cout << "value for b is " << my_map["b"] << endl;
      
  exit(0);
}
