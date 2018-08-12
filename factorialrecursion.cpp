#include<iostream>
#include<math.h>
using namespace std;

int factorialrec(int n);
void factiterate(int n)
{   int fact=1;

	for(int i=1;i<=n;++i)
	{
	fact=fact*i;	
	}
	printf("\nFactorial by iteration is: ");
	printf("%d",fact);
}


	void factorsByIteration(int n)
{
   
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
           
            if (n/i == i)
                printf("%d ", i);
 
            else 
                printf("%d %d ", i, n/i);
        }
    }
}

int factorByRecursion(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            return factorByRecursion(a - b, b);
        }
        else
        {
            return factorByRecursion(a, b - a);
        }
    }
    return a;
}


int main()
{
    int n,m,choice,ans;
    while(1)
    {
    	printf("1.Factorial by recursion\n ");
    	printf("2.Factorial by iteration\n ");
    	printf("3.Factors by recursion\n ");
    	printf("4.Factors by iteration\n ");
    	printf("5.Exit\n ");
    	printf("\nEnter your choice(1-5): ");
    	scanf("%d",&choice);
	
	switch(choice)
	
	{
		case 1:printf("\nEnter a positive integer: ");
               scanf("%d",&n);
			   ans=factorialrec(n);
			   printf("\nfactorial by recursion is: ");
			   printf("%d",ans);
			   printf("\n");
			   break;
	    case 2:	printf("\nEnter a positive integer: ");
               scanf("%d",&n);
			   	factiterate( n);
			   	printf("\n");
				   break;
	    case 3: printf("\nENter numbers :");
		        scanf("%d",&m,&n);
				ans=factorByRecursion(m,n);
				printf("\nfactors by recursion is: ");
				printf("%d",ans);
				printf("\n");
				break;			   
	    case 4:printf("\n");
	           printf("\nEnter a positive integer whose factor required: ");
               scanf("%d",&n);
               factorsByIteration(n);
               printf("\n");
               break;
        case 5:exit(0);       
               
		 default: printf("\nwrong choice");
		          break;      			      
}
    
}

    return 0;
}

int factorialrec(int n)
{
    if(n > 1)
        return n * factorialrec(n - 1);
    else if (n==0||n==1)
        return 1;
        else
        return 0;
}

