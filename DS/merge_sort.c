#include<stdio.h>
int count;
void merge_sort(int arr[],int lb, int ub){ // for breaking array into subarrays
    if (lb<ub)
    {
        int mid = (lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
    
}

void merge(int arr[],int lb,int mid, int ub ){ // for merging subarrays
    int i = lb,j = mid+1, k = lb;
    int b[20];
    while(i<=mid && j<=ub){
        if (*(arr + i)<*(arr + j)){
            b[k] = arr[i];
            i++;
            
        }
        else{
            b[k] = arr[j];
            j++;
            
        }
        k++;
        count++;
    }
    if(i>mid){
        while(j<=ub){
            b[k] = arr[j];
            k++; j++;
        }
    }
    else{
        while(i<=mid){
            b[k] = arr[i];
            i++; k++;
        }
    }
    for (k = lb; k<=ub; k++){
        arr[k] = b[k];
    }
}

void print_arr(int arr[],int n){
    for (int i =0;i<n;i++)
        printf("%d\n",*(arr+i));
    printf("\n");
}

void main(){
    int arr[20],i,j,n;
    printf("Enter the size: ");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    merge_sort(arr,0,n-1);
    printf("After Sorting: \n");
    print_arr(arr,n);
    printf("%d",count);
}