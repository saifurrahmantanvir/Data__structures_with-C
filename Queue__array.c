#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue
{
   int front, rear;
   int arr[MAX_SIZE];
};

// Function to initialize an empty queue
void initializeQueue(struct Queue *queue)
{
   queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue)
{
   return queue->front == -1;
}

// Function to check if the queue is full
bool isFull(struct Queue *queue)
{
   return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue (push) an element into the queue
void enqueue(struct Queue *queue, int value)
{
   if (isFull(queue))
   {
      printf("Queue Overflow\n");
      return;
   }
   if (isEmpty(queue))
   {
      queue->front = queue->rear = 0;
   }
   else
   {
      queue->rear = (queue->rear + 1) % MAX_SIZE;
   }
   queue->arr[queue->rear] = value;
}

// Function to dequeue (pop) an element from the queue
int dequeue(struct Queue *queue)
{
   if (isEmpty(queue))
   {
      printf("Queue Underflow\n");
      return -1;
   }
   int value = queue->arr[queue->front];
   if (queue->front == queue->rear)
   {
      queue->front = queue->rear = -1;
   }
   else
   {
      queue->front = (queue->front + 1) % MAX_SIZE;
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