#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        unordered_map<char, int> ump;
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int k = 2;
        while (right < s.size())
        {
            ump[s[right]]++;
            while (ump.size() > k)
            {
                ump[s[left]]--;
                if (ump[s[left]] == 0)
                {
                    ump.erase(s[left]);
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};