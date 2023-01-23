#include <stdio.h>

int callSuperCoolFunc(int car)
{
  if(car == 0 || car == 1)
    return 1;
  else
    {
      return(callSuperCoolFunc(car - 1) + callSuperCoolFunc(car - 2));
    }
  
}


int main(int argc, char *argv[])
{
  int cardinality;

  printf("Enter the cardinality of the number:");
  scanf("%d", &cardinality);

  for(int i = 0; i < cardinality; ++i)
    printf(" %d ", callSuperCoolFunc(i));
  printf("\n");
  return 0;
}
