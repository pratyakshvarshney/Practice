#include<stdio.h>
#include<stdlib.h>

typedef struct polynode{
    int coeff;
    int exp;
    struct polynode *next;
}node;

void printll(node *head){
    node *temp=head;
    printf("polynomial linked list as coefficient , its exponent is: \n");
    while(temp){
        printf("%d,%d->",temp->coeff,temp->exp);
        temp=temp->next;
    }
    printf("NULL \n");
}

node *createnode(int c,int e){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->coeff=c;
    newnode->exp=e;
    newnode->next=NULL;
    return newnode;
}

node *createll(node *head){
    node *temp, *newnode;
    int c,e;
    head = NULL;
    printf("Enter coefficient to be entered (enter 999 to stop): \n");
    scanf("%d", &c);
    if(c!=999){
        printf("Enter corresponding exponents for coefficient entered: \n");
        scanf("%d", &e);
    }
    while (c != 999) {
        newnode = createnode(c,e);
        if (head == NULL) {
            head = newnode;  
            temp = head;
        } 
        else {
            temp->next = newnode; 
            temp = newnode;    
        }
        printf("Enter coefficient to be entered (enter 999 to stop): \n");
        scanf("%d", &c);
        if(c!=999){
            printf("Enter corresponding exponents for coefficient entered: \n");
            scanf("%d", &e);
        }
    }
    return head;
}

int main(){
    node *head;
    
    head=createll(head);
    printll(head);
    
    

    return 0;
}
