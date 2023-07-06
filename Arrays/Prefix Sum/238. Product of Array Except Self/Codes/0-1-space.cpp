#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixArray(n, 1);
        int previousSuffix = 1;
        // Filling the prefix array
        for (int i = 1; i < n; i++)
        {
            prefixArray[i] = prefixArray[i - 1] * nums[i - 1];
        }
        // Filling the suffix array
        for (int i = n - 2; i >= 0; i--)
        {
            previousSuffix = previousSuffix * nums[i + 1];
            prefixArray[i] = prefixArray[i] * previousSuffix;
        }
        return prefixArray;
    }
};