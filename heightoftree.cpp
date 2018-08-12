#include<stdio.h>
struct LNode
{
	char data;
	struct LNode* lp;
	struct LNode* rp;
};
 int heightOfTree(struct LNode* root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->lp==NULL&&root->rp==NULL)
			return 0;
 		int xl= heightOfTree(root->lp);
		int xr= heightOfTree(root->rp);
 		return (max(xl,xr)+1);
	}
}
 int max(int x, int y)
{
	return  x>y?x:y;
}
int main()
{
	struct LNode root[]={
							{'x',root+1,root+4},
							{'y',root+2,root+3},
							{'z',NULL,NULL},
							{'a',NULL,NULL},
							{'b',root+5,root+6},
							{'c',NULL,NULL},
							{'d',root+7,root+7},
							{'e',NULL,NULL},
							{'f',NULL,NULL},
								};
 	printf("%d",heightOfTree(root));
	return 0;
}
