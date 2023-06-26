//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> indegree(V, 0);
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
            {
                indegree[x]++;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (q.size() > 0)
        {
            int ele = q.front();
            q.pop();
            count++;
            for (auto x : adj[ele])
            {
                if (indegree[x] >= 1)
                {
                    indegree[x]--;
                    if (indegree[x] == 0)
                    {
                        q.push(x);
                    }
                }
            }
        }
        return count == V ? false : true;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends