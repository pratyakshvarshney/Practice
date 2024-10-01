#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//ll definition
typedef struct stack{
    int data;
    struct stack*next;
}stack;

//stackdefinition
stack*createnode(int data){
    stack*newnode=(stack*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

//printing ll
void print_ll(stack*head){
    printf("Linked List is: \n");
    stack*temp=head;
    while(temp){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}

//creating ll
stack*createll(stack*head) {
    stack*temp, *newnode;
    int item;
    head = NULL;
    printf("Enter data to be entered (enter 999 to stop): \n");
    scanf("%d", &item);
    while (item != 999) {
        newnode= createnode(item);
        if (head == NULL) {
            head = newnode;  
            temp = head;
        } 
        else {
            temp->next = newnode; 
            temp = newNode;    
        }
        printf("Enter data to be entered (enter 999 to stop): \n");
        scanf("%d", &item);
    }
    return head;
}

int size;
stack*head;

bool isempty(){
    return top==-1;
}

bool isfull(){
    return top==size-1;
}

void push(int value){
    if(isfull()){
        printf("overflow condtition: \n");
        return;
    }
    stack[++top]=value;
}

int pop(){
    if(isempty()){
        printf("underflow condition: \n");
        return -1;
    }
    return stack[--top];
}

void peek(){
    if(isempty()){
        printf("underflow condition: \n");
        return ;
    }
    printf("peeked element is: %d \n",stack[top]);
}

void display(){
    printf("stack: \n");
    if(isempty()){
        printf("is empty  \n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d \n",stack[i]);
    }
}

int main(){
     printf("Enter the size of the stack (max 3): ");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid stack size. Please enter a size between 1 and 100.\n");
        return 1; // to represent error
    }
    
    int choice,value;
    while (true) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2: 
                pop();
                break;
            case 3:
                peek();
                break;
            case 4: 
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
