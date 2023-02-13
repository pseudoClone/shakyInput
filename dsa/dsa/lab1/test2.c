/* Find the sum of all elements of array */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
  int arr[5];
  int i = 0, temp = 0;
  for(i = 0; i < 5; ++i)
    {
      fputs("Enter your number:\n", stdout);
      scanf("%d", &arr[i]);
      temp += arr[i];
    }
  printf("The sum is: %d\n", temp);
  return 0;
}
