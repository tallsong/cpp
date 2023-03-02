/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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

class Solution_iterative
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur{dummy};
        while (list1 || list2)
        {
            if (!list2)
            {
                cur->next = list1;
                break;
            }
            if (!list1)
            {
                cur->next = list2;
                break;
            }
            if (list1->val < list2->val)
            {
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            }
        }
        return dummy->next;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
        {
            return list2;
        }
        if (!list2)
            return list1;

        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// @lc code=end

int main()
{

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    ListNode *b1 = new ListNode(1);
    ListNode *b2 = new ListNode(2);
    ListNode *b3 = new ListNode(3);
    ListNode *b4 = new ListNode(4);
    ListNode *b5 = new ListNode(5);
    b1->next = b2;
    b2->next = b3;
    b3->next = b4;
    b4->next = b5;
    Solution s;
    s.mergeTwoLists(a1, b1);
    return 0;
}