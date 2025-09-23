#include<iostream>
#include<queue>
using namespace std;

struct comparePair{
    bool operator () (pair<string,int> &p1, pair<string,int> &p2){
        //return p1.second < p2.second;// for max heap in pair: second
        return p1.second > p2.second;// for min heap in pair: second
    }
};
int main(){ 
    //priority_queue<pair<string,int>> pq; //By deafault pair priority queue gives max heap for pair:first value

    // For second pair value max heap we have to create struct for comparison 
    priority_queue<pair<string,int>, vector<pair<string, int>>, comparePair> pq; 

    pq.push(make_pair("yash", 85));
    pq.push(make_pair("bak", 95));
    pq.push(make_pair("sanket", 65));

    while (!pq.empty())
    {
        cout<<"top : "<<pq.top().first<<","<<pq.top().second<<endl;
        pq.pop();
    }
    return 0; 
}