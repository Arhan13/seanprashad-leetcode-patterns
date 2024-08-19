#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int lenS = s.size();
        int lenT = t.size();
        if (lenS < lenT)
        {
            return "";
        }
        int minStartIndex = -1;
        int minLen = INT_MAX;
        int right = 0;
        int left = 0;
        int missing = lenT;

        unordered_map<int, int> freq, count;
        for (char &c : t)
        {
            freq[c]++;
        }
        while (right < lenS)
        {
            // If the current element exists in t
            if (freq[s[right]] > 0)
            {
                count[s[right]]++;
                if (count[s[right]] <= freq[s[right]])
                {
                    missing--;
                }
            }
            right++;
            while (missing == 0)
            {
                // Check if the current window is the smallest
                if (right - left < minLen)
                {
                    minLen = right - left;
                    minStartIndex = left;
                }
                // Now decrease the window till we get a missing char
                if (freq[s[left]] > 0)
                {
                    // As we are removing the element out of the window
                    count[s[left]]--;
                    if (count[s[left]] < freq[s[left]])
                    {
                        missing++;
                    }
                }
                left++;
            }
        }
        return minStartIndex == -1 ? "" : s.substr(minStartIndex, minLen);
    }
};