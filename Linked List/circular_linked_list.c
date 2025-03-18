#include <stdio.h>
#include <stdlib.h>

int data;

struct node {
    int data;
    struct node* next;
};

// Create a new node
struct node* createNode(int data) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}


void display(struct node** head) {
    printf("Displaying Circular Linked List elements\n");
    printf("========================================\n");

    if (*head == NULL) {
        printf("The circular linked list is empty..\n");
    } else {
        struct node* temp = *head;
        do {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp != *head);  // Loop until back to the head
        printf("\n");
    }
}


void insertAtBegin(struct node** head) {
    printf("Insertion at Beginning\n");
    printf("======================\n");

    printf("Enter the value to insert: ");
    scanf("%d", &data);

    struct node* nn = createNode(data);

    if (*head == NULL) {
        *head = nn;
        nn->next = *head;  // Point to itself, making it circular
    } else {
        struct node* temp = *head;
        
        // Find the last node
        while (temp->next != *head) {  
            temp = temp->next;
        }
        
        nn->next = *head;  // New node points to the current head
        temp->next = nn;    // Last node points to the new node
        *head = nn;         // New node becomes the head
    }
}


void insertAtEnd(struct node** head) {
    printf("Insertion at End\n");
    printf("================\n");

    printf("Enter the value to insert: ");
    scanf("%d", &data);

    struct node* nn = createNode(data);

    if (*head == NULL) {
        *head = nn;
        nn->next = *head;  // Point to itself, making it circular
    } else {
        struct node* temp = *head;
        
        while (temp->next != *head) {  
            temp = temp->next;
        }
        
        temp->next = nn;    // Last node points to the new node
        nn->next = *head;   // New node points back to the head
    }
}


void insertAfterTarget(struct node** head) {
    printf("Insertion after specific number\n");
    printf("===============================\n");

    int target;
    printf("Enter the target: ");
    scanf("%d", &target);

    printf("Enter the value to insert: ");
    scanf("%d", &data);

    struct node* nn = createNode(data);

    if (*head == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }

    struct node* temp = *head;
    do {
        if (temp->data == target) {
            nn->next = temp->next;
            temp->next = nn;
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Target node with value %d not found.\n", target);
}


void deleteAtBegin(struct node** head) {
    printf("Deletion at Beginning\n");
    printf("=====================\n");

    if (*head == NULL) {
        printf("Impossible to delete from an empty list\n");
        return;
    }

    struct node* temp = *head;

    if (temp->next == *head) {
        // If there's only one node
        printf("Deleted: %d\n", temp->data);
        free(temp);
        *head = NULL;
    } else {
        // More than one node
        struct node* last = *head;
        while (last->next != *head) {  // Find the last node
            last = last->next;
        }
        *head = temp->next;
        last->next = *head;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}


void deleteAtEnd(struct node** head) {
    printf("Deletion at End\n");
    printf("===============\n");

    if (*head == NULL) {
        printf("Impossible to delete from an empty list\n");
        return;
    }

    struct node* temp = *head;

    if (temp->next == *head) {
        // Only one node
        printf("Deleted: %d\n", temp->data);
        free(temp);
        *head = NULL;
    } else {
        struct node* prev = NULL;
        while (temp->next != *head) {  // Traverse to the last node
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;  // Second last node points to head
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}


void deleteSpecificNode(struct node** head) {
    printf("Deletion of Specific Node\n");
    printf("=========================\n");

    if (*head == NULL) {
        printf("Impossible to delete from an empty list\n");
        return;
    }

    int target;
    printf("Enter the target element to delete: ");
    scanf("%d", &target);

    struct node* temp = *head;
    struct node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp->data == target) {
        deleteAtBegin(head);
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != target);

    if (temp == *head) {
        printf("Node with value %d not found.\n", target);
    } else {
        prev->next = temp->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}

int main() {
    printf("Circular Linked List Implementation\n");
    printf("===================================\n");

    struct node* head = NULL;
    int choice;

    while (1) {
        printf("\nCircular Linked List Operations..\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert after Target\n");
        printf("4. Delete at Beginning\n5. Delete at End\n6. Delete Specific Node\n");
        printf("7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                deleteSpecificNode(&head);
                break;
            case 7:
                display(&head);
                break;
            case 8:
                printf("Program exited...\n");
                exit(0);
            default:
                printf("Enter a valid choice...\n");
                break;
        }
    }
    
    return 0;
}
