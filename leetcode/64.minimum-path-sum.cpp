/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include <vector>

// @lc code=start
class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        auto m{grid.size()};
        auto n{grid.at(0).size()};
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        dp.at(0).at(0) = grid.at(0).at(0);
        for (int i{1}; i < m; ++i)
            dp.at(i).at(0) = dp.at(i - 1).at(0) + grid.at(i).at(0);
        for (int j{1}; j < n; ++j)
            dp.at(0).at(j) = dp.at(0).at(j - 1) + grid.at(0).at(j);
        for (int i{1}; i < m; ++i)
        {
            for (int j{1}; j < n; ++j)
            {
                dp.at(i).at(j) = std::min(dp.at(i - 1).at(j), dp.at(i).at(j - 1)) + grid.at(i).at(j);
            }
        }
        return dp.at(m - 1).at(n - 1);
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::vector<std::vector<int>> v1{{1, 2, 3}, {4, 5, 6}};
    s.minPathSum(v1);
    return 0;
}