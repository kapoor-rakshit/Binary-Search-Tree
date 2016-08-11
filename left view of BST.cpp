#include<bits/stdc++.h>
using namespace std;

struct node
{
int info;
node *left;
node *right;
}*temp,*root,*temp1;

void leftview(node *temp,int level,int *mxlevel)
{
if(temp==NULL) return;


if(*mxlevel<level)
{
printf("%d ",temp->info);
*mxlevel=level;
}
leftview(temp->left,level+1,mxlevel);
leftview(temp->right,level+1,mxlevel);
}

int main()
{
    int n;
    printf("Enter no. of elements to tree\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        temp=(node*)malloc(sizeof(node));
        scanf("%d",&temp->info);
        temp->right=NULL;
        temp->left=NULL;
        if(i==0)
        {
            root=temp;
        }
        else
        {
            temp1=root;
            while(1)
            {
                if((temp->info)>=(temp1->info))
                {
                    if(temp1->right==NULL)            //check before moving right
                        break;
                    temp1=temp1->right;
                }
                else
                {
                    if(temp1->left==NULL)            //check before moving left
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
    temp=root;

int level=1;
int mxlevel=0;
leftview(temp,level,&mxlevel);
}
