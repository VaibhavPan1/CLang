#include<stdio.h>
void main(){
    int a[10],b[10],c[6],n,i,j,k;\

    // printf("enter the size of array\n");
    // scanf("%d",&n);
    
    printf("enter the array 1 elements:\n");
    for(i=0;i<3;i++)scanf("%d",(a+i));
    
    printf("enter the array 2 elements: \n");
    for(i=0;i<3;i++)scanf("%d",&b[i]);

    for(i=0;i<3;i++){
        c[i]=a[i];
    }
    for (i=0;i<3;i++){
        c[3+i]=b[i];
    }

    for (i=0;i<6;i++){
        k=0;
        for(j=i+1;j<5;j++){
            if(c[i]==c[j]){
                k=1;break;
            }
        }
        if(k==0){
            printf("%d ",c[i]);
        }
    }


}