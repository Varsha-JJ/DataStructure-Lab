#include<stdio.h>
#define max 10
void insert();
void deletion();
void display();
int queue[max],rear=-1,front=-1;
void main()
{
    int choice;
    while(1)
    {
        printf("\n QUEUE OPERATION USING ARRAY \n");
        printf("\n 1.Insertion \n 2.Deletion \n 3.Display \n 4.Exit \n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deletion();
            break;
        case 3:
          display();
          break;
        case 4:
            printf("Exit point\n");
        default:
            printf("Enter a valid choice");
        }
    }
}
void insert()
{
int item;
if(rear==max-1)
    printf("Queue is full");
else
{
    if(front==-1)
    front=0;
    printf("Maximum size of the queue is 10\n");
    printf("Enter the element to be inserted into the queue:");
    scanf("%d",&item);
    rear=rear+1;
    queue[rear]=item;
}
}
void deletion()
{
    if(front==rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Element deleted from the queue is %d",queue[front]);
        front=front+1;
        rear++;
    }
}
void display()
{
    int i;
    printf("Queue elements are:\n");
    if(front==rear)
    {
        printf("Queue is empty");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
        printf("%d",queue[i]);
        printf("\n");
        }
    }
}
