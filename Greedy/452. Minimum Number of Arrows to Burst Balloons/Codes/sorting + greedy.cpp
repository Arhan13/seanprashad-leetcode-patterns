#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int count = 0;
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        for (int i = 0; i < points.size(); i++)
        {
            int j = i + 1;
            int end = points[i][1];
            while (j < points.size() && points[j][0] <= end)
            {
                end = min(end, points[j][1]);
                j++;
            }
            i = j - 1;
            count++;
        }
        return count;
    }
};