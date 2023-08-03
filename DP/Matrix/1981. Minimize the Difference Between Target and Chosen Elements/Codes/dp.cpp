#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        int n = mat.size();
        int m = mat[0].size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sort(mat[i].begin(), mat[i].end());
            sum += mat[i][0];
        }
        vector<vector<bool>> dp(n, vector<bool>(sum * m + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][mat[i][0]] = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = mat[i][j]; k <= sum * m; k++)
                {
                    dp[i][k] = dp[i][k] || dp[i - 1][k - mat[i][j]];
                }
            }
        }
        int ans = INT_MAX;
        for (int k = target; k <= sum * m; k++)
        {
            if (dp[n - 1][k])
            {
                ans = min(ans, abs(k - target));
            }
        }
        return ans;
    }
};