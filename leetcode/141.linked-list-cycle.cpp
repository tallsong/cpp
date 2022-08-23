/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start

#include<iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast{head};
        ListNode *slow{head};
        while (slow && slow->next && fast->next && fast->next->next)
        {
            if(slow->next == fast->next->next)
                return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};
// @lc code=end


int main()
{
    ListNode *p1 = new ListNode(3);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(0);
    ListNode *p4 = new ListNode(4);
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    p4->next=p2;
    Solution s;
    std::cerr<<s.hasCycle(p1);
    
    return 0;
}