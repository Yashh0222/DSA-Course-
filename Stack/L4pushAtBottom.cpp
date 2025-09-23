#include<iostream>
#include<stack>
using namespace std;

// pushing element aat the bottom of stack
void pushAtBottom(stack<int> &s, int val){

    // Base case

    if(s.empty()){
        s.push(val); //ppush new val whwn stack is empty
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp); //back tracking the poped element 

}
int main(){ 
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s, 4);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0; 
}