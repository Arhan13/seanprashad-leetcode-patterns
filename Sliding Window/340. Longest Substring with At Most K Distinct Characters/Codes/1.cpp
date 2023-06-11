#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        unordered_map<int, int> ump;
        int right = 0;
        int left = 0;
        int maxLength = 0;
        while (right < s.size())
        {
            // Increment the frequency of each character in the window
            ump[s[right]]++;
            // We we cross the max length of k elemnets, we will remove elements from the left of the window
            while (ump.size() > k)
            {
                ump[s[left]]--;
                if (ump[s[left]] == 0)
                {
                    ump.erase(s[left]);
                }
                left++;
            }
            // Set the max length of the window
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};