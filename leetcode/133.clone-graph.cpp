/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <vector>
#include <unordered_map>
#include <queue>
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

class Solution_dfs
{
public:
    std::unordered_map<Node *, Node *> hashtable;
    Node *cloneGraph(Node *node)
    {

        if (!node)
            return nullptr;
        if (hashtable.count(node))
            return hashtable[node];
        Node *new_node = new Node(node->val);
        hashtable[node] = new_node;

        for (auto &neighbor : node->neighbors)
        {
            new_node->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return new_node;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return node;
        }

        unordered_map<Node *, Node *> visited;

        // 将题目给定的节点添加到队列
        queue<Node *> Q;
        Q.push(node);
        // 克隆第一个节点并存储到哈希表中
        visited[node] = new Node(node->val);

        // 广度优先搜索
        while (!Q.empty())
        {
            // 取出队列的头节点
            auto n = Q.front();
            Q.pop();
            // 遍历该节点的邻居
            for (auto &neighbor : n->neighbors)
            {
                if (visited.find(neighbor) == visited.end())
                {
                    // 如果没有被访问过，就克隆并存储在哈希表中
                    visited[neighbor] = new Node(neighbor->val);
                    // 将邻居节点加入队列中
                    Q.push(neighbor);
                }
                // 更新当前节点的邻居列表
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {

        if (!node)
            return nullptr;
        std::unordered_map<Node *, Node *> hashtable;
        std::queue<Node *> q;
        q.push(node);
        hashtable[node] = new Node(node->val);
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            for (auto &neighbor : front->neighbors)
            {
                if (!hashtable.count(neighbor))
                {
                    Node *new_neighbor = new Node(neighbor->val);

                    hashtable[neighbor] = new_neighbor;
                    q.push(neighbor);
                }
                hashtable[front]->neighbors.emplace_back(hashtable[neighbor]);
            }
        }
        return hashtable[node];
    }
};

// @lc code=end
