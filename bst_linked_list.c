#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} tree;

tree *createnode(int value) {
    tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// In-order traversal LNR
void inorder(tree *node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Pre-order traversal NLR
void preorder(tree *node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Post-order traversal LRN
void postorder(tree *node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// Insert a node into the BST
tree *insert(tree *node, int value) {
    if (node == NULL) 
        return createnode(value);
    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    return node;
}

// Find the minimum value node
tree *find_min(tree *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Delete a node from the BST
tree *delete_node(tree *node, int value) {
    if (node == NULL) return node;

    if (value < node->data) {
        node->left = delete_node(node->left, value);
    } else if (value > node->data) {
        node->right = delete_node(node->right, value);
    } else {
        // Node with one child or no child
        if (node->left == NULL) {
            tree *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            tree *temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children: Get the inorder successor
        tree *temp = find_min(node->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data);
    }
    return node;
}

// Search for a value in the BST
tree *search(tree *node, int value) {
    if (node == NULL || node->data == value)
        return node;
    if (value < node->data)
        return search(node->left, value);
    return search(node->right, value);
}

// Menu function
void menu() {
    printf("Menu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. In-order Traversal\n");
    printf("5. Pre-order Traversal\n");
    printf("6. Post-order Traversal\n");
    printf("7. Exit\n");
}

int main() {
    tree *root = NULL;
    int choice, value;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2: // Delete
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                break;
            case 3: // Search
                printf("Enter value to search: ");
                scanf("%d", &value);
                tree *found = search(root, value);
                if (found) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 4: // In-order Traversal
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5: // Pre-order Traversal
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6: // Post-order Traversal
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7: // Exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
