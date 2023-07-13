#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int currentNode, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        visited[currentNode] = true;
        for (auto neighbour : adjList[currentNode])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, adjList, visited);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n, vector<int>());
        vector<bool> visited(n, false);
        int count = 0;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        // Iterate over all the edges
        for (int node = 0; node < n; node++)
        {
            if (!visited[node])
            {
                count++;
                dfs(node, adjList, visited);
            }
        }
        return count;
    }
};