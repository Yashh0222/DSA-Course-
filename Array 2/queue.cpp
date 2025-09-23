#include<iostream>
#include<queue>
using namespace std;
int main(){ 
    
    queue<string> s;

    s.push("yash");
    s.push("sanket");
    s.push("radhe");

    cout<<"Top element is ->"<<s.front()<<endl;

   cout<<"Size of queue before pop ->"<<s.size()<<endl;

    s.pop();
    cout<<"Top element is ->"<<s.front()<<endl;
    cout<<"Size of queue after pop ->"<<s.size()<<endl;
    cout<<"empty or not ->"<<s.empty()<<endl;

    return 0; 
}