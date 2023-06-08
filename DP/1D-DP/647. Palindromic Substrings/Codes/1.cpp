#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPali(int left, int right, string s)
    {
        int ans = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            ans++;
            left--;
            right++;
        }
        return ans;
    }
    int countSubstrings(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int left = i;
            int right = i;
            ans += countPali(i, i, s);
            ans += countPali(i, i + 1, s);
        }
        return ans;
    }
};