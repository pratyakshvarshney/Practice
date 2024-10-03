#include<stdio.h>
#include<stdbool.h>

int queue[100];
int size;
int front=-1;
int rear=-1;

bool isfull(){
    return (rear+1)%size==front;
}

bool isempty(){
    return front==-1;
}

void enqueue(int value){
    if(isfull()){
        printf("Queue is full\n");
        return;
    }
    if(isempty()){
        front=0;
    }
    rear=(rear+1)%size;
    queue[rear]=value;
    printf("Enqueued: %d\n",value);
}

int dequeue(){
    if(isempty()){
        printf("Queue is empty \n");
        return -1;
    }
    int value=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%size;
    }
    printf("Dequeued: %d\n",value);
    return 0;
}

int peek(){
    if(isempty()){
        printf("Queue is empty \n");
        return -1;
    }
    return queue[front];
}

void display(){
    if(isempty()){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue: \n");
    int i=front;
    while(true){
        printf("%d ",queue[i]);
        if(i==rear) break;
        i=(i+1)%size;
    }
    printf("\n");
}

int main(){
    printf("Enter the size of dhe queue (max 100): ");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid Queue size. Please enter a size between 1 and 100.\n");
        return 1; // to represent error
    }
    
    int choice,value;
    while (true) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                peek();
                break;
            case 5:
                printf("Exiting program.\n");
                while(!isempty())
                    dequeue;
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
