// 207 Course Schedule

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Construct the graph
        unordered_map<int, vector<int>> g;
        for (vector<int> prereq : prerequisites)
        {
            int pre = prereq[1];
            int curr = prereq[0];
            g[pre].push_back(curr);
        }
        unordered_map<int, int> inDeg;
        for (pair<int, vector<int>> x : g)
        {
            inDeg[x.first] = 0;
        }
        // We will calculate the indegree for each node
        for (pair<int, vector<int>> x : g)
        {
            for (int ngb : x.second)
            {
                inDeg[ngb]++;
            }
        }
        // Queue for BFS
        queue<int> q;
        // Check which of the nodes have an indeg of 0
        for (pair<int, vector<int>> x : g)
        {
            if (inDeg[x.first] == 0)
            {
                q.push(x.first);
            }
        }
        // This will contain the topo sort seq
        vector<int> topo = {};
        while (q.size() > 0)
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (int ngb : g[node])
            {
                inDeg[ngb]--;
                if (inDeg[ngb] == 0)
                {
                    q.push(ngb);
                }
            }
        }
        return topo.size() == g.size();
    }
};