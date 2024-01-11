#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        if (deadendsSet.count("0000"))
        {
            return -1;
        }
        if (target == "0000")
        {
            return 0;
        }
        int n = target.size();
        unordered_map<char, char> nextDigit = {
            {'0', '1'},
            {'1', '2'},
            {'2', '3'},
            {'3', '4'},
            {'4', '5'},
            {'5', '6'},
            {'6', '7'},
            {'7', '8'},
            {'8', '9'},
            {'9', '0'}};
        unordered_map<char, char> previousDigit;
        for (auto x : nextDigit)
        {
            previousDigit[x.second] = x.first;
        }
        string initialCombination = "0000";
        queue<string> q;
        q.push(initialCombination);
        unordered_map<string, int> steps;
        steps[initialCombination] = 0;
        while (q.size() > 0)
        {
            string currCombination = q.front();
            q.pop();
            // We can move one of the four lock codes
            // So we need to iterate over all the combinations
            for (int i = 0; i < n; i++)
            {
                // Next digit combination
                string newCombination = currCombination.substr(0, i) +
                                        nextDigit[currCombination[i]] +
                                        currCombination.substr(i + 1);
                if (steps.find(newCombination) == steps.end() &&
                    !deadendsSet.count(newCombination))
                {
                    q.push(newCombination);
                    steps[newCombination] = steps[currCombination] + 1;
                    if (newCombination == target)
                    {
                        return steps[newCombination];
                    }
                }
                // Pervious digit combination
                newCombination = currCombination.substr(0, i) +
                                 previousDigit[currCombination[i]] +
                                 currCombination.substr(i + 1);
                if (steps.find(newCombination) == steps.end() &&
                    !deadendsSet.count(newCombination))
                {
                    q.push(newCombination);
                    steps[newCombination] = steps[currCombination] + 1;
                    if (newCombination == target)
                    {
                        return steps[newCombination];
                    }
                }
            }
        }
        return -1;
    }
};