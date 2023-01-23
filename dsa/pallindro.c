#include <stdio.h>
int rev = 0, rem;


int coolFuncPrince(int num)
{
  if(num > 0)
    {
      rem = num % 10;
      rev = rev * 10 + rem;
      
      num /= 10;
      coolFuncPrince(num);
    }  
  return rev;
 
}

int main(int argc, char *argv[])
{
  int number;

  printf("Enter your number: ");
  scanf("%d", &number);

  if(number == coolFuncPrince(number) )
    printf("\nPallindrome\n");
  else
    printf("\nNot a pallindrome\n");
  return 0;
}
