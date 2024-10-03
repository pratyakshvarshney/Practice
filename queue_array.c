#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100  // Maximum size of the queue

// Queue array and variables
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to add an item to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty()) {
        front = 0;  // If queue was empty, set front to 0
    }
    rear = (rear + 1) % MAX_SIZE;  // Circular increment
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an item from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1; // Return an error value
    }
    int value = queue[front];
    if (front == rear) { // Queue has only one element
        front = -1;      // Reset queue
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;  // Circular increment
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (true) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;  // Circular increment
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    display();

    return 0;
}

