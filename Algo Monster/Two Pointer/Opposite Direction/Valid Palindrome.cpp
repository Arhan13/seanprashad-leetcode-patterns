#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string _s = "";
        for (char x : s)
        {
            if (isalnum(x))
            {
                _s.push_back(tolower(x));
            }
        }
        int left = 0;
        int right = _s.size() - 1;
        while (left < right)
        {
            if (_s.at(left) != _s.at(right))
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