#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
   int data;
   struct ListNode *next;
};

int linkedListSize(struct ListNode *head)
{
   int size = 0;

   if (head == NULL)
   {
      printf("Linked List is empty");
   }

   struct ListNode *current = head;

   while (current != NULL)
   {
      size++;
      current = current->next;
   }

   return size;
}

struct ListNode *createNode(int data)
{
   struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

   if (newNode == NULL)
   {
      perror("Memory allocation failed");
      exit(EXIT_FAILURE);
   }

   newNode->data = data;
   newNode->next = NULL;

   return newNode;
};

void linkedListTraversal(struct ListNode *head)
{
   if (head == NULL)
   {
      printf("Linked List is empty!");
   }

   struct ListNode *current = head;

   while (current != NULL)
   {
      printf("%d -> ", current->data);
      current = current->next;
   }

   printf("NULL");
}

struct ListNode *unshift(struct ListNode *head, int data)
{
   struct ListNode *newHead = createNode(data);

   newHead->next = head;
   head = newHead;

   return head;
}

struct ListNode *push(struct ListNode *tail, int data)
{
   struct ListNode *newTail = createNode(data);

   tail->next = newTail;
   tail = newTail;

   return tail;
}

void freeList(struct ListNode *head)
{
   struct ListNode *current = head;
   struct ListNode *temp;

   while (current != NULL)
   {
      temp = current;

      current = current->next;
      free(temp);
   }
}

int main()
{
   int testData[] = {20, 30, 40, 50, 60, 70, 80, 100};

   struct ListNode *head = NULL, *tail = NULL;

   int sizeOfList = sizeof(testData) / sizeof(testData[0]);
   int size = 0;

   while (sizeOfList--)
   {
      if (head == NULL)
      {
         head = createNode(testData[size]);
         tail = head;

         size++;
      }
      else
      {
         tail->next = createNode(testData[size]);
         tail = tail->next;

         size++;
      }
   }

   head = unshift(head, 10);
   head = unshift(head, 5);
   head = unshift(head, 2);

   tail = push(tail, 200);
   tail = push(tail, 210);
   tail = push(tail, 220);

   /* // Perform a traversal to print the linked list elements */
   printf("Linked list traversal: ");
   linkedListTraversal(head);
   printf("\n");

   /* // Print the size of the linked list */
   printf("Linked list size: %d\n", linkedListSize(head));

   freeList(head);
   freeList(tail);

   return 0;
}