#include<iostream>
#include<conio.h>

#define size 10
int q[size],i,front=-1 ,rear=-1,e;

int main()
{   
int choice;
char ch;
do
{    printf("----------------MENU--------------");
	printf("\n1.insert element to queue");
    printf("\n2.Delete element from queue");
    printf("\n3.Display queue");
    printf("\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:	if(rear>size)
	            printf("\n\nQUEUE IS FULL");
             	else
              	{
	              printf("\nEnter element to insert: ");
	              scanf("%d",&e);
	             if(front==-1)
               	{
	            	front=rear=0;
	            }
	
             	else
                	 rear=rear+1;
	            q[rear]=e;	
	            }
	            break;
	     case 2: int y;
		         if(front==-1)
		         printf("\n\nQueue is empty");
		         else
		         {
		         	y=q[front];
		         	if(front==rear)
		         	front=rear=-1;
		         	else
		         	front+=1;
		         	printf("\n\nNumber deleted is:%d ",y);
				 }
				 break;
		case 3:  if(front=-1)
		          printf("\n\nQueue contains nothing");
		          else
		          {
		          	 printf("\n\nQueue contains: ");
		          for(i=front;i<=rear;++i)  
				  printf("%d ",q[i]);
		          	
				  }
				 
				  break;
		case 4:  exit(0);
		default: printf("\n-------------------------SORRY WRONG CHOICE---------------------");
				       

	}
	printf("\nWant again(y/n): ");
    scanf("%s",&ch);

}	while(ch=='y'||ch=='Y');
    
    return 0;	
	
}
