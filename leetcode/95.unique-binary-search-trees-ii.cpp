/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

#include <vector>

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
    std::vector<TreeNode *> _generateTrees(int start, int end)
    {
        if (start > end)
            return {nullptr};
        std::vector<TreeNode *> result;
        for (int i{start}; i <= end; ++i)
        {
            auto left_trees = _generateTrees(start, i - 1);
            auto right_trees = _generateTrees(i + 1, end);
            for (auto left : left_trees)
            {
                for (auto right : right_trees)
                {
                    auto node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    result.emplace_back(node);
                }
            }
        }
        return result;
    }
    std::vector<TreeNode *> generateTrees(int n)
    {
        return _generateTrees(1, n);
    }
};
// @lc code=end

int main()
{
    Solution s;
    auto a = s.generateTrees(3);
    return 0;
}