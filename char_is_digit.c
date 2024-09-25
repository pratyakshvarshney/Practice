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
