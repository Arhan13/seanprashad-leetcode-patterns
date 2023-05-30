#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        int dp[n + 1];
        dp[0] = 0;
        ans.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            // DP[i] = Left Shift + is_odd ? 1 : 0
            // DP[i] = DP[i/2] + i%2
            dp[i] = dp[i / 2] + (i % 2);
            ans.push_back(dp[i]);
        }
        return ans;
    }
};