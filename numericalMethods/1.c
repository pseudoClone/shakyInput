#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define f(a) (a*a) - (4*a) - 10

int main(int argc, char *argv[])
{
  double a, b,c, E = 0.0001, f1, f2;
  int i;
 first:
  fputs("Enter your guess for a and b init:", stdout);
  scanf("%lf%lf", &a, &b);
  f1 = f(a);
  f2 = f(b);
  if(f(a) * f(b) > 0)
    {
      fputs("\nInvalid input!!!\n", stdout);
      goto first;
    }
  else if(f(a) * f(b) == 0)
    {
      if(f(a) == 0)
	{
	  printf("\nThe solution is %lf\n",a);
	  return 0;
	}
      else
	{
	  printf("The solution is: %lf", b);
	  return 0;
	}
    }
  else
    while(true)
      {
	c = (a + b)/2;
	if(f(a) * f(c) < 0)
	  {
	    b = c;
	    f2 = f(c);
	  }
	else if(f(a) * f(c) == 0)
	  {
	    printf("\nThe root is %lf\n", c);
	    return 0;
	  }
	else
	{
	  a = c;
	  f1 = f(a);
	}
	if(fabs(f(b - a)) < E)
	  {
	    printf("\nThe root is %lf\n",c);
	    return 0;
	  }
      }
  return 0;
}
