/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <vector>
#include <algorithm>
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        std::vector<int> dp(nums.size());
        for (int i{0}; i < nums.size(); ++i)
        {
            dp[i] = 1;
            for (int j{0}; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

// @lc code=end

int main()
{
    std::vector<int> v{8, 9, 1, 2};
    Solution s;
    s.lengthOfLIS(v);
    return 0;
}