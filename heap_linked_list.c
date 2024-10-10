#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int value) {
    Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        Node *prev = NULL;
        while (current != NULL && current->data < value) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            newNode->next = *head;
            *head = newNode;
        } else {
            newNode->next = current;
            prev->next = newNode;
        }
    }
}

void printHeap(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Simple example of heapify for min-heap
void heapify(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        Node *next = current->next;
        while (next != NULL) {
            if (current->data > next->data) {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
}

int main() {
    Node *heap = NULL;
    insert(&heap, 10);
    insert(&heap, 5);
    insert(&heap, 20);
    insert(&heap, 15);
    
    printf("Heap elements: ");
    printHeap(heap);
    
    heapify(&heap);
    
    printf("Heap after heapify: ");
    printHeap(heap);
    
    return 0;
}
