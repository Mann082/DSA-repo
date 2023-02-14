#include<bits/stdc++.h>
using namespace std;
void perms(int idx,vector<int>&vec,vector<vector<int>> &ans){
    if(idx==vec.size()){
        ans.push_back(vec);
        return;
    }
    for(int i=idx;i<vec.size();i++){
        swap(vec[i],vec[idx]);
        perms(idx+1,vec,ans);
        swap(vec[i],vec[idx]);
    }
}
int main(){
    cout<<"Enter Number of Elements in the list :";
    int n;
    cin>>n;
    cout<<"Enter list elements :";
    vector<int> vec;
    while(n--){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    vector<vector<int>> ans;
    map<int,bool>mp;
    perms(0,vec,ans);
    cout<<"All possible permutations are: "<<endl;
    for(auto it:ans){
        for(auto mt: it){
            cout<<mt<<" ";
        }
        cout<<endl;
    }
}