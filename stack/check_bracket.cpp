#include<iostream>
#include<stack>
using namespace std;
bool checkbracket(string s){
    int n=s.length();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='('|| s[i]=='{' || s[i]=='[')st.push(s[i]);
        else if(s[i]==')'){
            if(st.top()=='(')st.pop();
            else return false;
        }
        else if(s[i]=='}'){
            if(st.top()=='{')st.pop();
            else return false;
        }
        else if(s[i]==']'){
            if(st.top()=='[')st.pop();
            else return false;
        }
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    if(checkbracket(s))cout<<"balanced paranthesis"<<endl;
    else cout<<"Unbalanced paranthesis"<<endl;
    return 0;
}