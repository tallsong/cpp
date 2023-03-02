/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int start{0}, end{x};
        int result{-1};
        while (start <= end)
        {
            int mid{(start + end) / 2};
            if ((long long)mid * mid <= x)
            {

                result = mid;
                start = mid + 1;
            }

            else
                end = mid - 1;
        }
        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.mySqrt(33);
    return 0;
}
