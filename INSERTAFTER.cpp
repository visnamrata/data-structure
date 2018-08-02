#include<iostream>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
 
// function to get a new node
struct Node* getNode(int data)
{
    // allocate memory for the node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 
    // put in the data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}



void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) 
    { 
       printf("the given previous node cannot be NULL");       
       return;  
    }  
          
    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
  
    /* 3. put in the data  */
    new_node->data  = new_data;
  
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next; 
  
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

void printList(struct Node* head)
{
    while (head != NULL) 
	{
    	printf("%d",head->data);
    	printf(" ");
       // cout << head->data << " ";
        head = head->next;
    }
}
 
// Driver program to test above
int main()
{
    // Creating list 1->3->4->5
    struct Node* head = getNode(1);
    head->next = getNode(3);
    head->next->next = getNode(4);
    head->next->next->next = getNode(5);
 
    int  x = 2;
 
    printf("Original linked list ");
    printList(head);
 
    insertAfter(head,x);
 
    printf("\nLinked List After Insertion: ");
    printList(head);
 
    return 0;
}
