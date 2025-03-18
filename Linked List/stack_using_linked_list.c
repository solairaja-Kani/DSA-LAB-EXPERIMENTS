#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int num;
	struct node* next;
};

struct node* createStack(int data)
{
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->num = data;
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
            printf("%d\t",temp->num);
            temp = temp->next;
        }
    }
	
	printf("\n");
	
}


void push(struct node** head)
{
	
    printf("Push Operation\n");
	printf("==============\n");
	int data;
	printf("Enter the value to be insert : ");
	scanf("%d",&data);
	
	struct node *nn = createStack(data);
	if(!nn)
	{
		printf("Stack overflow..\n");
		return ;
	}
	else
	{
		if(*head==NULL)
		{
			*head = nn;
		}
		else
		{
			struct node *temp = *head;
		    while(temp->next!=NULL)
		    {
		        temp = temp->next;
		    }
		
		    temp->next=nn;
		}
		
	}
    
	
}


void pop(struct node** head)
{
    printf("Pop Operation\n");
	printf("=============\n");

    if(*head==NULL)
    {
        printf("Stack is empty..Stack underflow\n");
        return;
    }

    else
    {
    	
    	
        struct node* prev = *head;
        struct node* current = (*head)->next;
        
        if(!current)
        {
        	struct node* temp = *head;
		    *head = (*head)->next;
		    printf("Deleted: %d\n", temp->num);
		    free(temp);
		}
		else
		{
	        while(current->next!=NULL)
	        {
	            current=current->next;
	            prev=prev->next;
	        }
	
	        printf("Deleted : %d\n",current->num);
	        free(current);
	        prev->next=NULL;
		}
    }
    
	
}

bool isEmpty(struct node** head)
{
	if(*head==NULL)
	{
		return true;
	}
	return false;
}



void peek(struct node** head)
{
	printf("Peek element\n");
	printf("============\n");
	if(!isEmpty(head))
	{
	
		struct node *temp = *head;
		while(temp->next!=NULL)
		{
		        temp = temp->next;
		}
			
		printf("The element at peek is %d\n",temp->num);
	}
	else
	{
		printf("Stack is empty.\n");
	}
}

void main()
{
	printf("Stack implementation using Linked list\n");
	printf("======================================\n\n");
	
	struct node* head = NULL;
	int choice;
	
	while(1)
	{
		printf("Stack operations\n");
		printf("================\n");
		
		printf("1. Push\n2. Pop\n3. Display\n4. isEmpty\n5. Peek\n6. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				push(&head);
				break;
				
			case 2:
				pop(&head);
				break;
				
			case 3:
				display(&head);
				break;
			
			case 4:
				if(isEmpty(&head))
				{
					printf("Yes....Stack is empty..\n");
				}
				else
				{
					printf("No...Stack is not empty...\n");
				}
				break;
				
			case 5:
				peek(&head);
				break;
				
			case 6:
				exit(0);
				
			default:
				printf("Enter the valid choice...\n\n");
				break;
				
				
			
		}
	}
}

