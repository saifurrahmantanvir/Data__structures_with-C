#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Stack
{
   struct Node *top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack *stack)
{
   stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
   return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = stack->top;
   stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
   if (isEmpty(stack))
   {
      printf("Stack Underflow\n");
      return -1;
   }
   struct Node *temp = stack->top;
   int value = temp->data;
   stack->top = stack->top->next;
   free(temp);
   return value;
}

int main()
{
   struct Stack stack;
   initializeStack(&stack);

   push(&stack, 1);
   push(&stack, 2);
   push(&stack, 3);

   printf("Popped element: %d\n", pop(&stack));
   printf("Popped element: %d\n", pop(&stack));

   return 0;
}