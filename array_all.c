#include<stdio.h>

void entry(int *a,int c){
    int i;
    for(i=1;i<=c;i++){
        printf("enter %d element of array \n",i);
        scanf("%d",&a[i]);
    }
}

void display(int *a, int c){
    int i ;
    for(i=1;i<=c;i++){
        printf("element %d of array is: %d\n",i,a[i]);
    }
}

void insert(int *a,int loc,int item,int c){
    int i;
    for(i=c;i>loc;i--)
        a[i]=a[i-1];
    a[loc]=item;
}

int main(){
    int c;
    printf("enter the size of array \n");
    scanf("%d",&c);
    int a[c];
    entry(a,c);
    display(a,c);
    int item,loc;
    printf("enter item, loc want to inserted \n");
    scanf("%d",&item);
    scanf("%d",&loc);
    insert(a,loc,item,c);
    display(a,c);
    
    return 0;
}
