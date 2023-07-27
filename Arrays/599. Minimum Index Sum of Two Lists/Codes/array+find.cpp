#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        int leastIndexSum = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < list1.size(); i++)
        {
            auto it = find(list2.begin(), list2.end(), list1[i]);
            if (it != list2.end())
            {
                int dis = distance(list2.begin(), it);
                if (i + dis < leastIndexSum)
                {
                    leastIndexSum = i + dis;
                    ans.clear();
                    ans.push_back(list1[i]);
                }
                else if (i + dis == leastIndexSum)
                {
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};