#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *links[26];
    bool flag = false;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
        flag = false;
    }
    // containsKey
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    // put
    void put(char ch, TrieNode *node)
    {
        links[ch - 'a'] = node;
    }
    // get
    TrieNode *get(char ch)
    {
        return links[ch - 'a'];
    }
    // isEnd
    bool isEnd()
    {
        return flag;
    }
    // setEnd
    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
private:
    TrieNode *root = new TrieNode();

public:
    void insert(string word, TrieNode *node)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

public:
    TrieNode *buildTrie(vector<string> &words, TrieNode *root)
    {
        for (string word : words)
        {
            insert(word, root);
        }
        return root;
    }
};

class Solution
{
private:
    bool dfs(string word, TrieNode *root, int currentIndex, int wordCount)
    {
        int wordSize = word.size();
        if (currentIndex >= wordSize)
        {
            return wordCount > 1;
        }
        TrieNode *node = root;
        for (int i = currentIndex; i < wordSize; i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
            if (node->isEnd())
            {
                if (dfs(word, node, currentIndex + 1, wordCount + 1))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ans = {};
        Trie *trie = new Trie();
        TrieNode *root = new TrieNode();
        root = trie->buildTrie(words, root);
        for (string word : words)
        {
            if (dfs(word, root, 0, 0))
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};