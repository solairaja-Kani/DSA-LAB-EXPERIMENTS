#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100  // More buckets to reduce collisions

// Define the structure for a linked list node
typedef struct Node {
    char name[50];
    char phone[15];
    struct Node* next;
} Node;

// Define the structure for the hash table
typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

// Hash function based on the last 1 or 2 digits of the phone number
int hash(char* phone, int digits) {
    int length = strlen(phone);
    if (length < digits) {
        return atoi(phone) % TABLE_SIZE;  // Handle shorter numbers
    }
    return atoi(&phone[length - digits]) % TABLE_SIZE;
}

// Function to create a new node
Node* createNode(char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;  // Initialize each bucket as NULL
    }
    return ht;
}

// Function to insert a contact into the hash table
void insert(HashTable* ht, char* name, char* phone) {
    int index = hash(phone, 2);  // Use the last 2 digits as the key
    Node* newNode = createNode(name, phone);

    // Insert at the beginning of the linked list
    newNode->next = ht->table[index];
    ht->table[index] = newNode;

    printf("Contact '%s' with phone '%s' inserted.\n", name, phone);
}

// Function to search for contacts by the last 1 or 2 digits of the phone number
void search(HashTable* ht, int digits) {
    char input[15];
    printf("Enter the last %d digits to search: ", digits);
    scanf("%s", input);

    int index = hash(input, digits);
    Node* current = ht->table[index];

    printf("Contacts matching last %d digits '%s':\n", digits, input);
    int found = 0;
    while (current != NULL) {
        if (strlen(current->phone) >= digits &&
            strcmp(&current->phone[strlen(current->phone) - digits], input) == 0) {
            printf("-> Name: %s, Phone: %s\n", current->name, current->phone);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No contacts found.\n");
    }
}

// Function to delete a contact by phone number
void deleteContact(HashTable* ht, char* phone) {
    int index = hash(phone, 2);  // Use the last 2 digits as the key
    Node* current = ht->table[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->phone, phone) == 0) {
            // Contact found, delete it
            if (prev == NULL) {
                ht->table[index] = current->next;  // Remove the first node
            } else {
                prev->next = current->next;  // Remove from middle or end
            }
            free(current);
            printf("Contact with phone '%s' deleted.\n", phone);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Contact with phone '%s' not found.\n", phone);
}

// Function to display all contacts in the hash table
void display(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->table[i];
        
        if (current == NULL) {
            continue;
        } else {
            printf("Index %d: ", i);
            while (current != NULL) {
                printf("-> Name: %s, Phone: %s ", current->name, current->phone);
                current = current->next;
            }
            printf("\n");
        }
    }
}

int main() {
    HashTable* ht = createHashTable();
    int choice;
    char name[50], phone[15];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a contact\n");
        printf("2. Search for contacts by last digits\n");
        printf("3. Delete a contact by phone number\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                insert(ht, name, phone);
                break;

            case 2:
                printf("Search by (1 or 2) last digits? ");
                int digits;
                scanf("%d", &digits);
                if (digits == 1 || digits == 2) {
                    search(ht, digits);
                } else {
                    printf("Invalid choice. Enter 1 or 2.\n");
                }
                break;

            case 3:
                printf("Enter phone number to delete: ");
                scanf("%s", phone);
                deleteContact(ht, phone);
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
