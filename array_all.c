#include<stdio.h>

void entry(int *a,int c){
    int i;
    for(i=0;i<c;i++){
        printf("enter %d element of array \n",i+1);
        scanf("%d",&a[i]);
    }
}

void display(int *a, int c){
    int i ;
    for(i=0;i<c;i++){
        printf("element %d of array is: %d\n",i+1,a[i]);
    }
}

void insert(int *a,int loc,int item,int c){
    int i;
    for(i=c;i>loc;i--)
        a[i]=a[i-1];
    a[loc]=item;
}

void delete(int *a,int loc,int c){
    int i;
    for(i=loc-1;i<c-1;i++){
        a[i]=a[i+1];
    }
    a[c-1]=0;
}

void reverse(int *a,int c){
    int i,temp;
    for(i=0;i<c/2;i++){
        temp=a[i];
        a[i]=a[(c-1)-i];
        a[(c-1)-i]=temp;
    }
}

void bubblesort(int *a,int c){
    int i,j,temp,flag;
    for(i=0;i<c;i++){
        for(j=0;j<(c-1)-i;j++){
            flag=0;
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
    if(flag==0)
        break;
    }
}

void linearsearch(int *a,int c,int item){
    int i,check=0;
    for(i=0;i<c;i++){
        if(a[i]==item){
            printf("search is successful , element found at %d position\n",i+1);
            check++;
        }
    }
    if(check==0){
        printf("element not found! \n");
    }
}

void binarysearch(int *a,int c,int item){
    bubblesort(a,c);
    int lb,ub,mid,i,check=0;
    lb=0;
    ub=c-1;
    while(lb<=ub){
        mid=(lb+ub)/2;
        if(a[mid]==item){
            printf("element found at location %d \n",mid+1);
            check++;
            break;
        }
        else if(a[mid]>item){
            ub=mid-1;
        }
        else{
            lb=mid+1;
        }    
    }
    if(check==0)
        printf("search was unsuccessful! \n");
}

int main(){
    //for list formation and print it
    int c;
    printf("enter the size of array \n");
    scanf("%d",&c);
    int a[c];
    entry(a,c);
    display(a,c);
    
    //for element insertion when location and element is given
    int item,loc;
    printf("enter item, loc want to inserted \n");
    scanf("%d",&item);
    scanf("%d",&loc);
    insert(a,loc,item,c);
    display(a,c);
    
    //for element to be deletedwhen location is given
    int loc1;
    printf("enter the location from where element need to be deleted \n");
    scanf("%d",&loc1);
    delete(a,loc1,c);
    display(a,c-1);
    
    //reverse the list
    printf("reversed list is : \n");
    reverse(a,c);
    display(a,c);
    
    //sort the list
    printf("sorted array is : \n");
    bubblesort(a,c);
    display(a,c);
    
    //search an item in list
    int item;
    printf("enter element to be searched: \n");
    scanf("%d",&item);
    //linear search
    linearsearch(a,c,item);
    //binary search
    binarysearch(a,c,item);

    return 0;
}
