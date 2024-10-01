#include<stdio.h>
#define max_size 100

void printpoly(int coeff[],int exp[],int term){
    int i;
    for(i=0;i<term;i++){
        printf("%dx^%d",coeff[i],exp[i]);
        if(i<term-1)
            printf("+");
    }
    printf("\n");
}

void addpoly(int *coeff1,int *exp1,int term1,int *coeff2,int *exp2,int term2,int *coeff_r,int *exp_r,int *term_r){
    int i,j,k;
    i=j=k=0;
    while(i<term1 && j<term2){
        if(exp1[i]==exp2[j]){
            coeff_r[k]=coeff1[i]+coeff2[j];
            exp_r[k]=exp1[i];
            i++;
            j++;
        }
        else if(exp1[i] > exp2[j]){
            coeff_r[k]=coeff1[i];
            exp_r[k]=exp1[i];
            i++;
        }
        else{
            coeff_r[k]=coeff2[j];
            exp_r[k]=exp2[j];
            j++;
        }
        k++;
    }
    while(i<term1){
         coeff_r[k]=coeff1[i];
            exp_r[k]=exp1[i];
            i++;
            k++;
    }
    while(j<term2){
        coeff_r[k]=coeff2[j];
            exp_r[k]=exp2[j];
            j++;
            k++;
    }
    *term_r=k;
}

int main(){
    int coeff1[max_size],exp1[max_size],term1,coeff2[max_size],exp2[max_size],term2,coeff_r[max_size],exp_r[max_size],term_r,i;
 
    printf("enter no. of terms in polynomial 1: \n");
    scanf("%d",&term1);
    for(i=0;i<term1;i++){
        printf("enter term %d in the form of coefficient,exponent: \n",i+1);
        scanf("%d,%d",&coeff1[i],&exp1[i]);
    }
    printf("polynomial 1 is: \n");
    printpoly(coeff1,exp1,term1);
 
    printf("enter no. of terms in polynomial 2: \n");
    scanf("%d",&term2);
    for(i=0;i<term2;i++){
        printf("enter term %d in the form of coefficient,exponent: \n",i+1);
        scanf("%d,%d",&coeff2[i],&exp2[i]);
    }
    printf("polynomial 2 is: \n");
    printpoly(coeff2,exp2,term2);
    
    addpoly(coeff1,exp1,term1,coeff2,exp2,term2,coeff_r,exp_r,&term_r);
    printf("resultant polynomial is: \n");
    printpoly(coeff_r,exp_r,term_r);
    
return 0;
}
