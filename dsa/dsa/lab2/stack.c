#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 20

int arr[MAX];
int top = -1;


void push(int val)
{
  int i = 0;
  if(top == (MAX - 1))
    {
      printf("\nInvalid push operation!!!\n");
      exit(0);
    }
  else
    {
      top++;
      arr[top] = val;
    }
  printf("\n%d pushed into the stack\n", val);
}
int pop()
{
  if(top == -1)
    {
      fputs("\nUnderflow, invalid pop operation!!!\n", stdout);
      exit(0);
    }
  int x;
  x = arr[top];
  arr[top]=0;
  top --;
  return(x);
}

int isEmpty()
{
  if(top == -1)
    return 1;
  else
    return 0;
}

int isFull()
{
  if(top == MAX)
    return 1;
  else
    return 0;
}

void traverse()
{
  int i = 0;
  if(isEmpty() == 1)
    printf("\nThe stack is empty\n");
  if(isFull() == 1)
    {
      printf("\nThe stack is full\n");
      for(i = 0; i < top; ++i)
	printf("%d\x20",arr[i]);
    }
  else
    {
      for(i = 0; i < top; ++i)
	printf("%d\x20",arr[i]);
    }
  
}
void peek()
{
  if(top == -1)
    fputs("\nThe stack is empty!\n", stdout);
  else
    printf("\n%d is at the top of stack\n",arr[top]);
      
}
int main(int argc, char *argv[])
{
  int i = 0, choice, pushx;
  while(true)
    {
      fputs("\n:::STACK OPERATION PROGRAM:::\n", stdout);
  printf("Enter choice:\n(1)\x20Push Element\n(2)\x20Pop Element\n(3)\x20Traverse Array\n(4) Check for empty\n(5) Check for full\n");
  printf("(6)\x20Peek at the stack\n(7) Exit\n");
      printf("\nEnter your choice from above mentioned options:\x20");
      scanf("%d", &choice);
      switch(choice)
	{
	case 1:
	  system("clear");
	  fputs("Enter your number for pushing:\x20", stdout);
	  scanf("%d", &pushx);
	  push(pushx);
	  break;
	case 2:
	  system("clear");
	  fputs("The poped element is:\x20", stdout);
	  printf("%d\n", pop());
	  break;
	case 3:
	  system("clear");
	  fputs("The traversal generates:\n", stdout);
	  for(i = 0; i < MAX; ++i)
	    printf("\x20%d\n",arr[i]);
	  break;
	case 4:
	  system("clear");
	  if(isEmpty() == 1)
	    printf("\nThe stack is empty\n");
	  else
	    fputs("\nNot empty\n", stdout);
	  break;
	case 5:
	  system("clear");
	  if(isFull() == 1)
	    fputs("\nThe stack is full\n", stdout);
	  else
	    printf("\nThe stack is not full\n");
	  break;
	case 6:
	  system("clear");
	  peek();
	  break;
	case 7:
	  exit(0);
	  break;
	default:
	  exit(0);
	}
    }
  return 0;
}
