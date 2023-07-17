```
[Refer to Algo Monster Article](https://algo.monster/problems/lowest_common_ancestor)

 Summary -
1. The node-x is null
2. The node-x is either node1 or node2
3. The node-x is neither node1 nor node2
The first two cases (1) and (2) are simple and we can simply return themselves immediately. That is, if the current node is null, return null; and if the current node is either node1 or node2, immediately return node1 or node2 (whichever it is). We will see later why we can do this.

Case (3) is trickier in that it also involves some case work due to it getting returned values from both its subtrees. These are the cases and their respective behaviors:

a. If both subtrees return non-null nodes: return the current node itself
b. If both subtrees return null nodes: return null
c. If exactly one of the subtrees returns a non-null node and the other returns a null node: return the non-null node
```
