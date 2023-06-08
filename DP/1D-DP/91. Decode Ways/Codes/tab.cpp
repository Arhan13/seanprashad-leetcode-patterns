#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int currentIndex, string s, vector<int> &tab)
    {
        for (int i = currentIndex; i >= 0; i--)
        {
            int ans = 0;
            if (s[i] != '0')
            {
                tab[i] += tab[i + 1];
            }
            if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
            {
                tab[i] += tab[i + 2];
            }
        }
        return tab[0];
    }
    int numDecodings(string s)
    {
        vector<int> tab(s.size() + 1, 0);
        tab[s.size()] = 1;
        return solve(s.size() - 1, s, tab);
    }
};