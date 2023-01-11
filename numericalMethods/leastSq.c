#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float x[50], y[50] , sumx=0 , sumxx=0 , sumy=0 , sumyx=0 , y_inter , x_inter;
  int n;
  
  printf("Enter the value of n: ");
  scanf("%d", &n);

  printf("\nEnter the values of array:\n");
  for(int i=0;i<n;i++)
    {
      printf("x[%d]:", i);
      scanf("%f", &x[i]);

      printf("y[%d]:", i);
      scanf("%f", &y[i]);
    }
  for(int i=0;i<n;i++)
    {
      sumx = sumx + x[i];
      sumxx = sumxx + x[i] * x[i];
      sumy = sumy + y[i];
      sumyx = sumyx + y[i] * x[i];
    }

  y_inter = (sumxx * sumy - sumyx * sumx) / (n * sumxx - sumx * sumx);
  x_inter = (n * sumyx - sumx * sumy) / (n * sumxx - sumx * sumx);
 
  printf("The required equation is y = %fx  %f\n",x_inter, y_inter);
 
  return 0;
}
