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
vector<vector<int>> solve(treenode* &node){
    vector<vector<int>> ans;
    if(node==NULL){
        return ans;
    }
    queue<treenode*> q;
    q.push(node);
    while (!q.empty())
    {
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            treenode* temp=q.front();
            q.pop();
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}
void leveltraverse(treenode* &node){
    vector<vector<int>> ans=solve(node);    
    for(auto it:ans){
        for(auto mt: it){
            cout<<mt<<" ";
        }
    }
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
    leveltraverse(root);
    return 0;
}