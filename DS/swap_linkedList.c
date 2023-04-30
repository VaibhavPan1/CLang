#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}N;

N *head;

void create_ll(){
    N *new_node, *ptr, *previous,*current;
    int data;
    for (int i =0;i<5;i++){
        new_node = (N*)malloc(sizeof(N));
        new_node->next=NULL;
        current = new_node;
        printf("Enter the data: ");
        scanf("%d",&data);
        if(head == NULL){
            new_node->data = data;
            head = new_node;
            previous = head;
        }
        else{
            previous->next = current;
            current->data = data;
            previous = current;
        }
    }
}

void swap(N *ptr1, N* ptr2){
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp; 
}

void sort(){
    swap(head->next,head->next->next);
}

void print_list(){
    N *ptr = head;
    while (ptr!=NULL)
    {
        printf("%d\t",(ptr->data));
        ptr = ptr->next;
    }
    printf("\n");
    
}

void main(){
    if (head==NULL) printf("true");
    create_ll();
    print_list();
    sort();
    print_list();
}