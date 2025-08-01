#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i <= n; i++)
        {
            int gain = i == n ? 0 : nums[i];
            dp[i] = max(dp[i - 1], dp[i - 2] + gain);
        }
        return dp[n];
    }
};