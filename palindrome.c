#include<stdio.h>
void main(){
    int num, rev=0, rem,i,temp;
    scanf("%d",&num);
    temp = num;
    while(num){
        rem = num % 10;
        rev = rev*10 + rem;
        num = num/10;
         
    }
    printf("%d",rev);
    if (rev == temp)
        printf("it is palindrome\n");
    else
        printf("not palindrome\n");
}