//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        // We need to go over all the nodes of the graph
        vector<int> ans;
        vector<int> visited(V, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            ans.push_back(ele);
            // Pop the element and traverse over the neighbours
            for (int i = 0; i < adj[ele].size(); i++)
            {
                int v = adj[ele][i];
                // If the neighbour is not visited
                if (visited[v] == 0)
                {
                    visited[v] = 1;
                    // Mark it as visited and push it into the queue
                    q.push(v);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends