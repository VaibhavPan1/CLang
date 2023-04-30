#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int lb, int ub){ //backbone of the quicksort
    /*

    int pivot = arr[lb], start = lb, end = ub; //pivot as the first element
        
        
    while (start < end){
        while (arr[start]<= pivot)
            start++;
        while (arr[end]>pivot)
            end--;
        if (start < end)
            swap(&arr[start],&arr[end]);
    }

    swap(&arr[lb],&arr[end]);
    return end; */


    int pivot = arr[ub]; //pivot as the last element
    int i=lb-1;

    for (int j =lb;j<=ub;j++){
        if(arr[j]<pivot){
            i++;
            swap (&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[ub]);
    return i+1;

    
}

void quick_sort(int arr[],int lb,int ub){
    if (lb<ub){
        int loc = partition(arr,lb,ub); //pivot 
        quick_sort(arr,lb, loc-1); //left partition 
        quick_sort(arr, loc+1, ub); // right partition 
    }
}

void print_arr(int arr[],int n){
    for (int i=0;i<n;i++)
        printf("%d\t",*(arr+i));
    printf("\n");
}

void main(){
    int arr[20],i,n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for (i=0;i<n;i++)
        scanf("%d",arr+i);
    printf("Before sort: \n");
    print_arr(arr,n);
    printf("After sort: \n");
    quick_sort(arr,0,n-1);
    print_arr(arr,n);

}