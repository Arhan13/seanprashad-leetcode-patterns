#include <bits/stdc++.h>
using namespace std;

int binary_search(std::vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int firstTrueIndex = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (feasible(mid))
        {
            firstTrueIndex = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return firstTrueIndex;
}