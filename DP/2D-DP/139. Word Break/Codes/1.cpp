#include <bits/stdc++.h>
using namespace std;

// Bottom Up Approach
// Pattern - Unbounded Knapsack
/*
The time complexity of the unboundedKnapsack function is O(N^2 * M), where N is the length of the string s and M is the average length of the words in wordDict. This is because for each index currentIndex in the range [0, N-1], the function checks all possible substrings starting from currentIndex. Finding a substring takes O(N) time, and the find operation for each substring takes O(M) time on average.

The space complexity of the unboundedKnapsack function is O(N), where N is the length of the string s. This is because the memo vector has a size of N+1, and each recursive call creates a new frame on the call stack.

The space complexity of the wordBreak function is O(N), where N is the length of the string s. This is because the memo vector has a size of N+1.

Overall, the space and time complexity of the solution can be considered as O(N^2 * M) and O(N), respectively.
*/

class Solution
{
public:
    bool unboundedKnapsack(string s, vector<string> wordsDict, int currentIndex, vector<int> &memo)
    {
        if (currentIndex == s.size())
        {
            return true;
        }
        if (memo[currentIndex] != -1)
        {
            if (memo[currentIndex] == 0)
            {
                return false;
            }
            else if (memo[currentIndex] == 1)
            {
                return true;
            }
        }
        for (int i = currentIndex; i < s.size(); i++)
        {
            string substring = s.substr(currentIndex, i - currentIndex + 1);
            if ((find(wordsDict.begin(), wordsDict.end(), substring) != wordsDict.end()) && unboundedKnapsack(s, wordsDict, currentIndex + substring.size(), memo))
            {
                cout << substring << endl;
                memo[currentIndex] = 1;
                return true;
            }
        }
        memo[currentIndex] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> memo(s.size() + 1, -1);
        return unboundedKnapsack(s, wordDict, 0, memo);
    }
};