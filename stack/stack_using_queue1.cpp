#include<iostream>
#include<queue>
using namespace std;
class stack{                       // here we are making push operation costly
    int n=0;
    queue<int>q1;
    queue<int>q2;
    public:
    stack(){
        n=0;
    }
    void push(int val){
        q1.push(val);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        queue<int> temp;
        temp=q1;
        q1=q2;
        q2=temp;
        n++;
    }
    void pop(){
        if(n==0)cout<<"Stack is Empty"<<endl;
        else{q2.pop();
        n--;}
    }
    int top(){
        return q2.front();
    }
    bool empty(){
        return q2.empty();
    }
};
int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}