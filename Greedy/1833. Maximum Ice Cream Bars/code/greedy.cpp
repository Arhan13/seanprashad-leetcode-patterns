#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int count = 0;
        sort(costs.begin(), costs.end());
        int i = 0;
        while (coins > 0 && i < costs.size())
        {
            if (coins - costs[i] >= 0)
            {
                count++;
                coins -= costs[i];
            }
            i++;
        }
        return count;
    }
};