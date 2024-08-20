#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int n;

public:
    void expandFromMiddle(string &s, int left, int right, int &startIndex, int &maxLen)
    {
        while (left >= 0 && right <= n && s[left] == s[right])
        {
            int currLen = right - left + 1;
            if (currLen > maxLen)
            {
                startIndex = left;
                maxLen = currLen;
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s)
    {
        n = s.size();
        int startIndex = 0;
        int maxLen = 0;
        for (int i = 1; i < n; i++)
        {
            // Even length palindrome
            expandFromMiddle(s, i - 1, i, startIndex, maxLen);
            // Odd length palindrome
            expandFromMiddle(s, i - 1, i + 1, startIndex, maxLen);
        }
        return maxLen > 0 ? s.substr(startIndex, maxLen) : s.substr(startIndex, 1);
    }
};