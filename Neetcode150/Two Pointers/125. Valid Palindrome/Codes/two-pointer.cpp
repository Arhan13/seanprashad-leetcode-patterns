#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string cleanString = "";
        for (char &c : s)
        {
            if (isalnum(c))
            {
                cleanString += tolower(c);
            }
        }
        int n = cleanString.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            if (cleanString[left] != cleanString[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};