#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rows = 0;
    int cols = 0;
    vector<vector<int>> moves = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}};
    bool isValid(int row, int col)
    {
        return (row < rows && col < cols && row >= 0 && col >= 0);
    };
    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        grid[row][col] = '0';
        for (vector<int> &move : moves)
        {
            int newRow = row + move[0];
            int newCol = col + move[1];
            if (isValid(newRow, newCol) && grid[newRow][newCol] == '1')
            {
                dfs(grid, newRow, newCol);
            }
        }
    };

public:
    int numIslands(vector<vector<char>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};