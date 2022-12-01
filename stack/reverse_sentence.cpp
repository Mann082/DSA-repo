#include<iostream>
#include<stack>
using namespace std;
void reverse(string s){
    stack<string> st;
    for(int i=0;i<s.size();i++){
        string word="";
        while(s[i]!=' ' && i<s.size()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    cout<<"Reversed Sentence is: "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    string str;
    cout<<"Enter the sentence"<<endl;
    getline(cin, str);
    reverse(str);
    return 0;
}