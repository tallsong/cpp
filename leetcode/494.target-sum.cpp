/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

#include <vector>

// @lc code=start
class Solution
{
public:
    size_t result{0};
    void dfs(std::vector<int> &nums, int target, int sum, size_t depth)
    {
        if (depth < nums.size())
        {
            dfs(nums, target, sum + nums.at(depth), depth + 1);
            dfs(nums, target, sum - nums.at(depth), depth + 1);
        }
        else
        {
            if (sum ==target)
                ++result;
        }
    }
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        dfs(nums,target,0,0);
        return result;
    }
};
// @lc code=end

int main()
{
    return 0;
}