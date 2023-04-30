#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *head; //on global declerations value is initiated with null

void create_linked_list(int size){
    NODE *current, *previous, *ptr, *new_node;
    int data;
    for(int i=0;i<size;i++){
        new_node = (NODE *)malloc(sizeof(NODE));
        if(new_node == NULL){
            printf("Memory allocation unsucessfull\n");
        }
        else{
            current = new_node;
            printf("Enter the number: ");
            scanf("%d",&data);
            current->data = data;
            current -> next = NULL;
            if(head == NULL){
                head  = new_node;
                previous = current;
            }
            else{
                previous->next = current;
                previous = current;
            }
        }
    }
}

void insert_begin(){
    NODE *ptr=head, *new_node;
    int data;
    
        new_node = (NODE *)malloc(sizeof(NODE));
        new_node->next = head;
        printf("Enter the data at begin: ");
        scanf("%d",&data);
        new_node->data = data;
        head = new_node;
    
}

void insert_end(){
    NODE *ptr=head, *new_node;
    int data;
    if(ptr == NULL){
        printf("No list created!\n");
    }
    else{
        new_node = (NODE *)malloc(sizeof(NODE));
        new_node->next = NULL;
        printf("Enter the data at end: ");
        scanf("%d",&data);
        new_node->data = data;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next = new_node;
    }
}

void insert_before(){
    int before,data;
    NODE *new_node, *ptr=head, *previous;
    if(head==NULL){
        printf("No list created!\n");
    }
    else{
        printf("Insert Before: ");
        scanf("%d",&before);
        printf("Insert data: ");
        scanf("%d",&data);
        while(ptr->data!=before){
            previous = ptr;
            ptr=ptr->next;
        }
        new_node = (NODE *)malloc(sizeof(NODE));
        new_node->data = data;
        new_node->next=ptr;
        previous->next=new_node;
    }
}

void insert_after(){
    int after,data;
    NODE *new_node, *ptr=head, *previous;
    if(head==NULL){
        printf("No list created!\n");
    }
    else{
        printf("Insert After: ");
        scanf("%d",&after);
        printf("Insert data: ");
        scanf("%d",&data);
        while(ptr->data!=after){
            // previous = ptr;
            ptr=ptr->next;
        }
        new_node = (NODE *)malloc(sizeof(NODE));
        new_node->data = data;
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
}

void del_first(){
    NODE *ptr;
    ptr = head;
   
    if(head==NULL){
        printf("No list exist..!\n");
    }
    else{
         head = ptr->next;
        free(ptr);
        printf("Deleted first node successfully...\n");
    }
}

void del_last(){
    NODE *ptr,*preptr;
    ptr = head;
   
    if(head==NULL){
        printf("No list exist..!\n");
    }
    else if(ptr->next == NULL){
        free(ptr);
        head = NULL;
        printf("Deleted the node..\n");
    }
    else{
        while(ptr->next!=NULL){
            preptr = ptr;
            ptr=ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
        printf("Deleted Last node successfully...\n");
    }
}

void del_after(){
    NODE *ptr=head,*temp;
    int flag = 0,after;
    if(head == NULL){
        printf("No list in existence..!\n");
    }
    else if(ptr->next == NULL){
        printf("Only one node exist..\n");
    }
    else{
        printf("Delete after which node? ");
        scanf("%d",&after);
        while(ptr->data != after && ptr->next!=NULL){
            ptr = ptr->next;
        }
        if(ptr->data == after && ptr->next!=NULL){ // if the node is not the last node
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            printf("Deleted node after %d\n",after);
            flag = 1;
        }
        else if (ptr->data == after && ptr->next == NULL){ //if the node is last node then print error
            printf("No node after %d node..\n",after);
        }
        if(flag == 0)   printf("Node with value %d does not exist..\n",after);
        
    }
}

void del_before(){
    NODE *ptr=head,*temp,*preptr;
    int flag = 0,before;
    if(head == NULL){
        printf("No list in existence..!\n");
    }
    else if(ptr->next == NULL){
        printf("Only one node exist..\n");
    }
    else{
        printf("Delete before which node? ");
        scanf("%d",&before);
        while(ptr->next->data != before && ptr->next->next!=NULL){
            preptr = ptr;
            ptr = ptr->next;
        }
        if(ptr->next->data == before && ptr->next!=NULL){ // if the node is not the last node
            temp = ptr;
            preptr->next = ptr->next;
            free(temp);
            printf("Deleted node after %d\n",before);
            flag = 1;
        }
        else if (ptr->next->data == before && ptr->next == NULL){ //if the node is last node then print error
            printf("No node after %d node..\n",before);
        }
        if(flag == 0)   printf("Node with value %d does not exist..\n",before);
        
    }
}

void del_spe(){
    NODE *ptr=head,*temp;
    int data,flag = 0;
    if(head == NULL){
        printf("No list created..!\n");
    }
    else {
        printf("Enter  the value to be deleted: ");
        scanf("%d",&data);
        if(ptr->data == data){
            free(ptr);
            head = NULL;
            printf("Node with data %d deleted sucessfully\n",data);
        }
        else{
            while(ptr->next->data!=data && ptr->next->next != NULL){
                    ptr = ptr->next;
                
            }
            if(ptr->next->data==data){
                temp=ptr->next;
                ptr->next = temp->next;
                free(temp);
                printf("Sucessfully deleted node with value %d\n",data);  
                flag = 1;  
            }
            if (flag==0) printf("Value not found\n");
            
        }
    }
}

int mid_element(NODE *head){
    NODE *fast,*slow;
    fast = slow = head;
    while(fast!=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;

}

void print_list(){
    NODE *ptr=head;
    if (ptr == NULL){
        printf("No list created!\n");
    }
    else{
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }  
        printf("\n"); 
    }
}

void swap(NODE *ptr1, NODE *ptr2){
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp;
}

void sort_list(){
    NODE *ptr=head,*temp = head;
    if(head==NULL){
        printf("List does not exist..\n");
    }
    else if(ptr->next==NULL){
        printf("Sorted List: \n");
        print_list();
    }
    else{
        while(ptr->next!=NULL){
            temp = head;
            while(temp->next!=NULL){
                if(temp->data > temp->next->data){
                    swap(temp,temp->next);
                }
                temp = temp->next;
            }
            
            ptr=ptr->next;
        }
    }
}



void main(){
    int size,option;
    printf("Select 1 to create list 0 to exit:\n");
    scanf("%d",&option);
    if (option==1){
        
        printf("Enter the size: ");
        scanf("%d",&size);
        create_linked_list(size);
    }
    else if (option==0){
        exit(0);
    }
    else{
        printf("Please select valid option.!\n");
        exit(0);
    }
    do{
        printf("\n*****************\n");
        printf("1. Exit\n2. Insert beginning\n3. Insert End\n4. Insert Before\n5. Insert After\n6. Delete First\n7. Delete Last\n8. Delete Specific\n9. Sort List\n10. Delete After\n11. Delete Before\n12. Mid element\n13. Print List\n");
        scanf("%d",&option);
        switch(option){
            case 1: printf("EXITING...\n"); exit(0); break;
            case 2: insert_begin(); break;
            case 3: insert_end(); break;
            case 4: insert_before(); break;
            case 5: insert_after(); break;
            case 13: print_list(); break;
            case 6: del_first(); break;
            case 7: del_last(); break;
            case 8: del_spe(); break;
            case 9: sort_list(); break;
            case 10: del_after(); break;
            case 11: del_before(); break;
            case 12: printf("The mid element is %d",mid_element(head)); break;
            default: printf("Please select Valid Option..!\n"); break;

        }
    }while(1);
}