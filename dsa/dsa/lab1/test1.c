/* Program to display natural numbers upto 20 */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
  int i, cardinality = 20;
  fputs("Enter your number: ",stdout);
  scanf("%d", &cardinality);
  for(i = 1; i <= cardinality; ++i)
      {
	printf("\n%d\n", i);
      }
  return 0;
}
