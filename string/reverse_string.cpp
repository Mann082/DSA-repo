#include<iostream>
using namespace std;
class solve{
    public:
    string reverse(string s){
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            ans+=s[i];
        }
        return ans;
    }
};
int main(){
    string s;
    cin>>s;
    solve solution;
    cout<<solution.reverse(s)<<endl;
    return 0;
}