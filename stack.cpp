#include<iostream>
#include<stdlib.h>


int stack[5];
void push(int);
int pop();
void traverse();
int top=0;

int main()
{
	int element,choice;
	
	for(;;)
	{
		printf("---------------Stack operations---------------\n");
		printf("1.Insert into stack(push).\n");
		printf("2.Delete from stack(pop).\n");
		printf("3.Traverse satck.\n");
		printf("4.Exit\n");
		printf("Enter your choice(1-3): ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: if(top==5)
			        printf("Error: overflow\n\n");
			        else
			        {
			        	printf("Enter value to insert\n");
			        	scanf("%d",&element);
			        	push(element);
			        	
					}
					break;
			case 2:
			        if(top==0)
					printf("Error:Underflow\n\n");
					else
					{
						element=pop();
						printf("Element removed from stack is %d\n",element);
						
							}	
							break;
			case 3:
			         traverse();
					 break;
					 				
			case 4: exit(0);
		
		
		}
		
	}
}


void push(int value)
{
	stack[top]=value;
	top++;
	
}


int pop()
{
	top--;
	return stack[top];
	
}

void traverse()
{
	int d;
	if(top==0)
	{
		printf("Stack is empty.\n\n");
		return;
	}
	printf("There are %d elements in stack.\n",top);
	
	for(d=top-1;d>=0;d--)
	printf("%d\n",stack[d]);
	printf("\n");
}
