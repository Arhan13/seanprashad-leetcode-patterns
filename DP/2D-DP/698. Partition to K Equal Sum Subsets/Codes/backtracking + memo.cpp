/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{

private:
    bool backtracking(vector<int> &nums, int subsets, int currentSum, int targetSum, int currentIndex, string &taken, unordered_map<string, bool> &memo)
    {
        // Base case
        if (subsets == 1)
        {
            return true;
        }
        if (currentSum > targetSum)
        {
            return false;
        }
        // If we have already computed the current combination
        if (memo.find(taken) != memo.end())
        {
            return memo[taken];
        }
        if (currentSum == targetSum)
        {
            memo[taken] = backtracking(nums, subsets - 1, 0, targetSum, 0, taken, memo);
            return memo[taken];
        }
        // Now we iterate over all the elements in the nums array
        for (int i = currentIndex; i < nums.size(); i++)
        {
            if (taken[i] == '0' && currentSum + nums[i] <= targetSum)
            {
                taken[i] = '1';
                if (backtracking(nums, subsets, currentSum + nums[i], targetSum, i + 1, taken, memo))
                {
                    return true;
                }
                taken[i] = '0';
            }
        }
        return memo[taken] = false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
        {
            return false;
        }
        int targetSum = sum / k;
        int subsets = k;
        int currentSum = 0;
        // New memoization try
        unordered_map<string, bool> memo;
        // Memoize the ans using taken elements as a key
        string taken(nums.size(), '0');
        return backtracking(nums, subsets, 0, targetSum, 0, taken, memo);
    }
};
// @lc code=end
