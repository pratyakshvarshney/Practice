#include<stdio.h>
#define max 100

int tree[max];

void insert(int value){
    int i=0;
    while(i<max){
        if(tree[i]==0){
            tree[i]=value;
            return;
        }
        if(value < tree[i])
            i=2*i + 1;
        else
            i=2*i + 2;
    }
    printf("Tree s full , can't insert %d\n",value);
}

//inorder traversal LNR
void inorder(int i){
    if(i >= max || tree[i] == 0) return;
    inorder(2*i+1);
    printf("%d ",tree[i]);
    inorder(2*i+2);
}

//preorder traversal NLR
void preorder(int i){
    if(i >=max || tree[i] ==0) return;
    printf("%d ",tree[i]);
    preorder(2 * i + 1);
    preorder(2 * i + 2);
}

//postorder traversal LRN
void postorder(int i){
    if(i >=max || tree[i] ==0) return;
    postorder(2 * i + 1);
    postorder(2 * i + 2);
    printf("%d ",tree[i]);
}

int main(){
    int size,value;
    printf("Enter the no. of entries to be made for the tree (max 10): ");
    scanf("%d", &size);
    
    for (int i = 0; i < max; i++) {
        tree[i] = 0;
    }
    
    for(int i=0; i<size; i++){
        printf("Enter a value to insert: ");
        scanf("%d", &value);
        insert(value);
    }
    
    printf("In-order traversal: ");
    inorder(0);
    printf("\nPre-order traversal: ");
    preorder(0);
    printf("\nPost-order traversal: ");
    postorder(0);
    
    return 0;
}
