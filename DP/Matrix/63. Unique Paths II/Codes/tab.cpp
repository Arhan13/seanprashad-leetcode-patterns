#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<double>> tab(rows + 2, vector<double>(cols + 2, 0));
        for (int r = rows - 1; r >= 0; r--)
        {
            for (int c = cols - 1; c >= 0; c--)
            {
                if (r == rows - 1 && c == cols - 1 && obstacleGrid[r][c] != 1)
                {
                    tab[r][c] = 1;
                }
                else if (obstacleGrid[r][c] == 1)
                {
                    tab[r][c] = 0;
                }
                else
                {
                    tab[r][c] = tab[r + 1][c] + tab[r][c + 1];
                }
            }
        }
        return tab[0][0];
    }
};