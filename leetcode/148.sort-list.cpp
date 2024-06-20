/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */
#include <iostream>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
    ListNode* sortList(ListNode* head)
    {
        return helper(head, nullptr);
    }

    ListNode* helper(ListNode* head, ListNode* tail)
    {
        if (!head)
            return nullptr;

        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        auto slow = head;
        auto fast = head;

        // notice while condition and if condition
        while (fast && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast && fast->next != tail)
                fast = fast->next;
        }

        return merge_sort(helper(head, slow), helper(slow, tail));
    }

    ListNode* merge_sort(ListNode* left, ListNode* right)
    {
        auto dummy = new ListNode(0);
        auto tail = dummy;

        while (left && right)
        {
            if (left->val < right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left)
            tail->next = left;
        if (right)
            tail->next = right;

        return dummy->next;
    }
};
// @lc code=end

int main()
{
    ListNode* node1{new ListNode(3)};
    ListNode* node2{new ListNode(1, node1)};
    ListNode* node3{new ListNode(2, node2)};
    ListNode* node4{new ListNode(4, node3)};
    Solution s;
    auto node(s.sortList(node4));
    while (node)
    {
        std::cerr << '\t' << node->val;
        node = node->next;
    }
}