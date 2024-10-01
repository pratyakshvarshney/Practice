#include<stdio.h>
#define max_size 100;

void printpoly(int coeff[],int exp[],int term){
    int i;
    for(i=0;i<term;i++){
        printf("%dx^%d",coeff[i],exp[i]);
        if(i<term-1)
            printf("+");
    }
    printf("\n");
}



int main(){
    int coeff1[max_size],exp1[max_size],term1,coeff2[max_size],exp2[max_size],term2,coeff_r[max_si,exp_r[max_size],term_r,i;
 
    printf("enter no. of terms in polynomial 1: \n");
    scanf("%d",&term1);
    for(i=0;i<term1;i++){
        printf("enter term %d in the form of coefficient,exponent: \n",i+1);
        scanf("%d,%d",coeff[i],exp1[i]);
    }
    printf("polynomial 1 is: \n");
    printpoly(coeff1,exp1,term1);
 
    printf("enter no. of terms in polynomial 2: \n");
    scanf("%d",&term1);
    for(i=0;i<term1;i++){
        printf("enter term %d in the form of coefficient,exponent: \n",i+1);
        scanf("%d,%d",coeff[i],exp1[i]);
    }
    printf("polynomial 2 is: \n");
    printpoly(coeff2,exp2,term2);
    
    addpoly(coeff1,exp1,term1,coeff2,exp2,term2,coeff_r,exp_r,&term_r)
return 0;
}
