#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

class Solution
{
private:
    int n = 0, m = 0;
    string s = "", p = "";
    map<pi, bool> dp;
    bool dfs(int i, int j)
    {
        if (dp.count({i, j}))
        {
            return dp[{i, j}];
        }
        // Its fine if both of them are out of bounds
        if (i >= n && j >= m)
        {
            return true;
        }
        // If only j is out of bounds and i is not then we have an issue
        if (j >= m)
        {
            return false;
        }
        // Now there is still one case remainig where i can be out of bounds where j is not
        bool match = i < n && (s[i] == p[j] || p[j] == '.');
        // Handle the * case
        if ((j + 1) < m && p[j + 1] == '*')
        {
            // We have two choices when we face the *
            // We don't use the * or We use the star
            dp[{i, j}] = (dfs(i, j + 2) ||
                          (match && dfs(i + 1, j)));
            return dp[{i, j}];
        }
        // Handle
        if (match)
        {
            dp[{i, j}] = dfs(i + 1, j + 1);
            return dp[{i, j}];
        }
        dp[{i, j}] = false;
        return dp[{i, j}];
    }

public:
    bool isMatch(string _s, string _p)
    {
        s = _s;
        p = _p;
        n = s.size();
        m = p.size();
        return dfs(0, 0);
    }
};