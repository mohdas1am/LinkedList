#include <stdio.h>
#include <stdlib.h>


struct nodes{
    int data;
    struct nodes *link;
}*travel,*final;

struct nodes* createnode(int p);
void traverse (struct nodes *ptr);
struct nodes* reversenode();

void main(){
    int n;
    printf("Enter number of nodes; ");
    scanf("%d",&n);

    travel=createnode(n);

    printf("\n___________________________\n");
    printf("List after creating nodes: \n");
    traverse(travel);
    printf("List after reversing nodes: \n");
    final=reversenode();
    traverse(final);
}


struct nodes *createnode(int p){
    int i;
    struct nodes *head=NULL,*temp=NULL,*ptr=NULL;
    for(i=1;i<=p;i++){
        temp=(struct nodes*)malloc(sizeof(struct nodes));
        printf("Enter data for node %d\n",i+1);
        scanf("%d",&(temp->data));
        temp->link=NULL;

        if(head==NULL){
            head=temp;
        }else{
            ptr=head;
            while(ptr->link!=NULL){
            ptr=ptr->link;
            }
            ptr->link=temp;
        }
    }return head;
}


void traverse(struct nodes *ptr){
    int count=0;
    while(ptr!=NULL){
        count++;
        printf("\n______________________________________________________\n");
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }printf("Number of nodes are %d",count);
}


struct nodes* reversenode(){
    struct nodes *prev,*p1,*p2;
    p1=p2=travel;
    prev=NULL;
    while(p1!=NULL){
        p1=p1->link;
        p2->link=prev;
        prev=p2;
        p2=p1;

    }
    travel=prev;
    
    
    return travel;
    
}

