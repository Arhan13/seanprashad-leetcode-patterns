#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> tab(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = text1.size() - 1; i >= 0; i--)
        {
            for (int j = text2.size() - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    tab[i][j] = 1 + tab[i + 1][j + 1];
                }
                else
                {
                    tab[i][j] = max(tab[i + 1][j], tab[i][j + 1]);
                }
            }
        }
        return tab[0][0];
    }
};