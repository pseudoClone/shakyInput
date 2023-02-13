#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>

#define MAXSIZE 100

char stack[MAXSIZE];
int top = -1;


int isEmpty()
{
  if(top == -1)
    return 1;
  return 0;
}

int isFull()
{
  if(top == MAXSIZE - 1)
    return 1;
  return 0;
}
void push(char x)
{
  stack[++top] = x;
}
char pop()
{
  if(isEmpty() == 1)
    {
      printf("\nERR!!\n,%d\x20", errno);
      return -1;
    }

  return(stack[top--]);
}

int priority(char x)
{
  if(x == '(')
    return 0;
  if(x == '+' || x == '-')
    return 1;
  if(x == '*' || x == '/')
    return 2;
}


int main(int argc, char *argv[])
{
  int  xpop;
  char post[100];
  char *e;
  /* e = argv[1]; */
  /* if(argc < 2) */
  /*   { */
  /*     printf("\nLess arguments, please enter a valid argument\n"); */
  /*     exit(0); */
  /*   } */
  printf("Enter the symbols:\x20");
  scanf("%d", post);
  e = post;
  
  while(*e != '\0')
    {
      if (isalnum(*e))
	{
	  printf("\n%c\n", *e);
      	}
      else if(*e == '(')
	push(*e);
      else if(*e == ')')
	{
	  while((xpop = pop()) != '(')
	    printf("\n%c\n",xpop);
	}
      else
	{
	  while(priority(stack[top] >= priority(*e)))
	    printf("\n%c\n",pop());
	  push(*e);
	}
      e++;



      /* if(*argv[i] == '+' || *argv[i] == '*' || *argv[i] == '-' || *argv[i] == '/') */
      /* 	{ */
      /* 	  if(isEmpty() == 1) */
      /* 	    push(*argv[i]); */
      /* 	  else */
      /* 	    { */
      /* 	      if(priority(*argv[i] < stack[top])) */
      /* 		xpop = pop(); */
      /* 	      else */
      /* 		push(*argv[i]); */
	      
      /* 	    } */
      /* 	} */


    }
  while(top != -1)
    printf("\n%c", pop());
  
  return 0;
}
