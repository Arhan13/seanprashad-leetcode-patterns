//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define pii pair<int, int>
class Solution
{
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        // Making a distances array that contains max distances initially for all nodes
        vector<int> distances(N, INT_MAX);
        vector<vector<pii>> adj(N, vector<pii>());
        // Min heap to get the closest edges at the top
        // This contains the distance, node
        priority_queue<pii, vector<pii>, greater<pii>> minH;
        // Making adj list from the given edges
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
        // We will push the initial node 0 first
        minH.push({0, 0});
        distances[0] = 0;
        while (minH.size() > 0)
        {
            pii ele = minH.top();
            minH.pop();
            int node = ele.second;
            int distanceToThatNode = ele.first;
            for (auto currentNgb : adj[node])
            {
                int adjNode = currentNgb.first;
                int edgeW = currentNgb.second;
                int newDistance = distanceToThatNode + edgeW;
                if (newDistance < distances[adjNode])
                {
                    distances[adjNode] = newDistance;
                    minH.push({distances[adjNode], adjNode});
                }
            }
        }
        // Check if there are any unreachable nodes
        for (int i = 0; i < N; i++)
        {
            if (distances[i] == INT_MAX)
            {
                distances[i] = -1;
            }
        }
        return distances;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends