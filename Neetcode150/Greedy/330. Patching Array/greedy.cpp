#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int patches = 0;
        int index = 0;
        long miss = 1;
        while (miss <= n)
        {
            if (index < nums.size() && nums[index] <= miss) // miss is covered
            {
                miss += nums[index];
                index += 1;
            }
            else
            {
                // We patch the array with miss that why we do miss += miss
                // And add a path
                miss += miss;
                patches++; // increase the answer
            }
        }
        return patches;
    }
};