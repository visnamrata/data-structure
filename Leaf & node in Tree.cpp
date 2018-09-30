#include<iostream>
using namespace std;
struct node
{
	struct node *lp;
	struct node *rp;
	int data;
};
int getNode(struct node *p)
{
	if(p==NULL)
		return 0;
	else
	{
		if(p->rp==NULL && p->lp==NULL)
			return 0;
		else
		{
			int x= getNode(p->rp);
			int y= getNode(p->lp);
			return x+y+1;
		}
	}
}

int getLeaf(struct node*p)
{
	if(p==NULL)
		return 0;
	else
	{
		if(p->rp==NULL && p->lp==NULL)
			return 1;
		else
		{
			int x= getLeaf(p->rp);
			int y= getLeaf(p->lp);
			return x+y;
		}
	}
}
struct node *newNode(int d)
{
	struct node *n= new node();
	n->lp=NULL;
	n->rp=NULL;
	n->data=d;
	return n;
}
int main()
{
	int t;
	char ch;
	struct node *curr,*n;
	cout<<"Enter root: ";
	cin>>t;
	n=newNode(t);
	curr=n;
	
	while(1)
	{
		cout<<"\nEnter 'l' for left pointer";
		cout<<"\nEnter 'r' for right pointer";
		cout<<"\nEnter 'e' to goto root";
		cout<<"\nEnter 'q'to quit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 'l':  
						if(curr->lp==NULL)
						{
							cout<<"Enter data: ";
							cin>>t;
							curr->lp=newNode(t);
							curr=curr->lp;
						}
						else
						{
							curr=curr->lp;
							cout<<"\n\nData at this node is: "<<curr->data<<"\n\n";
						}
						break;
			case 'r':  if(curr->rp==NULL)
						{
							cout<<"Enter data: ";
							cin>>t;
							curr->rp=newNode(t);
							curr=curr->rp;
						}
						else
						{
							curr=curr->rp;
							cout<<"\n\nData at this node is: "<<curr->data<<"\n\n";
						}
						break;
			case 'e':   curr=n;
						cout<<"\n\nReached at root!!!!\n\n";
						break;
			case 'q':   
						break;
			default: 	cout<<"Wrong choice!!!!!";
						break;
		}
		if(ch=='q')
			break;
	}
	
	cout<<"\n\n"<<"Number of nodes are: "<<getNode(n);
	cout<<"\n"<<"Number of leaves are: "<<getLeaf(n);
}
