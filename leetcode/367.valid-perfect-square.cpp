/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 1;
        int right = num;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            auto square = long(mid) * mid;
            if (square < num)
            {
                left = mid + 1;
            }
            else
            {
                if (square > num)
                {
                    right = mid - 1;
                }
                else
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s.isPerfectSquare(14);
}