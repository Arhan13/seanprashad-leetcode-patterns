#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        vector<int> tab(n + 1, 0);
        tab[0] = 0;
        tab[1] = 1;
        tab[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            tab[i] = tab[i - 1] + tab[i - 2] + tab[i - 3];
        }
        return tab[n];
    }
};