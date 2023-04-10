/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
// @lc code=start

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i{1}; i <= amount; ++i)
        {
            for (auto coin : coins)
            {
                if (coin <= i && dp[i - coin] != INT_MAX)
                {
                    dp[i] = std::min(dp[i - coin] + 1, dp[i]);
                }
            }
        }

        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};
// @lc code=end

int main()
{

    std::vector<int> v{1, 2, 5};
    Solution s;
    std::cerr << s.coinChange(v, 11);
    return 0;
}