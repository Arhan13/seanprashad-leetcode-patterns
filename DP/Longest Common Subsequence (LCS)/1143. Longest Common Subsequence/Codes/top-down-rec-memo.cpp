#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &memo, string &text1, string &text2, int text1Index, int text2Index)
    {
        if (text1Index == text1.size() && text2Index == text2.size())
        {
            return 0;
        }
        if (text1Index == text1.size() || text2Index == text2.size())
        {
            return 0;
        }
        if (memo[text1Index][text2Index] != -1)
        {
            return memo[text1Index][text2Index];
        }
        int ans = 0;
        if (text1[text1Index] == text2[text2Index])
        {
            ans = 1 + solve(memo, text1, text2, text1Index + 1, text2Index + 1);
        }
        else
        {
            ans = max(solve(memo, text1, text2, text1Index + 1, text2Index), solve(memo, text1, text2, text1Index, text2Index + 1));
        }
        memo[text1Index][text2Index] = ans;
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        // Bottom up approach
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return solve(memo, text1, text2, 0, 0);
    }
};