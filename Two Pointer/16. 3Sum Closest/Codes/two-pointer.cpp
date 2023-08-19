#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int diff = INT_MAX;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < sz && diff != 0; i++)
        {
            int lo = i + 1;
            int hi = sz - 1;
            while (lo < hi)
            {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(diff))
                {
                    diff = target - sum;
                }
                if (sum < target)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
            }
        }
        return target - diff;
    }
};