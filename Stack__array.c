#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack
{
   int top;
   int arr[MAX_SIZE];
};

// Function to initialize an empty stack
void initializeStack(struct Stack *stack)
{
   stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack)
{
   return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
   if (stack->top == MAX_SIZE - 1)
   {
      printf("Stack Overflow\n");
      return;
   }
   stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
   if (isEmpty(stack))
   {
      printf("Stack Underflow\n");
      return -1;
   }
   return stack->arr[stack->top--];
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
