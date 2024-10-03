#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//queue definition
typedef struct queue{
    int data;
    struct queue *next;
}queue;

queue *front=NULL;
queue *rear=NULL;

//node definition
queue *createnode(int data){
    queue *newnode=(queue *)malloc(sizeof(queue));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

bool isempty(){
    return front==NULL;
}

//printing queue
void display(){
    if(isempty())
        printf("Queue is empty \n");
    else{
        printf("Queue is: \n");
        queue *temp=front;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

//dequeue operation
int dequeue(){
    if(isempty()){
        printf("Queue is empty \n");
        return -1;
    }
    queue *temp=front;
    int value=temp->data;
    front=temp->next;
    if(front==NULL){
        rear=NULL;
    }
    free(temp);
    printf("Dequeued value is %d \n",value);
    return 0;
}

void enqueue(int value){
    queue *newnode=createnode(value);
    if(rear==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=rear->next;
    }
    printf("Enqueued value is %d \n",value);
}

int peek(){
    if(isempty()){
        printf("Queue is empty \n");
        return -1;
    }
    return front->data;
}

int main(){
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
