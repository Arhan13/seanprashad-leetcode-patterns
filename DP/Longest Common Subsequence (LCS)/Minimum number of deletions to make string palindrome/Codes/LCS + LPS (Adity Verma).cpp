//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

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

int minDeletions(string str, int n)
{
    // complete the function here
    // LPS = Longest Palindromic Subsequence
    // Length of LPS is proportional to 1/(# of deletions)

    // So we need to find out the min number of delections for making str a palindrome
    // We will have to find the LPS(s) = LCS(s, revserse s)

    // min # of deletions = s.length - LPS

    int lengthOfLPS = longestPalindromeSubseq(str);
    return str.size() - lengthOfLPS;
}