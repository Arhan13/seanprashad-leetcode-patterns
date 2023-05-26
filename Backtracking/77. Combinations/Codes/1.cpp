#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &path, int index, int n, int k)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = index; i <= n; i++)
        {
            path.push_back(i);
            backtrack(ans, path, i + 1, n, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(ans, path, 1, n, k);
        return ans;
    }
};

int main()
{
    Solution s;
    int n = 4;
    int k = 2;
    vector<vector<int>> combinations = s.combine(n, k);
    // print the combinations
    cout << "All possible combinations of " << k << " numbers out of 1 to " << n << ":" << endl;
    for (vector<int> combination : combinations)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}