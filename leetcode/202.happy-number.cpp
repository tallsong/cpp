/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
#include <unordered_set>
// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        std::unordered_set<int> hashset;

        while (n != 1)
        {
            if (hashset.count(n))
                return false;

            hashset.insert(n);
            int temp{0};
            while (n > 0)
            {
                temp += ((n % 10) * (n % 10));
                n /= 10;
            }
            n = temp;
        }
        return true;
    }
};
// @lc code=end
