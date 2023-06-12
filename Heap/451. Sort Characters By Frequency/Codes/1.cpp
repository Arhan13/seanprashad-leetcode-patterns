#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        string ans = "";
        unordered_map<char, int> ump;
        // We need a max heap because we need the characters in decreasing order
        priority_queue<pair<int, char>> maxH;
        // We need to store the frequency of each character
        for (auto x : s)
        {
            ump[x]++;
        }
        // We need to push the characters in the heap according to their frequency
        for (auto x : ump)
        {
            maxH.push(make_pair(x.second, x.first));
        }
        // We need to pop the characters from the heap and add them to the ans string
        while (maxH.size() > 0)
        {
            pair<int, char> ele = maxH.top();
            while (ele.first--)
            {
                ans += ele.second;
            }
            maxH.pop();
        }
        return ans;
    }
};