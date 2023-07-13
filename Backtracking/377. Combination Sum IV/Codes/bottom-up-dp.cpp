#include <bits/stdc++.h>
using namespace std;

// Is this top down or bottom up DP?
//   This is bottom up DP because we are solving the subproblems first and then using them to solve the bigger problems

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // We know the base case that dp[0] = 1
        unordered_map<int, double> dp;
        dp[0] = 1;
        for (int currentSum = 1; currentSum <= target; currentSum++)
        {
            // Iterate over all the numbers in nums
            // Because we can use the same number multiple times, we need to iterate over all the numbers in nums
            for (int j = 0; j < nums.size(); j++)
            {
                // Recurrence relation
                //  dp[currentSum] = dp[currentSum - nums[j]] + dp[currentSum]
                dp[currentSum] += dp.count(currentSum - nums[j]) > 0 ? dp[currentSum - nums[j]] : 0;
            }
        }
        return dp[target];
    }
};