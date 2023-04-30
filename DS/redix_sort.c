#include<stdio.h>
int b[10],c[10];
void main(){
    int a[10],j,i;
    printf("Enter the array elements:\n");
    for (i=0;i<10;i++)
        scanf("%d",&a[i]);
    

    //counting and printing frequency
    printf("B:\n");
    for (i=0;i<10;i++)
        b[a[i]]+=1;
    for (i=0;i<10;i++)
        {printf("%d ",b[i]);
        }
    
    printf("\n");

    //calculating and printing cummulative sum
    printf("Cummulative B:\n");
    for (i=1;i<10;i++){
        b[i] = b[i-1]+b[i];
        
    }
    for (i=0;i<10;i++)
        {printf("%d ",b[i]);
        }
    printf("\n");

    printf("Sorted:\n");
    for (i=9;i>=0;i--){
        c[b[a[i]]-1]=a[i];
        b[a[i]]-=1;

    }
    
    for (i=0;i<10;i++)
        {printf("%d ",c[i]);
        }
}