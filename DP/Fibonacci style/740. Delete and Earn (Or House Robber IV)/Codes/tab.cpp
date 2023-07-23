#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> ump;
        int maxNumber = 0;
        // Fill the freq map
        for (auto num : nums)
        {
            if (ump.find(num) != ump.end())
            {
                ump[num] += num;
            }
            else
            {
                ump[num] = num;
            }
            maxNumber = max(maxNumber, num);
        }
        vector<int> points(maxNumber + 1, 0);
        points[1] = (ump.find(1) != ump.end()) ? ump[1] : 0;
        for (int i = 2; i <= maxNumber; i++)
        {
            int gain = (ump.find(i) != ump.end()) ? ump[i] : 0;
            points[i] = max(points[i - 1], points[i - 2] + gain);
        }
        return points[maxNumber];
    }
};