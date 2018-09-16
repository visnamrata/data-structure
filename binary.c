#include<stdio.h>

int main()
{
int arr[10],n,e;
printf("Number of elements in array: ");
scanf("%d",&n);
printf("\nEnter elements of array: ");
for(int i=0;i<n;++i)
scanf("%d",&arr[i]);
printf("\nEnter element to be searched: ");
scanf("%d",&e);
int beg=0,end=n-1,mid;
while(beg<=end)
{
mid=(beg+end)/2;
if(arr[mid]==e)
{
printf("\nElement is found at %d",mid+1);
break;
}
else if(arr[mid]<e)
{
beg=mid+1;
//end=n-1;
}
else if(arr[mid]>e)
{
end=mid-1;

}
}
return 0;
}
