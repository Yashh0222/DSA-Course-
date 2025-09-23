#include<iostream>
#include<vector>
using namespace std;

// to find max no off activites we can do in given span of time
//first the end time should be sorted so we can find smaller works and complete maximmum  work

int maxActivites(vector<int> start, vector<int> end){
    //sort the end but given already sorted
    // slect first activity A0
    cout<<"Selecting Activity A0"<<endl;
    int activityCount = 1;
    int currEndTime = end[0]; // to compare with another activity start

    for (int i = 0; i < start.size(); i++)
    {
        if (start[i] >= currEndTime)
        {
            //we can print which activity is selected
            cout<<"Selecting Activity A"<<i<<endl;
            //if one work is complete and other start is greater than the end we can do that activity
            // it doent overlap the other work 
            activityCount++;
            currEndTime = end[i];

        }
        
    }
    return activityCount;
}
int main(){ 
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9}; // ans is 4

    cout<<maxActivites(start,end)<<endl;
    return 0; 
}