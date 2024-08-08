#define pi pair<int, int>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        unordered_map<int, int> ump;
        priority_queue<pi, vector<pi>, greater<pi>> minH;
        for (auto num : nums)
        {
            ump[num]++;
        }
        for (auto ele : ump)
        {
            int sizeOfHeap = minH.size();
            if (sizeOfHeap < k)
            {
                minH.push(make_pair(ele.second, ele.first));
            }
            else if (minH.top().first < ele.second)
            {
                minH.pop();
                minH.push(make_pair(ele.second, ele.first));
            }
        }
        while (minH.size() > 0)
        {
            pi curr = minH.top();
            minH.pop();
            ans.push_back(curr.second);
        }
        return ans;
    }
};