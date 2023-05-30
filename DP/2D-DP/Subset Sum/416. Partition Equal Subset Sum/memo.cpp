#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

// 416. Partition Equal Subset Sum
// DP Pattern : Subset Sum : 2D DP : 0/1 Knapsack
// TC : O(N * target)
// SC : O(N * target)

bool isSubsetSum(vector<int> &nums, int target, int currentIndex, vector<vector<int>> &memo)
{
    if (currentIndex == -1)
    {
        return (target == 0);
    }
    if (memo[currentIndex][target] != -1)
    {
        return memo[currentIndex][target];
    }
    bool ans = false;
    if (target >= nums[currentIndex])
    {
        ans |= isSubsetSum(nums, target - nums[currentIndex], currentIndex - 1, memo);
    }
    ans |= isSubsetSum(nums, target, currentIndex - 1, memo);
    memo[currentIndex][target] = ans;
    return ans;
}
bool canPartition(vector<int> &nums)
{
    int target = 0;
    for (auto x : nums)
    {
        target += x;
    }
    // The target sum cannot be odd
    if (target % 2 != 0)
    {
        return false;
    }
    vector<vector<int>> memo(nums.size(), vector<int>(target / 2 + 1, -1));
    return isSubsetSum(nums, target / 2, nums.size() - 1, memo);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Inputs - we will get sum, size of array and the array
    int n;
    cin >> n;
    vector<int> nums(n, -1);
    // vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << canPartition(nums);
    return 0;
}