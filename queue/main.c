#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Queue
{
   struct Node *front;
   struct Node *rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue *queue)
{
   queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
   return queue->front == NULL;
}

// Function to enqueue (push) an element into the queue
void enqueue(struct Queue *queue, int value)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   if (isEmpty(queue))
   {
      queue->front = queue->rear = newNode;
   }
   else
   {
      queue->rear->next = newNode;
      queue->rear = newNode;
   }
}

// Function to dequeue (pop) an element from the queue
int dequeue(struct Queue *queue)
{
   if (isEmpty(queue))
   {
      printf("Queue Underflow\n");
      return -1;
   }
   struct Node *temp = queue->front;
   int value = temp->data;
   queue->front = queue->front->next;
   free(temp);
   if (queue->front == NULL)
   {
      queue->rear = NULL;
   }
   return value;
}

int main()
{
   struct Queue queue;
   initializeQueue(&queue);

   enqueue(&queue, 1);
   enqueue(&queue, 2);
   enqueue(&queue, 3);

   printf("Dequeued element: %d\n", dequeue(&queue));
   printf("Dequeued element: %d\n", dequeue(&queue));

   return 0;
}