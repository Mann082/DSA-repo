#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void push(struct node** head){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int temp;
    printf("Enter the value to be pushed:");
    scanf("%d",&temp);
    newnode->data=temp;
    newnode->link=*head;
    *head=newnode;
    printf("The Given Value is Pushed \n");
}
void pop(struct node** head){
    if(*head==NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp=*head;
    *head=temp->link;
    free(temp);
    printf("TOP is popped\n");
}
void display(struct node** head){
    struct node* temp=*head;
    printf("Values in Stack:-\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}
int main(){
    struct node* head=NULL;
    while(1){
        printf("\nPress:-\n");
        printf("1 for push\n");
        printf("2 for pop\n");
        printf("3 for display\n");
        int t;
        scanf("%d",&t);
        switch(t){
            case 1: push(&head);
            break;
            case 2: pop(&head);
            break;
            case 3: display(&head);
            break;
            default: printf("Invalid Option\n");
        }
    }
    return 0;
}