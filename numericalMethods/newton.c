#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x)
{
  return (sin(x) - exp(-(x)));
}

double derivativeFunc(double x)
{
  return (cos(x) + exp(-(x)));
}

int main(int argc, char *argv[])
{
  float h, x0, x1, epsilon,f1;
  int iterationNumber = 1, validIter;
  fputs("Enter the initial guess close to solution:\x20", stdout);
  scanf("%f",&x0);
  fputs("Enter the episilon value and max number of allowed iterations:\x20", stdout);
  scanf("%f%d", &epsilon, &validIter);


  do
    {
      h = (func(x0)/derivativeFunc(x0));
      x1 = x0 - h;
      printf("Iteration (%d) =  %f\n",iterationNumber, x1);

      if(fabs(h) < epsilon)
	{
	  printf("In %d th iteratiton: zero of the function = %f\n", iterationNumber, x1);
	  exit(0);
	}
      x0 = x1;
      f1 = func(x1);
      iterationNumber++;
    }
  while(fabs(f1) > epsilon);
  return 1;
}

