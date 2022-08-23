/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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



class Solution {
public:
     ListNode *reverseList(ListNode *head)
    {
        if ((!head))
        {
            return nullptr;
        }
        ListNode *pre{nullptr};
        ListNode *cur{head};
        while (cur)
        {
            ListNode *next{cur->next};
            cur->next=pre;
             pre=cur;
             cur=next;

        }
        return pre;

    }
};



// @lc code=end
