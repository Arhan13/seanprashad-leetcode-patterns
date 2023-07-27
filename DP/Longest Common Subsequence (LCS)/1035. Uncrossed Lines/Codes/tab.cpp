#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> tab(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            for (int j = nums2.size() - 1; j >= 0; j--)
            {
                if (nums1[i] == nums2[j])
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