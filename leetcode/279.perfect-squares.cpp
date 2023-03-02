/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

#include <stack>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;
        for (int i{1}; i <= n; ++i)
        {
            int x{1};
            while (x * x <= i)
            {
                dp[i] = std::min(dp[i], dp[i - x * x] + 1);
                ++x;
            }
        }
        return dp.back();
    }
};

// @lc code=end

int main()
{
    Solution s;
    std::cerr << s.numSquares(12);
}
