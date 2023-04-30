#include<stdio.h>
#include<math.h>
void main(){
    int arr[20],i,j,n,power;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    power = pow(2,n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);

    printf("Power set is:\n");
    
    for (i=0;i<power;i++){
        for (j=0;j<n;j++){
            if(i&(1<<j))
                printf("%d",arr[j]);
        }
        printf("\n");
    }
}