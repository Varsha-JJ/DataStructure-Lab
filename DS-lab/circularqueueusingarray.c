circularqueue.c
Who has access
Not shared
System properties
Type
C
Size
2 KB
Storage used
2 KB
Location
21/12/21
Owner
me
Modified
Dec 21, 2021 by me
Opened
8:06 AM by me
Created
Dec 21, 2021 with Google Drive Web
Add a description
Viewers can download
#include<stdio.h>
#define size 6
int queue[size],front=-1,rear=-1;

void enqueue();
void dequeue();
void display();

void main()
{
    int choice;
    while(1)
    {
        printf("\nCIRCULAR QUEUE USING ARRAY\n");
        printf("--------------------------\n");
        printf("\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice!!!\n");
        }
    }
}

void enqueue()
{
 int element;
 printf("Enter the value to inserted:");
 scanf("%d",&element);
 if(front==0 && rear==size-1)
 {
    printf("Circular Queue is full!!!\n");
 }
 else if(front==-1)
 {
    front=rear=0;
    queue[rear]=element;
 }
 else if(rear==size-1 && front!=0)
 {
     rear=0;
     queue[rear]=element;
 }
 else
 {
     rear++;
     queue[rear]=element;
 }
 printf("Enqueue successful!!!\n");
}

void dequeue()
{
    int element;
    if(front==-1)
    {
       printf("Queue is empty!!!\n");
    }
    else
    {
        element=queue[front];
        front=(front+1)%size;
    }
    printf("Deleted element is %d",element);
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty!!!\n");
    }
    printf("Elements in the circular queue are:\n");
    if(rear>=front)
    {
     for(i=front;i<=rear;i++)
     {
         printf("%d",queue[i]);
         printf("\n");
     }
    }
     else
     {
         for(i=front;i<size;i++)
         {
            printf("%d",queue[i]);
         }
        for(i=0;i<=rear;i++)
        {
         printf("%d",queue[i]);
        }
     }
   }

