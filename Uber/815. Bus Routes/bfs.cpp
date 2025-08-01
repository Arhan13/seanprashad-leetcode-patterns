#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
        {
            return 0;
        }
        int n = routes.size(); // Size of the graph
        vector<int> adj[n];
        // for(int i=0;i<n;i++){
        //     //Now we need the two edges
        //     //The current nodes index is the first node
        //     //The other edge can be a couple of different edges
        //     for(int j=0;j<n;j++){
        //         //Same route case
        //         if(i==j){
        //             continue;
        //         }
        //         //Now we need to check if there is connect between two bus routes
        //         for(int& stop : routes[i]){
        //             if(find(routes[j].begin(), routes[j].end(), stop) != routes[j].end()){
        //                 if(find(adj[i].begin(), adj[i].end(), j) == adj[i].end()){
        //                     adj[i].push_back(j);
        //                     adj[j].push_back(i);
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }
        unordered_map<int, vector<int>> stopsToRoutes;
        for (int i = 0; i < n; i++)
        {
            for (int stop : routes[i])
            {
                stopsToRoutes[stop].push_back(i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            set<int> connectedRoutes;
            for (int stop : routes[i])
            {
                for (int route : stopsToRoutes[stop])
                {
                    if (route != i)
                    {
                        connectedRoutes.insert(route);
                    }
                }
            }
            for (int route : connectedRoutes)
            {
                adj[i].push_back(route);
            }
        }
        // Now we do a BFS here to find the number
        queue<int> q;               // Queue contains the bus routes
        unordered_set<int> visited; // Visted bus routes
        int buses = 1;
        vector<int> startBusRoutes = {};
        vector<int> endBusRoutes = {};
        for (int i = 0; i < n; i++)
        {
            if (find(routes[i].begin(), routes[i].end(), source) != routes[i].end())
            {
                startBusRoutes.push_back(i);
            }
            if (find(routes[i].begin(), routes[i].end(), target) != routes[i].end())
            {
                endBusRoutes.push_back(i);
            }
        }
        if (startBusRoutes.empty() || endBusRoutes.empty())
            return -1;
        // When start and end bus route is the same
        for (int i = 0; i < endBusRoutes.size(); i++)
        {
            if (find(startBusRoutes.begin(), startBusRoutes.end(), endBusRoutes[i]) != startBusRoutes.end())
            {
                return 1;
            }
        }
        for (int i = 0; i < startBusRoutes.size(); i++)
        {
            q.push(startBusRoutes[i]);
            visited.emplace(startBusRoutes[i]);
        }
        while (q.size() > 0)
        {
            int currSize = q.size();
            for (int i = 0; i < currSize; i++)
            {
                int currBusRoute = q.front();
                q.pop();
                if (find(routes[currBusRoute].begin(), routes[currBusRoute].end(), target) != routes[currBusRoute].end())
                {
                    return buses;
                }
                for (int &neighbour : adj[currBusRoute])
                {
                    if (visited.count(neighbour))
                    {
                        continue;
                    }
                    q.push(neighbour);
                    visited.emplace(neighbour);
                }
            }
            buses++;
        }
        return -1;
    }
};