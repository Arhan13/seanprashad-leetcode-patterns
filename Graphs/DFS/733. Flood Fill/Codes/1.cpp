#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool inBounds(int x, int y, int n, int m)
    {
        if (x < n && y < m && x >= 0 && y >= 0)
        {
            return true;
        }
        return false;
    }

    void dfs(vector<vector<int>> &image, int r, int c, int color, int currentColor, int rows, int cols)
    {
        vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto move : moves)
        {
            int newRow = r + move[0];
            int newCol = c + move[1];
            if (!inBounds(newRow, newCol, rows, cols))
            {
                continue;
            }
            else if (image[newRow][newCol] == color || image[newRow][newCol] != currentColor)
            {
                continue;
            }
            image[newRow][newCol] = color;
            dfs(image, newRow, newCol, color, currentColor, rows, cols);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int rows = image.size();
        int cols = image[0].size();
        int currentColor = image[sr][sc];
        image[sr][sc] = color;
        dfs(image, sr, sc, color, currentColor, rows, cols);
        return image;
    }
};