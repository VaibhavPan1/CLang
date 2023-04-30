#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *head=NULL;

void print_list(){
    struct node *ptr;
    ptr = head;
    if (ptr == NULL){
        printf("No list created..\n");
    }
    else{
        printf("Linked List is:\n");
        while(ptr->next!=head){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\n");
}

void create_list(int size){
    NODE *ptr, *new_node, *current, *previous;
    int val;
    new_node = (NODE *)malloc(sizeof(NODE));
    current = new_node;
    if (new_node == NULL){
        printf("Memory allocation unsucessfull\n");
    }
    else{
        printf("Enter the value: ");
        scanf("%d",&val);
        new_node -> data = val;
        if(head == NULL){
            head = new_node;
            new_node -> next = head;            
            previous = current;
        }
        else{
            for (int i = 1;i<size;i++){
                new_node = (NODE*)malloc(sizeof(NODE));
                current = new_node;
                if(new_node == NULL){
                    printf("Memory allocation unsucessfull..\n");
                }
                else{
                    printf("Enter the value: ");
                    scanf("%d",&val);
                    ptr = previous;
                    new_node -> data = val;
                    new_node -> next = head;
                    ptr -> next = current;
                    previous = current;
                }
            }
        }
    }
}


void main(){
    int size;
    printf("Enter the size of list: ");
    scanf("%d",&size);
    create_list(size);
    print_list();
}