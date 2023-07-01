//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        // We will use BFS this time
        vector<int> ans;
        queue<int> q;
        vector<int> indegree(V, 0);
        // Calculate the indegree of the edges
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
            {
                indegree[x]++;
            }
        }
        // We will push the nodes with indegree of 0 into the queue
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // Now untill the queue is empty we will perform BFS on each node
        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            ans.push_back(ele);
            // Reduce the indegree of the neighbour nodes that are connected to the node
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