#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    int exp;
    struct node *link;
}*first,*second,*prod,*heads=NULL,*upd;

struct node* createnode();
void traverse(struct node *ptr);
struct node* polyprod(struct node *pol1,struct node *pol2);
struct node* insert(int,int);
struct node* update();
void main(){
    printf("Create polynomial 1:\n");
    first=createnode();
    //traverse(first);
    printf("Create polynomial 2:\n");
    second=createnode();
    //traverse(second);
    prod=polyprod(first,second);
    printf("Product is \n");
    traverse(prod);
    upd=update();
    printf("Product is \n");
    traverse(upd);
}

void traverse(struct node *ptr){
    while (ptr!=NULL){
        printf("%dx^%d",ptr->coef,ptr->exp);
        if(ptr->link!=NULL){
            printf("+");
        }ptr=ptr->link;
    }
}

struct node* createnode(){
    struct node *temp=NULL,*head=NULL,*ptr=NULL;
    int key,choice;
    do{
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter terms: ");
        printf("\nEnter coefficient: ");
        scanf("%d",&(temp->coef));
        printf("Enter exponent: ");
        scanf("%d",&(temp->exp));
        temp->link=NULL;
        key=temp->exp;

        if(head==NULL || head->exp <key){
            temp->link=head;
            head=temp;
        }else {
            ptr=head;
            while(ptr->link!=NULL && ptr->link->exp > key){
                ptr=ptr->link;
            }temp->link=ptr->link;
            ptr->link=temp;
        }printf("\n1 to continue\n0 to stop\n");
        scanf("%d",&choice);
    }while(choice==1);
    return head;
}

struct node* polyprod(struct node *pol1,struct node *pol2){
    
    int rco,rex;
    while(pol1!=NULL){
        pol2=second;
        while(pol2!=NULL){
            rco=pol1->coef*pol2->coef;
            rex=pol1->exp+pol2->exp;
            insert(rco,rex);
            pol2=pol2->link;
        }pol1=pol1->link;
    }return heads;
}

struct node* insert(int coeff,int expo){
    struct node *temp,*ptr=NULL;
    
    int key;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coef=coeff;
    temp->exp=expo;
    temp->link=NULL;
    key=temp->exp;

    if(heads==NULL || heads->exp<key){
        temp->link=heads;
        heads=temp;
    }else{
        ptr=heads;
        while(ptr->link!=NULL && ptr->link->exp>=key){
            ptr=ptr->link;
        }temp->link=ptr->link;
        ptr->link=temp;
    }return heads;
}

struct node* update(){
    struct node *ptr=prod,*temp=NULL;
    while(ptr->link!=NULL){
        if(ptr->exp==ptr->link->exp){
            ptr->coef=ptr->coef+ptr->link->coef;
            temp=ptr->link;
            ptr->link=ptr->link->link;
            free(temp);temp=NULL;
        }else{
            ptr=ptr->link;
        }
    }return prod;
}