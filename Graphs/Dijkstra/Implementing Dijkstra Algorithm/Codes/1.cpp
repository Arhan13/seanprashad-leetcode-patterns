//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int, int>
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // For Dijakstra we use BFS + Priority Queue
        // We need a min heap of pair<int, int>
        // priority_queue<pii, vector<pii>, greater<pii>> minH;
        set<pii> minH;
        vector<int> distances(V, INT_MAX);

        // We need to push the initial point into the queue
        minH.insert(make_pair(0, S));

        distances[S] = 0;

        while (minH.size() > 0)
        {
            // We need to get the node that is at least distance
            //  pii ele = minH.top();
            pii ele = *(minH.begin());
            minH.erase(ele);
            int node = ele.second;
            int distanceToThatNode = ele.first;

            // Now we need to iterate through the neighbours of the current node
            for (auto currentNgb : adj[node])
            {
                int adjNode = currentNgb[0];
                int edgeW = currentNgb[1];

                if (distanceToThatNode + edgeW < distances[adjNode])
                {
                    // We have found a shorter path to this particular node
                    // If the distace is not equal to the default value, then we will have to earse it
                    if (distanceToThatNode + edgeW != INT_MAX)
                    {
                        minH.erase({distances[adjNode], adjNode});
                    }
                    distances[adjNode] = distanceToThatNode + edgeW;
                    minH.insert({distances[adjNode], adjNode});
                }
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends