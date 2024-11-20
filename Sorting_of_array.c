#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//
void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j+1],&a[j]);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of elements for the array\n");
    scanf("%d",&n);
    int a[n];    
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    printf("Sorted Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    return 0; 
}
