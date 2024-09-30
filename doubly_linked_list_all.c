#include<stdio.h>
#include<stdlib.h>

//ll definition
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

//node definition
node *createnode(int data){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

//printing ll in forward direction
void print_ll(node *head){
    printf("Linked List in forward direction is: \n");
    node *temp=head;
    while(temp){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}

//printing ll in backward direction
void print_ll_backward(node *tail){
    printf("Linked List in backward direction is: \n");
    node *temp=tail;
    while(temp){
        printf("%d->",temp->data);
        temp=temp->prev;
    }
    printf("NULL \n");
}

//searching an elementin ll
void search(node *head){
    node *temp=head;
    int item;
    printf("enter data to be searched: \n");
    scanf("%d",&item);
    int count=0;
    node *loc;
    while(temp){
        if(temp->data==item){
            printf("search successful \n");
            return;
        }
        else
            temp=temp->next;
    }
    printf("search unsuccessful \n");
}

//specifying ll head and tail
typedef struct ll_components{
    node *head;
    node *tail;
}llc;

//creating ll
llc createll(node *head) {
    node *temp, *newnode ;
    llc lloc;
    int item;
    head = NULL;
    printf("Enter data to be entered (enter 999 to stop): \n");
    scanf("%d", &item);
    while (item != 999) {
        newnode = createnode(item);
        if (head == NULL) {
            head = newnode;  
            temp = head;
        } 
        else {
            temp->next = newnode; 
            newnode->prev=temp;
            temp = newnode;    
        }
        printf("Enter data to be entered (enter 999 to stop): \n");
        scanf("%d", &item);
    }
    lloc.head=head;
    lloc.tail=temp;
    return lloc;
}

//insert element at beginning
node *insert_begin(node *head){
    node *newnode;
    int item;
    printf("enter data to be inserted in new node at beginning: \n");
    scanf("%d",&item);
    newnode=createnode(item);
    newnode->next=head;
    head=newnode;
    return(head);
}

//insert element at end
node *insert_end(node *head){
    node *newnode,*temp=head;
    int item;
    printf("enter data to be inserted in new node at end: \n");
    scanf("%d",&item);
    newnode=createnode(item);
    if(head==NULL){
        head=newnode;
    }
    else{
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return(head);
}

//insert element after a given value
node *insert_after(node *head){
    node *newnode,*temp=head;
    int item,value;
    
    printf("enter value of a particular node after which newnode is to be inserted: \n");
    scanf("%d",&value);
    
    printf("enter data to be inserted in node after a particular node containing certain value: \n");
    scanf("%d",&item);
    newnode=createnode(item);
    
    if(head->data==value){
        newnode->next = head;
        head = newnode;
        return head;
    }
    
    else{
        while(temp!=NULL && temp->next->data!=value){
            temp=temp->next;
        }
        
        if(temp==NULL){
            printf("value not found \n");
        }
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }    
    
    return(head);
}

//insert element before a given value
node *insert_before(node *head){
    node *newnode,*temp=head;
    int item,value;
    
    printf("enter value of a particular node before which newnode is to be inserted: \n");
    scanf("%d",&value);
    
    printf("enter data to be inserted in node before a particular node containing certain value: \n");
    scanf("%d",&item);
    newnode=createnode(item);
    
    if(head->data==value){
        newnode->next=head;
        head=newnode;
        return head;
    }
    else{
        while(temp!=NULL && temp->next->data!=value){
            temp=temp->next;
        }
        
        if(temp==NULL){
            printf("value not found \n");
        }
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    return(head);
}

//delete element from beginning
node *delete_begin(node *head){
    node *temp=head;
    head=temp->next;
    free(temp);
    return head;
}

//delete element from end
node *delete_end(node *head){
    node *save,*temp=head;
    if(head==NULL){
        return head;
    }
    else if(head->next==NULL) {
        head=NULL;
        free(temp);
        return head;
    }
    else{
        while(temp->next->next){
            temp=temp->next;
        }
        save=temp->next;
        temp->next=NULL;
        free(save);
        return head;
    }
}

//delete element if it's known
node *delete_loc(node *head){
    node *save,*temp=head;
    int value;
    printf("enter value to be deleted: \n");
    scanf("%d",&value);
    if(head==NULL)
        return head;
    else if(temp->data==value){
        head=head->next;
        free(temp);
        return head;
    }
    else{
        while(temp){
            if(temp->next->data==value){
                save=temp->next;
                temp->next=temp->next->next;
                free(save);
                return head;
            }
            temp=temp->next;
        }
    }
}

//reverse the ll
node *reverse_ll(node *head){
    node *prev=NULL,*current=head,*next;
    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}

int main(){
    node *head,*tail;

    // creating ll
    llc lloc;
    lloc=createll(head);
    head=lloc.head;
    tail=lloc.tail;
    print_ll(head);
    print_ll_backward(tail);
    
    // // searching an element
    // head=search(head);
    // print_ll(head);

    // // insert at beginning
    // head=insert_begin(head);
    // print_ll(head);
    
    // // insert at end
    // head=insert_end(head);
    // print_ll(head);
    
    // // insert after a particular node
    // head=insert_after(head);
    // print_ll(head);
    
    // // insert before a particular node
    // head=insert_before(head);
    // print_ll(head);
    
    // // delete from beginning
    // head=delete_begin(head);
    // print_ll(head);
    
    // // delete from end
    // head=delete_end(head);
    // print_ll(head);
    
    // // delete if value is known
    // head=delete_loc(head);
    // print_ll(head);
    
    // // reverse the ll
    // head=reverse_ll(head);
    // print_ll(head);

    return 0;
}
