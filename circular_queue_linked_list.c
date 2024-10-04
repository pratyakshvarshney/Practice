
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//queue definition
typedef struct queue{
    int data;
    struct queue *next;
}queue;

queue *front = NULL;
queue *rear = NULL;

// Function to create a new node
queue *createnode(int data){
    queue *newnode = (queue *)malloc(sizeof(queue));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to check if the queue is empty
bool isempty(){
    return front == NULL;
}

// Function to print the elements of the queue
void display(){
    if(isempty()){
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        queue *temp = front;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

// Function to remove an element from the front of the queue (dequeue)
int dequeue(){
    if(isempty()){
        printf("Queue is empty.\n");
        return -1;
    }

    int value = front->data;

    // Case when there is only one node in the queue
    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        queue *temp = front;
        front = front->next;
        rear->next = front;  // Maintain circular link
        free(temp);
    }

    printf("Dequeued value is %d\n", value);
    return value;
}

// Function to add an element to the rear of the queue (enqueue)
void enqueue(int value){
    queue *newnode = createnode(value);

    if (rear == NULL) {
        front = rear = newnode;
        rear->next = front;  // Circular link: rear points to front
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;  // Circular link: rear points to front
    }

    printf("Enqueued value is %d\n", value);
}

// Function to get the front element of the queue (peek)
int peek(){
    if(isempty()){
        printf("Queue is empty.\n");
        return -1;
    }
    return front->data;
}

int main(){
    int choice, value;

    while(true){
        printf("\n Queue Operations Menu \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                value = peek();
                if(value != -1)
                    printf("Front element is: %d\n", value);
                break;
            case 5:
                printf("Exiting program.\n");
                // Free up all the nodes before exiting
                while(!isempty())
                    dequeue();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
