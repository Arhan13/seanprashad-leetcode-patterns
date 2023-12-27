#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int n = arrays.size();
        int mi = arrays[0][0];     // minimum element
        int mx = arrays[0].back(); // maximum element
        int maxDistance = 0;
        for (int i = 1; i < n; i++)
        {
            vector<int> currArr = arrays[i];
            int distanceToCurrMin = abs(currArr[0] - mx);
            int distanceToCurrMax = abs(currArr.back() - mi);
            maxDistance = max({maxDistance, distanceToCurrMin, distanceToCurrMax});
            mi = min(mi, currArr[0]);
            mx = max(mx, currArr.back());
        }
        return maxDistance;
    }
};