#include<iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	struct node* next;
	int data;
}*start;

void insertAtStart(int x)
{
	struct node *p= (struct node*) malloc(sizeof(struct node));
	if(p==NULL)
	{
		//memory gets full
		exit(0);
	}

	p->data=x;
	if(start == NULL)
	{
		p->next=NULL;
		start=p;
	}
	else
	{
		p->next=start;
		start=p;
	}
}

void showData()
{
    if (start == NULL)
    {
        cout<<"\nLinked List is Empty	"<<endl;
        return;
    }

    struct node *p;
    p = start;
    cout<<"\nElements of Linked list are: "<<endl;
    while (p != NULL)
    {
        cout<<" "<<p->data<<" -> ";
        p = p->next;
    }
    cout<<"NULL";
}

void deleteAtStart()
{
	struct node *p;

	if(start != NULL)
	{
		p=start;
		start= start->next;
		cout<<"\n"<<p->data<<" get popped.";
		free(p);
	}
	else
	{
		cout<<("Underflow!!!!\n");
	}
}

int main()
{
	int ch, data;
	while(ch!=4)
	{
		cout<<"\nMenu:\n";
		cout<<"1. Show Stack\n";
		cout<<"2. Push into Stack\n";
		cout<<"3. Pop from Stackt\n";
		cout<<"4. Exit\n";
		cout<<"Enter Your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1: showData();
					break;
			case 2: cout<<"\nEnter data to insert: ";
					cin>>data;
					insertAtStart( data);
					break;
			case 3: deleteAtStart();
					break;
			case 4:break;
			default: cout<<"\n!!!!Wrong choice!!!!";
		}
	}
	return 0;
}
