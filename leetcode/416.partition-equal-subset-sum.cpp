/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include <vector>
#include <algorithm>
#include <climits>
// @lc code=start
class Solution
{
public:
    bool canPartition(std::vector<int> &nums)
    {
        int n = nums.size();
        int sum{0};
        int max_element{INT_MIN};
        for (auto num : nums)
        {
            sum += num;
            max_element = std::max(max_element, num);
        }
        if (sum % 2)
            return false;
        int target{sum / 2};
        // avoid case [100]
        if (max_element > target)
            return false;
        std::vector<std::vector<bool>> dp(n, std::vector(target + 1, false));
        for (int i{0}; i < n; ++i)
            dp[i][0] = true;
        dp[0][nums[0]] = true;

        for (int i{1}; i < n; ++i)
        {
            for (int j{1}; j <= target; ++j)
            {
                if (j >= nums[i])
                {
                    dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n - 1][sum / 2];
    }
};
// @lc code=end

int main()
{
    std::vector<int> v{1, 5, 11, 5};
    Solution s;
    s.canPartition(v);
    return 0;
}