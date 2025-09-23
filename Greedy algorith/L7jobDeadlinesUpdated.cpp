#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// run in online compiler 
// class is used to combine three records simultesoully connected records
class job
{
public:
    int idx;
    int deadlines;
    int profits;

    job(int idx,int deadlines, int profits)
    {
        this->idx = idx;
        this->deadlines = deadlines;
        this->profits = profits;
    }
};

void maxProfit(vector<pair<int, int>> pairs)
{
    int n = pairs.size();
    
    vector<job> jobs; // job used as data type for vec
    for (int i = 0; i < n; i++)
    {
        jobs.emplace_back(i,pairs[i].first, pairs[i].second);// empplac_back func pushes direct all values 
    }
    
    sort(jobs.begin(), jobs.end(), [](job&a, job&b) { // & dirclty compares and sorts the vec using class 
        return a.profits > b.profits; // sorting in decending order 
    });// this type of comparison is called as lambda func conversion

    cout<<"Selecting job"<<jobs[0].idx<<endl;
    int profit = jobs[0].profits;
    int safeDeadline = 2;

    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadlines >= safeDeadline)
        {
            cout<<"selecting Job "<<jobs[i].idx<<endl;
            profit += jobs[i].profits;
            safeDeadline++;
        }
    }
    cout << " max profit is = " << profit << endl;
}
int main()
{
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs);
    return 0;
}