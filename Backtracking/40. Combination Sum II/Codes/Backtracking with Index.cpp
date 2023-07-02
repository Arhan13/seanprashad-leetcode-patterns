#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
// This is the solution for the problem 40. Combination Sum II in LeetCode, which can be found at https://leetcode.com/problems/combination-sum-ii/
// This is the solution using backtracking with index
// The solution is similar to the solution of 39. Combination Sum, but we have to skip over duplicates
//--Time & Space Complexity--//
// The time complexity is O(2^n) and the space complexity is O(n)
//--------------------------------------------------------------------//
// Interview question: What is the difference between the solution of 39. Combination Sum and 40. Combination Sum II?
// Answer: The solution of 39. Combination Sum doesn't have to skip over duplicates, but the solution of 40. Combination Sum II has to skip over duplicates
//--------------------------------------------------------------------//
// Interview question: How do you skip over duplicates?
// Answer: We can skip over duplicates by sorting the candidates vector and then skipping over the duplicates
// We can skip over duplicates by using the following code:
// while (currentIndex < candidates.size() - 1 && candidates[currentIndex] == candidates[currentIndex + 1])
// {
//     currentIndex++;
// }
// This code will skip over all the duplicates
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

class Solution
{
public:
    void findCombinations(
        vector<vector<int>> &ans,
        vector<int> candidates,
        vector<int> &currentCandidates,
        int currentIndex,
        int currentTarget)
    {

        // Check if the currentTarget is less than equal to 0
        if (currentTarget <= 0 || currentIndex >= candidates.size())
        {
            // If target is equal to 0, the we need to add it to the solution
            if (currentTarget == 0)
            {
                // sort(currentCandidates.begin(), currentCandidates.end());
                ans.push_back(currentCandidates);
            }
            return;
        }
        // Now we have two cases,
        // We either continue with the current element
        int currentElement = candidates[currentIndex];
        if (currentElement <= currentTarget)
        {
            currentCandidates.push_back(currentElement);
            findCombinations(
                ans,
                candidates,
                currentCandidates,
                currentIndex + 1,
                currentTarget - currentElement);
            currentCandidates.pop_back();
        }
        // Or we don't continue with the current element and move to the next element
        while (currentIndex < candidates.size() - 1 && candidates[currentIndex] == candidates[currentIndex + 1])
        {
            currentIndex++;
        }
        findCombinations(
            ans,
            candidates,
            currentCandidates,
            currentIndex + 1,
            currentTarget);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> currentCandidates = {};
        int currentIndex = 0;
        // Sort the candidates vector to skip over duplicates
        sort(candidates.begin(), candidates.end());
        findCombinations(
            ans,
            candidates,
            currentCandidates,
            currentIndex,
            target);

        return ans;
    }
};
