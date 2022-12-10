//MINIMUM NUMBER OF DELETIONS TO MAKE STRING A PALINDROME
#include<iostream>
using namespace std;
int count_deletions(string s,int i, int j){
    if(i>=j){
        return 0;
    }
    if(s[i]==s[j]){
        return count_deletions(s,i+1,j-1);
    }
    return 1+min(count_deletions(s,i+1,j),count_deletions(s,i,j-1));
}
int main(){
    string s;
    cin>>s;
    cout<<"Minimum number of deletions="<<count_deletions(s,0,s.length()-1);
    return 0;
}