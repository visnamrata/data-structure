#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>
struct node
{
	  node<T>* rp;
	  node<T>* lp;
	T data;

	void insertAtBegin(T d);
	void insertAfterX(T d, T x);
	void deleteAfterX(T x);
	void showall();
	int search(T x);
	void reverseDLL();
};
node <int> *start=NULL;

template <class T>
void node<T>::insertAtBegin(T d)
{
	struct node<int> *t= (struct node*) malloc(sizeof(struct node));	
	t->data=d;
	t->lp=NULL;
	if(start==NULL)
	{
		t->rp=NULL;
		start=t;
	}
	else
	{
		t->rp=start;
		start->lp=t;
		start=t;
	}
}

template <class T>
void node<T>::insertAfterX(T d, T x)	
{
	struct node *t= (struct node*) malloc(sizeof(struct node));	
	struct node *p;
	t->data=d;

	//now we'll find x
	p=start;
	while(p!=NULL && p->data!=x)
	{
		//cout<<("\nthis loop runs\n");
		p=p->rp;
	}
	if(p->data==x && p->rp!=NULL && p->lp!=NULL)
	{
		t->rp= p->rp;
		t->lp= p;

		p->rp=t;
		p->rp->rp->lp=t;
	}
	else if(p->data==x && p->rp==NULL)
	{
		p->rp=t;
		t->lp=p;
		t->rp=NULL;
	}
	else if(p->data==x && p->lp==NULL)
	{
		p->lp=t;
		t->rp=p;
		t->lp=NULL;
		start=t;
	}
}

template <class T>
void node<T>::deleteAfterX(T x)
{
	struct node* t=start;
	while(t->data!=x && t!=NULL)
		t=t->rp;
	struct node* temp= t->rp;
	t->rp=t->rp->rp;
	t->rp->lp=t;
	free(temp);
}

template <class T>
void node<T>::showall()
{
	struct node*t;
	t=start;
	while(t!=NULL)
	{
		cout<<t->data<<"->";
		t=t->rp;
	}
	cout<<"NULL";
}

template <class T>
int node<T>::search(T x)
{
	struct node*t;
	t=start;
	while(t!=NULL)
	{
		if(t->data==x)
			break;
		t=t->rp;
	}
	if(t->data==x)
		return 1;
	else
		return 0;
}

template <class T>
void node<T>:: reverseDLL()
{
	 struct node *temp = NULL;  
     struct node *current = start;
      
     /* swap next and prev for all nodes of 
       doubly linked list */
     while (current !=  NULL)
     {
       temp = current->lp;
       current->lp = current->rp;
       current->rp = temp;              
       current = current->lp;
     }      
      
     /* Before changing head, check for the cases like empty 
        list and list with only one node */
     if(temp != NULL )
        start = temp->lp;
}

int main()
{
	node<int> n1;
	int ch=0;
	int data,x,t;
	while(1)
	{
		cout<<"\n\nMenu:\n";
		cout<<"1. Insert at begin\n";
		cout<<"1. Insert after x\n";
		cout<<"3. Show all\n";
		cout<<"4. Delete after element 'x'\n";
		cout<<"5. Search a number\n";
		cout<<"6. Reverse DLL.\n";
		cout<<"7. Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1: cout<<"Enter value to be inserted: ";
					cin>>data;
					n1.insertAtBegin(data);
					break;
			case 2: cout<<"Enter value of 'x' after which data will be inserted: ";
					cin>>x;
					cout<<"Enter value to be inserted: ";
					cin>>data;
					n1.insertAfterX(data,x);
					break;
			case 3: n1.showall();
					break;
			case 4: cout<<"Enter value of 'x' after which data will be deleted: ";
					cin>>x;
					n1.deleteAfterX(x);
					break;
			case 5: cout<<"Enter no. to search: ";
					cin>>x;
					t=n1.search(x);
					if(t==1)
						cout<<"No. found";
					else
						cout<<"No. not found";
					break;
			case 6: n1.reverseDLL();
					cout<<"Double Linked list is reversed.";
					break;
			case 7: break;

			default: cout<<"\n\n\t\t!!!!Wrong choice!!!!\n";
		}
		if(ch==7)
			break;
	}
}
