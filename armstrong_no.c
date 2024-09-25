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
