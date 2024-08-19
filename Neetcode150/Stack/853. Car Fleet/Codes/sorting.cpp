#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = speed.size();
        int fleet = 0;
        if (n == 0)
        {
            return fleet;
        }
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.rbegin(), cars.rend());
        double currETA = 0.0;
        for (pair<int, double> &car : cars)
        {
            if (car.second > currETA)
            {
                fleet++;
                currETA = car.second;
            }
        }
        return fleet;
    }
};