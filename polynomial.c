#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    int exp;
    struct node *link;
}*travel;

struct node* createnode();
void traverse(struct node *ptr);

void main(){
    travel=createnode();
    traverse(travel);

}

struct node* createnode(){
    struct node *temp=NULL,*head=NULL,*ptr=NULL;
    int key,choice;
    do{
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter coefficient: ");
        scanf("%d",&(temp->coef));
        printf("Enter exponent: ");
        scanf("%d",&(temp->exp));
        temp->link=NULL;
        key=temp->exp;

        if(head==NULL || head->exp <key){
            temp->link=head;
            head=temp;
        }else{
            ptr=head;
            while(ptr->link!=NULL && ptr->link->exp > key){
                ptr=ptr->link;
            }temp->link=ptr->link;
            ptr->link=temp;
        }printf("\nPress 1 to continue\n0 to break");
        scanf("%d",&choice);
    }while(choice==1);
    return head;
}

void traverse(struct node *ptr){
    while (ptr!=NULL){
        printf("%dx^%d",ptr->coef,ptr->exp);
        
        if(ptr->link!=NULL){
            printf("+");
        }ptr=ptr->link;
    }

}

