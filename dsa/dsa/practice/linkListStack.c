#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int dat;
  struct Node* next;
};

struct Node* top = NULL;
typedef struct Node xNode;

void
push(int val)
{
  xNode* newNode;
  newNode = (xNode*) malloc(sizeof(xNode));
  newNode -> dat = val;		/* First assign then move pointer */
  if(top == NULL)
    newNode -> next = NULL;	/* Making node as top */
  else
    newNode -> next = top;
  top = newNode;
  fputs("\nNew element inserted\n", stdout);
}

int
pop()
{
  if(top == NULL)
    fputs("\nCheck stack for underflow\n", stdout);
  else
    {
      xNode* temp = top;
      int temp_data = top -> dat;
      top = top -> next;
      free(temp);
      return (temp_data);
    }
}
void
traverse()
{
  if (top == NULL)
    fputs("\nERROR!UNDERFLOW\n", stdout);
  else
    {
      fputs("\nHere is the stack:\n", stdout);
      xNode* temp = top;
      while(temp -> next != NULL)
	{
	  printf("\n%d---->", temp -> dat);
	  temp = temp -> next;
	}
      printf("\n%d---->NULL\n", temp -> dat);
    }
}
int main() {
  int choice, value;
  printf("\nImplementation of Stack using Linked List\n");
  while (1) {
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
    }
  }
}
/*
 *https://www.scaler.com/topics/c/stack-using-linked-list-in-c/
 */
