// Very often, graph problems are represented as matrices.For example :
// Number of Islands
// Knight Shortest Path

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct Coordinate
{
    int row, col;

    Coordinate(int _r, int _c)
    {
        row = _r;
        col = _c;
    }
};

vector<vector<int>> grid;

int num_rows = grid.size();
int num_cols = grid[0].size();

std::vector<Coordinate> get_neighbors(Coordinate coord)
{
    int row = coord.row;
    int col = coord.col;
    int delta_row[4] = {-1, 0, 1, 0};
    int delta_col[4] = {0, 1, 0, -1};
    std::vector<Coordinate> res;
    for (int i = 0; i < 4; i++)
    {
        int neighbor_row = row + delta_row[i];
        int neighbor_col = col + delta_col[i];

        if (0 <= neighbor_row && neighbor_row < num_rows &&
            0 <= neighbor_col && neighbor_col < num_cols)
        {
            res.emplace_back(Coordinate(neighbor_row, neighbor_col));
        }
    }
    return res;
}

void bfs(Coordinate starting_node)
{
    std::queue<Coordinate> q;
    q.push(starting_node);
    std::unordered_set<Coordinate> visited;
    visited.emplace(starting_node);

    while (q.size() > 0)
    {
        Coordinate node = q.front();
        for (Coordinate neighbor : get_neighbors(node))
        {
            if (visited.count(neighbor))
                continue;
            // Do stuff with the node if required
            // ...
            q.push(neighbor);
            visited.emplace(neighbor);
        }
        q.pop();
    }
}