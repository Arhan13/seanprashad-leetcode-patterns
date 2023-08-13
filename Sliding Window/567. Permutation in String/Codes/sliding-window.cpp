#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool matches(vector<int> &map1, vector<int> &map2)
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
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }
        for (int i = 0; i < s2.size() - s1.size(); i++)
        {
            // Add and remove the elements from the sliding window
            if (matches(map1, map2))
            {
                return true;
            }
            map2[s2[i] - 'a']--;
            map2[s2[i + s1.size()] - 'a']++;
        }
        return matches(map1, map2);
    }
};