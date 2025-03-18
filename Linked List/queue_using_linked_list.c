#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue function to add an element to the rear of the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        // If the queue is empty, front and rear point to the new node
        q->front = q->rear = newNode;
    } else {
        // Otherwise, add the new node to the end and move rear
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to the queue\n", data);
}

// Dequeue function to remove an element from the front of the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    // If the front becomes NULL, also set rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Main function to demonstrate enqueuse and dequeue
int main() {
    struct Queue* q = createQueue();
    
    printf("Queue implementation using Linked List\n");
    printf("======================================\n");
    int choice;
    while(1)
    {
    	printf("Queue operation....\n");
    	printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Show Rear\n5. Show Front\n6. Exit \n");
    	printf("Enter your choice : ");
    	scanf("%d",&choice);
    	
    	switch(choice)
    	{
    		case 1:
    			enqueue(q);
    			break;
    			
    		case 2:
    			dequeue(q);
    			break;
    			
    		case 3:
    			display(q);
    			break;
    			
    		case 4:
    			showRear(q);
    			break;
    			
    		case 5:
    			showFront(q);
    			break;
    		
    		case 6:
    			exit(0);
    		
    		default:
    			printf("Enter the valid choice....\n");
    			break;
		}
	}

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("%d dequeued from the queue\n", dequeue(q));
    printf("%d dequeued from the queue\n", dequeue(q));

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}

