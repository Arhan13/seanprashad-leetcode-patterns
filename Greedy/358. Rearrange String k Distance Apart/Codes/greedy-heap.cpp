#include <bits/stdc++.h>
using namespace std;

#define pic pair<int, char>

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// One line intuition: We need to make sure that the most frequent character is not repeated within k characters
// So we need to store the most frequent character in a heap and pop it out after k characters
// We need to store the popped out characters in a temporary storage and push them back after k characters
// We need to make sure that the heap is not empty and the temporary storage is empty
// If the heap is empty and the temporary storage is not empty, then we need to return an empty string
// If the heap is not empty and the temporary storage is empty, then we need to return the string

class Solution
{
public:
    string rearrangeString(string s, int k)
    {
        string ans = "";
        if (k == 0 || k == 1)
        {
            return s;
        }
        priority_queue<pic> maxH;
        vector<int> freq(26, 0);
        for (char x : s)
        {
            freq[x - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                maxH.push(make_pair(freq[i], i + 'a'));
            }
        }
        if (maxH.size() < k)
        {
            return "";
        }
        vector<pic> tempStorage;
        while (!maxH.empty())
        {
            int counter = k;
            while (counter > 0 && maxH.size() > 0)
            {
                counter--;
                pic ele = maxH.top();
                int tempChar = ele.second;
                int tempVal = ele.first;
                maxH.pop();
                tempVal--;
                ans += tempChar;
                if (tempVal > 0)
                {
                    tempStorage.push_back(make_pair(tempVal, tempChar));
                }
            }
            if (counter > 0 && maxH.size() == 0)
            {
                // Need to add 1 frquency edge case
                if (tempStorage.size() == 0)
                {
                    return ans;
                }
                else if (tempStorage.size() > 0)
                {
                    return "";
                }
            }
            // Push the elements that were poped
            for (pic x : tempStorage)
            {
                maxH.push(x);
            }
            tempStorage = {};
        }
        return ans;
    }
};