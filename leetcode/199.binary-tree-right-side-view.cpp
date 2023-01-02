/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

#include <iostream>
#include <vector>
#include <queue>

// 14:18
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
    std::vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> result;
        std::queue<TreeNode *> queue;
        if (root)
            queue.push(root);
        while (!queue.empty())
        {
            result.push_back(queue.front()->val);
            const auto size{queue.size()};
            for (int i{0}; i < size; ++i)
            {
                auto child{queue.front()};
                queue.pop();
                if (child->right)
                    queue.push(child->right);
                if (child->left)
                    queue.push(child->left);
            }
        }
        return result;
    }
};
// @lc code=end
