//isfull is not defined as use of linked list disable the size limit barrier to much extend

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//stack definition
typedef struct stack{
    int data;
    struct stack*next;
}stack;

//node definition
stack*createnode(int data){
    stack*newnode=(stack*)malloc(sizeof(stack));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

bool isempty(stack *top){
    return top==NULL;
}

void push(stack **top,int value){
    stack *newnode=createnode(value);
    newnode->next=*top;
    *top=newnode;
    printf("value %d is pushed into the stack \n",value);
}

void pop(stack **top){
    if(isempty(*top)){
        printf("underflow condition: \n");
        return ;
    }
    stack *temp=*top;
    int pop_value=temp->data;
    (*top)=(*top)->next;
    free(temp);
    printf("poped value is: %d \n",pop_value);
}

void peek(stack *top){
    if(isempty(top)){
        printf("underflow condition: \n");
        return ;
    }
    int peek_value=top->data;
    printf("peeked value is: %d \n",peek_value);
}

void display(stack *top){
    if (isempty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    stack*temp=top;
    while(temp){
        printf("%d \n",temp->data);
        temp=temp->next;
    }
}

int main(){
    stack *top;
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
                push(&top,value);
                break;
            case 2: 
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4: 
                display(top);
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
