#include<stdio.h>
#include<stdbool.h>

int top=-1,stack[3];
int size;

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
