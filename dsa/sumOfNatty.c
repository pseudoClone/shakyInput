#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int callFunc(int num)
{
  int temp = 0;
  if (num == 0)
    return 0;
  else if (num == 1)
    return 1;
  else
    {
      while (num != 0)
	{
	  temp += num;
	  num--;
	  callFunc(num);
	}
    }
  return temp;
}


int main(int argc, char *argv[])
{
  int n;
  printf("Enter the no. of natural numbers you want to sum:");
  scanf("%d", &n);

  printf("\nThe sum is %d\n",callFunc(n));
  return 0;
}
