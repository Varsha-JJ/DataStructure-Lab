#include<stdio.h>
void main()
{
int arr1,arr2,arr3;
printf("\n SORTING \n");
printf("Enter the size of the first array:");
scanf("%d",&arr1);
printf("Enter the size of the second array:");
scanf("%d",&arr2);
arr3=arr1+arr2;
printf("Enter the elements for first array:\n");
int a[arr1],b[arr2],c[arr3];
for(int i=0;i<arr1;i++)
  {
   scanf("%d",&a[i]);
   c[i]=a[i];
  }
  int x=arr2;
  printf("\nEnter the elements for second array:\n");
  for(int i=0;i<arr2;i++)
  {
   scanf("%d",&b[i]);
   c[x]=b[i];
   x++;
  }
  printf("The merged array is:\n");
  for(int i=0;i<arr3;i++)
  printf("\t%d",c[i]);

  printf("\nAfter sorting the array will be:\n");
  for(int i=0;i<arr3;i++)
  {
  int temp;
  for(int j=i+1;j<arr3;j++)
  {
   if(c[i]<c[j])
   {
    temp=c[i];
    c[i]=c[j];
    c[j]=temp;
   }
  }
  }
  for(int i=0;i<arr3;i++)
  {
  printf("\t%d",c[i]);
  }

}


