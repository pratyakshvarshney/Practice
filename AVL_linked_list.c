#include<stdio.h>
#include<stdlib.h>

typedef struct avl{
    int data;
    struct avl *left;
    struct avl *right;
    int height;
}avl;

int height(avl *node){
    return node ? node->height : 0 ;
}

int balancefactor(avl *node){
    return node? height(node->left) - height(node->right) : 0;
}

avl *createnode(int value){
    avl *newnode=(avl *)malloc(sizeof(avl));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    newnode->height=1;
    return newnode;
}

int max(int a,int b){
    return (a>b)?a:b;
}

avl *rotateright(avl *node){
    avl *x=node->left;
    avl *temp=x->right;
    
    x->right=node;
    node->left=temp;
    
    node->height = max(height(node->left),height(node->right)) + 1 ;
    x->height = max(height(x->left),height(x->right)) + 1 ; 
    
    return x;
}

avl *rotateleft(avl *node){
    avl *x=node->right;
    avl *temp=x->left;
    
    x->left=node;
    node->right=temp;
    
    node->height = max(height(node->left),height(node->right)) + 1 ;
    x->height = max(height(x->left),height(x->right)) + 1 ;
    
    return x;
}

avl *insert(avl *node,int value){
    if(node==NULL) return createnode(value);
    if(value < node->data)
        node->left=insert(node->left,value);
    else if(value > node->data)
        node->right=insert(node->right,value);
    else
        return node;
        
    node->height = max(height(node->left),height(node->right)) + 1 ;
    
    int balance = balancefactor(node);
    
    if(balance > 1 && value < node->left->data){
        return rotateright(node);
    }
    if(balance < -1 && value > node->right->data)
        return rotateleft(node);
    if(balance > 1 && value > node->left->data){
        node->left=rotateleft(node->left);
        return rotateright(node);
    }
    if(balance < -1 && value < node->right->data){
        node->right=rotateright(node->right);
        return rotateleft(node);
    }
    return node;
}

void inorder(avl *node){
    if(node != NULL){
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

int main() {
    avl *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("In-order traversal of the AVL tree:\n");
    inorder(root);

    return 0;
}            
