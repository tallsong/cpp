/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <vector>
#include <algorithm>
// @lc code=start

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        std::vector<int> dp{std::vector<int>(amount + 1, amount + 1)};

        dp[0] = 0;
        for (int i{1}; i <= amount; ++i)
        {
            for (int j{0}; j < int(coins.size()); ++j)
            {
                if (coins[j] <= i)
                {

                    dp[i] = std::min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }
        return dp[amount] > amount?-1 : dp[amount];
    }
};
// @lc code=end
