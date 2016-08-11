#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node *right;
    node *left;
}*temp,*temp1,*root;

void leveltrav(node *temp)
{
queue<node*> q;
q.push(temp);
while(q.empty()==false)
{
node *tq=q.front();
q.pop();
printf("%d ",tq->info);
if(tq->left!=NULL) q.push(tq->left);
if(tq->right!=NULL) q.push(tq->right);
} 
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

leveltrav(temp);
}
