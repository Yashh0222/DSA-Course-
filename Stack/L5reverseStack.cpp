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

void reverseStack(stack<int> &s){
    
    //BAse case
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s){
  while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){ 
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    printStack(s);

    reverseStack(s);
    printStack(s);
  
    return 0; 
}