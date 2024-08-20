#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lowRow = 0;
        int highRow = rows - 1;
        while (lowRow < highRow)
        {
            int mid = lowRow + (highRow - lowRow) / 2;
            if (matrix[mid][0] == target)
            {
                return true;
            }
            else if (matrix[mid][0] < target && target < matrix[mid + 1][0])
            {
                lowRow = mid;
                break;
            }
            else if (matrix[mid][0] < target)
            {
                lowRow = mid + 1;
            }
            else
            {
                highRow = mid - 1;
            }
        }

        int lowCol = 0;
        int highCol = cols - 1;

        while (lowCol <= highCol)
        {
            int mid = lowCol + (highCol - lowCol) / 2;
            if (matrix[lowRow][mid] == target)
            {
                return true;
            }
            else if (matrix[lowRow][mid] < target)
            {
                lowCol = mid + 1;
            }
            else
            {
                highCol = mid - 1;
            }
        }
        return false;
    }
};