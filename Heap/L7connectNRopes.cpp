#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNRopes(vector<int> ropes){
    // this adds ropes[i] to queue and using greater it is stored in the form of minheap 
    priority_queue<int, vector<int> ,greater<int>> pq(ropes.begin(), ropes.end());
    
    int minCost = 0;

    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        minCost += min1 + min2;
        pq.push(min1 + min2);
    }

    cout<<" Minimun cost of ropes is : "<<minCost<<endl;
    return minCost; 
}
int main(){ 
    vector<int> ropes = {4,2,3,6};

    connectNRopes(ropes);
    return 0; 
}