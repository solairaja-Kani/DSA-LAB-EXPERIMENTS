#include <stdio.h>

void push();
void pop();
void top_element();
void show();
void isEmpty();
void isFull();

int stack[100],top=-1,size;

void main()
{
	int choice;

	printf("Stack operation using Array\n");
	printf("===========================\n");
	
	printf("Enter the size of the stack : ");
	scanf("%d",&size);
	
	while(choice!=7)
	{
		printf("Enter your operation : \n1. Push\n2. Pop\n3. Top\n4. Display\n5. isEmpty\n6. is Full\n7. Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				push();
				break;
			
			case 2:
				pop();
				break;
			
			case 3:
				top_element();
				break;
				
			case 4:
				show();
				break;
				
			case 5:
				isEmpty();
				break;
				
			case 6:
				isFull();
				break;
			
			case 7:
				printf("Exiting....");
				break;
				
			default:
				printf("Invalid option\n");
				break;
		};
	}
}

void push()
{
	printf("Push Operation\n");
	printf("==============\n");
	
	if (top==size-1)
	{
		printf("Stack overflow...\n");
	}
	else
	{
		int num;
		printf("Enter the number to push : ");
		scanf("%d",&num);
		top += 1;
		stack[top] = num;
	}
}

void show()
{
	printf("Displaying Stack Elements\n");
	printf("=========================\n");
	
	int i;
	if (top==-1)
	{
		printf("Stack is empty..\n");
	}
	else
	{
	
		printf("The elements in the Stock are ...\n");
		for(i=0; i<=top;i++)
		{
			printf("%d\t",stack[i]);
		}
		
		printf("\n");
	}
}

void top_element()
{
	printf("Top Element\n");
	printf("===========\n");
	if (top==-1)
	{
		printf("Stack is empty..\n");
	}
	else
	{
		printf("The Top element is %d\n",stack[top]);
	}
}

void pop()
{
	printf("Pop Operation\n");
	printf("=============\n");
	if (top==-1)
	{
		printf("Stack is empty..\n");
	}
	else
	{
		printf("Popped element is %d\n",stack[top]);
		top-=1;
	}
}

void isEmpty()
{
	printf("isEmpty operation\n");
	printf("=================\n");
	if(top==-1)
	{
		printf("Yes, the stack is empty\n");
	}
	else
	{
		printf("No, the stack have values\n");
	}
}

void isFull()
{
	printf("isFull operation\n");
	printf("================\n");
	
	if (top==size-1)
	{
		printf("Yes, the stack is full\n");
	}
	else
	{
		printf("No, the stack doesn't reach the max limit\n");
	}
}
