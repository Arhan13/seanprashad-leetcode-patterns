
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Solution
{
private:
    bool matches(vi &map1, vi &map2)
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
        int n = s1.size();
        int m = s2.size();

        if (n > m)
        {
            return false;
        }

        vi map1(26, 0);
        vi map2(26, 0);

        for (int i = 0; i < n; i++)
        {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }

        for (int i = 0; i < m - n; i++)
        {
            if (matches(map1, map2))
            {
                return true;
            }
            map2[s2[i] - 'a']--;
            map2[s2[i + n] - 'a']++;
        }

        return matches(map1, map2);
    }
};