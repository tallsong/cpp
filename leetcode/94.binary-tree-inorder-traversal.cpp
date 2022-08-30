/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

#include <vector>
#include <stack>
#include <unordered_set>
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

class Solution_recursize
{
public:
    void recursize(TreeNode *root, std::vector<int> &v)
    {
        if (!root)
            return;
        if (root->left)
        {
            recursize(root->left, v);
        }
        v.push_back(root->val);
        if (root->right)
        {
            recursize(root->right, v);
        }
    }
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> v;
        recursize(root, v);
        return v;
    }
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        std::stack<TreeNode *> stack;
        while(root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root=root->left;
            }
            root=stack.top();
            stack.pop();
            result.push_back(root->val);
            root=root->right;
            
        }
        return result;
    }
};

// @lc code=end

int main()
{
    TreeNode *node3{new TreeNode(3)};
    TreeNode *node2{new TreeNode(2, node3, nullptr)};
    TreeNode *node1{new TreeNode(1, nullptr, node2)};
    Solution s;
    s.inorderTraversal(node1);

    return 0;
}
