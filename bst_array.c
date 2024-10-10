#include<stdio.h>
#define max 100

int tree[max];

//insertion in tree
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

//return largest element index from left child
int max_index(int  i){
    while(2*i+2<max && tree[2*i+2]!=0){
        i=2*i+2;
    }
    return i;
}

//deletion in tree
void delete(int value){
    int i=0;
    while(i<max){
        if(tree[i]==value){
            if(tree[2*i+1]==0 && tree[2*i+2]==0)
                tree[i]=0;
            else if(tree[2*i+1]==0){
                tree[i]=tree[2*i+2];
                tree[2*i+2]=0;
                }
            else if(tree[2*i+2]==0){
                tree[i]=tree[2*i+1];
                tree[2*i+1]=0;
                }
            else{
                int max1 = max_index(2*i+1);
                tree[i]=tree[max1];
                delete(tree[max1]);
                }
        return;
        }
        if (value < tree[i])
            i = 2*i+1;
        else
            i = 2*i+2;
    }
    printf("value not found!\n");
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

//search in tree
int search(int value){
    int i=0;
    while(i<max){
        if(tree[i]==value)
            return 1;
        if(value<tree[i])
            i=2*i+1;
        else
            i=2*i+2;
    }
    return 0;
}

// Menu function
void menu() {
    printf("Menu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. In-order Traversal\n");
    printf("5. Pre-order Traversal\n");
    printf("6. Post-order Traversal\n");
    printf("7. Exit\n");
}

int main(){
    int choice,value,found,i=0;
    while(i<max){
        tree[i]=0;
        i++;
    }
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2: // Delete
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3: // Search
                printf("Enter value to search: ");
                scanf("%d", &value);
                found=search(value);
                if (found) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 4: // In-order Traversal
                printf("In-order traversal: ");
                inorder(0);
                printf("\n");
                break;
            case 5: // Pre-order Traversal
                printf("Pre-order traversal: ");
                preorder(0);
                printf("\n");
                break;
            case 6: // Post-order Traversal
                printf("Post-order traversal: ");
                postorder(0);
                printf("\n");
                break;
            case 7: // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
