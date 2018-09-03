#include <stdio.h>
#include <math.h>

int main() {
  float x, y, z;
  x = sin(1.0);
  y = log(x);
  z = x*y;
  printf("x=%f, y=%f, z=%f\n", x, y, z);
  return 0;
}
