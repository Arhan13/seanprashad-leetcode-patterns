#include <bits/stdc++.h>
using namespace std;

#define pic pair<int, char>

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n == 0)
        {
            return tasks.size();
        }
        int ans = 0;
        priority_queue<pic> maxH;
        vector<int> freq(26, 0);
        for (char ch : tasks)
        {
            freq[ch - 'A']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                maxH.push(make_pair(freq[i], i + 'A'));
            }
        }
        while (maxH.size() > 0)
        {
            int counter = n + 1;
            vector<pic> tempStorage = {};
            while (counter > 0 && maxH.size() > 0)
            {
                pic currEle = maxH.top();
                int currVal = currEle.first;
                char currChar = currEle.second;
                currVal--;
                ans++;
                if (currVal > 0)
                {
                    tempStorage.push_back(make_pair(currVal, currChar));
                }
                maxH.pop();
                counter--;
            }
            for (auto ele : tempStorage)
            {
                maxH.push(ele);
            }
            if (maxH.size() == 0)
            {
                break;
            }
            if (counter > 0)
            {
                ans += counter;
            }
        }
        return ans;
    }
};