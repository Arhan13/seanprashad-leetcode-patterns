//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(stack<int> &st, vector<int> adj[], int node, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                dfs(st, adj, x, vis);
            }
        }
        st.push(node);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        // We will store the nodes in a stack
        stack<int> st;
        // We need to iterate through all the nodes
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(st, adj, i, vis);
            }
        }
        vector<int> ans;
        while (st.size() > 0)
        {
            int ele = st.top();
            st.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends