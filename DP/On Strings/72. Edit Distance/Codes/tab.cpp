#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // We need to find the Levenshtein Distance between the two strings
        word1.insert(0, " ");
        word2.insert(0, " ");
        int n = word1.size(), m = word2.size();
        vector<vector<int>> tab(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            tab[i][0] = i;
        }
        for (int j = 0; j < m; j++)
        {
            tab[0][j] = j;
        }
        for (int r = 1; r < n; r++)
        {
            for (int c = 1; c < m; c++)
            {
                if (word1[r] == word2[c])
                {
                    tab[r][c] = tab[r - 1][c - 1];
                }
                else
                {
                    tab[r][c] = 1 + min(tab[r - 1][c], min(tab[r][c - 1], tab[r - 1][c - 1]));
                }
            }
        }
        return tab[n - 1][m - 1];
    }
};