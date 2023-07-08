#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // Check if the rows and cols are in bounds
    bool isInBounds(int row, int col, int rows, int cols)
    {
        if (row < rows && row >= 0 && col < cols && col >= 0)
        {
            return true;
        }
        return false;
    }
    // This function populates the pacCells and atlCells
    void dfs(int row, int col, vector<vector<bool>> &cells, int rows, int cols, int previousHeightOfCell, vector<vector<int>> &heights)
    {
        // Now check if we can do a DFS on this cell
        // Check the bounds
        // Check if the height[row][col] >= previousHeightOfCell
        // Check if the cell has already been visited
        if (!isInBounds(row, col, rows, cols) || previousHeightOfCell > heights[row][col] || cells[row][col])
        {
            return;
        }
        // We can add this cell to the cells set
        cells[row][col] = true;
        // Now we can call DFS on the rest of the cells by iterating over moves
        for (auto move : moves)
        {
            dfs(row + move[0], col + move[1], cells, rows, cols, heights[row][col], heights);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> ans = {};
        vector<vector<bool>> pacCells(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlCells(rows, vector<bool>(cols, false));
        // For pacific ocean you need to scan the first row
        // For atlantic ocean you need to scan the last row
        // We know the rows, so we need to iterate over the cols
        for (int col = 0; col < cols; col++)
        {
            // Call DFS on each cell for both pacific and atlantic ocean
            dfs(0, col, pacCells, rows, cols, -1, heights);
            dfs(rows - 1, col, atlCells, rows, cols, -1, heights);
        }
        // For the pacific ocean you need to scan the first col
        // For atlantic ocean you need to scan the last col
        for (int row = 0; row < rows; row++)
        {
            // Call DFS on each cell for both pacific and atlantic ocean
            dfs(row, 0, pacCells, rows, cols, -1, heights);
            dfs(row, cols - 1, atlCells, rows, cols, -1, heights);
        }
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                pair<int, int> p = make_pair(row, col);
                if (pacCells[row][col] && atlCells[row][col])
                {
                    ans.push_back({row, col});
                }
            }
        }
        return ans;
    }
};