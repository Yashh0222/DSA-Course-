#include<iostream>
#include<vector>
using namespace std;

int countWaysToClimbaSteps(int n){
    if (n==0 || n==1) 
    {
        return 1;
    }
    // finding ways if we can climb 1 step or 2 steps at a time 
    return countWaysToClimbaSteps(n-1) + countWaysToClimbaSteps(n-2);
    // above recursive call finds no of ways 
}

// solution using Dp 
int countWaysToClimbaStepsUsingDP(int n, vector<int> &dp){
    if (n==0 || n==1) 
    {
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }
    // finding ways if we can climb 1 step or 2 steps at a time 

    dp[n] = countWaysToClimbaStepsUsingDP(n-1,dp) + countWaysToClimbaStepsUsingDP(n-2, dp);
    return dp[n];
    // above recursive call finds no of ways 
}

//using tabulation
int countWaysToClimbStepsUsingTabulation(int n){ // if we can take only 1 & 2 jumps  
    vector<int> ways(n+1, 0);

    ways[0] = 1;
    ways[1] = 1;

    for (int i = 2; i <= n ; i++)
    {
        ways[i] = ways[i-1] + ways[i-2];

    }

    return ways[n];
    
}
// includes climbing 1, 2 , 3 steps
int countWaysToClimbStepsUsingTabulation3(int n){
    vector<int> ways(n+1, 0);

    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        ways[i] = ways[i-1] + ways[i-2] + ways[i-3];
    }
    return ways[n];
}
int main(){ 
    int n = 4;   
    vector<int> dp(n+1 , -1);
    cout<<countWaysToClimbaSteps(n)<<endl;
    cout<<countWaysToClimbaStepsUsingDP(n, dp)<<endl;
    cout<<countWaysToClimbStepsUsingTabulation(n)<<endl;

    cout<<"for 1,2,3 steps "<<countWaysToClimbStepsUsingTabulation3(n)<<endl;

    return 0; 
}