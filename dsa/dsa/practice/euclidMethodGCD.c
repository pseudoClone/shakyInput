// EuclideanMethod

#include <stdio.h>
int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return (gcd(b%a, a));
}
int main(int argc, char *argv[])
{
  int x,y;
  fputs("Enter the numbers:",stdout);
  scanf("%d%d", &x, &y);
  printf("The GDC of x and y is: %d\n",gcd(x, y));
  return 0;
}
