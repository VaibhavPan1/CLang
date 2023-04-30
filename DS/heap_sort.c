#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *b = *a;
    *a = temp;
}


void min_heapify(int arr[],int i, int n){
    int left_child = 2*i + 1, right_child = 2*i + 2;
    if (right_child<n){
        if(arr[i]>arr[left_child] && arr[left_child]<arr[right_child]){
            
                swap(&arr[i],&arr[left_child]);
                min_heapify(arr,left_child,n);
            
        }
        else if(arr[i]>arr[right_child] && arr[right_child]<arr[left_child]){
            swap(&arr[i],&arr[right_child]);
            min_heapify(arr,right_child,n);
        }
        
    }
    else if(left_child < n && right_child>=n) {
        if(arr[i]>arr[left_child]){
            swap(&arr[i],&arr[left_child]);
            min_heapify(arr,left_child,n);
        }
    }
    /* int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest])
      smallest = l;
    if (r < n && arr[r] < arr[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(&arr[i], &arr[smallest]);
      min_heapify(arr, n, smallest);
    } */
}

void build_heap(int arr[],int n){
    for(int i=(n/2)-1; i>=0;i--){
        min_heapify(arr,i,n);
    }
}


void print_arr(int arr[],int n){
    for (int i = 0;i<n;i++){
        printf("%d\t",*(arr+i));
    }
}


void main(){
    int n,arr[10],i;
    printf("Enter the size of heap: ");
    scanf("%d",&n);
    printf("Enter the heap elements:\n");
    for (i=0;i<n;i++) scanf("%d",arr+i);
    build_heap(arr, n);
    print_arr(arr,n);

}
