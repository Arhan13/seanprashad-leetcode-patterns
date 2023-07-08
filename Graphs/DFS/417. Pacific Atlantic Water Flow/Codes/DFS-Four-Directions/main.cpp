#include <bits/stdc++.h>
#include "dfs.cpp"
using namespace std;

int main()
{
    Solution s;
    vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4}};
    vector<vector<int>> ans = s.pacificAtlantic(heights);
    for (auto v : ans)
    {
        cout << "[" << v[0] << ", " << v[1] << "]" << endl;
    }
    return 0;
}