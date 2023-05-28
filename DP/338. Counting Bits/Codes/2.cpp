#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 10;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i / 2] + (i % 2);
        cout << "No of set bits in " << i << " = " << dp[i] << endl;
    }
    return 0;
}