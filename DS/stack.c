#include<stdio.h>
int stack[50],top=0,val,size,i,j;
void push();
void pop();
void peep();
void show();
void main(){
    int choice;


    printf("Enter the size of stack(max 50): ");
    scanf("%d",&size);

    

    while(choice != 5){
        printf("Enter the choice: \n");
        printf("1. PUSH\n2. POP\n3. PEEP\n4. SHOW STACK\n5. EXIT");
        scanf("%d",&choice);

        switch (choice)
        {
        case 5:{
            printf("Exiting...\n");
            break;
        }
        case 1:{
            push();
            break;
        }
        case 2:{
            pop();
            break;
        }
        case 3:{
            peep();
            break;
        }
        case 4:{
            show();
            break;
        }

        
        default:
            printf("choose valid option..!\n");
        }

    }
}

void push (){     
    if (top == size )   
        printf("\n Overflow\n");   
    else   
    {  
        printf("Enter the value: \n");  
        scanf("%d",&val);            
        stack[top] = val;
        top++;   
    }  
}

void pop(){
    if (top==0){
        printf("\n Underflow\n");
    }
    else{
        top--;
    }

}

void show(){
    if(top == 0){  
        printf("\nStack is empty\n");  
    }
    else{
        printf("\n\nStack: \n");
        for(i=0;i<top;i++){
            printf("%d  ",stack[i]);
        }
        printf("\n");
    }
}

void peep(){
    if(top == 0){  
        printf("\nStack is empty\n");  
    }
    else{
        printf("\n\nTop Element: \n");
        printf("%d \n",stack[top]);
    }
}