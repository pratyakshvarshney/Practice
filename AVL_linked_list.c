#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

// Get the height of the node
int height(AVLNode *node) {
    return node ? node->height : 0;
}

// Calculate the balance factor
int balanceFactor(AVLNode *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Create a new AVL node
AVLNode *createNode(int data) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Update the height of a node
int max(int a, int b) { return (a > b) ? a : b; }

// Left Rotation
AVLNode *rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Right Rotation
AVLNode *rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Insert a value in the AVL Tree
AVLNode *insert(AVLNode *node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicate keys not allowed

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = balanceFactor(node);

    // LL Case
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    // RR Case
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    // LR Case
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL Case
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// In-order traversal
void inorderTraversal(AVLNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    AVLNode *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("In-order traversal of the AVL tree:\n");
    inorderTraversal(root);

    return 0;
}
