#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty())
        {
            return ans;
        }

        int height = matrix.size();
        int width = matrix[0].size();

        int left = 0;
        int right = width - 1;
        int top = 0;
        int bottom = height - 1;
        int dir = 0;
        while (top <= bottom && left <= right)
        {
            // Move from top left to top right
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            // Move from right top to right bottom
            else if (dir == 1)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            // Move from bottom right to bottom left
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // Move from left bottom to left top
            else if (dir == 3)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};