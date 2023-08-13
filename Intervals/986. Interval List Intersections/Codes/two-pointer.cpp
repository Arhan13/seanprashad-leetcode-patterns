#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> ans;
        int p1 = 0;
        int p2 = 0;
        if (firstList.size() == 0 || secondList.size() == 0)
        {
            return ans;
        }
        while (p1 < firstList.size() && p2 < secondList.size())
        {
            // There is no intersection
            // Second list elements are ahead of first list elements
            if (firstList[p1][1] < secondList[p2][0])
            {
                // We will move pointer 1 ahead
                p1++;
            }
            // When the first list if ahead of the second list
            else if (firstList[p1][0] > secondList[p2][1])
            {
                // We will move pointer 2 ahead
                p2++;
            }
            // Now we check the cases of intersection
            // When l2 is ahead, so we will move p1 after recording the intersection
            else if (secondList[p2][0] <= firstList[p1][1])
            {
                vector<int> _temp = {max(firstList[p1][0], secondList[p2][0]), min(firstList[p1][1], secondList[p2][1])};
                ans.push_back(_temp);
                if (firstList[p1][1] < secondList[p2][1])
                {
                    p1++;
                }
                else
                {
                    p2++;
                }
            }
            else if (firstList[p1][0] <= secondList[p2][1])
            {
                vector<int> _temp = {max(firstList[p1][0], secondList[p2][0]), min(firstList[p1][1], secondList[p2][1])};
                ans.push_back(_temp);
                p2++;
                if (firstList[p1][1] < secondList[p2][1])
                {
                    p1++;
                }
                else
                {
                    p2++;
                }
            }
        }
        return ans;
    }
};