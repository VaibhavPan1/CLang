#include<stdio.h>
#include<stdlib.h>

//code for a node
struct node{ 
    int data;
    struct node *next;
};

struct node *start = NULL; //if no node is created then set start/head = null;

//function to create a linked list
struct node *create_ll(struct node *start){
    struct node *new_node, *ptr, *current,*previous;
    int num;
    printf("Enter -1 to stop the process\n");
    printf("Enter the number: ");
    scanf("%d",&num);
    while(num!=-1){
        new_node = (struct node*)malloc(sizeof(struct node));
        current = new_node;
        current->data = num;
        current->next = NULL;
        if (start == NULL){
            current->next=NULL;
            start = new_node;
            previous = start;
        }
        else{
            ptr = previous;
            ptr->next=current;
            previous = current;
        }
        printf("Enter the number: ");
        scanf("%d",&num);

    }
    return start;
}

//function to display the list
struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    if (ptr == NULL){
        printf("No list created..\n");
    }
    else{
        printf("Linked List is:\n");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *ptr, *head,*new_node;
    int num;
    if(start==NULL){
        printf("Linked List doesn't exist..\n");
    }
    else{
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter the number: ");
        scanf("%d",&num);
        new_node->data=num;
        new_node->next=start;
        start=new_node;
        printf("Added sucessfully..\n");
    }
    return start;
}

struct node *insert_end(struct node *start){
    struct node *ptr,*new_node;
    int num;
    ptr = start;
    if(start==NULL){
        printf("Linked List doesn't exist..\n");
    }
    else{
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter the number: ");
        scanf("%d",&num);
        new_node->data=num;
        new_node->next=NULL;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new_node;
        printf("Element added sucessfully...\n");
    }
    return start;
}

struct node *del_first(struct node *start){
    struct node *ptr;
    if(start==NULL){
        printf("Linked List doesn't exist..\n");
    }
    else{
        ptr = start;
        start=start->next;
        free(ptr);
        printf("Deletion sucessful..\n");
    }
    return start;
}
struct node *del_last(struct node *start){
    struct node *ptr, *previous;
    ptr = start;
    if(start==NULL){
        printf("Linked List doesn't exist..\n");
    }
    else{
        while(ptr->next!=NULL){
            previous=ptr;
            ptr=ptr->next;
        }
        previous->next=NULL;
        printf("Deletion sucessful..\n");
        free(ptr);
    }
    return start;
}
int main(){
    int opt;
    do {
        printf("\n****MAIN MENU****\n");
        printf("1. Create Linked List\n2. Display\n3. Insert Beginning\n4. Insert End\n5. Delete First\n6. Delete last\n7. Exit\n");
        scanf("%d",&opt);
        switch (opt){
            case 1: start = create_ll(start);
                    printf("Linked List created...\n");
                    break;
            case 2: start = display(start);
                    break;
            case 3: start = insert_beg(start);
                    break;
            case 4: start = insert_end(start);
                    break;
            case 5: start = del_first(start);
                    break;
            case 6: start = del_last(start);
                    break;
            case 7: printf("Exiting Program...\n");
                    exit(0);
            default: printf("Please select valid option!\n");
                    break;
        }
    }while(opt!=7);
    return 0;
}