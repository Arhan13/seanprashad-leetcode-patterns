#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *links[26];
    string word = "";

    bool containsKey(char c)
    {
        return links[c - 'a'];
    }

    TrieNode *get(char c)
    {
        return links[c - 'a'];
    }

    void put(char c, TrieNode *node)
    {
        links[c - 'a'] = node;
    }

    void setEnd(string _word)
    {
        word = _word;
    }
    bool isEnd()
    {
        return word.size() > 0;
    }
};

class Solution
{
private:
    int n = 0;
    int m = 0;
    void insert(string word, TrieNode *root)
    {
        int wordLen = word.size();
        TrieNode *node = root;
        for (int i = 0; i < wordLen; i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd(word);
    }

    TrieNode *buildTrie(vector<string> &words, TrieNode *root)
    {
        for (string &word : words)
        {
            insert(word, root);
        }
        return root;
    }

    void dfs(int i, int j, vector<vector<char>> &board, vector<string> &ans, TrieNode *root)
    {
        char currChar = board[i][j];
        if (currChar == '$' || !root->containsKey(currChar))
        {
            return;
        }
        // If we hit the end of a word, we need to append it in ans
        // Make a copy of the root in node
        TrieNode *node = root;
        // Get the node
        node = node->get(currChar);
        if (node->isEnd())
        {
            ans.push_back(node->word);
            node->word = "";
        }
        board[i][j] = '$';
        // Check all the neighbours
        if (i > 0)
        {
            dfs(i - 1, j, board, ans, node);
        }
        if (j > 0)
        {
            dfs(i, j - 1, board, ans, node);
        }
        if (i < n - 1)
        {
            dfs(i + 1, j, board, ans, node);
        }
        if (j < m - 1)
        {
            dfs(i, j + 1, board, ans, node);
        }
        board[i][j] = currChar;
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        n = board.size();
        m = board[0].size();
        vector<string> ans;
        TrieNode *root = new TrieNode();
        // Build the trie
        root = buildTrie(words, root);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(i, j, board, ans, root);
            }
        }
        return ans;
    }
};