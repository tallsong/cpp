/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <vector>
#include <iostream>

// @lc code=start
class Solution
{
public:
    std::vector<int> t;
    std::vector<std::vector<int>> ans;

    void dfs(int cur, std::vector<int> &nums)
    {
        if (cur == nums.size())
        {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        dfs(0, nums);
        return ans;
    }
};

// @lc code=end
int main()
{
    std::vector<int> nums{1, 2, 3};
    Solution s;
    s.subsets(nums);
    return 0;
}