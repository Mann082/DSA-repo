#include<bits/stdc++.h>
using namespace std;
int sum(vector<int> vec){
    int sum=0;
    for(auto it:vec){
        sum+=it;
    }
    return sum;
}
void print(vector<int>vce){
    for(auto it:vce){
        cout<<it<<" ";
    }
    cout<<endl;
}
void solve(int idx,vector<int> aux,int tsum,vector<int> &vec){
    if(idx>=vec.size()){
        if(sum(aux)==tsum){
            print(aux);
        }
        return;
    }
    aux.push_back(vec[idx]);
    solve(idx+1,aux,tsum,vec);
    aux.pop_back();
    solve(idx+1,aux,tsum,vec);        
}
void findtarget(vector<int> &vec,int tsum){
    solve(0,{},tsum,vec);
}
int main(){
    int n;
    cout<<"Enter Number of elements in list :";
    cin>>n;
    vector<int> vec;
    cout<<"Enter the data : ";
    while(n--){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    cout<<"Enter Target Sum : ";
    int target;
    cin>>target;
    findtarget(vec,target);
    return 0;
}