#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float func(float x)
{
  return(1 + pow(x , 3));
}

int main(int argc, char *argv[])
{
  float integralValue, upLim, lowLim, h;
  int strips, choice;
  
  fputs("Enter the upper and lower limts simultaneously:", stdout);
  scanf("%f%f", &upLim, &lowLim);

  fputs("Enter the number of strips: " ,stdout);
  scanf("%d", &strips);
  printf("1 for Composite Trapezoidal\n2 for composite Simpson\nEnter choice:");
  scanf("%d", &choice);

  //Composite Trapezoidal
  if (choice == 1)
    {
      
      h = (float) ((upLim - lowLim) / strips);

      
      integralValue = (h / 2) * (func(lowLim) + func(upLim));

      printf("The integral value is: %f\n", integralValue);
    }

  //Composite Simpson
  else if(choice == 2)
    {
      float sum;

      if(strips % 2 != 0)
	{
	  printf("\nNumber of subdivision should be even");
	  exit(0);
	}
      h = (upLim - lowLim) / strips;
      sum = func(lowLim) - func(lowLim + strips * h);
      for(int i = 1 ; i < strips ; ++i)
	sum += 4 * func(lowLim + i * h) + 2 * func(lowLim + (i + 1) * h);
      sum *= h / 6;
      
      printf("\n The integral value is: %f\n",sum);
    }
  return 0;  
}

