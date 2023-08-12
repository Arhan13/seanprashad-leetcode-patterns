#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pii> maxH;
        for (int i = 0; i < arr.size(); i++)
        {
            int diff = abs(arr[i] - x);
            if (maxH.size() < k)
            {
                maxH.push(make_pair(diff, arr[i]));
            }
            else if (maxH.size() >= k)
            {
                diff = abs(arr[i] - x);
                if (diff < maxH.top().first || (diff == maxH.top().first && arr[i] < maxH.top().second))
                {
                    maxH.pop();
                    maxH.push(make_pair(diff, arr[i]));
                }
            }
        }
        vector<int> ans;
        int heapSize = maxH.size();
        while (heapSize--)
        {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};