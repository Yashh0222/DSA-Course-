#include<iostream>
#include<queue>
using namespace std;

//to crete stack propeties using 2 queue 
// sameas queue using 2 stacks

class stack{
    queue<int> q1; 
    queue<int> q2;
    
    public:

    void push(int data){
        //q1 to q2 then push data then again q2 to q1 
        // this will push data from q1 to q2 then step 2 will add new data and st 3 will bring bqck all data fromo q2
        // all elements will become reverse like stack 
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // step:2 push the new data in q1
        q1.push(data);

        //step: 3 now q2 to q1 this will bring back all element that are present at q1 in reverse order
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        } 
             
    }

    void pop(){
        q1.pop();
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};
int main(){ 
    stack s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
    return 0; 
}