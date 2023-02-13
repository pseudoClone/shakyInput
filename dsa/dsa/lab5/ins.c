#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* #define NULL  ((void *) 0) */


typedef struct Node
{
  int info;
  struct Node* next;
}node;

node* head = NULL;


/* void create() */
/* { */
/*   char choice; */
/*   int ins_val; */
/*   node* newNode = (node*) malloc(sizeof(node)); */
  
/*   if(head == NULL) */
/*     head = newNode; */
/*   if(head == NULL) */
/*     { */
/*       printf("\nError in creating nodes\n"); */
/*       exit(0); */
/*     } */
/*   fputs("Do you want to insert data right now or later?\nPress Y for yes or if no press any other key:", stdout); */
/*   scanf("%d", &choice); */
/*   if(choice == 'y' || choice == 'Y') */
/*     { */
/*       printf("Enter the value you want to enter:"); */
/*       scanf("%d", &ins_val); */
/*       newNode -> info = ins_val; */
/*       newNode -> next = NULL; 	/\* Meaning this is the last node for now and its next will NULL by default *\/ */
/*     } */
/*   else */
/*     printf("\nOK, no worries\n"); */
/* } */

void
ins_begin()
{
  int ins_val;
  node*  newNode = (node*) malloc(sizeof(node));
  fputs("Enter the value you want to insert:",stdout);
  scanf("%d", &ins_val);
  
  newNode -> next = head;
  newNode -> info = ins_val;
  head = newNode;
  return;
}

void
ins_end()
{
  int ins_val;
  node* newNode = (node*) malloc(sizeof(node));
  fputs("Enter the value for insertion:", stdout);
  scanf("%d", &ins_val);
  if(head == NULL)
    head = newNode;
  node* ptr;
  ptr = head;
  while((ptr -> next ) != NULL)
    {
      ptr = ptr -> next;
    }
  ptr -> next = newNode;
  newNode -> next = NULL;
  free(ptr);
}

void
ins_pos()
{
  int pos;
  node * newNode = (node*) malloc(sizeof(node));
  node * ptr;
  if(head == NULL)
    head = newNode;
  printf("Enter thr position your want to insert your value:");
  scanf("%d", pos);
  ptr = head;
  for(int i = 0; i < pos - 1; ++i)
    ptr = ptr -> next;
  ptr -> next = newNode;
  newNode -> next = ptr -> next;
}

void delbeg()
{
  if(head == NULL)
    {
      printf("\nUnderflow error!!!\n");
      return;
    }
  node* temp = head;
  
  head = head -> next;
  free(temp);
  return;
}


void
del_end()
{
  if(head == NULL)
    {
      fputs("\nInvalid deletion operation of nodes\n Exiting......", stdout);
      exit(0);
    }
  node* ptr;
  node* temp;
  while(ptr -> next != NULL)
    {
      temp = ptr;
      ptr = ptr -> next;
    }
  temp -> next = NULL;
  printf("\nThe  deleted item is: %d\n", temp -> info);
  free(temp);free(ptr);
}
void
del_pos()
{
  int pos;
  node* ptr;
  node* temp;
  ptr = head;
  fputs("Enter the position at which you want deletion be done:", stdout);
  scanf("%d", &pos);
  for(int i = 0; i < pos; ++i)
    {
      temp = ptr;
      ptr = ptr -> next;
    }
  temp -> next = ptr -> next;
  free(temp);
  free(ptr);
}


void traverse()
{
  struct Node* ptr;
  ptr = head;
  if(head == NULL)
    {
      printf("\nEmpty list!! NO TRAVERSING POSSIBLE\n");
      exit(0);
    }
  else
    {
      while(ptr != NULL)
	{
	  printf("\n%d\n", ptr -> info);
	  ptr = ptr -> next;
	}
    }
  free(ptr);
  
}

int main(int argc, char *argv[])
{
  node* head = NULL;
  int choice;
  int xpos;
  printf("Enter your choice:\n");
  while(true)
    {
      printf("\n1.Insert\n2.Del\n3.Traverse\n4.Exit\n");
      scanf("%d", &choice);
      switch(choice)
	{
	  
	case 1:
	  printf("Enter the position you want to insert in:");
	  scanf("%d", &xpos);
	  if(xpos == 1)
	    ins_begin();
	  else if(xpos == 100)
	    ins_end();
	  else
	    ins_pos();
      
	  break;
	case 2:
	  printf("\nEnter the position you want to delete in:\n");
	  scanf("%s",xpos);
	  if(xpos == 1)
	    delbeg();
	  else if(xpos == 100)
	    del_end();
	  else
	    del_pos();
	  break;
	case 3:
	  traverse();
	  break;
	case 4:
	  fputs("\nExiting program......\n", stdout);
	  exit(0);
	  break;
	  
	default:
	  fputs("\nExiting program......\n", stdout);
	  exit(0);
	}
    }
  return 0;
}
