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
void inserttail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool search(node* head,int val){
    node* current=head;
    while(current!=NULL){
        if(current->data==val)return true;
        current=current->next;
    }
    return false;
}
void inserthead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void deletenode(node* &head,int val){
    node* temp=head;
    node* temp2;
    int count=0;
    while(temp!=NULL && temp->data!=val){
        temp2=temp;
        temp=temp->next;
        count++;
    }
    if(count==0){
        head=temp->next;
        delete temp;
        return;
    }
    temp2->next=temp->next;
    delete temp;
}
 int main(){
    node* head=NULL;
    inserttail(head,1);
    inserttail(head,2);
    inserttail(head,3);
    inserthead(head,0);
    display(head);
    if(search(head,3))cout<<"3 is present"<<endl;
    else cout<<"3 is not present"<<endl;
    deletenode(head,0);
    display(head);
    return 0;

 }