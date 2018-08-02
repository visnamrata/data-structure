#include <stdio.h>
#include <stdlib.h>
 

struct Node
{
    int data;
    struct Node *next;
};
 

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 

void deleteNode(struct Node *head,struct Node *n)
{
	if(head==n)
	{
		if(head->next==NULL)
		{
			printf("There is only one node so list cant be empty ");
			return;
		}
		head->data=head->next->data;
		n=head->next;
		head->next=head->next->next;
		free(n);
		return;
	}
	struct Node *prev=head;
	while(prev->next!=NULL&&prev->next!=n)
	prev=prev->next;
	if(prev->next==NULL)
	{
		printf("\nGiven node is not present in linked list ");
		return;
	}
	prev->next=prev->next->next;
	free(n);
	return;
}

    

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
 

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    printf("Given linked list : ");
    printList(head);
    printf("\nDeleting node %d: ",head->next->next->data);
    deleteNode(head,head->next->next);
    //deleteNode(&head, 1);
    printf("\nModified linked list : ");
    printList(head);
    printf("\nDeleting first node ");
    deleteNode(head,head);
    printf("\nModified linked list: ");
    printList(head);
    return 0;
}

