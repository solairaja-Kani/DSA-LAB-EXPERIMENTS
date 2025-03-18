#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Define the structure for a linked list node
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Define the structure for the hash table
typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

// Hash function to calculate the index from the key
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL; // Initialize each bucket as NULL
    }
    return ht;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* ht, int value) {
    int key = value; // Simple key generation based on value
    int index = hash(key);
    Node* newNode = createNode(key, value);

    // If there is no collision, insert the new node directly
    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        // If there is a collision, add the new node to the linked list at the index
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }
}

// Function to search for a value by key in the hash table
int search(HashTable* ht, int value) {
    int key = value; // Generate the key from the value
    int index = hash(key);
    Node* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value; // Key found, return the value
        }
        current = current->next;
    }
    return -1; // Return -1 if the key is not found
}

// Function to delete a key-value pair from the hash table
void delete(HashTable* ht, int value) {
    int key = value; // Generate the key from the value
    int index = hash(key);
    Node* current = ht->table[index];
    Node* prev = NULL;

    // Search for the key in the linked list
    while (current != NULL) {
        if (current->key == key) {
            // Key found, remove the node
            if (prev == NULL) {
                ht->table[index] = current->next; // Remove the first node
            } else {
                prev->next = current->next; // Remove node from the middle or end
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to display the hash table
void display(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->table[i];
        printf("Index %d: ", i);
        if (current == NULL) {
            printf("Empty\n");
        } else {
            while (current != NULL) {
                printf("-> (%d, %d) ", current->key, current->value);
                current = current->next;
            }
            printf("\n");
        }
    }
}

int main() {
    HashTable* ht = createHashTable();
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. Search for a value\n");
        printf("3. Delete a value\n");
        printf("4. Display hash table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(ht, value);
                printf("Inserted value %d into the hash table.\n", value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                value = search(ht, value);
                if (value != -1) {
                    printf("Value found: %d\n", value);
                } else {
                    printf("Value not found in the hash table.\n");
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(ht, value);
                printf("Value %d deleted from the hash table.\n", value);
                break;
            case 4:
                display(ht);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

