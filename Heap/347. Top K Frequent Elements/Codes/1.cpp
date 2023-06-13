#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

#define pi pair<int, int>

// Time complexity: O(nlogk)
// Space complexity: O(n)

// Approach: Using min heap
//  1. Create a map to store the frequency of each element
//  2. Create a min heap of size k
//  3. Traverse the map and push the elements in the min heap
//  4. If the size of the min heap is greater than k, then pop the top element
//  5. At the end, the min heap will contain the k most frequent elements
//  6. Push the elements of the min heap in the answer vector and return it

// Intution : We are using min heap because we want to store the k most frequent elements
//            and we want to store the elements in the increasing order of their frequency
//            So, we will store the elements in the min heap and if the size of the min heap
//            becomes greater than k, then we will pop the top element of the min heap
//            So, at the end, the min heap will contain the k most frequent elements

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        unordered_map<int, int> ump;
        priority_queue<pi, vector<pi>, greater<pi>> minH;
        for (auto x : nums)
        {
            ump[x]++;
        }
        for (auto x : ump)
        {
            if (minH.size() < k)
            {
                minH.push(make_pair(x.second, x.first));
            }
            else if (minH.top().first < x.second)
            {
                minH.pop();
                minH.push(make_pair(x.second, x.first));
            }
        }
        while (minH.size() > 0)
        {
            pi ele = minH.top();
            ans.push_back(ele.second);
            minH.pop();
        }
        return ans;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution S;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    // cout<<S.topKFrequent(nums, k)<<endl;
    S.topKFrequent(nums, k);
    return 0;
}