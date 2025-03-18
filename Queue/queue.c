#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int front,rear,capacity;
	int *queue;
};

struct queue* createQueue(int capacity)
{
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->front = 0;
	q->rear = -1;
	q->capacity = capacity;
	q->queue = (int *)malloc(capacity * sizeof(int));
	
	return q;
}

void enqueue(struct queue* q,int val)
{
	printf("Enqueue operation\n");
	printf("=================\n");
	
	if (q->rear == q->capacity-1)
	{
		printf("Queue is full\n");
	}
	else
	{
		q->queue[++q->rear] = val;
		printf("%d Inserted successfully..\n",val);
	}
}

void display(struct queue* q)
{
	
	if(q->front>q->rear)
	{
		printf("The Queue is empty..\n\n");
	}
	else
	{
		int i;
		printf("Printing the Queue elements\n");
		printf("===========================\n");
		for(i=q->front;i<=q->rear;i++)
		{
			printf("%d <--  ",q->queue[i]);
		}
		printf("\n");
	}
}

void dequeue(struct queue* q)
{
	printf("Dequeue operation\n");
	printf("=================\n");
	
	if (q->front > q->rear)
	{
		printf("Queue is Empty..");
	}
	else
	{
		printf("%d is dequeued successfully from the queue.\n",q->queue[0]);
		int i;
		for(i=0; i < q->rear; i++)
		{
			q->queue[i]=q->queue[i+1];
		}
		q->rear--;
	}
}

void front(struct queue* q)
{
	printf("Displaying Front element\n");
	printf("========================\n");
	
	if(q->front>q->rear)
	{
		printf("Queue is empty..\n");
	}
	else
	{
		printf("The element at the front of the queue is %d \n\n",q->queue[q->front]);
	}
}

int main()
{
	
	struct queue* Q = createQueue(3);
	enqueue(Q,5);
	enqueue(Q,9);
	enqueue(Q,19);
	enqueue(Q,29);
	display(Q);
	
	front(Q);
	
	dequeue(Q);
	display(Q);
	
	dequeue(Q);
	display(Q);
	
	dequeue(Q);
	display(Q);

	dequeue(Q);
	
	return 0;
}
