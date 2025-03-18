#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int val)
{
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->left = NULL;
	nn->right = NULL;
	
	return nn;
}

struct node* insertion(struct node* root, int val)
{
	
//	struct node* nn = createNode(val);
	
	
	if(root==NULL)
	{

		return createNode(val);
	}

	if(root->data == val)
		return root;
	
	if (root->data<val)
	{
		root->right = insertion(root->right,val);
	}	
	
	else
	{
		root->left = insertion(root->left,val);
	}
	printf("Element inserted successfully..\n");
	return root;
}

// Find the minimum node in a BST (used for finding the in-order successor)
struct node* findMin(struct node* root)
{
	while(root->left!=NULL)
	{
		root = root->left;
	}
	
	return root;
}

struct node* deletion(struct node* root,int key)
{
	if(root==NULL)
		return root;
		
	// traverse the tree t find the node to delete
	if(root->data>key)
	{
		root->left = deletion(root->left,key);
	}
	else if(root->data<key)
	{
		root->right = deletion(root->right,key);
	}
	else
	{
		// node with only one child or no child
		if(root->left==NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		
		else if(root->right==NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		
		// Node with two children: get the in-order successor ( Smallest in the right subtree)
		struct node* temp = findMin(root->right);
		
		// copy the in-order successor's data to this node
		root->data = temp->data;
		
		// delete the in-order successor
		root->right = deletion(root->right,temp->data);
	}
	
	return root;
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

void main()
{
	printf("Binary Search Tree Implementation\n");
	printf("=================================\n");
	
	struct node* root = NULL;
	int choice,val,rootval;
	
	printf("Enter the root node value : ");
	scanf("%d",&rootval);
	
	root = insertion(root,rootval);
	
	while(1)
	{
		printf("\nList of Operations...\n");
		printf("1. For Insertion\n2. For Deletion\n3. For Display\n4. For Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Insertion Operation\n");
				printf("===================\n");
	
				printf("Enter the value to be insert : ");
				scanf("%d",&val);
				insertion(root,val);
				
				break;
				
			case 2:
				printf("Deletion Operation\n");
				printf("==================\n");
	
				printf("Enter the value to delete  : ");
				scanf("%d",&val);
				
				deletion(root,val);
				break;
				
			case 3:
				printf("Displaying the Tree elements\n");
				printf("============================\n");
				if(root==NULL)
					printf("The tree has no elements\n");
				else
					inorder(root);
				break;
				
			case 4:
				exit(0);
				break;
				
			default:
				printf("Enter the valid choice..\n");
				break;
		}
	}
	
}
