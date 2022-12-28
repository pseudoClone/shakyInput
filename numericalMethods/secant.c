#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (x-cos(x))

int main(int argc, char *argv[])
{
  long double g0, g1, g2, fnot, fone, ftwo, epsilon;
  int iteration = 0;
 first:
  fputs("Enter the value for initial guesses:\x20", stdout);
  scanf("%Lf%Lf", &g0, &g1);
  if(g1 == g2)
    {
      printf("\nHey!!!!\n");
      goto first;
    }
  printf("Enter the error bound:\x20", stdout);
  scanf("%Lf", &epsilon);
  printf("\ng0\t\t\tg1\t\t\tg2\t\t\tftwo\n");
  do
    {
      fnot = f(g0);
      fone = f(g1);
      g2 = g1 - (((g1 - g0)/ (fone - fnot)) * fone);
      ftwo = f(g2);
      
      printf("\n%Lf\t\t%Lf\t\t%Lf\t\t%Lf\n",g0,g1,g2,ftwo);
      g0 = g1;
      g1 = g2;
      iteration++;
    }
  while(fabs(ftwo) > epsilon);
  printf("\nThe root = %Lf\n",g2);
  return 0;
}
