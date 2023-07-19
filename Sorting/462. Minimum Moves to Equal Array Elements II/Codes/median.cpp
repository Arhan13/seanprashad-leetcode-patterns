#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = n % 2 == 0 ? (nums[n / 2] + nums[n / 2 - 1]) / 2 : nums[n / 2];
        int i = 0;
        int j = n - 1;
        int moves = 0;
        while (i < j)
        {
            moves += median - nums[i];
            moves += nums[j] - median;
            i++;
            j--;
        }
        return moves;
    }
};