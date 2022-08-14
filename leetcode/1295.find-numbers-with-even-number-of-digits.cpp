/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution
{
public:
    int findNumbers(std::vector<int> &nums)
    {
        int result{0};
        for (auto i : nums)
        {
            if ((i >= 10 && i < 100) || (i >= 1000 && i < 10000) || i==100000)
                ++result;
        }
        return result;
    }
};
// @lc code=end
