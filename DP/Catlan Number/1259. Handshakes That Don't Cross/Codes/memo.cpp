#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int numberOfWays(int numPeople)
    {
        vector<int> dp(numPeople + 1, 0);
        function<int(int)> countWays = [&](int n)
        {
            if (n < 2)
            {
                return 1;
            }
            if (dp[n] != 0)
            {
                return dp[n];
            }
            for (int left = 0; left < n; left += 2)
            {
                int right = n - 2 - left;
                dp[n] += (1L * countWays(left) * countWays(right) % MOD);
                dp[n] %= MOD;
            }
            return dp[n];
        };
        return countWays(numPeople);
    }
};