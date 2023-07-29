#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> timeline(1001, 0);
        for (auto trip : trips)
        {
            timeline[trip[1]] += trip[0];
            timeline[trip[2]] -= trip[0];
        }
        int passengers = 0;
        for (auto time : timeline)
        {
            passengers += time;
            if (passengers > capacity)
            {
                return false;
            }
        }
        return true;
    }
};