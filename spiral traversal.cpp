#include<bits/stdc++.h>
using namespace std;

struct node
{
int info;
node* left;
node* right;
}*temp,*temp1,*root;

void spiralprint(node* temp)
{
stack<node*> st1;
stack<node*> st2;

st1.push(temp);

while(st1.empty()==false || st2.empty()==false)
{
while(st1.empty()==false)
{
node *tp=st1.top();
st1.pop();
printf("%d ",tp->info);
if(tp->left) st2.push(tp->left);
if(tp->right) st2.push(tp->right);
}
while(st2.empty()==false)
{
	node *tp=st2.top();
	st2.pop();
	printf("%d ",tp->info);
	if(tp->right) st1.push(tp->right);
	if(tp->left) st1.push(tp->left);
}
}
}

main()
{
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
	    temp=(node*)malloc(sizeof(node));
		scanf("%d",&temp->info);
		temp->left=NULL;
		temp->right=NULL;
		if(i==0) root=temp;
		else{
			temp1=root;

			while(1)
			{
				if(temp->info>=temp1->info)
				{
					if(temp1->right==NULL) break;
					temp1=temp1->right;
				}
				else
				{
					if(temp1->left==NULL) break;
					temp1=temp1->left;
				}
			}
			if(temp->info>=temp1->info) temp1->right=temp;
			else temp1->left=temp;
		}
	}

	temp=root;

	spiralprint(temp);
}
