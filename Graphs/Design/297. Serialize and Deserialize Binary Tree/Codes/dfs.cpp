#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    void serializeDfs(TreeNode *node, vector<string> &nodes)
    {
        if (!node)
        {
            nodes.push_back("x");
            return;
        }
        // Now if its a valid node
        // We need to check the child nodes
        nodes.push_back(to_string(node->val));
        serializeDfs(node->left, nodes);
        serializeDfs(node->right, nodes);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        vector<string> nodes = {};
        serializeDfs(root, nodes);
        string serializedBuffer = "";
        for (string s : nodes)
        {
            serializedBuffer += s + " ";
        }
        return serializedBuffer;
    }

    TreeNode *deserializeHelper(vector<string> &nodes, int &index)
    {
        string val = nodes[index];
        index++;
        if (val == "x")
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(val));
        node->left = deserializeHelper(nodes, index);
        node->right = deserializeHelper(nodes, index);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> nodes;
        string val = "";
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ' ')
            {
                nodes.push_back(val);
                val = "";
            }
            else
            {
                val += data[i];
            }
        }
        if (val != "")
        {
            nodes.push_back(val);
        }
        int index = 0;
        return deserializeHelper(nodes, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));