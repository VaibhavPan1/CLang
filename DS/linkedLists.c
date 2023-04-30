/* implemention of basic linked list without loops */

#include<stdio.h>
#include<stdlib.h>

//code for node:
struct node{
    int data;
    struct node* next;
};

struct node *head = NULL;

void main(){
    struct node *var,*var2,*ptr; //pointers of type struct node(holding size of node and members of node)
    
    //pointer of type _type_ will only contain the address of type _type_ (manually creating two nodes)
    var = (struct node*)malloc(sizeof(struct node*));   //a node initialization returning address with type struct node (this is the first node)
    var2 = (struct node*)malloc(sizeof(struct node*)); //another node initialization returning address with type struct node (this if second node)
   
    head = var;  // head will always contain the addess of first node
    ptr = head; //another pointer ptr will be used for operations in list like traversing and searching
    
    //inserting values in nodes
    var->data=5;
    var->next=var2;
    var2->data= 10;
    var2->next = NULL;

    

    // printf("%d",var->data);
    // printf("%d",var2->data);
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr = ptr -> next;

    }
}
