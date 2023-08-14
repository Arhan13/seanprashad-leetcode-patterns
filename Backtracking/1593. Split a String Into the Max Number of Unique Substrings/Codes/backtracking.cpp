#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int count = 0;
    unordered_set<string> us;
    void backtracking(string &s, int currentIndex)
    {
        if (us.size() > count)
        {
            count = us.size();
        }
        if (currentIndex >= s.size())
        {
            return;
        }
        string str = "";
        for (int i = currentIndex; i < s.size(); i++)
        {
            str += s[i];
            if (us.find(str) == us.end())
            {
                us.insert(str);
                backtracking(s, i + 1);
                us.erase(str);
            }
        }
    }

public:
    int maxUniqueSplit(string s)
    {
        int currentIndex = 0;
        backtracking(s, currentIndex);
        return count;
    }
};