/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

#include <vector>
#include <stack>
#include <iostream>
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
class Solution_recursive
{

public:
    std::vector<int> result;
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        if (root)
        {
            result.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return result;
    }
};

class Solution
{

public:
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        std::vector<int> result;
        std::stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            auto font{stk.top()};
            stk.pop();
            result.push_back(font->val);
            if (font->right)
                stk.push(font->right);
            if (font->left)
                stk.push(font->left);
        }
        return result;
    }
};

// @lc code=end

int main()
{
    TreeNode *t2{new TreeNode(2)};
    TreeNode *t4{new TreeNode(4, t2, nullptr)};
    TreeNode *t3{new TreeNode(3, nullptr, nullptr)};
    TreeNode *t1{new TreeNode(1, t4, t3)};
    Solution s;
    for (auto i : s.preorderTraversal(t1))
    {
        std::cerr << i << '\t';
    }
    return 0;
}