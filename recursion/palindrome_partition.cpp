#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end])return false;
        start++;
        end--;
    }
    return true;
}
void solve(string s,int idx,vector<vector<string>> &ans,vector<string> &aux){
    if(idx==s.size()){
        ans.push_back(aux);
        return;
    }
    for(int i=idx;i<s.size();i++){
        if(ispalindrome(s,idx,i)){
            aux.push_back(s.substr(idx,i-idx+1));
            solve(s,i+1,ans,aux);
            aux.pop_back();
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> aux;
    solve(s,0,ans,aux);
    return ans;
}
int main(){
    cout<<"Enter the string :";
    string s;
    cin>>s;
    vector<vector<string>> ans;
    ans=partition(s);
    for(auto it:ans){
        for(auto mt:it){
            cout<<mt<<" ";
        }
        cout<<endl;
    }
    return 0;
}