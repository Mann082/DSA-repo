#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
// #define node* struct node*
void enqueue(struct node** head){
    struct node* temp=*head;
    printf("Enter the Value to be inseerted in queue:");
    int t;
    scanf("%d",&t);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=t;
    newnode->link=NULL;
    if(temp==NULL){
        *head=newnode;
        return;
    }
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newnode;
    printf("\nEnqueue was completed!\n");
}
void dequeue(struct node** head){
    if(head==NULL){
        printf("Queue is Empty\n");
        return;
    }
    struct node* temp=*head;
    *head=temp->link;
    free(temp);
    printf("Dequeue was executed!\n");
}
void display(struct node* head){
    struct node* temp=head;
    printf("\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main(){
    struct node* head=NULL;
    while(1){
        printf("Press 1:-\n");
        printf("1 for Enqueue\n");
        printf("2 for Dequque\n");
        printf("3 for display\n");
        int o;
        scanf("%d",&o);
        switch(o){
            case 1: enqueue(&head);
            break;
            case 2: dequeue(&head);
            break;
            case 3: display(head);
            break;
            default: printf("Invalid Option\n");
            break;
        }
    }
    return 0;
}