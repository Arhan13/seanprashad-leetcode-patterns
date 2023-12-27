#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int numberOfWays(int numPeople)
    {
        vector<int> dp(numPeople / 2 + 1);
        dp[0] = 1;
        for (int i = 1; i <= numPeople / 2; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += (1LL * dp[j] * dp[i - j - 1] % MOD);
                dp[i] %= MOD;
            }
        }
        return dp[numPeople / 2];
    }
};