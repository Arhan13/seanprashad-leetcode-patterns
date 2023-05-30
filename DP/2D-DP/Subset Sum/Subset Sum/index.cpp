#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

const int N = 1000;
int a[N], n;
// Sumset Sum Problem
bool subsetSum(int index, int sum)
{
    // no elements left for sum
    if (index == -1)
    {
        return (sum == 0);
    }
    int ans = false;
    // Include a[index]
    if (sum >= a[index])
    {
        ans |= subsetSum(index - 1, sum - a[index]);
    }
    // Exclude a[index]
    ans |= subsetSum(index - 1, sum);
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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << subsetSum(n - 1, sum) << endl;
    return 0;
}