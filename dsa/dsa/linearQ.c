#include<stdio.h>
#include<stdlib.h>
//the MAX is defined for array size
#define MAX 5
int q[MAX];
//here r indicates the index of last element in queue
int r=-1;
//function to insert element in queue
void insert();
//function to delete an element from queue
int delet();
//function to delete all the elements from the queue
void traverse();
int main()
{
	int choice;
	int value;
	printf("in 1\n");
	while(1)
	{
		printf("1. To insert an element to queue\n");
		printf("2. To delete an element from queue\n");
		printf("3. To delete all the elements from queue\n");
		printf("4. To Exit\n");
		printf("enter choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:insert();
			break;
		case 2:value=delet();
			value==-1?printf("queue is empty\n"):printf("The deleted element is %d\n",value);
                   break;
            case 3:traverse();
                   break;
            case 4:exit(0);
            default:printf("Enter a valid choice\n");
         }
    }
}
void insert()
{
    int item;
    //this is the condition for overflow
    if(r==MAX-1)
        printf("queue is full\n");
    else
    {
        printf("Enter item other than -1\n");
        scanf("%d",&item);
        r=r+1;
        q[r]=item;
    }
}
int delet()
{
    int temp,i;
    if(r==-1)
        return -1;
    else
    {
        temp = q[0];
        for(i=0;i<r;i++)
            q[i]=q[i+1];
        r=r-1;
        return temp;
    }
}
void traverse()
{
    int i;
    for(i=0;i<=r;i++)
        printf("%d\n",q[i]);
}
