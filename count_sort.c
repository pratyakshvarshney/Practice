#include <stdio.h>
#include <stdlib.h>

void countsort(int *arr, int n){
    int min_val = arr[0], max_val = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }

    int offset = (min_val < 0) ? -min_val : 0;
    int k = max_val + offset;
    for (int i = 0; i < n; i++) {
        arr[i] += offset;
    }
    
    int *count = (int *)calloc(k+1, sizeof(int));
    
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
    
    for(int i=1;i<k+1;i++){
        count[i] += count[i-1];
    }
    
    int *output = (int *)malloc(n * sizeof(int));
    
    for(int i=n-1; i>=0; i--){
        output[--count[arr[i]]] = arr[i];
    }
    
    for(int i=0; i<n ;i++){
        arr[i] = output[i] - offset;
    }

    free(output);
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
