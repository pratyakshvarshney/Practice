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
    node *temp=head, *newnode ;
    llc lloc;
    int item;
    head = NULL;
    lloc.tail=NULL;
    printf("Enter data to be entered (enter 999 to stop): \n");
    scanf("%d", &item);
    while (item != 999) {
        newnode = createnode(item);
        if (head == NULL) {
            head = lloc.tail= newnode;  
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
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;
    return(head);
}

//insert element at end
llc insert_end(node *head){
    node *newnode,*temp=head;
    llc lloc;
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
        newnode->prev=temp;
    }
    lloc.head=head;
    lloc.tail=newnode;
    return(lloc);
}

//insert element after a given value
llc insert_after(node *head){
    llc lloc;
    node *newnode,*temp=head;
    int item,value;
    
    printf("enter value of a particular node after which newnode is to be inserted: \n");
    scanf("%d",&value);
    
    printf("enter data to be inserted in node after a particular node containing certain value: \n");
    scanf("%d",&item);
    newnode=createnode(item);
    
    if(head->data==value){
        newnode->next = head->next;
        newnode->prev=head;
        head->next=newnode;
        if(newnode->next)
            newnode->next->prev=newnode;
        lloc.head=head;
        lloc.tail=newnode;
        return lloc;
    }
    
    else{
        while(temp && temp->data!=value){
            temp=temp->next;
        }
        
        if(temp==NULL){
            printf("value not found \n");
        }
        else{
            newnode->next=temp->next;
            newnode->prev=temp;
            if(temp->next)
                temp->next->prev=newnode;
            temp->next=newnode;
        }
        lloc.head=head;
    }    
    return(lloc);
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
        newnode->prev=NULL;
        head->prev=newnode;
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
            temp->next->prev=newnode;
            newnode->prev=temp;
            temp->next=newnode;
        }
    }
    return(head);
}

//delete element from beginning
llc delete_begin(node *head){
    llc lloc;
    if(head->next==NULL){
        lloc.head=NULL;
        lloc.tail=NULL;
        return lloc;
    }
    else{
        node *temp=head;
        head=head->next;
        head->prev=NULL;
        lloc.head=head;
        free(temp);
        return lloc;
    }
}

//delete element from end
llc delete_end(node *head){
    llc lloc;
    node *save,*temp=head;
    if(head==NULL){
        lloc.head=lloc.tail=NULL;
        return lloc;
    }
    else if(head->next==NULL) {
        lloc.head=lloc.tail=NULL;
        free(temp);
        return lloc;
    }
    else{
        while(temp->next->next){
            temp=temp->next;
        }
        save=temp->next;
        temp->next=NULL;
        lloc.tail=temp;
        free(save);
        return lloc;
    }
}

//delete element if it's known
llc delete_loc(node *head){
    llc lloc;
    node *save,*temp=head;
    int value;
    printf("enter value to be deleted: \n");
    scanf("%d",&value);
    if(head==NULL){
        lloc.head=lloc.tail=NULL;
        return lloc;
    }
    else if(temp->data==value){
        if(temp->next==NULL){
            lloc.head=lloc.tail=NULL;
            return lloc;
        }
        else{
            head=head->next;
            head->prev=NULL;
            free(temp);
            lloc.head=head;
            return lloc;
        }
    }
    else{
        while(temp){
            if(temp->next->data==value){
                save=temp->next;
                temp->next=save->next;
                if(save->next==NULL){
                    temp->next=NULL;
                    lloc.head=head;
                    lloc.tail=temp;
                    return lloc;
                }
                save->next->prev=temp;
                free(save);
                lloc.head=head;
                return lloc;
            }
            temp=temp->next;
        }
    }
}

//reverse the ll
llc reverse_ll(node *head){
    llc lloc;
    node *prev=NULL,*current=head,*next;
    node *t_prev=NULL,*t_current=lloc.tail,*t_next;
    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
     while(t_current){
        t_prev=t_current->prev;
        t_currrent->prev=t_next;
        t_next=t_current;
        t_current=t_prev;
    }
    tail=t_next;
    lloc.head=head;
    lloc.tail=tail;
    return lloc;
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
    
    // searching an element
    search(head);

    // insert at beginning
    head=insert_begin(head);
    print_ll(head);
    print_ll_backward(tail);
    
    // insert at end
    lloc=insert_end(head);
    head=lloc.head;
    tail=lloc.tail;
    print_ll(head);
    print_ll_backward(tail);
    
    // insert after a particular node if value is known
    lloc=insert_after(head);
    head=lloc.head;
    tail=lloc.tail;
    print_ll(head);
    print_ll_backward(tail);
    
    // insert before a particular node if value is known
    head=insert_before(head);
    print_ll(head);
    print_ll_backward(tail);
    
    // delete from beginning
    lloc=delete_begin(head);
    head=lloc.head;
    tail=lloc.tail;
    print_ll(head);
    print_ll_backward(tail);
    
    // delete from end
    lloc=delete_end(head);
    head=lloc.head;
    tail=lloc.tail;
    print_ll(head);
    print_ll_backward(tail);
    
    
    // delete if value is known
    lloc=delete_loc(head);
    head=lloc.head;
    tail=lloc.tail;
    print_ll(head);
    print_ll_backward(tail);
    
    // // reverse the ll
    lloc=reverse_ll(head);
    head=lloc.head;
    tail=lloc.tail;
    print_ll(head);
    print_ll_backward(tail);

    return 0;
}
