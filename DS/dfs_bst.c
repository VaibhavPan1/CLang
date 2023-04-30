#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left , *right, *prev;
}NODE;

NODE *root;

/* NODE * insert_node(int data){
    NODE *new_node, *ptr;
    int data;
/*     prinf("Enter the data: ");
    scanf("%d",&data); */
    new_node = (NODE *)malloc(sizeof(NODE));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->prev = NULL;
    new_node->data = data;
    return new_node;
} */


void create_tree(){
    NODE *new_node,*ptr,*preptr;
    int data,size;
    printf("\nEnter the Total no of elements: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        new_node = (NODE *)malloc(sizeof(NODE));
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->prev = NULL;
        printf("Enter the data: ");
        scanf("%d",&data);
        new_node->data = data;
        if(root == NULL){
            root = new_node;
        }
        else{
            ptr = root; //frontline
            while(ptr!=NULL){
                preptr=ptr; //follower, where to insert will be stored here
                if(data < ptr->data) ptr = ptr->left;
                else if(data > ptr->data) ptr = ptr->right;
                else {
                    printf("\nDublicate data!..");
                    printf("\nEnter the data: ");
                    scanf("%d",&data);
                    new_node->data = data;
                    ptr = preptr = root;
                }
            }
            if(data < preptr->data) {
                preptr->left = new_node;
                new_node->prev = preptr;
            }
            else {
                preptr->right = new_node;
                new_node->prev = preptr;
            }
        }
    }
    printf("\nSuccessfully created Binary Search Tree\n");
}


void in_order(NODE * root){
    if(root !=NULL){
        printf()
    }
}


dfs