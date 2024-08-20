#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int index = 0;
        long miss = 1;
        int patches = 0;
        while (miss <= target)
        {
            if (index < n && coins[index] <= miss)
            {
                miss += coins[index];
                index++;
            }
            else
            {
                // We need to patch
                miss += miss;
                patches++;
            }
        }
        return patches;
    }
};