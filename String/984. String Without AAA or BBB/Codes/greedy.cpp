#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        string ans = "";
        char c1 = 'a';
        char c2 = 'b';
        if (b > a)
        {
            swap(a, b);
            swap(c1, c2);
        }
        while (a > 0 || b > 0)
        {
            if (a > 0)
            {
                ans += c1;
                a--;
            }
            if (a > b)
            {
                ans += c1;
                a--;
            }
            if (b > 0)
            {
                ans += c2;
                b--;
            }
        }
        return ans;
    }
};