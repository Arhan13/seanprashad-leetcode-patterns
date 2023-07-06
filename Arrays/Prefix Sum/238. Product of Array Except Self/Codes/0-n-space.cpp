#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixArray(n, 1);
        vector<int> suffixArray(n, 1);
        // Filling the prefix array
        for (int i = 1; i < n; i++)
        {
            prefixArray[i] = prefixArray[i - 1] * nums[i - 1];
        }
        // Filling the suffix array
        for (int i = n - 2; i >= 0; i--)
        {
            suffixArray[i] = suffixArray[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            prefixArray[i] *= suffixArray[i];
        }
        return prefixArray;
    }
};