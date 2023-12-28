#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int kMax = 101;
    vector<vector<int>> dp;

    int compression(string &s, int i, int k)
    {
        // if k is less than equal to 0
        if (k < 0)
        {
            return kMax;
        }
        if (i == s.length() || s.length() - i <= k)
        {
            return 0;
        }
        if (dp[i][k] != kMax)
        {
            return dp[i][k];
        }
        int maxFreq = 0;
        vector<int> counter(128, 0);
        for (int j = i; j < s.length(); j++)
        {
            maxFreq = max(maxFreq, ++counter[s[j]]);
            dp[i][k] = min(
                dp[i][k],
                getLength(maxFreq) + compression(s, j + 1, k - (j - i + 1 - maxFreq)));
        }
        return dp[i][k];
    }

    int getLength(int maxFreq)
    {
        if (maxFreq == 1)
        {
            return 1;
        }
        if (maxFreq < 10)
        {
            return 2;
        }
        if (maxFreq < 100)
        {
            return 3;
        }
        return 4;
    }

public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        dp.resize(s.length(), vector<int>(k + 1, kMax));
        return compression(s, 0, k);
    }
};