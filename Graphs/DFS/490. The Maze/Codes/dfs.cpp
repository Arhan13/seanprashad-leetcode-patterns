#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<vector<int>> &maze,
             vector<int> current,
             vector<int> &destination,
             int n, int m,
             vector<vector<bool>> &visited)
    {
        if (visited[current[0]][current[1]])
        {
            return false;
        }
        else if (current[0] == destination[0] && current[1] == destination[1])
        {
            return true;
        }
        visited[current[0]][current[1]] = true;
        // Now move in all directions
        for (vector<int> move : this->moves)
        {
            int r = current[0];
            int c = current[1];
            // move ball till you can
            while (r >= 0 && r < n && c >= 0 && c < m && maze[r][c] == 0)
            {
                r += move[0];
                c += move[1];
            }
            // revert it
            if (this->dfs(maze, {r - move[0], c - move[1]}, destination, n, m, visited))
            {
                return true;
            }
        }
        return false;
    }

public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return this->dfs(maze, start, destination, n, m, visited);
    }
};