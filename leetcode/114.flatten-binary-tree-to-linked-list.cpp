/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root)
    {
        TreeNode *current{root};
        while (current)
        {
            if (current->left)
            {
                auto current_right{current->right};
                current->right = current->left;
                current->left=nullptr;
                auto temp{current->right};
                while (temp->right)
                {
                    temp = temp->right;
                }
                temp->right = current_right;
                current = current->right;
            }
            else
            {
                current = current->right;
            }
        }
    }
};

class Solution_DFS
{
public:
    void flatten(TreeNode* root)
    {
        helper(root);
    }
    // flatten and return last node
    TreeNode* helper(TreeNode* node)
    {
        if (!node)
        {
            return nullptr;
        }
        auto left_last = helper(node->left);
        auto right_last = helper(node->right);

        if (left_last)
        {
            left_last->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        if(right_last)
            return right_last;
        if(left_last)
            return left_last;
        return node;
    }
};
// @lc code=end


class Solution
{
public:
    void flatten(TreeNode* root)
    {

        helper(root);
    }
    TreeNode* helper(TreeNode* node)
    {
        if (!node)
            return nullptr;
        if (!node->left && !node->right)
            return node;

        auto left = helper(node->left);
        auto right = helper(node->right);
       

        if (left)
        {
             auto tail = left;
            while (tail && tail->right)
            {
                tail = tail->right;
            }
            tail->right = right;
            node->right = left;
            node->left = nullptr;
        }
        return node;
    
    }
};
int main()
{
    TreeNode *n3{new TreeNode(3)};
    TreeNode *n4{new TreeNode(4)};
    TreeNode *n2{new TreeNode(2, n3, n4)};
    TreeNode *n6{new TreeNode(6)};
    TreeNode *n5{new TreeNode(5, nullptr, n6)};
    TreeNode *n1{new TreeNode(1, n2, n5)};
    Solution s;
    s.flatten(n1);

    return 0;
}