#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

//arr1 is original array and arr2 is copy of it in sorted and unique 
int LIS(vector<int> arr1){
    unordered_set<int> s(arr1.begin(), arr1.end()); // to find unique values in array 

    vector<int> arr2(s.begin(), s.end()); // to copy all values from set to new arrayy 
    sort(arr2.begin(), arr2.end()); // we need this sorted arry to makke LCS with orignial array to find LIS
    // by doing LCS with arr1 & arr2 we get our longest increasing subsequense 

    int n = arr1.size();
    int m = arr2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(arr1[i-1] == arr2[j-1]){ 
                dp[i][j] = 1 + dp[i-1][j-1];            
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
    }
    return dp[n][m];
}

int main(){ 
    vector<int> arr1 = {50,3,10,7,40,80};

    cout<<LIS(arr1)<<endl;
    return 0; 
}