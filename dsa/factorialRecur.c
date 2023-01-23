#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int callCoolFunc(int num)
{
  int temp = 1;
  if(num == 0)
    return 0;
  else if(num == 1)
    return 1;
  else
    {
      return (num * callCoolFunc(num - 1));
    }
}

int main(int argc, char *argv[])
{
  int num;

  printf("Enter the number you want to do the factorial of:");
  scanf("%d", &num);

  printf("\nThe factorial is: %d\n",callCoolFunc(num));
  
  return 0;
}
