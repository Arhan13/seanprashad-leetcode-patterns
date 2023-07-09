#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int currentNode, vector<vector<int>> &adjList, int previousNode, vector<bool> &visited)
    {
        // We need to check if the currentNode is in the visit set
        if (visited[currentNode])
        {
            return false;
        }
        visited[currentNode] = true;
        // We check the adj nodes are not the previous and then perform DFS on them
        for (auto neighbour : adjList[currentNode])
        {
            if (neighbour != previousNode)
            {
                if (!dfs(neighbour, adjList, currentNode, visited))
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
        {
            return true;
        }
        // A tree is an undirected grah with a single connected component without any loops
        vector<vector<int>> adjList(n, vector<int>());
        // Building the adj list
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool> visited(n, false);
        if (!dfs(0, adjList, -1, visited))
        {
            return false;
        }
        for (auto v : visited)
        {
            if (!v)
            {
                return false;
            }
        }
        return true;
    }
};