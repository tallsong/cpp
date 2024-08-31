/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <iostream>
#include <vector>

// dfs 分为两种, 一种是 每个数字选or不选构成的二叉树, 另一种是当前的subset添加不同的元素构成的叉树

// @lc code=start
class Solution
{
public:
    std::vector<int> current;
    std::vector<std::vector<int>> ans;
    // 一个binary treek, 表示每个坐标的上的element 是否加入当前的current, 最后生成2^n个结果
    void dfs(int cur, std::vector<int>& nums)
    {
        if (cur == nums.size())
        {
            ans.push_back(current);
            return;
        }
        current.push_back(nums[cur]);
        dfs(cur + 1, nums);
        current.pop_back();
        dfs(cur + 1, nums);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        dfs(0, nums);
        return ans;
    }
};

class Solution_cascading
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> outputs;
        outputs.push_back({});

        for (auto num : nums)
        {
            std::vector<std::vector<int>> temps;
            // output is a copy instead of reference
            for (auto output : outputs)
            {
                auto temp{output};
                temp.push_back(num);
                temps.push_back(temp);
            }
            for (auto& temp : temps)
            {
                outputs.push_back(temp);
            }
        }
        return outputs;
    }
};
class Solution_Backtracking
{
    std::vector<std::vector<int>> outputs;
    std::vector<int> subset;

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {

        outputs.clear();
        subset.clear();
        helper(nums, 0);
        return outputs;
    }
    void helper(std::vector<int>& nums, int start)
    {
        outputs.push_back(subset);
        for (int i{start}; i < nums.size(); ++i)
        {
            subset.push_back(nums[i]);
            helper(nums, i + 1);
            subset.pop_back();
        }
    }
};

// [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]

// [[1,2,3],[1,2],[1,3],[1],[2,3],[2],[3],[]]
class SolutioSolution_Backtrackingn_DIY
{
public:
    vector<vector<int>> outputs;
    vector<int> current;
    vector<vector<int>> subsets(vector<int>& nums)
    {

        back_tracing(0, nums);
        return outputs;
    }
    void back_tracing(int index, vector<int>& nums)
    {
        if (nums.size() == index)
        {
            outputs.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        back_tracing(index + 1, nums);
        current.pop_back();
        back_tracing(index + 1, nums);
    }
};

// @lc code=end
int main()
{
    std::vector<int> nums{1, 2, 3};
    Solution_Backtracking s;
    for (auto arr_arr : s.subsets(nums))
    {
        for (auto arr : arr_arr)
        {
            std::cerr << arr << '\t';
        }
        std::cerr << '\n';
    }

    return 0;
}