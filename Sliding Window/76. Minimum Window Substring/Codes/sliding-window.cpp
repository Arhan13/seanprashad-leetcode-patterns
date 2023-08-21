#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int sLength = s.size();
        int tLength = t.size();
        if (sLength < tLength)
        {
            return "";
        }
        int right = 0;
        int left = 0;
        int minLen = INT_MAX;
        int minStart = -1;
        int missing = tLength;
        unordered_map<int, int> freq, count;
        for (auto i : t)
        {
            freq[i]++;
        }
        while (right < sLength)
        {
            // We need to include the right most element
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
                // We need to check if this window is the smallest
                if (right - left < minLen)
                {
                    minLen = right - left;
                    minStart = left;
                }
                // We will move the left pointer
                if (freq[s[left]] > 0)
                {
                    count[s[left]]--;
                    if (count[s[left]] < freq[s[left]])
                    {
                        missing++;
                    }
                }
                left++;
            }
        }
        return minStart == -1 ? "" : s.substr(minStart, minLen);
    }
};