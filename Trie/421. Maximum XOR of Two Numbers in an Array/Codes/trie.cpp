#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *links[2];

    TrieNode()
    {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    // To check if the node has the given bit
    bool containsKey(int bit)
    {
        return links[bit] != nullptr;
    }
    // To put a node with a given bit in the trie node
    void put(int bit, TrieNode *node)
    {
        links[bit] = node;
    }
    // To get the node with a given bit
    TrieNode *get(int bit)
    {
        return links[bit];
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

public:
    // We need a function to insert
    void insert(int num)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            // What is the meaning of the line below?
            //  We are getting the ith bit from the right
            int bit = num >> i & 1;
            if (!node->containsKey(bit))
            {
                // If the node does not contain the bit, we need to put it
                node->put(bit, new TrieNode());
            }
            // We are moving to the next node
            node = node->get(bit);
        }
    }

public:
    // We need a function to get max xor with a given number
    int findMax(int num)
    {
        TrieNode *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = num >> i & 1;
            if (node->containsKey(1 - bit))
            {
                // What is the meaning of the line below?
                // We are setting the ith bit from the right to 1
                // Why are we doing this?
                // Because we want to maximize the xor
                // If we set the ith bit to 1, we will maximize the xor
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie *trie = new Trie();
        int maxNum = 0;
        for (int num : nums)
        {
            trie->insert(num);
        }
        for (int num : nums)
        {
            maxNum = max(maxNum, trie->findMax(num));
        }
        return maxNum;
    }
};