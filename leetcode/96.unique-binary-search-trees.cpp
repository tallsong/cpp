/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

#include <vector>
#include <iostream>
// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        std::vector<unsigned int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i{1}; i <= n; ++i)
        {
            for (int j{1}; j <= i; ++j)
            {
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }
        return dp.back();
    }
    
};
// @lc code=end

int main()
{
    Solution s;
    std::cerr << s.numTrees(32);
    return 0;
}
