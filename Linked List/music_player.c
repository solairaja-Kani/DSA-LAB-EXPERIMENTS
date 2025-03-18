#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct music
{
	char song[100];
	struct music* next;
};

struct music* createMusic(char* musicname)
{
	struct music* m = (struct music*)malloc(sizeof(struct music));
	strncpy(m->song,musicname,100);
	m->next = NULL;
	
	return m;
}

void display(struct music** head)
{
	printf("Display Playlist\n");
	printf("================\n");
	if(*head==NULL)
	{
		printf("No songs in the playlist\n");
	}
	else
	{
			printf("Your playlist contains the following songs....\n");
	
			struct music *temp = *head;
			int i=1;
			do
			{
				printf("%d. %s\n",i++,temp->song);
				temp = temp->next;
				
			}while(temp != *head);
	}

	
}

void insertSong(struct music** head)
{
	printf("Add Music to your List\n");
	printf("======================\n");
	
	char name[100];
	printf("Enter the song name : ");
	getchar();
	scanf("%[^\n]s",name);
	
	struct music *temp = *head;
	struct music *nn = createMusic(name);
	
	if (nn == NULL)
	{
		printf("Unable to create a new song ");
	}
	else
	{
		if(*head==NULL)
		{
			*head = nn;
			nn->next = *head;
		}
		else
		{
			while(temp->next != *head)
			{
				temp = temp->next;
			}
			
			temp->next=nn;
			nn->next=*head;
			*head = nn;
		}
	}
	
}


void playSong(struct music** head)
{
	
	printf("Playing a Song\n");
	printf("==============\n\n");
	
	if(*head == NULL)
	{
		printf("Your playlist is empty...\n");
	}
	else
	{
		printf("Your current song is %s\n",(*head)->song);
		
		struct music *temp=*head;
		int option=0;
		while(option!=2)
		{
			printf("1. For Next song\t2. For Stop\n");
			printf("Give a option : ");
			scanf("%d",&option);
			
			switch(option)
			{
				case 1:
					
					temp = temp->next;
					printf("Next song : %s\n",temp->song);
					break;
				
				case 2:
					printf("Music player stopped\n");
					break;
				
				default:
					printf("Enter the valid option\n");
					break;
					
			}
		}
	}
	
}

void main()
{
	struct music* head = NULL;
	
	printf("Music player\n");
	printf("============\n\n");
	
	int choice;
	
	while(1)
	{
		printf("Your choices are here...\n");
		printf("1. Add Song\n2. Display the Playlist\n3. Play Song\n4. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				insertSong(&head);
				break;
				
			case 2:
				display(&head);
				break;
				
			case 3:
				playSong(&head);
				break;
			
			case 4:
				printf("Exited...");
				exit(0);
				
			default:
				printf("Provide a valid choice\n");
				break;
		}
	}
}
