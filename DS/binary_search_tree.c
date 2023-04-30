#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree*  left,*right;
}TREE;

TREE *root;

void create_tree(){
    TREE *new_node,*ptr,*preptr;
    int data,size;
    printf("\nEnter the Total no of elements: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        new_node = (TREE *)malloc(sizeof(TREE));
        new_node->left = NULL;
        new_node->right = NULL;
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
            if(data < preptr->data) preptr->left = new_node;
            else preptr->right = new_node;
        }
    }
    printf("\nSuccessfully created Binary Search Tree\n");
}

void insert(){
    TREE *new_node,*ptr = root,*preptr;
    int data;
    if(root == NULL){
        printf("\nNo Tree exist..");
    }
    else{
        new_node = (TREE *)malloc(sizeof(TREE));
        new_node->left = NULL;
        new_node->right = NULL;
        printf("\nEnter the data: ");
        scanf("%d",&data);
        new_node->data = data;
        while(ptr!=NULL){ 
            preptr = ptr;
            if(data < ptr->data) ptr = ptr->left;
            else if (data > ptr->data) ptr = ptr->right;
            else {printf("\nDublicate value!");return;}
        }
        if(data < preptr->data) preptr->left = new_node;
        else preptr->right = new_node;
        printf("\nSuccessfully added node with value %d",data);
    }
}

void search(){
    TREE *ptr=root;
    int key,flag=0;
    if(root == NULL){
        printf("\nNo Tree in existence");
    }
    else{
        printf("\nEnter the search element: ");
        scanf("%d",&key);
        while(ptr!=NULL){
            if(ptr->data == key){
                printf("\nElement Found");
                flag = 1; break;
            }
            else if(key < ptr->data) ptr = ptr->right;
            else ptr = ptr->left;
        }
        if(flag == 0) printf("\nElement not found");
    }
}

void delete(){

}

void pre_order(TREE *root){
    if(root != NULL){
        printf("%d\t",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}



void in_order(TREE *root){
    if(root !=NULL){
        in_order(root->left);
        printf("%d\t",root->data);
        in_order(root->right);
    }
}

/* 

void in_order(){
    

}

 */

void post_order(TREE *root){
    if(root !=NULL){
        in_order(root->left);
        in_order(root->right);
        printf("%d\t",root->data);
    }
}

void main(){
    int opt,option;

    do{
        printf("\nSelect 1 to create a Binary Search Tree or select 0 to exit: ");
        scanf("%d",&opt);
        if(opt == 0){
            exit(0);
        }
        else if(opt == 1){
            create_tree();
            break;
        }
        printf("\nSelect valid option");
    }while(1);

    do{
        printf("\n***************");
        printf("\n0. Exit\n1. Pre-Order Traversal\n2. In-Order Traversal\n3. Post-Order Traversal\n4. Insert Element\n5. Search \n");
        scanf("%d",&option);
        switch(option){
            case 0: exit(0);
            case 1: pre_order(root); break;
            case 2: in_order(root); break;
            case 3: post_order(root); break;
            case 4: insert(); break;
            case 5: search();
        }
    }while(1);
    
    
}