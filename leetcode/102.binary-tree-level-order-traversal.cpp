/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */
#include <vector>
#include <iostream>
#include<queue>
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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        if(!root)
            return result;
        std::queue<TreeNode*>q;
        q.emplace(root);
        while (!q.empty())
        {
            result.push_back({});
            auto q_szie{q.size()};
            for(auto i{0};i<q_szie;++i)
            {
                auto font{q.front()};
                q.pop();
                result.back().push_back(font->val);
                if(font->left)
                    q.push(font->left);
                if(font->right)
                    q.push(font->right);

            }
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
    auto rrr{s.levelOrder(t1)};
    return 0;
}