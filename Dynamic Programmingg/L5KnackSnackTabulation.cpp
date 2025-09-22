#include<iostream>
#include<vector>
using namespace std;

int knackSnackTabulatioin(vector<int> val, vector<int> wt, int W, int n){
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0)); // created 2D array which stores n and W->weight of sack 
    // which all filled with 0

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            int itemWt = wt[i-1];  // wt[i-1] gives wt of particular index as i starts with 1 and [1-1]=0 so index 0 starts 
            int itemVal = val[i-1]; // same here this gives an item val 

            if (itemWt <= j)
            {                 //condn to include             // condn to exclude 
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt] , dp[i-1][j]); 
                //gives max b/w to include or exclude that item 
            }else{
                dp[i][j] = dp[i-1][j]; // if item wt is greater tham sack weight
            }
            
        }
        
    }

    cout<<"Tabulation  Matrix: "<<endl;
    for (int i = 0; i < n+1 ; i++)
    {
        for (int j = 0; j< W+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;                
    }
     cout<<endl;

    return dp[n][W];

    
}
int main(){ 
    vector<int> val = {15,14,10,45,30}; 
    vector<int> wt = {2,5,1,3,4};
    int W = 7; // weight of sack(bori)
    int n = 5;

    cout<<knackSnackTabulatioin(val, wt,  W,  n)<<endl;  
    

    return 0; 
}