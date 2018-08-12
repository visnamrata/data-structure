#include<stdio.h>
struct LNode
{
	char data;
	struct LNode* lp;
	struct LNode* rp;
};
 int numberOfLeaf(struct LNode* root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->lp==NULL&&root->rp==NULL)
			return 1;	
 		int xl= numberOfLeaf(root->lp);
		int xr= numberOfLeaf(root->rp);
 		return (xl+xr);
	}
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
							{'d',NULL,NULL}	};
 	printf("%d",numberOfLeaf(root));
	return 0;
}
