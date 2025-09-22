#include <iostream>
#include <vector>
using namespace std;

bool targetSum(vector<int> nums, int target)
{
    int n = nums.size();

    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (nums[i - 1] <= j)
            {
                dp[i][j] = max(nums[i - 1] + dp[i - 1][j - nums[i - 1]], dp[i - 1][j]);

                if (dp[i][j] == target)
                {
                    ans++;
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[n][target] == target)
    {
        ans++;
    }
    return ans;
    // return dp[n][target] == target;
}
int main()
{
     vector<int> nums = {4,2,7,1,3};
    //vector<int> nums = {1, 1, 1, 1, 1};
    int target = 7;

    cout << targetSum(nums, target) << endl;
    return 0;
}