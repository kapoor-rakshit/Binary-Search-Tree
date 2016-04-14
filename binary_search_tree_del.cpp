#include<bits/stdc++.h>
struct node
{
    int info;
    node *left;
    node *right;
}*temp,*temp1,*root,*parent,*t;
int dir_node;
void inorder(node *temp)
{

    if(temp==NULL)
        return;
    inorder(temp->left);
    printf("%d ",temp->info);
    inorder(temp->right);
}
void preorder(node *temp)
{

    if(temp==NULL)
        return;

    printf("%d ",temp->info);
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(node *temp)
{

    if(temp==NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->info);
}

void dele(node *pos)
{
   if(pos->left==NULL&&pos->right==NULL)
   {
       if(dir_node==1)
       {
           parent->left=NULL;
           free(pos);
       }
       else
       {
           parent->right=NULL;
           free(pos);
       }
   }
   else if(pos->right=NULL)
   {
       pos->info=pos->left->info;
       free(pos->left);
   }
   else if(pos->left=NULL)
   {
       pos->info=pos->right->info;
       free(pos->right);
   }
   else
   {
       temp=pos->right;
       while(temp->left!=NULL)
       {
           temp=temp->left;
       }
       pos->info=temp->info;
       dele(temp);
   }
}
node *sear(int val)
{
    temp=root;t=NULL;
    while(temp!=NULL)
    {
        if(val<temp->info)
        {
            dir_node=1;
            parent=temp;
            temp=temp->left;
        }
        else if(val>temp->info)
        {
            dir_node=2;
            parent=temp;
            temp=temp->right;
        }
        else
        {
            t=temp;
            break;
        }
    }
    return t;
}
main()
{
int n;
printf("Enter no.of elements to tree\n");
scanf("%d",&n);
printf("Enter %d elements to tree\n",n);
for(int i=0;i<n;i++)
{
    temp=(node*)malloc(sizeof(node));
    scanf("%d",&temp->info);
    temp->left=NULL;
    temp->right=NULL;
    if(i==0)
        root=temp;
    else
    {
        temp1=root;
        while(1)
        {
            if(temp->info>=temp1->info)
            {
                if(temp1->right==NULL)
                    break;
                temp1=temp1->right;
            }
            else
            {
                if(temp1->left==NULL)
                    break;
                temp1=temp1->left;
            }
        }
        if(temp->info>=temp1->info)
            temp1->right=temp;
        else
            temp1->left=temp;
    }
}

printf("\nPreorder is\n");
    preorder(root);
    printf("\n");

    printf("\nInorder is\n");
    inorder(root);
    printf("\n");

    printf("\nPostorder is\n");
    postorder(root);
    printf("\n");

printf("\nEnter no.of elements to be deleted\n");
int m;
scanf("%d",&m);
for(int i=0;i<m;i++)
{
    int val;
    scanf("%d",&val);
    node *pos=sear(val);
    if(pos!=NULL)
    dele(pos);
    else
        printf("\nElement to be deleted is not found\n");

    printf("\nPreorder is\n");
    preorder(root);
    printf("\n");

    printf("\nInorder is\n");
    inorder(root);
    printf("\n");

    printf("\nPostorder is\n");
    postorder(root);
    printf("\n");
}
}
