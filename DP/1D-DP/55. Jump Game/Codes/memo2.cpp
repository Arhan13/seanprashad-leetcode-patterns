#include <bits/stdc++.h>
using namespace std;

// DP Patterns - 1D DP - 55. Jump Game
// https://leetcode.com/problems/jump-game/
// Recurence Relation - dp[i] = dp[i+1] || dp[i+2] || ... || dp[i+nums[i]]
// Base Case - dp[n-1] = true
// Answer - dp[0]
// Time Complexity - O(n^2)
// Space Complexity - O(n)
// Better Solution - Greedy
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution
{
public:
    bool solve(int currentIndex, vector<int> &nums, vector<int> &memo)
    {
        if (memo[currentIndex] != -1)
        {
            return memo[currentIndex] == 1 ? true : false;
        }
        bool ans = false;
        int farthestJump = min(currentIndex + nums[currentIndex], (int)nums.size() - 1);
        for (int i = currentIndex + 1; i <= farthestJump; i++)
        {
            if (solve(i, nums, memo))
            {
                memo[currentIndex] = 1;
                return true;
            }
        }
        memo[currentIndex] = 0;
        return false;
    }
    bool canJump(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        memo[nums.size() - 1] = 1;
        return solve(0, nums, memo);
    }
};