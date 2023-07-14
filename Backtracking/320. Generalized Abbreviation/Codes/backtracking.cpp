#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtracking(string &word, vector<string> &ans, string currentPath, int currentIndex, int countSkips)
    {
        if (currentIndex == word.size())
        {
            if (countSkips > 0)
            {
                string _temp = "";
                _temp += currentPath;
                _temp += to_string(countSkips);
                ans.push_back(_temp);
            }
            else
            {
                ans.push_back(currentPath);
            }
            return;
        }
        // If we include the character and count > 0
        if (countSkips > 0)
        {
            backtracking(word, ans, currentPath + to_string(countSkips) + (word[currentIndex]), currentIndex + 1, 0);
        }
        // If we include the character and count == 0
        else
        {
            backtracking(word, ans, currentPath + (word[currentIndex]), currentIndex + 1, 0);
        }
        // If we exclude the character
        backtracking(word, ans, currentPath, currentIndex + 1, countSkips + 1);
        return;
    }

public:
    vector<string> generateAbbreviations(string word)
    {
        vector<string> ans = {};
        string currentPath = "";
        backtracking(word, ans, currentPath, 0, 0);
        return ans;
    }
};