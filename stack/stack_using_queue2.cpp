#include<iostream>
#include<queue>
using namespace std;
class stack{           //here we are making pop opeeration costly 
    queue<int>q1;
    queue<int>q2;
    int n;
    public:
    stack(){
        n=0;
    }
    void push(int val){
        q1.push(val);
        n++;
    }
    void pop(){
        if(n==0){
            cout<<"Empty Stack"<<endl;
            return;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        queue<int> temp;
        temp=q1;
        q1=q2;
        q2=temp;
    }
    int top(){
        return q1.back();
    }
    bool empty(){
        return q1.empty();
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
