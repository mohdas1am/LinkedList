#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    struct node *link;
}*first,*second,*sum,*heads=NULL;

struct node* createnode();
void traverse(struct node *ptr);
struct node* insbtw(struct node *pol1,struct node *pol2);
//struct node* insert(int,int);
void main(){
    printf("Create polynomial 1:\n");
    first=createnode();
    //traverse(first);
    printf("Create polynomial 2:\n");
    second=createnode();
    //traverse(second);
    traverse(insbtw(first,second));

}

struct node* createnode(){
    struct node *temp=NULL,*head=NULL,*ptr=NULL;
    int key,choice;
    do{
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter terms: ");
        printf("\nEnter coefficient: ");
        scanf("%d",&(temp->coef));
        temp->link=NULL;

        if(head==NULL){
            head=temp;
        }else {
            ptr=head;
            while(ptr->link!=NULL){
                ptr=ptr->link;
            }
            ptr->link=temp;
        }printf("\n1 to continue\n0 to stop\n");
        scanf("%d",&choice);
    }while(choice==1);
    return head;
}

struct node* insbtw(struct node *pol1,struct node *pol2){
    struct node* ptr1=pol1;
    struct node* ptr2=pol2;
    struct node *rptr1,*rptr2;
    while(ptr1!=NULL && ptr2!=NULL){
            rptr1=ptr1;
            rptr2=ptr2;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
            rptr1->link=rptr2;
            rptr2->link=ptr1;       
    }ptr1=pol1;
    while(ptr1->link!=NULL)
    ptr1=ptr1->link;
    ptr1->link=ptr2;

    return pol1;
}

void traverse(struct node *ptr){
    while(ptr!=NULL){
        printf("\n______________________________\n");
        printf("%d",ptr->coef);
        ptr=ptr->link;
    }
}
