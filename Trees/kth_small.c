#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Global variable to keep track of the count of visited nodes
int count = 0;
int kthSmallest = -1; // Variable to store the kth smallest element

// In-order traversal function to find the kth smallest element
void inorder(struct Node* root, int k) {
    if (root == NULL || count >= k) {
        return;
    }
    // Traverse the left subtree
    inorder(root->left, k);
    // Increment the count
    count++;
    // If count equals k, store the current node's data
    if (count == k) {
        kthSmallest = root->data;
        return;
    }
    // Traverse the right subtree
    inorder(root->right, k);
}

int main() {
    int n, data, k;
    struct Node* root = NULL;

    // Input the root node value
    printf("Enter the root node: ");
    scanf("%d", &n);
    root = createNode(n);

    // Insert additional nodes
    while (1) {
        printf("Enter data to insert (0 to stop): ");
        scanf("%d", &data);
        if (data == 0) break;
        insert(root, data);
    }

    // Input the value of k
    printf("Enter the value of k to find the kth smallest element: ");
    scanf("%d", &k);

    // Reset count and kthSmallest before the traversal
    count = 0;
    kthSmallest = -1;

    // Perform in-order traversal to find the kth smallest element
    inorder(root, k);

    // Output the result
    if (kthSmallest != -1) {
        printf("The %dth smallest element is: %d\n", k, kthSmallest);
    } else {
        printf("There are less than %d elements in the tree.\n", k);
    }

    return 0;
}

