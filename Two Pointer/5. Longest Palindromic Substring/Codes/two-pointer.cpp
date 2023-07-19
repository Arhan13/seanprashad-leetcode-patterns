#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void handleMaxLength(int i, int j, string &s, int &maxLength, int &startIndex)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            if (j - i + 1 > maxLength)
            {
                maxLength = j - i + 1;
                startIndex = i;
            }
            i--;
            j++;
        }
    }

public:
    string longestPalindrome(string s)
    {
        int i = 0;
        int j = 0;
        int maxLength = 0;
        int startIndex = 0;
        for (int curr = 1; curr < s.size(); curr++)
        {
            // Lets start with two pointers that start in the middle and then spread
            handleMaxLength(curr - 1, curr, s, maxLength, startIndex);
            // Lets start with two pointers around an element in the middle and then spread out
            handleMaxLength(curr - 1, curr + 1, s, maxLength, startIndex);
        }
        return maxLength > 0 ? s.substr(startIndex, maxLength) : s.substr(startIndex, 1);
    }
};