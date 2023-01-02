/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>

// @lc code=start

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {

        int pre{0};
        // notice that we assign max_sum nums[0] instead of 0 bacause of test cast [-1]
        int max_sum{nums[0]};
        for (const auto num : nums)
        {
            pre = std::max(pre + num, num);
            max_sum = std::max(pre, max_sum);
        }
        return max_sum;
    }
};
// @lc code=end
