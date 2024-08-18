#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->prev = head;
        node->next = temp;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *node)
    {
        Node *currPrev = node->prev;
        Node *currNext = node->next;
        currPrev->next = currNext;
        currNext->prev = currPrev;
        size--;
    }
};

class LFUCache
{
private:
    map<int, Node *> keyNode;     // maps values to nodes
    map<int, List *> freqListMap; // maps frequency values to List
    int maxSizeCache;             // given in the question
    int minFreq;
    int currSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreqListMap(Node *node)
    {
        // Remove the values of the node
        keyNode.erase(node->key);
        // Erase the frequency of the node from the freq map
        freqListMap[node->cnt]->removeNode(node);
        // Check if the current node was the least frequency
        // And if the lease frquency list is empty, we need to pick the next frequenct element
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }
        // Updte the frquency and update this list
        List *nextHigherFreqList = new List();
        if (freqListMap.count(node->cnt + 1))
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    int get(int key)
    {
        if (keyNode.count(key))
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
        {
            return;
        }
        if (keyNode.count(key))
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            // If this list is full
            if (currSize == maxSizeCache)
            {
                // Least freq list
                List *list = freqListMap[minFreq];
                // Delete the least recently used in the above list
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.count(minFreq))
            {
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */