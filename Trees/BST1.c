#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int val)
{
	struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}

struct Node* insert(struct Node* root, int val)
{
	if(root==NULL)
	{
		struct Node* nn=createNode(val);
		return nn;
	}
	if(root->data==val)
	{
		return root;
	}
	else if(root->data>val)
	{
		root->left=insert(root->left,val);
	}
	else if(root->data<val)
	{
		root->right=insert(root->right,val);
	}
	
	return root;
}

struct Node* findMin(struct Node* root)
{
	while(root && root->left!=NULL)
	{
		root=root->left;
	}
	
	return root;
}

struct Node* deletes(struct Node* root, int key)
{
	if(root==NULL)
	{
		return root;
	}
	if (root->data>key)
	{
		root->left=deletes(root->left,key);
	}
	else if(root->data<key)
	{
		root->right=deletes(root->right,key);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL)
		{
			struct Node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct Node* temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			struct Node* temp =findMin(root->right);
			root->data=temp->data;
			root->right=deletes(root->right,temp->data);
		}
	}
	
	return root;
	
}

void inorder(struct Node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
		
}

void preorder(struct Node* root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->data);
	inorder(root->left);
	inorder(root->right);
}

void postorder(struct Node* root)
{
	if(root==NULL)
		return;
	
	inorder(root->left);
	inorder(root->right);
	printf("%d\t",root->data);
}


void main()
{
	struct Node* root=NULL;
	
	int choice,data;
	printf("BST\n");
	printf("===\n");
	
	printf("Enter the root element : ");
	scanf("%d",&data);
	
	root=createNode(data);
	
	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\nEnter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
			{
				case 1:
					printf("Enter the value to insert : ");
					scanf("%d",&data);
					insert(root,data);
					break;
				
				case 2:
					printf("Enter the value to delete : ");
					scanf("%d",&data);
					deletes(root,data);
					break;
				
				case 3:
					inorder(root);
					break;
				
				case 4:
					preorder(root);
					break;
					
				case 5:
					postorder(root);
					break;
				
				case 6:
					printf("Exiting...\n");
					exit(0);
			}
			
		
	}
}
