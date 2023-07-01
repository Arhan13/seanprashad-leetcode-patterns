#include <bits/stdc++.h>
using namespace std;

int main()
{
    // n = number of vertices
    // m = number of edges
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }
    return 0;
}