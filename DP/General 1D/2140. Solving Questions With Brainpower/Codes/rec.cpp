#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long solve(vector<vector<int>> &questions, int currentIndex, int skips)
    {
        if (currentIndex >= questions.size())
        {
            return 0;
        }
        // If skips = 0, then you can include that question in your sequence
        if (skips <= 0)
        {
            long long ifWeSkip = solve(questions, currentIndex + 1, skips - 1);
            long long ifWeTake = questions[currentIndex][0] + solve(questions, currentIndex + 1, questions[currentIndex][1]);
            return max(ifWeSkip, ifWeTake);
        }
        else
        {
            // Logic for skipping and moving ahead
            long long ifWeSkip = solve(questions, currentIndex + 1, skips - 1);
            return ifWeSkip;
        }
    }

public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        return solve(questions, 0, 0);
    }
};