#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        int i = 0, j = 0;
        int n = neededTime.size();
        while (i < n && j < n)
        {
            int currTotal = 0;
            int currMax = 0;
            while (j < n && colors[i] == colors[j])
            {
                currTotal += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }
            // keep the max and remove the rest
            ans += currTotal - currMax;
            i = j;
        }
        return ans;
    }
};