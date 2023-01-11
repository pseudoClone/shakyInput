#include <stdio.h>
#include <math.h>
#include <stdlib.h>



float func(float x)
{
  return(1 + pow(x , 3));
}
int main(int argc, char *argv[])
{
  float integralValue, h, up , low;

  printf("Enter lower limit:");
  scanf("%f", &low);
  printf("Enter upper limit:");
  scanf("%f", &up);

  h = (up - low) / 3;
  
  integralValue = ((3*h)/8) * (func(low) + 3 * func(low + h) + 3 * func(low + (2 * h)) + func(up));
  printf("The integral values is: %f\n", integralValue);

  
  return 0;
}
