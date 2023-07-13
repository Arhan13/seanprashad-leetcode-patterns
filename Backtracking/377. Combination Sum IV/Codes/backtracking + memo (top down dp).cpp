#include <bits/stdc++.h>
using namespace std;

// Is this top down or bottom up DP?
//  This is top down DP because we are using memoization to store the results of the subproblems

// Is tabluation bottom up DP?
//   Yes, tabulation is bottom up DP because we are solving the subproblems first and then using them to solve the bigger problems

// Time Complexity: O(n*target)
// Space Complexity: O(target)
// One line intution : We have to find all the combinations of k numbers that add up to a number n, where only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

class Solution
{
public:
    int backtracking(vector<int> &nums, int target, int currentSum, unordered_map<int, int> &memo)
    {
        if (currentSum == target)
        {
            // We return 1 because we have found a valid combination
            return 1;
        }
        if (memo.count(currentSum))
        {
            return memo[currentSum];
        }
        int _ans = 0;
        // Now we need to iterate over all the numbers in nums
        for (int i = 0; i < nums.size(); i++)
        {
            if (currentSum + nums[i] <= target)
            {
                _ans += backtracking(nums, target, currentSum + nums[i], memo);
            }
        }
        memo[currentSum] = _ans;
        return _ans;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return 0;
        }
        unordered_map<int, int> memo;
        return backtracking(nums, target, 0, memo);
    }
};