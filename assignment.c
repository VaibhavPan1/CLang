#include<stdio.h>
void main(){
   int T,i,j,k,l,m,n,o,size,element,arr[100],index,occur,pos,len,result[100],a;
   printf("Enter the number of test cases: \n");
   scanf("%d",&T);
   for(i=1;i<=T;i++){
      len=0;
      occur=0;
      printf("Enter the size of array and element to be removed:\n");
      scanf("%d%d",&size,&element);
      printf("Enter the array elements:\n");
      for(j=0;j<size;j++){
         scanf("%d",arr+j);
      }
      for(k=0;k<size;k++){
         if(arr[k]==element){
            occur++;
         }
      }      
      for(l=1;l<=occur;l++){
         for(m=0;m<size;m++){
            if(arr[m]==element){
               pos=m+1;
               break;
            }
         }
         for(n=pos-1;n<size-1;n++){
            arr[n]=arr[n+1];
         }
      size--; 
      }
      if(occur==0){
         printf("element not found\n");
      }
    printf("Resultant Array is:\n");
      for(o=0;o<size;o++){
           printf("%d\n",arr[o]);
           len=len+1;
           
      }
      a=len;
      printf("Length of Resultant array = %d\n",len); 
      result[i-1]=len;   
   }
   printf("\n**********\nFinal Result:\n");
   for(i=0;i<T;i++)
   	printf("%d\n",result[i]);
}
