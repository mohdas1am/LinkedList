#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*travel,*head=NULL,*tail=NULL,*temp=NULL;

void create();
void traverse(struct node *ptr);
void traverse2(struct node *ptr);
struct node* insertfirst();
struct node* insert();
struct node* lastinsert();
struct node* lastdelete();
struct node* deletefirst();
struct node* deletebet();

void main(){
    int choose;
    create();
    travel=head;
    
    do{
        printf("Choose\n1 for insert at first\n2 for insert at last\n3 to insert in between\n4 to delete last node\n5 to delete first node\n6to delete between nodes\n7 to travel back\n");
        scanf("%d",&choose);
        switch(choose){
        case 1:
            printf("List after inserting node at first is\n");
            traverse(insertfirst());
            break;
        case 2:
            printf("List after inserting node at last is\n");
            traverse(lastinsert());
            break;
        case 3:
            printf("List after inserting node at between is\n");
            traverse(insert());
            break;
        case 4:
            printf("List after delete node at last is\n");
            traverse(lastdelete());
            break;
        case 5:
            printf("List after delete node at first is\n");
            traverse(deletefirst());
            break;
        case 6:
            printf("List after delete node between is\n");
            traverse(deletebet());
            break;
        case 7:
            printf("Traversing from back\n");
            traverse2(tail);
            break;
    }printf("\n 1 to continue");
    scanf("%d",&choose);
    }  while(choose==1);
}

void traverse(struct node *ptr){
    while(ptr!=NULL){
        printf("\n_________________\n");
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void traverse2(struct node *ptr){
    while(ptr!=NULL){
        printf("\n_________________\n");
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }
}

void create(){ 
    int ch,key;
    do{
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&(temp->data));
        key=temp->data;
        temp->prev=NULL;
        temp->next=NULL;
        if(head==NULL){
            head=tail=temp;
        }else{
            tail->next=temp;
            temp->prev=tail;   
            tail=temp;
        }printf("\n 1 to continue\n");
        scanf("%d",&ch);
    }while(ch==1);
}

struct node* insertfirst(){
    struct node *ptr=travel,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted: ");
    scanf("%d",&(temp->data));
    temp->prev=NULL;
    temp->next=ptr;
    ptr->prev=temp;
    travel=temp;
    return travel;
}

struct node* insert(){
    struct node *ptr=travel,*temp;
    int ch,i=1;
    printf("Enter position to insert: ");
    scanf("%d",&ch);
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted: ");
    scanf("%d",&(temp->data));
    
        while(i<ch-1){
            ptr=ptr->next;
            i++;
        }temp->prev=ptr;
        temp->next=ptr->next;
        ptr->next->prev=temp;
        ptr->next=temp;
        
    return travel;
}

struct node* lastinsert(){
        struct node *ptr=travel,*temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data to be inserted: ");
        scanf("%d",&(temp->data));
        temp->next=NULL;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }temp->prev=ptr;
        ptr->next=temp;
        tail=temp;
    return travel;
}
struct node* lastdelete(){
    struct node *ptr=travel,*ptr1;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }ptr1=ptr;
    ptr->prev->next=NULL;
    free(ptr1);
    return travel;
}

struct node* deletefirst(){
    struct node *ptr=travel;
    travel=travel->next;
    travel->prev=NULL;
    free(ptr);
    return travel;
}
struct node* deletebet(){
    struct node *ptr=travel;
    int ch,i=1;
    printf("Enter position to delete: ");
    scanf("%d",&ch);
    while(i<ch){
        ptr=ptr->next;
        i++;
    }
    ptr->next->prev=ptr->prev;
    if(ptr->next!=NULL)
    ptr->prev->next=ptr->next;
    else
    printf("Invalid position");
    free(ptr);
    return travel;
    
}