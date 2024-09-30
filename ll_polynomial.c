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

node *addpoly(node *head1,node *head2){
    
}

int main(){
    node *head1,*head2,*add;
    
    head1=createll(head1);
    head2=createll(head2);
    
    printf("1st");
    printll(head1);

    printf("2nd");
    printll(head2);
    
    add=addpoly(head1,head2);
    printll(add);
    

    return 0;
}
