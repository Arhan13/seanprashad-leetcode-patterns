#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V+E)
// Space Complexity: O(V+E)
// V = number of nodes
// E = number of edges of the graph
// One line intution - The nodes with indegree 1 are the leaf nodes
// We will remove the leaf nodes from the graph and update the indegree of their neighbours
// We will keep on doing this until we are left with 1 or 2 nodes
// These nodes will be the root nodes of the minimum height trees
// We will use BFS + Khans for this

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n <= 2)
        {
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);
        for (vector<int> edge : edges)
        {
            // There is an undirected edge between ai and bi
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        // The leaf nodes will have an indegree of 0
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
            {
                q.push(i);
            }
        }
        int remainingLeaves = n;
        while (remainingLeaves > 2)
        {
            /*
            The while loop is used to remove the leaf nodes from the graph.
            In each iteration of the while loop, we remove all the leaf nodes from
            the graph and update the indegree of their neighbours.
            We also add the new leaf nodes to the queue.
            We keep doing this until we are left with only 1 or 2 nodes in the graph.
            */
            int qSize = q.size();
            while (qSize--)
            {
                int node = q.front();
                q.pop();
                remainingLeaves--;
                for (int neighbour : adj[node])
                {
                    indegree[neighbour]--;
                    if (indegree[neighbour] == 1)
                    {
                        // We push it neighbours into the queue, as these nodes
                        // are part of the next leaf level
                        q.push(neighbour);
                    }
                }
            }
        }
        vector<int> ans;
        while (q.size() > 0)
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
        }
        return ans;
    }
};