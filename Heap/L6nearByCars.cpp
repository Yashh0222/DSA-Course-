#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// create class to store idx and distSq combined in vector car 
class car{
    public:
    int idx;
    int distSq;

    car(int idx, int distSq){
        this->idx = idx;
        this->distSq= distSq;
    }

    bool operator < (const car &obj) const{ // used to find minheap(>) 
        return this->distSq > obj.distSq;
    }
};

void nearCars(vector<pair<int,int>> pos, int k){
    vector<car> cars; // using class vec 

    for (int i = 0; i < pos.size(); i++) // got dist from origin and added to vec cars with index
    {
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(car(i, distSq));
    }
    
    priority_queue<car> pq(cars.begin(),  cars.end());// created priority queue for less time to show only k cars which are nearr using min heap 

    for (int i = 0; i < k; i++) // TC: 0(n + klogn) less than normal loop clears more test cases
    {
        cout<<"car: "<<pq.top().idx<<endl;
        pq.pop();
    }
    

}
int main(){ 
    vector<pair<int, int>> pos; // create pair 

    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    nearCars(pos, 2);
    return 0; 
}