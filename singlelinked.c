#include <stdio.h>
#include <stdlib.h>


struct nodes{
    int data;
    struct nodes *link;
}*travel,*final;


struct nodes* createnode();
struct nodes* insertnode();
struct nodes* lastinsertnode();
struct nodes* middleinsertnode();
struct nodes *deletefirstnode();
struct nodes *lastdeletenode();
struct nodes* delete();
struct nodes* afterplace();
struct nodes* beforeplace();
struct nodes* sort();
void traverse (struct nodes *ptr);

void main(){
    int n,ch,con;

    travel=createnode();

    printf("\n___________________________\n");
    printf("List after creating nodes: \n");
    traverse(travel);
    
    
    do{
        printf("Enter choice\n1 for insertion at first\n2 for insertion at last\n3 for insertion in between\n4 for deletion\n5 for deletion at last\n6 to delete in between\n7 to add data after a data\n8 to add node before a data\n9to sort\n");
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
            case 7:
                printf("\n___________________________\n");
                printf("List after inserting node after a data: \n");
                traverse(afterplace());
                break;

            case 8:
                printf("\n___________________________\n");
                printf("List after inserting node before a data: \n");
                traverse(beforeplace());
                break;

            case 9:
                printf("\n___________________________\n");
                printf("List after sorting: \n");
                traverse(sort());
                break;
            
            case 10:
                traverse(travel);
                break;

            default:
                printf("Wrong input\n");
                break;
        }printf("\nEnter 1 to continue\n0 to exit\n");
        scanf("%d",&con);
    }while(con==1);
}


//creating nodes and attaching one by one

struct nodes* createnode(){
    int i;
    struct nodes *head=NULL,*temp=NULL,*ptr=NULL;
    do{
        temp=(struct nodes*)malloc(sizeof(struct nodes));
        printf("Enter data for node\n");
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
        }printf("\nEnter 1 to continue\n0 to exit\n");
        scanf("%d",&i);
    }while(i==1);
    return head;
}


//displaying contents
void traverse(struct nodes *ptr){
    while(ptr!=NULL){
        printf("\n______________________________________________________\n");
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
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
    int i=0,choice;
    printf("Enter number where node to be inserted");
    scanf("%d",&choice);

    temp=(struct nodes*)malloc(sizeof(struct nodes));
    if(choice==1){
        insertnode();
    }else{
    while(i<choice-2){
        ptr=ptr->link;
        i++;
    }printf("Enter data into node to be inserted: ");
    scanf("%d",&(temp->data));
    temp->link=ptr->link;
    ptr->link=temp;

   return travel;
    }
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

struct nodes* afterplace(){
    
    struct nodes *temp,*ptr=travel;
    int choice;
    printf("Enter data after which node to be inserted");
    scanf("%d",&choice);

    while(ptr->data!=choice&&ptr->link!=NULL ){
        ptr=ptr->link;
    }if(ptr->data==choice){
        temp=(struct nodes*)malloc(sizeof(struct nodes));
        printf("Enter data into node to be inserted: ");
        scanf("%d",&(temp->data));
        temp->link=ptr->link;
        ptr->link=temp;
        return travel;
    }else{
        printf("\nWrong input\n");
        return 0;
    }  
}

struct nodes* beforeplace(){
    
    struct nodes *temp,*prev=NULL;
    struct nodes *ptr;
    int i=2,choice;
    printf("Enter data before which node to be inserted");
    scanf("%d",&choice);
    if(choice==travel->data){
        temp=(struct nodes*)malloc(sizeof(struct nodes));
        printf("Enter data into node to be inserted: ");
        scanf("%d",&(temp->data));
        temp->link=travel;
        travel=temp;
    }else{
        ptr=travel;
        while(ptr->data!=choice && ptr->link!=NULL){
            prev=ptr;
            ptr=ptr->link;
        }if(choice==ptr->data){
            temp=(struct nodes*)malloc(sizeof(struct nodes));
            printf("Enter data into node to be inserted: ");
            scanf("%d",&(temp->data));
            temp->link=prev->link;
            prev->link=temp;
            return travel;
        }else
            printf("\nNo data found\n");
            return 0;
    }
   
}
struct nodes *sort(){
    struct nodes *prev,*ptr;
    int temp;
    for(ptr=travel;ptr->link!=NULL;ptr=ptr->link){
        for(prev=ptr->link;prev!=NULL;prev=prev->link){
            if(ptr->data > prev->data){
                temp=ptr->data;
                ptr->data=prev->data;
                prev->data=temp;
            }
        }
    }
   return travel;
}



