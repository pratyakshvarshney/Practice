//check if it is Armstrong number
#include<stdio.h>
#include<math.h>
int main(){
    int n,temp,remainder,digit=0,result=0;
    printf("enter no. to be checked as armstrong \n");
    scanf("%d",&n);

    temp=n;
    while (temp){
        temp/=10;
        digit++;
    }

    temp=n;
    while(temp){
        remainder=temp%10;
        result+=pow(remainder,digit);
        temp/=10;
    }

    if(result==n){
        printf("number is armstrong number \n");
    }
    else{
        printf("number is not armstrong number \n");
    }
return 0;
}

//average of three numbers
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

//check if input character is digit or not
#include<stdio.h>
int main(){
    char chr;
    int i;
    printf("enter the character to be checked: \n");
    scanf(" %c",&chr);
        if(chr>='0' && chr<='9'){
            printf("input character is digit \n");
        }
        else{
            printf("input character is not digit \n");
        }
    return 0;
}

//cube of a number
#include<stdio.h>
int main(){
    int n;
    printf("enter number whose cube is required: \n");
    scanf("%d",&n);
    printf("cube of number %d is: %d ",n,n*n*n);
    return 0;
}

//area of rectangle
#include <stdio.h>
int main() {
    //perimeter of rectangle
    int a,b;
    printf("enter length a of rectangle \n");
    scanf("%d",&a);
    printf("enter breadth b of rectangle \n");
    scanf("%d",&b);
    printf("area of rectangle is: %d",a*b);
    return 0;
}

//smaller of teo numbers
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
