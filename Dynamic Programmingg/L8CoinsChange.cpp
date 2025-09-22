#include<iostream>
#include<vector>
using namespace std;

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        //here after solving dp stores the no of combination at particular index in 2D

        //if coins are there and amount is zero then we count it a coombinaiton
        for(int i = 0; i<n+1; i++){
            dp[i][0] = 1;            
        }// this makes first col with combination 1 

        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<amount+1; j++){
                if(coins[i-1] <= j){ //condn to include the coin (j acts as amount) 
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                }else{ // condn to exclude coin 
                    dp[i][j] = dp[i-1][j];
                }

            }
        }
        return dp[n][amount];
    }

int main(){ 
    vector<int> coins = {1,2,5};
    int amount = 5;

    cout<<change(amount, coins)<<endl;
    return 0; 
}