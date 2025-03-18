#include <stdio.h>
#include <stdlib.h>

int data;
int count;
struct node
{
	int data;
	struct node* next;
};

struct node* createNode(int data)
{
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	
	nn->data = data;
	nn->next = NULL;
	
	return nn;
}

void display(struct node** head)
{
	printf("Displaying Singly linked list elements\n");
	printf("======================================\n");

    if(*head ==NULL)
    {
        printf("The singly linked list is empty..\n");
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
	
	printf("Enter the value to be insert : ");
	scanf("%d",&data);
	
	struct node *nn = createNode(data);
	
	if(*head==NULL)
	{
		*head = nn;
	}
	else
	{
		nn->next = *head;
		*head = nn;
	}
	count++;
}

void insertAtEnd(struct node** head)
{
    printf("Insertion at End\n");
	printf("================\n");
	
	printf("Enter the value to be insert : ");
	scanf("%d",&data);
	
	struct node *nn = createNode(data);

    struct node *temp = *head;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next=nn;
    count++;
	
}

void insertAfterTarget(struct node** head)
{
    printf("Insertion after specific number\n");
	printf("===============================\n");
	int target,flag=0;
    printf("Enter the target : ");
	scanf("%d",&target);

	printf("Enter the value to be insert : ");
	scanf("%d",&data);
	
	struct node *nn = createNode(data);

    struct node *temp = *head;

    while(temp->data!=target && temp->next!=NULL)
    {
        temp=temp->next;
    }
    if (temp->data==target)
    {
        nn->next = temp->next;
        temp->next = nn;
        count++;
    }
    else
    {
        printf("No such target element is found\n\n");
    }
	
}

void deleteAtBegin(struct node** head)
{
    printf("Deletion at beginning\n");
	printf("=====================\n");

    if (*head == NULL) {
        printf("Impossible to delete from empty Singly Linked List\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);

	
}

void deleteAtEnd(struct node** head)
{
	printf("Deletion at End\n");
	printf("===============\n");

    if(*head==NULL)
    {
        printf("Impossible to delete from empty Singly Linked List\n");
        return;
    }

    else
    {
        struct node* prev = *head;
        struct node* current = (*head)->next;

        while(current->next!=NULL)
        {
            current=current->next;
            prev=prev->next;
        }

        printf("Deleted : %d\n",current->data);
        free(current);
        prev->next=NULL;
    }
    

}

void deleletSpecificNode(struct node** head)
{
    printf("Deletion of specific number\n");
    printf("===========================\n");
    if(*head==NULL)
    {
        printf("Impossible to delete from empty Singly Linked List\n");
        return;
    }
    else
    {
       
        int target,flag=0;
        printf("Enter the target element to delete: ");
        scanf("%d",&target);

        struct node* temp = *head;
        struct node* prev = NULL;

        // If the node to be deleted is the head node
        if (temp != NULL && temp->data == target) {
            *head= temp->next; // Change head
            free(temp); // Free memory
            return;
        }

        // Search for the target to be deleted
        while (temp != NULL && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        // If the target was not present in the linked list
        if (temp == NULL) {
            printf("Node with value %d not found.\n", target);
            return;
        }

        // Unlink the node from the linked list
        prev->next = temp->next;
        free(temp); // Free memory
       
       
    }
}

void goto_Nth_node(struct node** head)
{
	printf("Goto N'th Node\n");
	printf("==============\n");
	
	int n,tempN;
	
	printf("Enter the position that you want to go to : ");
	scanf("%d",&n);
	
	tempN = n;
	
	if(*head==NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		if(n>count)
		{
			printf("Enter the valid position\n");
		}
		else
		{
			struct node* temp = *head;
			
			while(n>1)
			{
				temp = temp->next;
				n--;
			}
			
			if(temp!=NULL)
			{
				printf("The data at position %d is %d\n",tempN,temp->data);
			}
		}
	}
	
	
}

int main()
{
	printf("Implementation Singly Linked List\n");
	printf("=================================\n");
	
	struct node * head =NULL;
	
	int choice;
	
	while(1)
	{
		printf("\nSingly Linked List Operations..\n");
		printf("1. Insert at Beginning\n2. Insert at End\n3. Insert after target number\n4. Delete at Beginning\n5. Delete at End\n6. Delete a specific node\n7. Display\n8. Goto N'th Node'\n9. Exit\n");
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
				goto_Nth_node(&head);
				break;
			
			case 9:
				printf("Program exited....\n");
				exit(0);
			
			default:
				printf("Enter the valid choice...\n");
				break;
		}
		
	}
	
	return 0;
}
