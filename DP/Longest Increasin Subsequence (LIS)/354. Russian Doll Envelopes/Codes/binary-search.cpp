#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        vector<int> lis;
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             {
            if(a[0] == b[0]){
                return a[1] > b[1];
            }else{
                return a[0] < b[0];
            } });
        for (int i = 0; i < n; i++)
        {
            if (lis.empty() || envelopes[i][1] > lis.back())
            {
                lis.push_back(envelopes[i][1]);
            }
            else
            {
                int index = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
                lis[index] = envelopes[i][1];
            }
        }
        return lis.size();
    }
};