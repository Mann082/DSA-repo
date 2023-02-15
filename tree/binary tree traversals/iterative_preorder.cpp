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
vector<int> preorder(treenode* &root){
    vector<int> preorder;
    if(root==NULL)return preorder;
    stack<treenode*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right!=NULL)st.push(root->right);
        if(root->left!=NULL)st.push(root->left);
    }
    return preorder;
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
    vector<int> vec=preorder(root);
    for(auto it:vec){
        cout<<it<<" ";
    }
    return 0;
}