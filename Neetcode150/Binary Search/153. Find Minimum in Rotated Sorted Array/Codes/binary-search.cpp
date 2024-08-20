#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size(); // Get the size of the input array
        int l = 0;           // Initialize the left pointer to the start of the array
        int r = n - 1;       // Initialize the right pointer to the end of the array
        int ans = nums[0];   // Initialize the answer with the first element of the array

        // Start a binary search loop that continues as long as the left pointer is less than or equal to the right pointer
        while (l <= r)
        {
            // If the subarray between l and r is already sorted (i.e., the leftmost element is less than the rightmost),
            // then the minimum element in this subarray is nums[l], so update the answer and break out of the loop.
            if (nums[l] < nums[r])
            {
                ans = min(ans, nums[l]);
                break;
            }

            // Calculate the midpoint of the current subarray to divide the array into two halves
            int mid = l + (r - l) / 2;

            // Update the answer to the minimum of the current answer and the element at the midpoint
            ans = min(ans, nums[mid]);

            // Determine which part of the array to search next
            if (nums[mid] >= nums[l])
            {
                // If the element at the midpoint is greater than or equal to the element at the left pointer,
                // it means the left side (from l to mid) is sorted, and the minimum must be in the right side.
                l = mid + 1; // Move the left pointer to mid + 1 to search in the right half
            }
            else
            {
                // If the element at the midpoint is less than the element at the left pointer,
                // it means the right side (from mid to r) is not sorted, and the minimum must be in the left side.
                r = mid - 1; // Move the right pointer to mid - 1 to search in the left half
            }
        }
        return ans; // Return the minimum element found
    }
};