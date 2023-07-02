#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m*n)
// Space Complexity: O(m+n)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        set<vector<int>> markerSet;
        set<int> markedRow;
        set<int> markedCol;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (matrix[i][j] == 0)
                {
                    markedRow.insert(i);
                    markedCol.insert(j);
                }
            }
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (markedRow.count(i) > 0 || markedCol.count(j) > 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};