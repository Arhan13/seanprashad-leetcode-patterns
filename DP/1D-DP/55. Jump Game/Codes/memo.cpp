#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int currentIndex, vector<int> &nums, vector<int> &memo)
    {
        if (currentIndex == nums.size() - 1)
        {
            return true;
        }
        if (memo[currentIndex] != -1)
        {
            return memo[currentIndex] == 1 ? true : false;
        }
        bool ans = false;
        for (int i = 1; i <= nums[currentIndex]; i++)
        {
            if (currentIndex + i < nums.size())
            {
                ans |= solve(currentIndex + i, nums, memo);
            }
        }
        ans ? memo[currentIndex] = 1 : memo[currentIndex] = 0;
        return ans;
    }
    bool canJump(vector<int> &nums)
    {
        vector<int> memo(nums.size() + 1, -1);
        return solve(0, nums, memo);
    }
};