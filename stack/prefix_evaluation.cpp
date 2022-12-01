#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
bool operatorr(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%')
    return true;
    return false;
}
char solve(char c,int a,int b){
    int m=a,n=b,x;
    switch(c){
        case '+': x=m+n;
        break;
        case '-': x=m-n;
        break;
        case '/': x=m/n;
        break;
        case '*': x=m*n;
        break;
        case '^': x=pow(m,n);
        break;
        case '%': x=m%n;
        break; 
    }
    return x;
}
void evaluate(string s){
    stack<int> st;
    for(int i=s.size()-1;i>=0;i--){
        // cout<<st.top()<<" ";
        if(operatorr(s[i])){
            int operand1=st.top();
            st.pop();
            int operand2=st.top();
            st.pop();
            st.push(solve(s[i],operand1,operand2));
            continue; 
        }
        st.push(s[i]-'0');
    }
    cout<<st.top()<<endl;
}
int main(){
    string s;
    cout<<"Enter the prefix expresion:"<<endl;
    cin>>s;
    cout<<"The Evaluated value is:"<<endl;
    evaluate(s);
    return 0;
}