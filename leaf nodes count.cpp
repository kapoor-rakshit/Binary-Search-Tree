#include<bits/stdc++.h>
struct node
{
    int info;
    node* left;
    node* right;
}*root,*temp,*temp1;
int co=0;
void inorder(node* temp)
{
    if(temp==NULL)
        return;
    inorder(temp->left);
    printf("%d ",temp->info);
    inorder(temp->right);
}
void print(node* temp)
{
    if(temp==NULL)
        return;
    if(temp->left==NULL&&temp->right==NULL)
    {
        printf("%d ",temp->info);
        co++;
        return;
    }
    print(temp->left);
    print(temp->right);
}
main()
{
    int n;
    printf("Enter no.of nodes\n");
    scanf("%d",&n);
    printf("Enter info of nodes\n");
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
                if(temp->info<temp1->info)
                {
                    if(temp1->left==NULL)
                        break;
                    temp1=temp1->left;
                }
                else
                {
                    if(temp1->right==NULL)
                        break;
                    temp1=temp1->right;
                }
            }
         if(temp->info<temp1->info)
                temp1->left=temp;
         else
            temp1->right=temp;
        }
    }
    printf("\nInorder is\n");
    inorder(root);
    printf("\n");
    printf("Leaf nodes are\n");
    print(root);
    printf("\nNo. of leaf nodes are\n");
    printf("%d",co);
}
