#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution
{
private:
    void reverse(vi &nums, int left, int right)
    {
        while (left < right)
        {
            int tempLeft = nums[left];
            nums[left] = nums[right];
            nums[right] = tempLeft;
            left++;
            right--;
        }
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
        {
            return;
        }
        k = k % (n);
        // We will reverse the array and then reverse in groups of k
        int left = 0;
        int right = nums.size();
        reverse(nums, 0, n - 1);
        // We will reverse in group of 0, k-1
        reverse(nums, 0, k - 1);
        // Reverse in group of k, n-1
        reverse(nums, k, n - 1);
        return;
    }
};