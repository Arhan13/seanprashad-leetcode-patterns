#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> isConnected, vector<int> &vis, int node, int n)
    {
        vis[node] = 1;
        for (int i = 0; i < n; i++)
        {
            if (isConnected[node][i] == 1 && !vis[i])
            {
                dfs(isConnected, vis, i, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // Iterate through all the nodes
        int n = isConnected.size();
        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(isConnected, vis, i, n);
            }
        }
        return ans;
    }
};