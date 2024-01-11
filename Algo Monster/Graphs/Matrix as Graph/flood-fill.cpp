#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Coordinate
    {
        int r;
        int c;
        Coordinate(int _r, int _c)
        {
            r = _r;
            c = _c;
        }
    };
    vector<vector<int>> moves = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};

private:
    bool checkInBounds(int nr, int nc, int rows, int cols)
    {
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
        {
            return true;
        }
        return false;
    }
    vector<Coordinate> getNeighbors(vector<vector<int>> &image, Coordinate node, int rows, int cols, int rootColor)
    {
        vector<Coordinate> neighbors = {};
        for (int i = 0; i < 4; i++)
        {
            int nr = node.r + moves[i][0];
            int nc = node.c + moves[i][1];
            if (checkInBounds(nr, nc, rows, cols))
            {
                if (image[nr][nc] == rootColor)
                {
                    neighbors.push_back(Coordinate(nr, nc));
                }
            }
        }
        return neighbors;
    }
    void bfs(vector<vector<int>> &image, Coordinate root, int replacementColor)
    {
        int rows = image.size();
        int cols = image[0].size();
        queue<Coordinate> q;
        q.push(root);
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[root.r][root.c] = true;
        int rootColor = image[root.r][root.c];
        image[root.r][root.c] = replacementColor;
        while (q.size() > 0)
        {
            Coordinate node = q.front();
            q.pop();
            vector<Coordinate> neighbors = getNeighbors(image, node, rows, cols, rootColor);
            for (Coordinate neighbour : neighbors)
            {
                if (visited[neighbour.r][neighbour.c])
                {
                    continue;
                }
                visited[neighbour.r][neighbour.c] = true;
                image[neighbour.r][neighbour.c] = replacementColor;
                q.push(neighbour);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        bfs(image, Coordinate(sr, sc), color);
        return image;
    };
};