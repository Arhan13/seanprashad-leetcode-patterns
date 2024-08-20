#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int size1 = s.size();
        int size2 = t.size();
        if (size1 != size2)
        {
            return false;
        }
        unordered_map<char, int> ump1;
        unordered_map<char, int> ump2;
        for (auto ele1 : s)
        {
            ump1[ele1]++;
        }
        for (auto ele2 : t)
        {
            ump2[ele2]++;
        }
        if (ump1 == ump2)
        {
            return true;
        }
        return false;
    }
};