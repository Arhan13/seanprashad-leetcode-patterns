#include <bits/stdc++.h>
using namespace std;

// Is this top down or bottom up?
// This is bottom up
// Why is this bottom up?
// Because we are starting from the base case and then going up

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // dp(i, 0) = Max value that we will get if we don't rob the house
        // dp(i, 0) = max(dp(i+1, 0), dp(i+1, 1)) --> Equation 1
        // dp(i, 1) = Max value that we will get if we rob the house
        // dp(i, 1) = dp(i+1, 0) + nums[i] --> Equation 2
        // On applying Eq 1 in Eq 2
        // dp(i, 1) = max(dp(i+2, 0), dp(i+2, 1)) + nums[i]
        // dp(i) = Gives the max value if I select or don't select ith element
        // dp(i) = max(dp(i, 0), dp(i, 1))
        // dp(i) = max(dp(i+1), dp(i+2) + nums[i])
        int N = nums.size();
        if (N == 0)
        {
            return 0;
        }
        if (N == 1)
        {
            return nums[0];
        }
        int dp[N];
        // We get maximum value for the last house when we pick it
        dp[N - 1] = nums[N - 1];
        // For the 2nd last house we will either pick it or the max value that the last house returns
        dp[N - 2] = max(nums[N - 2], dp[N - 1]);
        for (int i = N - 3; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
        }
        return dp[0];
    }
};