#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

const int N = 1000;
int a[N], n;
vector<vector<int>> memo;

// TC - O(N*sum) - N is the size of the array and sum is the sum we want to achieve
// SC - O(N*sum) - N is the size of the array and sum is the sum we want to achieve
// DP Pattern - 0/1 Knapsack
//  Sumset Sum Problem with memoization

bool subsetSum(int index, int sum)
{
    // no elements left for sum
    if (index == -1)
    {
        return (sum == 0);
    }
    if (memo[index][sum] != -1)
    {
        return memo[index][sum];
    }
    int ans = false;
    // Include a[index]
    if (sum >= a[index])
    {
        ans |= subsetSum(index - 1, sum - a[index]);
    }
    // Exclude a[index]
    ans |= subsetSum(index - 1, sum);
    memo[index][sum] = ans;
    return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Inputs - we will get sum, size of array and the array
    int sum, n;
    cin >> sum >> n;
    memo.resize(n + 1, vector<int>(sum + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << subsetSum(n - 1, sum) << endl;
    return 0;
}