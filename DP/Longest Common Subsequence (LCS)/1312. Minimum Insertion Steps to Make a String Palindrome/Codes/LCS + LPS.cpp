#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
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

    int longestPalindromeSubseq(string s)
    {
        string rs = s;
        reverse(rs.begin(), rs.end());
        return longestCommonSubsequence(s, rs);
    }

public:
    int minInsertions(string s)
    {
        // LPS = Longest Palindromic Subsequence
        // Length of LPS is proportional to 1/(# of deletions)

        // So we need to find out the min number of delections for making str a palindrome
        // We will have to find the LPS(s) = LCS(s, revserse s)

        // min # of deletions = s.length - LPS
        // # of insertions = # of deletions

        int lengthOfLPS = longestPalindromeSubseq(s);
        return s.size() - lengthOfLPS;
    }
};