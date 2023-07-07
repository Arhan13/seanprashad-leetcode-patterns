#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Maintain a sliding window. If we encounter a zero, we will update the maxNumberOfOnes and reset the left and right pointers to the current index.

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int maxNumberOfOnes = 0;
        while (right < nums.size())
        {
            if (nums[right] == 1)
            {
                right++;
                maxNumberOfOnes = max(maxNumberOfOnes, right - left);
            }
            else if (nums[right] == 0)
            {
                maxNumberOfOnes = max(maxNumberOfOnes, right - left);
                right++;
                left = right;
            }
        }
        return maxNumberOfOnes;
    }
};