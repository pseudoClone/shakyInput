#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float funcx(float x)
{
  return(1 + (3 * pow(x,2)));
}

int main(int argc, char *argv[])
{
  float xp, x, y, h, n, m1, m2, m3, m4, fVal;


  fputs("Enter intital values: ", stdout);
  scanf("%f%f", &x, &y);

  fputs("Enter the value for step size: ", stdout);
  scanf("%f", &h);

  fputs("Enter the value for which  y is to be calculated: " ,stdout);
  scanf("%f", &xp);

  n = (xp - x) / h;

  for(int i = 0; i < n; ++i)
    {
      fVal = funcx(x);

      m1 = fVal;
      m2 = funcx(x + (h / 2));
      m3 = funcx(x + (h / 2));
      m4 = funcx(x + h);

      y += ((m1 + 2 * m2 + 2 * m3 + m4) /6 * h);
      x += h;
    }
  printf("\n x = %f \n y = %f\n", x, y);
  return 0;
}
