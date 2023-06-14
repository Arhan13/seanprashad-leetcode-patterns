#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(nlogn)
// Space complexity: O(n)

/// Approach: Using max heap
//  1. Create a map to store the frequency of each character
//  2. Create a max heap
//  3. Traverse the map and push the elements in the max heap
//  4. At the end, the max heap will contain the characters in the decreasing order of their frequency
//  5. Now, we will pop the top 2 elements from the max heap and append them to the answer string
//  6. We will decrease the frequency of the popped elements by 1 and if the frequency is greater than 0,
//     then we will push the element in the max heap
//  7. We will repeat the above steps until the size of the max heap becomes 1
//  8. If the size of the max heap is greater than 1, then we will return an empty string
//  9. Else, we will append the last element of the max heap to the answer string and return it

// Intution : We are using max heap because we want to store the characters in the decreasing order of their frequency
//            So, we will store the characters in the max heap and if the size of the max heap
//            becomes greater than 1, then we will pop the top 2 elements of the max heap
//            So, at the end, the max heap will contain only 1 element
//            If the size of the max heap is greater than 1, then we will return an empty string
//            Else, we will append the last element of the max heap to the answer string and return it

class Solution
{
public:
    string reorganizeString(string s)
    {
        string ans = "";
        unordered_map<char, int> ump;
        // We need a max heap as we need the most used chars on the top
        priority_queue<pair<int, char>> maxH;
        for (auto x : s)
        {
            ump[x]++;
        }
        for (auto y : ump)
        {
            maxH.push(make_pair(y.second, y.first));
        }
        while (maxH.size() > 1)
        {
            pair<int, char> ele1 = maxH.top();
            maxH.pop();
            pair<int, char> ele2 = maxH.top();
            maxH.pop();
            ans += ele1.second;
            ans += ele2.second;
            ele1.first--;
            ele2.first--;
            if (ele1.first > 0)
            {
                maxH.push(ele1);
            }
            if (ele2.first > 0)
            {
                maxH.push(ele2);
            }
        }
        cout << ans << endl;
        if (maxH.size() > 0)
        {
            if (maxH.top().first > 1)
            {
                return "";
            }
            else
            {
                ans += maxH.top().second;
            }
        }
        return ans;
    }
};