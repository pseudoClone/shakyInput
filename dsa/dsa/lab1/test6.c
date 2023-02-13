/* Adding 2 numbers using pointers */

#include <stdio.h>

int
main(int argc, char *argv[])
{
  int *ptr1, *ptr2, *ptr3, a , b, sum;
  ptr1 = &a;
  ptr2 = &b;
  fputs("\nEnter the numbers you want to add:\n", stdout);
  scanf("%d%d",ptr1, ptr2);
  ptr3 = &sum;
  *ptr3 = *ptr1 + *ptr2;
  printf("The sum is: %d\n", *ptr3);
  return 0;
}
