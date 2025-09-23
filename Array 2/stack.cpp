#include<iostream>
#include<stack>
using namespace std;
int main(){ 
    
    stack<string> s;

    s.push("yash");
    s.push("sanket");
    s.push("radhe");

    cout<<"Top element is ->"<<s.top()<<endl;

   

    s.pop();
    cout<<"Top element is ->"<<s.top()<<endl;
    cout<<"Size of stack ->"<<s.size()<<endl;
    cout<<"empty or not ->"<<s.empty()<<endl;

    return 0; 
}