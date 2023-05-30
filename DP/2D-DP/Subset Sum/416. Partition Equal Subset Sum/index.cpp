#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

// 416. Partition Equal Subset Sum
// DP Pattern : Subset Sum : 2D DP : 0/1 Knapsack
// Gives TLE

bool targetSum(vector<int> &nums, int target, int currentIndex)
{
    if (currentIndex == -1)
    {
        return (target == 0);
    }
    bool ans = false;
    if (target >= nums[currentIndex])
    {
        ans |= targetSum(nums, target - nums[currentIndex], currentIndex - 1);
    }

    ans |= targetSum(nums, target, currentIndex - 1);
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
    return targetSum(nums, target / 2, nums.size() - 1);
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