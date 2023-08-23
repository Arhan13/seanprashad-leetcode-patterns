#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int backtracking(vector<int> &nums, int target, int currentSum, unordered_map<int, int> &memo)
    {
        if (currentSum > target)
        {
            return 0;
        }
        if (currentSum == target)
        {
            return 1;
        }
        if (memo.count(currentSum) > 0)
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
        int currentSum = 0;
        return backtracking(nums, target, currentSum, memo);
    }
};