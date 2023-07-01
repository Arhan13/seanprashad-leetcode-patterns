#include <bits/stdc++.h>
using namespace std;

// Space Complexity: O(n*m)
// Time Complexity: O(n*m)
// Graph Algorithm: BFS
// Why use BFS and not DFS?
// Because we need the number of days to rot all the oranges. And each iteration of BFS is a day.

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Get the size of the grid
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int total = 0;
        int count = 0;
        int days = 0;
        vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Check where we have the rotten oranges
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    total++;
                }
                if (grid[i][j] == 2)
                {
                    total++;
                    q.push(make_pair(i, j));
                }
            }
        }

        // If there are no rotten oranges, return 0
        if (q.empty() && total > 0)
        {
            return -1;
        }
        if (q.empty())
        {
            return 0;
        }

        count = q.size();
        while (!q.empty())
        {
            int currentSize = q.size();
            while (currentSize--)
            {
                pair<int, int> ele = q.front();
                q.pop();
                for (auto move : moves)
                {
                    int newX = ele.first + move[0];
                    int newY = ele.second + move[1];
                    if ((newX < n && newY < m && newX >= 0 && newY >= 0) && grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        q.push(make_pair(newX, newY));
                        count++;
                    }
                }
            }
            if (!q.empty())
            {
                days++;
            }
        }
        if (count == total)
        {
            return days;
        }
        return -1;
    }
};