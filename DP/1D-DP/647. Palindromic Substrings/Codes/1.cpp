#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

class Solution
{
public:
    bool isPalindrome(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right++;
        }
        return true;
    }
    void dfs(string s, int currentIndex, vector<string> &path, vector<vector<bool>> &memo, vector<int> &pathLengths)
    {
        if (currentIndex == s.size())
        {
            pathLengths.push_back(path.size());
            return;
        }
        for (int i = currentIndex; i < s.size(); i++)
        {
            string substring = s.substr(currentIndex, i - currentIndex + 1);
            if (isPalindrome(s, currentIndex, i))
            {
                path.push_back(substring);
                dfs(s, currentIndex + 1, path, memo, pathLengths);
                path.pop_back();
            }
        }
        return;
    }
    int countSubstrings(string s)
    {
        vector<int> pathLengths;
        vector<vector<bool>> memo(s.size() + 1, vector<bool>(s.size() + 1, false));
        vector<string> path;
        dfs(s, 0, path, memo, pathLengths);
        int ans = 0;
        for (auto x : pathLengths)
        {
            ans += x;
        }
        return ans;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution S;
    string s = "a";
    cout << S.countSubstrings(s) << endl;
    return 0;
}