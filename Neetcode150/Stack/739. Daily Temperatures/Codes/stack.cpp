#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temps)
    {
        int n = temps.size();
        if (n == 0)
        {
            return {};
        }
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (st.size() > 0 && temps[i] > temps[st.top()])
            {
                int index = st.top();
                st.pop();
                ans[index] = i - index;
            }
            st.push(i);
        }
        return ans;
    }
};