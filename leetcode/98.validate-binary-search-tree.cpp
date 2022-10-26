/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */
#include <iostream>
#include <climits>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool helper(TreeNode *root, long long lower, long long upper)
    {
        if (!root)
            return true;
        if (root->val > lower && root->val < upper)
            return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// @lc code=end

int main()
{
    TreeNode *t3{new TreeNode(3)};
    TreeNode *t7{new TreeNode(7)};
    TreeNode *t6{new TreeNode(6, t3, t7)};

    TreeNode *t4{new TreeNode(4)};
    TreeNode *t5{new TreeNode(5, t4, t6)};
    Solution s;
    auto flag{s.isValidBST(t5)};
    if (flag)
    {
        std::cerr << "ok!";
    }

    return 0;
}