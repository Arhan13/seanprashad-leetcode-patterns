// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/957263856/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, string> mapper = {
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    void dfs(string digits, string path, int index, vector<string> &ans)
    {
        if (path.size() == digits.size())
        {
            ans.push_back(path);
            return;
        }
        // Iterate over all the letters mapped for that digit
        for (auto x : mapper[digits[index]])
        {
            path.push_back(x);
            dfs(digits, path, index + 1, ans);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return {};
        }
        vector<string> ans;
        dfs(digits, "", 0, ans);
        return ans;
    }
};
