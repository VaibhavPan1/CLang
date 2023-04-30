// program to implement queue using linkedlist
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}NODE;

NODE *front, *rear;

void enqueue(){
    NODE *ptr;
    ptr = (NODE * )malloc(sizeof(NODE));
    ptr->next = NULL;
    printf("Enter the data: ");
    scanf("%d", &ptr->val);
    if(rear == NULL){
        front = rear = ptr;
    }
    else{
        rear->next = ptr;
        rear = ptr;
    }
    printf("Successfully added to rear\n");
}

void dequeue(){
    NODE *ptr;
    if(front == rear) printf("Queue is empty\n");
    else{
        ptr = front;
        front = front->next;
        free(ptr);
        printf("Successfully deleted form front\n");
    }
}

void display(){
    NODE *ptr;
    if(front == rear) printf("Queue is empty\n");
    else{
        ptr = front;
         while(ptr->next!=NULL){
            printf("%d\t", ptr->val);
            ptr = ptr->next;
         }
         printf("\n");
    }
}

void main(){
    int opt, size;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Select option: ");
        scanf("%d", &opt);
        switch(opt){
            case 1: enqueue(size); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(1); break;
            default: printf("Select valid option\n");
        }
    }
}