#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> nums, int currentIndex, int lastIndex, unordered_map<int, int> &ump)
    {
        // As indexs in from 0 to nums.size()-1
        // So anything beyond that will be 0
        if (currentIndex >= lastIndex)
        {
            return 0;
        }
        if (ump.find(currentIndex) != ump.end())
        {
            return ump[currentIndex];
        }
        // Now we have two cases
        // Rob the current house
        int rob = nums[currentIndex] + solve(nums, currentIndex + 2, lastIndex, ump);
        int noRob = solve(nums, currentIndex + 1, lastIndex, ump);
        ump[currentIndex] = max(rob, noRob);
        return ump[currentIndex];
    }
    int rob(vector<int> &nums)
    {
        unordered_map<int, int> memo1;
        unordered_map<int, int> memo2;
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        // We calculate from 1st to nth-1
        int val1 = solve(nums, 0, n - 1, memo1);
        // We calculate from 2nd to nth
        int val2 = solve(nums, 1, n, memo2);
        return max(val1, val2);
    }
};