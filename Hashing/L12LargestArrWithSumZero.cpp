#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Formula we used = sum[i,j] = sum[j] - sum[i-1]
int LargestArrWithSumZero(vector<int> arr){
    unordered_map<int, int> m;

    int sum =0 ;
    int ans =0 ;
    
    for (int j = 0; j < arr.size(); j++)
    {
        sum += arr[j];

        if(m.count(sum)){
            int currlen = j - m[sum]; // if sum[j] = sum in map then we got the sub which subarr b/w sum[j] and map[sum] 
            ans = max(ans, currlen); // eg: 15 gets added to map and after some steps we get again sum 15 so we find it in map and get that subarr using currlen 
        }else{ // currlen = j - sum[idx] eg: sum[idx] is first sum=15 idx
            m[sum] = j;
        }
    } 
    return ans;    
}
int main(){ 
    vector<int> arr = {15,-2, 2,-8,1,7,10};
    cout<< "largest subarray with sum 0 is "<<LargestArrWithSumZero(arr)<<endl;
    return 0; 
}