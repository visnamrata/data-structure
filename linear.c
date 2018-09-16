#include<stdio.h>
int main()
{
 int arr[10],e,i,n;
 printf("Enter size of array: ");
scanf("%d",&n);
printf("\nEnter elements of array ");
for(i=0;i<n;++i)
{
 scanf("%d",&arr[i]);
}

printf("\nEnter element to be searched: ");
scanf("%d",&e);
for(i=0;i<n;++i)
{
 if(arr[i]==e)
{
 printf("\nElement is found at position: ");
 printf("%d",i+1);
}
 }

return 0;
}


