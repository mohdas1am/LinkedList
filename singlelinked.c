#include <stdio.h>
#include <stdlib.h>


struct nodes{
    int data;
    struct nodes *link;
}*travel,*final;


struct nodes* createnode(int p);
struct nodes* insertnode();
struct nodes* lastinsertnode();
struct nodes* middleinsertnode();
struct nodes *deletefirstnode();
struct nodes *lastdeletenode();
struct nodes* delete();
void traverse (struct nodes *ptr);

void main(){
    int n,ch,con;
    printf("Enter number of nodes; ");
    scanf("%d",&n);

    travel=createnode(n);

    printf("\n___________________________\n");
    printf("List after creating nodes: \n");
    traverse(travel);
    
    
    do{
        printf("Enter choice\n1 for insertion at first\n2 for insertion at last\n3 for insertion in between\n4 for deletion\n5 for deletion at last\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\n___________________________\n");
                printf("List after inserting node at first: \n");
                final=insertnode();
                traverse(final);
                break;
            case 2:
                printf("\n___________________________\n");
                printf("List after inserting node at last: \n");
                traverse(lastinsertnode());
                break;

            case 3:
                printf("\n___________________________\n");
                printf("List after inserting node in between: \n");
                traverse(middleinsertnode());
                break;

            case 4:
                printf("\n___________________________\n");
                printf("List after deleting node at first: \n");
                traverse(deletefirstnode());
                break;

            case 5:
                printf("\n___________________________\n");
                printf("List after deleting node at last: \n");
                traverse(lastdeletenode());
                break;

            case 6:
                printf("\n___________________________\n");
                printf("List after deleting node between: \n");
                traverse(delete());
                break;

            default:
                printf("Wrong input\n");
                break;
        }printf("\nEnter 9 to continue\n0 to exit\n");
        scanf("%d",&con);
    }while(con==9);
}


//creating nodes and attaching one by one

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


//displaying contents
void traverse(struct nodes *ptr){
    int count=0;
    while(ptr!=NULL){
        count++;
        printf("\n______________________________________________________\n");
        printf("%d\n",ptr->data);
        ptr=ptr->link;
}printf("Number of nodes are %d",count);
}


struct nodes *insertnode(){
    struct nodes *ptr;
    ptr=(struct nodes*)malloc(sizeof(struct nodes));

    printf("Enter data into node to be inserted: ");
    scanf("%d",&(ptr->data));
    
    ptr->link=travel;
    travel=ptr;
    return travel;
}



struct nodes *lastinsertnode(){
    struct nodes *temp,*ptr=travel;
    temp=(struct nodes*)malloc(sizeof(struct nodes));
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }printf("Enter data into node to be inserted: ");
    scanf("%d",&(temp->data));
    temp->link=NULL;
    ptr->link=temp;
    
   return travel;
}



struct nodes *middleinsertnode(){
    struct nodes *temp,*ptr=travel;
    int i=2,choice;
    printf("Enter number where node to be inserted");
    scanf("%d",&choice);

    temp=(struct nodes*)malloc(sizeof(struct nodes));
    while(i<choice){
        ptr=ptr->link;
        i++;
    }printf("Enter data into node to be inserted: ");
    scanf("%d",&(temp->data));
    temp->link=ptr->link;
    ptr->link=temp;
    
   
    
   return travel;
}


struct nodes *deletefirstnode(){
    struct nodes *ptr=travel;    
    ptr=ptr->link;
    travel=ptr;   
   return travel;
}


struct nodes *lastdeletenode(){
    struct nodes *ptr=travel,*ptr1;
    
    while(ptr->link!=NULL){
        ptr1=ptr;
        ptr=ptr->link;
    }ptr1->link=NULL;
    
    free(ptr);
    
   return travel;
}

struct nodes* delete(){
    struct nodes *ptr,*prev;
    ptr=travel;
    int ch;
    printf("Enter data to be deleted: ");
    scanf("%d",&ch);
    while(ptr->data!=ch){
        prev=ptr;
        ptr=ptr->link;
    }prev->link=ptr->link;
    free(ptr);
    return travel;
}




