#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        unordered_map<char, int> ump;
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int maxLength = 0;
        while (right < n)
        {
            ump[s[right]]++;
            int currCount = ump[s[right]];
            maxCount = max(maxCount, currCount);
            int currLen = right - left + 1;
            if (currLen - maxCount > k)
            {
                ump[s[left]]--;
                left++;
            }
            int updatedLength = right - left + 1;
            maxLength = max(maxLength, updatedLength);
            right++;
        }
        return maxLength;
    }
};