#include<stdio.h>
int main(){
    int a,b,c,avg;
    printf("enter first number \n");
    scanf("%d",&a);
    printf("enter second number \n");
    scanf("%d",&b);
    printf("enter third number \n");
    scanf("%d",&c);
    avg=(a+b+c)/3;
    printf("average of %d,%d,%d is:%d",a,b,c,avg);
    return 0;
}
