#include<stdio.h>
#define max 50

int partition(int a[],int beg,int end){
    int pivot=a[beg];
    int j=beg;
    for(int i=beg+1;i<=end;i++){
        if(a[i]<pivot){
            j++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp = a[beg];
    a[beg] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[],int beg,int end){
    if (beg < end) {
        int pivot = partition(a, beg, end);
        quicksort(a, beg, pivot - 1);
        quicksort(a, pivot + 1, end);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int a[max],n;
    printf("enter the number of elements less than equal 50: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter element %d: ",i);
        scanf("%d",&a[i]);
    }
    
    printf("array is: \n");
    printArray(a,n);
    
    quicksort(a,0,n-1);
    
    printf("sorted array is: \n");
    printArray(a,n);
}