#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
// Intution in one line - We will maintain a sliding window.
// If the sum of the elements in the current window is greater than or equal to the target,
// we will update the minLength and remove the leftmost element from the window.
// If the sum of the elements in the current window is less than the target, we will add the rightmost element to the window.

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int rangeSum = 0;
        int minLength = INT_MAX;
        while (right < nums.size())
        {
            rangeSum += nums[right++];
            while (rangeSum >= target)
            {
                rangeSum -= nums[left++];
                minLength = min(minLength, right - left + 1);
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};