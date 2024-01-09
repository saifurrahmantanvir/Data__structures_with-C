#include<stdio.h>
#include<stdlib.h>

/**
 * @brief Every `TreeNode` will have three member variables/fields.
 * 
 * @def data -> Content of the `TreeNode`. This can be of any type.
 * 
 * @def left -> left field will hold/(point to) the memory address of the left
 * `TreeNode`. Similarly,
 * 
 * @def right -> right field will hold the memory address of the right
 * `TreeNode`.
 * 
 * 
 */
struct TreeNode {
   int data;
   struct TreeNode *left;
   struct TreeNode *right;
};

/**
 * @brief With the `createNode` function, we are creating a `TreeNode` and
 * returning the memory address of the created `TreeNode`
 * 
 * @param data 
 * @return struct TreeNode*
 * 
 * 
 */
struct TreeNode *createNode(int data) {
   /**
    * @brief With the `malloc` function, we are allocating memory required to
    * store a `TreeNode`.
    * 
    * `malloc` function takes(as argument) the size required to store a
    * `TreeNode` and allocates memory and returns the memory address of the
    * allocated memory
    * 
    * `malloc` function returns the memory address as a type of void pointer.
    * @ref void *malloc(size_t _Size) {}
    * 
    * So, we are type casting the returned value of `malloc` function using
    * (struct TreeNode*)
    * 
    * 
    * 
    */
   struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

   if(newNode == NULL) {
      perror("Memory allocation failed");
      exit(EXIT_FAILURE);
   }

   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;

   return newNode;
};

struct TreeNode *insert(struct TreeNode *root, int data) {
   if(root == NULL) {
      return createNode(data);
   }

   if(data < root->data) {
      root->left = insert(root->left, data);
   }
   else if(data > root->data) {
      root->right = insert(root->right, data);
   }

   return root;
}

void inorderTraversal(struct TreeNode *root) {
   if(root != NULL) {
      inorderTraversal(root->left);
      printf("%d ", root->data);
      inorderTraversal(root->right);
   }
}

void preorderTraversal(struct TreeNode *root) {
   if(root != NULL) {
      printf("%d ", root->data);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
   }
}

void postorderTraversal(struct TreeNode *root) {
   if(root != NULL) {
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      printf("%d ", root->data);
   }
}

void freeTree(struct TreeNode *root) {
   if(root != NULL) {
      freeTree(root->left);
      freeTree(root->right);

      free(root);
   }
}

int main() {
   struct TreeNode *root = NULL;

   root = insert(root, 50);
   insert(root, 30);
   insert(root, 20);
   insert(root, 40);
   insert(root, 70);
   insert(root, 60);
   insert(root, 80);

   /* // Perform an inorder traversal to print the tree elements */
   printf("Inorder traversal: ");
   inorderTraversal(root);
   printf("\n");

   /* // Perform a preorder traversal to print the tree elements */
   printf("Preorder traversal: ");
   preorderTraversal(root);
   printf("\n");

   /* // Perform a postorder traversal to print the tree elements */
   printf("Postorder traversal: ");
   postorderTraversal(root);
   printf("\n");

   freeTree(root);

   return 0;
}