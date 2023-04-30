//implementation of bubble sort
#include<stdio.h>
void main(){
    int arr[20],i,j,temp,size,key;

    printf("enter the size:" );
    scanf("%d",&size);
    if (size ==0)printf("Please input size greater than 0!");
    else{
    printf("enter the array elements: \n");
    for (i=0;i<size;i++)
        scanf("%d",&arr[i]);
   
    for (i=0;i<size-1;i++){
        // key = arr[i];
        for (j=0;j<size-i;j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array: \n");
    for (i=0;i<size;i++)
        printf("%d   ",arr[i]);
    }


}