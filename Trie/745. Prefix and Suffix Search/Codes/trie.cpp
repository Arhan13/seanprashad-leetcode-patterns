#include <bits/stdc++.h>
using namespace std;

struct Node
{

    // This an array of Node* that point to various node from a to z
    Node *links[28] = {nullptr};
    int index = -1;

    // Check if the character exists in the links array
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    // Put the ch in links
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    // Get the node that ch points to
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // To set end, we will make flag as true
    // To check if the current node is the end node
    void setIndex(int _index)
    {
        index = _index;
    }
    int getIndex()
    {
        return index;
    }
};

class Trie
{
private:
    // Declare root node here
    Node *root;

public:
    Trie()
    {
        // Initialize root node here
        root = new Node();
    }

    void insert(string word, int index)
    {
        // Make a copy of the node
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                // If the node does not contains the word[i], then we create a new node and insert it
                node->put(word[i], new Node());
            }
            // Now we need to move to the next node
            node = node->get(word[i]);
            node->setIndex(index);
        }
    }

    int startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return -1;
            }
            node = node->get(prefix[i]);
        }
        return node->getIndex();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class WordFilter
{
private:
    Trie *trie;

public:
    WordFilter(vector<string> &words)
    {
        trie = new Trie();
        for (int i = 0; i < words.size(); i++)
        {
            string currWord = words[i];
            string temp = "|";
            temp += currWord;
            for (int j = currWord.size() - 1; j >= 0; j--)
            {
                temp = currWord[j] + temp;
                trie->insert(temp, i);
            }
        }
    }

    int f(string pref, string suff)
    {
        string s = suff + "|" + pref;
        int res = trie->startsWith(s);
        return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */