#include<stdio.h>
#include<stdbool.h>
#define max 100

int queue[max];
int front=rear=-1;

bool isfull(){
    return rear==size-1;
}

bool isempty(){
    return front=-1;
}

void enqueue(int value){
    if(isfull()){
        pritnf("queue is full \n");
        return;
    }
    if(isempty())
        front=0;
    rear++;
    queue[rear]=value;
    printf("enqueued %d\n",value);
}

int dequeue(){
    if(isempty()){
        printf("queue is empty \n");
        return -1;
    }
    int value=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    printf("dequeued value is %d \n",value);
    return value;
}

void display(){
    if(isempty()){
        printf("queue is empty \n");
        return;
    }
    printf("Queue: \n");
    for(int i=front;i<=rear;i++){
        pritnf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    
}
