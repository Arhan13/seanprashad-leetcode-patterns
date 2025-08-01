#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        // return findUParent(parent[node]);
        parent[node] = findUParent(parent[node]);
        return parent[node];
    }

    void unionByRank(int u, int v)
    {
        // Find the ultimate parent of u, v [pu, pv]
        int ultimateParentU = findUParent(u);
        int ultimateParentV = findUParent(v);
        // If they belong to the same component, no need to do Union
        if (ultimateParentU == ultimateParentV)
        {
            return;
        }
        // Find the rank of ultimateParentU and ultimateParentV
        int ultimateParentURank = rank[ultimateParentU];
        int ultimateParentVRank = rank[ultimateParentV];
        // Connect smaller rank to larger rank always
        if (ultimateParentURank < ultimateParentVRank)
        {
            // No change in rank because smaller -> larger
            // The smaller nodes ultimate parent will change to the ultimate parent of the node its attaching to
            parent[ultimateParentU] = ultimateParentV;
        }
        else if (ultimateParentVRank < ultimateParentURank)
        {
            parent[ultimateParentV] = ultimateParentU;
        }
        else
        {
            // Just attach V to U if rank is same
            parent[ultimateParentV] = ultimateParentU;
            rank[ultimateParentU]++;
        }
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int count = 0;
        DisjointSet d(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    d.unionByRank(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (d.findUParent(i) == i)
            {
                count++;
            }
        }
        return count;
    }
};