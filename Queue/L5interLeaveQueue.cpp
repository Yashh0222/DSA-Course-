#include<iostream>
#include<queue>
using namespace std;

//interLEave is from staring and mid pushing one one element 

void interLeave(queue<int> &orginal){ //TC: 0(n) , SC: (n) 
    // creating anaother queue and pushing half of orignal values
    int n = orginal.size();
    queue<int> first;

    for (int i = 0; i <n/2 ; i++)
    {
        first.push(orginal.front());
        orginal.pop();
    }
    
    //now pushing first queue val in orinal queue and also from front of orignal queue val which starts from 6

    while (!first.empty())
    {
        //Ex: 1 added to orignal queue from first quueue
        orginal.push(first.front());
        first.pop();
        
        orginal.push(orginal.front());
        orginal.pop();

    }
    
}
int main(){ 
    queue<int> orginal;
    for (int i = 1; i <= 10; i++)
    {
        orginal.push(i);
    }
    
    interLeave(orginal);

    for (int i = 1; i <= 10; i++)
    {
        cout<<orginal.front()<<" ";
        orginal.pop();
    }
    
    return 0; 
}