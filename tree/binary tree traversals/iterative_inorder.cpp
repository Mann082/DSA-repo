#include<bits/stdc++.h>
using namespace std;
class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
vector<int> inorder(treenode* &root){
    vector<int> inorder;
    if(root==NULL)return inorder;
    treenode* current=root;
    stack<treenode*> st;
    while(true){
        if(current!=NULL){
            st.push(current);
            current=current->left;
        }
        else{
            if(st.empty())break;
            current=st.top();
            st.pop();
            inorder.push_back(current->data);
            current=current->right;
        }
    }
    return inorder;
}
int main(){
    treenode* root=new treenode(1);
    treenode* left1=new treenode(2);
    treenode* right1=new treenode(3);
    treenode* ll=new treenode(4);
    treenode* lr=new treenode(5);
    treenode* rl=new treenode(6);
    treenode* rr=new treenode(7);
    left1->left=ll;
    left1->right=lr;
    right1->left=rl;
    right1->right=rr;
    root->left=left1;
    root->right=right1;
    vector<int> vec=inorder(root);
    for(auto it:vec){
        cout<<it<<" ";
    }
    return 0;
}