#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void countsort(int *arr, int n){
    int k = arr[0];
    
    for(int i=1; i<n; i++){
        k = fmax(k, arr[i]);
    }
    
    int *count = (int *)calloc(k, sizeof(int));
    
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
    
    for(int i=1;i<k+1;i++){
        count[i] += count[i-1];
    }
    
    int output[n];
    
    for(int i=n-1; i>=0; i--){
        output[--count[arr[i]]] = arr[i];
    }
    
    for(int i=0; i<n ;i++){
        arr[i] = output[i];
    }
    
    free(count);
    
}

void print(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 1, 0, 1, 3, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    countsort(arr, n);
    print(arr, n);

    return 0;
}
