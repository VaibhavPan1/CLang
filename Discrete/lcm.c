#include<stdio.h>
int min_num(int a,int b, int c){
    if (a>b && a>c) return a;
    else if(b>a && b>c) return b;
    else return c;
}
void main(){
    int i,num1,num2,num3,flag=0,lcm,gcd;
    printf("Enter num 1: ");
    scanf("%d",&num1);
    printf("Enter num 2:");
    scanf("%d",&num2);
    printf("Enter num 3:");
    scanf("%d",&num3);
    int min = min_num (num1,num2,num3);
    for (i=2;i<=(min/2);i++){
        if(num1%i==0 && num2%i==0 && num3%i == 0 ){
            gcd = i;
            flag=1;
            break;
        }

    }
    if(flag==0){
        lcm = num1*num2*num3;
        printf("LCM = %d\n",lcm);
        printf("GCD = %d\n",(num1*num2*num3)/lcm);
    }
    else{
        printf("GCD = %d\n",lcm);
        printf("LCM = %d\n",(num1*num2*num3)/lcm);
    }
    
}