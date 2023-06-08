#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;
        for (int currentIndex = nums.size() - 2; currentIndex >= 0; currentIndex--)
        {
            int farthestJump = min(currentIndex + nums[currentIndex], (int)nums.size() - 1);
            for (int i = currentIndex + 1; i <= farthestJump; i++)
            {
                if (dp[i])
                {
                    dp[currentIndex] = true;
                }
            }
        }
        return dp[0];
    }
};