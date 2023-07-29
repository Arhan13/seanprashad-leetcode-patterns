#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> passengers(1001, 0);
        vector<int> prefix(1001, 0);
        for (auto trip : trips)
        {
            int numPass = trip[0];
            int from = trip[1];
            int to = trip[2];
            passengers[from] += numPass;
            // As the passenger will leave the station at to
            passengers[to] -= numPass;
            prefix[0] = passengers[0];
            if (prefix[0] > capacity)
            {
                return false;
            }
            // Line sweep
            for (int i = 1; i < 1001; i++)
            {
                prefix[i] = prefix[i - 1] + passengers[i];
                if (prefix[i] > capacity)
                {
                    return false;
                }
            }
        }
        return true;
    }
};