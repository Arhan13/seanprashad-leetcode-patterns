#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ump;
        int n = strs.size();
        if (n == 0)
        {
            return ans;
        }
        for (auto str : strs)
        {
            string currStr = str;
            sort(currStr.begin(), currStr.end());
            ump[currStr].push_back(str);
        }
        for (auto ele : ump)
        {
            ans.push_back(ele.second);
        }
        return ans;
    }
};