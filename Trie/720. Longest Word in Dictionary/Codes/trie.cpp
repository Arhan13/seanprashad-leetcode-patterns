#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *links[26];
    bool flag = false;

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
    void setEnd()
    {
        flag = true;
    }
    // Check if the word ends at this node
    bool isEnd()
    {
        return flag;
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
    TrieNode *buildTrie(vector<string> words, TrieNode *root)
    {
        for (auto word : words)
        {
            insert(word, root);
        }
        return root;
    }

public:
    bool checkIfWordAndWordPrefixExist(string word, TrieNode *node)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

public:
    bool isLongestPossibleWord(string currentLongestWord, TrieNode *root, string possibleLongestWord)
    {
        if (checkIfWordAndWordPrefixExist(possibleLongestWord, root))
        {
            for (int i = 1; i < possibleLongestWord.size(); i++)
            {
                string prefix = possibleLongestWord.substr(0, i);
                if (!checkIfWordAndWordPrefixExist(prefix, root))
                {
                    return false;
                }
            }
            if (currentLongestWord.size() > possibleLongestWord.size())
            {
                return false;
            }
            else if (currentLongestWord.size() < possibleLongestWord.size())
            {
                return true;
            }
            else if (currentLongestWord.size() == possibleLongestWord.size())
            {
                return possibleLongestWord < currentLongestWord;
            }
        }
        return false;
    }
};

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        Trie *trie = new Trie();
        string ans = "";
        TrieNode *root = new TrieNode();
        root = trie->buildTrie(words, root);
        for (auto word : words)
        {
            if (trie->isLongestPossibleWord(ans, root, word))
            {
                ans = word;
            }
        }
        return ans;
    }
};