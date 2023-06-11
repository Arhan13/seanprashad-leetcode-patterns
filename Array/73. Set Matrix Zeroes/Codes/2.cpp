#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m*n)
// Space Complexity: O(1)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    /*
                    The reason why setting matrix[0][j] and matrix[i][0] to 0 doesn't interfere with setting
                    first_row_zero and first_col_zero to true is because we only set first_row_zero and first_col_zero
                    to true if the first row or first column themselves contain a 0.
                    We don't set them to true if any other row or column contains a 0.
                    When we set matrix[0][j] and matrix[i][0] to 0, we are using the
                    first row and first column to store information about which rows and columns need to be set to 0.
                    We are not modifying the first row or first column themselves. We only modify the first row and first column later,
                    after we have used them to store information about which rows and columns need to be set to 0.
                    */
                    if (i == 0)
                    {
                        isFirstRowZero = true;
                    }
                    if (j == 0)
                    {
                        isFirstColZero = true;
                    }
                    // Mark the first row as zero
                    matrix[0][j] = 0;
                    // Mark the first column as zero
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isFirstRowZero)
        {
            for (int i = 0; i < cols; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (isFirstColZero)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};