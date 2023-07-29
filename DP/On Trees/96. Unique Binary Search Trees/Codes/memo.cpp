#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dp[20]{};

public:
    int numTrees(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        if (dp[n])
        {
            return dp[n];
        }
        for (int i = 1; i <= n; i++)
        {
            dp[n] += numTrees(i - 1) * numTrees(n - i);
        }
        return dp[n];
    }
};