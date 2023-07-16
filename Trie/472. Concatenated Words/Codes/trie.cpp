#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N * L^2)
// Time Complexity explanation: N is the number of words in the input list, L is the average length of words.
//                              For each word, we need to traverse the word, so the time complexity is O(N * L).
//                              For each word, we need to traverse the word again to check if it is a concatenated word,
//                              so the time complexity is O(N * L^2).
// Is this true after memoization? Yes, because the memoization is based on the word and the wordCount, so the time complexity
//                                  is O(N * L^2).
// Space Complexity: O(N * L)
// Space Complexity explanation: N is the number of words in the input list, L is the average length of words.
//                               For each word, we need to traverse the word, so the space complexity is O(N * L).

// Intution: We can use a Trie to store all the words in the input list. Then we can traverse each word in the input list, and
//           check if it is a concatenated word. We can use DFS to check if it is a concatenated word. We can use memoization
//           to optimize the time complexity.

// Logic for the DFS:
// 1. If the currentIndex is greater than or equal to the wordSize, we can return wordCount > 1.
// 2. We can get the key by concatenating the substring of the word from currentIndex to wordSize and the wordCount.
// 3. If the key is in the memo, we can return the value of the key.
// 4. We can traverse the word from currentIndex to wordSize.
// 5. If the current character is not in the Trie, we can return false.
// 6. If the current character is in the Trie, we can get the node of the current character.
// 7. If the current character is the end of a word, we can check if the rest of the word is a concatenated word.
// 8. If the rest of the word is a concatenated word, we can return true.
// 9. If the rest of the word is not a concatenated word, we can continue to traverse the word.
// 10. If the current character is not the end of a word, we can continue to traverse the word.
// 11. If we cannot find a concatenated word, we can return false.
// 12. If we can find a concatenated word, we can return true.
// 13. We can store the key and the value in the memo.

// Give me a nice leetcode solution title -
//  Trie + DFS + Memoization

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
    unordered_map<string, bool> memo;
    bool dfs(string word, TrieNode *root, int currentIndex, int wordCount)
    {
        int wordSize = word.size();
        if (currentIndex >= wordSize)
        {
            return wordCount > 1;
        }
        string key = word.substr(currentIndex, wordSize) + "-" + to_string(wordCount);
        if (memo.count(key))
        {
            return memo[key];
        }
        TrieNode *node = root;
        for (int i = currentIndex; i < wordSize; i++)
        {
            if (!node->containsKey(word[i]))
            {
                memo[key] = false;
                return false;
            }
            node = node->get(word[i]);
            if (node->isEnd())
            {
                if (dfs(word, root, i + 1, wordCount + 1))
                {
                    memo[key] = true;
                    return true;
                }
            }
        }
        memo[key] = false;
        return memo[key];
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