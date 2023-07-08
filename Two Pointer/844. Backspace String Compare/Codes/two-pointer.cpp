#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeBackspaceString(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i != 0 && s[i] == '#')
            {
                s.erase(i - 1, 2);
                i -= 2;
            }
            else if (i == 0 && s[i] == '#')
            {
                s.erase(i, 1);
                i--;
            }
        }
        return s;
    }
    bool backspaceCompare(string s, string t)
    {
        return removeBackspaceString(s) == removeBackspaceString(t);
    }
};