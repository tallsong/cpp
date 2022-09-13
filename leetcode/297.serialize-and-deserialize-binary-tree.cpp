/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

#include <string>
#include <list>
#include<iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 


class Codec
{
public:
    // Encodes a tree to a single string.

    void reserialize(TreeNode *root, std::string &s)
    {
        if (!root)
        {
            s += "None,";
        }
        else
        {
            s += std::to_string(root->val) + ',';
            reserialize(root->left, s);
            reserialize(root->right, s);
        }
    }

    std::string serialize(TreeNode *root)
    {
        std::string s;
        reserialize(root, s);
        return s;
    }

    TreeNode *redeserialize(std::list<std::string>& data_array)
    {
        if (data_array.front() == "None")
        {
            data_array.erase(data_array.begin());
            return nullptr;
        }
        else
        {
            TreeNode *root{new TreeNode(std::stoi(data_array.front()))};
            data_array.erase(data_array.begin());
            root->left = redeserialize(data_array);
            root->right = redeserialize(data_array);
            return root;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        std::list<std::string> data_array;
        std::string str;
        for (auto &c : data)
        {
            if (c == ',')
            {
                data_array.push_back(str);
                str.clear();
            }
            else
            {
                // temp += c;//*****
                str.push_back(c);
            }
        }
        if (!str.empty())
        {
            data_array.push_back(str);
            str.clear();
        }
        return redeserialize(data_array);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end



int main()
{
    TreeNode* t5{new TreeNode(5)};
    TreeNode* t4{new TreeNode(4)};
    TreeNode* t3{new TreeNode(3)};
    t3->left=t4;
    t3->right=t5;
    TreeNode* t2{new TreeNode(2)};
    TreeNode* t1{new TreeNode(1)};
    t1->left=t2;
    t1->right=t3;
    Codec c;
    Codec_std c_std;

    std::cerr<<c.serialize(t1)<<'\n';
    return 0;
    


}