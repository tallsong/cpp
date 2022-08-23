/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode *head)
    {

        ListNode *point{head};
        size_t length{0};
        while (point)
        {
            ++length;
            point = point->next;
        }
        std::stack<int> stack;
        point = head;
        for (int i{0}; i < length / 2; ++i)
        {
            stack.push(point->val);
            point = point->next;
        }
        if(length%2)
            point=point->next;
        while (point)
        {
            if (point->val != stack.top())
                return false;
            stack.pop();
            point = point->next;
        }
        return true;
    }
};
// @lc code=end
