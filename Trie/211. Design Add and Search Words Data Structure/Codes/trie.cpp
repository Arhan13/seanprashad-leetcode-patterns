#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *links[26];
    bool flag = false;

    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }

    void put(char c, TrieNode *node)
    {
        links[c - 'a'] = node;
    }

    TrieNode *get(char c)
    {
        return links[c - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class WordDictionary
{
private:
    TrieNode *root;

    bool searchInTrie(string &word, TrieNode *node, int index)
    {
        if (index == word.size())
        {
            return node->isEnd();
        }

        char c = word[index];
        if (c == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->links[i] && searchInTrie(
                                          word,
                                          node->links[i],
                                          index + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if (!node->containsKey(c))
            {
                return false;
            }
            return searchInTrie(word, node->get(c), index + 1);
        }
    }

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
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
        node->setEnd();
    }

    bool search(string word)
    {
        return searchInTrie(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */