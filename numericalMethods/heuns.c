#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float funcx(float x)
{
  return(1 + (3 * pow(x,2)));
}

int main(int argc, char *argv[])
{
  float x, y, xp, h, n, fVal, m2, m1;


  printf("Enter the initial values x and y: ");
  scanf("%f%f", &x, &y);

  printf("Enter step size: ");
  scanf("%f", &h);

  printf("Enter the value for which y is to be calculted: ");
  scanf("%f", &xp);

  n = (xp - x) / h;

  for(int i = 0; i < n; ++i)
    {
      m1 = fVal;
      m2 = funcx(x + h);
      fVal = funcx(x);
      y += ((h/2) * (m1 + m2));
      x += h;
    }
  printf("The value:\nx = %f\ny = %f\n", x, y);
  return 0;
}
