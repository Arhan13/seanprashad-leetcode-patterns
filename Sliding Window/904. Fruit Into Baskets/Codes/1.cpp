#include <bits/stdc++.h>
using namespace std;

// Approach 1: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int type1 = fruits[0];
        int type2 = -1;
        int type1Count = 0;
        int type2Count = 0;
        int maxCount = 0;
        int l = 0; // window start
        for (int i = 0; i < (int)fruits.size(); i++)
        {
            int currentFruit = fruits[i];
            // If current fruit is of type1
            if (currentFruit == type1)
            {
                type1Count++;
                maxCount = max(maxCount, type1Count + type2Count);
            }
            // If current fruit is of type2
            else if (type2 == currentFruit || type2 == -1)
            {
                type2 = currentFruit;
                type2Count++;
                maxCount = max(maxCount, type1Count + type2Count);
            }
            // If the current fruit is not of type1 and type2
            else
            {
                // We will have to remove one of the elements from the basket
                // So check which element becomes empty it will be the oldest element in the pair
                while (type1Count > 0 && type2Count > 0)
                {
                    if (fruits[l] == type1)
                    {
                        type1Count--;
                    }
                    else
                    {
                        type2Count--;
                    }
                    l++;
                }
                if (type1Count == 0)
                {
                    type1 = currentFruit;
                    type1Count = 1;
                }
                else
                {
                    type2 = currentFruit;
                    type2Count = 1;
                }
            }
        }
        return maxCount;
    }
};