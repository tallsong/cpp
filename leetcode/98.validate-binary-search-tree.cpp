/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */
#include <iostream>
#include <climits>
#include<vector>
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

class Solution_base
{
public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(std::vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        // 总是选择中间位置左边的数字作为根节点
        int mid = (left + right) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};

class Solution
{
public:
    int helper(TreeNode *root, bool is_left)
    {
        if (!root)
            return is_left ? INT_MIN : INT_MAX;
        if (!root->left && !root->right)
        {
            return root->val;
        }
        if (auto right{helper(root->right, false)}; !root->left)
        {
            
            if (is_left)
            {
                if (root->val >= right)
                {
                    return INT_MAX;
                }
                else
                {
                    return right;
                }
            }
            else
            {
                if (root->val >= right)
                    return INT_MIN;
                else
                {
                    return root->val;
                }
            }
        }
        if (!root->right)
        {
            if (auto left{root->left->val}; is_left)
            {
                if (root->val > left)
                {
                    return root->val;
                }
                else
                {
                    return INT_MAX;
                }
            }
            else
            {
                if (root->val > left)
                {
                    return root->val;
                }
                else
                {
                    return INT_MAX;
                }
            }
        }

        if (is_left)
        {
            if (root->val > helper(root->left, true) && root->val < helper(root->right, false))
                return helper(root->right, false);
            else
            {
                return INT_MAX;
            }
        }
        else
        {
            if (root->val > helper(root->left, true) && root->val < helper(root->right, false))
                return helper(root->left, true);
            else
            {
                return INT_MIN;
            }
        }
    }

    bool isValidBST(TreeNode *root)
    {
        return root->val > helper(root->left, true) && root->val < helper(root->right, false);
    }
};

// @lc code=end

int main()
{
    TreeNode *t3{new TreeNode(3)};
    TreeNode *t7{new TreeNode(7)};
    TreeNode *t6{new TreeNode(6, t3, t7)};

    TreeNode *t4{new TreeNode(4)};
    TreeNode *t5{new TreeNode(5, t4, t6)};
    Solution s;
    auto flag{s.isValidBST(t5)};
    if (flag)
    {
        std::cerr << "ok!";
    }
    Solution_base sb;
    std::vector<int> v{32, 26, 47, 19, INT_MAX, INT_MAX, 56, INT_MAX, 27};
    auto root = sb.sortedArrayToBST(v);

    if (s.isValidBST(root))
    {
        std::cerr << "ok!";
    }

    return 0;
}