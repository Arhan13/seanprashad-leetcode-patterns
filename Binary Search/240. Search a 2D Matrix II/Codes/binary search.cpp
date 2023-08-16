#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // We will start at the top right corner
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;
        int currRow = 0;
        int currCol = cols;

        while (currRow <= rows && currCol >= 0)
        {
            if (matrix[currRow][currCol] == target)
            {
                return true;
            }
            // We will move down if the value is less than the target
            else if (matrix[currRow][currCol] < target)
            {
                currRow += 1;
            }
            // We will move left if the value if more than the target
            else if (matrix[currRow][currCol] > target)
            {
                currCol -= 1;
            }
        }
        return false;
    }
};