#include<stdio.h>
void main(){
    int arr[10],brr[10],j,i,n,m;
    printf("Enter the size of first set: ");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for (i=0;i<n;i++)
        scanf("%d",(arr+i));
    printf("Enter the size of second set: ");
    scanf("%d",&m);
    for (j=0;j<m;j++)
        scanf("%d",(brr+j));
    printf("{");
    for (i=0;i<n;i++){
        for(j=0;j<m;j++){
            
            printf("(%d , %d) ",*(arr+i),*(brr+j));
            
        }
    }
    printf("}");
}