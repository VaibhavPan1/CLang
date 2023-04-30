//program to find intersection of two sets
#include<stdio.h>
void intersection();
void main(){
    intersection();
}

void intersection(){
    int c[6],i,j,k,a[3],b[3],flag=0;
    printf("Enter the aray elements 1:\n");
    for (i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the aray elements 2:\n");
    for (i=0;i<3;i++){
        scanf("%d",&b[i]);
    }

    //combine both sets
    for (i=0;i<3;i++){
        c[i]=a[i];
    }
    for (i=0;i<3;i++){
        c[i+3]=b[i];
    }
    printf("intersection\n");
    for(i=0;i<3;i++){
        flag=0;
        for(j=3;j<6;j++){
            if(c[i]==c[j]){
                flag=1;
                printf("%d\n",c[i]);
                break;
            }
        }
        // if(flag==1)
        //     printf("%d\n",c[i]);
    }

}