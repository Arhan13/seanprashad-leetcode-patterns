#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct node
    {
        int data;
        int arrIndex;
        int colIndex;

        node(int _data, int _arrIndex, int _colIndex)
        {
            data = _data;
            arrIndex = _arrIndex;
            colIndex = _colIndex;
        }
    };
    // Why is this so?
    struct compare
    {
        bool operator()(node a, node b)
        {
            return a.data > b.data;
        }
    };

public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> ans;
        priority_queue<node, vector<node>, compare> minH;
        int rows = nums.size() - 1;
        int cols = nums[0].size() - 1;

        int maxEle = INT_MIN;
        int minEle = INT_MAX;

        for (int i = 0; i <= rows; i++)
        {
            // We need to push the first elements from each of the lists in the priority queue
            node _d(nums[i][0], i, 0);
            minH.push(_d);
            maxEle = max(maxEle, nums[i][0]);
            minEle = min(minEle, nums[i][0]);
        }

        int rangeStart = minEle;
        int rangeEnd = maxEle;
        int minRange = maxEle - minEle;
        while (true)
        {
            node currData = minH.top();
            int currArrIndex = currData.arrIndex;
            int currColIndex = currData.colIndex;
            int nextColIndex = currColIndex + 1;
            minH.pop();
            // We have reached the maximum capacity of a list
            if (currColIndex + 1 == nums[currArrIndex].size())
            {
                break;
            }
            // We will check the next element in the list where the min element is, the min element is basically the top of the heap
            int nextVal = nums[currArrIndex][nextColIndex]; // next element in the current array
            maxEle = max(maxEle, nextVal);
            node _d(nextVal, currArrIndex, nextColIndex);
            minH.push(_d);
            node newMinEle = minH.top();
            int newMinValue = newMinEle.data;
            int range = maxEle - newMinValue;
            if (range < minRange)
            {
                rangeStart = newMinValue;
                rangeEnd = maxEle;
                minRange = range;
            }
        }
        ans.push_back(rangeStart);
        ans.push_back(rangeEnd);
        return ans;
    }
};