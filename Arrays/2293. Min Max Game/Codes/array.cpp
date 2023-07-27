#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &nums, int n)
    {
        if (n == 1)
        {
            return nums[0];
        }
        for (int i = 0; i < n / 2; i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
            else
            {
                nums[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
        }
        return helper(nums, n / 2);
    }

public:
    int minMaxGame(vector<int> &nums)
    {
        int n = nums.size();
        return helper(nums, n);
    }
};