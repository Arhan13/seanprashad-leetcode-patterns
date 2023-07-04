#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
// dp[i] = max(0, dp[i-1]) + nums[i]
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currentSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            currentSum = max(0, currentSum) + nums[i];
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
