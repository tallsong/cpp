/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

#include <stack>
#include <iostream>
#include <vector>

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> f(n + 1);
        for (int i{1}; i <= n; ++i)
        {
            int minn{INT_MAX};
            for (int j{1}; j * j <= i; ++j)
                minn = std::min(minn, f.at(i - j * j));
            f.at(i) = minn + 1;
        }
        return f.at(n);
    }
};


// @lc code=end

int main()
{
    Solution s;
    std::cerr << s.numSquares(12);
}
