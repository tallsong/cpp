/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

#include <vector>
#include <unordered_map>
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start

// Definition for a Node.

class Solution1
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *dummy = new Node(0);
        Node *cur{dummy};
        Node *cur_origin{head};
        std::vector<Node *> origin_address;
        std::vector<Node *> result_address;
        while (cur_origin)
        {
            Node *node = new Node(cur_origin->val);
            cur->next = node;
            cur = cur->next;
            origin_address.push_back(cur_origin);
            result_address.push_back(node);
            cur_origin = cur_origin->next;
        }
        cur_origin = head;
        cur = dummy->next;
        while (cur_origin)
        {
            if (cur_origin->random)
            {
                auto it = std::find(origin_address.begin(), origin_address.end(), cur_origin->random);
                cur->random = result_address.at(it - origin_address.begin());
            }
            cur_origin = cur_origin->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};

class Solution2
{
public:
    std::unordered_map<Node *, Node *> cache_node;
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        if (!cache_node.count(head))
        {
            Node *new_node{new Node(head->val)};
            cache_node[head] = new_node;
            new_node->next = copyRandomList(head->next);
            new_node->random = copyRandomList(head->random);
        }
        return cache_node[head];
    }
};


// @lc code=end

int main()
{
    return 0;
}