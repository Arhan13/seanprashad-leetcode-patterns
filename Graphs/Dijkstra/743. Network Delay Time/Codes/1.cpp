#include <bits/stdc++.h>
using namespace std;
// Mistake in made - Took nodes from 0 to n-1 instead of 1 to n
// Time Complexity: O(ElogV)
// Space Complexity: O(V+E)
// Time Complexity Proof -
// We are using a priority queue which is implemented using a heap
// The time complexity of heapify is O(logn)
// We are doing this for all the edges
// So the time complexity is O(ElogV)
// Space Complexity Proof -
// We are using a priority queue which is implemented using a heap
// The space complexity of heapify is O(n)
// We are doing this for all the edges
// So the space complexity is O(V+E)
// V = number of nodes
// E = number of edges
// One line intution - We will use Dijkstra's algorithm to find the shortest path from the source node to all the other nodes
#define pii pair<int, int>

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pii>> adj(n + 1, vector<pii>());
        for (auto time : times)
        {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }
        vector<int> distances(n + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> minH;
        distances[k] = 0;
        minH.push({0, k});
        while (minH.size() > 0)
        {
            pii ele = minH.top();
            int node = ele.second;
            int distance = ele.first;
            minH.pop();
            for (auto ngb : adj[node])
            {
                int adjNode = ngb.first;
                int edgeW = ngb.second;
                if (distance + edgeW < distances[adjNode])
                {
                    distances[adjNode] = distance + edgeW;
                    minH.push({distances[adjNode], adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (distances[i] == INT_MAX)
            {
                return -1;
            }
            else if (distances[i] > ans)
            {
                ans = distances[i];
            }
        }
        return ans;
    }
};