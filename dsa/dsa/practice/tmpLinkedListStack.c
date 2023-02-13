#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  int dat;
  struct stack* jmpx;
}Nodal;

Nodal* top = NULL;

void
push(int number)
{
  Nodal* newNode;
  newNode = (Nodal*) malloc(sizeof(Nodal));
  newNode -> dat = number;
  if (top == NULL)
    newNode -> jmpx = NULL;
  else
    newNode -> jmpx = top;
  top = newNode;
  fputs("\nNumber inserted in stack\n", stdout);
}
int
pop()
{
  if(top == NULL)
    {
      fputs("\nCheck for empty stack!!!\n", stdout);
      return 0;
    }
  
  else
    {
      Nodal* tmpPointer = top;
      int tmp_dat = top -> dat;
      free(tmpPointer);
      return (tmp_dat);
    }
}
void
traverse()
{
  if(top == NULL)
    fputs("\nEmpty stack, nothing to traverse\n", stdout);
  else
    {
      Nodal* tmpPointer = top;
      while(tmpPointer -> jmpx != NULL)
	{
	  printf("\n%d\n",tmpPointer -> dat);
	  tmpPointer = tmpPointer -> jmpx;
	}
      printf("\n%d\n", tmpPointer -> dat);
	}
}

int
main(int argc, char *argv[])
{
  int choice, value;
  for(;;)
    {
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("\nEnter your choice : ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
	printf("\nEnter the value to insert: ");
	scanf("%d", &value);
	push(value);
	break;
      case 2:
	printf("Popped element is :%d\n", pop());
	break;
      case 3:
	traverse();
	break;
      case 4:
	exit(0);
	break;
      default:
	printf("\nWrong Choice\n");
	exit(0);
      }
    }
  return 0;
}
