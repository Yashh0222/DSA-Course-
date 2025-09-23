#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// To find majority elements in nums arr whose occuranse is greatyer than n/3 size of nums
void majorityElements(vector<int> nums){
    unordered_map<int, int> m ; // <nums[i], occurasnse>

    for (int i = 0; i < nums.size(); i++)
    {
        if(m.count(nums[i])){
            m[nums[i]]++; // of no alredy exists in vec increse occurasnse 
        }else{
            m[nums[i]] = 1; // if not create and add freq = 1
        }
    }

    for(pair<int, int> p : m){
        if(p.second > nums.size()/3){
            cout<<p.first<<" ";
        }
    }
    cout<<endl;
}
int main(){ 
    vector<int> nums = {1,3,2,5,1,3,1,5,1};
    vector<int> nums2 = {1,2};

    majorityElements(nums);
    return 0; 
}