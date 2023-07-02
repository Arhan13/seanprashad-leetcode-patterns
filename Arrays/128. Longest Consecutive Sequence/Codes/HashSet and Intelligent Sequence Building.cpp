#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(n)
// Space Complexity: O(n)
// One line intition - If there is no previous element in the set for the currentNumber, then we will start a new sequence from the currentNumber.
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // We will create hashmap
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int longestConsecutiveSequenceLength = 0;
        for (auto x : s)
        {
            int currentNumber = x;
            // If there is no previous element in the set for the currentNumber
            if ((s.count(x - 1) == 0))
            {
                int currentStreak = 1;
                while (s.count(currentNumber + 1) > 0)
                {
                    currentNumber += 1;
                    currentStreak += 1;
                }
                longestConsecutiveSequenceLength = max(longestConsecutiveSequenceLength, currentStreak);
            }
        }
        return longestConsecutiveSequenceLength;
    }
};