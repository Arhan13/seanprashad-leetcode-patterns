#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }

    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
        return;
    }

    Node *get(char c)
    {
        return links[c - 'a'];
    }

    void setEnd()
    {
        flag = true;
        return;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */