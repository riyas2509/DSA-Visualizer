// tree.c
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

TreeNode* root = NULL;

// Function to create a new node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node into BST
TreeNode* insert(TreeNode* node, int val) {
    if (node == NULL) return createNode(val);
    if (val < node->data) node->left = insert(node->left, val);
    else node->right = insert(node->right, val);
    return node;
}

// Inorder Traversal
void inorder(TreeNode* node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Preorder Traversal
void preorder(TreeNode* node) {
    if (node) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Postorder Traversal
void postorder(TreeNode* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

// Basic ASCII Display (Indented)
void displayTree(TreeNode* node, int space) {
    if (node == NULL) return;
    space += 5;
    displayTree(node->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", node->data);
    displayTree(node->left, space);
}

// Tree Menu
void treeMenu() {
    int choice, val;
    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert Node\n2. Inorder\n3. Preorder\n4. Postorder\n5. Display Tree\n6. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Tree Structure:\n");
                displayTree(root, 0);
                break;
            case 6:
                return;
            default:
                printf("Invalid input.\n");
        }
    }
}