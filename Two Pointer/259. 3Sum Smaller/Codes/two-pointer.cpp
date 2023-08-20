#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumSmaller(vector<int> &nums, int target)
    {
        int ans = 0;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < sz; i++)
        {
            int lo = i + 1;
            int hi = sz - 1;
            while (lo < hi)
            {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum < target)
                {
                    ans += hi - lo;
                    lo++;
                }
                else
                {
                    hi--;
                }
            }
        }
        return ans;
    }
};