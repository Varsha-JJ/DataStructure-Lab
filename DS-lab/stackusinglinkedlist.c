#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();

struct node
{
int data;
struct node*next;
};
struct node*head=NULL;

void main()
{
int choice;
while(1)
{
 printf("\nSTACK OPERATION USING LINKED LIST\n");
 printf("\n 1.push \n 2.pop \n 3.display \n 4.exit \n");
 printf("Enter the choice:");
 scanf("%d",&choice);
 switch(choice)
  {
  case 1:
      push();
      break;
  case 2:
      pop();
      break;
  case 3:
      display();
      break;
  case 4:
      exit(0);
      break;
  default:
      printf("Enter a valid choice");
  }
 }
}
void push()
{
int value;
struct node *newNode;
newNode=(struct node*)malloc(sizeof(struct node));
if(newNode==NULL)
 {
  printf("The value can't push\n");
 }
 else
 {
  printf("Enter the value to insert:\n");
  scanf("%d",&value);
  if(head==NULL)
  {
   newNode->data=value;
   newNode->next=NULL;
   head=newNode;
  }
  else
  {
  newNode->data=value;
  newNode->next=head;
  head=newNode;
  }
  printf("The value is pushed\n");
 }
}

void pop()
{
int value;
 struct node *p;
 if(head==NULL)
 {
 printf("UNDERFLOW");
 }
 else
 {
 value=head->data;
 p=head;
 head=head->next;
 free(p);
 printf("Value is popped");
 }
}

void display()
{
 int i;
 struct node *temp;
 temp=head;
 if(head==NULL)
 {
  printf("stack is empty");
 }
 else
 {
  printf("Stack elements are:\n");
  while(temp!=NULL)
  {
   printf("%d\n",temp->data);
   temp=temp->next;
  }
 }
}
