#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> ump;
        int left = 0;
        int right = 0;
        int maxLength = 0;
        while (right < s.size())
        {
            // The element is not in the window, include it in the window
            ump[s[right]]++;
            // Remove the repeating element from the window
            while (ump[s[right]] > 1)
            {
                ump[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};
/*abefah*/