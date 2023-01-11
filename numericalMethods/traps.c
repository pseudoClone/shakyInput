#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>


/* Simple trap */

float func(float x)
{
  return(1 + pow(x , 3));
}

int main(int argc, char *argv[])
{
  int choice = 1;
  float varx, upLim, lowLim, h;
  
  printf("Enter the lower limit:");
  scanf("%f", &lowLim);
  
  printf("Enter the upper limit:");
  scanf("%f", &upLim);

 coolx:
  printf("1 for Simple Trap\n2 for 1/3 Trap\nEnter choice:");
  scanf("%d", &choice);

  if (choice == 1)
    {
      
      h = upLim - 1;
  
      varx = h/2 * (func(lowLim) + func(upLim));
      printf("\nThe integral value is: %f\n", varx);
    }
  else if (choice == 2)
    {
      h = (upLim - lowLim) / 2;
      varx = (h/3) * (func(lowLim) + 4 * (func((upLim + lowLim)/2) ) + func(upLim));
      printf("\n The integral value is : %f\n", varx);
    }
  else
    {
      printf("\nInvalid choice\n");
      goto coolx;
    }
  return 0;
}
