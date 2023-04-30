//program for stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}NODE;

NODE *head;

void push(){
    NODE *ptr;
    ptr = (NODE * )malloc(sizeof(NODE));
    printf("Enter the value: ");
    ptr->next = NULL;
    scanf("%d",&ptr->val);
    if(head == NULL){
        head = ptr;
    }
    else{
        ptr->next = head;
        head = ptr;
    }
    printf("Successfully added %d to the top of stack\n",head->val);
}

void pop(){
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    if(head == NULL){
        printf("Stack underflow!\n");
    }
    else{
        ptr = head;
        head = head->next;
        printf("Poped node %d\n",ptr->val);
        free(ptr);
    }
}

void peep(){
    if(head == NULL ) printf("Stack underflow!\n");
    else printf("\nTop of stack is %d\n", head->val);
}

void main(){
    int opt;
    while(1){
        printf("1. PUSH\n2. POP\n3. PEEP\n4. EXIT\n");
        printf("Please select any option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1: push();
                    break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: exit(0);
            default: printf("Please select valid option\n");
        }
    }
}

