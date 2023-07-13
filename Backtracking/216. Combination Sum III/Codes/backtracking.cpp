#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^n)
// Time Complexity is O(2^n) because we have to find all the combinations of k numbers that add up to a number n, where only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//  Space Complexity: O(2^n)
//  Space complexity is O(2^n) because we have to store all the combinations in the answer vector.
//  Backtracking
//  One line intution : We have to find all the combinations of k numbers that add up to a number n, where only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
// Approach - We will use backtracking to solve this problem. We will use a recursive function to find all the combinations of k numbers that add up to a number n, where only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

class Solution
{
public:
    void backtrackingSolve(
        vector<vector<int>> &ans,
        vector<int> &candidates,
        vector<int> &currentCandidates,
        int currentIndex,
        int currentTarget,
        int k)
    {
        if (currentTarget == 0 && k == 0)
        {
            ans.push_back(currentCandidates);
            return;
        }
        if (currentIndex >= candidates.size() || currentTarget < 0 || k < 0)
        {
            return;
        }
        int currentElement = candidates[currentIndex];
        if (currentElement <= currentTarget)
        {
            currentCandidates.push_back(currentElement);
            backtrackingSolve(ans, candidates, currentCandidates, currentIndex + 1, currentTarget - currentElement, k - 1);
            currentCandidates.pop_back();
        }
        // Now we move to the next index
        backtrackingSolve(ans, candidates, currentCandidates, currentIndex + 1, currentTarget, k);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans = {};
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> currentCandidates = {};
        int currentIndex = 0;
        backtrackingSolve(ans, candidates, currentCandidates, currentIndex, n, k);
        return ans;
    }
};