#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void backtracking(int n, vector<vector<int>> &ans, vector<int> &currentSet, double currentProduct, int currentIndex)
    {
        if (currentProduct > n)
        {
            return;
        }
        if (currentProduct == n)
        {
            ans.push_back(currentSet);
        }
        for (int i = currentIndex; i <= floor(n / currentProduct); i++)
        {
            if (n % i == 0 && i != n)
            {
                currentSet.push_back(i);
                backtracking(n, ans, currentSet, currentProduct * i, i);
                currentSet.pop_back();
            }
        }
        return;
    }

public:
    vector<vector<int>> getFactors(int n)
    {
        if (n == 1)
        {
            return {};
        }
        vector<vector<int>> ans;
        // As we go from 2 to n-1
        //  int currentIndex = 2;
        vector<int> currentSet = {};
        // int currentProduct = 1;
        backtracking(n, ans, currentSet, 1, 2);
        return ans;
    }
};