#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  float x[20],y[20], xp, yp, p = 0;
  int i,j,k,n;
  float l[i];

  printf("Enter the polynomial degree:\x20");
  scanf("%d", &n);
  printf("Enter the interpolation value:\x20");
  scanf("%f", &xp);

  for(i = 0; i < n; ++i)
    {
      printf("\nx[%d]:",i);
      scanf("%f", &x[i]);
      printf("\ny[%d]:",i);
      scanf("%f", &y[i]);
    }


  /* Now interpolating */

  for(i = 0; i < n; ++i)
    {
      l[i] = 1;
      for(j = 0; j < n; ++j)
	{
	  if(i != j)
	    {
	      l[i] = l[i]*((xp - x[j]) / (x[i] - x[j]));
	      printf("\nCalculating: %f\n", l[i]);
	    }
	  
	}
      p += y[i] * l[i];
    }
  printf("\nThe interpolation value is: %f\n", p);
  return 0;
}
