#include <bits/stdc++.h>
using namespace std;

struct Node
{

    // This an array of Node* that point to various node from a to z
    Node *links[27];
    bool flag = false;

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
    void setEnd()
    {
        flag = true;
    }
    // To check if the current node is the end node
    bool isEnd()
    {
        return flag;
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

    void insert(string word)
    {
        // Make a copy of the node
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                // If the node does not contains the word[i], then we create a new node and insert it
                node->put(word[i], new Node);
            }
            // Now we need to move to the next node
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        // To search a word in the trie we will start at the root
        Node *node = root;
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

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */