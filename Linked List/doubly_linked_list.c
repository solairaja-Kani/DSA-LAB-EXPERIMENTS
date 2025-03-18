#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(int data)
{
    struct node* nn =(struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->prev = NULL;
    nn->next = NULL;

    return nn;
}

void display(struct node** head)
{
    printf("Displaying Doubly linked list elements\n");
	printf("======================================\n");

    if(*head ==NULL)
    {
        printf("The Doubly linked list is empty..\n");
    }
    else
    {
        struct node *temp = *head;
	
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
	
}

void insertAtBegin(struct node** head)
{
    printf("Insertion at beginning\n");
    printf("======================\n");
    
    int data;
    printf("Enter the value to be insert : ");
    scanf("%d", &data);
    
    struct node* nn = createNode(data);
    
    if (*head == NULL) {
        *head = nn;
    } else {
        nn->next = *head;
        (*head)->prev = nn;  
        *head = nn;
    }

}

void insertAtEnd(struct node** head)
{
    printf("Insertion At Beginning\n");
    printf("======================\n");

    int data;
    printf("Enter the data to insert : ");
    scanf("%d",&data);

    struct node* temp = *head;
    struct node* nn = createNode(data);

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp ->next = nn;
    nn->prev = temp;
    
}

void insertAfterTarget(struct node** head)
{
    printf("Insertion after specific number\n");
	printf("===============================\n");
	int target,flag=0,data;
    printf("Enter the target : ");
	scanf("%d",&target);

	printf("Enter the value to be insert : ");
	scanf("%d",&data);
	
	struct node *nn = createNode(data);

    struct node *temp = *head;

    while(temp->data != target)
    {
        temp = temp->next;
    }

    if (temp->data == target)
    {
        nn->next = temp->next;
        nn->prev = temp;
        temp->next = nn;
        temp->next->prev = nn;
    }
    else
    {
        printf("The target element is not found on the list\n");
    }
    
}

void deleteAtBegin(struct node** head)
{
    printf("Deletion at beginning\n");
	printf("=====================\n");

    if (*head == NULL) {
        printf("Impossible to delete from empty Doubly Linked List\n");
        return;
    }
    else
    {
        printf("Element %d is Succesfully Deleted from beginning\n",(*head)->data);

        *head = (*head)->next;
    }
}

void deleteAtEnd(struct node** head)
{

    printf("Deletion at End\n");
	printf("===============\n");

    if(*head==NULL)
    {
        printf("Impossible to delete from empty Doubly Linked List\n");
        return;
    }
    else
    {
        struct node* temp=*head;
        struct node* current=(*head)->next;

        if (temp->next == NULL) {  // Only one node
            printf("Deleted: %d\n", temp->data);
            free(temp);
            *head = NULL;
        } 
        else {

            while(current->next!=NULL)
            {
                temp = temp->next;
                current = current->next;
            }
            printf("Element %d is successfully deleted from end\n",current->data);
            temp->next = NULL;
            free(current);
        }
    }
    
}

void deleletSpecificNode(struct node** head)
{
   
    printf("Deletion of specific number\n");
    printf("===========================\n");
    
    if (*head == NULL) {
        printf("Impossible to delete from empty list\n");
        return;
    }
    
    int target;
    printf("Enter the target element to delete: ");
    scanf("%d", &target);
    
    struct node* temp = *head;
    
    if (temp->next == NULL) { 
		if( temp->data==target)
		{
			printf("Deleted: %d\n", temp->data);
            free(temp);
            *head = NULL;
		}
		else
		{
			printf("Target element is not found \n");
			return ;
		}
            
    }
    
    else
    {
    	while (temp != NULL && temp->data != target) {
	        temp = temp->next;
	    }
	    
	    if (temp == NULL) {
	        printf("Node with value %d not found.\n", target);
	        return;
	    }   
	    if (temp->prev != NULL) {
	        temp->prev->next = temp->next;  // Update previous node's next
	    } else {
	        *head = temp->next;  // If the target is the head
	    }
	    
	    if (temp->next != NULL) {
	        temp->next->prev = temp->prev;  // Update next node's prev
	    }
	    
	    printf("Deleted: %d\n", temp->data);
	    free(temp);
    	
	}
    
    

}


int main()
{
    printf("Implementation Doubly Linked List\n");
	printf("=================================\n");
	
	struct node * head = NULL ;
	
	int choice;
	
	while(1)
	{
		printf("\nDoubly Linked List Operations..\n");
		printf("1. Insert at Beginning\n2. Insert at End\n3. Insert after target number\n4. Delete at Beginning\n5. Delete at End\n6. Delete a specific node\n7. Display\n8. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				insertAtBegin(&head);
				break;
			
			case 2:
				insertAtEnd(&head);
				break;
			
			case 3:
				insertAfterTarget(&head);
				break;
			
			case 4:
				deleteAtBegin(&head);
				break;
			
			case 5:
				deleteAtEnd(&head);
				break;
				
			case 6:
				deleletSpecificNode(&head);
				break;
				
			case 7:
				display(&head);
				break;
			
			case 8:
				printf("Program exited....\n");
				exit(0);
			
			default:
				printf("Enter the valid choice...\n");
				break;
		}
		
	}
	
	return 0;

}
