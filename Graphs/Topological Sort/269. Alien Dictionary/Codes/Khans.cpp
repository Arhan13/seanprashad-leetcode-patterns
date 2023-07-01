#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;

        // Initialize in-degree for all characters
        for (string word : words)
        {
            for (char c : word)
            {
                inDegree[c] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.length(), word2.length());
            int flag = 0;
            for (int j = 0; j < len; j++)
            {
                char c1 = word1[j];
                char c2 = word2[j];

                if (c1 != c2)
                {
                    graph[c1].push_back(c2);
                    inDegree[c2]++;
                    flag = 1;
                    break;
                }
            }
            if (word1.size() > word2.size() && flag == 0)
            {
                return "";
            }
        }

        // Perform topological sort using BFS
        queue<char> q;

        for (auto &entry : inDegree)
        {
            if (entry.second == 0)
            {
                q.push(entry.first);
            }
        }

        string result;

        while (!q.empty())
        {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : graph[curr])
            {
                inDegree[neighbor]--;

                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        if (result.length() != inDegree.size())
        {
            return "";
        }

        return result;
    }
};