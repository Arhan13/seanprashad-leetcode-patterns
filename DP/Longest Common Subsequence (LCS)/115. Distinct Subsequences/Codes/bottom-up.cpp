#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dp;
    int dfs(int i, int j, string &s, string &t)
    {
        if (j == t.length())
        { // When t is empty
            return 1;
        }
        if (i == s.length())
        { // When s is empty
            return 0;
        }
        if (dp[i][j] != INT_MIN)
        {
            return dp[i][j];
        }
        if (s[i] == t[j])
        {
            dp[i][j] = dfs(i + 1, j + 1, s, t) + dfs(i + 1, j, s, t);
        }
        else
        {
            dp[i][j] = dfs(i + 1, j, s, t);
        }
        return dp[i][j];
    }

public:
    int numDistinct(string s, string t)
    {
        dp.resize(s.length() + 1, vector<int>(t.size() + 1, INT_MIN));
        return dfs(0, 0, s, t);
    }
};