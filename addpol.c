#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    int exp;
    struct node *link;
}*first,*second,*sum,*heads=NULL;

struct node* createnode();
void traverse(struct node *ptr);
struct node* polyadd(struct node *pol1,struct node *pol2);
struct node* insert(int,int);
void main(){
    printf("Create polynomial 1:\n");
    first=createnode();
    //traverse(first);
    printf("Create polynomial 2:\n");
    second=createnode();
    //traverse(second);
    sum=polyadd(first,second);
    printf("Sum is \n");
    traverse(sum);

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

void traverse(struct node *ptr){
    while (ptr!=NULL){
        printf("%dx^%d",ptr->coef,ptr->exp);
        if(ptr->link!=NULL){
            printf("+");
        }ptr=ptr->link;
    }
}

struct node* polyadd(struct node *pol1,struct node *pol2){
    
    
    while(pol1!=NULL && pol2!=NULL){
        
        if(pol1->exp==pol2->exp){
            
            heads=insert(pol1->coef+pol2->coef,pol1->exp);
            pol1=pol1->link;
            pol2=pol2->link;
        }else if(pol1->exp > pol2->exp){
            
            heads=insert(pol1->coef,pol1->exp);
            pol1=pol1->link;
        }else if(pol1->exp < pol2->exp){
            
            heads=insert(pol2->coef,pol2->exp);
            pol2=pol2->link;
        }     
    }while(pol1!=NULL){
        heads=insert(pol1->coef,pol1->exp);
        pol1=pol1->link;
    }while(pol2!=NULL){
        heads=insert(pol2->coef,pol2->exp);
        pol2=pol2->link;
    }
    return heads;
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