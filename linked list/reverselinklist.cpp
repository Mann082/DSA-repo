#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* link;
    node(int val){
        data=val;
        link=NULL;
    }
};
void create(node* &head,int n){
    cout<<"Enter the Data of Nodes :"<<endl;
    int temp;
    cin>>temp;
    node* pnode= new node(temp);
    head=pnode;
    for(int i=0;i<n-1;i++){
        cin>>temp;
        node* newnode= new node(temp);
        pnode->link=newnode;
        pnode=newnode;
    }
    cout<<endl;
    cout<<"List Created"<<endl;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->link;
    }
    cout<<endl;
}
void reverse(node* &head){
    node* prev=NULL;
    node* curr= head;
    node* next;
    while(curr!=NULL){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    cout<<"List reversed"<<endl;
}
node* recursiverevers(node* &head){
    if(head==NULL || head->link==NULL){
        return head;
    }
    node* newhead= recursiverevers(head->link);
    head->link->link=head;
    head->link=NULL;
    return newhead;
}
int main(){
    int n;
    node* head=NULL;
    cout<<"Enter the Number of Node you want to put : ";
    cin>>n;
    create(head,n);
    display(head);
    reverse(head);
    display(head);
    head=recursiverevers(head);
    display(head);
    return 0;
}