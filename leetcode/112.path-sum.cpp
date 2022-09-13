/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */
#include <queue>
#include <utility>
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
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        std::queue<std::pair<TreeNode *, int>> q; 
        q.emplace(root, root->val);
        while (!q.empty())
        {
            auto [node, value]{q.front()};
            q.pop();
            if (!node->left && !node->right)
            {
                if (value == targetSum)
                    return true;
            }
            else
            {

                if (node->left)
                {
                    auto leftTargetSum{node->left->val + value};

                    q.emplace(node->left, leftTargetSum);
                }
                if (node->right)
                {
                    auto rightTargetSum{node->right->val + value};
                    q.emplace(node->right, rightTargetSum);
                }
            }
        }
        return false;
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

    auto rrr{s.hasPathSum(t1, 7)};
    if (rrr)
    {
        std::cerr << "get!";
    }

    return 0;
}
