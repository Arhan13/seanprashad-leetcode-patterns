#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return 0;
        }
        int ans = 0;
        vector<map<long long, int>> dp(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long diff = (long long)nums[i] - (long long)nums[j];
                int prev = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += prev + 1;
                ans += prev;
            }
        }
        return ans;
    }
};