#include <stdio.h>
int main(int argc, char *argv[])
{
  char nuts[5];
  if((fgets(nuts, 5, stdin)) != NULL)
    printf("\n%s\n", nuts);
  return 0;
}
