#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

int lcs(string a, string b, int i, int j, vector<vector<int>> &memo)
{
    if (i == a.size() && j == b.size())
    {
        return 0;
    }
    if (i == a.size())
    {
        return 0;
    }
    if (j == b.size())
    {
        return 0;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + lcs(a, b, i + 1, j + 1, memo);
    }
    else
    {
        ans = max(lcs(a, b, i + 1, j, memo), lcs(a, b, i, j + 1, memo));
    }
    memo[i][j] = ans;
    return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    vector<vector<int>> memo(a.size() + 1, vector<int>(b.size() + 1, -1));
    cout << lcs(a, b, 0, 0, memo);
    return 0;
}