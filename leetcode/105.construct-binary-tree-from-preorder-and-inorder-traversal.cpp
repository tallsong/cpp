/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

#include <iostream>
#include <unordered_map>
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
        int point{0};
        std::unordered_map<int, int> map;
        TreeNode *helper(int start, int end, std::vector<int> &preorder, std::vector<int> &inorder)
        {
            if (start > end)
                return nullptr;
            auto index{map.at(preorder.at(point))};
            TreeNode *root{new TreeNode(preorder.at(point++))};
            root->left = helper(start, index - 1, preorder, inorder);
            root->right = helper(index + 1, end, preorder, inorder);
            return root;
        }
        TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
        {

            for (int i{0}; i < inorder.size(); ++i)
            {
                map[inorder.at(i)] = i;
            }
            return helper(0, int(preorder.size()) - 1, preorder, inorder);
        }
    };
// @lc code=end

int main()
{
    Solution;
    std::vector<int> pre{3, 9, 20, 15, 7};
    std::vector<int> in{9, 3, 15, 20, 7};
}
