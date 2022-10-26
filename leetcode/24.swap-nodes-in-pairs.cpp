/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *point{head};
        while (point && point->next)
        {
            std::swap(point->val, point->next->val);
            point=point->next->next;
        }
        return head;
    }
};
// @lc code=end
