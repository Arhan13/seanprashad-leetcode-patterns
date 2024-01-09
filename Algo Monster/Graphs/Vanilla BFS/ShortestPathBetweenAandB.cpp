#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
#include <queue>
#include <unordered_set>

using namespace std;

int bfs(vector<vector<int>> &graph, int root, int target)
{
    int distance = 0;
    queue<int> q;
    q.push(root);
    unordered_set<int> visited;
    visited.emplace(root);
    bool flag = true;
    while (q.size() > 0 && flag)
    {
        int n = q.size();
        // Go over all the neighbours in that level
        for (int i = 0; i < n; i++)
        {
            int node = q.front();
            q.pop();
            if (node == target)
            {
                return distance;
            }
            for (int neighbour : graph[node])
            {
                if (visited.count(neighbour))
                {
                    continue;
                }
                q.push(neighbour);
                visited.emplace(neighbour);
            }
        }
        distance++;
    }
    return distance;
}

int shortest_path(std::vector<std::vector<int>> graph, int a, int b)
{
    // WRITE YOUR BRILLIANT CODE HERE
    return bfs(graph, a, b);
}

template <typename T>
std::vector<T> get_words()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    int graph_length;
    std::cin >> graph_length;
    ignore_line();
    std::vector<std::vector<int>> graph;
    for (int i = 0; i < graph_length; i++)
    {
        graph.emplace_back(get_words<int>());
    }
    int a;
    std::cin >> a;
    ignore_line();
    int b;
    std::cin >> b;
    ignore_line();
    int res = shortest_path(graph, a, b);
    std::cout << res << '\n';
}
