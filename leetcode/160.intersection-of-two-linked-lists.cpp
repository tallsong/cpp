/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == headB)
            return headA;
        bool skipA{false};
        bool skipB{false};
        ListNode *pointA{headA};
        ListNode *pointB{headB};
        while (pointA != pointB)
        {
            if (!skipA && !pointA->next)
            {
                skipA = true;
                pointA = headB;
            }
            else
            {
                if (!pointA->next)
                    return nullptr;
                pointA = pointA->next;
            }
            if (!skipB && !pointB->next)
            {
                skipB = true;
                pointB = headA;
            }
            else
            {
                if (!pointB->next)
                {
                    return nullptr;
                }
                pointB = pointB->next;
            }
        }

        return pointA;
    }
};
// @lc code=end

int test1()
{
    ListNode *a1 = new ListNode(4);
    ListNode *a2 = new ListNode(1);
    ListNode *a3 = new ListNode(8);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    ListNode *b1 = new ListNode(5);
    ListNode *b2 = new ListNode(6);
    ListNode *b3 = new ListNode(1);
    b1->next = b2;
    b2->next = b3;
    b3->next = a3;

    Solution s;
    auto var{s.getIntersectionNode(a1, b1)};

    return 0;
}

int main()
{
    ListNode *a1 = new ListNode(2);
    ListNode *a2 = new ListNode(3);
    a1->next = a2;
    Solution s;
    auto var{s.getIntersectionNode(a2, a1)};

    return 0;
}