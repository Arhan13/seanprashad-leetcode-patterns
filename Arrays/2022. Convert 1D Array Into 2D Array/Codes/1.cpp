#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> ans = {};
        if (original.size() != m * n)
        {
            return ans;
        }
        int currentRow = 1;
        for (int i = 0; i < m; i++)
        {
            vector<int> row = {};
            for (int j = 0; j < n; j++)
            {
                row.push_back(original[i * n + j]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};