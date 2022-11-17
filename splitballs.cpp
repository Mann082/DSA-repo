#include <bits/stdc++.h>
using namespace std;
long long arr[10000001];
#define mod 1000000007

int main() {
	// your code goes here
	arr[0]=0;
    arr[1]=1;
	for(int i=2;i<=1000000;i++){
	    arr[i] = (i*(arr[i-1])%mod)%mod;
	}

	int t; cin>>t;
	while(t--){
	long n; cin>>n;
    vector<long long> vec;
    long long temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        temp=temp%mod;
        vec.push_back(temp);
    }
	long long sum=0;
    for(auto it:vec)
    {
        sum=(sum+it%mod)%mod;
    }
	cout<<sum<<endl;
	}
	return 0;
}