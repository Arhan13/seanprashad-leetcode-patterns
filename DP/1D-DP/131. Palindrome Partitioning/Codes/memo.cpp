#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void dfs(vector<vector<string>> &ans, vector<string> &path, string s, int currentIndex, vector<vector<bool>> &memo)
    {
        // When we reach the end of the tree, we push the path to the answer
        if (currentIndex == s.size())
        {
            ans.push_back(path);
            return;
        }
        // Iterate throught the rest of the string and find partitions
        for (int i = currentIndex; i < s.size(); i++)
        {
            // If the current substring is a palindrome, we push it to the path and continue
            string currentSubstring = s.substr(currentIndex, i - currentIndex + 1);
            if (memo[currentIndex][i] || isPalindrome(s, currentIndex, i))
            {
                // Push the current substring to the path
                path.push_back(currentSubstring);
                // Continue the dfs
                dfs(ans, path, s, i + 1, memo);
                // Pop the current substring from the path
                path.pop_back();
                // Mark the current substring as a palindrome
                memo[currentIndex][i] = true;
            }
        }
        return;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        if (s.empty())
        {
            return ans;
        }
        vector<string> path;
        int currentIndex = 0;
        vector<vector<bool>> memo(s.size(), vector<bool>(s.size(), false));
        dfs(ans, path, s, 0, memo);
        return ans;
    }
};