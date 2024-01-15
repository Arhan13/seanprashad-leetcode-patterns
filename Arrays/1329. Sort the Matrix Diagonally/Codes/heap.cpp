#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        const int n = mat.size();
        const int m = mat[0].size();

        map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        // for each cell matrix[i][j] in the same diagonal
        // then will have the same i-j value

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mp[i - j].push(mat[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = mp[i - j].top();
                mp[i - j].pop();
            }
        }
        return mat;
    }
};