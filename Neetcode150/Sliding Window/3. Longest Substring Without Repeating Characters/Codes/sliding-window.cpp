#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC - O(n)
    // SC - O(n)
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        unordered_map<char, int> ump;
        int left = 0;
        int right = 0;
        int maxLen = INT_MIN;
        while (right < n)
        {
            char rightChar = s.at(right);
            ump[rightChar]++;
            while (ump[rightChar] > 1)
            {
                ump[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};