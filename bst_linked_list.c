#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

tree *createnode(int value){
    tree *newnode=(tree *)malloc(sizeof(tree));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

//inoder traversal LNR
void inorder(tree *node){
    if(node==NULL) return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}

//preorder traversal NLR
void preorder(tree *node){
    if(node==NULL) return;
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

//postorder traversal LRN
void postorder(tree *node){
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
}

//BST
tree *insert(tree *node,int value){
    if(node==NULL) 
        return createnode(value);
    if(value < node->data)
        node->left=insert(node->left,value);
    else if(value > node->data)
        node->right=insert(node->right,value);
    return node;
}

int main(){
    tree *root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,56);
    insert(root,45);
    insert(root,31);
    insert(root,22);
    
    printf("In-order traversal: ");
    inorder(root);
    printf("\nPre-order traversal: ");
    preorder(root);
    printf("\nPost-order traversal: ");
    postorder(root);
    
    return 0;
}
