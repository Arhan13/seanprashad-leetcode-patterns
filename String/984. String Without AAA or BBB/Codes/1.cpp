#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        string ans = "";
        if (a < 3 && b < 3)
        {
            ans += string(a, 'a');
            ans += string(b, 'b');
            return ans;
        }
        int a3Set = a / 3;
        int a3Rem = a % 3;
        int b3Set = b / 3;
        int b3Rem = b % 3;

        while (a3Set > 0 || b3Set > 0)
        {
            if (a3Set > 0)
            {
                a3Set--;
                ans += string(3, 'a');
            }
            else
            {
                if (a3Rem > 0)
                {
                    a3Rem--;
                    ans += string(1, 'a');
                }
            }
            if (b3Set > 0)
            {
                b3Set--;
                ans += string(3, 'b');
            }
            else
            {
                if (b3Rem > 0)
                {
                    b3Rem--;
                    ans += string(1, 'b');
                }
            }
        }
        if (a3Rem > 0)
        {
            ans += string(a3Rem, 'a');
        }
        if (b3Rem > 0)
        {
            ans += string(b3Rem, 'b');
        }
        return ans;
    }
};