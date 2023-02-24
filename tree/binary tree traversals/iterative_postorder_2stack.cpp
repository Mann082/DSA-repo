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
vector<int> postorder(treenode* root){
    vector<int> postorder;
    if(root==NULL)return postorder;
    stack<int> st2;
    stack<treenode*> st1;
    st1.push(root);
    while(!st1.empty()){
        treenode* curr=st1.top();
        st1.pop();
        st2.push(curr->data);
        if(curr->left!=NULL)st1.push(curr->left);
        if(curr->right!=NULL)st1.push(curr->right);
    }
    while(!st2.empty()){
        postorder.push_back(st2.top());
        st2.pop();
    }
    return postorder;
}
int main(){
    treenode* root=new treenode(1);
    treenode* rootleft=new treenode(2);
    treenode* rootright=new treenode(3);
    treenode* rootleftleft=new treenode(4);
    treenode* rootleftright=new treenode(5);
    treenode* rootrightleft=new treenode(6);
    treenode* rootrightright=new treenode(7);
    rootleft->left=rootleftleft;
    rootleft->right=rootleftright;
    rootright->left=rootrightleft;
    rootright->right=rootrightright;
    root->left=rootleft;
    root->right=rootright;
    vector<int> ans=postorder(root);
    for(auto it:ans ){
        cout<<it<<" ";
    }
    return 0;
}
