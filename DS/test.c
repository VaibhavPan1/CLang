#include<conio.h>

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node{
    int data;
    struct node *next;
}n;
n *root=NULL;
void printLL(){
    n *temp=root;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data );
        temp=temp->next;
    }
}
void create_LL(){
    int data,i,size;
    n *newnode,*temp;
   
    printf("\nEnter Number of node\n");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
         newnode=(n*)malloc(sizeof(n));
         newnode->next=NULL;
        printf("\nEnter %d data : ",i+1);
        scanf("%d",&data);
        newnode->data=data;
    
    if(root==NULL){
        root=newnode;
    }
    
    else{
        temp=root;
        while(temp->next!=NULL)
        {
          temp=temp->next;
        }
        temp->next=newnode;
    }
    }
    
}

void delete_after()
{
    int del,i,temp;
    n *ptr,*current,*aft;
    current=root;
    printf("\nEnter after which node you want to delete\n");
    scanf("%d",&del);

    while(current!=del)
    {
        current=current->next;
    }
    temp=current->next;
    aft=current->next->next;
    if(aft!=NULL)
    {
        current->next=aft;
    }
    else{
        current->next=NULL;
    }
      free(temp);
}

void main()
{
    int ch;
    printf("\nPress\n1-Create Node\n0-Exit");
    scanf("%d",&ch);
    switch(ch){
        case 1:create_LL(); break;
        case 2:exit(0);
    }
    printLL();
    delete_after();
    printLL();
}