#include<stdio.h>
int main()
{
    int a[50];
    int size,i,choice,num,pos;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter %d  elements into array:",size);
        for(i=0;i<size;i++)
         {
           scanf("%d",&a[i]);
         }
         while(1)
         {
        printf("\n ARRAY OPERATIONS\n");
        printf("\n1.Insertion\n2.Traversal\n3.Deletion\n4.searching\n ");
        printf("Enter your choice:");
        scanf("%d",&choice);
         switch(choice)
        {
            case 1:
                 printf("Enter an element to insert:");
                 scanf("%d",&num);
                 printf("Enter the position:");
                 scanf("%d",&pos);
                 for(i=size-1;i>=pos-1;i--)
                   {
                    a[i+1]=a[i];
                   }
                 a[pos]=num;
                 printf("After insertion the array is:");
                 for(i=0;i<=size;i++)
                 printf("%d\t",a[i]);
                 break;

            case 2:
                printf("Element in the array are:");
                for(i=0;i<=size;i++)
                {
                    printf("%d\t",a[i]);
                }
                break;

            case 3:
                printf("Enter the position to delete element:");
                scanf("%d",&pos);
                for(i=pos-1;i<=size;i++)
                {
                    a[i]=a[i+1];
                }
                printf("Resultant array after deletion is:\n");
                for(i=0;i<=size;i++)
                printf("%d\t",a[i]);
                break;

            case 4:
                printf("Enter the element to be searched:");
                scanf("%d",&num);
                for(i=0;i<size;i++)
                {
                    if(a[i]==num)
                    {
                        printf("Element found at %d position",i);
                    }
                }
                break;

            default:
                printf("Invalid choice\n");
                return 0;
        }
     }
    }

