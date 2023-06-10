#include <bits/stdc++.h>
using namespace std;

// This is a DFS problem
// Space Complexity: O(width*height)
// Time Complexity: O(width*height)
// Intution behind this problem is that we have to find the number of connected components in the graph
// Approach: We will traverse the grid and whenever we find a 1 we will increment the noOfIslands and then we will call the dfs function to erase all the 1's that are connected to this 1

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int width, int height, int x, int y, int noOfIslands)
    {
        if (x < 0 || y < 0 || x >= width || y >= height || grid[x][y] == '0')
        {
            return;
        }
        // This function removes all the 1's that exist on the island
        grid[x][y] = '0';
        vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto move : moves)
        {
            dfs(grid, width, height, x + move[0], y + move[1], noOfIslands);
        }
        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int width = grid.size();
        if (width == 0)
        {
            return 0;
        }
        int height = grid[0].size();
        int noOfIslands = 0;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (grid[i][j] == '1')
                {
                    noOfIslands++;
                    dfs(grid, width, height, i, j, noOfIslands);
                }
            }
        }
        return noOfIslands;
    }
};