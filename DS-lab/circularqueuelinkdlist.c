#include<stdlib.h>
#include<stdio.h>

void insertion_begin();
void insertion_pos();
void insertion_end();
void deletion_begin();
void deletion_pos();
void deletion_end();
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
        printf("\nCIRCULAR LINKED LIST\n");
        printf("----------------------\n");
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
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted:");
    scanf("%d",&newNode->data);
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
    }
    else
    {
        struct node*temp=head;
        while(temp->next!=head)
        {
          temp=temp->next;
        }
        newNode->next=head;
        temp->next=newNode;
        head=newNode;
    }
    printf("Insertion successful at begin!!!\n");
}


void insertion_end()
{
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted:");
    scanf("%d",&newNode->data);
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=head)
        {
         temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }
    printf("Insertion successful at end!!!\n");
}


void insertion_pos()
{
    int key;
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted:");
    scanf("%d",&newNode->data);
    printf("Enter a data after which the node is to be inserted: ");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("Circular linked list is empty\n");
    }
    else
    {
        struct node *temp=head;
        while(temp->data!=key && temp->next!=head)
        {
            temp=temp->next;
        }
        if(temp->data==key)
        {
            newNode->next=temp->next;
            temp->next=newNode;
        }
        else
        {
            printf("Key not found\n");
        }

    }
  printf("Insertion successful at position!!!\n");
}

void deletion_begin()
{
   if(head==NULL)
   {
       printf("Circular linked list is empty\n");
   }
   else
   {
       struct node *temp=head;
       struct node *temp1=head;
       while(temp->next!=head)
       {
           temp=temp->next;
       }
       temp->next=head->next;
       head=temp->next;
       free(temp1);
   }
   printf("Deletion successful at begin!!!\n");
}

void deletion_pos()
{
    struct node *temp=head;
    struct node *temp1;
    int key;
    if(head==NULL)
    {
        printf("Circular linked list is empty\n");
    }
    else
    {
        printf("Enter a data which you want to delete: ");
        scanf("%d",&key);
        if(temp->data==key&&temp->next==head)
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
                printf("\n key not found\n");
            }
        }
    }
    printf("Deletion successful at position!!!\n");
}


void deletion_end()
{
  if(head==NULL)
  {
    printf("Circular linked list is empty\n");
  }
  else
    {
     struct node *temp=head;
     struct node *temp1=temp;
     while(temp->next!=head)
     {
      temp1=temp;
      temp=temp->next;
     }
    temp1->next=temp->next;
    free(temp);
    }
    printf("Deletion successful at end!!!\n");
}

void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
      printf("Circular linked list is empty!!!\n");
    }
    else
    {
      printf("The elements in the Circular Linked List are:\n");
      while(temp->next!=head)
      {
        printf("%d\t",temp->data);
        temp=temp->next;
      }
      printf("%d\t",temp->data);
     }
}
