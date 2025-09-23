#include<iostream>
#include<stack>
using namespace std;

class queue{
   stack<int> s1;
   stack<int> s2;

   public:

   // to push data like queue use 2 stacks
   // first push data from s1 to s2 and add new data to s1 then again push data from s2 t s2
   void push(int data){
    // s1 -> s2
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    
    // now add new data to s1
    s1.push(data);

    // push s2 data to s1 

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();        
    }
    
   }

   // we already have reversed s1 so top of stack and front of is always same so we can pop 
   void pop(){
       s1.pop();
   }

   int front(){
    return s1.top();
   }

   bool empty(){
    return s1.empty();
   }
};
int main(){ 
    queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();

    }
    
    return 0; 
}