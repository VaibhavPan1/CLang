#include<stdio.h>
#include<stdlib.h>

typedef struct node{ //neither singly nor doubly, it is special singly
    int data;
    struct node *left, *right;
}TREE;

TREE *root;

void create_tree(){
    TREE *new_node;
    int data, size, height;
    printf("Enter the height of tree: ");
    scanf("%d",&data);
    new_node = (TREE *)malloc(sizeof(TREE));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    if(root == NULL){
        root = new_node;
    }
    else{
        
    }
}