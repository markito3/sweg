#include <stdio.h>

class eg {
  int x, y, z;
 public:
  eg():x(2) {}
  int f(int i, int j) {
    printf("x,y,z = %d %d %d\n", x, y, z);
    return i*j*x*y*z;
  }
};

int main()
{
  int a, b, c;
  a=7;
  c = a*b;
  printf("%d %d %d\n", a, b, c);
  eg myeg;
  b=4;
  c = myeg.f(a,b);
  printf("%d %d %d\n", a, b, c);
};
