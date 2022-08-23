/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return nullptr;

        int length{0};
        ListNode *cur{head};
        while (cur)
        {
            ++length;
            cur = cur->next;
        }
        k %= length;
        if (!k)
            return head;
        ListNode *new_head{nullptr};
        ListNode *dummy{new ListNode(0, head)};
        ListNode *fast{dummy};
        ListNode *slow{dummy};
        for (int i{0}; i < k; ++i)
        {
            fast = fast->next;
        }
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        new_head = slow->next;
        slow->next = nullptr;
        fast->next = head;
        delete dummy;
        return new_head;
    }
};
// @lc code=end

