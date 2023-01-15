/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

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
Definition for a binary tree node.

 */
class Solution
{
public:
    int rootSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        int result{0};
        if (root->val == targetSum)
            ++result;
        result += rootSum(root->left, targetSum - root->val);
        result += rootSum(root->right, targetSum - root->val);
        return result;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        int result{0};
        result += rootSum(root, targetSum);
        result += pathSum(root->left, targetSum);
        result += pathSum(root->right, targetSum);
        return result;
    }
};

// @lc code=end
