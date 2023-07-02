#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = *max_element(nums.begin(), nums.end());
        int currentMax = 1;
        int currentMin = 1;
        for (auto x : nums)
        {
            if (x == 0)
            {
                currentMax = 1;
                currentMin = 1;
            }
            else
            {
                int tempMin = x * currentMin;
                int tempMax = x * currentMax;
                currentMax = max(tempMax, max(tempMin, x));
                currentMin = min(tempMax, min(tempMin, x));
                ans = max(ans, currentMax);
            }
        }
        return ans;
    }
};