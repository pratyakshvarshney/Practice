#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//bubble sort
void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j+1],&a[j]);
            }
        }
    }
}

//selection sort
void selectionsort(int *a,int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(&a[i],&a[min]);
    }
}

//quick sort
int partition(int *a,int low,int high){
    int pivot=a[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
}

//insertionsort
void insertionsort(int *a,int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

//

int main(){
    int n;
    printf("Enter the number of elements for the array\n");
    scanf("%d",&n);
    int a[n];    
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    
    //bubblesort(a,n);
    //selectionsort(a,n);
    //insertionsort(a,n);
    printf("Sorted Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0; 
}            
