/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *answer;
    bool helper(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
        {
            return false;
        }
        bool lson{helper(root->left, p, q)};
        bool rson{helper(root->right, p, q)};
        if ((lson && rson) || ((root == p || root == q) && (lson || rson)))
            answer = root;
        return lson || rson || root == p || root == q;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        helper(root, p, q);
        return answer;
    }
};
// @lc code=end
