#include<stdio.h>
#include<stdlib.h>
int key;
struct bst
{
int data;
struct bst *left;
struct bst *right;
}*root=NULL;
void inorder(struct bst *temp)
{
if(temp!=NULL)
{
if(temp->left!=NULL)
inorder(temp->left);
printf("%d-->\t",temp->data);
if(temp->right!=NULL)
inorder(temp->right);
}
}
void preorder(struct bst *temp)
{
    if(temp!=NULL)
    {
            printf("%d-->\t",temp->data);
        if(temp->left!=NULL)
        {
                preorder(temp->left);
        }
        if(temp->right!=NULL)
        {
            preorder(temp->right);
        }

    }

}
void postorder(struct bst *temp)
{
if(temp!=NULL)
{
    if(temp->left!=NULL)
        postorder(temp->left);
    if(temp->right!=NULL)
        postorder(temp->right);
    printf("%d-->\t",temp->data);
}
}
struct bst* insert(struct bst *temp, int val)
{
if(temp==NULL)
{
temp=(struct bst*)malloc(sizeof(struct bst));
temp->data=val;
temp->left=NULL;
temp->right=NULL;

}
else
{
    if(val<temp->data)
    {
        temp->left=insert(temp->left,val);
    }
    else if(temp->data==val)
            printf("\n the data already exists\n");
        else
        {
            temp->right=insert(temp->right,val);
        }
}
return temp;
}
void search(struct bst *root1)
{
while(root1->data!=key)
{
if(root1->data==key)
    printf("\n key found\n");
else if(key<root1->data)
    search(root1->left);
else
    search(root1->right);
}
}
void main()
{
int opt,val;
do
{
printf("\n SELECT AN OPTION\n");
printf("\n1. INSERTION\n");
printf("\n2. SEARCHING\n");
printf("\n3. TRAVERSAL\n");
printf("\n4. EXIT \n");
scanf("%d",&opt);
switch(opt)
{
case 1: printf("\n enter data for new node: \n");
        scanf("%d",&val);
        root=insert(root,val);
        break;
case 2: printf("\n enter a value to be searched: \n");
        scanf("%d",&key);
        search(root);
        break;
case 3: printf("\n INORDER TRAVERSAL\n");
        inorder(root);
        printf("\n PREORDER TRAVERSAL\n");
        preorder(root);
        printf("\n POSTORDER TRAVERSAL\n");
        postorder(root);
        break;
case 4: exit(0);
}
}
while(opt!=4);
}
