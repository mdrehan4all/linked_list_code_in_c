#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void display(){
    struct node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("\nNothing to print");
    }else{
        printf("\nPrinting values...\n");
        while(ptr!=NULL){
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}

void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL){  
        printf("\nEmpty List");  
    }else{   
        printf("\nEnter item which you want to search: ");   
        scanf("%d",&item);  
        while (ptr!=NULL){  
            if(ptr->data == item){  
                printf("item found at location %d ",i+1);  
                flag=0;  
            }else{  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1) {  
            printf("Item not found\n");  
        }  
    }            
}  

void insertBeg(){
    struct node *ptr;
    int item;
    ptr = (struct node*) malloc(sizeof(struct node*));
    if(ptr == NULL){
        printf("\nOverflow");
    }else{
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode Inserted");
    }
}

void insertLast(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow");
    }else{
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
            printf("\nNode inserted");
        }else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted");
        }
    }
}

void insertAnywhere(){  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc(sizeof(struct node));  
    if(ptr == NULL){  
        printf("\nOverflow");  
    }else{  
        printf("\nEnter element value: ");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location after which you want to insert: ");  
        scanf("%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++){  
            temp = temp->next;  
            if(temp == NULL){  
                printf("\ncan't insert\n");  
                return;  
            }  
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        printf("\nNode inserted");  
    }  
} 

void deleteBeg(){  
    struct node *ptr;  
    if(head == NULL){  
        printf("\nList is empty");  
    }else{  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining");  
    }  
}

void deleteLast(){  
    struct node *ptr,*ptr1;  
    if(head == NULL){  
        printf("\nlist is empty");  
    }else if(head -> next == NULL){  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted");  
    }else{  
        ptr = head;   
        while(ptr->next != NULL){  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last");  
    }     
}  

void deleteAnywhere(){  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\nEnter the location of the node after which you want to perform deletion: ");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++){  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL){  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  

int main(){
    int select = 1;
    while(select){
        printf("\n\n0 to exit");
        printf("\n1 to insert at beginning");
        printf("\n2 to insert at end");
        printf("\n3 to insert at any location");
        printf("\n4 to delete from begninning");
        printf("\n5 to delete from end");
        printf("\n6 to delete from any location");
        printf("\n7 to display all nodes");
        printf("\n8 to search");
        printf("\nEnter option: ");
        scanf("%d", &select);
        if(select == 1){
            insertBeg();
        }else if(select == 2){
            insertLast(); 
        }else if(select == 3){
            insertAnywhere();
        }else if(select == 4){
            deleteBeg();
        }else if(select == 5){
            deleteLast();
        }else if(select == 6){
            deleteAnywhere();
        }else if(select == 7){
            display();
        }else if(select == 8){
            search();
        }
    }
    return 0;
}