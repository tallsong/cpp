/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
// @lc code=start

class Solution
{
public:
    std::vector<std::vector<int>> results;
    std::vector<int> result;
    void help(std::vector<int>& nums, std::vector<int> result)
    {
        if (result.size() == nums.size())
            results.push_back(result);
        for (auto num : nums)
        {
            if (std::ranges::count(result, num))
                continue;
            result.push_back(num);
            help(nums, result);
            result.pop_back();
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        result.clear();
        results.clear();
        help(nums, result);
        return results;
    }
};
// @lc code=end

int main()
{
    std::vector<int> nums{0, 1};
    Solution s;
    s.permute(nums);
    return 0;
}
