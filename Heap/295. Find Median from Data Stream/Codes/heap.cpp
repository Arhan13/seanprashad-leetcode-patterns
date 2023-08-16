#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> lo;                            // max heap
    priority_queue<int, vector<int>, greater<int>> hi; // min heap

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // lo = max heap = mostly stores the numbers that are smaller than the median
        // hi = min heap = mostly stores the numbers that are larger than the median
        // Add the number to the heap
        // So we will first insert it into the max heap ie 'lo'
        lo.push(num);
        // Now we need to do the balancing step
        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian()
    {
        // The lo heap will have at worst one more element than the hi heap
        return lo.size() > hi.size() ? lo.top() : ((double)lo.top() + hi.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */