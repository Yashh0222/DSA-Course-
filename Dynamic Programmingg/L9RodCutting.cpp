// to cut rod and find maximum profit
#include<iostream>
#include<vector>
using namespace std;

int rodCutting(vector<int> length, vector<int> price, int L, int n){
    vector<vector<int>> dp(n+1, vector<int>(L+1, 0));

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < L+1; j++)
        {
            int rodLength = length[i-1]; 
            int rodPrice = price[i-1]; 

            if(rodLength <= j){
                dp[i][j] = max(rodPrice + dp[i][j - rodLength], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }
    return dp[n][L];
}
int main(){ 
    vector<int> length = {1,2,3,4,5,6,7,8};
    vector<int> price = {1,5,8,9,10,17,17,20};
    int L = 8; // rod length 
    int n = 8;

    cout<<rodCutting(length, price, L, n)<<endl;
    return 0; 
}