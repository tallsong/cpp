/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include <unordered_set>
// @lc code=start
class Solution
{
    std::vector<std::vector<int>> outputs;
    std::vector<int> subset;

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
    {

        std::ranges::sort(nums);
        outputs.clear();
        subset.clear();
        helper(nums, 0);
        return outputs;
    }
    void helper(std::vector<int>& nums, int start)
    {
        outputs.push_back(subset);
        unordered_set<int> hash;
        for (int i{start}; i < nums.size(); ++i)
        {
            if (hash.count(nums[i]))
            {
                continue;
            }
            hash.insert(nums[i]);
            subset.push_back(nums[i]);
            helper(nums, i + 1);
            subset.pop_back();
        }
    }
};

// @lc code=end
