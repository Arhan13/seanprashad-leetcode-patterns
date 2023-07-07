#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Count the number of ones in the current window. If we encounter a zero, we will update the max_counter and reset the counter to zero.

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int counter = 0;
        int max_counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                counter++;
                max_counter = max(max_counter, counter);
            }
            else
            {
                max_counter = max(max_counter, counter);
                counter = 0;
            }
        }
        return max_counter;
    }
};