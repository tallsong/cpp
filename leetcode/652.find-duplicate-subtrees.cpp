/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */

#include <functional>
#include <unordered_map>
#include <vector>
#include <string>
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
    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        std::unordered_map<int, int> count;
        std::unordered_map<std::string, int> string_id;
        std::vector<TreeNode *> result;
        std::function<int(TreeNode *)> travel = [&count, &result, &travel, &string_id](TreeNode *node) -> int
        {
            if (!node)
            {
                return 0;
            }
            std::string represtation = std::to_string(travel(node->left)) + "," + std::to_string(node->val) + "," + std::to_string(travel(node->right));
            if (!string_id.count(represtation))
            {
                string_id[represtation] = string_id.size() + 1;
            }

            auto id = string_id[represtation];
            ++count[id];
            if (count[id] == 2)
            {
                result.push_back(node);
            }
            return id;
        };
        travel(root);

        return result;
    }
};

// @lc code=end

int main()
{

    TreeNode *n2{new TreeNode(1)};
    TreeNode *n3{new TreeNode(1)};
    TreeNode *n1{new TreeNode(2, n2, n3)};

    Solution s;
    auto v{s.findDuplicateSubtrees(n1)};
    return 0;
}
