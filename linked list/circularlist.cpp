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
void listcreate(node* &head){
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
        }
        temp->link=newnode;
        temp=temp->link;
    }
    temp->link=head;
}
void display(node* head){
    if(head==NULL)return;
    node* temp=head;
    cout<<"The List is displayed as:\n";
    cout<<temp->data<<" ";
    temp=temp->link;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
int main(){
    node* head=NULL;
    listcreate(head);
    display(head);
    return 0;
}