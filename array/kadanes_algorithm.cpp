//solving the problem by using kadane's algorithm
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxend=0,maxans=INT_MIN;
    for(int i=0;i<n;i++){
        maxend=maxend+arr[i];
        maxans=max(maxend,maxans);
        if(maxend<0)maxend=0;
    }
    cout<<maxans<<endl;
    return 0;
}