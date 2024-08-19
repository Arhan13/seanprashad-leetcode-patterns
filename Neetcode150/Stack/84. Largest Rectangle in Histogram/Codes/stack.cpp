#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<pair<int, int>> st;
        int ans = 0;
        // Loop over the heights, and build stack
        for (int i = 0; i < n; i++)
        {
            int start = i;
            int currHeight = heights[i];
            while (st.size() > 0 && st.top().second > currHeight)
            {
                pii topEle = st.top();
                st.pop();
                int height = topEle.second;
                int index = topEle.first;
                int width = i - index;
                start = index;
                ans = max(ans, height * width);
            }
            st.push({start, currHeight});
        }
        while (st.size() > 0)
        {
            pair<int, int> topEle = st.top();
            st.pop();
            int height = topEle.second;
            int index = topEle.first;
            int width = (n - index);
            ans = max(ans, height * width);
        }
        return ans;
    }
};