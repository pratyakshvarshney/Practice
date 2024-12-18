#include <stdio.h>

void conquer(int arr[], int si, int mid, int ei){
    int merged[ei - si + 1];
    
    int index1 = si;
    int index2 = mid+1;
    int x = 0;
    
    while(index1 <= mid && index2 <= ei){
        if(arr[index1] <= arr[index2])
            merged[x++] = arr[index1++];
        else
            merged[x++] = arr[index2++];
    }
    
    while(index1 <= mid){
        merged[x++] = arr[index1++];
    }
    
    while(index2 <= ei){
        merged[x++] = arr[index2++];
    }
    
    int j = si;
    int n = ei - si + 1;
    for(int i=0; i<n; i++){
        arr[j++] = merged[i];
    }
}

void mergesort(int *arr, int si, int ei){
    if(si >= ei)
        return;
    int mid = si + (ei - si)/2;
    mergesort(arr, si, mid);
    mergesort(arr, mid+1, ei);
    conquer(arr, si, mid, ei);
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
    mergesort(arr, 0, n-1);
    print(arr, n);

    return 0;
}
