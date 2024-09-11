/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    std::unordered_set<int> visited;
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {

        std::ranges::sort(nums);
        helper(nums);

        return result;
    }
    void helper(vector<int>& nums)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }
        for (int i{0}; i < nums.size(); ++i)
        {

            auto num = nums[i];
            if (visited.count(i))
                continue;
            // 如果当前的元素和上一个元素相同,并且上一个元素未加入当前的current(确保相同元素出现的顺序和nums中相同)
            // 去重方法: 相同的组合选一个代表, 只把这个代表加入结果,其他的都过滤掉.
            if (i > 0 && nums[i] == nums[i - 1] && !visited.count(i - 1))
                continue;

            current.push_back(num);
            visited.insert(i);
            helper(nums);
            visited.erase(i);
            current.pop_back();
        }
    }
};
// @lc code=end
