#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *links[26];
    string word = "";

    // Check if the node is connected to this char
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    // Get the TrieNode that the char points to
    TrieNode *get(char ch)
    {
        return links[ch - 'a'];
    }
    // Put the char in the trie
    void put(char ch, TrieNode *node)
    {
        links[ch - 'a'] = node;
    }
    // Set the end to the word
    void setEnd(string _word)
    {
        word = _word;
    }
    // Check if the word ends at this node
    bool isEnd()
    {
        return word.size() > 0;
    }
};

class Solution
{
private:
    void insert(string word, TrieNode *node)
    {
        // We need to insert the word in the Trie
        for (int i = 0; i < word.size(); i++)
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
        for (string word : words)
        {
            insert(word, root);
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *root, vector<string> &ans)
    {
        char currentChar = board[i][j];
        // If the ch == '#;
        // If the ch is the first letter of the word
        if (currentChar == '#' || !root->containsKey(currentChar))
        {
            return;
        }
        TrieNode *node = root;
        node = node->get(currentChar);
        if (node->isEnd())
        {
            ans.push_back(node->word);
            // Erase the word
            node->word = "";
        }
        board[i][j] = '#';
        if (i > 0)
        {
            dfs(board, i - 1, j, node, ans);
        }
        if (j > 0)
        {
            dfs(board, i, j - 1, node, ans);
        }
        if (i < board.size() - 1)
        {
            dfs(board, i + 1, j, node, ans);
        }
        if (j < board[0].size() - 1)
        {
            dfs(board, i, j + 1, node, ans);
        }
        board[i][j] = currentChar;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        vector<string> ans = {};
        root = buildTrie(words, root);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};