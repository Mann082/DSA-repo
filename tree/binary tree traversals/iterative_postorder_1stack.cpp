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
    stack<treenode*> st;
    vector<int> postorder;
    treenode* curr=root;
    while(!st.empty() || curr!=NULL){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            treenode* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else curr=temp;
        }
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
