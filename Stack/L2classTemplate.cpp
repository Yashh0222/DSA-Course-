#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//to add varible data type we can use class template
template<class T> 
class Stack
{
    vector<T> vec;

public:
    void push(T val)
    {
        vec.push_back(val);
    }

    void pop()
    {
        if (isEmpty())
        {
            cout<<"stack is empty"<<endl;
        }
        
        vec.pop_back();
    }

    T top()
    {
        //if (isEmpty())
        //{
        //    cout<<"stack is empty"<<endl;
        //    return -1;
//
        //}
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};
int main()
{

    Stack<char> s;

    s.push('h');
    s.push('s');
    s.push('a');
    s.push('y');
   
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}