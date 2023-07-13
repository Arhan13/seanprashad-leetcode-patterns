#include <bits/stdc++.h>
using namespace std;

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
            for (int j = 0; j < nums.size(); j++)
            {
                dp[currentSum] += dp.count(currentSum - nums[j]) > 0 ? dp[currentSum - nums[j]] : 0;
            }
        }
        return dp[target];
    }
};