#include <stdio.h>
#include "funcs.h"

int main()
{
  float x, y, z;
  x = set_x();
  y = set_y();
  z = x + y;
  printf("%f %f %f\n", x, y, z);
  return 0;
}
