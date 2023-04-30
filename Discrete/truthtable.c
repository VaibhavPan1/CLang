#include<stdio.h>
void main(){
    int a,b,i,j,opt;
    printf("A\tB\tA.B\n");
    //AND TABLE
    for(i=0;i<2;i++){
        for (j=0;j<2;j++){
            printf("%d\t%d\t%d ",i,j,i&j);
            printf("\n");
        }
    }

    //OR TABLE
    printf("\n");
    printf("A\tB\tA+B\n");
    for(i=0;i<2;i++){
        for (j=0;j<2;j++){
            printf("%d\t%d\t%d ",i,j,i|j);
            printf("\n");
        }
    }

    //NOT
    printf("\n");
    printf("A\tA'\n");
        for (j=0;j<2;j++){
            printf("%d\t%d ",j,!j);
            printf("\n");
        }

    /*     do{
        printf("Enter the A: " );
        scanf("%d",&a);
        printf("Enter the B: ");
        scanf("%d",&b);
        printf("A\tB\tA.B\n");
        printf("%d\t%d\t%d\n",a,b,a&b);
        printf("Do you wish to continue? Press any key to continue else press -1. ");
        scanf("%d",&opt);

    }while(opt!=-1); */

}