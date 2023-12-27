#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> ump;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int prev = arr[i] - difference;
            if (ump.count(prev))
            {
                ump[arr[i]] = ump[prev] + 1;
            }
            else
            {
                ump[arr[i]] = 1;
            }
            ans = max(ans, ump[arr[i]]);
        }
        return ans;
    }
};