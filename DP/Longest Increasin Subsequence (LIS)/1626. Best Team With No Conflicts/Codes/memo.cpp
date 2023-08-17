#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int currIndex, vector<pair<int, int>> &playerData, int lastIndex, vector<vector<int>> &memo)
    {
        if (currIndex == playerData.size())
        {
            return 0;
        }
        if (memo[currIndex][lastIndex + 1] != -1)
        {
            return memo[currIndex][lastIndex + 1];
        }
        int take = 0;
        // We can only take an older player if their score is more than or equal to a younger player
        if (lastIndex == -1 || playerData[currIndex].second >= playerData[lastIndex].second)
        {
            take = playerData[currIndex].second + solve(currIndex + 1, playerData, currIndex, memo);
        }
        int didNotTake = solve(currIndex + 1, playerData, lastIndex, memo);
        return memo[currIndex][lastIndex + 1] = max(take, didNotTake);
    }

public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        vector<pair<int, int>> playerData;
        for (int i = 0; i < scores.size(); i++)
        {
            playerData.push_back(make_pair(ages[i], scores[i]));
        }
        sort(playerData.begin(), playerData.end());
        vector<vector<int>> memo(scores.size(), vector<int>(scores.size() + 1, -1));
        return solve(0, playerData, -1, memo);
    }
};