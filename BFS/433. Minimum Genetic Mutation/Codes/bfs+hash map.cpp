#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        // We will store the distances of each of the string from the start string
        map<string, int> distance;
        distance[startGene] = 0;
        queue<string> q;
        q.push(startGene);
        while (q.size())
        {
            string topEle = q.front();
            q.pop();
            for (string newEle : bank)
            {
                if (distance.count(newEle))
                {
                    continue;
                }
                int diff = 0;
                for (int i = 0; i < topEle.size(); i++)
                {
                    if (topEle[i] != newEle[i])
                    {
                        diff++;
                    }
                }
                if (diff == 1)
                {
                    distance[newEle] = distance[topEle] + 1;
                    q.push(newEle);
                }
            }
        }
        if (distance.count(endGene) > 0)
        {
            return distance[endGene];
        }
        else
        {
            return -1;
        }
    }
};