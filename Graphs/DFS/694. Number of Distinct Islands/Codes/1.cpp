#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool inBounds(int i, int j, int rows, int cols)
    {
        if (i < rows && j < cols && i >= 0 && j >= 0)
        {
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>> &grid, int i, int j, int rows, int cols, vector<pair<int, int>> &island)
    {
        if (!inBounds(i, j, rows, cols) || grid[i][j] == 0)
        {
            return;
        }
        island.push_back(make_pair(i, j));
        grid[i][j] = 0;
        for (auto move : moves)
        {
            dfs(grid, i + move[0], j + move[1], rows, cols, island);
        }
        return;
    }
    int numDistinctIslands(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        set<string> islands;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Start storing all the points in that island
                    vector<pair<int, int>> island = {};
                    // I will wipe off the whole island and store it in island vector
                    dfs(grid, i, j, rows, cols, island);
                    string tempS = "";
                    for (auto point : island)
                    {
                        tempS += to_string(point.first - i) + to_string(point.second - j);
                    }
                    islands.insert(tempS);
                }
            }
        }
        return islands.size();
    }
};