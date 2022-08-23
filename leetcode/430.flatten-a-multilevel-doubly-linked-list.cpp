/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */
#include <iostream>
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
    Node(int x) : val(x), prev{nullptr}, next(nullptr), child(nullptr){};
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution2 {
public:
    Node* flatten(Node* head) {
        std::function<Node*(Node*)> dfs = [&](Node* node) {
            Node* cur = node;
            // 记录链表的最后一个节点
            Node* last = nullptr;

            while (cur) {
                Node* next = cur->next;
                //  如果有子节点，那么首先处理子节点
                if (cur->child) {
                    Node* child_last = dfs(cur->child);

                    next = cur->next;
                    //  将 node 与 child 相连
                    cur->next = cur->child;
                    cur->child->prev = cur;

                    //  如果 next 不为空，就将 last 与 next 相连
                    if (next) {
                        child_last->next = next;
                        next->prev = child_last;
                    }

                    // 将 child 置为空
                    cur->child = nullptr;
                    last = child_last;
                }
                else {
                    last = cur;
                    
                }
                cur = next;
            }
            return last;
        };

        dfs(head);
        return head;
    }
};



{
    public :
        Node * flatten(Node * head){
                   Node * current{head};
while (current)
{
    if (current->child)
    {

        auto child = flatten(current->child);
        Node *end{child};
        while (end->next)
        {
            end = end->next;
        }
        Node *next{current->next};
        current->next = child;
        child->prev = current;
        current->child = nullptr;
        end->next = next;
        next->prev = end;
    }
    current = current->next;
}
return head;
}
}
;
// @lc code=end

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    n1->next = n2;
    n1->child = n3;
    n1->prev = n1;
    Solution2 s;
    n1 = s.flatten(n1);
    while (n1)
    {
        std::cerr << n1->val << '\t';
        n1 = n1->next;
    }

    return 0;
}