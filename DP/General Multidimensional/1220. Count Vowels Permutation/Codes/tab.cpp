#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long int MOD = 1e9 + 7;

public:
    int countVowelPermutation(int n)
    {
        // a e i o u
        // We will make 5 vectors
        vector<long long int> aMemo(n, 0);
        vector<long long int> eMemo(n, 0);
        vector<long long int> iMemo(n, 0);
        vector<long long int> oMemo(n, 0);
        vector<long long int> uMemo(n, 0);

        // For length of 1, each vowel has 1 possiblity

        aMemo[0] = 1;
        eMemo[0] = 1;
        iMemo[0] = 1;
        oMemo[0] = 1;
        uMemo[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int prev = i - 1;
            aMemo[i] = (eMemo[prev] + iMemo[prev] + uMemo[prev]) % MOD;
            eMemo[i] = (aMemo[prev] + iMemo[prev]) % MOD;
            iMemo[i] = (eMemo[prev] + oMemo[prev]) % MOD;
            oMemo[i] = iMemo[prev] % MOD;
            uMemo[i] = (iMemo[prev] + oMemo[prev]) % MOD;
        }

        int ans = (aMemo[n - 1] + eMemo[n - 1] + iMemo[n - 1] + oMemo[n - 1] + uMemo[n - 1]) % MOD;
        return ans;
    }
};