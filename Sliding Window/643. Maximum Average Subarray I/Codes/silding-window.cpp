#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Reason for O(n) time complexity: We are using sliding window technique and we are iterating over the array only once.
// Space Complexity: O(1)
// Reason for O(1) space complexity: We are not using any extra space.
// One line intuition:
// Find the sum of first k elements and then slide the window by adding the next element and removing the first element from the window and keep track of the maximum sum.

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        double ans = INT_MIN;
        int i = 0;
        int j = i + k - 1;
        // We maintain a window of size k and find the sum of the elements in the window and divide it by k to get the average.
        double rangeSum = 0;
        for (int it = i; it <= j; it++)
        {
            rangeSum += nums[it];
        }
        ans = rangeSum / k;
        while (j < n)
        {
            // We slide the window by adding the next element and removing the first element from the window and keep track of the maximum sum.
            rangeSum -= nums[i++];
            rangeSum += nums[++j];
            ans = max(ans, rangeSum / k);
        }
        return ans;
    }
};