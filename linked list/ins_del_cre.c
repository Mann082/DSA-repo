#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void display(struct node* head_ref){
    while(head_ref!=NULL){
        printf("%d ",head_ref->data);
        head_ref=head_ref->link;
    }
}
void insert(struct node** head_ref){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the Data of the node:");
    int temp;
    scanf("%d",&temp);
    new->data=temp;
    new->link=NULL;
    if(*head_ref==NULL){
        *head_ref=new;
        return;
    }
    struct node* last=*head_ref;
    while(last->link!=NULL){
        last=last->link;
    }
    last->link=new;
    return;
}
void delete(struct node** head){
    struct node*p,*n;
    n=*head;
    p=n;
    while(n->link!=NULL){
        p=n;
        n=n->link;
    }
    p->link=NULL;
    free(n);
    return;
}
int main(){
    struct node* head=NULL;
    int o;
    while(1){
    printf("Enter :-\n");
    printf("1 for Display\n");
    printf("2 for Insertion\n");
    printf("3 for Deletion\n");
    
    scanf("%d",&o);
    
    switch(o){
        case 1:display(head);
                break;
        case 2: insert(&head);
                break;
        case 3: delete(&head);
                break;
    }}
    return 0;
}