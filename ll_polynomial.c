#include<stdio.h>
#include<stdlib.h>

typedef struct polynode{
    int coeff;
    int exp;
    struct polynode *next;
}node;

void print_ll(node *head){
    node *temp=head;
    printf("polynomial linked list is: \n");
    while(temp){
        printf("%d->")
    }
}

node *createnode(int c,int e){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->coeff=c;
    newnode->exp=e;
    newnode->next=NULL;
    return newnode;
}

node *create_ll(node *head){
    
}
