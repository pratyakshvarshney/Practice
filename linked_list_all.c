#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *createnode(int data){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void print_ll(node *head){
    printf("Linked List is: \n");
    node *temp=head;
    while(temp){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}

node *createll(node *head){
    int i,n;
    node *temp=head;
    printf("enter no. of node wanna enter excluding the head(treated as node 0): \n");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        printf("enter data for Node%d : \n",i);
        scanf("%d",temp->data);
        temp=temp->next;
    }
    temp=head;
    while(n){
        temp=
        n--;
    }
}

int main(){
    node *head;
    head=createnode(10);
    head->next=createnode(20);
    head->next->next=createnode(30);
    
    print_ll(head);
    
    return 0;
}
