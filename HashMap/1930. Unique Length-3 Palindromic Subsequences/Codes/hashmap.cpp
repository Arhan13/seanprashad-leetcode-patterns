#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> first(26, 100001);
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
        {
            first[s[i] - 'a'] = min(i, first[s[i] - 'a']);
            last[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            unordered_set<int> ust;
            for (int j = first[i] + 1; j < last[i]; j++)
            {
                ust.insert(s[j] - 'a');
            }
            ans += ust.size();
        }
        return ans;
    }
};