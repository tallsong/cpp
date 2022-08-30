/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <vector>
#include <unordered_map>

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    std::unordered_map<Node *, Node *> visted;
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        if (visted.count(node))
            return visted.at(node);
        Node *target_node{new Node(node->val)};
        visted[node] = target_node;
        for (auto neigbor : node->neighbors)
        {
            target_node->neighbors.emplace_back(cloneGraph(neigbor));
        }
        return target_node;
    }
};
// @lc code=end
