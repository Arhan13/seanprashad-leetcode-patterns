#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vi ans = {};
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int currSum = nums[left] + nums[right];
            if (currSum == target)
            {
                return {left + 1, right + 1};
            }
            if (currSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {};
    }
};