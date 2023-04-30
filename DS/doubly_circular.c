#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *previous;
    int data;
    struct node *next;
}NODE;

NODE *head;

void print_list(){
    NODE *ptr=head;
    int flag = 0;
    while(flag == 0){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
        if(ptr == head) flag = 1;
    }
    printf("\n");
}

//function to create initial doubly circular linked list
void create_ll(){
    NODE *ptr=head,*new_node,*preptr, *current;
    int data,size;
    printf("Enter the size of list: ");
    scanf("%d",&size);
    for (int i=0;i<size;i++){
        new_node = (NODE *)malloc(sizeof(NODE));
        new_node->next = new_node; //should point to itself when only one node
        new_node->previous = new_node; 
        if(new_node == NULL){
            printf("Memory allocation unsuccessfull..\n");
        }
        else{
            current = new_node;
            printf("Enter the data: ");
            scanf("%d",&data);
            current->data = data;
            if(head==NULL){
                head = new_node;
                preptr = new_node;
            }
            else{
                new_node->data = data;
                ptr = preptr;
                ptr->next = new_node;
                new_node->next = head;
                head->previous = new_node;
                new_node->previous = ptr;
                preptr = current;

            }

        }
    }
}

//all the insertion cases with value checking
void insert_beg(){
    NODE *ptr=head,*new_node;
    int data;
    if (head == NULL){
        printf("No list created, please create one..\n");
    }
    else{
        new_node = (NODE *)malloc(sizeof(NODE));
        if(new_node == NULL){
            printf("Memory Allocation unsuccess\n");
        }
        else{
            printf("Enter the data at begining: ");
            scanf("%d",&data);
            new_node->data = data;
            new_node->next = head;
            while(ptr->next!=head){
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->previous = ptr;
            head = new_node;
            printf("Successfully added node at begin with value %d\n",data);
        }
    }
    
}

void insert_end(){
    NODE *ptr = head,*new_node;
    int data;
    if(head == NULL){
        printf("No list exist, please create one..\n");
    }
    else{
        new_node = (NODE *)malloc(sizeof(NODE));
        if(new_node==NULL){
            printf("Memory allocation unsucessful..\n");
        }
        else{
            new_node->next = head;
            printf("Enter the data at end: ");
            scanf("%d",&data);
            new_node->data = data;
            while(ptr->next!=head){
                ptr = ptr->next;
            }
            ptr->next = new_node;
            head->previous = new_node;
            new_node->previous = ptr;
            printf("Successfully added node at end with value %d\n",data);
        }
    }
}


void insert_before(){ //add condition for inserting before head 
    NODE *ptr=head,*new_node,*preptr;
    int data,before,flag=0;
    if(head == NULL){
        printf("No list exist, please create one..\n");
    }
    else{
        new_node = (NODE *)malloc(sizeof(NODE));
        if(new_node == NULL){
            printf("Memory allocation unsuccessfull..\n");
        }
        else{
            printf("Insert Before? ");
            scanf("%d",&before);
            printf("Enter the data: ");
            scanf("%d",&data);
            new_node->data = data;
            while(ptr->data!=before && ptr->next!=head){
                preptr = ptr;
                ptr = ptr -> next;
            }
            if(ptr->data==before){
                preptr->next = new_node;
                new_node->previous = preptr;
                new_node->next = ptr;
                ptr->previous = new_node;
                printf("Successfully added node before %d with value %d\n",before,data);
                flag =1;
            }
            if(flag == 0) printf("Node with value %d not found\n",before);

            
        }
    }
}

void insert_after(){
    NODE *ptr=head,*new_node,*preptr;
    int data,after,flag=0;
    if(head==NULL){
        printf("No list exist..\n");
    }
    else{
        new_node = (NODE *)malloc(sizeof(NODE));
        if(new_node == NULL){
            printf("Memory allocation unsuccessfull..\n");
        }
        else{
            printf("Insert After? ");
            scanf("%d",&after);
            printf("Enter the data: ");
            scanf("%d",&data);
            new_node->data = data;
            while(ptr->data!=after && ptr->next != head){
                ptr = ptr->next;
            }
            if(ptr->data==after){
                new_node->previous = ptr;
                new_node->next = ptr->next;
                ptr->next->previous = new_node;
                ptr->next = new_node;
                printf("Successfully added node after %d with value %d\n",after,data);
                flag = 1;
            }
            if(flag==0) printf("Node with value %d not found!\n",after);
            
        }
        
    }
}


//all deletion cases
void del_begin(){
    NODE *ptr=head,*temp=head;
    if(head == NULL){
        printf("No list exist, please create one..\n");
    }
    else{
        while(ptr->next != head){
            ptr = ptr -> next;
        }
        head = temp->next;
        head->previous = ptr;
        ptr->next = head;
        free(temp);   
        printf("Successfully deleted first node..\n");
    }
}

void del_end(){
    NODE *ptr,*preptr;
    if(head == NULL){
        printf("No list exist, please create one..\n");
    }
    else{
        while(ptr->next!=head){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = head;
        head->previous = preptr;
        free(ptr);
        printf("Successfully deleted last node..\n");

    }
}

void del_before(){
    NODE *ptr=head,*preptr;
    int before,flag=0;
    if(head == NULL){
        printf("No list exist..\n");
    }
    else{
        printf("Delete before? ");
        scanf("%d",&before);
        if(head->data == before){
            printf("Cannot delete node before head..\n");
            flag = 1;
        }
        else{
          while(ptr->data != before && ptr->next != head){
                preptr = ptr;
                ptr = ptr->next;
            }
            if(ptr->data == before){
                preptr->previous->next = ptr;
                ptr->previous = preptr->previous;
                free(preptr);
                printf("Successfully deleted node before %d \n",before);
                flag = 1;
            }  
        }
        
        if(flag == 0) printf("Node with value %d not found\n",before);
    }
}

void del_after(){
    NODE *ptr=head,*temp;
    int after,flag=0; //flag to check if node exist, flag will be zero only when value does not exist, 1 otherwise. Flag = 1 means value exist 
    if(head == NULL){
        printf("No list exist..\n");
    }
    else{
        printf("Delete after? ");
        scanf("%d",&after);
        while(ptr->data!= after && ptr->next != head){
            ptr = ptr->next;
        }
        if(ptr->data== after && ptr->next != head ){ //to check if the node is not the last node
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->previous = ptr;
            free(temp);
            printf("Successfully deleted node after %d\n",after);
            flag = 1;
        }
        else{
            printf("Cannot delete node after last node\n"); //if node is last node then its next is head which we cannot delete
            flag = 1;
        } 
        if(flag == 0) printf("Node with value %d not found\n",after); //execute when node does not exist
    }
}

void del_spe(){
    NODE *ptr=head;
    int key,flag=0;
    if(head== NULL){
        printf("No list created..\n");
    }
    else{
        printf("Enter the node to be deleted: ");
        scanf("%d",&key);
        if(head->data == key){
            //del_begin(); but it must have a return 
            ptr->previous->next = ptr->next;
            ptr->next->previous = ptr->previous;
            head = ptr ->next;
            free(ptr); 
            flag = 1;
            printf("First node deleted successfully..\n");
        }
        else{
            while(ptr->data!=key && ptr->next!=head){
                ptr = ptr->next;
            }
            if(ptr->data==key){
                ptr->previous->next = ptr->next;
                ptr->next->previous = ptr->previous;
                free(ptr);
                printf("Node with value %d deleted successfully..\n",key);
                flag = 1;    
            } 
        }              
    }
    if(flag==0) printf("Node with value %d not found..\n",key);
}

//swap function 
void swap(NODE *ptr1, NODE *ptr2){
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp; 
}

//bubble sort function
void sort_list(){
    NODE *ptr = head,*temp;
    if (head == NULL){
        printf("No list exist, please created one..\n");
    }
    else{
        if(head->next == head){
            printf("Sorted list is: \n");
            print_list();
        }
        else{
            while(ptr->next!=head){
                temp = head;
                while(temp->next!=head){
                    if(temp->data > temp->next->data){
                        swap(temp,temp->next);
                    }
                    temp = temp->next;
                }
                ptr = ptr->next;
            }
        }
        printf("List sorted successfully..\n");
    }
}

/* 
void b_search(){
    int key,flag=0,mid,lb,ub;
    if(head == NULL){
        printf("No list exist, please create one...\n");
    }
    else{
        sort_list();
        printf("Enter the element to be searched: ");
        scanf("%d",&key);

    }
}
 */

void main(){
    int option;
    printf("Select 1 to create Circular Doubly List or 0 to exit: ");
    scanf("%d",&option);
    if(option==1){
        create_ll();   
    }
    else if(option==0){
        exit(1);
    }
    else{
        printf("Please select valid option.\n");
        exit(0);
    }
    do{
        printf("*******MENU********\n");
        printf("1. Exit\n2. Insert beginning\n3. Insert End\n4. Insert Before\n5. Insert After\n6. Delete First\n7. Delete Last\n8. Delete Specific\n9. Delete Before\n10. Delete After\n11. Sort List\n12. Print List\n");
        scanf("%d",&option);
        switch(option){
            case 1: printf("EXITING...\n"); exit(0); break;
            case 2: insert_beg(); break;
            case 3: insert_end(); break;
            case 4: insert_before(); break;
            case 5: insert_after(); break;            
            case 6: del_begin(); break;
            case 7: del_end(); break;
            case 8: del_spe(); break;
            case 9: del_before(); break;
            case 10: del_after(); break;
            case 11: sort_list(); break;
            case 12: print_list(); break;            
            default: printf("Please select Valid Option..!\n"); break;
        }
    }while(1);
}