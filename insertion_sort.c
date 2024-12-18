#include <stdio.h>

void insertionsort(int *arr, int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j] > current && j>=0 ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

void print(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    
    int arr[] = {3, 5, 1, 2, 0, 9, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    print(arr, n);
    insertionsort(arr, n);
    print(arr, n);

    return 0;
}
