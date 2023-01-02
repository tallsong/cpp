/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */
#include <iostream>
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
    ListNode *sortList(ListNode *head)
    {
        return helper(head, nullptr);
    }
    ListNode *helper(ListNode *head, ListNode *tail)
    {
        if (!head)
            return nullptr;
        if (head->next == tail)
        {
            // avoid circular LinkedList
            head->next = nullptr;
            return head;
        }

        auto fast{head};
        auto slow{head};
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }

        return merge_two_list(helper(head, slow), helper(slow, tail));
    }

    ListNode *merge_two_list(ListNode *head1, ListNode *head2)
    {
        ListNode *tail{new ListNode()};
        ListNode *dummy{tail};
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                tail->next = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        if (head1)
        {
            tail->next = head1;
        }
        if (head2)
        {
            tail->next = head2;
        }
        return dummy->next;
    }
};
// @lc code=end

int main()
{
    ListNode *node1{new ListNode(3)};
    ListNode *node2{new ListNode(1, node1)};
    ListNode *node3{new ListNode(2, node2)};
    ListNode *node4{new ListNode(4, node3)};
    Solution s;
    auto node(s.sortList(node4));
    while (node)
    {
        std::cerr << '\t' << node->val;
        node = node->next;
    }
}