#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int currentIndex, string s, vector<int> &memo)
    {
        if (s.length() <= currentIndex)
        {
            return 1;
        }
        if (memo[currentIndex] != -1)
        {
            return memo[currentIndex];
        }
        int ans = 0;
        if (s[currentIndex] != '0')
        {
            ans += solve(currentIndex + 1, s, memo);
        }
        if (currentIndex < s.size() - 1 && (s[currentIndex] == '1' || (s[currentIndex] == '2' && s[currentIndex + 1] < '7')))
        {
            ans += solve(currentIndex + 2, s, memo);
        }
        memo[currentIndex] = ans;
        return ans;
    }
    int numDecodings(string s)
    {
        vector<int> memo(s.size(), -1);
        return solve(0, s, memo);
    }
};