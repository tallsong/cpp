/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
            return 2;
        int p{0}, q{1}, c{1};
        for (int i{2}; i <= n; ++i)
        {
            p = q;
            q = c;
            c = q + p;
        }
        return c;
    }
};
// @lc code=end

