#include<iostream>
#include<stack>
using namespace std;
int prec(char c){
    if(c=='^')return 3;
    if(c=='*' || c=='/')return 2;
    if(c=='+' || c=='-')return 1;
    return -1;
}
string postfix(string s){
    string ans="";
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
        ans+=s[i];
        else if(s[i]=='(')
        st.push('(');
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    cout<<"Enter the infix expression:"<<endl;
    string s;
    cin>>s;
    cout<<"The postfix expression is:"<<postfix(s)<<endl;
    return 0;
}