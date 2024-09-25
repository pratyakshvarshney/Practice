#include<stdio.h>
int main(){
    int a,b;
    printf("enter first number: \n");
    scanf("%d",&a);
    printf("enter second number: \n");
    scanf("%d",&b);
    if(a<b){
        printf("%d is smaller of two numbers provided\n",a);
    }
    else{
        printf("%d is smaller of two numbers provided\n",b);
    }
    return 0;
}
