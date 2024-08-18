#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution
{
private:
    int n = 0;
    bool inBounds(int i)
    {
        return (i >= 0 && i < n);
    }

public:
    int candy(vector<int> &ratings)
    {
        n = ratings.size();
        if (n == 0)
        {
            return 0;
        }
        vi candies(n, 1);
        // Moving left to right
        for (int i = 1; i < n; i++)
        {
            int left = i - 1;
            if (ratings[i] > ratings[left])
            {
                candies[i] = max(candies[i], candies[left] + 1);
            }
        }

        // Move from right to left
        for (int i = n - 2; i >= 0; i--)
        {
            int right = i + 1;
            if (ratings[i] > ratings[right])
            {
                candies[i] = max(candies[i], candies[right] + 1);
            }
        }
        int totalCandies = 0;
        for (int i = 0; i < n; i++)
        {
            totalCandies += candies[i];
        }
        return totalCandies;
    }
};