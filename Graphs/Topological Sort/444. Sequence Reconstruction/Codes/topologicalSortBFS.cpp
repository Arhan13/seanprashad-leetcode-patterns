#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
    {
        int n = nums.size();
        // We take n+1 because the elements are from 1 --> n
        // We first need to create a graph of the elements present in the sequence
        vector<vector<int>> adj(n + 1, vector<int>());
        // Now we initialize our indegree vector
        vector<int> indegree(n + 1, 0);
        // Creating an adj list using sequences
        for (vector<int> seq : sequences)
        {
            for (int i = 0; i < seq.size() - 1; i++)
            {
                // So there is going to be an edge from i to i+1
                adj[seq[i]].push_back(seq[i + 1]);
                indegree[seq[i + 1]]++;
            }
        }

        // Creating a queue
        queue<int> q;
        vector<int> ans = {};
        // Now we need to push all the nodes with indegree 0 into the queue
        for (int i = 1; i < nums.size() + 1; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // Cannot have more than 2 elements in the queue, as it will not lead to unique
        // topologically sorted sequences
        // Now we do our topological sort
        while (q.size() > 0)
        {
            if (q.size() >= 2)
            {
                return false;
            }
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        return ans == nums;
    }
};