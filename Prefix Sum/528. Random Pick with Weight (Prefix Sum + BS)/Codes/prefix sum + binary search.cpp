#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> prefix;

public:
    Solution(vector<int> &w)
    {
        int n = w.size();
        prefix.resize(n);
        prefix[0] = w[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = w[i] + prefix[i - 1];
        }
    }

    int pickIndex()
    {
        int total = prefix.back();
        int r = rand() % total;
        int ans = 0;
        int lo = 0;
        int hi = prefix.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (prefix[mid] <= r)
            {
                lo = mid + 1;
            }
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */