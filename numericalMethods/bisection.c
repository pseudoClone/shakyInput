#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>


#define f(x) (4*sin(x))-(exp(x))

int main(int argc, char *argv[])
{
  float f0, f1, f2, e, x, x2, x0, x1;
  int i = 0;
 first:
  printf("\nEnter vals and error: ");
  scanf("%f%f%f", &x1,&x2,&e);
  f1 = f(x1);
  f2 = f(x2);
  if (f1 * f2 > 0)
      goto first;
  printf("\ta\t\tb\t\tc\t\tf(a)\t\t\tf(b)\t\t\tf(c)\n");
  do
    {
      x0 = (x1 + x2) / 2;
      f0 = f(x0);
      printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n", (i+1), x1,x2,x0,f1,f2,f0);
      if(f1 * f0 < 0)
	{
	  x2 = x0;
	  f2 = f0;
	}
      else
	{
	  x1 = x0;
	  f1 = f0;
	}
      i++;
    }
  while(fabs(f0) > e);
  printf("\nThe root is %f\n",x0);
}
