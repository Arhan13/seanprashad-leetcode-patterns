#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

class Solution
{
private:
    int n;
    int m;

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        n = text1.size();
        m = text2.size();
        vvi tab(n + 1, vi(m + 1, 0));

        // Fill the DP table
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
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

    int longestPalindromeSubseq(string s)
    {
        string revString = s;
        reverse(revString.begin(), revString.end());
        return longestCommonSubsequence(s, revString);
    }
};