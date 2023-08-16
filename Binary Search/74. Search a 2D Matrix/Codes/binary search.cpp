#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;

        int left = 0;
        int right = rows;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] <= target && matrix[mid][cols] >= target)
            {
                int l = 0;
                int r = cols;
                while (l <= r)
                {
                    int m = l + (r - l + 1) / 2;
                    if (matrix[mid][m] == target)
                    {
                        return true;
                    }
                    else if (matrix[mid][m] > target)
                    {
                        r = m - 1;
                    }
                    else
                    {
                        l = m + 1;
                    }
                }
                return false;
            }
            else if (matrix[mid][cols] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};