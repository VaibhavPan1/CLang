//symmetric difference
#include<stdio.h>
void main(){
    int a[50],b[50],c[50];
    int i,j,k,l,m,n,flag=0,ind=0;
    printf("Enter the no of elements in first set: \n");
    scanf("%d",&n);
    printf("Enter the set elements\n");
    for  (i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the no of elements in second set: \n");
    scanf("%d",&m);
    printf("Enter the set elements\n");
    for  (i=0;i<m;i++)
        scanf("%d",&b[i]);
    
    //logic for a-b
    for (i=0;i<n;i++){
        flag=0;
        for (j=0;j<m;j++){
            if (a[i]==b[j]){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            c[ind]=a[i];
            ind++;
        }
    }


    printf("\n");
    //logic for b-a
    for (i=0;i<m;i++){
        flag=0;
        for (j=0;j<n;j++){
            if (b[i]==a[j]){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            c[ind]=b[i];
            ind++;
        }
    }

    //print c
    printf("Symmetric diff of A and B:\n");
    for (i=0;i<ind;i++){
        printf("%d ",c[i]);
    }
}