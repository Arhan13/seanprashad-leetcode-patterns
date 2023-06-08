#include <bits/stdc++.h>
using namespace std;

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