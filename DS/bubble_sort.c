//program for bubble sort
#include<stdio.h>
void main(){
    int arr[20],i,j,temp,size,key;
    printf("enter the size:" );
    scanf("%d",&size);
    printf("enter the array elements: \n");
    for (i=0;i<size;i++)
        scanf("%d",&arr[i]);

    for (i=0;i<size-1;i++){
        key = arr[i];
        for (j=0;j<size-i;j++){
            if (key > arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    printf("Sorted arary: \n");
    for (i=0;i<size;i++)
        printf("%d   ",arr[i]);   
}


//handle the errors