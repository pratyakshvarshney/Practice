#include<stdio.h>
#include<stdlib.h>

//queue definition
typedef struct queue{
    int data;
    struct queue *next;
}queue;

queue *front,*rear;

//node definition
queue *createnode(int data){
    queue *newnode=(queue *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

//printing queue
void print_ll(node *front){
    printf("Queue is: \n");
    node *temp=front;
    while(temp){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

//Enqueue operations
queue *enqueue(queue *front){
    queue *newnode;
    int item;
    printf("enter data to be inserted in new node at beginning: \n");
    scanf("%d",&item);
    newnode=createnode(item);
    newnode->next=head;
    front=newnode;
    return(front);
}

//delete element from beginning
node *delete_begin(node *head){
    node *temp=head;
    head=temp->next;
    free(temp);
    return head;
}

//in it after several enqueue operation to max limit then dequeue after which it size decreases!!

#include<stdio.h>
#include<stdbool.h>

int queue[100];
int size;
int front=-1;
int rear=-1;

bool isfull(){
    return rear==size-1;
}

bool isempty(){
    return front==-1;
}

void enqueue(int value){
    if(isfull()){
        printf("queue is full \n");
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
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    printf("Enter the size of the queue (max 100): ");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid stack size. Please enter a size between 1 and 100.\n");
        return 1; // to represent error
    }
    
    int choice,value;
    while (true) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

int main(){
    node *head;

    // creating ll
    head=createll(head);
    print_ll(head);
    
    // searching an element
    search(head);

    // insert at beginning
    head=insert_begin(head);
    print_ll(head);
    
    // insert at end
    head=insert_end(head);
    print_ll(head);
    
    // insert after a particular node
    head=insert_after(head);
    print_ll(head);
    
    // insert before a particular node
    head=insert_before(head);
    print_ll(head);
    
    // delete from beginning
    head=delete_begin(head);
    print_ll(head);
    
    // delete from end
    head=delete_end(head);
    print_ll(head);
    
    // delete if value is known
    head=delete_loc(head);
    print_ll(head);
    
    // reverse the ll
    head=reverse_ll(head);
    print_ll(head);

    return 0;
}
