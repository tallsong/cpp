/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur{dummy};
        bool carry = false;
        while (l1 || l2)
        {
            int l1_value{l1 ? l1->val : 0};
            int l2_value{l2 ? l2->val : 0};
            int value{l1_value + l2_value};
            if (carry)
            {

                ++value;
                carry = false;
            }
            if (value >= 10)
            {
                carry = true;
                value %= 10;
            }
            ListNode *temp = new ListNode(value);
            cur->next = temp;
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry)
        {
            ListNode *temp = new ListNode(1);
            cur->next = temp;
        }
        return dummy->next;
    }
};
// @lc code=end
