#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestArithSeqLength(vector<int> &A)
    {
        int ans = 0;
        vector<map<int, int>> dp(A.size());
        for (int i = 1; i < A.size(); i++)
        { // Iterate over the array
            for (int j = 0; j < i; j++)
            {                           // For the current element, check against all elements before it
                int diff = A[i] - A[j]; // Calculate the difference between current element and previous element
                // The state is represented by current index i and difference diff
                // If there already exists such a state, we use the maximum value of existing one and current
                // Otherwise we start from 2
                dp[i][diff] = max(2, 1 + dp[j][diff]);
                ans = max(ans, dp[i][diff]); // Update the maximum value
            }
        }
        return ans; // Return the maximum value
    }
};