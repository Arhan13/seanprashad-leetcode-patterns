#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        long long int i = 1;
        while (i < n)
        {
            i *= 3;
        }
        return (i == n);
    }
};