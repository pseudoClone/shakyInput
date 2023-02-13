#include <stdio.h>
#include <stdlib.h>

long squareFunc(int val )
{
  return(val * val);
}

int
main(int argc, char *argv[])
{
  int numberToSquare = 0;
  fputs("Enter a number for squaring:", stdout);
  scanf("%d", &numberToSquare);
  printf("\n%ld\n",squareFunc(numberToSquare));
  return 0;
}
