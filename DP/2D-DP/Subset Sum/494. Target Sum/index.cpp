#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

// 494. Target Sum

int dfs(vector<int> &nums, int target, int currentIndex)
{
    // Base conditions
    if (currentIndex == -1)
    {
        return (target == 0) ? 1 : 0;
    }
    if (currentIndex == -1)
    {
        return 0;
    }
    int possitive = dfs(nums, target + nums[currentIndex], currentIndex - 1);
    int negative = dfs(nums, target - nums[currentIndex], currentIndex - 1);

    return possitive + negative;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int currentIndex = nums.size() - 1;
    return dfs(nums, target, currentIndex);
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Inputs - we will get sum, size of array and the array
    int target, n;
    cin >> target >> n;
    vector<int> nums(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}