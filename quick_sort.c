#include<stdio.h>
#define max 50

int partition(int a[],int beg,int end){
    int left=beg,right=end;
    int pivot=beg,temp;
    
    while(left!=right){
        while(a[pivot]<=a[right]  && pivot!=right){
            right--;
        }
        if(pivot==right) return pivot;
        if(a[pivot]>a[right]){
            temp=a[pivot];
            a[pivot]=a[right];
            a[right]=temp;
            pivot=right;
        }
        
        while(a[pivot]>=a[left]  && pivot!=left){
            left++;
        }
        if(pivot==left) return pivot;
        if(a[pivot]<a[left]){
            temp=a[pivot];
            a[pivot]=a[left];
            a[left]=temp;
            pivot=left;
        }
    }
    return pivot;
}

void quicksort(int a[],int n){
    int lower[max],upper[max],top=-1;
    int beg,end,pivot;
    
    if(n>1){
        top++;
        lower[top]=0;
        upper[top]=n-1;
    }
    
    while(top!=-1){
        beg=lower[top];
        end=upper[top];
        top--;
        
        pivot=partition(a,beg,end);
        
        if(beg<pivot-1){
             top++;
             lower[top]=beg;
             upper[top]=pivot-1;
        }
        
        if(pivot+1<end){
            top++;
            lower[top]=pivot+1;
            upper[top]=end;
        }
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
    printf("enter the number of elements \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter element %d: ",i);
        scanf("%d",&a[i]);
    }
    
    printf("array is: \n");
    printArray(a,n);
    
    quicksort(a,n);
    
    printf("sorted array is: \n");
    printArray(a,n);
}
