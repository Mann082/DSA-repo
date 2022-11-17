#include <iostream>
#include<map>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        bool flag=0;
        for(auto it:s)
        {
            if(mp[it]>1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}