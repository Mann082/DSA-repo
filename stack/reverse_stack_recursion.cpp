#include<iostream>
#include<stack>
using namespace std;
void InsertAtBottom(stack<int> &st,int elem){
    if(st.empty()){
        st.push(elem);
        return;
    }
    int topele=st.top();
    st.pop();
    InsertAtBottom(st,elem);
    st.push(topele);
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int elem=st.top();
    st.pop();
    reverse(st);
    InsertAtBottom(st,elem);
}
void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    display(st);
    reverse(st);
    display(st);
}