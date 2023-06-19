#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)

// Approach: Using two pointers
//  1. Initialize two pointers left and right at the start and end of the array respectively
//  2. Initialize a variable ans to store the maximum area
//  3. Traverse the array and check if the height of the left pointer is less than the height of the right pointer
//  4. If yes, then update the ans and increment the left pointer
//  5. Else, update the ans and decrement the right pointer
//  6. Return the ans

// Intution : We are using two pointers because we want to find the maximum area
//            So, we will initialize two pointers left and right at the start and end of the array respectively
//            and we will traverse the array and check if the height of the left pointer is less than the height of the right pointer
//            If yes, then we will update the ans and increment the left pointer
//            Else, we will update the ans and decrement the right pointer
//            So, at the end, we will return the ans

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
            {
                left++;
            }
            else if (height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return ans;
    }
};