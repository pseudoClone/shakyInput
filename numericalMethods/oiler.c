#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float funcx(float x)
{
  return(1 + (3 * pow(x,2)));
}

int main(int argc, char *argv[])
{
  float x, y, xp, h, fVal, n;
 
  
  printf("Enter the intial values x and y: ");
  scanf("%f%f", &x, &y);

  printf("Enter the step size: ");
  scanf("%f", &h);

  printf("Enter the value for which y is to be calculated: ");
  scanf("%f",&xp);

  n = (xp - x) / h;
  
  for(int i = 0; i < n; ++i)
    {
      fVal = funcx(x);
      y += (h * fVal);
      x += h;
      printf("\n The value is: x = %f & y = %f \n", x, y);
    }
  
  return 0;
}
