#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int n;
    void helper(vector<string> &ans, int size, int open, int close, string tempString)
    {
        if (tempString.size() == size)
        {
            ans.push_back(tempString);
            return;
        }
        if (close < open)
        {
            helper(ans, size, open, close + 1, tempString + ")");
        }
        if (open < n)
        {
            helper(ans, size, open + 1, close, tempString + "(");
        }
        return;
    }

public:
    vector<string> generateParenthesis(int _n)
    {
        n = _n;
        vector<string> ans;
        int size = n * 2;
        helper(ans, size, 0, 0, "");
        return ans;
    }
};