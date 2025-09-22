// mountain ranges can also be solved using catalan no logic 
#include <iostream>
#include <vector>
using namespace std;

int catalanRec(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // for i=1      c1       * (4-1-1) c2            ex: c2->2
        ans += catalanRec(i) * catalanRec(n - i - 1);
    }

    return ans;
} 

int catalanMemo(int n, vector<int> &dp) 
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        
        ans += catalanMemo(i, dp) * catalanMemo(n - i - 1, dp);
    }

    return dp[n] = ans ;
}

int catalanTabulation(int n) 
{
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <n+1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i-j-1];
        }
        
    }
    return dp[n];
}
int main()
{

    int n = 6;
    //vector<int> dp(n+1 , -1);
    for (int i = 0; i <= 6; i++)
    {
        //cout << catalanMemo(i, dp) << " ";
        cout << catalanTabulation(i) << " ";
       
    }
    
    return 0;
}