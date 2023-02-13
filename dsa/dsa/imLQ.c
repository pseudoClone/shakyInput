#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

int queue[MAX];

int rear = -1;
int front = 0;
void enqueue(int val)
{
  if(rear == MAX - 1)
    {
      fputs("The queue is full\n",stdout);
      exit(0);
    }
  else
    {
      rear++;
      queue[rear] = val;
    }
}
int dequeue()
{
  int i, return_val;
  if(rear == -1)
    {
      printf("Invalid deletion operation in data structure\n");
      exit(0);
    }
  
  else
    {
      return_val = queue[0];
      for(i = 0; i < rear; ++i)
	queue[i] = queue[i+1];
      rear--;
      front++;
      return return_val; 
    }
}

void
traverse()
{
  if(rear == front - 1)
    fputs("\nThe queue is empty\n",stdout);
  for(int i = 0; i <= rear; ++i)
    printf("\n%d\n",queue[i]);
}

int main(int argc, char *argv[])
{
  printf("\n");
  int num_ch, ins_val;
  while(true)
    {
      printf("1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n");
      scanf("%d",&num_ch);
      switch(num_ch)
	{
	case 1:
	  printf("\nEnter the value for enqueueing\n");
	  scanf("%d", &ins_val);
	  enqueue(ins_val);
	  break;
	case 2:
	  printf("\nThe deleted value is:\x20%d\n",dequeue());
	  break;
	case 3:
	  traverse();
	  break;
	case 4:
	  printf("\nQuiting the program\n");
	  exit(0);
	  break;
	default:
	  printf("\nQuiting the program\n");
	  exit(0);
	}
    }
  return 0;
}
