// program to implement queue using stack
#include<stdio.h>
#include<stdlib.h>
int arr[10];
int front =-1;
int  rear = -1;
void enqueue(int n){
    if(rear == n-1) printf("Queue is full\n");
    else{
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        rear++;
        arr[rear] = data;
        printf("Successfully added to rear\n");
    }
}

void dequeue(){
    if(front == rear) printf("Queue is empty\n");
    else{
        front++;
        if(front == rear) front = rear = -1;
        printf("Successfully deleted from front\n");
    }
}

void display(){
    int i;
    if(front == rear) printf("Queue is empty\n");
    else{
        for (i = front+1; i<=rear; i++)
            printf("%d\t", *(arr+i));
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