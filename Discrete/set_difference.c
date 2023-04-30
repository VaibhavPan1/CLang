//set difference of a-b and b-a

#include<stdio.h>
void main(){
    int a[20],b[20],size,i,j,flag = 0,c[20],ind=0; //no need for C and ind
    printf("enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the array elements of a: \n");
    for (int i=0; i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the array elements of b: \n");
    for (int i=0; i<size;i++){
        scanf("%d",&b[i]);
    }
    printf("diff of a and b:\n");
    for(i=0; i<size; i++){
        flag = 0;
        for(j=0;j<size;j++){
            if(a[i]==b[j]){
                flag = 1;
                break;
            }
        }
        if (flag==0){
            printf("%d ",a[i]);
            c[ind] = a[i];
        }

    }

    /* for(i=0;i<=ind;i++)
        printf("%d",c[i]); */

    printf("\ndiff of b and a:\n");
    for(i=0; i<size; i++){
        flag = 0;
        for(j=0;j<size;j++){
            if(b[i]==a[j]){
                flag = 1;
                break;
            }
        }
        if (flag==0){
            printf("%d ",b[i]);
        }

    }
    

}