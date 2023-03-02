/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

class Solution
{
public:
    double caulate(double x, long long n)
    {
        if (n == 0)
            return 1;
        double y = caulate(x, n / 2);
        return n % 2 ? y * y * x : y * y;
    }
    double myPow(double x, int n)
    {
        long long N{n};
        return N > 0 ? caulate(x, N) : 1 / caulate(x, -N);
    }
};

// @lc code=end
