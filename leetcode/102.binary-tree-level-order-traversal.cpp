/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */
#include <iostream>
#include <queue>
#include <vector>
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
class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> result;
        q.push(root);
        while (!q.empty())
        {
            std::vector<int> temp;
            // 注意这里的q长度会变必须要提前取出来
            auto width = q.size();
            for (int i{0}; i < width; ++i)
            {

                auto node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(temp);
        }

        return result;
    }
};
// @lc code=end

int main()
{
    TreeNode* t2{new TreeNode(2)};
    TreeNode* t4{new TreeNode(4, t2, nullptr)};
    TreeNode* t3{new TreeNode(3, nullptr, nullptr)};
    TreeNode* t1{new TreeNode(1, t4, t3)};
    Solution s;
    auto rrr{s.levelOrder(t1)};
    return 0;
}