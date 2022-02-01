#include<stdio.h>
#include<stdlib.h>
void insert_front();
void insert_pos();
void insert_end();
void delete_front();
void delete_pos();
void delete_end();
void display();

struct node
{
 int data;
 struct node *prev;
 struct node *next;
};
struct node *head=NULL;


void main()
{
 int choice;
 while(1)
 {
 printf("DOUBLY lINKED lIST OPERATIONS\n");
 printf("-------------------------------");
 while(1)
 {
  printf("\n 1.InsertionFront\n 2.InserstionPos\n 3.InsertionEnd\n 4.DeletionFront\n 5.DeletionPos\n 6.DeletioEnd\n 7.Display\n 8.Exit\n");
  printf("Enter the choice:\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
       insert_front();
       break;
   case 2:
       insert_pos();
       break;
   case 3:
       insert_end();
       break;
   case 4:
       delete_front();
       break;
   case 5:
       delete_pos();
       break;
   case 6:
       delete_end();
       break;
   case 7:
       display();
       break;
   case 8:
       exit(0);
       break;
   default:
       printf("Enter a valid choice\n");
  }
 }
 }
}

void insert_front()
{
 int value;
 struct node *newNode;
 newNode=(struct node*)malloc(sizeof(struct node));
 printf("Enter the value to be inserted:");
 scanf("%d",&newNode->data);
 newNode->prev=NULL;
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
    printf("Insertion Successful at Begin!!!\n");
 }

 void insert_end()
 {
     int value;
     struct node *newNode;
     newNode=(struct node*)malloc(sizeof(struct node));
     printf("Enter the value to be inserted:");
     scanf("%d",&newNode->data);
     newNode->next=NULL;
     if(head==NULL)
     {
         newNode->prev=NULL;
         head=newNode;

     }
     else
     {
         struct node *temp=head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=newNode;
         newNode->prev=temp;
     }
     printf("Insertion successful at End!!!!\n");
 }

 void insert_pos()
 {
  int key;
  struct node *newNode;
  newNode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the value to be inserted:");
  scanf("%d",&newNode->data);
  printf("Enter the value to be inserted after a node:");
  scanf("%d",&key);
  if(head==NULL)
  {
      printf("Doubly Linked List is Empty!!!\n");
  }
  else
  {
      struct node *temp1=head;
      struct node *temp2;
      while(temp1->data!=key && temp1->next!=head)
      {
       temp1=temp1->next;
      }
      if(temp1->data==key)
      {
      temp2=temp1->next;
      temp1->next=newNode;
      newNode->prev=temp1;
      newNode->next=temp2;
      temp2->prev=newNode;
      printf("Insertion successful at Position!!!\n");
      }
      else
      {
          printf("Key not found!!!\n");
      }
  }
 }

void delete_front()
{
    if(head==NULL)
    {
        printf("List is empty!!!\n");
    }
    else
    {
        struct node *temp=head;
        if(temp->prev==temp->next)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            head=temp->next;
            head->prev=NULL;
            free(temp);
        }
    }
    printf("Deletion successful at Begin!!!\n");
}

void delete_end()
{
    if(head==NULL)
    {
        printf("List is empty\n!!!");
    }
    else
    {
        struct node *temp=head;
        if(temp->prev==temp->next)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->prev->next=NULL;
            free(temp);
        }
        printf("Deletion successful at End!!!\n");
    }

}

void delete_pos()
{
    int key;
    struct node *temp,*newNode,*temp1;
    if(head==NULL)
    {
        printf("Doubly Linked List is empty!!!\\n");
    }
    else
    {
        struct node *temp=head;
        printf("Enter the data which you want to delete:");
        scanf("%d",&key);
        if(temp->data==key && temp->next==head)
        {
         head=NULL;
         free(temp);
        }
        else if(temp->data ==key && temp->next!=head)
        {
            head=temp->next;
            free(temp);
        }
        else
        {
            while(temp->data!=key && temp->next!=head)
            {
                temp1=temp;
                temp=temp->next;
            }
            if(temp->data==key)
            {
                temp1->next=temp->next;
                free(temp);
            }
            else
            {
                printf("Key not found!!!\n");
            }
        }
    }
    printf("Deletion Successful at Position!!!\n");
}

void display()
{
    struct node *temp;
    if(head==NULL)
    {
       printf("List is empty\n");
    }
    else
    {
        temp=head;
        printf("List element are:\n");
        while(temp!=NULL)
        {
            printf("<===>%d",temp->data);
            temp=temp->next;
        }
    }

}
