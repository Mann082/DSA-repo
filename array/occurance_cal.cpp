#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    vector<pair<int,int>> count_occurance(int arr[],int n){
        bool visited[n];
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==true)continue;
            else{
                int count=1;
                for(int j=i+1;j<n;j++){
                    if(arr[i]==arr[j]){
                        count++;
                        visited[j]=true;
                    }
                }
                pair<int,int> temp;
                temp.first=arr[i];
                temp.second=count;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
int main(){
    solution solve;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<pair<int,int>> ans=solve.count_occurance(arr,n);
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}