#include<stdlib.h>
#include<stdio.h>

void insertion_begin();
void insertion_pos();
void insertion_end();
void deletion_begin();
void deletion_pos();
void deletion_end();
void display();
void count();

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
    printf("\nLINKED lIST OPERATIONS\n");
    printf("-----------------------");
    printf("\n 1.InsertionAtFront \n 2.InsertionAtSpecific \n 3.InsertionAtEnd \n 4.DeletionAtBegin \n 5.DeletionAtSpecific \n 6.DeletionAtEnd \n 7.Display \n 8.Exit \n");
    printf("Enter the choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {

    case 1:
        insertion_begin();
         break;
    case 2:
        insertion_pos();
         break;
    case 3:
        insertion_end();
        break;
    case 4:
        deletion_begin();
        break;
    case 5:
        deletion_pos();
        break;
    case 6:
        deletion_end();
        break;
    case 7:
        display();
        break;
    case 8:
        exit(0);
    default:
        printf("Enter a valid choice:");
    }
    }
}

void insertion_begin()
{
    int value;
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted:");
    scanf("%d",&newNode->data);
    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
     newNode->next=head;
     head=newNode;
    }
    printf("Insertion successful at begin!!!\n");
}

 void insertion_end()
 {
     int value;
     struct node*newNode=NULL;
     newNode=(struct node*)malloc(sizeof(struct node));
     printf("Enter the value to be inserted:");
     scanf("%d",&newNode->data);
     newNode->next=NULL;
     if(head==NULL)
     {
         newNode->next=head;
         head=newNode;
     }
     else
     {
         struct node*temp=head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=newNode;
     }
     printf("Insertion successful at end!!!!\n");
 }

 void insertion_pos()
 {
     int value,pos,i=1,count=0;
     struct node *newNode,*temp;
     newNode=(struct node*)malloc(sizeof(struct node));
     printf("Enter the position to insert:");
     scanf("%d",&pos);
     printf("Enter the value to be inserted:");
     scanf("%d",&newNode->data);
     count()
     if(pos>count)
     {

     }
     else
     {
         temp=head;
         while(i<pos)
         {
          temp=temp->next;
          i++;
         }
        newNode->next=temp->next;
        temp->next=newNode;
        printf("Insertion successful at specific position!!!\n");
     }
 }


void deletion_begin()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("List is empty!!!\n");
    }
    else
    {
       temp=head;
       head=head->next;
       free(temp);
    }
    printf("Node is deleted from beginning!!!!\n");
}


void deletion_end()
{
    if(head==NULL)
    {
        printf("List is empty!!!\n");
    }
    else{
  struct node*temp,*prevnode;
  temp=head;
  while(temp->next!=NULL)
  {
   prevnode=temp;
   temp=temp->next;
  }
  if(temp==head)
  {
      head=NULL;
  }
  else
  {
      prevnode->next=NULL;
  }
  free(temp);
  printf("Deletion successful at end!!!");
    }
}



void deletion_pos()
{
    int pos,i=1;
    struct node*temp,*nextNode;
    printf("Enter the position to be deleted:");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("List is empty!!!\n");
    }
    else
    {
      temp=head;
      while(i<pos-1)
      {
          temp=temp->next;
          i++;
      }
      nextNode=temp->next;
      temp->next=nextNode->next;
      free(nextNode);
    }
    printf("Deletion successful at specific pos!!!!\n");
}

 void display()
 {
 struct node*temp;
 if(head==NULL)
 {
     printf("List is empty!!!\n");
 }
 else
 {
     temp=head;
     printf("Linked list elements are:\n");
     while(temp!=NULL)
     {
         printf("-->%d\t",temp->data);
         temp=temp->next;
     }
 }
 }

 void count()
 {
     int count=0;
     struct node*temp=head;
     while(temp!=NULL)
     {
         count=count+1;
         temp=temp->next;
     }
   printf("Number of nodes is %d",count);

 }
