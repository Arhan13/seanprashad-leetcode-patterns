//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(vector<int> adj[], vector<int> &visited, vector<int> &ans, int node)
    { // Mark the node as visited
        visited[node] = 1;
        ans.push_back(node);
        // Iterate through all the adjacent nodes
        for (int i = 0; i < adj[node].size(); i++)
        {
            int ele = adj[node][i];
            // Check if the adj ele is visited or not
            if (visited[ele] == 0)
            {
                // If adj ele is  !visited then call dfs
                dfs(adj, visited, ans, ele);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            // Check if the node is visited or not
            if (visited[i] == 0)
            {
                // If not visited then call dfs
                dfs(adj, visited, ans, i);
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
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends