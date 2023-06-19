#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(nlogn)
// Space complexity: O(n)

// Approach: Using min heap
//  1. Sort the intervals according to their start time
//  2. Create a min heap to store the end time of the meetings
//  3. Push the end time of the first meeting in the min heap
//  4. Traverse the intervals and check if the top of the min heap is less than the start time of the current meeting
//  5. If yes, then pop the top of the min heap and push the end time of the current meeting in the min heap
//  6. Else, push the end time of the current meeting in the min heap
//  7. At the end, the size of the min heap will be the minimum number of meeting rooms required

// Intution : We are using min heap because we want to store the end time of the meetings
//            and we want to store the end time of the meetings in the increasing order
//            So, we will store the end time of the meetings in the min heap and if the top of the min heap
//            is less than the start time of the current meeting, then we will pop the top of the min heap
//            and push the end time of the current meeting in the min heap
//            So, at the end, the size of the min heap will be the minimum number of meeting rooms required

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
        {
            return 1;
        }
        // sort(intervals.begin(), intervals.end(), [](auto a, auto b){
        //     return a[0] < b[0];
        // });
        sort(intervals.begin(), intervals.end());
        // If the mininimum end time is less than the start time of a meeting, then the meeting
        // can happen in the same room
        priority_queue<int, vector<int>, greater<int>> minH;
        minH.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (minH.top() > intervals[i][0])
            {
                minH.push(intervals[i][1]);
            }
            else
            {
                if (minH.top() < intervals[i][1])
                {
                    minH.pop();
                    minH.push(intervals[i][1]);
                }
            }
        }
        return minH.size();
    }
};