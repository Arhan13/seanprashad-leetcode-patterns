#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int n = 0;
    int m = 0;

public:
    int minDistance(string word1, string word2)
    {
        n = word1.size();
        m = word2.size();
        if (n == 0 && m == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // Handeling the base cases where one of the strings is ""
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(
                                       // insert
                                       dp[i][j - 1], min(
                                                         // delete
                                                         dp[i - 1][j],
                                                         // replace
                                                         dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};