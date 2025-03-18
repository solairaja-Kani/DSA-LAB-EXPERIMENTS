#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#include <stdbool.h>
int b[MAXSIZE],n,data,pos,i,flag,j;
void display();
void create()
{
	printf("Creation of List \n");
	printf("================ \n");
	
	printf("Enter the size of the list : ");
	scanf("%d",&n);
	
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the Employee ID for Employee %d : ",i+1);
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
	
	printf("Enter the Employee ID to be insert : ");
	scanf("%d",&data);
	
	printf("Enter the position that you wish to insert : ");
	scanf("%d",&pos);
	
	for(i=n-1;i>=pos-1;i--)
	{
		b[i+1] = b[i];
	}
	
	b[pos-1] = data;
	
	n+=1;
	
	display();
}

void find_duplicates()
{
	printf("Finding Duplicates\n");
	printf("==================\n");
	int duplicates[MAXSIZE]={0};
	
	for(i=0;i<n;i++)
	{
		if(!duplicates[i]==1)
		{
			for(j=i+1;j<n;j++)
			{
				if (b[i]==b[j]){
					printf("Duplicate elements : %d Index : %d \n\n",b[i],j);
					duplicates[j]=1;
				}
					
			}
		}
		
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
		printf("1. Insert\n2.Display\n3. Find duplicates\n4.Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				insert();
				break;
			
			case 2:
				display();
				break;
				
			case 3:
				find_duplicates();
				break;
			
			case 4:
				exit(1);
			
			default:
				printf("Select the valid choice ....\n");
				break;
		}
	}
}
