/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
class Solution_
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        std::stack<TreeNode*> stk;
        while (root || stk.size())
        {
            while (root)
            {

                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            --k;
            if (!k)
                return root->val;
            root = root->right;
        }

        return 0;
    }
};
// 九章
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        std::stack<TreeNode*> stack;

        while (root)
        {
            stack.push(root);
            root = root->left;
        }

        for (int i{0}; i < k - 1; ++i)
        {
            auto top = stack.top();
            stack.pop();

            if (top->right)
            {
                top = top->right;
                while (top)
                {
                    stack.push(top);
                    top = top->left;
                }
            }

            
        }
        return stack.top()->val;
    }
};

// @lc code=end
