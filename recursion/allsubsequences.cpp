#include<bits/stdc++.h>
using namespace std;
void print(vector<int> &vec){
    for(auto it:vec){
        cout<<it<<" ";
    }
    cout<<endl;
}
void solve(int idx,vector<int> aux,vector<int> &vec){
    if(idx>=vec.size()){
        print(aux);
        return;
    }
    aux.push_back(vec[idx]);
    solve(idx+1,aux,vec);
    aux.pop_back();
    solve(idx+1,aux,vec);
}
void allsubseq(vector<int> vec){
    solve(0,{},vec);
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
    cout<<"Following are the all possible subsequences :"<<endl;
    allsubseq(vec);
    return 0;
}