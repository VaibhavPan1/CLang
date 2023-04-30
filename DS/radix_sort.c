#include<stdio.h>
int get_max(int arr[],int n){
    int i,max=arr[0];
    for(i=1;i<n;i++){
        if (max<*(arr+i)){
            max = *(arr+i);             

        }
    }
    return max;
}

void count_sort(int arr[],int n, int pos){
    int b[10]={0},c[n],i;

    for (i=0;i<n;i++)
        b[(arr[i]/pos)%10]++; //this is count array  it stores the frequencyd

    for (i=1;i<10;i++)
        b[i] += b[i-1]; // this is the cummulative sum array it stores the cummulative sum

    for (i=n-1;i>=0;i--){
        c[b[(arr[i]/pos)%10]-1]=arr[i]; //c is the output array
        b[(arr[i]/pos)%10]-=1;

    }
    for (i=0;i<n;i++)
        arr[i]=c[i]; //copying the value of c in original array
        
}

void radix_sort(int arr[],int n){
    int max = get_max(arr,n),pos; //to get the no of digits in max value so that we can class count sort that many tinmes
    for (pos = 1;max/pos>0;pos*=10){
        count_sort(arr,n,pos);
    }
}

void print(int arr[],int n){
    for (int i=0;i<n;i++)
        {printf("%d ",arr[i]);
        }
    printf("\n");
}


void main(){
    int arr[20],n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    // n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting: \n");
    print(arr,n);
    printf("After sorting: \n");
    radix_sort(arr,n);
    print(arr,n);
    
}