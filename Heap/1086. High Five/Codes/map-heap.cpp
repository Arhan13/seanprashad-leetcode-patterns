#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int k = 5;

public:
    vector<vector<int>> highFive(vector<vector<int>> &items)
    {
        map<int, priority_queue<int>> mp;
        for (vector<int> &item : items)
        {
            mp[item[0]].push(item[1]);
        }
        vector<vector<int>> ans;
        // process the 5 average
        for (auto &[id, scores] : mp)
        {
            int sum = 0;
            for (int i = 0; i < this->k; i++)
            {
                sum += scores.top();
                scores.pop();
            }
            ans.push_back({id, sum / this->k});
        }
        return ans;
    }
};