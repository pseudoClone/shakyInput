#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define MAXSIZE 100

char stack[MAXSIZE];
int top = -1;


int isEmpty()
{
  if(top == -1)
    return 1;
  return 0;
}

/* int isFull() */
/* { */
/*   if(top == MAXSIZE - 1) */
/*     return 1; */
/*   return 0; */
/* } */
void push(char x)
{
  stack[++top] = x;
}
int pop()
{
  if(isEmpty() == 1)
    {
      printf("\nERR!!\n,%d\x20");
      return -1;
    }

  return(stack[top--]);
}

/* int priority(char x) */
/* { */
/*   if(x == '(') */
/*     return 0; */
/*   if(x == '+' || x == '-') */
/*     return 1; */
/*   if(x == '*' || x == '/') */
/*     return 2; */
/* } */


int main(int argc, char *argv[])
{
  char x,y;
  char stq[100];
  char *e;
  
  printf("Enter your eval string:\x20");

  scanf("%s", stq);

  e = stq;

  while(*e !='\0')
    {
      if(isdigit(*e))
	{
	  push(*e);
	}
      if(*e == '*' || *e == '+' || *e == '/' ||*e == '-')
	{
	  x = pop();
	  y = pop();

	  if(*e == '+')
	    printf("\n%d\n",(x - 48) + (y - 48));
	  else if(*e == '-')
	    printf("\n%d\n",(x -48) - (y - 48));
	  else if(*e == '*')
	    printf("\n%d\n",(x -48) * (y - 48));
	  else
	    printf("\n%d\n",(x -48) / (y - 48));
	}
      e++;
    }

  return 0;
}
