/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <vector>
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        for (int i{0}; i < m; ++i)
            dp.at(i).at(0) = 1;
        for (int i{0}; i < n; ++i)
            dp.at(0).at(i) = 1;
        for (int i{1}; i < m; ++i)
        {
            for (int j{1}; j < n; ++j)
            {
                dp.at(i).at(j) = dp.at(i - 1).at(j) + dp.at(i).at(j - 1);
            }
        }
        return dp.at(m - 1).at(n - 1);
    }
};
// @lc code=end
