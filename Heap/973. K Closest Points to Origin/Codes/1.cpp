#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(nlogk)
// Space complexity: O(n)
// Approach: Using max heap
//  1. Create a max heap of size k
//  2. Traverse the points vector and calculate the distance of each point from the origin
//  3. If the size of the max heap is less than k, then push the distance and the point in the max heap
//  4. Else if the top element of the max heap is greater than the distance, then pop the top element and push the distance and the point in the max heap
//  5. At the end, the max heap will contain the k closest points to the origin
//  6. Push the points of the max heap in the answer vector and return it

// Intution : We are using max heap because we want to store the k closest points to the origin
//            and we want to store the points in the decreasing order of their distance from the origin
//            So, we will store the points in the max heap and if the size of the max heap
//            becomes greater than k, then we will pop the top element of the max heap
//            So, at the end, the max heap will contain the k closest points to the origin

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        // We have min distance so we will use max heap
        // Might make a mistake using a int instead of float
        priority_queue<pair<float, pair<int, int>>> maxH;
        for (auto x : points)
        {
            float distance = sqrt(pow(x[0], 2) + pow(x[1], 2));
            if (maxH.size() < k)
            {
                maxH.push(make_pair(distance, make_pair(x[0], x[1])));
            }
            else if (maxH.top().first > distance)
            {
                maxH.pop();
                maxH.push(make_pair(distance, make_pair(x[0], x[1])));
            }
        }
        while (maxH.size() > 0)
        {
            pair<float, pair<int, int>> ele = maxH.top();
            maxH.pop();
            ans.push_back({ele.second.first, ele.second.second});
        }
        return ans;
    }
};