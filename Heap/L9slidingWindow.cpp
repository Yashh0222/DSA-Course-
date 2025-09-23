#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Sliding Window: To find maximum in every window upto n 
void slidingWindow(vector<int> arr, int k){
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(make_pair(arr[i], i)); // adding top k values in queue 
    }
    // printing top val as its max due to max heap 
    cout<<" output : "<<pq.top().first<<" ";

    //slide the window
    for (int i = k; i < arr.size(); i++)
    {
        while(!pq.empty() && pq.top().second <= (i - k)){
            pq.pop();
        }

        // after checking for sliding window add arr val  to queue
        pq.push(make_pair(arr[i], i));
        cout<<pq.top().first<<" ";
    }
    
    
}
int main(){ 
    
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    slidingWindow(arr, k);
    return 0; 
}