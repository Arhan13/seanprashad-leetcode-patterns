#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        // We need a max heap
        priority_queue<int> maxH;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                maxH.push(matrix[i][j]);
                if (maxH.size() > k)
                {
                    maxH.pop();
                }
            }
        }
        return maxH.top();
    }
};