#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<char>> &matrix, vector<vector<int>> &memo, int currentRow, int currentCol, int rows, int cols)
    {
        if (currentRow >= rows || currentCol >= cols)
        {
            return 0;
        }
        if (memo[currentRow][currentCol] != -1)
        {
            return memo[currentRow][currentCol];
        }
        // Now we need to check the neighbours
        if (matrix[currentRow][currentCol] == '0')
        {
            memo[currentRow][currentCol] = 0;
            return 0;
        }
        int down = solve(matrix, memo, currentRow + 1, currentCol, rows, cols);
        int right = solve(matrix, memo, currentRow, currentCol + 1, rows, cols);
        int diagonal = solve(matrix, memo, currentRow + 1, currentCol + 1, rows, cols);
        memo[currentRow][currentCol] = 1 + min({down, right, diagonal});
        return memo[currentRow][currentCol];
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        int maxVal = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                maxVal = max(maxVal, solve(matrix, memo, i, j, rows, cols));
            }
        }
        return maxVal * maxVal;
    }
};