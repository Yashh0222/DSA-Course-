// this gives better time complexxity than normal recursion 
// with recursion TC : 0(2^n)
// with DP   TC : 0(n*w)  so we use DP 
#include<iostream>
#include<vector>
using namespace std;

int knackSnackMemoisation(vector<int> val,vector<int>  wt, int W, int n, vector<vector<int>> &dp){
    //base case
    if (n == 0 || W == 0)
    {
        return 0;
    }

    // for memoisation 
    // when samw step of memoisation occurs this returns previos calculated value in that step
    if (dp[n][W] != -1)
    {
        return dp[n][W]; 
    }
    

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if (itemWt <= W)
    {
        // if we want to include the item in sack
        int ans1 = knackSnackMemoisation(val, wt, W-itemWt, n-1, dp) + itemVal;

        
        // if we doesnt want to include the item in sack
        int ans2 = knackSnackMemoisation(val, wt, W, n-1, dp);

        dp[n][W] = max(ans1,ans2);

    }else{
        dp[n][W] = knackSnackMemoisation(val, wt, W, n-1, dp);
    }
    
    return dp[n][W];
    
}
int main(){ 
    vector<int> val = {15,14,10,45,30}; 
    vector<int> wt = {2,5,1,3,4};
    int W = 7; // weight of sack(bori)
    int n = 5;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    cout<< knackSnackMemoisation(val , wt, W, n, dp)<<endl;

    cout<<"Memoisation Matrix: "<<endl;
    for (int i = 0; i < n+1 ; i++)
    {
        for (int j = 0; j< W+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;                
    }
     cout<<endl;
    return 0; 
}