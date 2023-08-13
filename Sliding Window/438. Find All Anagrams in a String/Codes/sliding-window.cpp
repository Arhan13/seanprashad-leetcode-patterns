#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool matches(vector<int> map1, vector<int> map2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (map1[i] != map2[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (p.size() > s.size())
        {
            return ans;
        }
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        for (int i = 0; i < p.size(); i++)
        {
            map1[p[i] - 'a']++;
            map2[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size() - p.size(); i++)
        {
            if (matches(map1, map2))
            {
                ans.push_back(i);
            }
            // Remove and add elements of strig 's' according to the index 'i'
            map2[s[i] - 'a']--;
            map2[s[i + p.size()] - 'a']++;
        }
        if (matches(map1, map2))
        {
            ans.push_back(s.size() - p.size());
        }
        return ans;
    }
};