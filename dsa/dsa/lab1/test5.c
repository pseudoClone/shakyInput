/* Program to calculate the area of a rectangle */

#include <stdio.h>

long
areax(int val1, int val2)
{
  return (val1*val2);
}

int
main(int argc, char *argv[])
{
  int length, breadth;
  fputs("Enter the length and breadth of the rectangle:",stdout);
  scanf("%d%d", &length, &breadth);
  printf("\n%ld sq. units\n", areax(length, breadth));
  return 0;
}
