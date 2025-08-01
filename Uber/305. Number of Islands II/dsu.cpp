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
        parent[node] = findUParent(parent[node]);
        return parent[node];
    }

    bool unionByRank(int u, int v)
    {
        // Find the u parent for each
        int up_u = findUParent(u);
        int up_v = findUParent(v);
        if (up_u == up_v)
        {
            return false;
        }
        // Find rank of u and v
        int r_up_u = rank[up_u];
        int r_up_v = rank[up_v];

        if (r_up_u < r_up_v)
        {
            parent[up_u] = up_v;
        }
        else if (r_up_v < r_up_u)
        {
            parent[up_v] = up_u;
        }
        else
        {
            // Just join u to v if same rank
            parent[up_v] = up_u;
            rank[up_u]++;
        }
        return true;
    }
};
class Solution
{
    int rows = 0, cols = 0;
    vector<vector<int>> moves = {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int getIndex(int row, int col)
    {
        return row * cols + col;
    }
    bool isInBounds(int row, int col)
    {
        return (row < rows && col < cols && row >= 0 && col >= 0);
    }

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
    {
        vector<int> ans = {};
        rows = m;
        cols = n;
        set<int> lands = {};
        int totalNodes = rows * cols;
        DisjointSet d(totalNodes);
        int islandCount = 0;
        for (vector<int> &position : positions)
        {
            // Find land parcels
            int row = position[0];
            int col = position[1];
            int currIndex = getIndex(row, col);
            if (lands.count(currIndex))
            {
                ans.push_back(islandCount);
                continue;
            }
            lands.insert(currIndex);
            islandCount++;
            // Check if there are other land parcels that are connected
            for (vector<int> &move : moves)
            {
                int _row = row + move[0], _col = col + move[1];
                if (!isInBounds(_row, _col))
                {
                    continue;
                }
                int moveIndex = getIndex(_row, _col);
                if (lands.count(moveIndex))
                {
                    if (d.unionByRank(currIndex, moveIndex))
                    {
                        islandCount--;
                    }
                }
            }
            ans.push_back(islandCount);
        }
        return ans;
    }
};