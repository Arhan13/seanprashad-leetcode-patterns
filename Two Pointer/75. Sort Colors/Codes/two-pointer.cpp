#include <bits/stdc++.h>
using namespace std;

// Also known as Dutch National Flag Algorithm
// https://en.wikipedia.org/wiki/Dutch_national_flag_problem
// Time Complexity: O(n)
// Space Complexity: O(1)
// One line explanation: We will need 3 pointer for the 3 colors1

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // We will need 3 pointer for the 3 colors
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;
        while (mid <= right)
        {
            int color = nums[mid];
            switch (color)
            {
            case 0:
                swap(nums[mid], nums[left]);
                left++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[right]);
                right--;
                break;
            }
        }
    }
};