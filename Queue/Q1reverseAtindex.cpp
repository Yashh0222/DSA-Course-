#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseAtindex(queue<int>  & q, int k){
    stack<int> s;
    
   for (int i = 0; i < k && !q.empty(); i++) {
    s.push(q.front());
    q.pop();
}

    while (!s.empty() )
    {
        q.push(s.top());
        s.pop();
    }
    
    int n = q.size();
    int idx = n - k;

    for (int i = 0; i < idx; i++)
    {
        q.push(q.front());
        q.pop();
    }
    

}
int main(){ 
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseAtindex(q, 3);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    

    return 0; 
}