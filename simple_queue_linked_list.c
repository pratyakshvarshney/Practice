#include<stdio.h>
#include<stdlib.h>

//queue definition
typedef struct queue{
    int data;
    struct queue *next;
}queue;

queue *front,*rear;
front=NULL;
rear=NULL;

//node definition
queue *createnode(int data){
    queue *newnode=(queue *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

//printing queue
void display(node *front){
    printf("Queue is: \n");
    node *temp=front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

//Enqueue operations
queue *enqueue(queue *front){
    queue *newnode;
    int item;
    printf("enter data to be enqueued: \n");
    scanf("%d",&item);
    newnode=createnode(item);
    newnode->next=front;
    front=newnode;
    return(front);
}

//dequeue operation
int dequeue(queue *front){
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
    return value;
}

bool isempty(){
    return front==NULL;
}

void enqueue(int value){
    queue *newnode=createnode(value);
    if(rear==NULL){
        front=newnode;
        reae=newnode;
    }
    else{
        rear->next=newnode;
        rear=rear->next;
    }
    printf("Enqueued value is %d \n",value);
}

int seek(){
    if(isempty()){
        pritnf("Queue is empty \n");
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
