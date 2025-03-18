#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the priority queue

// Structure for the priority queue (Max Heap)
typedef struct {
    int data[MAX];  // Array to store the heap elements
    int size;       // Current size of the heap
} PriorityQueue;

// Function declarations
void insert(PriorityQueue *pq, int value); // Function to insert a value into the heap
int delete(PriorityQueue *pq);              // Function to delete the maximum value (root) from the heap
void display(PriorityQueue *pq);            // Function to display the current elements in the heap

int main() {
    // Initialize the priority queue with size 0
    PriorityQueue pq = {.size = 0};
    int choice, value;

    // Infinite loop for menu-driven operations
    while (1) {
        // Display the menu options
        printf("\nPriority Queue Operations (Max Heap):\n");
        printf("1. Insert\n2. Delete Max\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Exit the loop if the user chooses option 4 (Exit)
        if (choice == 4) break;

        // Handle the user's choice using a switch statement
        switch (choice) {
            case 1:
                // Insert operation
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&pq, value);  // Call insert function to add value to the priority queue
                break;
            case 2:
                // Delete operation (deletes the maximum value)
                if (pq.size > 0)
                    printf("Deleted value: %d\n", delete(&pq));  // Call delete function to remove max value
                else
                    printf("Priority queue is empty!\n");
                break;
            case 3:
                // Display the current elements of the priority queue
                display(&pq);  // Call display function to show heap elements
                break;
            default:
                printf("Invalid choice! Try again.\n");  // Invalid input handling
        }
    }
    return 0;  // Exit the program
}

// Function to insert a value into the max heap
void insert(PriorityQueue *pq, int value) {
    // Check if the priority queue is full
    if (pq->size >= MAX) {
        printf("Priority queue overflow!\n");
        return;  // Return without doing anything if the queue is full
    }

    // Insert the new value at the end of the heap
    int i = pq->size++;  // Increment size first, then assign the value
    pq->data[i] = value;

    // Heapify-up: Move the value up to its correct position to maintain the max heap property
    while (i > 0 && pq->data[i] > pq->data[(i - 1) / 2]) {
        // Swap the current value with its parent if it's larger
        int temp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = temp;

        // Update the current index to the parent's index
        i = (i - 1) / 2;
    }
}

// Function to delete and return the maximum value (root) from the max heap
int delete(PriorityQueue *pq) {
    // Store the maximum value (root) for return
    int max = pq->data[0];

    // Move the last element to the root
    pq->data[0] = pq->data[--pq->size];  // Decrease size and place last element at root

    // Heapify-down: Move the new root value to its correct position
    int i = 0;
    while (1) {
        // Calculate the left and right children of the current node
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;

        // Find the largest of the current node and its children
        if (left < pq->size && pq->data[left] > pq->data[largest])  // Left child is larger
            largest = left;
        if (right < pq->size && pq->data[right] > pq->data[largest])  // Right child is larger
            largest = right;

        // If the largest value is already at the current node, we're done
        if (largest == i) 
            break;

        // Swap the current node with the largest child
        int temp = pq->data[i];
        pq->data[i] = pq->data[largest];
        pq->data[largest] = temp;

        // Move down to the child that was swapped
        i = largest;
    }

    // Return the maximum value that was removed
    return max;
}

// Function to display the elements of the priority queue
void display(PriorityQueue *pq) {
    // Check if the priority queue is empty
    if (pq->size == 0) {
        printf("Priority queue is empty!\n");
        return;
    }
	int i;
    // Display all the elements in the priority queue
    printf("Priority queue elements: ");
    for (i = 0; i < pq->size; i++)
        printf("%d ", pq->data[i]);
    printf("\n");
}

