#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    vector<string> getNgb(string currWord, unordered_set<string> &unvisitedWords)
    {
        vector<string> unvisitedNgb;
        for (int i = 0; i < currWord.size(); i++)
        {
            for (char c : alphabets)
            {
                string newWord = currWord.substr(0, i) + c + currWord.substr(i + 1);
                if (unvisitedWords.count(newWord))
                {
                    unvisitedNgb.push_back(newWord);
                    unvisitedWords.erase(newWord);
                }
            }
        }
        return unvisitedNgb;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (beginWord == endWord)
        {
            return 0;
        }
        unordered_set<string> unvisitedWords(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int distance = 0;
        unvisitedWords.erase(beginWord);
        while (q.size() > 0)
        {
            int n = q.size();
            distance += 1;
            for (int i = 0; i < n; i++)
            {
                string currWord = q.front();
                q.pop();
                for (string ngb : getNgb(currWord, unvisitedWords))
                {
                    if (ngb == endWord)
                    {
                        return distance + 1;
                    }
                    q.push(ngb);
                }
            }
        }
        return 0;
    }
};