#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> nums, int currentIndex, unordered_map<int, int> &ump)
    {
        // As indexs in from 0 to nums.size()-1
        // So anything beyond that will be 0
        if (currentIndex >= nums.size())
        {
            return 0;
        }
        if (ump.find(currentIndex) != ump.end())
        {
            return ump[currentIndex];
        }
        // Now we have two cases
        // Rob the current house
        int rob = nums[currentIndex] + solve(nums, currentIndex + 2, ump);
        int noRob = solve(nums, currentIndex + 1, ump);
        int maxValue = max(rob, noRob);
        ump[currentIndex] = maxValue;
        return maxValue;
    }
    int rob(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        return solve(nums, 0, ump);
    }
};