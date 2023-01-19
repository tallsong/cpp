/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <unordered_map>
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hashtable;
        for (int i{0}; i < nums.size(); ++i)
        {
        }
        for (int i{0}; i < nums.size(); ++i)
        {
            if (hashtable.count(target - nums[i]))
                return {i, hashtable[target - nums[i]]};
            else
            {
                hashtable.insert(std::make_pair(nums[i], i));
            }
        }
        return {};
    }
};
// @lc code=end
