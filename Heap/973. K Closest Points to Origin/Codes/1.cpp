#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        // We have min distance so we will use max heap
        priority_queue<pair<float, pair<int, int>>> maxH;
        for (auto x : points)
        {
            float distance = sqrt(pow(x[0], 2) + pow(x[1], 2));
            if (maxH.size() < k)
            {
                maxH.push(make_pair(distance, make_pair(x[0], x[1])));
            }
            else if (maxH.top().first > distance)
            {
                maxH.pop();
                maxH.push(make_pair(distance, make_pair(x[0], x[1])));
            }
        }
        while (maxH.size() > 0)
        {
            pair<float, pair<int, int>> ele = maxH.top();
            maxH.pop();
            ans.push_back({ele.second.first, ele.second.second});
        }
        return ans;
    }
};