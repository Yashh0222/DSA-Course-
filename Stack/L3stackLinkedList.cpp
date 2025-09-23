#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//to add varible data type we can use class template
//creating Linked list using stack
template<class T> 
class Node{
    public:
    T data;
    Node* next;

    Node(T val){
        data = val;
        next = NULL;
    }
};

template<class T> 
class Stack
{
   Node<T>* head;

public:
   Stack(){
    head = NULL;
}
    void push(T val)
    {
        //creatting newNode 
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top()
    {
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
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