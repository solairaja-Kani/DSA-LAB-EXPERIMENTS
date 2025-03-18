#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep function

struct queue {
    int front, rear, capacity;
    int *queue;
};

// Function to create a queue
struct queue* createQueue(int capacity) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    q->queue = (int *)malloc(capacity * sizeof(int));
    return q;
}

// Function to enqueue (book ticket)
void enqueue(struct queue* q, int val) {
    if (q->rear == q->capacity - 1) {
        printf("Queue is full. Cannot book more tickets.\n");
    } else {
        q->queue[++q->rear] = val;
        printf("Customer %d is in the queue for booking.\n", val);
    }
}

// Function to display the queue
void display(struct queue* q) {
	int i;
    if (q->front > q->rear) {
        printf("The Queue is empty.\n\n");
    } else {
        printf("Current Bookings:\n");
        printf("===================\n");
        for ( i = q->front; i <= q->rear; i++) {
            printf("Customer %d\n", q->queue[i]);
        }
        printf("\n");
    }
}

// Function to process a booking
void processBooking(struct queue* q) {
    if (q->front > q->rear) {
        printf("No bookings to process.\n");
    } else {
        printf("Processing booking for customer %d...\n", q->queue[q->front]);
        sleep(2); // Simulate processing time (2 seconds)
        printf("Booking for customer %d has been confirmed.\n", q->queue[q->front]);
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1; // Reset the queue if empty
        }
    }
}

// Function to show the front element
void front(struct queue* q) {
    printf("Displaying Front Booking\n");
    printf("=========================\n");
    if (q->front > q->rear) {
        printf("Queue is empty. No bookings.\n");
    } else {
        printf("The next customer to be served is %d\n\n", q->queue[q->front]);
    }
}

// Main function
int main() {
    int capacity;
    printf("Enter the capacity of the booking queue: ");
    scanf("%d", &capacity);

    struct queue* Q = createQueue(capacity);
    int choice = 0;

    while (choice != 5) {
        printf("\nTicket Booking System Operations\n");
        printf("1. Book Ticket\n");
        printf("2. Process Booking\n");
        printf("3. Display Bookings\n");
        printf("4. Show Next Booking\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num;
                printf("Enter customer ID to book ticket: ");
                scanf("%d", &num);
                enqueue(Q, num);
                break;
            }
            case 2:
                processBooking(Q);
                break;
            case 3:
                display(Q);
                break;
            case 4:
                front(Q);
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Please enter a valid operation.\n");
                break;
        }
    }

    // Clean up
    free(Q->queue);
    free(Q);
    return 0;
}

