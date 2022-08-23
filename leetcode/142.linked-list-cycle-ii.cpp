/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

#include <iostream>

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast{head};
        ListNode *slow{head};
        while (slow && slow->next && fast->next && fast->next->next)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {

                ListNode *ptr{head};
                while (slow != ptr)
                {
                    slow = slow->next;
                    ptr = ptr->next;
                }

                return ptr;
            }
        }
        return nullptr;
    }
};

// @lc code=end

int main()
{
    ListNode *p1 = new ListNode(3);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(0);
    ListNode *p4 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p2;
    Solution s;
    std::cerr << s.detectCycle(p1)->val;

    return 0;
}
