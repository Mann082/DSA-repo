#include<bits/stdc++.h>
using namespace std;
void perms(vector<int> vec,map<int,bool> mp,vector<vector<int>> &ans,vector<int> aux){
    if(aux.size()==vec.size()){
        ans.push_back(aux);
        return;
    }
    for(int i=0;i<vec.size();i++){
        if(mp[vec[i]]==false){
            mp[vec[i]]=true;
            aux.push_back(vec[i]);
            perms(vec,mp,ans,aux);
            aux.pop_back();
            mp[vec[i]]=false;
        }
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
    perms(vec,mp,ans,{});
    cout<<"All possible permutations are: "<<endl;
    for(auto it:ans){
        for(auto mt: it){
            cout<<mt<<" ";
        }
        cout<<endl;
    }
}
