#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 50
int b[MAXSIZE],n,data,pos,i,flag;

void create()
{
	printf("Creation of List \n");
	printf("================ \n");
	
	printf("Enter the size of the list : ");
	scanf("%d",&n);
	
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the value for list[%d] : ",i+1);
		scanf("%d",&b[i]);
	}
	
	display();
}

void display()
{
	printf("Displaying the List elements\n");
	printf("============================\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",b[i]);
	}
	
	printf("\n");
}

void insert()
{
	printf("Inserting the element\n");
	printf("=====================\n");
	
	printf("Enter the element to be insert : ");
	scanf("%d",&data);
	
	printf("Enter the position that you wish to insert : ");
	scanf("%d",&pos);
	
	if (pos>n)
	{
		printf("The position value must be lesser than or equal to size.\n");
	}
	else
	{
		for(i=n-1;i>=pos-1;i--)
		{
			b[i+1] = b[i];
		}
		
		b[pos-1] = data;
		
		n+=1;
		
		display();
	}
	
}

void deletes()
{
	printf("Deleting the element\n");
	printf("=====================\n");

	printf("Enter the position that you wish to delete : ");
	scanf("%d",&pos);
	if (pos>n)
	{
		printf("The position value must be lesser than or equal to size.\n");
	}
	else
	{
		for(i=pos-1;i<n-1;i++)
		{
			b[i] = b[i+1];
		}
		
		n-=1;
		
		display();
	}
	
}

void search()
{
	printf("Searching the element\n");
	printf("=====================\n");
	
	printf("Enter the element to be Search : ");
	scanf("%d",&data);
	
	flag = 0;
	
	for(i=0;i<n;i++)
	{
		if(b[i]==data)
		{
			flag=1;
			pos=i;
			break;
		}
	}
	
	if (flag)
	{
		printf("Yes, the element %d is present in position %d",data,pos);
	}
	else
	{
		printf("Ooops....the element you have searched is not present in the list");
	}
	
	printf("\n");
}

void main()
{
	printf("Implementation of List using Array\n");
	printf("==================================\n");
	
	create();
	
	int choice;
	
	while(true)
	{
		printf("List operations....\n");
		printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				insert();
				break;
			
			case 2:
				deletes();
				break;
				
			case 3:
				search();
				break;
			
			case 4:
				display();
				break;
			
			case 5:
				exit(1);
			
			default:
				printf("Select the valid choice ....\n");
				break;
		}
	}
}
