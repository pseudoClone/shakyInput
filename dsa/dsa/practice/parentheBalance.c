#include <stdio.h>
#include <stdlib.h>

#define bool int

struct stack
{
  char dat;
  struct stack *next;
};

typedef struct stack Nodal;

Nodal* top = NULL;

void push(int val, Nodal* top_ref);

bool isMatchingPair(char char1, char char2)
{
  if (character1 == '(' && character2 == ')')
    return 1;
  else if (character1 == '{' && character2 == '}')
    return 1;
  else if (character1 == '[' && character2 == ']')
    return 1;
  else
    return 0;
}
