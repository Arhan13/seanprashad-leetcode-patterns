#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<int, int> ump;
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int maxLength = 0;
        while (right < s.size())
        {
            ump[s[right]]++;
            maxCount = max(maxCount, ump[s[right]]);
            int currLength = right - left + 1;
            // We check if the current length - maxCount is greater than k
            if (currLength - maxCount > k)
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