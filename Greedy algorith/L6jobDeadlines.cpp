#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double,int> p1, pair<double,int> p2){
    return p1.second > p2.second ;  
}

void maxProfit(vector<pair<int,int>> jobs){
    int n = jobs.size();

    sort(jobs.begin(),jobs.end(),compare);

    int profit = jobs[0].second;
    int safeDeadline = 2; // one work is done in one day then other jobs of 1 day will not be done so dealine is 2

    for (int i = 0; i < n; i++)
    {
        if (jobs[i].first >= safeDeadline) // this checks for deadline 
        {
            profit += jobs[i].second;
            safeDeadline++;
        }
        
    }
    cout<<" max profit is = "<<profit<<endl;
    
}
int main(){ 
    int n = 4;
    vector<pair<int,int>> jobs(n, make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);

    maxProfit(jobs);
    return 0; 
}