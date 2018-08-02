#include<iostream>
#include<stdlib.h>
struct node 
{
	int data;
	struct node* next;
	
};
void insertAtbegin(int);
void insertAtend(int);
void display();

struct node* head=NULL;
int main()
{
   int x,n,i;
   printf("Enter no of elements:\n");
   scanf("%d",&n);
   for(i=0;i<n;++i)
   {
   	printf("Enter element to insert:\n");
   	scanf("%d",&x);
   	insertAtbegin(x);
   	printf("now enter at end\n\n");
   	insertAtend(x);
   	printf("original list is\n\n");
	display();      
   }
      
   	
}


void insertAtbegin(int x)
{
 struct node* temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 temp->next=NULL;
 if(head!=NULL)
 temp->next=head;
 head=temp;	
}


void insertAtend(int X)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new(struct node);
	temp->next->data=X;
	temp->next->next=NULL;
	
}


void display()
{
    struct node* temp=head;	
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
		printf("\n");
	}
	printf("\n");
}
