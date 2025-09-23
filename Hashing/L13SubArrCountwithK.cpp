#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Formula we used = sum[i,j] = sum[j] - sum[i-1]
int subArrCountEqualToK(vector<int> arr, int k){ 
    unordered_map<int, int> m; // <sum, count>
    m[0] = 1;
    int sum = 0; 
    int ans = 0;
    
    for(int j = 0; j<arr.size(); j++){
        sum += arr[j];
        if(m.count(sum-k)){ // if already exists in map then there is subarr with val k in map add its count to ans 
            ans += m[sum-k];
        }
        
        //if not present add to map 
        if(m.count(sum)){
            m[sum]++; // if already exists increse count
        }else{
            m[sum] = 1;
        }
    }
    return ans;
}
int main(){ 
    vector<int> arr = {10,2,-2,-20,10};
    int k = -10;

    cout<<"subarr count with val sum of k is : "<<subArrCountEqualToK(arr, k);
    return 0; 
}