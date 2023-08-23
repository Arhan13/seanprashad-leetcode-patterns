#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    pair<int, int> count1And0(string s)
    {
        int zero = 0;
        int one = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                zero++;
            }
            else if (s[i] == '1')
            {
                one++;
            }
        }
        return make_pair(zero, one);
    }
    int dfs(vector<string> &strs, int currM, int currN, int currIndex, vector<vector<vector<int>>> &memo)
    {
        if (currIndex >= strs.size())
        {
            return 0;
        }
        if (currM < 0 || currN < 0)
        {
            return 0;
        }
        if (memo[currIndex][currM][currN] != -1)
        {
            return memo[currIndex][currM][currN];
        }
        // We either pick the element or we skip it
        int takeCurr = 0;
        int skipCurr = 0;

        // Can we even pick the element
        pair<int, int> curr10Count = count1And0(strs[currIndex]);
        if (currM - curr10Count.first >= 0 && currN - curr10Count.second >= 0)
        {
            takeCurr += 1 + dfs(strs, currM - curr10Count.first, currN - curr10Count.second, currIndex + 1, memo);
        }
        skipCurr += dfs(strs, currM, currN, currIndex + 1, memo);
        return memo[currIndex][currM][currN] = max(takeCurr, skipCurr);
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<vector<int>>> memo(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(strs, m, n, 0, memo);
    }
};