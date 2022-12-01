#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void create(node* &head){
    node* temp=head;
    cout<<"How many nodes do you want?";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tempd;
        cout<<"Enter the data of "<<i<<"th node :";
        cin>>tempd;
        node* newnode=new node(tempd);
        if(temp==NULL){
            temp=newnode;
            head=temp;
            continue;
        }
        temp->next=newnode;
        temp=temp->next;
    }
    cout<<"List Created Successfully !!!"<<endl;
}
void display(node* head){
    node* temp=head;
    cout<<"list is:\n";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void evenafterodd(node* &head){
    node* temp=head;
    node* evenstart;
    node* odd;
    node* even;
    evenstart=temp->next;
    even=temp->next;
    odd=even->next;
    temp->next=odd;
    while(even->next!=NULL && odd->next!=NULL){
        even->next=odd->next;
        even=even->next;
        if(even->next==NULL)break;
        odd->next=even->next;
        odd=odd->next;
    }
    if(even->next==NULL){
        odd->next=evenstart;
        return;
    }
    else{
        even->next=NULL;
        odd->next=evenstart;
    }
}
int main(){
    node* head=NULL;
    create(head);
    display(head);
    evenafterodd(head);
    display(head);
    return 0;
}