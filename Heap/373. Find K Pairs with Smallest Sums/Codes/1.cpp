#include <bits/stdc++.h>
using namespace std;

/*
The time complexity of the given code is O(k * m * log(k)),
where m is the size of the smaller array. This is because we are iterating over both arrays and performing heap operations which take log(k) time.
The space complexity is O(k) because we are storing at most k elements in the heap.
*/
// One line intution - We need to store the pairs in a vector and we need a max heap because we will store the pairs in decreasing order. So the bottom k pairs will be the smallest pairs.
// One line approach - We need to store the pairs in a vector and we need a max heap because we will store the pairs in decreasing order. So the bottom k pairs will be the smallest pairs.
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // We need to store the pairs in a vector
        vector<vector<int>> ans;
        // We need a max heap because we will store the pairs in decreasing order
        // So the bottom k pairs will be the smallest pairs
        priority_queue<pair<int, pair<int, int>>> maxH;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                pair<int, int> currentPair = make_pair(nums1[i], nums2[j]);
                // If the size of the heap is less than k, then we can push the current pair
                if (maxH.size() < k)
                {
                    maxH.push(make_pair(sum, currentPair));
                }
                // If the size of the heap is equal to k, then we need to compare the sum of the current pair with the sum of the top element of the heap
                // If the sum of the current pair is less than the sum of the top element of the heap, then we need to pop the top element of the heap and push the current pair
                else if (sum < maxH.top().first)
                {
                    maxH.pop();
                    maxH.push(make_pair(sum, currentPair));
                }
                // If the sum of the current pair is greater than the sum of the top element of the heap, then we need to break the loop
                // Because the array is sorted, so the sum of the current pair will be greater than the sum of the next pair
                else
                {
                    break;
                }
            }
        }
        while (maxH.size() > 0)
        {
            pair<int, pair<int, int>> ele = maxH.top();
            ans.push_back({ele.second.first, ele.second.second});
            maxH.pop();
        }
        return ans;
    }
};