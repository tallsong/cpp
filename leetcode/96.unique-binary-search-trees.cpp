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
        std::vector<int> g(n + 1);
        g[0] = 1;
        g[1] = 1;
        for (int i{2}; i <= n; ++i)
        {
            for (int j{1}; j <= i; ++j)
            {
                g[i] += (g[j - 1] * g[i - j]);
            }
        }
        return g[n];
    }
};
// @lc code=end

int main()
{
    Solution s;
    std::cerr << s.numTrees(32);
    return 0;
}
