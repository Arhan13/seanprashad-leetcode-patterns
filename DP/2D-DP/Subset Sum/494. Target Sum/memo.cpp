#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

// 494. Target Sum

int dfs(vector<int> &nums, int target, int currentIndex, vector<vector<int>> &memo)
{
    // Base conditions
    // If we reach the end of the tree, we check if the target is 0 or not
    if (currentIndex == -1)
    {
        return (target == 0) ? 1 : 0;
    }
    // If the result is already present in the memo, we return it
    if (memo[currentIndex][target + 2000] != -1)
    {
        return memo[currentIndex][target + 2000];
    }
    // We can either add the current element or subtract it from the target
    // If we add it
    int possitive = dfs(nums, target + nums[currentIndex], currentIndex - 1, memo);
    // If we subtract it
    int negative = dfs(nums, target - nums[currentIndex], currentIndex - 1, memo);
    // We add 2000 to the target because the target can be negative as well
    // Store the result in the memo
    memo[currentIndex][target + 2000] = possitive + negative;
    return memo[currentIndex][target + 2000];
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int currentIndex = nums.size() - 1;
    // We keep size of the memo as 2001 because the target can be negative as well
    vector<vector<int>> memo(nums.size(), vector<int>(4001, -1));
    return dfs(nums, target, currentIndex, memo);
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