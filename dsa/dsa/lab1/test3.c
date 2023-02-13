/* Dynamic Memory alloc */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int *ptr;
  int i = 0, cardinal, temp = 0;
  fputs("Enter the number of elements for your array:", stdout);
  
  scanf("%d", &cardinal);
  ptr = (int *) malloc(sizeof(int));
  for(i = 0; i < cardinal; ++i)
    {
      fputs("Enter your element:\n", stdout);
      scanf("%d", (ptr + i));
      temp += *(ptr + i);
    }
  printf("\nThe sum is: %d\n", temp);
  return 0;
}
