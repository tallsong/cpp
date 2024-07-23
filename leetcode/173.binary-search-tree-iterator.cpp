/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#include <stack>


class BSTIterator
{
private:
    std::stack<TreeNode*> stack;

public:
    BSTIterator(TreeNode* root)
    {
        while (root)
        {
            stack.push(roo t);
            root = root->left;
        }
    }

    int next()
    {
        auto top = stack.top();
        stack.pop();
        auto root = top->right;
        while (root)
        {
            stack.push(root);
            root = root->left;
        }

        return top->val;
    }

    bool hasNext()
    {
        return stack.size();
    }
};

int main()
{
    return 0;
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
