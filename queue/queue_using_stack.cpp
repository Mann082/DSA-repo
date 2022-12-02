#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int>s1;
    stack<int>s2;
    int n;
    public:
    queue(){
        n=0;
    }
    void enqueue(int val){
        s1.push(val);
    }
    void dequeue(){
        if(s1.empty() and s2.empty()){
            cout<<"Queue is empty";
            return;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
        n--;
    }
    int front(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty(){
        return s1.empty() && s2.empty();
    }
};
int main(){
    queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    while(!q1.empty()){
        cout<<q1.front()<<endl;
        q1.dequeue();
    }
    return 0;
}