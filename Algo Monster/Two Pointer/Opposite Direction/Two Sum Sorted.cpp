#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int currSum = 0;
        while (left < right)
        {
            currSum = nums.at(left) + nums.at(right);
            if (currSum == target)
            {
                return {left + 1, right + 1};
            }
            if (currSum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return {};
    }
};