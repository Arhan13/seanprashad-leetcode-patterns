#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V+E)
// Space Complexity: O(V+E)
// V = number of courses
// E = number of prerequisites

// One line intution - If there is a cycle in the graph then we cannot complete all the courses

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // We can use topological sort for this
        // as we can say that length of the sorted nodes is not equal to the
        // total nodes then there is atleast one cycle
        // We will be using BFS for the topo sort
        // We will first create a graph and calculate the indegree of the nodes
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        // Creating an adj list
        for (auto x : prerequisites)
        {
            int crs = x[0];
            int pre = x[1];
            adj[crs].push_back(pre);
            indegree[pre]++;
        }
        // Now push the courses with 0 indegree into the queue
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0; // Length of the sorted graph nodes
        // Now we will pop the elements of the queue
        // Once we pop an element from the queue we will reduce the neighbours
        // indegree if the indegree is 0 then we will push it into the queue
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
        return count == numCourses;
    }
};